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
    return a.exec();
}
