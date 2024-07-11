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

signals:
    void finish(QByteArray Data);

private slots:

    void on_previous_clicked();//上一首

    void on_next_clicked();//下一首

    void on_load_clicked();//导入本地音乐

    void on_play_clicked();//播放暂停

    void on_LocalMusiclist_itemDoubleClicked(QListWidgetItem *item);//双击播放本地音乐

    void on_timeslider_sliderReleased();//音乐进度条

    void on_close_clicked();//自定义关闭按钮

    void on_volumeslider_sliderMoved(int position);//音量调节

    void on_volumeslider_sliderPressed();//音量调节

    void on_voice_clicked();//静音切换

    void on_option_currentRowChanged(int currentRow);//界面切换

    void on_stackedWidget_currentChanged(int arg1);//设置当前页面和列表

    void on_MediaSourceChanged(const QUrl &mediaSource);//媒体源切换，插入历史播放记录

    void on_search_clicked();//点击搜索

    void on_NetMusicList_itemDoubleClicked(QListWidgetItem *item);//双击播放网络音乐

    void on_download_clicked();//点击下载

    void on_minimize_clicked();//自定义最小化

    void on_maximize_clicked(); //自定义最大化

    void slotShowMenu(const QPoint &pos);//历史播放记录右键菜单

private:



    // QPoint z;
};

#endif // MUSICPLAYER_H
