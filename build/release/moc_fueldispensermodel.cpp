/****************************************************************************
** Meta object code from reading C++ file 'fueldispensermodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/model/fueldispensermodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fueldispensermodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FuelDispenserModel_t {
    QByteArrayData data[25];
    char stringdata0[357];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FuelDispenserModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FuelDispenserModel_t qt_meta_stringdata_FuelDispenserModel = {
    {
QT_MOC_LITERAL(0, 0, 18), // "FuelDispenserModel"
QT_MOC_LITERAL(1, 19, 20), // "currentVolumeChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 16), // "totalCostChanged"
QT_MOC_LITERAL(4, 58, 20), // "pricePerLiterChanged"
QT_MOC_LITERAL(5, 79, 20), // "selectedGradeChanged"
QT_MOC_LITERAL(6, 100, 19), // "presetAmountChanged"
QT_MOC_LITERAL(7, 120, 19), // "targetVolumeChanged"
QT_MOC_LITERAL(8, 140, 25), // "simulatedFuelIndexChanged"
QT_MOC_LITERAL(9, 166, 27), // "simulatedKeypadIndexChanged"
QT_MOC_LITERAL(10, 194, 13), // "currentVolume"
QT_MOC_LITERAL(11, 208, 9), // "totalCost"
QT_MOC_LITERAL(12, 218, 13), // "pricePerLiter"
QT_MOC_LITERAL(13, 232, 13), // "selectedGrade"
QT_MOC_LITERAL(14, 246, 12), // "presetAmount"
QT_MOC_LITERAL(15, 259, 12), // "targetVolume"
QT_MOC_LITERAL(16, 272, 18), // "simulatedFuelIndex"
QT_MOC_LITERAL(17, 291, 20), // "simulatedKeypadIndex"
QT_MOC_LITERAL(18, 312, 9), // "FuelGrade"
QT_MOC_LITERAL(19, 322, 4), // "None"
QT_MOC_LITERAL(20, 327, 6), // "Petrol"
QT_MOC_LITERAL(21, 334, 3), // "E20"
QT_MOC_LITERAL(22, 338, 3), // "E80"
QT_MOC_LITERAL(23, 342, 7), // "Premium"
QT_MOC_LITERAL(24, 350, 6) // "Diesel"

    },
    "FuelDispenserModel\0currentVolumeChanged\0"
    "\0totalCostChanged\0pricePerLiterChanged\0"
    "selectedGradeChanged\0presetAmountChanged\0"
    "targetVolumeChanged\0simulatedFuelIndexChanged\0"
    "simulatedKeypadIndexChanged\0currentVolume\0"
    "totalCost\0pricePerLiter\0selectedGrade\0"
    "presetAmount\0targetVolume\0simulatedFuelIndex\0"
    "simulatedKeypadIndex\0FuelGrade\0None\0"
    "Petrol\0E20\0E80\0Premium\0Diesel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FuelDispenserModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       8,   62, // properties
       1,   94, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,
       7,    0,   59,    2, 0x06 /* Public */,
       8,    0,   60,    2, 0x06 /* Public */,
       9,    0,   61,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::Double, 0x00495103,
      11, QMetaType::Double, 0x00495103,
      12, QMetaType::Double, 0x00495103,
      13, QMetaType::Int, 0x00495103,
      14, QMetaType::Double, 0x00495103,
      15, QMetaType::Double, 0x00495103,
      16, QMetaType::Int, 0x00495103,
      17, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,

 // enums: name, alias, flags, count, data
      18,   18, 0x0,    6,   99,

 // enum data: key, value
      19, uint(FuelDispenserModel::None),
      20, uint(FuelDispenserModel::Petrol),
      21, uint(FuelDispenserModel::E20),
      22, uint(FuelDispenserModel::E80),
      23, uint(FuelDispenserModel::Premium),
      24, uint(FuelDispenserModel::Diesel),

       0        // eod
};

void FuelDispenserModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FuelDispenserModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentVolumeChanged(); break;
        case 1: _t->totalCostChanged(); break;
        case 2: _t->pricePerLiterChanged(); break;
        case 3: _t->selectedGradeChanged(); break;
        case 4: _t->presetAmountChanged(); break;
        case 5: _t->targetVolumeChanged(); break;
        case 6: _t->simulatedFuelIndexChanged(); break;
        case 7: _t->simulatedKeypadIndexChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FuelDispenserModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FuelDispenserModel::currentVolumeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FuelDispenserModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FuelDispenserModel::totalCostChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FuelDispenserModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FuelDispenserModel::pricePerLiterChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FuelDispenserModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FuelDispenserModel::selectedGradeChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FuelDispenserModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FuelDispenserModel::presetAmountChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (FuelDispenserModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FuelDispenserModel::targetVolumeChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (FuelDispenserModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FuelDispenserModel::simulatedFuelIndexChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (FuelDispenserModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FuelDispenserModel::simulatedKeypadIndexChanged)) {
                *result = 7;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<FuelDispenserModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->currentVolume(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->totalCost(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->pricePerLiter(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->selectedGrade(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->presetAmount(); break;
        case 5: *reinterpret_cast< double*>(_v) = _t->targetVolume(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->simulatedFuelIndex(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->simulatedKeypadIndex(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<FuelDispenserModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentVolume(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setTotalCost(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->setPricePerLiter(*reinterpret_cast< double*>(_v)); break;
        case 3: _t->setSelectedGrade(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setPresetAmount(*reinterpret_cast< double*>(_v)); break;
        case 5: _t->setTargetVolume(*reinterpret_cast< double*>(_v)); break;
        case 6: _t->setSimulatedFuelIndex(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->setSimulatedKeypadIndex(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject FuelDispenserModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FuelDispenserModel.data,
    qt_meta_data_FuelDispenserModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FuelDispenserModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FuelDispenserModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FuelDispenserModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FuelDispenserModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void FuelDispenserModel::currentVolumeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FuelDispenserModel::totalCostChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FuelDispenserModel::pricePerLiterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FuelDispenserModel::selectedGradeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void FuelDispenserModel::presetAmountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void FuelDispenserModel::targetVolumeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void FuelDispenserModel::simulatedFuelIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void FuelDispenserModel::simulatedKeypadIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
