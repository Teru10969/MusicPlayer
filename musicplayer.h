#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include "qaudiooutput.h"
#include "qmediaplayer.h"
#include <QWidget>
#include <QList>
#include <QListWidget>
namespace Ui {
class musicplayer;
}

class musicplayer : public QWidget
{
    Q_OBJECT

public:
    explicit musicplayer(QWidget *parent = 0);
    ~musicplayer();

private slots:

    void on_previous_clicked();

    void on_next_clicked();

    void on_load_clicked();

    void on_play_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_timeslider_sliderReleased();

    void on_close_clicked();

    void on_volumeslider_sliderMoved(int position);

    void on_volumeslider_sliderPressed();

    void on_voice_clicked();

    // void on_timeslider_sliderMoved(int position);

private:
    Ui::musicplayer *ui;
    QList<QUrl> playList;
    QAudioOutput* output;
    QMediaPlayer* player;
    int index=0;
    int saveposition;
};

#endif // MUSICPLAYER_H
