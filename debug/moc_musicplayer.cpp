/****************************************************************************
** Meta object code from reading C++ file 'musicplayer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../musicplayer.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSmusicplayerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSmusicplayerENDCLASS = QtMocHelpers::stringData(
    "musicplayer",
    "finish",
    "",
    "Data",
    "on_previous_clicked",
    "on_next_clicked",
    "on_load_clicked",
    "on_play_clicked",
    "on_LocalMusiclist_itemDoubleClicked",
    "QListWidgetItem*",
    "item",
    "on_timeslider_sliderReleased",
    "on_close_clicked",
    "on_volumeslider_sliderMoved",
    "position",
    "on_volumeslider_sliderPressed",
    "on_voice_clicked",
    "on_option_currentRowChanged",
    "currentRow",
    "on_MediaSourceChanged",
    "mediaSource",
    "on_search_clicked",
    "netReply",
    "QNetworkReply*",
    "reply",
    "UrlAnalysis",
    "encode_album_audio_id",
    "on_NetMusicList_itemDoubleClicked",
    "on_stackedWidget_currentChanged",
    "arg1",
    "on_download_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSmusicplayerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  128,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,  131,    2, 0x08,    3 /* Private */,
       5,    0,  132,    2, 0x08,    4 /* Private */,
       6,    0,  133,    2, 0x08,    5 /* Private */,
       7,    0,  134,    2, 0x08,    6 /* Private */,
       8,    1,  135,    2, 0x08,    7 /* Private */,
      11,    0,  138,    2, 0x08,    9 /* Private */,
      12,    0,  139,    2, 0x08,   10 /* Private */,
      13,    1,  140,    2, 0x08,   11 /* Private */,
      15,    0,  143,    2, 0x08,   13 /* Private */,
      16,    0,  144,    2, 0x08,   14 /* Private */,
      17,    1,  145,    2, 0x08,   15 /* Private */,
      19,    1,  148,    2, 0x08,   17 /* Private */,
      21,    0,  151,    2, 0x08,   19 /* Private */,
      22,    1,  152,    2, 0x08,   20 /* Private */,
      25,    1,  155,    2, 0x08,   22 /* Private */,
      27,    1,  158,    2, 0x08,   24 /* Private */,
      28,    1,  161,    2, 0x08,   26 /* Private */,
      30,    0,  164,    2, 0x08,   28 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::QUrl,   20,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::QString, QMetaType::QString,   26,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject musicplayer::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSmusicplayerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSmusicplayerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSmusicplayerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<musicplayer, std::true_type>,
        // method 'finish'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'on_previous_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_next_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_load_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_play_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_LocalMusiclist_itemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_timeslider_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_close_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_volumeslider_sliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_volumeslider_sliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_voice_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_option_currentRowChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_MediaSourceChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QUrl &, std::false_type>,
        // method 'on_search_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'netReply'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'UrlAnalysis'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_NetMusicList_itemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_stackedWidget_currentChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_download_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void musicplayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<musicplayer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finish((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 1: _t->on_previous_clicked(); break;
        case 2: _t->on_next_clicked(); break;
        case 3: _t->on_load_clicked(); break;
        case 4: _t->on_play_clicked(); break;
        case 5: _t->on_LocalMusiclist_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 6: _t->on_timeslider_sliderReleased(); break;
        case 7: _t->on_close_clicked(); break;
        case 8: _t->on_volumeslider_sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->on_volumeslider_sliderPressed(); break;
        case 10: _t->on_voice_clicked(); break;
        case 11: _t->on_option_currentRowChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->on_MediaSourceChanged((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 13: _t->on_search_clicked(); break;
        case 14: _t->netReply((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 15: { QString _r = _t->UrlAnalysis((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->on_NetMusicList_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 17: _t->on_stackedWidget_currentChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->on_download_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (musicplayer::*)(QByteArray );
            if (_t _q_method = &musicplayer::finish; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *musicplayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *musicplayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSmusicplayerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int musicplayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void musicplayer::finish(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
