#include "database.h"
#include "musicplayer.h"
#include "ui_musicplayer.h"
#include <QSqlError>
#include <QDebug>
#include <QTableWidget>

Database::Database(class musicplayer* parent){
    this->musicplayer=parent;
}

void Database::connectDatabase(){
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("MusicPlayer.db");
    if(!db.open()){
        qDebug() << "Error: connection with database fail";
    } else {
        qDebug() << "Database: connection ok";
    }
}
void Database::upsertPlayHistory(const QString &songName){ //更新播放记录到数据库
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
void Database::displayPlayHistory() { //显示历史播放记录
    QSqlQuery query;
    query.exec("SELECT song_name, play_time FROM PlayHistory ORDER BY play_time DESC");

    // 清除现有条目
    musicplayer->ui->HistoryList->setRowCount(0);
    int row = 0;

    while (query.next()) {
        QString songName = query.value(0).toString();
        QString playTime = query.value(1).toString();
        musicplayer->ui->HistoryList->insertRow(row);
        musicplayer->ui->HistoryList->setItem(row,0,new QTableWidgetItem(songName));
        musicplayer->ui->HistoryList->setItem(row,1,new QTableWidgetItem(playTime));
        row++;
    }

    musicplayer->ui->HistoryList->resizeRowsToContents();
    musicplayer->ui->HistoryList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//填充列宽
    musicplayer->ui->HistoryList->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);// 根据内容设置所有行高
}
