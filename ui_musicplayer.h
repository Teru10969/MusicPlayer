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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_musicplayer
{
public:
    QHBoxLayout *horizontalLayout_7;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_9;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_7;
    QPushButton *search;
    QLineEdit *searchline;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *close;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_6;
    QListWidget *option;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QHBoxLayout *horizontalLayout_8;
    QListWidget *LocalMusiclist;
    QWidget *page2;
    QHBoxLayout *horizontalLayout_9;
    QListWidget *NetMusicList;
    QWidget *page3;
    QHBoxLayout *horizontalLayout_10;
    QTableWidget *HistoryList;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *load;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *previous;
    QPushButton *play;
    QPushButton *next;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *voice;
    QSlider *volumeslider;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *download;
    QSpacerItem *horizontalSpacer_9;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QLabel *time1;
    QSlider *timeslider;
    QLabel *time2;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QWidget *musicplayer)
    {
        if (musicplayer->objectName().isEmpty())
            musicplayer->setObjectName("musicplayer");
        musicplayer->resize(960, 540);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(musicplayer->sizePolicy().hasHeightForWidth());
        musicplayer->setSizePolicy(sizePolicy);
        musicplayer->setMinimumSize(QSize(960, 540));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/QTMusicPlayer/logo.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        musicplayer->setWindowIcon(icon);
        musicplayer->setStyleSheet(QString::fromUtf8("#widget_3{border-image: url(:/QTMusicPlayer/wallpaper.png);}\n"
"QPushButton {\n"
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
        horizontalLayout_7 = new QHBoxLayout(musicplayer);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 1, 0);
        widget_3 = new QWidget(musicplayer);
        widget_3->setObjectName("widget_3");
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        widget_3->setLayoutDirection(Qt::LeftToRight);
        widget_3->setAutoFillBackground(false);
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_9 = new QWidget(widget_2);
        widget_9->setObjectName("widget_9");
        widget_9->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_9->sizePolicy().hasHeightForWidth());
        widget_9->setSizePolicy(sizePolicy2);
        widget_9->setMinimumSize(QSize(40, 40));
        widget_9->setMaximumSize(QSize(900, 900));
        widget_9->setStyleSheet(QString::fromUtf8("image: url(:/QTMusicPlayer/Music.svg);"));

        horizontalLayout_4->addWidget(widget_9);

        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setTextFormat(Qt::PlainText);

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName("widget_4");
        sizePolicy2.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy2);
        widget_4->setMinimumSize(QSize(500, 0));
        widget_4->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_5 = new QHBoxLayout(widget_4);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 6);
        widget_7 = new QWidget(widget_4);
        widget_7->setObjectName("widget_7");
        sizePolicy2.setHeightForWidth(widget_7->sizePolicy().hasHeightForWidth());
        widget_7->setSizePolicy(sizePolicy2);
        widget_7->setMinimumSize(QSize(0, 40));
        search = new QPushButton(widget_7);
        search->setObjectName("search");
        search->setGeometry(QRect(400, 2, 32, 32));
        sizePolicy.setHeightForWidth(search->sizePolicy().hasHeightForWidth());
        search->setSizePolicy(sizePolicy);
        search->setMinimumSize(QSize(32, 32));
        search->setMaximumSize(QSize(32, 32));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/QTMusicPlayer/chazhao.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        search->setIcon(icon1);
        search->setAutoDefault(false);
        searchline = new QLineEdit(widget_7);
        searchline->setObjectName("searchline");
        searchline->setGeometry(QRect(90, 2, 341, 32));
        sizePolicy.setHeightForWidth(searchline->sizePolicy().hasHeightForWidth());
        searchline->setSizePolicy(sizePolicy);
        searchline->setMinimumSize(QSize(0, 32));
        searchline->setMaximumSize(QSize(16777215, 32));
        searchline->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        searchline->raise();
        search->raise();

        horizontalLayout_5->addWidget(widget_7);


        horizontalLayout_4->addWidget(widget_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, -1, -1, 10);
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(32, 32));
        pushButton->setMaximumSize(QSize(32, 32));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/QTMusicPlayer/zuixiaohua.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon2);
        pushButton->setIconSize(QSize(23, 23));

        horizontalLayout->addWidget(pushButton);

        close = new QPushButton(widget_2);
        close->setObjectName("close");
        close->setMinimumSize(QSize(32, 32));
        close->setMaximumSize(QSize(32, 32));
        close->setStyleSheet(QString::fromUtf8("QPushButton:hover {\n"
"	\n"
"	background-color: rgb(255, 0, 0);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/QTMusicPlayer/guanbi.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        close->setIcon(icon3);
        close->setIconSize(QSize(23, 23));

        horizontalLayout->addWidget(close);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 2);
        horizontalLayout_4->setStretch(4, 1);

        verticalLayout_2->addWidget(widget_2);

        widget_8 = new QWidget(widget_3);
        widget_8->setObjectName("widget_8");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_8->sizePolicy().hasHeightForWidth());
        widget_8->setSizePolicy(sizePolicy3);
        horizontalLayout_6 = new QHBoxLayout(widget_8);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        option = new QListWidget(widget_8);
        new QListWidgetItem(option);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(option);
        __qlistwidgetitem->setBackground(brush);
        new QListWidgetItem(option);
        option->setObjectName("option");
        option->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	border:0px;\n"
"	color:rgb(55,55,55);\n"
"	padding-left:15px;	\n"
"}\n"
" \n"
"/*\345\216\273\351\231\244\347\204\246\347\202\271\350\231\232\347\272\277*/\n"
"*\n"
"{\n"
"	outline:0px;\n"
"}\n"
" \n"
"QListWidget::Item\n"
"{\n"
"	\n"
"	height:50;\n"
"	border:0px solid rgb(255,255,255);	\n"
"	padding-top:1px;\n"
" \n"
"}\n"
" \n"
"QListWidget::Item:hover\n"
"{\n"
"	background-color: rgb(232, 232, 232);\n"
"}\n"
"/*\351\200\211\344\270\255*/\n"
"QListWidget::Item:selected\n"
"{\n"
"	font: 75 16pt \"\351\230\277\351\207\214\345\246\210\345\246\210\346\225\260\351\273\221\344\275\223\";\n"
"	color:rgb(55,55,55);\n"
"	border:0px;\n"
"	background:rgb(221,221,221);	\n"
"}\n"
"\n"
""));

        horizontalLayout_6->addWidget(option);

        stackedWidget = new QStackedWidget(widget_8);
        stackedWidget->setObjectName("stackedWidget");
        page1 = new QWidget();
        page1->setObjectName("page1");
        horizontalLayout_8 = new QHBoxLayout(page1);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        LocalMusiclist = new QListWidget(page1);
        LocalMusiclist->setObjectName("LocalMusiclist");
        LocalMusiclist->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	border:0px;\n"
"    color:rgb(55,55,55);\n"
"    padding-left:15px;	\n"
"    padding-right:15px;	\n"
"}\n"
" \n"
"/*\345\216\273\351\231\244\347\204\246\347\202\271\350\231\232\347\272\277*/\n"
"*\n"
"{\n"
"	outline:0px;\n"
"}\n"
" \n"
"QListWidget::Item\n"
"{\n"
"	height:50;\n"
"    border:0px solid rgb(255,255,255);	\n"
"	padding-top:1px;\n"
"}\n"
" \n"
"QListWidget::Item:hover\n"
"{\n"
"	background-color: rgb(232, 232, 232);\n"
"}\n"
"\n"
"/*\351\200\211\344\270\255*/\n"
"QListWidget::Item:selected\n"
"{\n"
"	font: 75 16pt \"\351\230\277\351\207\214\345\246\210\345\246\210\346\225\260\351\273\221\344\275\223\";\n"
"	color:rgb(55,55,55);\n"
"	border:0px;\n"
"	background:rgb(221,221,221);	\n"
"}\n"
""));
        LocalMusiclist->setSelectionRectVisible(false);

        horizontalLayout_8->addWidget(LocalMusiclist);

        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName("page2");
        horizontalLayout_9 = new QHBoxLayout(page2);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        NetMusicList = new QListWidget(page2);
        NetMusicList->setObjectName("NetMusicList");
        NetMusicList->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	border:0px;\n"
"    color:rgb(55,55,55);\n"
"    padding-left:15px;	\n"
"    padding-right:15px;	\n"
"}\n"
" \n"
"/*\345\216\273\351\231\244\347\204\246\347\202\271\350\231\232\347\272\277*/\n"
"*\n"
"{\n"
"	outline:0px;\n"
"}\n"
" \n"
"QListWidget::Item\n"
"{\n"
"	height:50;\n"
"    border:0px solid rgb(255,255,255);	\n"
"	padding-top:1px;\n"
"}\n"
" \n"
"QListWidget::Item:hover\n"
"{\n"
"	background-color: rgb(232, 232, 232);\n"
"}\n"
"\n"
"/*\351\200\211\344\270\255*/\n"
"QListWidget::Item:selected\n"
"{\n"
"	font: 75 16pt \"\351\230\277\351\207\214\345\246\210\345\246\210\346\225\260\351\273\221\344\275\223\";\n"
"	color:rgb(55,55,55);\n"
"	border:0px;\n"
"	background:rgb(221,221,221);	\n"
"}\n"
""));

        horizontalLayout_9->addWidget(NetMusicList);

        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName("page3");
        horizontalLayout_10 = new QHBoxLayout(page3);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        HistoryList = new QTableWidget(page3);
        if (HistoryList->columnCount() < 2)
            HistoryList->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        HistoryList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        HistoryList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        HistoryList->setObjectName("HistoryList");
        HistoryList->setLayoutDirection(Qt::LeftToRight);
        HistoryList->setStyleSheet(QString::fromUtf8("/* QTableWidget QSS */\n"
"\n"
"/* \350\241\250\345\244\264\346\240\267\345\274\217 */\n"
"QHeaderView::section {\n"
"    background-color: ; /* \347\273\277\350\211\262\350\203\214\346\231\257 */\n"
"    color: ; /* \347\231\275\350\211\262\345\255\227\344\275\223 */\n"
"    padding: 4px;\n"
"    border: none; /* \346\227\240\350\276\271\346\241\206 */\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* \350\241\250\346\240\274\345\206\205\345\256\271\346\240\267\345\274\217 */\n"
"QTableWidget {\n"
"  \n"
"    border: none; /* \346\227\240\350\276\271\346\241\206 */\n"
"    gridline-color: #ddd; /* \347\275\221\346\240\274\347\272\277\351\242\234\350\211\262 */\n"
"    font-size: 14px;\n"
"    selection-background-color: #4CAF50; /* \351\200\211\344\270\255\350\203\214\346\231\257\350\211\262 */\n"
"    selection-color: white; /* \351\200\211\344\270\255\345\255\227\344\275\223\351\242\234\350\211\262 */\n"
"    color:rgb(55,55,55);\n"
"    padding-left:15px;	\n"
"    padding-right:15px;	\n"
"}\n"
"\n"
"/* \350\241\250"
                        "\346\240\274\346\235\241\347\233\256\346\240\267\345\274\217 */\n"
"QTableWidget::item {\n"
"    padding: 4px;\n"
"    height:50;\n"
"	border:0px solid rgb(255,255,255);	\n"
"	padding-top:1px;\n"
"}\n"
"\n"
"/* \350\241\250\346\240\274\346\235\241\347\233\256\351\200\211\344\270\255\346\240\267\345\274\217 */\n"
"QTableWidget::item:selected {\n"
"    font: 75 16pt \"\351\230\277\351\207\214\345\246\210\345\246\210\346\225\260\351\273\221\344\275\223\";\n"
"	color:rgb(55,55,55);\n"
"	border:0px;\n"
"	background:rgb(221,221,221);	\n"
"}\n"
"\n"
"/* \350\241\250\346\240\274\347\272\277\346\235\241\346\240\267\345\274\217 */\n"
"QTableWidget QTableCornerButton::section {\n"
"    background-color: transparent; /* \350\247\222\346\214\211\351\222\256\351\200\217\346\230\216\350\203\214\346\231\257 */\n"
"}\n"
"\n"
"/* \346\273\232\345\212\250\346\235\241\346\240\267\345\274\217 */\n"
"QScrollBar:vertical {\n"
"    background: #f1f1f1;\n"
"    width: 12px;\n"
"    margin: 22px 0 22px 0;\n"
"}\n"
"\n"
"QScrollBar::han"
                        "dle:vertical {\n"
"    background: #888;\n"
"    min-height: 20px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    background: none;\n"
"    height: 20px;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background: none;\n"
"}\n"
"\n"
"Line{\n"
"	height:5\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border-top:2px solid #52DCFE;\n"
"}"));
        HistoryList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        HistoryList->horizontalHeader()->setVisible(true);
        HistoryList->verticalHeader()->setVisible(false);
        HistoryList->verticalHeader()->setCascadingSectionResizes(false);

        horizontalLayout_10->addWidget(HistoryList);

        stackedWidget->addWidget(page3);

        horizontalLayout_6->addWidget(stackedWidget);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 4);

        verticalLayout_2->addWidget(widget_8);

        widget = new QWidget(widget_3);
        widget->setObjectName("widget");
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(16777215, 80));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(widget);
        widget_5->setObjectName("widget_5");
        sizePolicy1.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy1);
        widget_5->setMaximumSize(QSize(16777215, 32));
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        horizontalSpacer_10 = new QSpacerItem(120, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);

        load = new QPushButton(widget_5);
        load->setObjectName("load");
        sizePolicy.setHeightForWidth(load->sizePolicy().hasHeightForWidth());
        load->setSizePolicy(sizePolicy);
        load->setMinimumSize(QSize(32, 32));
        load->setMaximumSize(QSize(32, 32));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/QTMusicPlayer/wenjianjia.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        load->setIcon(icon4);
        load->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(load);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        previous = new QPushButton(widget_5);
        previous->setObjectName("previous");
        sizePolicy.setHeightForWidth(previous->sizePolicy().hasHeightForWidth());
        previous->setSizePolicy(sizePolicy);
        previous->setMinimumSize(QSize(32, 32));
        previous->setMaximumSize(QSize(32, 32));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/QTMusicPlayer/shangyishou.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        previous->setIcon(icon5);
        previous->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(previous, 0, Qt::AlignHCenter);

        play = new QPushButton(widget_5);
        play->setObjectName("play");
        sizePolicy.setHeightForWidth(play->sizePolicy().hasHeightForWidth());
        play->setSizePolicy(sizePolicy);
        play->setMinimumSize(QSize(32, 32));
        play->setMaximumSize(QSize(32, 32));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/QTMusicPlayer/bofang.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon6.addFile(QString::fromUtf8(":/QTMusicPlayer/zanting.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        play->setIcon(icon6);
        play->setIconSize(QSize(40, 40));
        play->setCheckable(true);

        horizontalLayout_2->addWidget(play, 0, Qt::AlignHCenter);

        next = new QPushButton(widget_5);
        next->setObjectName("next");
        sizePolicy.setHeightForWidth(next->sizePolicy().hasHeightForWidth());
        next->setSizePolicy(sizePolicy);
        next->setMinimumSize(QSize(32, 32));
        next->setMaximumSize(QSize(32, 32));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/QTMusicPlayer/xiayishou.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        next->setIcon(icon7);
        next->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(next, 0, Qt::AlignHCenter);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        voice = new QPushButton(widget_5);
        voice->setObjectName("voice");
        sizePolicy.setHeightForWidth(voice->sizePolicy().hasHeightForWidth());
        voice->setSizePolicy(sizePolicy);
        voice->setMinimumSize(QSize(32, 32));
        voice->setMaximumSize(QSize(32, 32));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/QTMusicPlayer/yinliang.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon8.addFile(QString::fromUtf8(":/QTMusicPlayer/jingyin.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        voice->setIcon(icon8);
        voice->setIconSize(QSize(32, 32));
        voice->setCheckable(true);

        horizontalLayout_2->addWidget(voice);

        volumeslider = new QSlider(widget_5);
        volumeslider->setObjectName("volumeslider");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(volumeslider->sizePolicy().hasHeightForWidth());
        volumeslider->setSizePolicy(sizePolicy4);
        volumeslider->setMinimumSize(QSize(0, 0));
        volumeslider->setMaximumSize(QSize(200, 16777215));
        volumeslider->setMaximum(100);
        volumeslider->setValue(100);
        volumeslider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(volumeslider);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        download = new QPushButton(widget_5);
        download->setObjectName("download");
        sizePolicy.setHeightForWidth(download->sizePolicy().hasHeightForWidth());
        download->setSizePolicy(sizePolicy);
        download->setMinimumSize(QSize(32, 32));
        download->setMaximumSize(QSize(32, 32));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/QTMusicPlayer/xiazai.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        download->setIcon(icon9);
        download->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(download);

        horizontalSpacer_9 = new QSpacerItem(200, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);


        verticalLayout->addWidget(widget_5);

        widget_6 = new QWidget(widget);
        widget_6->setObjectName("widget_6");
        widget_6->setMaximumSize(QSize(16777215, 32));
        horizontalLayout_3 = new QHBoxLayout(widget_6);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        time1 = new QLabel(widget_6);
        time1->setObjectName("time1");
        sizePolicy.setHeightForWidth(time1->sizePolicy().hasHeightForWidth());
        time1->setSizePolicy(sizePolicy);
        time1->setMinimumSize(QSize(32, 32));
        time1->setMaximumSize(QSize(32, 32));

        horizontalLayout_3->addWidget(time1);

        timeslider = new QSlider(widget_6);
        timeslider->setObjectName("timeslider");
        sizePolicy.setHeightForWidth(timeslider->sizePolicy().hasHeightForWidth());
        timeslider->setSizePolicy(sizePolicy);
        timeslider->setMaximumSize(QSize(263, 16777215));
        timeslider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(timeslider);

        time2 = new QLabel(widget_6);
        time2->setObjectName("time2");
        sizePolicy.setHeightForWidth(time2->sizePolicy().hasHeightForWidth());
        time2->setSizePolicy(sizePolicy);
        time2->setMinimumSize(QSize(32, 32));
        time2->setMaximumSize(QSize(32, 32));

        horizontalLayout_3->addWidget(time2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout->addWidget(widget_6);


        verticalLayout_2->addWidget(widget);


        horizontalLayout_7->addWidget(widget_3);


        retranslateUi(musicplayer);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(musicplayer);
    } // setupUi

    void retranslateUi(QWidget *musicplayer)
    {
        musicplayer->setWindowTitle(QCoreApplication::translate("musicplayer", "musicplayer", nullptr));
        label->setText(QCoreApplication::translate("musicplayer", "TeruMusicPlayer", nullptr));
        search->setText(QString());
        pushButton->setText(QString());
        close->setText(QString());

        const bool __sortingEnabled = option->isSortingEnabled();
        option->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = option->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("musicplayer", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = option->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("musicplayer", "\347\275\221\347\273\234\351\237\263\344\271\220", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = option->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("musicplayer", "\345\216\206\345\217\262\346\222\255\346\224\276", nullptr));
        option->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem = HistoryList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("musicplayer", "\346\255\214\346\233\262", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = HistoryList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("musicplayer", "\346\222\255\346\224\276\346\227\266\351\227\264", nullptr));
        load->setText(QString());
        previous->setText(QString());
        play->setText(QString());
        next->setText(QString());
        voice->setText(QString());
        download->setText(QString());
        time1->setText(QCoreApplication::translate("musicplayer", "00:00", nullptr));
        time2->setText(QCoreApplication::translate("musicplayer", "00:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class musicplayer: public Ui_musicplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICPLAYER_H
