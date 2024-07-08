#include "musicplayer.h"
#include "ui_musicplayer.h"

#include <QMouseEvent>
#include <QPoint>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QObject>

#include <QMediaPlayer>
#include <QAudioOutput>

#include <QDir>
#include <QFileDialog>

#include <QDebug>

#include <QListWidget>
#include <QListWidgetItem>
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
    ui->stackedWidget->setCurrentIndex(0);
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
    connect(ui->timeslider, &QSlider::valueChanged, this, [=](qint64 position) { // 播放时刻随进度条值改变
        ui->time1->setText(QString("%1:%2")
        .arg(position / 1000 / 60, 2, 10, QChar('0'))
        .arg(position / 1000 % 60, 2, 10, QChar('0')));
    });
    connect(player,&QMediaPlayer::playingChanged,ui->play,&QPushButton::setChecked);
    connect(player, &QMediaPlayer::sourceChanged, [&](const QUrl &mediaSource) {
        currentMediaSource = mediaSource;
        flag1=true;
    });
    connect(player,&QMediaPlayer::playingChanged,this,[=](bool flag2){
        if(flag1&&flag2){
            musicplayer::on_MediaSourceChanged(currentMediaSource);
            flag1=false;
        }
    });
     // ui->listWidget->item(0)->setForeground(Qt::red);
     // ui->listWidget_2->item(0)->setForeground(Qt::red);
     // qDebug()<<ui->listWidget->item(0)->text();
    // connect(ui->volumeslider,&QSlider::sliderMoved,output,&QAudioOutput::setVolume);
    // connect(output,&QAudioOutput::setVolume,ui->volumeslider,&QSlider::setSliderPosition);
   // connect(ui->timeslider,&QSlider::sliderReleased, this,&on_timeslider_sliderReleased);
    // connect(ui->timeslider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);
    // connect(ui->timeslider,&QSlider::sliderPressed,player,&QMediaPlayer::setPosition(ui->timeslider->value));
}

musicplayer::~musicplayer()
{
    delete ui;
}
// void musicplayer::mouseMoveEvent(QMouseEvent* event){
//     QWidget::mouseMoveEvent(event);
//     QPoint y=event->globalPos();
//     QPoint x=y-this->z;
//     this->move(x);
// }
// void musicplayer::mousePressEvent(QMouseEvent* event){
//     QWidget::mousePressEvent(event);
//     QPoint x=this->geometry().topLeft();
//     this->z=y-x;
// }
// void musicplayer::mouseReleaseEvent(QMouseEvent* event){
//     QWidget::mouseReleaseEvent(event);
//     this->z=QPoint();
// }

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
    for(QString file:musiclist)//使用范围循环遍历musiclist中的每个文件名
    // playList.append(QUrl::fromLocalFile(path+"/"+file)); //文件放入播放列表里

    // 检查播放列表是否为空
    if (musiclist.isEmpty())
    {
        QMessageBox::information(this, "提示", "选定的目录中没有音乐文件");
        return;
    }

    player->setSource(playList[index]);
    ui->LocalMusiclist->setCurrentRow(0);
}

void musicplayer::updateCurrentPlayingItem()
{
    QWidget* currentwidget=ui->stackedWidget->currentWidget();
    QListWidget* currentList=currentwidget->findChild<QListWidget *>();
    for (int i = 0; i < ui->LocalMusiclist->count(); i++) {
        if (i == index) {
            ui->LocalMusiclist->item(i)->setForeground(Qt::red);
        }else{
            ui->LocalMusiclist->item(i)->setForeground(Qt::black);
        }
        // qDebug()<<i;
        // qDebug()<<ui->LocalMusiclist->item(i);
        // qDebug()<<ui->LocalMusiclist->item(i)->foreground();
    }
}

void musicplayer::on_play_clicked()//播放暂停音乐
{
    // 检查是否选中了音乐
    if (ui->LocalMusiclist->currentRow() == -1) {
        QMessageBox::information(this, "提示", "请先选择一首音乐");
        ui->play->setChecked(false);
        return;
    }
    switch(player->playbackState())
    {
    case QMediaPlayer::PlaybackState::StoppedState://停止状态 播放当前选中音乐
    {
        // ui->play->setChecked(true);
        index=ui->LocalMusiclist->currentRow();
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
    // ui->play->setChecked(true);
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
    // ui->play->setChecked(true);
}


void musicplayer::on_LocalMusiclist_itemDoubleClicked(QListWidgetItem *item)
{
    index =ui->LocalMusiclist->row(item); // 获取双击项目的索引
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
    qDebug()<<volume;
    output->setVolume(volume);
}

void musicplayer::on_voice_clicked()
{
    //按下声音键切换静音状态和音量状态
    output->setMuted(!output->isMuted());
}



void musicplayer::on_LocalMusicList_itemClicked(QListWidgetItem *item)
{
    ui->LocalMusiclist->setCurrentItem(item);
}




void musicplayer::on_option_currentRowChanged(int currentRow)
{
    ui->stackedWidget->setCurrentIndex(currentRow);
}


void musicplayer::upsertPlayHistory(const QString &songName){
    QSqlQuery query;
    // 检查歌曲是否已经存在
    query.prepare("SELECT id FROM PlayHistory WHERE song_name = :song_name");
    query.bindValue(":song_name", songName);
    query.exec();

    if (query.next()) {
        // 如果存在，更新播放时间
        int id = query.value(0).toInt();
        query.prepare("UPDATE PlayHistory SET play_time = CURRENT_TIMESTAMP WHERE id = :id");
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

void musicplayer::on_MediaSourceChanged(const QUrl &mediaSource) {
    // 从媒体源URL中提取歌曲名称（假设歌曲名称是文件名的一部分）
    QString songName = mediaSource.fileName();
    musicplayer::upsertPlayHistory(songName);
}
