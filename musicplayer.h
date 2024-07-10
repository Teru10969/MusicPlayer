#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
#include<database.h>
#include<network.h>
#include <QMediaPlayer>
#include <QAudioOutput>
#include<QMessageBox>
#include <QWidget>
#include <QList>
#include <QListWidget>
#include <QPoint>
#include <QFile>
#include <QString>


namespace Ui {
class musicplayer;
}

class musicplayer : public QWidget
{
    Q_OBJECT

public:
    explicit musicplayer(QWidget *parent = 0);
    ~musicplayer();
    Ui::musicplayer *ui;
    QList<QUrl> playList;
    QAudioOutput* output;
    QMediaPlayer* player;
    QUrl currentMediaSource;
    QWidget* currentwidget;
    QListWidget* currentList;
    QTableWidget* currentTable;
    int index=0;
    bool flag1;
    Database* database;
    Network* network;
    void resetAllItemsColor(QListWidget* listWidget);
    void updateCurrentPlayingItem();//将当前播放音乐变成红色
    void getMusicList();
    void setTimeSlider();
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

    void on_option_currentRowChanged(int currentRow);

    void on_MediaSourceChanged(const QUrl &mediaSource);

    void on_search_clicked();

    void on_NetMusicList_itemDoubleClicked(QListWidgetItem *item);

    void on_stackedWidget_currentChanged(int arg1);

    void on_download_clicked();

    void on_minimize_clicked();

    void on_maximize_clicked();

private:



    // QPoint z;
};

#endif // MUSICPLAYER_H
