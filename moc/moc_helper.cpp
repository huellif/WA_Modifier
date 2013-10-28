/****************************************************************************
** Meta object code from reading C++ file 'helper.h'
**
** Created: Mon 28. Oct 17:31:56 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../helper.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'helper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Helper[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x02,
      24,   17,    7,    7, 0x02,
      36,    7,    7,    7, 0x02,
      43,    7,    7,    7, 0x02,
      51,    7,    7,    7, 0x02,
      63,    7,    7,    7, 0x02,
      74,   70,    7,    7, 0x02,
      88,    7,    7,    7, 0x02,
      94,    7,    7,    7, 0x02,
     103,    7,    7,    7, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_Helper[] = {
    "Helper\0\0launch()\0hidden\0close(bool)\0"
    "hide()\0reset()\0resetNote()\0note()\0mif\0"
    "icon(QString)\0del()\0reboot()\0clear()\0"
};

const QMetaObject Helper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Helper,
      qt_meta_data_Helper, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Helper::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Helper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Helper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Helper))
        return static_cast<void*>(const_cast< Helper*>(this));
    return QObject::qt_metacast(_clname);
}

int Helper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: launch(); break;
        case 1: close((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: hide(); break;
        case 3: reset(); break;
        case 4: resetNote(); break;
        case 5: note(); break;
        case 6: icon((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: del(); break;
        case 8: reboot(); break;
        case 9: clear(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
