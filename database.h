#ifndef DATABASE_H
#define DATABASE_H
#include<ui_musicplayer.h>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

class musicplayer;

class Database : public QWidget
{
    Q_OBJECT

public:
    Database(musicplayer* parent);
    musicplayer* musicplayer;
    QSqlDatabase db;
    void connectDatabase();
    void upsertPlayHistory(const QString &songName);
    void displayPlayHistory();
    void deletePlayHistory(const QString &songName);
};

#endif // DATABASE_H
