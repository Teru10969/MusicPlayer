#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QWidget>
#include <QList>
#include <QListWidget>
#include <QPoint>
#include <QSqlQuery>
#include <QString>
#include <QNetworkRequest>          //HTTP的URL管理类
#include <QNetworkAccessManager>    //URL的上传管理
static QString kugouSearchApi = "https://complexsearch.kugou.com/v2/search/song?";
static QString kugouDownldadApi = "https://wwwapi.kugou.com/play/songinfo?";

namespace Ui {
class musicplayer;
}

class musicplayer : public QWidget
{
    Q_OBJECT

public:
    explicit musicplayer(QWidget *parent = 0);
    ~musicplayer();
    void updateCurrentPlayingItem();//将当前播放音乐变成红色
    void connectDatabase();//连接数据库
    void upsertPlayHistory(const QString &songName);//更新历史播放数据库
    void displayPlayHistory();//显示历史播放列表
    void hashJsonAnalysis(QByteArray JsonData);
    void httpAccess(QString url);
    QString musicJsonAnalysis(QByteArray JsonData);
    QString getDownload_Md5(QString time,QString encode_album_audio_id);
    QString getSearch_Md5(QString songname,QString time);
    // virtual void mouseMoveEvent(QMouseEvent* event);
    // virtual void mousePressEvent(QMouseEvent* event);
    // virtual void mouseReleaseEvent(QMouseEvent* event);

signals:
    void finish(QByteArray Data);

private slots:

    void on_previous_clicked();

    void on_next_clicked();

    void on_load_clicked();

    void on_play_clicked();

    void on_LocalMusiclist_itemDoubleClicked(QListWidgetItem *item);

    void on_timeslider_sliderReleased();

    void on_close_clicked();

    void on_volumeslider_sliderMoved(int position);

    void on_volumeslider_sliderPressed();

    void on_voice_clicked();

    // void on_timeslider_sliderMoved(int position);

    // void on_LocalMusicList_itemClicked(QListWidgetItem *item);

    void on_option_currentRowChanged(int currentRow);

    void on_MediaSourceChanged(const QUrl &mediaSource);

    void on_search_clicked();

    void netReply(QNetworkReply *reply);

    // void downloadPlayer(QString encode_album_audio_id);

private:
    Ui::musicplayer *ui;
    QList<QUrl> playList;
    QAudioOutput* output;
    QMediaPlayer* player;
    QUrl currentMediaSource;
    QWidget* currentwidget;
    QListWidget* currentList;
    int index=0;
    QSqlDatabase db;
    bool flag1;
    QNetworkRequest* request;
    QNetworkAccessManager* manager;
    // QPoint z;
};

#endif // MUSICPLAYER_H
