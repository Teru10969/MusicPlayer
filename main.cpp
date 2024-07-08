#include "musicplayer.h"
#include <QApplication>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    musicplayer w;
    w.show();

    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("MusicPlayer.db");
    if(!db.open()){
        qDebug() << "Error: connection with database fail";
    } else {
        qDebug() << "Database: connection ok";
    }

    return a.exec();
}
