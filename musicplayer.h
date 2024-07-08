#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include "qaudiooutput.h"
#include "qmediaplayer.h"
#include <QWidget>
#include <QList>
#include <QListWidget>
#include <QPoint>
#include <QSqlQuery>
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
    void updateCurrentPlayingItem();
    void connectDatabase();
    void upsertPlayHistory(const QString &songName);
    void displayPlayHistory();
    // virtual void mouseMoveEvent(QMouseEvent* event);
    // virtual void mousePressEvent(QMouseEvent* event);
    // virtual void mouseReleaseEvent(QMouseEvent* event);

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

private:
    Ui::musicplayer *ui;
    QList<QUrl> playList;
    QAudioOutput* output;
    QMediaPlayer* player;
    QUrl currentMediaSource;
    QWidget* currentwidget;
    QListWidget* currentList;
    int index=0;
    bool flag1;

    // QPoint z;
};

#endif // MUSICPLAYER_H
