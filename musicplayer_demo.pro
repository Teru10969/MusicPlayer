#-------------------------------------------------
#
# Project created by QtCreator 2024-07-04T11:15:50
#
#-------------------------------------------------

QT       += core gui multimedia sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = musicplayer_demo
TEMPLATE = app


SOURCES += main.cpp\
        musicplayer.cpp

HEADERS  += musicplayer.h

FORMS    += musicplayer.ui

RESOURCES += \
    res.qrc \
    res/res.qrc
