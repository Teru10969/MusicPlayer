#include "network.h"
#include "database.h"
#include "musicplayer.h"
#include "ui_musicplayer.h"
#include <QFile>
#include <QDebug>
#include <QObject>
#include<QFile>
#include<QFileDialog>

#include <QWidget>
Network::Network(class musicplayer* parent){
    this->musicplayer=parent;
}

void Network::hashJsonAnalysis(QByteArray JsonData)
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
                    musicplayer->ui->NetMusicList->addItem(item);
                }
            }
        }
    }
}
void Network::httpAccess(QString url)
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
    connect(manager,&QNetworkAccessManager::finished,this,&Network::netReply);
}
QString Network::musicJsonAnalysis(QByteArray JsonData)
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

QString Network::getDownload_Md5(QString time,QString encode_album_audio_id)
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

QString Network::getSearch_Md5(QString songname,QString time)
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

void Network::netReply(QNetworkReply *reply)
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

void Network::search()
{
    musicplayer->ui->NetMusicList->clear();// 清空网络音乐列表
    QSqlQuery query;
    QString sql="delete from songlist;";
    if(!query.exec(sql))qDebug()<<"错误"<<query.lastError().text();
    QDateTime time = QDateTime::currentDateTime();
    // 将当前时间转换为自纪元以来的秒数，并将其转换为字符串
    QString currentTimeString = QString::number(time.toSecsSinceEpoch()*1000);
    QString signaturecode = getSearch_Md5(musicplayer->ui->searchline->text(),currentTimeString);
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
                                           ).arg(currentTimeString).arg(musicplayer->ui->searchline->text()).arg(signaturecode);

    // 发起 HTTP 请求
    httpAccess(url);
    QByteArray JsonData;
    QEventLoop loop;

    // 等待 HTTP 请求完成并获取数据
    auto c = connect(this, &Network::finish, [&](const QByteArray &data){
        JsonData = data;
        loop.exit(1);
    });
    loop.exec();
    disconnect(c);

    // 解析获取的 JSON 数据
    hashJsonAnalysis(JsonData);
    musicplayer->ui->option->setCurrentRow(1);
}

QString Network::UrlAnalysis(QString encode_album_audio_id)
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
    auto d = connect(this,&Network::finish, [&](const QByteArray &data){
        JsonData = data;
        loop.exit(1);
    });
    loop.exec();
    disconnect(d);
    // 解析要播放的音乐URL
    QString music = Network::musicJsonAnalysis(JsonData);
    return music;
}

void Network::NetMusicPlay(int netindex)
{
    qDebug()<<"ui->NetMusicList->currentRow"<<netindex;
    QSqlQuery query;
    QString sql = QString("select * from songlist where id = %1;").arg(netindex);
    if (!query.exec(sql))
    {
        QMessageBox::critical(nullptr, "select * from songlist where id =",database->db.lastError().text());
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
    }
    // 播放选中的音乐
    QString musicUrl=Network::UrlAnalysis(EMixSongID);
    musicplayer->player->setSource(QUrl(musicUrl));
    musicplayer->player->play();
    musicplayer->updateCurrentPlayingItem();
}

void Network::download()
{
    if(musicplayer->currentList!=musicplayer->ui->NetMusicList||musicplayer->currentList->count()==0)
    {
        QMessageBox::information(musicplayer, "提示", "请选择网络音乐下载");
        return;
    }

    QString fileName=QFileDialog::getSaveFileName(this, "保存音乐文件", QDir::homePath()+ "/" + musicplayer->currentList->currentItem()->text(), "音乐文件 (*.mp3 *.flac *.wav)");
    if (fileName.isEmpty())return;

    int downloadindex=musicplayer->ui->NetMusicList->currentRow();
    QSqlQuery query;
    QString sql = QString("select * from songlist where id = %1;").arg(downloadindex);
    if (!query.exec(sql))
    {
        QMessageBox::critical(musicplayer, "select * from songlist where id =", database->db.lastError().text());
    }
    QString EMixSongID;
    while (query.next())
    {
        QSqlRecord record = query.record();
        int EMixSongIDkey = record.indexOf("EMixSongID");
        EMixSongID = query.value(EMixSongIDkey).toString();
    }
    QString musicUrl=Network::UrlAnalysis(EMixSongID);
    //实例化网络请求操作事项
    request = new QNetworkRequest;
    //将url网页地址存入request请求中
    request->setUrl(musicUrl);
    //实例化网络管理（访问）
    manager = new QNetworkAccessManager;
    //通过get,上传具体的请求
    QNetworkReply *reply =manager->get(*request);
    connect(reply, &QNetworkReply::finished, this, [reply,fileName,this]() {
        if (reply->error() == QNetworkReply::NoError) {
            QFile file(fileName);
            if (file.open(QIODevice::WriteOnly)) {
                file.write(reply->readAll());
                file.close();
                QMessageBox::information(musicplayer, "提示", "下载完成");
            } else {
                QMessageBox::information(musicplayer, "提示", "文件保存失败");
            }
        } else {
            QMessageBox::information(musicplayer, "提示", "下载失败");
        }
        reply->deleteLater();
    });
}
