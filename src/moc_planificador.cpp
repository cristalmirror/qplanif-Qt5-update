/****************************************************************************
** Meta object code from reading C++ file 'planificador.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "planificador.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'planificador.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Planificador_t {
    QByteArrayData data[21];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Planificador_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Planificador_t qt_meta_stringdata_Planificador = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Planificador"
QT_MOC_LITERAL(1, 13, 12), // "tareasNuevas"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "ParseErrorEn"
QT_MOC_LITERAL(4, 40, 6), // "newDoc"
QT_MOC_LITERAL(5, 47, 6), // "cargar"
QT_MOC_LITERAL(6, 54, 11), // "const char*"
QT_MOC_LITERAL(7, 66, 8), // "closeDoc"
QT_MOC_LITERAL(8, 75, 15), // "toggleStatusBar"
QT_MOC_LITERAL(9, 91, 13), // "toggleHerrBar"
QT_MOC_LITERAL(10, 105, 10), // "togglePaso"
QT_MOC_LITERAL(11, 116, 20), // "planificador_elegido"
QT_MOC_LITERAL(12, 137, 15), // "recurso_elegido"
QT_MOC_LITERAL(13, 153, 9), // "actualiza"
QT_MOC_LITERAL(14, 163, 3), // "hay"
QT_MOC_LITERAL(15, 167, 10), // "setQuantum"
QT_MOC_LITERAL(16, 178, 7), // "setPaso"
QT_MOC_LITERAL(17, 186, 12), // "mostrarAyuda"
QT_MOC_LITERAL(18, 199, 14), // "mostrarAutores"
QT_MOC_LITERAL(19, 214, 15), // "setTareasNuevas"
QT_MOC_LITERAL(20, 230, 7) // "aboutQt"

    },
    "Planificador\0tareasNuevas\0\0ParseErrorEn\0"
    "newDoc\0cargar\0const char*\0closeDoc\0"
    "toggleStatusBar\0toggleHerrBar\0togglePaso\0"
    "planificador_elegido\0recurso_elegido\0"
    "actualiza\0hay\0setQuantum\0setPaso\0"
    "mostrarAyuda\0mostrarAutores\0setTareasNuevas\0"
    "aboutQt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Planificador[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       3,    1,  112,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  115,    2, 0x08 /* Private */,
       5,    0,  116,    2, 0x08 /* Private */,
       5,    1,  117,    2, 0x08 /* Private */,
       7,    0,  120,    2, 0x08 /* Private */,
       8,    0,  121,    2, 0x08 /* Private */,
       9,    0,  122,    2, 0x08 /* Private */,
      10,    1,  123,    2, 0x08 /* Private */,
      11,    1,  126,    2, 0x08 /* Private */,
      12,    1,  129,    2, 0x08 /* Private */,
      13,    1,  132,    2, 0x08 /* Private */,
      13,    0,  135,    2, 0x28 /* Private | MethodCloned */,
      15,    1,  136,    2, 0x08 /* Private */,
      16,    1,  139,    2, 0x08 /* Private */,
      17,    0,  142,    2, 0x08 /* Private */,
      18,    0,  143,    2, 0x08 /* Private */,
      19,    1,  144,    2, 0x08 /* Private */,
      20,    0,  147,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void Planificador::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Planificador *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->tareasNuevas((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->ParseErrorEn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->newDoc(); break;
        case 3: _t->cargar(); break;
        case 4: _t->cargar((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 5: _t->closeDoc(); break;
        case 6: _t->toggleStatusBar(); break;
        case 7: _t->toggleHerrBar(); break;
        case 8: _t->togglePaso((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->planificador_elegido((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->recurso_elegido((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->actualiza((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->actualiza(); break;
        case 13: _t->setQuantum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setPaso((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->mostrarAyuda(); break;
        case 16: _t->mostrarAutores(); break;
        case 17: _t->setTareasNuevas((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->aboutQt(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Planificador::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Planificador::tareasNuevas)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Planificador::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Planificador::ParseErrorEn)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Planificador::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Planificador.data,
    qt_meta_data_Planificador,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Planificador::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Planificador::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Planificador.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Planificador::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void Planificador::tareasNuevas(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Planificador::ParseErrorEn(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
