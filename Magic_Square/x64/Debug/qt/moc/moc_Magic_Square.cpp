/****************************************************************************
** Meta object code from reading C++ file 'Magic_Square.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Magic_Square.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Magic_Square.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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
struct qt_meta_stringdata_CLASSMagic_SquareENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMagic_SquareENDCLASS = QtMocHelpers::stringData(
    "Magic_Square",
    "signalLoadingOK",
    "",
    "PYCreationUnit",
    "index",
    "Rotation",
    "RCRound",
    "RCExplode",
    "slotInit"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMagic_SquareENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[13];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[6];
    char stringdata5[9];
    char stringdata6[8];
    char stringdata7[10];
    char stringdata8[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMagic_SquareENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMagic_SquareENDCLASS_t qt_meta_stringdata_CLASSMagic_SquareENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "Magic_Square"
        QT_MOC_LITERAL(13, 15),  // "signalLoadingOK"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 14),  // "PYCreationUnit"
        QT_MOC_LITERAL(45, 5),  // "index"
        QT_MOC_LITERAL(51, 8),  // "Rotation"
        QT_MOC_LITERAL(60, 7),  // "RCRound"
        QT_MOC_LITERAL(68, 9),  // "RCExplode"
        QT_MOC_LITERAL(78, 8)   // "slotInit"
    },
    "Magic_Square",
    "signalLoadingOK",
    "",
    "PYCreationUnit",
    "index",
    "Rotation",
    "RCRound",
    "RCExplode",
    "slotInit"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMagic_SquareENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   51,    2, 0x08,    2 /* Private */,
       5,    0,   54,    2, 0x08,    4 /* Private */,
       6,    0,   55,    2, 0x08,    5 /* Private */,
       7,    0,   56,    2, 0x08,    6 /* Private */,
       8,    0,   57,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Magic_Square::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSMagic_SquareENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMagic_SquareENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMagic_SquareENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Magic_Square, std::true_type>,
        // method 'signalLoadingOK'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'PYCreationUnit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'Rotation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RCRound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RCExplode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotInit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Magic_Square::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Magic_Square *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalLoadingOK(); break;
        case 1: _t->PYCreationUnit((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->Rotation(); break;
        case 3: _t->RCRound(); break;
        case 4: _t->RCExplode(); break;
        case 5: _t->slotInit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Magic_Square::*)();
            if (_t _q_method = &Magic_Square::signalLoadingOK; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Magic_Square::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Magic_Square::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMagic_SquareENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Magic_Square::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Magic_Square::signalLoadingOK()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
