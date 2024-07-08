/****************************************************************************
** Meta object code from reading C++ file 'musicplayer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../musicplayer.h"
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
    "on_previous_clicked",
    "",
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
    "mediaSource"
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
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    0,   87,    2, 0x08,    2 /* Private */,
       4,    0,   88,    2, 0x08,    3 /* Private */,
       5,    0,   89,    2, 0x08,    4 /* Private */,
       6,    1,   90,    2, 0x08,    5 /* Private */,
       9,    0,   93,    2, 0x08,    7 /* Private */,
      10,    0,   94,    2, 0x08,    8 /* Private */,
      11,    1,   95,    2, 0x08,    9 /* Private */,
      13,    0,   98,    2, 0x08,   11 /* Private */,
      14,    0,   99,    2, 0x08,   12 /* Private */,
      15,    1,  100,    2, 0x08,   13 /* Private */,
      17,    1,  103,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::QUrl,   18,

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
        QtPrivate::TypeAndForceComplete<const QUrl &, std::false_type>
    >,
    nullptr
} };

void musicplayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<musicplayer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_previous_clicked(); break;
        case 1: _t->on_next_clicked(); break;
        case 2: _t->on_load_clicked(); break;
        case 3: _t->on_play_clicked(); break;
        case 4: _t->on_LocalMusiclist_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 5: _t->on_timeslider_sliderReleased(); break;
        case 6: _t->on_close_clicked(); break;
        case 7: _t->on_volumeslider_sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_volumeslider_sliderPressed(); break;
        case 9: _t->on_voice_clicked(); break;
        case 10: _t->on_option_currentRowChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_MediaSourceChanged((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        default: ;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
