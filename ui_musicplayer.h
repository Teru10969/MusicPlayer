/********************************************************************************
** Form generated from reading UI file 'musicplayer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICPLAYER_H
#define UI_MUSICPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_musicplayer
{
public:
    QListWidget *listWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *close;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *time1;
    QSlider *timeslider;
    QLabel *time2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *load;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *previous;
    QPushButton *play;
    QPushButton *next;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *voice;
    QSlider *volumeslider;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *download;

    void setupUi(QWidget *musicplayer)
    {
        if (musicplayer->objectName().isEmpty())
            musicplayer->setObjectName("musicplayer");
        musicplayer->resize(847, 573);
        musicplayer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-radius:10px\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(232, 232, 232);\n"
"}\n"
"\n"
"QSlider::add-page:Horizontal#horizontalSlider_music\n"
"{\n"
"	background-color: rgb(205,205,205);height:4px;\n"
"}\n"
"QSlider::sub-page:Horizontal#horizontalSlider_music\n"
"{\n"
"	background-color: rgb(255,78,78);height:4px;\n"
"}\n"
"QSlider::handle:Horizontal#horizontalSlider_music\n"
"{\n"
"	width:14px;border-image: url(:/QTMusicPlayer/hua.png);margin:-4 px -4px;\n"
"}\n"
"QSlider::groove:Horizontal#horizontalSlider_music\n"
"{\n"
"	background:rgb(0, 255, 0);height:4px;\n"
"}\n"
""));
        listWidget = new QListWidget(musicplayer);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(260, 130, 301, 351));
        horizontalLayoutWidget = new QWidget(musicplayer);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(760, 0, 91, 34));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(32, 32));
        pushButton->setMaximumSize(QSize(32, 32));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/QTMusicPlayer/zuixiaohua.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon);

        horizontalLayout->addWidget(pushButton);

        close = new QPushButton(horizontalLayoutWidget);
        close->setObjectName("close");
        close->setMinimumSize(QSize(32, 32));
        close->setMaximumSize(QSize(32, 32));
        close->setStyleSheet(QString::fromUtf8("QPushButton:hover {\n"
"	\n"
"	background-color: rgb(255, 0, 0);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/QTMusicPlayer/guanbi.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        close->setIcon(icon1);

        horizontalLayout->addWidget(close);

        layoutWidget = new QWidget(musicplayer);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(250, 540, 321, 34));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        time1 = new QLabel(layoutWidget);
        time1->setObjectName("time1");
        time1->setMinimumSize(QSize(32, 32));
        time1->setMaximumSize(QSize(32, 32));

        horizontalLayout_2->addWidget(time1);

        timeslider = new QSlider(layoutWidget);
        timeslider->setObjectName("timeslider");
        timeslider->setMaximumSize(QSize(263, 16777215));
        timeslider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(timeslider);

        time2 = new QLabel(layoutWidget);
        time2->setObjectName("time2");
        time2->setMinimumSize(QSize(32, 32));
        time2->setMaximumSize(QSize(32, 32));

        horizontalLayout_2->addWidget(time2);

        layoutWidget1 = new QWidget(musicplayer);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(190, 510, 601, 42));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        load = new QPushButton(layoutWidget1);
        load->setObjectName("load");
        load->setMinimumSize(QSize(32, 32));
        load->setMaximumSize(QSize(32, 32));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/QTMusicPlayer/wenjianjia.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        load->setIcon(icon2);
        load->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(load);

        horizontalSpacer_4 = new QSpacerItem(120, 27, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        previous = new QPushButton(layoutWidget1);
        previous->setObjectName("previous");
        previous->setMinimumSize(QSize(32, 32));
        previous->setMaximumSize(QSize(32, 32));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/QTMusicPlayer/shangyishou.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        previous->setIcon(icon3);
        previous->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(previous);

        play = new QPushButton(layoutWidget1);
        play->setObjectName("play");
        play->setMinimumSize(QSize(32, 32));
        play->setMaximumSize(QSize(32, 32));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/QTMusicPlayer/bofang.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon4.addFile(QString::fromUtf8(":/QTMusicPlayer/zanting.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        play->setIcon(icon4);
        play->setIconSize(QSize(40, 40));
        play->setCheckable(true);

        horizontalLayout_3->addWidget(play);

        next = new QPushButton(layoutWidget1);
        next->setObjectName("next");
        next->setMinimumSize(QSize(32, 32));
        next->setMaximumSize(QSize(32, 32));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/QTMusicPlayer/xiayishou.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        next->setIcon(icon5);
        next->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(next);

        horizontalSpacer_3 = new QSpacerItem(120, 27, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        voice = new QPushButton(layoutWidget1);
        voice->setObjectName("voice");
        voice->setMinimumSize(QSize(32, 32));
        voice->setMaximumSize(QSize(32, 32));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/QTMusicPlayer/yinliang.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon6.addFile(QString::fromUtf8(":/QTMusicPlayer/jingyin.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        voice->setIcon(icon6);
        voice->setIconSize(QSize(32, 32));
        voice->setCheckable(true);

        horizontalLayout_3->addWidget(voice);

        volumeslider = new QSlider(layoutWidget1);
        volumeslider->setObjectName("volumeslider");
        volumeslider->setMaximum(100);
        volumeslider->setValue(100);
        volumeslider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(volumeslider);

        horizontalSpacer_5 = new QSpacerItem(20, 27, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        download = new QPushButton(layoutWidget1);
        download->setObjectName("download");
        download->setMinimumSize(QSize(40, 40));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/QTMusicPlayer/xiazai.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        download->setIcon(icon7);
        download->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(download);


        retranslateUi(musicplayer);

        QMetaObject::connectSlotsByName(musicplayer);
    } // setupUi

    void retranslateUi(QWidget *musicplayer)
    {
        musicplayer->setWindowTitle(QCoreApplication::translate("musicplayer", "musicplayer", nullptr));
        pushButton->setText(QString());
        close->setText(QString());
        time1->setText(QCoreApplication::translate("musicplayer", "00:00", nullptr));
        time2->setText(QCoreApplication::translate("musicplayer", "00:00", nullptr));
        load->setText(QString());
        previous->setText(QString());
        play->setText(QString());
        next->setText(QString());
        voice->setText(QString());
        download->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class musicplayer: public Ui_musicplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICPLAYER_H
