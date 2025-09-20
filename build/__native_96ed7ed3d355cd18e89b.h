#ifndef MYPYC_NATIVE_96ed7ed3d355cd18e89b_H
#define MYPYC_NATIVE_96ed7ed3d355cd18e89b_H
#include <Python.h>
#include <CPy.h>
#ifndef MYPYC_DECLARED_tuple_T3OOO
#define MYPYC_DECLARED_tuple_T3OOO
typedef struct tuple_T3OOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
} tuple_T3OOO;
#endif

#ifndef MYPYC_DECLARED_tuple_T2OO
#define MYPYC_DECLARED_tuple_T2OO
typedef struct tuple_T2OO {
    PyObject *f0;
    PyObject *f1;
} tuple_T2OO;
#endif

#ifndef MYPYC_DECLARED_tuple_T2IO
#define MYPYC_DECLARED_tuple_T2IO
typedef struct tuple_T2IO {
    CPyTagged f0;
    PyObject *f1;
} tuple_T2IO;
#endif

#ifndef MYPYC_DECLARED_tuple_T2II
#define MYPYC_DECLARED_tuple_T2II
typedef struct tuple_T2II {
    CPyTagged f0;
    CPyTagged f1;
} tuple_T2II;
#endif

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} faster_eth_abi___exceptions___EncodingErrorObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} faster_eth_abi___exceptions___EncodingTypeErrorObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} faster_eth_abi___exceptions___IllegalValueObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} faster_eth_abi___exceptions___ValueOutOfBoundsObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} faster_eth_abi___exceptions___DecodingErrorObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} faster_eth_abi___exceptions___InsufficientDataBytesObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} faster_eth_abi___exceptions___NonEmptyPaddingBytesObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} faster_eth_abi___exceptions___InvalidPointerObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} faster_eth_abi___exceptions___ParseErrorObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} faster_eth_abi___exceptions___ABITypeErrorObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} faster_eth_abi___exceptions___PredicateMappingErrorObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} faster_eth_abi___exceptions___NoEntriesFoundObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} faster_eth_abi___exceptions___MultipleEntriesFoundObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_expected_base;
    char _with_arrlist;
    char _None;
    PyObject *_decorator;
} faster_eth_abi___from_type_str___parse_type_str_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *___mypyc_env__;
    PyObject *_old_from_type_str;
    PyObject *_new_from_type_str;
    PyObject *_expected_base;
    char _with_arrlist;
    char _None;
    PyObject *_decorator;
} faster_eth_abi___from_type_str___decorator_parse_type_str_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} faster_eth_abi___from_type_str___decorator_parse_type_str_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} faster_eth_abi___from_type_str___new_from_type_str_parse_type_str_decorator_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_old_from_type_str;
    PyObject *_new_from_type_str;
} faster_eth_abi___from_type_str___parse_tuple_type_str_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} faster_eth_abi___from_type_str___new_from_type_str_parse_tuple_type_str_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *__strategies;
} faster_eth_abi___tools____strategies___StrategyRegistryObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_scaling_factor;
    PyObject *_f;
    CPyTagged _places;
} faster_eth_abi___utils___numeric___scale_places_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} faster_eth_abi___utils___numeric___f_scale_places_objObject;

#endif
