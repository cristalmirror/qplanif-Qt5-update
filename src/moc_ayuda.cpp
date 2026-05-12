/****************************************************************************
** Meta object code from reading C++ file 'ayuda.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "ayuda.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ayuda.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AyudaCls_t {
    QByteArrayData data[8];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AyudaCls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AyudaCls_t qt_meta_stringdata_AyudaCls = {
    {
QT_MOC_LITERAL(0, 0, 8), // "AyudaCls"
QT_MOC_LITERAL(1, 9, 6), // "newDoc"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 4), // "load"
QT_MOC_LITERAL(4, 22, 11), // "const char*"
QT_MOC_LITERAL(5, 34, 8), // "fileName"
QT_MOC_LITERAL(6, 43, 8), // "closeDoc"
QT_MOC_LITERAL(7, 52, 13) // "ayuda_elegida"

    },
    "AyudaCls\0newDoc\0\0load\0const char*\0"
    "fileName\0closeDoc\0ayuda_elegida"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AyudaCls[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       6,    0,   38,    2, 0x0a /* Public */,
       7,    1,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void AyudaCls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AyudaCls *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newDoc(); break;
        case 1: _t->load((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 2: _t->closeDoc(); break;
        case 3: _t->ayuda_elegida((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AyudaCls::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AyudaCls.data,
    qt_meta_data_AyudaCls,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AyudaCls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AyudaCls::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AyudaCls.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AyudaCls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
