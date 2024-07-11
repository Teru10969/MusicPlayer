#ifndef NETWORK_H
#define NETWORK_H
#include<database.h>
#include<ui_musicplayer.h>
#include <QString>
#include<QWidget>
/*网络相关*/
#include <QNetworkRequest>          //HTTP的URL管理类
#include <QNetworkAccessManager>    //URL的上传管理
#include <QNetworkReply>            //网页回复数据触发信号的类
#include <QEventLoop>               //提供一种进入和离开事件循环的方法
#include <QJsonArray>               //封装JSON数组
#include <QJsonObject>              //封装JSON对象
#include <QJsonDocument>
#include<QMessageBox>
static QString kugouSearchApi = "https://complexsearch.kugou.com/v2/search/song?";
static QString kugouDownldadApi = "https://wwwapi.kugou.com/play/songinfo?";
class musicplayer;
class Network: public QWidget
{
    Q_OBJECT

public:
    Network(musicplayer* parent);

    musicplayer* musicplayer;

    void httpAccess(QString url);

    void hashJsonAnalysis(QByteArray JsonData);

    QString musicJsonAnalysis(QByteArray JsonData);

    QString getDownload_Md5(QString time,QString encode_album_audio_id);

    QString getSearch_Md5(QString songname,QString time);

    QString UrlAnalysis(QString encode_album_audio_id);

    void search();

    Database* database;

    QNetworkRequest* request;

    QNetworkAccessManager* manager;

signals:
    void finish(QByteArray Data);

public slots:
    void netReply(QNetworkReply *reply);
    void NetMusicPlay(int netindex);
    void download();
};

#endif // NETWORK_H
