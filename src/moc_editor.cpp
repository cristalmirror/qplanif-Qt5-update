/****************************************************************************
** Meta object code from reading C++ file 'editor.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "editor.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editor.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Papel_t_t {
    QByteArrayData data[3];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Papel_t_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Papel_t_t qt_meta_stringdata_Papel_t = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Papel_t"
QT_MOC_LITERAL(1, 8, 14), // "cursor_Changed"
QT_MOC_LITERAL(2, 23, 0) // ""

    },
    "Papel_t\0cursor_Changed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Papel_t[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void Papel_t::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Papel_t *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->cursor_Changed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Papel_t::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Papel_t::cursor_Changed)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject Papel_t::staticMetaObject = { {
    QMetaObject::SuperData::link<QTextEdit::staticMetaObject>(),
    qt_meta_stringdata_Papel_t.data,
    qt_meta_data_Papel_t,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Papel_t::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Papel_t::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Papel_t.stringdata0))
        return static_cast<void*>(this);
    return QTextEdit::qt_metacast(_clname);
}

int Papel_t::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void Papel_t::cursor_Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Editor_t {
    QByteArrayData data[12];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Editor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Editor_t qt_meta_stringdata_Editor = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Editor"
QT_MOC_LITERAL(1, 7, 8), // "re_carga"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 11), // "const char*"
QT_MOC_LITERAL(4, 29, 7), // "newFile"
QT_MOC_LITERAL(5, 37, 4), // "load"
QT_MOC_LITERAL(6, 42, 8), // "fileName"
QT_MOC_LITERAL(7, 51, 4), // "save"
QT_MOC_LITERAL(8, 56, 6), // "saveAs"
QT_MOC_LITERAL(9, 63, 5), // "close"
QT_MOC_LITERAL(10, 69, 12), // "RemarcaLinea"
QT_MOC_LITERAL(11, 82, 13) // "update_status"

    },
    "Editor\0re_carga\0\0const char*\0newFile\0"
    "load\0fileName\0save\0saveAs\0close\0"
    "RemarcaLinea\0update_status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Editor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   62,    2, 0x0a /* Public */,
       5,    0,   63,    2, 0x0a /* Public */,
       5,    1,   64,    2, 0x0a /* Public */,
       7,    0,   67,    2, 0x0a /* Public */,
       8,    0,   68,    2, 0x0a /* Public */,
       9,    0,   69,    2, 0x0a /* Public */,
      10,    1,   70,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void Editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Editor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->re_carga((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 1: _t->newFile(); break;
        case 2: _t->load(); break;
        case 3: _t->load((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 4: _t->save(); break;
        case 5: _t->saveAs(); break;
        case 6: _t->close(); break;
        case 7: _t->RemarcaLinea((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->update_status(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Editor::*)(const char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Editor::re_carga)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Editor::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Editor.data,
    qt_meta_data_Editor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Editor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Editor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Editor::re_carga(const char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
