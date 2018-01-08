/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CG/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[267];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_ButtonLine_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 23), // "on_ButtonCircle_clicked"
QT_MOC_LITERAL(4, 58, 21), // "on_ButtonOval_clicked"
QT_MOC_LITERAL(5, 80, 23), // "on_ButtonDoodle_clicked"
QT_MOC_LITERAL(6, 104, 15), // "on_Fill_clicked"
QT_MOC_LITERAL(7, 120, 16), // "on_Curve_clicked"
QT_MOC_LITERAL(8, 137, 18), // "on_Reverse_clicked"
QT_MOC_LITERAL(9, 156, 15), // "on_Move_clicked"
QT_MOC_LITERAL(10, 172, 15), // "on_Zoom_clicked"
QT_MOC_LITERAL(11, 188, 8), // "saveFile"
QT_MOC_LITERAL(12, 197, 18), // "on_Polygon_clicked"
QT_MOC_LITERAL(13, 216, 14), // "on_Cut_clicked"
QT_MOC_LITERAL(14, 231, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(15, 253, 13) // "on_D3_clicked"

    },
    "MainWindow\0on_ButtonLine_clicked\0\0"
    "on_ButtonCircle_clicked\0on_ButtonOval_clicked\0"
    "on_ButtonDoodle_clicked\0on_Fill_clicked\0"
    "on_Curve_clicked\0on_Reverse_clicked\0"
    "on_Move_clicked\0on_Zoom_clicked\0"
    "saveFile\0on_Polygon_clicked\0on_Cut_clicked\0"
    "on_pushButton_clicked\0on_D3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       7,    0,   91,    2, 0x08 /* Private */,
       8,    0,   92,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ButtonLine_clicked(); break;
        case 1: _t->on_ButtonCircle_clicked(); break;
        case 2: _t->on_ButtonOval_clicked(); break;
        case 3: _t->on_ButtonDoodle_clicked(); break;
        case 4: _t->on_Fill_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_Curve_clicked(); break;
        case 6: _t->on_Reverse_clicked(); break;
        case 7: _t->on_Move_clicked(); break;
        case 8: _t->on_Zoom_clicked(); break;
        case 9: _t->saveFile(); break;
        case 10: _t->on_Polygon_clicked(); break;
        case 11: _t->on_Cut_clicked(); break;
        case 12: _t->on_pushButton_clicked(); break;
        case 13: _t->on_D3_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
