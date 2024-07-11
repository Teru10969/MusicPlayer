#include "musicplayer.h"
#include "ui_musicplayer.h"

#include <QDebug>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QBrush>
#include <QColor>
#include <QGraphicsDropShadowEffect>

/*播放音乐相关*/
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QAudioDevice>
#include<QMediaDevices>

/*本地文件相关*/
#include <QDir>
#include <QFileDialog>

#include <QMenu>

musicplayer::musicplayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::musicplayer)
{
    ui->setupUi(this);
    //无边框
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

     //设置阴影
    QGraphicsDropShadowEffect* shadow=new QGraphicsDropShadowEffect();
    //阴影高度
    shadow->setBlurRadius(8);
    //阴影的颜色
    shadow->setColor(Qt::black);
    //阴影的偏移
    shadow->setOffset(0);
    ui->mainWidget->setGraphicsEffect(shadow);

    //设置主窗口透明
    this->setAttribute(Qt::WA_TranslucentBackground);

    output=new QAudioOutput(this);//初始化音频输出，指向默认输出设备
    player=new QMediaPlayer(this);//初始化媒体播放器
    player->setAudioOutput(output);//设置媒体播放器使用的音频输出设备

    database=new Database(this);//初始化数据库操作对象
    network=new Network(this);//初始化网络请求对象
    database->connectDatabase();//连接数据库
    musicplayer::setTimeSlider();//初始化音乐进度条
    database->displayPlayHistory();//初始化历史播放记录

    //界面窗口初始设置为本地音乐窗口
    ui->stackedWidget->setCurrentIndex(0);
    currentwidget=ui->stackedWidget->widget(0);
    currentList=currentwidget->findChild<QListWidget *>();

    connect(player,&QMediaPlayer::playingChanged,ui->play,&QPushButton::setChecked);//播放状态与播放、暂停按钮同步
    connect(player, &QMediaPlayer::sourceChanged,this,[&](const QUrl &mediaSource) {
        currentMediaSource = mediaSource;//媒体源变化，记录当前媒体源
        flag1=true;
    });

    connect(player,&QMediaPlayer::playingChanged,this,[=](bool flag2){
        if(flag1&&flag2){//当媒体源开始播放，使用槽函数添加历史记录
            musicplayer::on_MediaSourceChanged(currentMediaSource);
            flag1=false;
        }
    });
    ui->HistoryList->setContextMenuPolicy(Qt::CustomContextMenu);//右键菜单
    connect(ui->HistoryList, &QTableView::customContextMenuRequested, this, &musicplayer::slotShowMenu);
}

musicplayer::~musicplayer()
{
    delete ui;
}

/********自定义关闭、最小化和最大化********/
void musicplayer::on_close_clicked()//自定义程序关闭按钮
{
    musicplayer::close();
}

void musicplayer::on_minimize_clicked()//自定义程序最小化按钮
{
    musicplayer::showMinimized();
}


void musicplayer::on_maximize_clicked()//自定义程序最大化按钮
{
    if (musicplayer::isMaximized()) {
        musicplayer::showNormal();
    } else {
        musicplayer::showMaximized();
    }
}
/*********************************/

/***********导入本地音乐***********/
void musicplayer::on_load_clicked()//导入本地音乐文件
{
    QString path=QFileDialog::getExistingDirectory(this,"请选择音乐所在的目录","./music");
    // 检查用户是否取消了选择
    if (path.isEmpty())return;

    QDir dir(path);
    QStringList musiclist=dir.entryList(QStringList()<<"*.mp3"<<"*.flac"<<"*.wav");
    // 检查播放列表是否为空
    if (musiclist.isEmpty())
    {
        QMessageBox::information(this, "提示", "选定的目录中没有音乐文件");
        return;
    }

    // 使用 QSet 来跟踪已经导入的文件
    QSet<QString> existingFiles;
    // 遍历当前播放列表中的每个 QUrl 对象，将其本地文件路径添加到 existingFiles 集合中
    for (const QUrl &url : playList) {
        existingFiles.insert(url.toLocalFile());
    }

    QStringList newMusicList;// 用于存储新发现的、尚未添加到播放列表的音乐文件名
    // 遍历所有待添加的音乐文件名
    for (const QString &file : musiclist) {

        QString fullPath = path + "/" + file;// 构建完整的文件路径

        if (!existingFiles.contains(fullPath)) // 检查文件路径是否已经存在于播放列表中
        {
            newMusicList.append(file); // 如果文件路径是新的，则将文件名添加到新音乐列表中
            playList.append(QUrl::fromLocalFile(fullPath));//将新音乐文件路径转换为 QUrl 对象，并添加到播放列表中
        }
    }
    if (newMusicList.isEmpty()) {
        QMessageBox::information(this, "提示", "选定的目录中没有新的音乐文件");
        return;
    }

    ui->LocalMusiclist->addItems(newMusicList);//在本地音乐列表中加入音乐
    ui->option->setCurrentRow(0);
}
/********************************/

/*******将当前播放音乐变成红色*******/
void musicplayer::resetAllItemsColor(QListWidget* listWidget)
{
    for (int i = 0; i < listWidget->count(); ++i) {
        listWidget->item(i)->setForeground(Qt::black);
    }
}
void musicplayer::updateCurrentPlayingItem()
{
    resetAllItemsColor(ui->LocalMusiclist);
    resetAllItemsColor(ui->NetMusicList);
    if(player->source().isLocalFile())currentList=ui->LocalMusiclist;
    else currentList=ui->NetMusicList;
    for (int i = 0; i < currentList->count(); i++) {
        if (i == index) {
            currentList->item(i)->setForeground(Qt::red);
        }else{
            currentList->item(i)->setForeground(Qt::black);
        }
    }
}
/********************************/

/***********播放暂停音乐***********/
void musicplayer::on_play_clicked()
{
    // if(ui->stackedWidget->currentIndex()==2)
    // {
    //     // ui->play->setChecked(false);
    //     ui->play->setChecked(!ui->play->isChecked());
    //     return;
    // }
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
        if(currentList->currentRow()==-1)//如果未选择歌曲，不处理，默认播放第一个
        {
            currentList->setCurrentRow(0);
        }
        if(currentList==ui->LocalMusiclist)
        {
            index=currentList->currentRow(); //播放选择的音乐
            player->setSource(playList[index]);
            player->play();
        }else if(currentList==ui->NetMusicList)
        {
            index=currentList->currentRow(); //播放选择的音乐
            network->NetMusicPlay(index);
        }
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
/********************************/

/*************上一曲*************/
void musicplayer::on_previous_clicked()
{
    // if(ui->stackedWidget->currentIndex()==2)return;//历史播放页时按下按钮不反应
    //检查列表中是否有音乐可播放
    if ((currentList->count()==0&&player->playbackState()==QMediaPlayer::PlaybackState::StoppedState)) {
        QMessageBox::information(this, "提示", "播放列表为空");
        ui->play->setChecked(false);
        return;
    }

    if (index == 0) {
        if(player->source().isLocalFile())
        index = ui->LocalMusiclist->count() - 1;
        else index = ui->NetMusicList->count() - 1;
    } else {
        index--;
    }
    if(player->source().isLocalFile())
    {
        player->setSource(playList[index]);// 设置媒体源为本地的URL
        player->play();
    }else
    {
        network->NetMusicPlay(index);//网络播放
    }
    updateCurrentPlayingItem();
}
/********************************/

/*************下一曲*************/
void musicplayer::on_next_clicked()
{
    // if(ui->stackedWidget->currentIndex()==2)return;//历史播放页时按下按钮不反应
    //检查列表中是否有音乐可播放
    if ((currentList->count()==0&&player->playbackState()==QMediaPlayer::PlaybackState::StoppedState)) {
        QMessageBox::information(this, "提示", "播放列表为空");
        ui->play->setChecked(false);
        return;
    }
    if(player->source().isLocalFile())
    {
        index=(index+1)%ui->LocalMusiclist->count();
        player->setSource(playList[index]);// 设置媒体源为本地的URL
        player->play();
    }else
    {
        index=(index+1)%ui->NetMusicList->count();
        network->NetMusicPlay(index);//网络播放
    }
    updateCurrentPlayingItem();
}
/********************************/

/**********双击播放本地音乐**********/
void musicplayer::on_LocalMusiclist_itemDoubleClicked(QListWidgetItem *item)//双击播放本地音乐
{
    index =ui->LocalMusiclist->row(item); // 获取双击项目的索引
    player->setSource(playList[index]); // 设置媒体源为选中的 URL
    updateCurrentPlayingItem();
    player->play(); // 播放选中的音乐
}
/********************************/

/**********双击播放网络音乐**********/
void musicplayer::on_NetMusicList_itemDoubleClicked(QListWidgetItem *item) //双击播放网络音乐
{
    index=ui->NetMusicList->row(item);
    network->NetMusicPlay(index);
}
/********************************/

/*********设置音乐时间进度条*********/
void musicplayer::setTimeSlider()
{
    connect(player,&QMediaPlayer::durationChanged,this,[=](qint64 duration){//音乐总时长
        ui->time2->setText(QString("%1:%2")
                               .arg(duration/1000/60,2,10,QChar('0'))
                               .arg(duration/1000%60,2,10,QChar('0')));//设置总时长文本显示
        ui->timeslider->setRange(0,duration);//进度条范围设置为总时长
    });
    connect(player,&QMediaPlayer::positionChanged,this,[=](qint64 position){//当前播放时刻
        if(ui->timeslider->isSliderDown())//如果手动调整进度条，则不处理（解决拖动进度条时播放进度会实时改变的bug)
            return;
        ui->time1->setText(QString("%1:%2")
                               .arg(position/1000/60,2,10,QChar('0'))
                               .arg(position/1000%60,2,10,QChar('0')));//设置当前播放时刻文本显示
        ui->timeslider->setSliderPosition(position);//进度条位置随播放时刻改变
    });
    connect(ui->timeslider, &QSlider::valueChanged,this,[=](qint64 position) { // 当前播放时刻文本随进度条位置改变
        ui->time1->setText(QString("%1:%2")
                               .arg(position / 1000 / 60, 2, 10, QChar('0'))
                               .arg(position / 1000 % 60, 2, 10, QChar('0')));
    });
}
/********************************/

/***********改变音乐进度***********/
void musicplayer::on_timeslider_sliderReleased()//当松开进度条时才改变当前播放位置
{
    int position = ui->timeslider->value();
    player->setPosition(position);
    ui->time1->setText(QString("%1:%2")
     .arg(position / 1000 / 60, 2, 10, QChar('0'))
     .arg(position / 1000 % 60, 2, 10, QChar('0')));
}
/********************************/

/*************音量调节*************/
void musicplayer::on_volumeslider_sliderMoved(int position)
{
    float volume=(float)position/100;
    output->setVolume(volume);//音量随音量条位置实时改变
}
void musicplayer::on_volumeslider_sliderPressed()
{
    float position=ui->volumeslider->value();
    float volume=position/100;
    output->setVolume(volume);//按下指定位置改变音量
}
/********************************/

/*************静音切换*************/
void musicplayer::on_voice_clicked()//按下声音键切换静音状态
{ 
    output->setMuted(!output->isMuted());
}
/********************************/

void musicplayer::on_option_currentRowChanged(int currentRow)//页面切换
{
    ui->stackedWidget->setCurrentIndex(currentRow);//页面随选项切换
}


void musicplayer::on_MediaSourceChanged(const QUrl &mediaSource) { //媒体源切换，插入历史播放记录
    // 从媒体源URL中提取歌曲名称（假设歌曲名称是文件名的一部分）
    if(mediaSource.isLocalFile()){
        QString songName = mediaSource.fileName();
        database->upsertPlayHistory(songName);
        qDebug() << "新增一条播放记录:" << songName;
    }else{
        int id=index;
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
                database->upsertPlayHistory(netsongName);
                qDebug() << "新增一条播放记录" << id << ":" << netsongName;
            } else {
                qDebug() << "No records found for id" << id;
            }
        }
    }
    database->displayPlayHistory();//更新历史记录界面
    qDebug()<<"index:"<<index;
}

void musicplayer::on_search_clicked()//按下搜索按钮
{
    network->search();//搜索网络音乐
}

void musicplayer::on_stackedWidget_currentChanged(int arg1) //发生页面切换
{
    /*设置当前页面和列表*/
    currentwidget=ui->stackedWidget->widget(arg1);
    if(ui->stackedWidget->currentIndex()!=2)
    currentList=currentwidget->findChild<QListWidget *>();
    qDebug()<<"ui->stackedWidget->currentIndex()"<<ui->stackedWidget->currentIndex();
}
void musicplayer::on_download_clicked()//按下下载按钮
{
    network->download();//下载网络音乐
}

void musicplayer::slotShowMenu(const QPoint &pos)
{
    // 获取右键时 Qtableview 中的项
    QModelIndex t_index = ui->HistoryList->indexAt(pos);

    if (t_index.isValid())
    {
        QString songName = ui->HistoryList->item(t_index.row(), 0)->text(); // 获取第一列（歌曲名）的文本
        Q_UNUSED(pos);
        QMenu* contextMenu = new QMenu(this);
        QAction* deleteAction = contextMenu->addAction("删除");
        connect(deleteAction, &QAction::triggered, this, [this, songName]() {
            database->deletePlayHistory(songName); // 删除数据库记录
            database->displayPlayHistory(); // 更新界面显示
        });

        contextMenu->exec(ui->HistoryList->viewport()->mapToGlobal(pos));
        delete contextMenu;
    }

}
