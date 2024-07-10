#-------------------------------------------------
#
# Project created by QtCreator 2024-07-04T11:15:50
#
#-------------------------------------------------

QT       += core gui network multimedia sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = musicplayer_demo
TEMPLATE = app


SOURCES += main.cpp\
        database.cpp \
        musicplayer.cpp \
        network.cpp

HEADERS  += musicplayer.h \
    database.h \
    network.h

FORMS    += musicplayer.ui

RESOURCES += \
    res.qrc \
    res/res.qrc
