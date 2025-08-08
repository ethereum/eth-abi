#ifndef MYPYC_NATIVE_5b955ff1c0e1f317068d_H
#define MYPYC_NATIVE_5b955ff1c0e1f317068d_H
#include <Python.h>
#include <CPy.h>
#ifndef MYPYC_DECLARED_tuple_T2OO
#define MYPYC_DECLARED_tuple_T2OO
typedef struct tuple_T2OO {
    PyObject *f0;
    PyObject *f1;
} tuple_T2OO;
#endif

#ifndef MYPYC_DECLARED_tuple_T3OOO
#define MYPYC_DECLARED_tuple_T3OOO
typedef struct tuple_T3OOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
} tuple_T3OOO;
#endif

#ifndef MYPYC_DECLARED_tuple_T2II
#define MYPYC_DECLARED_tuple_T2II
typedef struct tuple_T2II {
    CPyTagged f0;
    CPyTagged f1;
} tuple_T2II;
#endif

#ifndef MYPYC_DECLARED_tuple_T2IO
#define MYPYC_DECLARED_tuple_T2IO
typedef struct tuple_T2IO {
    CPyTagged f0;
    PyObject *f1;
} tuple_T2IO;
#endif

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
    PyObject *__frames;
    CPyTagged __total_offset;
} faster_eth_abi___io___ContextFramesBytesIOObject;

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


struct export_table_5b955ff1c0e1f317068d {
    PyObject **CPyStatic_abi___default_codec;
    PyObject **CPyStatic_abi___encode;
    PyObject **CPyStatic_abi___decode;
    PyObject **CPyStatic_abi___is_encodable;
    PyObject **CPyStatic_abi___is_encodable_type;
    char (*CPyDef_abi_____top_level__)(void);
    char (*CPyDef_constants_____top_level__)(void);
    PyTypeObject **CPyType_from_type_str___parse_type_str_env;
    PyObject *(*CPyDef_from_type_str___parse_type_str_env)(void);
    PyTypeObject **CPyType_from_type_str___decorator_parse_type_str_env;
    PyObject *(*CPyDef_from_type_str___decorator_parse_type_str_env)(void);
    PyTypeObject **CPyType_from_type_str___decorator_parse_type_str_obj;
    PyObject *(*CPyDef_from_type_str___decorator_parse_type_str_obj)(void);
    PyTypeObject **CPyType_from_type_str___new_from_type_str_parse_type_str_decorator_obj;
    PyObject *(*CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj)(void);
    PyTypeObject **CPyType_from_type_str___parse_tuple_type_str_env;
    PyObject *(*CPyDef_from_type_str___parse_tuple_type_str_env)(void);
    PyTypeObject **CPyType_from_type_str___new_from_type_str_parse_tuple_type_str_obj;
    PyObject *(*CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj)(void);
    PyObject *(*CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_cls, PyObject *cpy_r_type_str, PyObject *cpy_r_registry);
    PyObject *(*CPyDef_from_type_str___decorator_parse_type_str_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef_from_type_str___decorator_parse_type_str_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_old_from_type_str);
    PyObject *(*CPyDef_from_type_str___parse_type_str)(PyObject *cpy_r_expected_base, char cpy_r_with_arrlist);
    PyObject *(*CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_cls, PyObject *cpy_r_type_str, PyObject *cpy_r_registry);
    PyObject *(*CPyDef_from_type_str___parse_tuple_type_str)(PyObject *cpy_r_old_from_type_str);
    char (*CPyDef_from_type_str_____top_level__)(void);
    PyTypeObject **CPyType_io___ContextFramesBytesIO;
    PyObject *(*CPyDef_io___ContextFramesBytesIO)(PyObject *cpy_r_initial_bytes);
    char (*CPyDef_io___ContextFramesBytesIO_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_initial_bytes);
    char (*CPyDef_io___ContextFramesBytesIO_____init___3__ContextFramesBytesIO_glue)(PyObject *cpy_r_self, PyObject *cpy_r_initial_bytes);
    char (*CPyDef_io___ContextFramesBytesIO___seek_in_frame)(PyObject *cpy_r_self, CPyTagged cpy_r_pos, PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
    char (*CPyDef_io___ContextFramesBytesIO___seek_in_frame__ContextFramesBytesIO_glue)(PyObject *cpy_r_self, CPyTagged cpy_r_pos, PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
    char (*CPyDef_io___ContextFramesBytesIO___push_frame)(PyObject *cpy_r_self, CPyTagged cpy_r_offset);
    char (*CPyDef_io___ContextFramesBytesIO___push_frame__ContextFramesBytesIO_glue)(PyObject *cpy_r_self, CPyTagged cpy_r_offset);
    PyObject *(*CPyDef_io___ContextFramesBytesIO___pop_frame)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_io___ContextFramesBytesIO___pop_frame__ContextFramesBytesIO_glue)(PyObject *cpy_r_self);
    char (*CPyDef_io_____top_level__)(void);
    PyObject **CPyStatic_packed___default_encoder_packed;
    PyObject **CPyStatic_packed___encode_packed;
    PyObject **CPyStatic_packed___is_encodable_packed;
    char (*CPyDef_packed_____top_level__)(void);
    char (*CPyDef_tools_____top_level__)(void);
    PyObject **CPyStatic__strategies___address_strategy;
    PyObject **CPyStatic__strategies___bool_strategy;
    PyObject **CPyStatic__strategies___bytes_strategy;
    PyObject **CPyStatic__strategies___string_strategy;
    PyObject **CPyStatic__strategies___strategy_registry;
    PyObject **CPyStatic__strategies___get_abi_strategy;
    PyTypeObject **CPyType__strategies___StrategyRegistry;
    PyObject *(*CPyDef__strategies___StrategyRegistry)(void);
    char (*CPyDef__strategies___StrategyRegistry_____init__)(PyObject *cpy_r_self);
    char (*CPyDef__strategies___StrategyRegistry___register_strategy)(PyObject *cpy_r_self, PyObject *cpy_r_lookup, PyObject *cpy_r_registration, PyObject *cpy_r_label);
    char (*CPyDef__strategies___StrategyRegistry___unregister_strategy)(PyObject *cpy_r_self, PyObject *cpy_r_lookup_or_label);
    PyObject *(*CPyDef__strategies___StrategyRegistry___get_strategy)(PyObject *cpy_r_self, PyObject *cpy_r_type_str);
    PyObject *(*CPyDef__strategies___get_uint_strategy)(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry);
    PyObject *(*CPyDef__strategies___get_int_strategy)(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry);
    PyObject *(*CPyDef__strategies___get_ufixed_strategy)(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry);
    PyObject *(*CPyDef__strategies___get_fixed_strategy)(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry);
    PyObject *(*CPyDef__strategies___get_bytes_strategy)(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry);
    PyObject *(*CPyDef__strategies___get_array_strategy)(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry);
    PyObject *(*CPyDef__strategies___get_tuple_strategy)(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry);
    char (*CPyDef__strategies_____top_level__)(void);
    char (*CPyDef_utils_____top_level__)(void);
    PyObject **CPyStatic_numeric___abi_decimal_context;
    PyObject **CPyStatic_numeric___ZERO;
    PyObject **CPyStatic_numeric___TEN;
    PyObject **CPyStatic_numeric___Decimal;
    PyTypeObject **CPyType_numeric___scale_places_env;
    PyObject *(*CPyDef_numeric___scale_places_env)(void);
    PyTypeObject **CPyType_numeric___f_scale_places_obj;
    PyObject *(*CPyDef_numeric___f_scale_places_obj)(void);
    CPyTagged (*CPyDef_numeric___ceil32)(CPyTagged cpy_r_x);
    tuple_T2II (*CPyDef_numeric___compute_unsigned_integer_bounds)(CPyTagged cpy_r_num_bits);
    tuple_T2II (*CPyDef_numeric___compute_signed_integer_bounds)(CPyTagged cpy_r_num_bits);
    tuple_T2OO (*CPyDef_numeric___compute_unsigned_fixed_bounds)(CPyTagged cpy_r_num_bits, CPyTagged cpy_r_frac_places);
    tuple_T2OO (*CPyDef_numeric___compute_signed_fixed_bounds)(CPyTagged cpy_r_num_bits, CPyTagged cpy_r_frac_places);
    PyObject *(*CPyDef_numeric___f_scale_places_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef_numeric___f_scale_places_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_x);
    PyObject *(*CPyDef_numeric___scale_places)(CPyTagged cpy_r_places);
    char (*CPyDef_numeric_____top_level__)(void);
    PyObject *(*CPyDef_padding___zpad)(PyObject *cpy_r_value, CPyTagged cpy_r_length);
    PyObject *(*CPyDef_padding___zpad32)(PyObject *cpy_r_value);
    PyObject *(*CPyDef_padding___zpad_right)(PyObject *cpy_r_value, CPyTagged cpy_r_length);
    PyObject *(*CPyDef_padding___zpad32_right)(PyObject *cpy_r_value);
    PyObject *(*CPyDef_padding___fpad)(PyObject *cpy_r_value, CPyTagged cpy_r_length);
    PyObject *(*CPyDef_padding___fpad32)(PyObject *cpy_r_value);
    char (*CPyDef_padding_____top_level__)(void);
    PyObject *(*CPyDef_string___abbr)(PyObject *cpy_r_value, CPyTagged cpy_r_limit);
    char (*CPyDef_string_____top_level__)(void);
    char (*CPyDef_validation___validate_bytes_param)(PyObject *cpy_r_param, PyObject *cpy_r_param_name);
    char (*CPyDef_validation___validate_list_like_param)(PyObject *cpy_r_param, PyObject *cpy_r_param_name);
    char (*CPyDef_validation_____top_level__)(void);
};
#endif
