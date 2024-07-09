#include "musicplayer.h"
#include "ui_musicplayer.h"

#include <QMouseEvent>
#include <QPoint>

/*数据库相关*/
#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

/*播放音乐相关*/
#include <QMediaPlayer>
#include <QAudioOutput>

/*本地文件相关*/
#include <QDir>
#include <QFileDialog>

/*网络相关*/
#include <QNetworkRequest>          //HTTP的URL管理类
#include <QNetworkAccessManager>    //URL的上传管理
#include <QNetworkReply>            //网页回复数据触发信号的类
#include <QEventLoop>               //提供一种进入和离开事件循环的方法
#include <QJsonArray>               //封装JSON数组
#include <QJsonObject>              //封装JSON对象
#include <QJsonDocument>

#include <QDebug>

#include <QListWidget>
#include <QListWidgetItem>
#include <QTableWidget>
#include <QTableWidgetItem>

#include <QMessageBox>
#include <QBrush>
#include <QColor>

musicplayer::musicplayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::musicplayer)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

    output=new QAudioOutput(this);
    player=new QMediaPlayer(this);
    player->setAudioOutput(output);

    musicplayer::connectDatabase();

    //界面窗口初始设置为本地音乐窗口
    ui->stackedWidget->setCurrentIndex(0);
    currentwidget=ui->stackedWidget->widget(0);
    currentList=currentwidget->findChild<QListWidget *>();

    connect(player,&QMediaPlayer::durationChanged,this,[=](qint64 duration){//音乐总时长
        ui->time2->setText(QString("%1:%2")
        .arg(duration/1000/60,2,10,QChar('0'))
        .arg(duration/1000%60,2,10,QChar('0')));
        ui->timeslider->setRange(0,duration);
    });
    connect(player,&QMediaPlayer::positionChanged,this,[=](qint64 position){//当前播放时刻
        if(ui->timeslider->isSliderDown())//如果手动调整进度条，则不处理（解决拖动进度条时播放时刻是当前播放进度的bug)
        return;
        ui->time1->setText(QString("%1:%2")
        .arg(position/1000/60,2,10,QChar('0'))
        .arg(position/1000%60,2,10,QChar('0')));
        ui->timeslider->setSliderPosition(position);
    });
    connect(ui->timeslider, &QSlider::valueChanged,this,[=](qint64 position) { // 播放时刻随进度条值改变
        ui->time1->setText(QString("%1:%2")
        .arg(position / 1000 / 60, 2, 10, QChar('0'))
        .arg(position / 1000 % 60, 2, 10, QChar('0')));
    });
    connect(player,&QMediaPlayer::playingChanged,ui->play,&QPushButton::setChecked);

    connect(player, &QMediaPlayer::sourceChanged,this,[&](const QUrl &mediaSource) {
        currentMediaSource = mediaSource;
        flag1=true;
    });
    connect(player,&QMediaPlayer::playingChanged,this,[=](bool flag2){
        if(flag1&&flag2){//当媒体源开始播放，使用槽函数添加历史记录
            musicplayer::on_MediaSourceChanged(currentMediaSource);
            flag1=false;
        }
    });
    musicplayer::displayPlayHistory();
    // qDebug()<<"currentwidget:"<<ui->stackedWidget->currentIndex();
}

musicplayer::~musicplayer()
{
    delete ui;
}

void musicplayer::on_load_clicked()//导入本地音乐文件
{
    QString path=QFileDialog::getExistingDirectory(this,"请选择音乐所在的目录","./music");
    // 检查用户是否取消了选择
    if (path.isEmpty())return;

    QDir dir(path);
    QStringList musiclist=dir.entryList(QStringList()<<"*.mp3"<<"*.flac"<<"*.wav");

    // 使用 QSet 来跟踪已经导入的文件
    QSet<QString> existingFiles;
    for (const QUrl &url : playList) {
        existingFiles.insert(url.toLocalFile());
    }

    QStringList newMusicList;
    for (const QString &file : musiclist) {
        QString fullPath = path + "/" + file;
        if (!existingFiles.contains(fullPath)) {
            newMusicList.append(file);
            playList.append(QUrl::fromLocalFile(fullPath));
        }
    }

    if (newMusicList.isEmpty()) {
        QMessageBox::information(this, "提示", "选定的目录中没有新的音乐文件");
        return;
    }
    ui->LocalMusiclist->addItems(newMusicList);
    // for(QString file:musiclist)使用范围循环遍历musiclist中的每个文件名
    // playList.append(QUrl::fromLocalFile(path+"/"+file)); //文件放入播放列表里

    // 检查播放列表是否为空
    if (musiclist.isEmpty())
    {
        QMessageBox::information(this, "提示", "选定的目录中没有音乐文件");
        return;
    }

    player->setSource(playList[index]);
    ui->option->setCurrentRow(0);
    // ui->LocalMusiclist->setCurrentRow(0);
}

void musicplayer::updateCurrentPlayingItem()//将当前播放音乐变成红色
{

    for (int i = 0; i < ui->LocalMusiclist->count(); i++) {
        if (i == index) {
            ui->LocalMusiclist->item(i)->setForeground(Qt::red);
        }else{
            ui->LocalMusiclist->item(i)->setForeground(Qt::black);
        }
    }
}

void musicplayer::on_play_clicked()//播放暂停音乐
{
    //检查列表中是否有音乐可播放
    if ((currentList->count()==0&&player->playbackState()==QMediaPlayer::PlaybackState::StoppedState)) {
        QMessageBox::information(this, "提示", "播放列表为空");
        ui->play->setChecked(false);
        return;
    }
    switch(player->playbackState())
    {
    case QMediaPlayer::PlaybackState::StoppedState://停止状态 播放当前选中音乐
    {
        // ui->play->setChecked(true);
        if(currentList->currentRow()==-1); //如果未选择歌曲，不处理，默认播放第一个
        else index=currentList->currentRow(); //播放选择的音乐
        player->setSource(playList[index]);
        player->play();
        updateCurrentPlayingItem();
        break;
    }
    case QMediaPlayer::PlaybackState::PlayingState://播放状态 按下按钮暂停
    {
        // ui->play->setChecked(false);
        player->pause();
        break;
    }
    case QMediaPlayer::PlaybackState::PausedState://暂停状态 按下按钮继续播放
    {
        player->play();
        break;
    }
    }
}


void musicplayer::on_previous_clicked()//上一曲
{
    // 检查播放列表是否为空
    if (playList.isEmpty()) {
        QMessageBox::information(this, "提示", "播放列表为空，请先导入音乐文件");
        return;
    }

    if (index == 0) {
        index = playList.size() - 1;
    } else {
        index--;
    }

    player->setSource(playList[index]); // 设置媒体源为选中的 URL
    updateCurrentPlayingItem();
    player->play(); // 播放选中的音乐
}


void musicplayer::on_next_clicked()//下一曲
{
    // 检查播放列表是否为空
    if (playList.isEmpty()) {
        QMessageBox::information(this, "提示", "播放列表为空，请先导入音乐文件");
        return;
    }
    index=(index+1)%playList.size();
    player->setSource(playList[index]); // 设置媒体源为选中的 URL
    updateCurrentPlayingItem();
    player->play(); // 播放选中的音乐
}


void musicplayer::on_LocalMusiclist_itemDoubleClicked(QListWidgetItem *item)
{
    index =currentList->row(item); // 获取双击项目的索引
    player->setSource(playList[index]); // 设置媒体源为选中的 URL
    updateCurrentPlayingItem();
    item->setForeground(Qt::red);
    player->play(); // 播放选中的音乐
}



void musicplayer::on_timeslider_sliderReleased()//进度条更改音乐播放进度
{
    int position = ui->timeslider->value();
    player->setPosition(position);
    ui->time1->setText(QString("%1:%2")
     .arg(position / 1000 / 60, 2, 10, QChar('0'))
     .arg(position / 1000 % 60, 2, 10, QChar('0')));
}


void musicplayer::on_close_clicked()
{
    musicplayer::close();
}

void musicplayer::on_volumeslider_sliderMoved(int position)
{
    float volume=(float)position/100;
    output->setVolume(volume);
}


void musicplayer::on_volumeslider_sliderPressed()
{
    float position=ui->volumeslider->value();
    float volume=position/100;
    output->setVolume(volume);
}

void musicplayer::on_voice_clicked()
{
    //按下声音键切换静音状态和音量状态
    output->setMuted(!output->isMuted());
}

void musicplayer::on_option_currentRowChanged(int currentRow)
{
    ui->stackedWidget->setCurrentIndex(currentRow);
}

void musicplayer::connectDatabase(){
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("MusicPlayer.db");
    if(!db.open()){
        qDebug() << "Error: connection with database fail";
    } else {
        qDebug() << "Database: connection ok";
    }
}
void musicplayer::upsertPlayHistory(const QString &songName){ //更新播放记录到数据库
    QSqlQuery query;
    // 检查歌曲是否已经存在
    query.prepare("SELECT id FROM PlayHistory WHERE song_name = :song_name");
    query.bindValue(":song_name", songName);
    query.exec();

    if (query.next()) {
        // 如果存在，更新播放时间
        int id = query.value(0).toInt();
        query.prepare("UPDATE PlayHistory SET play_time = (datetime(CURRENT_TIMESTAMP, 'localtime')) WHERE id = :id");
        query.bindValue(":id", id);
    } else {
        // 如果不存在，插入新记录
        query.prepare("INSERT INTO PlayHistory (song_name) VALUES (:song_name)");
        query.bindValue(":song_name", songName);
    }

    if (!query.exec()) {
        qDebug() << "Error: failed to upsert play history -" << query.lastError();
    } else {
        qDebug() << "Play history upserted successfully";
    }
}

void musicplayer::on_MediaSourceChanged(const QUrl &mediaSource) { //媒体源切换槽函数
    // 从媒体源URL中提取歌曲名称（假设歌曲名称是文件名的一部分）
    if(mediaSource.isLocalFile()){
        QString songName = mediaSource.fileName();
        musicplayer::upsertPlayHistory(songName);
    }else{
        int id=currentList->currentRow();
        index=id;
        QSqlQuery query;
        query.prepare("SELECT FileName FROM songlist WHERE id = :id");
        query.bindValue(":id", id);
        if (!query.exec()) {
            qDebug() << "Query execution error:";
            qDebug() << query.lastError().text();
        } else {
            if (query.next()) {
                // 获取查询结果，并赋值给songname
                QString netsongName = query.value(0).toString();
                musicplayer::upsertPlayHistory(netsongName);
                qDebug() << "FileName for id" << id << ":" << netsongName;
            } else {
                qDebug() << "No records found for id" << id;
            }
        }
    }
    displayPlayHistory();//更新历史记录界面
    qDebug()<<index;
}

void musicplayer::displayPlayHistory() { //显示历史播放记录
    QSqlQuery query;
    query.exec("SELECT song_name, play_time FROM PlayHistory ORDER BY play_time DESC");

     // 清除现有条目
    ui->HistoryList->setRowCount(0);
    int row = 0;

    while (query.next()) {
        QString songName = query.value(0).toString();
        QString playTime = query.value(1).toString();
        ui->HistoryList->insertRow(row);
        ui->HistoryList->setItem(row,0,new QTableWidgetItem(songName));
        ui->HistoryList->setItem(row,1,new QTableWidgetItem(playTime));
        row++;
    }

    ui->HistoryList->resizeRowsToContents();
    ui->HistoryList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//填充列宽
    ui->HistoryList->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);// 根据内容设置所有行高
}

void musicplayer::on_search_clicked()
{
    ui->NetMusicList->clear();// 清空网络音乐列表
    QSqlQuery query;
    QString sql="delete from songlist;";
    if(!query.exec(sql))qDebug()<<"错误"<<query.lastError().text();
    QDateTime time = QDateTime::currentDateTime();
    // 将当前时间转换为自纪元以来的秒数，并将其转换为字符串
    QString currentTimeString = QString::number(time.toSecsSinceEpoch()*1000);
    QString signaturecode = getSearch_Md5(ui->searchline->text(),currentTimeString);
    // 根据用户输入的 MP3 名称发起操作请求
    QString url = kugouSearchApi + QString("callback=callback123"
                                           "&srcappid=2919"
                                           "&clientver=1000"
                                           "&clienttime=%1"
                                           "&mid=707708a817d80eedd95f2ae68bc57780"
                                           "&uuid=707708a817d80eedd95f2ae68bc57780"
                                           "&dfid=11SITU3au0iw0OdGgJ0EhTvI"
                                           "&keyword=%2"
                                           "&page=1"
                                           "&pagesize=30"
                                           "&bitrate=0"
                                           "&isfuzzy=0"
                                           "&inputtype=0"
                                           "&platform=WebFilter"
                                           "&userid=0"
                                           "&iscorrection=1"
                                           "&privilege_filter=0"
                                           "&filter=10"
                                           "&token="
                                           "&appid=1014"
                                           "&signature=%3"
                                           ).arg(currentTimeString).arg(ui->searchline->text()).arg(signaturecode);

    // 发起 HTTP 请求
    httpAccess(url);
    QByteArray JsonData;
    QEventLoop loop;

    // 等待 HTTP 请求完成并获取数据
    auto c = connect(this, &musicplayer::finish, [&](const QByteArray &data){
        JsonData = data;
        loop.exit(1);
    });
    loop.exec();
    disconnect(c);

    // 解析获取的 JSON 数据
    hashJsonAnalysis(JsonData);
    ui->option->setCurrentRow(1);
}

void musicplayer::httpAccess(QString url)
{
    //实例化网络请求操作事项
    request = new QNetworkRequest;
    //将url网页地址存入request请求中
    request->setUrl(url);
    //实例化网络管理（访问）
    manager = new QNetworkAccessManager;
    //通过get,上传具体的请求
    manager->get(*request);
    //当网页回复消息，出发finish信号，读取数据
    connect(manager,&QNetworkAccessManager::finished,this,&musicplayer::netReply);
}

void musicplayer::netReply(QNetworkReply *reply)
{
    // 获取响应状态码，200 属于正常
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug() << status_code;
    // 重定向目标属性
    reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    if (reply->error() == QNetworkReply::NoError)
    {
        // 如果没有发生网络错误，则读取响应数据
        QByteArray data = reply->readAll();
        // 发射自定义的 finish 信号，将响应数据传递给槽函数
        emit finish(data);
    }
    else
    {
        // 如果发生了网络错误，则打印错误信息
        qDebug() << reply->errorString();
    }
}

void musicplayer::hashJsonAnalysis(QByteArray JsonData)
{
    //qDebug()<< JsonData; // 打印输入的 JSON 数据，用于调试
    //移除callback123()
    // 找到第一个左括号 "(" 的位置
    int leftBracketIndex = JsonData.indexOf('(');
    if (leftBracketIndex != -1)
    {
        // 找到最后一个右括号 ")" 的位置
        int rightBracketIndex = JsonData.lastIndexOf(')');
        if (rightBracketIndex != -1)
        {
            // 提取 JSON 数据，去除包裹的部分
            JsonData = JsonData.mid(leftBracketIndex + 1, rightBracketIndex - leftBracketIndex - 1);
        }
    }
    //保存json查看数据
    QFile file("hash.json");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        file.write(JsonData);
        file.close();
    }


    // 将 JSON 数据解析为 QJsonDocument 对象
    QJsonDocument document = QJsonDocument::fromJson(JsonData);

    if(document.isObject()) // 如果解析后的对象是一个 JSON 对象
    {
        qDebug()<<"boject";
        QJsonObject data = document.object(); // 获取 JSON 对象中的"data"字段
        if(data.contains("data")) // 如果"data"字段存在
        {
            QJsonObject objectInfo = data.value("data").toObject(); // 获取"data"字段中的对象
            qDebug()<<"data";
            if(objectInfo.contains("lists")) // 如果"lists"字段存在
            {
                QJsonArray objectHash = objectInfo.value("lists").toArray(); // 获取"lists"字段中的数组
                qDebug()<<"lists";
                for(int i = 0; i < objectHash.count(); i++) // 遍历数组中的每个元素
                {
                    QString singer_song_name,EMixSongID;
                    QJsonObject album = objectHash.at(i).toObject(); // 获取数组元素中的对象

                    // 从对象中获取歌曲名、歌手名、专辑 ID 和哈希值
                    if(album.contains("FileName"))
                    {
                        singer_song_name = album.value("FileName").toString();
                    }
                    if(album.contains("EMixSongID"))
                    {
                        EMixSongID = album.value("EMixSongID").toString();
                    }
                    // 将解析出的信息插入数据库
                    QSqlQuery query;
                    query.prepare("INSERT INTO songlist (id, FileName, EMixSongID) VALUES (:id, :song_name, :song_id)");
                    query.bindValue(":id", i);
                    query.bindValue(":song_name", singer_song_name);
                    query.bindValue(":song_id", EMixSongID);
                    if(!query.exec()) // 如果插入数据库失败
                    {
                        qDebug()<<"插入数据库错误"<<query.lastError().text();
                    }

                    // 在搜索展示框中显示歌曲名称和歌手名称
                    QListWidgetItem *item = new QListWidgetItem(singer_song_name);
                    ui->NetMusicList->addItem(item);
                }
            }
        }
    }
}

QString musicplayer::musicJsonAnalysis(QByteArray JsonData)
{
    // 保存 JSON 数据到文件中以便查看
    QFile file("download.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        file.write(JsonData);
        file.close();
    }

    // 解析 JSON 数据
    QJsonDocument document = QJsonDocument::fromJson(JsonData);
    if (document.isObject())
    {
        QJsonObject data = document.object();
        if (data.contains("data"))
        {
            QJsonObject objectPlayurl = data.value("data").toObject();
            // // 如果包含歌词，发送歌词显示信号
            // if (objectPlayurl.contains("lyrics"))
            // {
            //     emit lyricShow(objectPlayurl.value("lyrics").toString());
            // }
            // 返回音乐播放 URL
            if (objectPlayurl.contains("play_url"))
            {
                return objectPlayurl.value("play_url").toString();
                qDebug()<<objectPlayurl.value("play_url").toString();
            }
        }
    }
}

QString musicplayer::getDownload_Md5(QString time,QString encode_album_audio_id)
{
    // 构建签名列表
    QStringList signature_list;
    signature_list << "NVPh5oo715z5DIWAeQlhMDsWXXQV4hwt"
                   << "appid=1014"
                   << "clienttime=" + time
                   << "clientver=20000"
                   << "dfid=11SITU3au0iw0OdGgJ0EhTvI"
                   << "encode_album_audio_id=" + encode_album_audio_id
                   << "mid=707708a817d80eedd95f2ae68bc57780"
                   << "platid=4"
                   << "srcappid=2919"
                   << "token="
                   << "userid=0"
                   << "uuid=707708a817d80eedd95f2ae68bc57780"
                   << "NVPh5oo715z5DIWAeQlhMDsWXXQV4hwt";

    // 将签名列表中的元素连接成一个字符串
    QString string = signature_list.join("");
    //qDebug()<< string;
    //生成 MD5 哈希
    QByteArray hashedData = QCryptographicHash::hash(string.toUtf8(), QCryptographicHash::Md5);

    // 将哈希数据转换为十六进制字符串
    QString md5Hash = hashedData.toHex();

    return md5Hash;
}
QString musicplayer::getSearch_Md5(QString songname,QString time)
{
    // 构建签名列表
            QStringList signature_list;
    signature_list <<   "NVPh5oo715z5DIWAeQlhMDsWXXQV4hwt"
                   <<   "appid=1014"
                   <<   "bitrate=0"
                   <<   "callback=callback123"
                   <<   "clienttime=" + time
                   <<   "clientver=1000"
                   <<   "dfid=11SITU3au0iw0OdGgJ0EhTvI"
                   <<   "filter=10"
                   <<   "inputtype=0"
                   <<   "iscorrection=1"
                   <<   "isfuzzy=0"
                   <<   "keyword=" + songname
                   <<   "mid=707708a817d80eedd95f2ae68bc57780"
                   <<   "page=1"
                   <<   "pagesize=30"
                   <<   "platform=WebFilter"
                   <<   "privilege_filter=0"
                   <<   "srcappid=2919"
                   <<   "token="
                   <<   "userid=0"
                   <<   "uuid=707708a817d80eedd95f2ae68bc57780"
                   <<   "NVPh5oo715z5DIWAeQlhMDsWXXQV4hwt";

    // 将签名列表中的元素连接成一个字符串
    QString string = signature_list.join("");
    //qDebug()<< string;
    //生成 MD5 哈希
    QByteArray hashedData = QCryptographicHash::hash(string.toUtf8(), QCryptographicHash::Md5);
    // 将哈希数据转换为十六进制字符串
    QString md5Hash = hashedData.toHex();
    return md5Hash;
}

QString musicplayer::loadPlayer(QString encode_album_audio_id)
{
    //构建歌曲的 URL
    QDateTime time = QDateTime::currentDateTime();
    // 将当前时间转换为自纪元以来的秒数，并将其转换为字符串
    QString currentTimeString = QString::number(time.toSecsSinceEpoch()*1000);
    // currentTimeString = "1713782920612";
    // QString encode_album_audio_id = "j5yn384";
    QString signaturecode = getDownload_Md5(currentTimeString,encode_album_audio_id);
    QString url = kugouDownldadApi + QString("srcappid=2919"
                                             "&clientver=20000"
                                             "&clienttime=%1"
                                             "&mid=707708a817d80eedd95f2ae68bc57780"
                                             "&uuid=707708a817d80eedd95f2ae68bc57780"
                                             "&dfid=11SITU3au0iw0OdGgJ0EhTvI"
                                             "&appid=1014"
                                             "&platid=4"
                                             "&encode_album_audio_id=%2"
                                             "&token="
                                             "&userid=0"
                                             "&signature=%3"
                                             ).arg(currentTimeString).arg(encode_album_audio_id).arg(signaturecode);
    qDebug()<<url;
    // 发起 HTTP 请求获取歌曲数据
    httpAccess(url);

    QByteArray JsonData;
    QEventLoop loop;

    // 等待 HTTP 请求完成并获取数据
    auto d = connect(this,&musicplayer::finish, [&](const QByteArray &data){
        JsonData = data;
        loop.exit(1);
    });
    loop.exec();
    disconnect(d);

    // 解析要播放的音乐URL
    QString music = musicplayer::musicJsonAnalysis(JsonData);
    return music;
}

void musicplayer::on_NetMusicList_itemDoubleClicked(QListWidgetItem *item) //双击列表项播放网络音乐
{
    // 获取双击的歌曲索引，即数据表的 ID 号
    index=ui->NetMusicList->currentRow();
    QSqlQuery query;
    QString sql = QString("select * from songlist where id = %1;").arg(index);
    if (!query.exec(sql))
    {
        QMessageBox::critical(nullptr, "select * from songlist where id =", db.lastError().text());
    }
    // 将选中的音乐的数据信息存入历史数据表
    QString  singer_song_name,EMixSongID;
    while (query.next())
    {
        QSqlRecord record = query.record();
        int singer_song_namekey = record.indexOf("FileName");
        int EMixSongIDkey = record.indexOf("EMixSongID");

        singer_song_name = query.value(singer_song_namekey).toString();
        EMixSongID = query.value(EMixSongIDkey).toString();

        // 查询历史数据表中是否已经存在该歌曲的记录
        sql = QString("select EMixSongID from netsonghistory where EMixSongID = '%1';").arg(EMixSongID);
        if (!query.exec(sql))
        {
            QMessageBox::critical(nullptr, "select hash from netsonghistory where EMixSongID =", db.lastError().text());
        }
        // 如果不存在该记录，则将其存入历史数据表
        if (query.next() == NULL)
        {
            sql = QString("insert into netsonghistory values(NULL, '%1', '%2')").arg(singer_song_name).arg(EMixSongID);
            if (!query.exec(sql))
            {
                QMessageBox::critical(nullptr, "insert error", db.lastError().text());
            }
            // 将歌手和歌名放入历史歌曲表中显示
            // QListWidgetItem *item = new QListWidgetItem(singer_song_name);
            // ui->lw_record->addItem(item);
        }
    }
    // 播放选中的音乐
    QString music=musicplayer::loadPlayer(EMixSongID);
    player->setSource(QUrl(music));
    player->play();
}


void musicplayer::on_stackedWidget_currentChanged(int arg1) //界面切换
{
    currentwidget=ui->stackedWidget->widget(arg1);
    currentList=currentwidget->findChild<QListWidget *>();
    qDebug()<<ui->stackedWidget->currentIndex();
}

void musicplayer::getNetList()
{
    QSqlQuery query;
    QString sql="delete from neturl;";
}
