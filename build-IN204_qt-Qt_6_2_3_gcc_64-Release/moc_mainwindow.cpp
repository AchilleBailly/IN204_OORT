/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../IN204_qt/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[34];
    char stringdata0[345];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 21), // "on_buttonLoad_clicked"
QT_MOC_LITERAL(56, 26), // "on_buttonAddObject_clicked"
QT_MOC_LITERAL(83, 25), // "on_listWidget_itemClicked"
QT_MOC_LITERAL(109, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(126, 4), // "item"
QT_MOC_LITERAL(131, 31), // "on_listWidget_itemDoubleClicked"
QT_MOC_LITERAL(163, 26), // "on_listWidget_indexesMoved"
QT_MOC_LITERAL(190, 15), // "QModelIndexList"
QT_MOC_LITERAL(206, 7), // "indexes"
QT_MOC_LITERAL(214, 27), // "on_buttonUpdateList_clicked"
QT_MOC_LITERAL(242, 26), // "on_buttonSaveImage_clicked"
QT_MOC_LITERAL(269, 23), // "on_buttonRender_clicked"
QT_MOC_LITERAL(293, 25), // "on_buttonSaveJson_clicked"
QT_MOC_LITERAL(319, 25) // "on_buttonLoadJson_clicked"

    },
    "MainWindow\0on_pushButton_clicked\0\0"
    "on_buttonLoad_clicked\0on_buttonAddObject_clicked\0"
    "on_listWidget_itemClicked\0QListWidgetItem*\0"
    "item\0on_listWidget_itemDoubleClicked\0"
    "on_listWidget_indexesMoved\0QModelIndexList\0"
    "indexes\0on_buttonUpdateList_clicked\0"
    "on_buttonSaveImage_clicked\0"
    "on_buttonRender_clicked\0"
    "on_buttonSaveJson_clicked\0"
    "on_buttonLoadJson_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    1,   83,    2, 0x08,    4 /* Private */,
       8,    1,   86,    2, 0x08,    6 /* Private */,
       9,    1,   89,    2, 0x08,    8 /* Private */,
      12,    0,   92,    2, 0x08,   10 /* Private */,
      13,    0,   93,    2, 0x08,   11 /* Private */,
      14,    0,   94,    2, 0x08,   12 /* Private */,
      15,    0,   95,    2, 0x08,   13 /* Private */,
      16,    0,   96,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_buttonLoad_clicked(); break;
        case 2: _t->on_buttonAddObject_clicked(); break;
        case 3: _t->on_listWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->on_listWidget_indexesMoved((*reinterpret_cast< const QModelIndexList(*)>(_a[1]))); break;
        case 6: _t->on_buttonUpdateList_clicked(); break;
        case 7: _t->on_buttonSaveImage_clicked(); break;
        case 8: _t->on_buttonRender_clicked(); break;
        case 9: _t->on_buttonSaveJson_clicked(); break;
        case 10: _t->on_buttonLoadJson_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QModelIndexList >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndexList &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
