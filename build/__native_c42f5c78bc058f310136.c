#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "pythonsupport.c"
#include "__native_c42f5c78bc058f310136.h"
#include "__native_internal_c42f5c78bc058f310136.h"
static int _codec_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_faster_eth_abi____codec_internal, "__name__");
    CPyStatic__codec___globals = PyModule_GetDict(CPyModule_faster_eth_abi____codec_internal);
    if (unlikely(CPyStatic__codec___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef__codec_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_faster_eth_abi____codec_internal);
    Py_CLEAR(modname);
    return -1;
}
static PyMethodDef _codecmodule_methods[] = {
    {"encode_c", (PyCFunction)CPyPy__codec___encode_c, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"decode_c", (PyCFunction)CPyPy__codec___decode_c, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef _codecmodule = {
    PyModuleDef_HEAD_INIT,
    "faster_eth_abi._codec",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    _codecmodule_methods,
    NULL,
};

PyObject *CPyInit_faster_eth_abi____codec(void)
{
    if (CPyModule_faster_eth_abi____codec_internal) {
        Py_INCREF(CPyModule_faster_eth_abi____codec_internal);
        return CPyModule_faster_eth_abi____codec_internal;
    }
    CPyModule_faster_eth_abi____codec_internal = PyModule_Create(&_codecmodule);
    if (unlikely(CPyModule_faster_eth_abi____codec_internal == NULL))
        goto fail;
    if (_codec_exec(CPyModule_faster_eth_abi____codec_internal) != 0)
        goto fail;
    return CPyModule_faster_eth_abi____codec_internal;
    fail:
    return NULL;
}

PyObject *CPyDef__codec___encode_c(PyObject *cpy_r_self, PyObject *cpy_r_types, PyObject *cpy_r_args) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    cpy_r_r0 = CPyStatics[3]; /* 'types' */
    cpy_r_r1 = CPyDef_validation___validate_list_like_param(cpy_r_types, cpy_r_r0);
    if (unlikely(cpy_r_r1 == 2)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "encode_c", 44, CPyStatic__codec___globals);
        goto CPyL12;
    }
    cpy_r_r2 = CPyStatics[4]; /* 'args' */
    cpy_r_r3 = CPyDef_validation___validate_list_like_param(cpy_r_args, cpy_r_r2);
    if (unlikely(cpy_r_r3 == 2)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "encode_c", 45, CPyStatic__codec___globals);
        goto CPyL12;
    }
    cpy_r_r4 = CPyStatics[5]; /* '_registry' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_self, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "encode_c", 47, CPyStatic__codec___globals);
        goto CPyL12;
    }
    cpy_r_r6 = CPyStatics[6]; /* 'get_tuple_encoder' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r6);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "encode_c", 47, CPyStatic__codec___globals);
        goto CPyL12;
    }
    cpy_r_r8 = PyList_New(0);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "encode_c", 47, CPyStatic__codec___globals);
        goto CPyL13;
    }
    cpy_r_r9 = CPyList_Extend(cpy_r_r8, cpy_r_types);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "encode_c", 47, CPyStatic__codec___globals);
        goto CPyL14;
    } else
        goto CPyL15;
CPyL6: ;
    cpy_r_r10 = PyList_AsTuple(cpy_r_r8);
    CPy_DECREF_NO_IMM(cpy_r_r8);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "encode_c", 47, CPyStatic__codec___globals);
        goto CPyL13;
    }
    cpy_r_r11 = PyDict_New();
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "encode_c", 47, CPyStatic__codec___globals);
        goto CPyL16;
    }
    cpy_r_r12 = PyObject_Call(cpy_r_r7, cpy_r_r10, cpy_r_r11);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "encode_c", 47, CPyStatic__codec___globals);
        goto CPyL12;
    }
    PyObject *cpy_r_r13[1] = {cpy_r_args};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = PyObject_Vectorcall(cpy_r_r12, cpy_r_r14, 1, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "encode_c", 49, CPyStatic__codec___globals);
        goto CPyL12;
    }
    if (likely(PyBytes_Check(cpy_r_r15) || PyByteArray_Check(cpy_r_r15)))
        cpy_r_r16 = cpy_r_r15;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_codec.py", "encode_c", 49, CPyStatic__codec___globals, "bytes", cpy_r_r15);
        goto CPyL12;
    }
    return cpy_r_r16;
CPyL12: ;
    cpy_r_r17 = NULL;
    return cpy_r_r17;
CPyL13: ;
    CPy_DecRef(cpy_r_r7);
    goto CPyL12;
CPyL14: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r8);
    goto CPyL12;
CPyL15: ;
    CPy_DECREF(cpy_r_r9);
    goto CPyL6;
CPyL16: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    goto CPyL12;
}

PyObject *CPyPy__codec___encode_c(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"self", "types", "args", 0};
    static CPyArg_Parser parser = {"OOO:encode_c", kwlist, 0};
    PyObject *obj_self;
    PyObject *obj_types;
    PyObject *obj_args;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_self, &obj_types, &obj_args)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_types = obj_types;
    PyObject *arg_args = obj_args;
    PyObject *retval = CPyDef__codec___encode_c(arg_self, arg_types, arg_args);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/_codec.py", "encode_c", 26, CPyStatic__codec___globals);
    return NULL;
}

PyObject *CPyDef__codec___decode_c(PyObject *cpy_r_self, PyObject *cpy_r_types, PyObject *cpy_r_data, char cpy_r_strict) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject **cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject **cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    if (cpy_r_strict != 2) goto CPyL2;
    cpy_r_strict = 1;
CPyL2: ;
    cpy_r_r0 = CPyStatics[3]; /* 'types' */
    cpy_r_r1 = CPyDef_validation___validate_list_like_param(cpy_r_types, cpy_r_r0);
    if (unlikely(cpy_r_r1 == 2)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "decode_c", 76, CPyStatic__codec___globals);
        goto CPyL15;
    }
    cpy_r_r2 = CPyStatics[7]; /* 'data' */
    cpy_r_r3 = CPyDef_validation___validate_bytes_param(cpy_r_data, cpy_r_r2);
    if (unlikely(cpy_r_r3 == 2)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "decode_c", 77, CPyStatic__codec___globals);
        goto CPyL15;
    }
    cpy_r_r4 = CPyStatics[5]; /* '_registry' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_self, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "decode_c", 79, CPyStatic__codec___globals);
        goto CPyL15;
    }
    cpy_r_r6 = CPyStatics[8]; /* 'get_tuple_decoder' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r6);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "decode_c", 79, CPyStatic__codec___globals);
        goto CPyL15;
    }
    cpy_r_r8 = PyList_New(0);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "decode_c", 79, CPyStatic__codec___globals);
        goto CPyL16;
    }
    cpy_r_r9 = CPyList_Extend(cpy_r_r8, cpy_r_types);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "decode_c", 79, CPyStatic__codec___globals);
        goto CPyL17;
    } else
        goto CPyL18;
CPyL8: ;
    cpy_r_r10 = CPyStatics[9]; /* 'strict' */
    cpy_r_r11 = PyList_AsTuple(cpy_r_r8);
    CPy_DECREF_NO_IMM(cpy_r_r8);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "decode_c", 79, CPyStatic__codec___globals);
        goto CPyL16;
    }
    cpy_r_r12 = cpy_r_strict ? Py_True : Py_False;
    cpy_r_r13 = CPyDict_Build(1, cpy_r_r10, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "decode_c", 79, CPyStatic__codec___globals);
        goto CPyL19;
    }
    cpy_r_r14 = PyObject_Call(cpy_r_r7, cpy_r_r11, cpy_r_r13);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r11);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "decode_c", 79, CPyStatic__codec___globals);
        goto CPyL15;
    }
    cpy_r_r15 = CPyStatics[10]; /* 'stream_class' */
    PyObject *cpy_r_r16[2] = {cpy_r_self, cpy_r_data};
    cpy_r_r17 = (PyObject **)&cpy_r_r16;
    cpy_r_r18 = PyObject_VectorcallMethod(cpy_r_r15, cpy_r_r17, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "decode_c", 80, CPyStatic__codec___globals);
        goto CPyL20;
    }
    PyObject *cpy_r_r19[1] = {cpy_r_r18};
    cpy_r_r20 = (PyObject **)&cpy_r_r19;
    cpy_r_r21 = PyObject_Vectorcall(cpy_r_r14, cpy_r_r20, 1, 0);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "decode_c", 82, CPyStatic__codec___globals);
        goto CPyL21;
    }
    CPy_DECREF(cpy_r_r18);
    if (likely(PyTuple_Check(cpy_r_r21)))
        cpy_r_r22 = cpy_r_r21;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_codec.py", "decode_c", 82, CPyStatic__codec___globals, "tuple", cpy_r_r21);
        goto CPyL15;
    }
    return cpy_r_r22;
CPyL15: ;
    cpy_r_r23 = NULL;
    return cpy_r_r23;
CPyL16: ;
    CPy_DecRef(cpy_r_r7);
    goto CPyL15;
CPyL17: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r8);
    goto CPyL15;
CPyL18: ;
    CPy_DECREF(cpy_r_r9);
    goto CPyL8;
CPyL19: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r11);
    goto CPyL15;
CPyL20: ;
    CPy_DecRef(cpy_r_r14);
    goto CPyL15;
CPyL21: ;
    CPy_DecRef(cpy_r_r18);
    goto CPyL15;
}

PyObject *CPyPy__codec___decode_c(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"self", "types", "data", "strict", 0};
    static CPyArg_Parser parser = {"OOO|O:decode_c", kwlist, 0};
    PyObject *obj_self;
    PyObject *obj_types;
    PyObject *obj_data;
    PyObject *obj_strict = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_self, &obj_types, &obj_data, &obj_strict)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_types = obj_types;
    PyObject *arg_data;
    if (PyBytes_Check(obj_data) || PyByteArray_Check(obj_data))
        arg_data = obj_data;
    else {
        arg_data = NULL;
    }
    if (arg_data != NULL) goto __LL1;
    arg_data = obj_data;
    if (arg_data != NULL) goto __LL1;
    CPy_TypeError("union[bytes, object]", obj_data); 
    goto fail;
__LL1: ;
    char arg_strict;
    if (obj_strict == NULL) {
        arg_strict = 2;
    } else if (unlikely(!PyBool_Check(obj_strict))) {
        CPy_TypeError("bool", obj_strict); goto fail;
    } else
        arg_strict = obj_strict == Py_True;
    PyObject *retval = CPyDef__codec___decode_c(arg_self, arg_types, arg_data, arg_strict);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/_codec.py", "decode_c", 52, CPyStatic__codec___globals);
    return NULL;
}

char CPyDef__codec_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    char cpy_r_r17;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[11]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "<module>", -1, CPyStatic__codec___globals);
        goto CPyL8;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[204]; /* ('TYPE_CHECKING', 'Any', 'Iterable', 'Tuple', 'cast') */
    cpy_r_r6 = CPyStatics[17]; /* 'typing' */
    cpy_r_r7 = CPyStatic__codec___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "<module>", 1, CPyStatic__codec___globals);
        goto CPyL8;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[205]; /* ('Decodable', 'TypeStr') */
    cpy_r_r10 = CPyStatics[20]; /* 'eth_typing' */
    cpy_r_r11 = CPyStatic__codec___globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "<module>", 9, CPyStatic__codec___globals);
        goto CPyL8;
    }
    CPyModule_eth_typing = cpy_r_r12;
    CPy_INCREF(CPyModule_eth_typing);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[206]; /* ('validate_bytes_param', 'validate_list_like_param') */
    cpy_r_r14 = CPyStatics[23]; /* 'faster_eth_abi.utils.validation' */
    cpy_r_r15 = CPyStatic__codec___globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_codec.py", "<module>", 14, CPyStatic__codec___globals);
        goto CPyL8;
    }
    CPyModule_faster_eth_abi___utils___validation = cpy_r_r16;
    CPy_INCREF(CPyModule_faster_eth_abi___utils___validation);
    CPy_DECREF(cpy_r_r16);
    return 1;
CPyL8: ;
    cpy_r_r17 = 2;
    return cpy_r_r17;
}
static int _encoding_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_faster_eth_abi____encoding_internal, "__name__");
    CPyStatic__encoding___globals = PyModule_GetDict(CPyModule_faster_eth_abi____encoding_internal);
    if (unlikely(CPyStatic__encoding___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef__encoding_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_faster_eth_abi____encoding_internal);
    Py_CLEAR(modname);
    return -1;
}
static PyMethodDef _encodingmodule_methods[] = {
    {"encode_tuple", (PyCFunction)CPyPy__encoding___encode_tuple, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"encode_fixed", (PyCFunction)CPyPy__encoding___encode_fixed, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"encode_signed", (PyCFunction)CPyPy__encoding___encode_signed, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"encode_elements", (PyCFunction)CPyPy__encoding___encode_elements, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"encode_elements_dynamic", (PyCFunction)CPyPy__encoding___encode_elements_dynamic, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"encode_uint_256", (PyCFunction)CPyPy__encoding___encode_uint_256, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"int_to_big_endian", (PyCFunction)CPyPy__encoding___int_to_big_endian, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef _encodingmodule = {
    PyModuleDef_HEAD_INIT,
    "faster_eth_abi._encoding",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    _encodingmodule_methods,
    NULL,
};

PyObject *CPyInit_faster_eth_abi____encoding(void)
{
    if (CPyModule_faster_eth_abi____encoding_internal) {
        Py_INCREF(CPyModule_faster_eth_abi____encoding_internal);
        return CPyModule_faster_eth_abi____encoding_internal;
    }
    CPyModule_faster_eth_abi____encoding_internal = PyModule_Create(&_encodingmodule);
    if (unlikely(CPyModule_faster_eth_abi____encoding_internal == NULL))
        goto fail;
    if (_encoding_exec(CPyModule_faster_eth_abi____encoding_internal) != 0)
        goto fail;
    return CPyModule_faster_eth_abi____encoding_internal;
    fail:
    return NULL;
}

PyObject *CPyDef__encoding___encode_tuple(PyObject *cpy_r_values, PyObject *cpy_r_encoders) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    int32_t cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    int32_t cpy_r_r13;
    char cpy_r_r14;
    PyObject **cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    int32_t cpy_r_r19;
    char cpy_r_r20;
    PyObject **cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    int32_t cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    int32_t cpy_r_r28;
    char cpy_r_r29;
    char cpy_r_r30;
    char cpy_r_r31;
    CPyTagged cpy_r_r32;
    CPyTagged cpy_r_r33;
    CPyPtr cpy_r_r34;
    int64_t cpy_r_r35;
    CPyTagged cpy_r_r36;
    char cpy_r_r37;
    int64_t cpy_r_r38;
    CPyPtr cpy_r_r39;
    CPyPtr cpy_r_r40;
    int64_t cpy_r_r41;
    CPyPtr cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    char cpy_r_r46;
    CPyTagged cpy_r_r47;
    PyObject *cpy_r_r48;
    CPyPtr cpy_r_r49;
    int64_t cpy_r_r50;
    CPyTagged cpy_r_r51;
    CPyTagged cpy_r_r52;
    CPyTagged cpy_r_r53;
    CPyTagged cpy_r_head_length;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    CPyPtr cpy_r_r56;
    int64_t cpy_r_r57;
    PyObject *cpy_r_r58;
    CPyTagged cpy_r_r59;
    CPyPtr cpy_r_r60;
    int64_t cpy_r_r61;
    CPyTagged cpy_r_r62;
    char cpy_r_r63;
    int64_t cpy_r_r64;
    CPyPtr cpy_r_r65;
    CPyPtr cpy_r_r66;
    int64_t cpy_r_r67;
    CPyPtr cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    CPyPtr cpy_r_r71;
    int64_t cpy_r_r72;
    CPyTagged cpy_r_r73;
    PyObject *cpy_r_r74;
    char cpy_r_r75;
    CPyTagged cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject **cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    CPyPtr cpy_r_r86;
    CPyPtr cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    CPyTagged cpy_r_r91;
    CPyTagged cpy_r_r92;
    CPyPtr cpy_r_r93;
    int64_t cpy_r_r94;
    CPyTagged cpy_r_r95;
    char cpy_r_r96;
    CPyPtr cpy_r_r97;
    int64_t cpy_r_r98;
    CPyTagged cpy_r_r99;
    char cpy_r_r100;
    int64_t cpy_r_r101;
    CPyPtr cpy_r_r102;
    CPyPtr cpy_r_r103;
    int64_t cpy_r_r104;
    CPyPtr cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    CPyTagged cpy_r_r109;
    PyObject *cpy_r_r110;
    char cpy_r_r111;
    CPyTagged cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    int32_t cpy_r_r116;
    char cpy_r_r117;
    CPyTagged cpy_r_r118;
    CPyTagged cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    cpy_r_r0 = PyList_New(0);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 27, CPyStatic__encoding___globals);
        goto CPyL61;
    }
    cpy_r_r1 = PyList_New(0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 28, CPyStatic__encoding___globals);
        goto CPyL62;
    }
    cpy_r_r2 = PyObject_GetIter(cpy_r_values);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 29, CPyStatic__encoding___globals);
        goto CPyL63;
    }
    cpy_r_r3 = PyObject_GetIter(cpy_r_encoders);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 29, CPyStatic__encoding___globals);
        goto CPyL64;
    }
CPyL4: ;
    cpy_r_r4 = PyIter_Next(cpy_r_r2);
    if (cpy_r_r4 == NULL) goto CPyL65;
    cpy_r_r5 = PyIter_Next(cpy_r_r3);
    if (cpy_r_r5 == NULL) goto CPyL66;
    cpy_r_r6 = CPyStatics[24]; /* 'is_dynamic' */
    cpy_r_r7 = 0 ? Py_True : Py_False;
    cpy_r_r8 = CPyObject_GetAttr3(cpy_r_r5, cpy_r_r6, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 30, CPyStatic__encoding___globals);
        goto CPyL67;
    }
    cpy_r_r9 = PyObject_IsTrue(cpy_r_r8);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r10 = cpy_r_r9 >= 0;
    if (unlikely(!cpy_r_r10)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 30, CPyStatic__encoding___globals);
        goto CPyL67;
    }
    cpy_r_r11 = cpy_r_r9;
    if (!cpy_r_r11) goto CPyL13;
    cpy_r_r12 = Py_None;
    cpy_r_r13 = PyList_Append(cpy_r_r0, cpy_r_r12);
    cpy_r_r14 = cpy_r_r13 >= 0;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 31, CPyStatic__encoding___globals);
        goto CPyL67;
    }
    PyObject *cpy_r_r15[1] = {cpy_r_r4};
    cpy_r_r16 = (PyObject **)&cpy_r_r15;
    cpy_r_r17 = PyObject_Vectorcall(cpy_r_r5, cpy_r_r16, 1, 0);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 32, CPyStatic__encoding___globals);
        goto CPyL68;
    }
    CPy_DECREF(cpy_r_r4);
    if (likely(PyBytes_Check(cpy_r_r17) || PyByteArray_Check(cpy_r_r17)))
        cpy_r_r18 = cpy_r_r17;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 32, CPyStatic__encoding___globals, "bytes", cpy_r_r17);
        goto CPyL69;
    }
    cpy_r_r19 = PyList_Append(cpy_r_r1, cpy_r_r18);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r20 = cpy_r_r19 >= 0;
    if (unlikely(!cpy_r_r20)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 32, CPyStatic__encoding___globals);
        goto CPyL69;
    } else
        goto CPyL4;
CPyL13: ;
    PyObject *cpy_r_r21[1] = {cpy_r_r4};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = PyObject_Vectorcall(cpy_r_r5, cpy_r_r22, 1, 0);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 34, CPyStatic__encoding___globals);
        goto CPyL68;
    }
    CPy_DECREF(cpy_r_r4);
    if (likely(PyBytes_Check(cpy_r_r23) || PyByteArray_Check(cpy_r_r23)))
        cpy_r_r24 = cpy_r_r23;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 34, CPyStatic__encoding___globals, "bytes", cpy_r_r23);
        goto CPyL69;
    }
    cpy_r_r25 = PyList_Append(cpy_r_r0, cpy_r_r24);
    CPy_DECREF(cpy_r_r24);
    cpy_r_r26 = cpy_r_r25 >= 0;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 34, CPyStatic__encoding___globals);
        goto CPyL69;
    }
    cpy_r_r27 = CPyStatics[189]; /* b'' */
    cpy_r_r28 = PyList_Append(cpy_r_r1, cpy_r_r27);
    cpy_r_r29 = cpy_r_r28 >= 0;
    if (unlikely(!cpy_r_r29)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 35, CPyStatic__encoding___globals);
        goto CPyL69;
    } else
        goto CPyL4;
CPyL17: ;
    cpy_r_r30 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r30)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 29, CPyStatic__encoding___globals);
        goto CPyL63;
    }
    cpy_r_r31 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 29, CPyStatic__encoding___globals);
        goto CPyL63;
    }
    cpy_r_r32 = 0;
    cpy_r_r33 = 0;
CPyL20: ;
    cpy_r_r34 = (CPyPtr)&((PyVarObject *)cpy_r_r0)->ob_size;
    cpy_r_r35 = *(int64_t *)cpy_r_r34;
    cpy_r_r36 = cpy_r_r35 << 1;
    cpy_r_r37 = (Py_ssize_t)cpy_r_r33 < (Py_ssize_t)cpy_r_r36;
    if (!cpy_r_r37) goto CPyL28;
    cpy_r_r38 = (Py_ssize_t)cpy_r_r33 >> 1;
    cpy_r_r39 = (CPyPtr)&((PyListObject *)cpy_r_r0)->ob_item;
    cpy_r_r40 = *(CPyPtr *)cpy_r_r39;
    cpy_r_r41 = cpy_r_r38 * 8;
    cpy_r_r42 = cpy_r_r40 + cpy_r_r41;
    cpy_r_r43 = *(PyObject * *)cpy_r_r42;
    CPy_INCREF(cpy_r_r43);
    if (PyBytes_Check(cpy_r_r43) || PyByteArray_Check(cpy_r_r43))
        cpy_r_r44 = cpy_r_r43;
    else {
        cpy_r_r44 = NULL;
    }
    if (cpy_r_r44 != NULL) goto __LL2;
    if (cpy_r_r43 == Py_None)
        cpy_r_r44 = cpy_r_r43;
    else {
        cpy_r_r44 = NULL;
    }
    if (cpy_r_r44 != NULL) goto __LL2;
    CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 37, CPyStatic__encoding___globals, "bytes or None", cpy_r_r43);
    goto CPyL70;
__LL2: ;
    cpy_r_r45 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r46 = cpy_r_r44 == cpy_r_r45;
    if (cpy_r_r46) {
        goto CPyL71;
    } else
        goto CPyL24;
CPyL23: ;
    cpy_r_r47 = 64;
    goto CPyL26;
CPyL24: ;
    if (likely(cpy_r_r44 != Py_None))
        cpy_r_r48 = cpy_r_r44;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 37, CPyStatic__encoding___globals, "bytes", cpy_r_r44);
        goto CPyL70;
    }
    cpy_r_r49 = (CPyPtr)&((PyVarObject *)cpy_r_r48)->ob_size;
    cpy_r_r50 = *(int64_t *)cpy_r_r49;
    CPy_DECREF(cpy_r_r48);
    cpy_r_r51 = cpy_r_r50 << 1;
    cpy_r_r47 = cpy_r_r51;
CPyL26: ;
    cpy_r_r52 = CPyTagged_Add(cpy_r_r32, cpy_r_r47);
    CPyTagged_DECREF(cpy_r_r32);
    CPyTagged_DECREF(cpy_r_r47);
    cpy_r_r32 = cpy_r_r52;
    cpy_r_r53 = cpy_r_r33 + 2;
    cpy_r_r33 = cpy_r_r53;
    goto CPyL20;
CPyL28: ;
    cpy_r_head_length = cpy_r_r32;
    cpy_r_r54 = CPyList_GetSlice(cpy_r_r1, 0, -2);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 38, CPyStatic__encoding___globals);
        goto CPyL72;
    }
    if (likely(PyList_Check(cpy_r_r54)))
        cpy_r_r55 = cpy_r_r54;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 38, CPyStatic__encoding___globals, "list", cpy_r_r54);
        goto CPyL72;
    }
    cpy_r_r56 = (CPyPtr)&((PyVarObject *)cpy_r_r55)->ob_size;
    cpy_r_r57 = *(int64_t *)cpy_r_r56;
    cpy_r_r58 = PyList_New(cpy_r_r57);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 38, CPyStatic__encoding___globals);
        goto CPyL73;
    }
    cpy_r_r59 = 0;
CPyL32: ;
    cpy_r_r60 = (CPyPtr)&((PyVarObject *)cpy_r_r55)->ob_size;
    cpy_r_r61 = *(int64_t *)cpy_r_r60;
    cpy_r_r62 = cpy_r_r61 << 1;
    cpy_r_r63 = (Py_ssize_t)cpy_r_r59 < (Py_ssize_t)cpy_r_r62;
    if (!cpy_r_r63) goto CPyL74;
    cpy_r_r64 = (Py_ssize_t)cpy_r_r59 >> 1;
    cpy_r_r65 = (CPyPtr)&((PyListObject *)cpy_r_r55)->ob_item;
    cpy_r_r66 = *(CPyPtr *)cpy_r_r65;
    cpy_r_r67 = cpy_r_r64 * 8;
    cpy_r_r68 = cpy_r_r66 + cpy_r_r67;
    cpy_r_r69 = *(PyObject * *)cpy_r_r68;
    CPy_INCREF(cpy_r_r69);
    if (likely(PyBytes_Check(cpy_r_r69) || PyByteArray_Check(cpy_r_r69)))
        cpy_r_r70 = cpy_r_r69;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 38, CPyStatic__encoding___globals, "bytes", cpy_r_r69);
        goto CPyL75;
    }
    cpy_r_r71 = (CPyPtr)&((PyVarObject *)cpy_r_r70)->ob_size;
    cpy_r_r72 = *(int64_t *)cpy_r_r71;
    CPy_DECREF(cpy_r_r70);
    cpy_r_r73 = cpy_r_r72 << 1;
    cpy_r_r74 = CPyTagged_StealAsObject(cpy_r_r73);
    cpy_r_r75 = CPyList_SetItemUnsafe(cpy_r_r58, cpy_r_r59, cpy_r_r74);
    if (unlikely(!cpy_r_r75)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 38, CPyStatic__encoding___globals);
        goto CPyL75;
    }
    cpy_r_r76 = cpy_r_r59 + 2;
    cpy_r_r59 = cpy_r_r76;
    goto CPyL32;
CPyL36: ;
    cpy_r_r77 = PyObject_GetIter(cpy_r_r58);
    CPy_DECREF_NO_IMM(cpy_r_r58);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 38, CPyStatic__encoding___globals);
        goto CPyL72;
    }
    cpy_r_r78 = CPyStatic__encoding___globals;
    cpy_r_r79 = CPyStatics[25]; /* 'accumulate' */
    cpy_r_r80 = CPyDict_GetItem(cpy_r_r78, cpy_r_r79);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 38, CPyStatic__encoding___globals);
        goto CPyL76;
    }
    PyObject *cpy_r_r81[1] = {cpy_r_r77};
    cpy_r_r82 = (PyObject **)&cpy_r_r81;
    cpy_r_r83 = PyObject_Vectorcall(cpy_r_r80, cpy_r_r82, 1, 0);
    CPy_DECREF(cpy_r_r80);
    if (unlikely(cpy_r_r83 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 38, CPyStatic__encoding___globals);
        goto CPyL76;
    }
    CPy_DECREF(cpy_r_r77);
    cpy_r_r84 = PyList_New(1);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 38, CPyStatic__encoding___globals);
        goto CPyL77;
    }
    cpy_r_r85 = CPyStatics[192]; /* 0 */
    cpy_r_r86 = (CPyPtr)&((PyListObject *)cpy_r_r84)->ob_item;
    cpy_r_r87 = *(CPyPtr *)cpy_r_r86;
    *(PyObject * *)cpy_r_r87 = cpy_r_r85;
    cpy_r_r88 = CPyList_Extend(cpy_r_r84, cpy_r_r83);
    CPy_DECREF(cpy_r_r83);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 38, CPyStatic__encoding___globals);
        goto CPyL78;
    } else
        goto CPyL79;
CPyL41: ;
    cpy_r_r89 = PyList_AsTuple(cpy_r_r84);
    CPy_DECREF_NO_IMM(cpy_r_r84);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 38, CPyStatic__encoding___globals);
        goto CPyL72;
    }
    cpy_r_r90 = PyList_New(0);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 39, CPyStatic__encoding___globals);
        goto CPyL80;
    }
    cpy_r_r91 = 0;
    cpy_r_r92 = 0;
CPyL44: ;
    cpy_r_r93 = (CPyPtr)&((PyVarObject *)cpy_r_r0)->ob_size;
    cpy_r_r94 = *(int64_t *)cpy_r_r93;
    cpy_r_r95 = cpy_r_r94 << 1;
    cpy_r_r96 = (Py_ssize_t)cpy_r_r91 < (Py_ssize_t)cpy_r_r95;
    if (!cpy_r_r96) goto CPyL81;
    cpy_r_r97 = (CPyPtr)&((PyVarObject *)cpy_r_r89)->ob_size;
    cpy_r_r98 = *(int64_t *)cpy_r_r97;
    cpy_r_r99 = cpy_r_r98 << 1;
    cpy_r_r100 = (Py_ssize_t)cpy_r_r92 < (Py_ssize_t)cpy_r_r99;
    if (!cpy_r_r100) goto CPyL81;
    cpy_r_r101 = (Py_ssize_t)cpy_r_r91 >> 1;
    cpy_r_r102 = (CPyPtr)&((PyListObject *)cpy_r_r0)->ob_item;
    cpy_r_r103 = *(CPyPtr *)cpy_r_r102;
    cpy_r_r104 = cpy_r_r101 * 8;
    cpy_r_r105 = cpy_r_r103 + cpy_r_r104;
    cpy_r_r106 = *(PyObject * *)cpy_r_r105;
    CPy_INCREF(cpy_r_r106);
    if (PyBytes_Check(cpy_r_r106) || PyByteArray_Check(cpy_r_r106))
        cpy_r_r107 = cpy_r_r106;
    else {
        cpy_r_r107 = NULL;
    }
    if (cpy_r_r107 != NULL) goto __LL3;
    if (cpy_r_r106 == Py_None)
        cpy_r_r107 = cpy_r_r106;
    else {
        cpy_r_r107 = NULL;
    }
    if (cpy_r_r107 != NULL) goto __LL3;
    CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 39, CPyStatic__encoding___globals, "bytes or None", cpy_r_r106);
    goto CPyL82;
__LL3: ;
    cpy_r_r108 = CPySequenceTuple_GetItem(cpy_r_r89, cpy_r_r92);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 39, CPyStatic__encoding___globals);
        goto CPyL83;
    }
    if (likely(PyLong_Check(cpy_r_r108)))
        cpy_r_r109 = CPyTagged_FromObject(cpy_r_r108);
    else {
        CPy_TypeError("int", cpy_r_r108); cpy_r_r109 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r108);
    if (unlikely(cpy_r_r109 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 39, CPyStatic__encoding___globals);
        goto CPyL83;
    }
    cpy_r_r110 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r111 = cpy_r_r107 == cpy_r_r110;
    if (cpy_r_r111) {
        goto CPyL84;
    } else
        goto CPyL85;
CPyL50: ;
    cpy_r_r112 = CPyTagged_Add(cpy_r_head_length, cpy_r_r109);
    CPyTagged_DECREF(cpy_r_r109);
    cpy_r_r113 = CPyDef__encoding___encode_uint_256(cpy_r_r112);
    CPyTagged_DECREF(cpy_r_r112);
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 40, CPyStatic__encoding___globals);
        goto CPyL82;
    }
    cpy_r_r114 = cpy_r_r113;
    goto CPyL54;
CPyL52: ;
    if (likely(cpy_r_r107 != Py_None))
        cpy_r_r115 = cpy_r_r107;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 40, CPyStatic__encoding___globals, "bytes", cpy_r_r107);
        goto CPyL82;
    }
    cpy_r_r114 = cpy_r_r115;
CPyL54: ;
    cpy_r_r116 = PyList_Append(cpy_r_r90, cpy_r_r114);
    CPy_DECREF(cpy_r_r114);
    cpy_r_r117 = cpy_r_r116 >= 0;
    if (unlikely(!cpy_r_r117)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 39, CPyStatic__encoding___globals);
        goto CPyL82;
    }
    cpy_r_r118 = cpy_r_r91 + 2;
    cpy_r_r91 = cpy_r_r118;
    cpy_r_r119 = cpy_r_r92 + 2;
    cpy_r_r92 = cpy_r_r119;
    goto CPyL44;
CPyL56: ;
    cpy_r_r120 = PyList_AsTuple(cpy_r_r90);
    CPy_DECREF_NO_IMM(cpy_r_r90);
    if (unlikely(cpy_r_r120 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 39, CPyStatic__encoding___globals);
        goto CPyL86;
    }
    cpy_r_r121 = CPyStatics[189]; /* b'' */
    cpy_r_r122 = CPyBytes_Join(cpy_r_r121, cpy_r_r120);
    CPy_DECREF(cpy_r_r120);
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 44, CPyStatic__encoding___globals);
        goto CPyL86;
    }
    cpy_r_r123 = CPyStatics[189]; /* b'' */
    cpy_r_r124 = CPyBytes_Join(cpy_r_r123, cpy_r_r1);
    CPy_DECREF_NO_IMM(cpy_r_r1);
    if (unlikely(cpy_r_r124 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 44, CPyStatic__encoding___globals);
        goto CPyL87;
    }
    cpy_r_r125 = CPyBytes_Concat(cpy_r_r122, cpy_r_r124);
    CPy_DECREF(cpy_r_r124);
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 44, CPyStatic__encoding___globals);
        goto CPyL61;
    }
    return cpy_r_r125;
CPyL61: ;
    cpy_r_r126 = NULL;
    return cpy_r_r126;
CPyL62: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL61;
CPyL63: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    goto CPyL61;
CPyL64: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    goto CPyL61;
CPyL65: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r3);
    goto CPyL17;
CPyL66: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    goto CPyL17;
CPyL67: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r5);
    goto CPyL61;
CPyL68: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    goto CPyL61;
CPyL69: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r3);
    goto CPyL61;
CPyL70: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_r32);
    goto CPyL61;
CPyL71: ;
    CPy_DECREF(cpy_r_r44);
    goto CPyL23;
CPyL72: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_head_length);
    goto CPyL61;
CPyL73: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_head_length);
    CPy_DecRef(cpy_r_r55);
    goto CPyL61;
CPyL74: ;
    CPy_DECREF_NO_IMM(cpy_r_r55);
    goto CPyL36;
CPyL75: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_head_length);
    CPy_DecRef(cpy_r_r55);
    CPy_DecRef(cpy_r_r58);
    goto CPyL61;
CPyL76: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_head_length);
    CPy_DecRef(cpy_r_r77);
    goto CPyL61;
CPyL77: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_head_length);
    CPy_DecRef(cpy_r_r83);
    goto CPyL61;
CPyL78: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_head_length);
    CPy_DecRef(cpy_r_r84);
    goto CPyL61;
CPyL79: ;
    CPy_DECREF(cpy_r_r88);
    goto CPyL41;
CPyL80: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_head_length);
    CPy_DecRef(cpy_r_r89);
    goto CPyL61;
CPyL81: ;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    CPyTagged_DECREF(cpy_r_head_length);
    CPy_DECREF(cpy_r_r89);
    goto CPyL56;
CPyL82: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_head_length);
    CPy_DecRef(cpy_r_r89);
    CPy_DecRef(cpy_r_r90);
    goto CPyL61;
CPyL83: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_head_length);
    CPy_DecRef(cpy_r_r89);
    CPy_DecRef(cpy_r_r90);
    CPy_DecRef(cpy_r_r107);
    goto CPyL61;
CPyL84: ;
    CPy_DECREF(cpy_r_r107);
    goto CPyL50;
CPyL85: ;
    CPyTagged_DECREF(cpy_r_r109);
    goto CPyL52;
CPyL86: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL61;
CPyL87: ;
    CPy_DecRef(cpy_r_r122);
    goto CPyL61;
}

PyObject *CPyPy__encoding___encode_tuple(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"values", "encoders", 0};
    static CPyArg_Parser parser = {"OO:encode_tuple", kwlist, 0};
    PyObject *obj_values;
    PyObject *obj_encoders;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_values, &obj_encoders)) {
        return NULL;
    }
    PyObject *arg_values = obj_values;
    PyObject *arg_encoders = obj_encoders;
    PyObject *retval = CPyDef__encoding___encode_tuple(arg_values, arg_encoders);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_tuple", 23, CPyStatic__encoding___globals);
    return NULL;
}

PyObject *CPyDef__encoding___encode_fixed(PyObject *cpy_r_value, PyObject *cpy_r_encode_fn, char cpy_r_is_big_endian, CPyTagged cpy_r_data_byte_size) {
    PyObject **cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject **cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r0[1] = {cpy_r_value};
    cpy_r_r1 = (PyObject **)&cpy_r_r0;
    cpy_r_r2 = PyObject_Vectorcall(cpy_r_encode_fn, cpy_r_r1, 1, 0);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_fixed", 53, CPyStatic__encoding___globals);
        goto CPyL9;
    }
    if (likely(PyBytes_Check(cpy_r_r2) || PyByteArray_Check(cpy_r_r2)))
        cpy_r_r3 = cpy_r_r2;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_fixed", 53, CPyStatic__encoding___globals, "bytes", cpy_r_r2);
        goto CPyL9;
    }
    if (!cpy_r_is_big_endian) goto CPyL6;
    cpy_r_r4 = CPyStatics[190]; /* b'\x00' */
    cpy_r_r5 = CPyStatics[26]; /* 'rjust' */
    CPyTagged_INCREF(cpy_r_data_byte_size);
    cpy_r_r6 = CPyTagged_StealAsObject(cpy_r_data_byte_size);
    PyObject *cpy_r_r7[3] = {cpy_r_r3, cpy_r_r6, cpy_r_r4};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = PyObject_VectorcallMethod(cpy_r_r5, cpy_r_r8, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_fixed", 55, CPyStatic__encoding___globals);
        goto CPyL10;
    }
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r6);
    if (likely(PyBytes_Check(cpy_r_r9) || PyByteArray_Check(cpy_r_r9)))
        cpy_r_r10 = cpy_r_r9;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_fixed", 55, CPyStatic__encoding___globals, "bytes", cpy_r_r9);
        goto CPyL9;
    }
    return cpy_r_r10;
CPyL6: ;
    cpy_r_r11 = CPyStatics[190]; /* b'\x00' */
    cpy_r_r12 = CPyStatics[27]; /* 'ljust' */
    CPyTagged_INCREF(cpy_r_data_byte_size);
    cpy_r_r13 = CPyTagged_StealAsObject(cpy_r_data_byte_size);
    PyObject *cpy_r_r14[3] = {cpy_r_r3, cpy_r_r13, cpy_r_r11};
    cpy_r_r15 = (PyObject **)&cpy_r_r14;
    cpy_r_r16 = PyObject_VectorcallMethod(cpy_r_r12, cpy_r_r15, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_fixed", 57, CPyStatic__encoding___globals);
        goto CPyL11;
    }
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r13);
    if (likely(PyBytes_Check(cpy_r_r16) || PyByteArray_Check(cpy_r_r16)))
        cpy_r_r17 = cpy_r_r16;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_fixed", 57, CPyStatic__encoding___globals, "bytes", cpy_r_r16);
        goto CPyL9;
    }
    return cpy_r_r17;
CPyL9: ;
    cpy_r_r18 = NULL;
    return cpy_r_r18;
CPyL10: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r6);
    goto CPyL9;
CPyL11: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r13);
    goto CPyL9;
}

PyObject *CPyPy__encoding___encode_fixed(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"value", "encode_fn", "is_big_endian", "data_byte_size", 0};
    static CPyArg_Parser parser = {"OOOO:encode_fixed", kwlist, 0};
    PyObject *obj_value;
    PyObject *obj_encode_fn;
    PyObject *obj_is_big_endian;
    PyObject *obj_data_byte_size;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_value, &obj_encode_fn, &obj_is_big_endian, &obj_data_byte_size)) {
        return NULL;
    }
    PyObject *arg_value = obj_value;
    PyObject *arg_encode_fn = obj_encode_fn;
    char arg_is_big_endian;
    if (unlikely(!PyBool_Check(obj_is_big_endian))) {
        CPy_TypeError("bool", obj_is_big_endian); goto fail;
    } else
        arg_is_big_endian = obj_is_big_endian == Py_True;
    CPyTagged arg_data_byte_size;
    if (likely(PyLong_Check(obj_data_byte_size)))
        arg_data_byte_size = CPyTagged_BorrowFromObject(obj_data_byte_size);
    else {
        CPy_TypeError("int", obj_data_byte_size); goto fail;
    }
    PyObject *retval = CPyDef__encoding___encode_fixed(arg_value, arg_encode_fn, arg_is_big_endian, arg_data_byte_size);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_fixed", 47, CPyStatic__encoding___globals);
    return NULL;
}

PyObject *CPyDef__encoding___encode_signed(PyObject *cpy_r_value, PyObject *cpy_r_encode_fn, CPyTagged cpy_r_data_byte_size) {
    PyObject **cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject **cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r0[1] = {cpy_r_value};
    cpy_r_r1 = (PyObject **)&cpy_r_r0;
    cpy_r_r2 = PyObject_Vectorcall(cpy_r_encode_fn, cpy_r_r1, 1, 0);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_signed", 65, CPyStatic__encoding___globals);
        goto CPyL11;
    }
    if (likely(PyBytes_Check(cpy_r_r2) || PyByteArray_Check(cpy_r_r2)))
        cpy_r_r3 = cpy_r_r2;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_signed", 65, CPyStatic__encoding___globals, "bytes", cpy_r_r2);
        goto CPyL11;
    }
    cpy_r_r4 = CPyStatics[192]; /* 0 */
    cpy_r_r5 = PyObject_RichCompare(cpy_r_value, cpy_r_r4, 5);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_signed", 66, CPyStatic__encoding___globals);
        goto CPyL12;
    }
    if (unlikely(!PyBool_Check(cpy_r_r5))) {
        CPy_TypeError("bool", cpy_r_r5); cpy_r_r6 = 2;
    } else
        cpy_r_r6 = cpy_r_r5 == Py_True;
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r6 == 2)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_signed", 66, CPyStatic__encoding___globals);
        goto CPyL12;
    }
    if (!cpy_r_r6) goto CPyL8;
    cpy_r_r7 = CPyStatics[190]; /* b'\x00' */
    cpy_r_r8 = CPyStatics[26]; /* 'rjust' */
    CPyTagged_INCREF(cpy_r_data_byte_size);
    cpy_r_r9 = CPyTagged_StealAsObject(cpy_r_data_byte_size);
    PyObject *cpy_r_r10[3] = {cpy_r_r3, cpy_r_r9, cpy_r_r7};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = PyObject_VectorcallMethod(cpy_r_r8, cpy_r_r11, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_signed", 67, CPyStatic__encoding___globals);
        goto CPyL13;
    }
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r9);
    if (likely(PyBytes_Check(cpy_r_r12) || PyByteArray_Check(cpy_r_r12)))
        cpy_r_r13 = cpy_r_r12;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_signed", 67, CPyStatic__encoding___globals, "bytes", cpy_r_r12);
        goto CPyL11;
    }
    return cpy_r_r13;
CPyL8: ;
    cpy_r_r14 = CPyStatics[191]; /* b'\xff' */
    cpy_r_r15 = CPyStatics[26]; /* 'rjust' */
    CPyTagged_INCREF(cpy_r_data_byte_size);
    cpy_r_r16 = CPyTagged_StealAsObject(cpy_r_data_byte_size);
    PyObject *cpy_r_r17[3] = {cpy_r_r3, cpy_r_r16, cpy_r_r14};
    cpy_r_r18 = (PyObject **)&cpy_r_r17;
    cpy_r_r19 = PyObject_VectorcallMethod(cpy_r_r15, cpy_r_r18, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_signed", 69, CPyStatic__encoding___globals);
        goto CPyL14;
    }
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r16);
    if (likely(PyBytes_Check(cpy_r_r19) || PyByteArray_Check(cpy_r_r19)))
        cpy_r_r20 = cpy_r_r19;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_signed", 69, CPyStatic__encoding___globals, "bytes", cpy_r_r19);
        goto CPyL11;
    }
    return cpy_r_r20;
CPyL11: ;
    cpy_r_r21 = NULL;
    return cpy_r_r21;
CPyL12: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL11;
CPyL13: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r9);
    goto CPyL11;
CPyL14: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r16);
    goto CPyL11;
}

PyObject *CPyPy__encoding___encode_signed(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"value", "encode_fn", "data_byte_size", 0};
    static CPyArg_Parser parser = {"OOO:encode_signed", kwlist, 0};
    PyObject *obj_value;
    PyObject *obj_encode_fn;
    PyObject *obj_data_byte_size;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_value, &obj_encode_fn, &obj_data_byte_size)) {
        return NULL;
    }
    PyObject *arg_value = obj_value;
    PyObject *arg_encode_fn = obj_encode_fn;
    CPyTagged arg_data_byte_size;
    if (likely(PyLong_Check(obj_data_byte_size)))
        arg_data_byte_size = CPyTagged_BorrowFromObject(obj_data_byte_size);
    else {
        CPy_TypeError("int", obj_data_byte_size); goto fail;
    }
    PyObject *retval = CPyDef__encoding___encode_signed(arg_value, arg_encode_fn, arg_data_byte_size);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_signed", 60, CPyStatic__encoding___globals);
    return NULL;
}

PyObject *CPyDef__encoding___encode_elements(PyObject *cpy_r_item_encoder, PyObject *cpy_r_value) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    int32_t cpy_r_r7;
    char cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_items_are_dynamic;
    int32_t cpy_r_r14;
    char cpy_r_r15;
    char cpy_r_r16;
    CPyTagged cpy_r_r17;
    char cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    CPyTagged cpy_r_r21;
    CPyTagged cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    CPyPtr cpy_r_r25;
    int64_t cpy_r_r26;
    PyObject *cpy_r_r27;
    CPyTagged cpy_r_r28;
    CPyPtr cpy_r_r29;
    int64_t cpy_r_r30;
    CPyTagged cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    CPyPtr cpy_r_r35;
    int64_t cpy_r_r36;
    CPyTagged cpy_r_r37;
    PyObject *cpy_r_r38;
    char cpy_r_r39;
    CPyTagged cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject **cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    CPyPtr cpy_r_r50;
    CPyPtr cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    CPyPtr cpy_r_r54;
    int64_t cpy_r_r55;
    PyObject *cpy_r_r56;
    CPyTagged cpy_r_r57;
    CPyPtr cpy_r_r58;
    int64_t cpy_r_r59;
    CPyTagged cpy_r_r60;
    char cpy_r_r61;
    PyObject *cpy_r_r62;
    CPyTagged cpy_r_r63;
    CPyTagged cpy_r_r64;
    PyObject *cpy_r_r65;
    char cpy_r_r66;
    CPyTagged cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    cpy_r_r0 = PyList_New(0);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 73, CPyStatic__encoding___globals);
        goto CPyL43;
    }
    cpy_r_r1 = PyObject_GetIter(cpy_r_value);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 73, CPyStatic__encoding___globals);
        goto CPyL44;
    }
CPyL2: ;
    cpy_r_r2 = PyIter_Next(cpy_r_r1);
    if (cpy_r_r2 == NULL) goto CPyL45;
    PyObject *cpy_r_r3[1] = {cpy_r_r2};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_Vectorcall(cpy_r_item_encoder, cpy_r_r4, 1, 0);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 73, CPyStatic__encoding___globals);
        goto CPyL46;
    }
    CPy_DECREF(cpy_r_r2);
    if (likely(PyBytes_Check(cpy_r_r5) || PyByteArray_Check(cpy_r_r5)))
        cpy_r_r6 = cpy_r_r5;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_elements", 73, CPyStatic__encoding___globals, "bytes", cpy_r_r5);
        goto CPyL47;
    }
    cpy_r_r7 = PyList_Append(cpy_r_r0, cpy_r_r6);
    CPy_DECREF(cpy_r_r6);
    cpy_r_r8 = cpy_r_r7 >= 0;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 73, CPyStatic__encoding___globals);
        goto CPyL47;
    } else
        goto CPyL2;
CPyL6: ;
    cpy_r_r9 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 73, CPyStatic__encoding___globals);
        goto CPyL44;
    }
    cpy_r_r10 = PyList_AsTuple(cpy_r_r0);
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 73, CPyStatic__encoding___globals);
        goto CPyL43;
    }
    cpy_r_r11 = CPyStatics[24]; /* 'is_dynamic' */
    cpy_r_r12 = 0 ? Py_True : Py_False;
    cpy_r_r13 = CPyObject_GetAttr3(cpy_r_item_encoder, cpy_r_r11, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 75, CPyStatic__encoding___globals);
        goto CPyL48;
    }
    cpy_r_items_are_dynamic = cpy_r_r13;
    cpy_r_r14 = PyObject_IsTrue(cpy_r_items_are_dynamic);
    CPy_DECREF(cpy_r_items_are_dynamic);
    cpy_r_r15 = cpy_r_r14 >= 0;
    if (unlikely(!cpy_r_r15)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 75, CPyStatic__encoding___globals);
        goto CPyL48;
    }
    cpy_r_r16 = cpy_r_r14;
    if (!cpy_r_r16) goto CPyL13;
    cpy_r_r17 = CPyObject_Size(cpy_r_value);
    if (unlikely(cpy_r_r17 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 76, CPyStatic__encoding___globals);
        goto CPyL48;
    }
    cpy_r_r18 = cpy_r_r17 == 0;
    CPyTagged_DECREF(cpy_r_r17);
    if (!cpy_r_r18) goto CPyL15;
CPyL13: ;
    cpy_r_r19 = CPyStatics[189]; /* b'' */
    cpy_r_r20 = CPyBytes_Join(cpy_r_r19, cpy_r_r10);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 77, CPyStatic__encoding___globals);
        goto CPyL43;
    }
    return cpy_r_r20;
CPyL15: ;
    cpy_r_r21 = CPyObject_Size(cpy_r_value);
    if (unlikely(cpy_r_r21 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 79, CPyStatic__encoding___globals);
        goto CPyL48;
    }
    cpy_r_r22 = CPyTagged_Multiply(64, cpy_r_r21);
    CPyTagged_DECREF(cpy_r_r21);
    cpy_r_r23 = CPySequenceTuple_GetSlice(cpy_r_r10, 0, -2);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 80, CPyStatic__encoding___globals);
        goto CPyL49;
    }
    if (likely(PyTuple_Check(cpy_r_r23)))
        cpy_r_r24 = cpy_r_r23;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_elements", 80, CPyStatic__encoding___globals, "tuple", cpy_r_r23);
        goto CPyL49;
    }
    cpy_r_r25 = (CPyPtr)&((PyVarObject *)cpy_r_r24)->ob_size;
    cpy_r_r26 = *(int64_t *)cpy_r_r25;
    cpy_r_r27 = PyList_New(cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 80, CPyStatic__encoding___globals);
        goto CPyL50;
    }
    cpy_r_r28 = 0;
CPyL20: ;
    cpy_r_r29 = (CPyPtr)&((PyVarObject *)cpy_r_r24)->ob_size;
    cpy_r_r30 = *(int64_t *)cpy_r_r29;
    cpy_r_r31 = cpy_r_r30 << 1;
    cpy_r_r32 = (Py_ssize_t)cpy_r_r28 < (Py_ssize_t)cpy_r_r31;
    if (!cpy_r_r32) goto CPyL51;
    cpy_r_r33 = CPySequenceTuple_GetItem(cpy_r_r24, cpy_r_r28);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 80, CPyStatic__encoding___globals);
        goto CPyL52;
    }
    if (likely(PyBytes_Check(cpy_r_r33) || PyByteArray_Check(cpy_r_r33)))
        cpy_r_r34 = cpy_r_r33;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_elements", 80, CPyStatic__encoding___globals, "bytes", cpy_r_r33);
        goto CPyL52;
    }
    cpy_r_r35 = (CPyPtr)&((PyVarObject *)cpy_r_r34)->ob_size;
    cpy_r_r36 = *(int64_t *)cpy_r_r35;
    CPy_DECREF(cpy_r_r34);
    cpy_r_r37 = cpy_r_r36 << 1;
    cpy_r_r38 = CPyTagged_StealAsObject(cpy_r_r37);
    cpy_r_r39 = CPyList_SetItemUnsafe(cpy_r_r27, cpy_r_r28, cpy_r_r38);
    if (unlikely(!cpy_r_r39)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 80, CPyStatic__encoding___globals);
        goto CPyL52;
    }
    cpy_r_r40 = cpy_r_r28 + 2;
    cpy_r_r28 = cpy_r_r40;
    goto CPyL20;
CPyL25: ;
    cpy_r_r41 = PyObject_GetIter(cpy_r_r27);
    CPy_DECREF_NO_IMM(cpy_r_r27);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 80, CPyStatic__encoding___globals);
        goto CPyL49;
    }
    cpy_r_r42 = CPyStatic__encoding___globals;
    cpy_r_r43 = CPyStatics[25]; /* 'accumulate' */
    cpy_r_r44 = CPyDict_GetItem(cpy_r_r42, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 80, CPyStatic__encoding___globals);
        goto CPyL53;
    }
    PyObject *cpy_r_r45[1] = {cpy_r_r41};
    cpy_r_r46 = (PyObject **)&cpy_r_r45;
    cpy_r_r47 = PyObject_Vectorcall(cpy_r_r44, cpy_r_r46, 1, 0);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 80, CPyStatic__encoding___globals);
        goto CPyL53;
    }
    CPy_DECREF(cpy_r_r41);
    cpy_r_r48 = PyList_New(1);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 80, CPyStatic__encoding___globals);
        goto CPyL54;
    }
    cpy_r_r49 = CPyStatics[192]; /* 0 */
    cpy_r_r50 = (CPyPtr)&((PyListObject *)cpy_r_r48)->ob_item;
    cpy_r_r51 = *(CPyPtr *)cpy_r_r50;
    *(PyObject * *)cpy_r_r51 = cpy_r_r49;
    cpy_r_r52 = CPyList_Extend(cpy_r_r48, cpy_r_r47);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 80, CPyStatic__encoding___globals);
        goto CPyL55;
    } else
        goto CPyL56;
CPyL30: ;
    cpy_r_r53 = PyList_AsTuple(cpy_r_r48);
    CPy_DECREF_NO_IMM(cpy_r_r48);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 80, CPyStatic__encoding___globals);
        goto CPyL49;
    }
    cpy_r_r54 = (CPyPtr)&((PyVarObject *)cpy_r_r53)->ob_size;
    cpy_r_r55 = *(int64_t *)cpy_r_r54;
    cpy_r_r56 = PyTuple_New(cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 81, CPyStatic__encoding___globals);
        goto CPyL57;
    }
    cpy_r_r57 = 0;
CPyL33: ;
    cpy_r_r58 = (CPyPtr)&((PyVarObject *)cpy_r_r53)->ob_size;
    cpy_r_r59 = *(int64_t *)cpy_r_r58;
    cpy_r_r60 = cpy_r_r59 << 1;
    cpy_r_r61 = (Py_ssize_t)cpy_r_r57 < (Py_ssize_t)cpy_r_r60;
    if (!cpy_r_r61) goto CPyL58;
    cpy_r_r62 = CPySequenceTuple_GetItem(cpy_r_r53, cpy_r_r57);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 81, CPyStatic__encoding___globals);
        goto CPyL59;
    }
    if (likely(PyLong_Check(cpy_r_r62)))
        cpy_r_r63 = CPyTagged_FromObject(cpy_r_r62);
    else {
        CPy_TypeError("int", cpy_r_r62); cpy_r_r63 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r62);
    if (unlikely(cpy_r_r63 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 81, CPyStatic__encoding___globals);
        goto CPyL59;
    }
    cpy_r_r64 = CPyTagged_Add(cpy_r_r22, cpy_r_r63);
    CPyTagged_DECREF(cpy_r_r63);
    cpy_r_r65 = CPyDef__encoding___encode_uint_256(cpy_r_r64);
    CPyTagged_DECREF(cpy_r_r64);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 82, CPyStatic__encoding___globals);
        goto CPyL59;
    }
    cpy_r_r66 = CPySequenceTuple_SetItemUnsafe(cpy_r_r56, cpy_r_r57, cpy_r_r65);
    if (unlikely(!cpy_r_r66)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 81, CPyStatic__encoding___globals);
        goto CPyL59;
    }
    cpy_r_r67 = cpy_r_r57 + 2;
    cpy_r_r57 = cpy_r_r67;
    goto CPyL33;
CPyL39: ;
    cpy_r_r68 = CPyStatics[189]; /* b'' */
    cpy_r_r69 = CPyBytes_Join(cpy_r_r68, cpy_r_r56);
    CPy_DECREF(cpy_r_r56);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 84, CPyStatic__encoding___globals);
        goto CPyL48;
    }
    cpy_r_r70 = CPyStatics[189]; /* b'' */
    cpy_r_r71 = CPyBytes_Join(cpy_r_r70, cpy_r_r10);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 84, CPyStatic__encoding___globals);
        goto CPyL60;
    }
    cpy_r_r72 = CPyBytes_Concat(cpy_r_r69, cpy_r_r71);
    CPy_DECREF(cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 84, CPyStatic__encoding___globals);
        goto CPyL43;
    }
    return cpy_r_r72;
CPyL43: ;
    cpy_r_r73 = NULL;
    return cpy_r_r73;
CPyL44: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL43;
CPyL45: ;
    CPy_DECREF(cpy_r_r1);
    goto CPyL6;
CPyL46: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r2);
    goto CPyL43;
CPyL47: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    goto CPyL43;
CPyL48: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL43;
CPyL49: ;
    CPy_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_r22);
    goto CPyL43;
CPyL50: ;
    CPy_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r24);
    goto CPyL43;
CPyL51: ;
    CPy_DECREF(cpy_r_r24);
    goto CPyL25;
CPyL52: ;
    CPy_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r27);
    goto CPyL43;
CPyL53: ;
    CPy_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r41);
    goto CPyL43;
CPyL54: ;
    CPy_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r47);
    goto CPyL43;
CPyL55: ;
    CPy_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r48);
    goto CPyL43;
CPyL56: ;
    CPy_DECREF(cpy_r_r52);
    goto CPyL30;
CPyL57: ;
    CPy_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r53);
    goto CPyL43;
CPyL58: ;
    CPyTagged_DECREF(cpy_r_r22);
    CPy_DECREF(cpy_r_r53);
    goto CPyL39;
CPyL59: ;
    CPy_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r53);
    CPy_DecRef(cpy_r_r56);
    goto CPyL43;
CPyL60: ;
    CPy_DecRef(cpy_r_r69);
    goto CPyL43;
}

PyObject *CPyPy__encoding___encode_elements(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"item_encoder", "value", 0};
    static CPyArg_Parser parser = {"OO:encode_elements", kwlist, 0};
    PyObject *obj_item_encoder;
    PyObject *obj_value;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_item_encoder, &obj_value)) {
        return NULL;
    }
    PyObject *arg_item_encoder = obj_item_encoder;
    PyObject *arg_value = obj_value;
    PyObject *retval = CPyDef__encoding___encode_elements(arg_item_encoder, arg_value);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements", 72, CPyStatic__encoding___globals);
    return NULL;
}

PyObject *CPyDef__encoding___encode_elements_dynamic(PyObject *cpy_r_item_encoder, PyObject *cpy_r_value) {
    CPyTagged cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    cpy_r_r0 = CPyObject_Size(cpy_r_value);
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements_dynamic", 88, CPyStatic__encoding___globals);
        goto CPyL5;
    }
    cpy_r_r1 = CPyDef__encoding___encode_uint_256(cpy_r_r0);
    CPyTagged_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements_dynamic", 88, CPyStatic__encoding___globals);
        goto CPyL5;
    }
    cpy_r_r2 = CPyDef__encoding___encode_elements(cpy_r_item_encoder, cpy_r_value);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements_dynamic", 89, CPyStatic__encoding___globals);
        goto CPyL6;
    }
    cpy_r_r3 = CPyBytes_Concat(cpy_r_r1, cpy_r_r2);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements_dynamic", 90, CPyStatic__encoding___globals);
        goto CPyL5;
    }
    return cpy_r_r3;
CPyL5: ;
    cpy_r_r4 = NULL;
    return cpy_r_r4;
CPyL6: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL5;
}

PyObject *CPyPy__encoding___encode_elements_dynamic(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"item_encoder", "value", 0};
    static CPyArg_Parser parser = {"OO:encode_elements_dynamic", kwlist, 0};
    PyObject *obj_item_encoder;
    PyObject *obj_value;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_item_encoder, &obj_value)) {
        return NULL;
    }
    PyObject *arg_item_encoder = obj_item_encoder;
    PyObject *arg_value = obj_value;
    PyObject *retval = CPyDef__encoding___encode_elements_dynamic(arg_item_encoder, arg_value);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_elements_dynamic", 87, CPyStatic__encoding___globals);
    return NULL;
}

PyObject *CPyDef__encoding___encode_uint_256(CPyTagged cpy_r_i) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    cpy_r_r0 = CPyDef__encoding___int_to_big_endian(cpy_r_i);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_uint_256", 96, CPyStatic__encoding___globals);
        goto CPyL4;
    }
    cpy_r_r1 = CPyStatics[190]; /* b'\x00' */
    cpy_r_r2 = CPyStatics[26]; /* 'rjust' */
    cpy_r_r3 = CPyStatics[193]; /* 32 */
    PyObject *cpy_r_r4[3] = {cpy_r_r0, cpy_r_r3, cpy_r_r1};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = PyObject_VectorcallMethod(cpy_r_r2, cpy_r_r5, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_uint_256", 97, CPyStatic__encoding___globals);
        goto CPyL5;
    }
    CPy_DECREF(cpy_r_r0);
    if (likely(PyBytes_Check(cpy_r_r6) || PyByteArray_Check(cpy_r_r6)))
        cpy_r_r7 = cpy_r_r6;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "encode_uint_256", 97, CPyStatic__encoding___globals, "bytes", cpy_r_r6);
        goto CPyL4;
    }
    return cpy_r_r7;
CPyL4: ;
    cpy_r_r8 = NULL;
    return cpy_r_r8;
CPyL5: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL4;
}

PyObject *CPyPy__encoding___encode_uint_256(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"i", 0};
    static CPyArg_Parser parser = {"O:encode_uint_256", kwlist, 0};
    PyObject *obj_i;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_i)) {
        return NULL;
    }
    CPyTagged arg_i;
    if (likely(PyLong_Check(obj_i)))
        arg_i = CPyTagged_BorrowFromObject(obj_i);
    else {
        CPy_TypeError("int", obj_i); goto fail;
    }
    PyObject *retval = CPyDef__encoding___encode_uint_256(arg_i);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/_encoding.py", "encode_uint_256", 93, CPyStatic__encoding___globals);
    return NULL;
}

PyObject *CPyDef__encoding___int_to_big_endian(CPyTagged cpy_r_value) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject **cpy_r_r3;
    PyObject *cpy_r_r4;
    CPyTagged cpy_r_r5;
    CPyTagged cpy_r_r6;
    CPyTagged cpy_r_r7;
    char cpy_r_r8;
    CPyTagged cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject **cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    cpy_r_r0 = CPyStatics[28]; /* 'bit_length' */
    CPyTagged_INCREF(cpy_r_value);
    cpy_r_r1 = CPyTagged_StealAsObject(cpy_r_value);
    PyObject *cpy_r_r2[1] = {cpy_r_r1};
    cpy_r_r3 = (PyObject **)&cpy_r_r2;
    cpy_r_r4 = PyObject_VectorcallMethod(cpy_r_r0, cpy_r_r3, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "int_to_big_endian", 102, CPyStatic__encoding___globals);
        goto CPyL10;
    }
    CPy_DECREF(cpy_r_r1);
    if (likely(PyLong_Check(cpy_r_r4)))
        cpy_r_r5 = CPyTagged_FromObject(cpy_r_r4);
    else {
        CPy_TypeError("int", cpy_r_r4); cpy_r_r5 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r5 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "int_to_big_endian", 102, CPyStatic__encoding___globals);
        goto CPyL9;
    }
    cpy_r_r6 = CPyTagged_Add(cpy_r_r5, 14);
    CPyTagged_DECREF(cpy_r_r5);
    cpy_r_r7 = CPyTagged_Rshift(cpy_r_r6, 6);
    CPyTagged_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "int_to_big_endian", -1, CPyStatic__encoding___globals);
        goto CPyL9;
    }
    cpy_r_r8 = cpy_r_r7 != 0;
    if (!cpy_r_r8) goto CPyL11;
    cpy_r_r9 = cpy_r_r7;
    goto CPyL6;
CPyL5: ;
    cpy_r_r9 = 2;
CPyL6: ;
    cpy_r_r10 = CPyStatics[29]; /* 'big' */
    cpy_r_r11 = CPyStatics[30]; /* 'to_bytes' */
    CPyTagged_INCREF(cpy_r_value);
    cpy_r_r12 = CPyTagged_StealAsObject(cpy_r_value);
    cpy_r_r13 = CPyTagged_StealAsObject(cpy_r_r9);
    PyObject *cpy_r_r14[3] = {cpy_r_r12, cpy_r_r13, cpy_r_r10};
    cpy_r_r15 = (PyObject **)&cpy_r_r14;
    cpy_r_r16 = PyObject_VectorcallMethod(cpy_r_r11, cpy_r_r15, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "int_to_big_endian", 102, CPyStatic__encoding___globals);
        goto CPyL12;
    }
    CPy_DECREF(cpy_r_r12);
    CPy_DECREF(cpy_r_r13);
    if (likely(PyBytes_Check(cpy_r_r16) || PyByteArray_Check(cpy_r_r16)))
        cpy_r_r17 = cpy_r_r16;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/_encoding.py", "int_to_big_endian", 102, CPyStatic__encoding___globals, "bytes", cpy_r_r16);
        goto CPyL9;
    }
    return cpy_r_r17;
CPyL9: ;
    cpy_r_r18 = NULL;
    return cpy_r_r18;
CPyL10: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL9;
CPyL11: ;
    CPyTagged_DECREF(cpy_r_r7);
    goto CPyL5;
CPyL12: ;
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r13);
    goto CPyL9;
}

PyObject *CPyPy__encoding___int_to_big_endian(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"value", 0};
    static CPyArg_Parser parser = {"O:int_to_big_endian", kwlist, 0};
    PyObject *obj_value;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_value)) {
        return NULL;
    }
    CPyTagged arg_value;
    if (likely(PyLong_Check(obj_value)))
        arg_value = CPyTagged_BorrowFromObject(obj_value);
    else {
        CPy_TypeError("int", obj_value); goto fail;
    }
    PyObject *retval = CPyDef__encoding___int_to_big_endian(arg_value);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/_encoding.py", "int_to_big_endian", 100, CPyStatic__encoding___globals);
    return NULL;
}

char CPyDef__encoding_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject **cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    int32_t cpy_r_r22;
    char cpy_r_r23;
    char cpy_r_r24;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[11]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "<module>", -1, CPyStatic__encoding___globals);
        goto CPyL10;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[207]; /* ('accumulate',) */
    cpy_r_r6 = CPyStatics[31]; /* 'itertools' */
    cpy_r_r7 = CPyStatic__encoding___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "<module>", 1, CPyStatic__encoding___globals);
        goto CPyL10;
    }
    CPyModule_itertools = cpy_r_r8;
    CPy_INCREF(CPyModule_itertools);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[208]; /* ('TYPE_CHECKING', 'Any', 'Callable', 'List', 'Optional',
                                   'Sequence', 'TypeVar') */
    cpy_r_r10 = CPyStatics[17]; /* 'typing' */
    cpy_r_r11 = CPyStatic__encoding___globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "<module>", 4, CPyStatic__encoding___globals);
        goto CPyL10;
    }
    CPyModule_typing = cpy_r_r12;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[37]; /* 'T' */
    cpy_r_r14 = CPyStatic__encoding___globals;
    cpy_r_r15 = CPyStatics[36]; /* 'TypeVar' */
    cpy_r_r16 = CPyDict_GetItem(cpy_r_r14, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "<module>", 20, CPyStatic__encoding___globals);
        goto CPyL10;
    }
    PyObject *cpy_r_r17[1] = {cpy_r_r13};
    cpy_r_r18 = (PyObject **)&cpy_r_r17;
    cpy_r_r19 = PyObject_Vectorcall(cpy_r_r16, cpy_r_r18, 1, 0);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "<module>", 20, CPyStatic__encoding___globals);
        goto CPyL10;
    }
    cpy_r_r20 = CPyStatic__encoding___globals;
    cpy_r_r21 = CPyStatics[37]; /* 'T' */
    cpy_r_r22 = CPyDict_SetItem(cpy_r_r20, cpy_r_r21, cpy_r_r19);
    CPy_DECREF(cpy_r_r19);
    cpy_r_r23 = cpy_r_r22 >= 0;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("faster_eth_abi/_encoding.py", "<module>", 20, CPyStatic__encoding___globals);
        goto CPyL10;
    }
    return 1;
CPyL10: ;
    cpy_r_r24 = 2;
    return cpy_r_r24;
}
static int abi_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_faster_eth_abi___abi_internal, "__name__");
    CPyStatic_abi___globals = PyModule_GetDict(CPyModule_faster_eth_abi___abi_internal);
    if (unlikely(CPyStatic_abi___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_abi_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_faster_eth_abi___abi_internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic_abi___default_codec);
    CPyStatic_abi___default_codec = NULL;
    CPy_XDECREF(CPyStatic_abi___encode);
    CPyStatic_abi___encode = NULL;
    CPy_XDECREF(CPyStatic_abi___decode);
    CPyStatic_abi___decode = NULL;
    CPy_XDECREF(CPyStatic_abi___is_encodable);
    CPyStatic_abi___is_encodable = NULL;
    CPy_XDECREF(CPyStatic_abi___is_encodable_type);
    CPyStatic_abi___is_encodable_type = NULL;
    return -1;
}
static PyMethodDef abimodule_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef abimodule = {
    PyModuleDef_HEAD_INIT,
    "faster_eth_abi.abi",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    abimodule_methods,
    NULL,
};

PyObject *CPyInit_faster_eth_abi___abi(void)
{
    if (CPyModule_faster_eth_abi___abi_internal) {
        Py_INCREF(CPyModule_faster_eth_abi___abi_internal);
        return CPyModule_faster_eth_abi___abi_internal;
    }
    CPyModule_faster_eth_abi___abi_internal = PyModule_Create(&abimodule);
    if (unlikely(CPyModule_faster_eth_abi___abi_internal == NULL))
        goto fail;
    if (abi_exec(CPyModule_faster_eth_abi___abi_internal) != 0)
        goto fail;
    return CPyModule_faster_eth_abi___abi_internal;
    fail:
    return NULL;
}

char CPyDef_abi_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject **cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    int32_t cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    char cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    int32_t cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    char cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    int32_t cpy_r_r44;
    char cpy_r_r45;
    PyObject *cpy_r_r46;
    char cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    int32_t cpy_r_r52;
    char cpy_r_r53;
    PyObject *cpy_r_r54;
    char cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    int32_t cpy_r_r60;
    char cpy_r_r61;
    char cpy_r_r62;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[11]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", -1, CPyStatic_abi___globals);
        goto CPyL31;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[209]; /* ('Final',) */
    cpy_r_r6 = CPyStatics[17]; /* 'typing' */
    cpy_r_r7 = CPyStatic_abi___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 1, CPyStatic_abi___globals);
        goto CPyL31;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[210]; /* ('ABICodec',) */
    cpy_r_r10 = CPyStatics[40]; /* 'faster_eth_abi.codec' */
    cpy_r_r11 = CPyStatic_abi___globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 5, CPyStatic_abi___globals);
        goto CPyL31;
    }
    CPyModule_faster_eth_abi___codec = cpy_r_r12;
    CPy_INCREF(CPyModule_faster_eth_abi___codec);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[211]; /* ('registry',) */
    cpy_r_r14 = CPyStatics[42]; /* 'faster_eth_abi.registry' */
    cpy_r_r15 = CPyStatic_abi___globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 8, CPyStatic_abi___globals);
        goto CPyL31;
    }
    CPyModule_faster_eth_abi___registry = cpy_r_r16;
    CPy_INCREF(CPyModule_faster_eth_abi___registry);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r17 = CPyStatic_abi___globals;
    cpy_r_r18 = CPyStatics[41]; /* 'registry' */
    cpy_r_r19 = CPyDict_GetItem(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 12, CPyStatic_abi___globals);
        goto CPyL31;
    }
    cpy_r_r20 = CPyStatic_abi___globals;
    cpy_r_r21 = CPyStatics[39]; /* 'ABICodec' */
    cpy_r_r22 = CPyDict_GetItem(cpy_r_r20, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 12, CPyStatic_abi___globals);
        goto CPyL32;
    }
    PyObject *cpy_r_r23[1] = {cpy_r_r19};
    cpy_r_r24 = (PyObject **)&cpy_r_r23;
    cpy_r_r25 = PyObject_Vectorcall(cpy_r_r22, cpy_r_r24, 1, 0);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 12, CPyStatic_abi___globals);
        goto CPyL32;
    }
    CPy_DECREF(cpy_r_r19);
    CPyStatic_abi___default_codec = cpy_r_r25;
    CPy_INCREF(CPyStatic_abi___default_codec);
    cpy_r_r26 = CPyStatic_abi___globals;
    cpy_r_r27 = CPyStatics[43]; /* 'default_codec' */
    cpy_r_r28 = CPyDict_SetItem(cpy_r_r26, cpy_r_r27, cpy_r_r25);
    CPy_DECREF(cpy_r_r25);
    cpy_r_r29 = cpy_r_r28 >= 0;
    if (unlikely(!cpy_r_r29)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 12, CPyStatic_abi___globals);
        goto CPyL31;
    }
    cpy_r_r30 = CPyStatic_abi___default_codec;
    if (likely(cpy_r_r30 != NULL)) goto CPyL13;
    PyErr_SetString(PyExc_NameError, "value for final name \"default_codec\" was not set");
    cpy_r_r31 = 0;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 14, CPyStatic_abi___globals);
        goto CPyL31;
    }
    CPy_Unreachable();
CPyL13: ;
    cpy_r_r32 = CPyStatics[44]; /* 'encode' */
    cpy_r_r33 = CPyObject_GetAttr(cpy_r_r30, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 14, CPyStatic_abi___globals);
        goto CPyL31;
    }
    CPyStatic_abi___encode = cpy_r_r33;
    CPy_INCREF(CPyStatic_abi___encode);
    cpy_r_r34 = CPyStatic_abi___globals;
    cpy_r_r35 = CPyStatics[44]; /* 'encode' */
    cpy_r_r36 = CPyDict_SetItem(cpy_r_r34, cpy_r_r35, cpy_r_r33);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r37 = cpy_r_r36 >= 0;
    if (unlikely(!cpy_r_r37)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 14, CPyStatic_abi___globals);
        goto CPyL31;
    }
    cpy_r_r38 = CPyStatic_abi___default_codec;
    if (likely(cpy_r_r38 != NULL)) goto CPyL18;
    PyErr_SetString(PyExc_NameError, "value for final name \"default_codec\" was not set");
    cpy_r_r39 = 0;
    if (unlikely(!cpy_r_r39)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 15, CPyStatic_abi___globals);
        goto CPyL31;
    }
    CPy_Unreachable();
CPyL18: ;
    cpy_r_r40 = CPyStatics[45]; /* 'decode' */
    cpy_r_r41 = CPyObject_GetAttr(cpy_r_r38, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 15, CPyStatic_abi___globals);
        goto CPyL31;
    }
    CPyStatic_abi___decode = cpy_r_r41;
    CPy_INCREF(CPyStatic_abi___decode);
    cpy_r_r42 = CPyStatic_abi___globals;
    cpy_r_r43 = CPyStatics[45]; /* 'decode' */
    cpy_r_r44 = CPyDict_SetItem(cpy_r_r42, cpy_r_r43, cpy_r_r41);
    CPy_DECREF(cpy_r_r41);
    cpy_r_r45 = cpy_r_r44 >= 0;
    if (unlikely(!cpy_r_r45)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 15, CPyStatic_abi___globals);
        goto CPyL31;
    }
    cpy_r_r46 = CPyStatic_abi___default_codec;
    if (likely(cpy_r_r46 != NULL)) goto CPyL23;
    PyErr_SetString(PyExc_NameError, "value for final name \"default_codec\" was not set");
    cpy_r_r47 = 0;
    if (unlikely(!cpy_r_r47)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 16, CPyStatic_abi___globals);
        goto CPyL31;
    }
    CPy_Unreachable();
CPyL23: ;
    cpy_r_r48 = CPyStatics[46]; /* 'is_encodable' */
    cpy_r_r49 = CPyObject_GetAttr(cpy_r_r46, cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 16, CPyStatic_abi___globals);
        goto CPyL31;
    }
    CPyStatic_abi___is_encodable = cpy_r_r49;
    CPy_INCREF(CPyStatic_abi___is_encodable);
    cpy_r_r50 = CPyStatic_abi___globals;
    cpy_r_r51 = CPyStatics[46]; /* 'is_encodable' */
    cpy_r_r52 = CPyDict_SetItem(cpy_r_r50, cpy_r_r51, cpy_r_r49);
    CPy_DECREF(cpy_r_r49);
    cpy_r_r53 = cpy_r_r52 >= 0;
    if (unlikely(!cpy_r_r53)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 16, CPyStatic_abi___globals);
        goto CPyL31;
    }
    cpy_r_r54 = CPyStatic_abi___default_codec;
    if (likely(cpy_r_r54 != NULL)) goto CPyL28;
    PyErr_SetString(PyExc_NameError, "value for final name \"default_codec\" was not set");
    cpy_r_r55 = 0;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 17, CPyStatic_abi___globals);
        goto CPyL31;
    }
    CPy_Unreachable();
CPyL28: ;
    cpy_r_r56 = CPyStatics[47]; /* 'is_encodable_type' */
    cpy_r_r57 = CPyObject_GetAttr(cpy_r_r54, cpy_r_r56);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 17, CPyStatic_abi___globals);
        goto CPyL31;
    }
    CPyStatic_abi___is_encodable_type = cpy_r_r57;
    CPy_INCREF(CPyStatic_abi___is_encodable_type);
    cpy_r_r58 = CPyStatic_abi___globals;
    cpy_r_r59 = CPyStatics[47]; /* 'is_encodable_type' */
    cpy_r_r60 = CPyDict_SetItem(cpy_r_r58, cpy_r_r59, cpy_r_r57);
    CPy_DECREF(cpy_r_r57);
    cpy_r_r61 = cpy_r_r60 >= 0;
    if (unlikely(!cpy_r_r61)) {
        CPy_AddTraceback("faster_eth_abi/abi.py", "<module>", 17, CPyStatic_abi___globals);
        goto CPyL31;
    }
    return 1;
CPyL31: ;
    cpy_r_r62 = 2;
    return cpy_r_r62;
CPyL32: ;
    CPy_DecRef(cpy_r_r19);
    goto CPyL31;
}
static int constants_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_faster_eth_abi___constants_internal, "__name__");
    CPyStatic_constants___globals = PyModule_GetDict(CPyModule_faster_eth_abi___constants_internal);
    if (unlikely(CPyStatic_constants___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_constants_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_faster_eth_abi___constants_internal);
    Py_CLEAR(modname);
    return -1;
}
static PyMethodDef constantsmodule_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef constantsmodule = {
    PyModuleDef_HEAD_INIT,
    "faster_eth_abi.constants",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    constantsmodule_methods,
    NULL,
};

PyObject *CPyInit_faster_eth_abi___constants(void)
{
    if (CPyModule_faster_eth_abi___constants_internal) {
        Py_INCREF(CPyModule_faster_eth_abi___constants_internal);
        return CPyModule_faster_eth_abi___constants_internal;
    }
    CPyModule_faster_eth_abi___constants_internal = PyModule_Create(&constantsmodule);
    if (unlikely(CPyModule_faster_eth_abi___constants_internal == NULL))
        goto fail;
    if (constants_exec(CPyModule_faster_eth_abi___constants_internal) != 0)
        goto fail;
    return CPyModule_faster_eth_abi___constants_internal;
    fail:
    return NULL;
}

char CPyDef_constants_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    CPyTagged cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    int32_t cpy_r_r13;
    char cpy_r_r14;
    CPyTagged cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    int32_t cpy_r_r19;
    char cpy_r_r20;
    CPyTagged cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    int32_t cpy_r_r25;
    char cpy_r_r26;
    char cpy_r_r27;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[11]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/constants.py", "<module>", -1, CPyStatic_constants___globals);
        goto CPyL8;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[209]; /* ('Final',) */
    cpy_r_r6 = CPyStatics[17]; /* 'typing' */
    cpy_r_r7 = CPyStatic_constants___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/constants.py", "<module>", 1, CPyStatic_constants___globals);
        goto CPyL8;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = (CPyTagged)CPyStatics[194] | 1; /* 115792089237316195423570985008687907853269984665640564039457584007913129639936 */
    cpy_r_r10 = CPyStatic_constants___globals;
    cpy_r_r11 = CPyStatics[48]; /* 'TT256' */
    CPyTagged_INCREF(cpy_r_r9);
    cpy_r_r12 = CPyTagged_StealAsObject(cpy_r_r9);
    cpy_r_r13 = CPyDict_SetItem(cpy_r_r10, cpy_r_r11, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r14 = cpy_r_r13 >= 0;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("faster_eth_abi/constants.py", "<module>", 5, CPyStatic_constants___globals);
        goto CPyL8;
    }
    cpy_r_r15 = (CPyTagged)CPyStatics[195] | 1; /* 115792089237316195423570985008687907853269984665640564039457584007913129639935 */
    cpy_r_r16 = CPyStatic_constants___globals;
    cpy_r_r17 = CPyStatics[49]; /* 'TT256M1' */
    CPyTagged_INCREF(cpy_r_r15);
    cpy_r_r18 = CPyTagged_StealAsObject(cpy_r_r15);
    cpy_r_r19 = CPyDict_SetItem(cpy_r_r16, cpy_r_r17, cpy_r_r18);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r20 = cpy_r_r19 >= 0;
    if (unlikely(!cpy_r_r20)) {
        CPy_AddTraceback("faster_eth_abi/constants.py", "<module>", 6, CPyStatic_constants___globals);
        goto CPyL8;
    }
    cpy_r_r21 = (CPyTagged)CPyStatics[196] | 1; /* 57896044618658097711785492504343953926634992332820282019728792003956564819968 */
    cpy_r_r22 = CPyStatic_constants___globals;
    cpy_r_r23 = CPyStatics[50]; /* 'TT255' */
    CPyTagged_INCREF(cpy_r_r21);
    cpy_r_r24 = CPyTagged_StealAsObject(cpy_r_r21);
    cpy_r_r25 = CPyDict_SetItem(cpy_r_r22, cpy_r_r23, cpy_r_r24);
    CPy_DECREF(cpy_r_r24);
    cpy_r_r26 = cpy_r_r25 >= 0;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("faster_eth_abi/constants.py", "<module>", 7, CPyStatic_constants___globals);
        goto CPyL8;
    }
    return 1;
CPyL8: ;
    cpy_r_r27 = 2;
    return cpy_r_r27;
}

static PyObject *from_type_str___parse_type_str_env_setup(PyTypeObject *type);
PyObject *CPyDef_from_type_str___parse_type_str_env(void);

static PyObject *
from_type_str___parse_type_str_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_from_type_str___parse_type_str_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return from_type_str___parse_type_str_env_setup(type);
}

static int
from_type_str___parse_type_str_env_traverse(faster_eth_abi___from_type_str___parse_type_str_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_expected_base);
    Py_VISIT(self->_decorator);
    return 0;
}

static int
from_type_str___parse_type_str_env_clear(faster_eth_abi___from_type_str___parse_type_str_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_expected_base);
    Py_CLEAR(self->_decorator);
    return 0;
}

static void
from_type_str___parse_type_str_env_dealloc(faster_eth_abi___from_type_str___parse_type_str_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, from_type_str___parse_type_str_env_dealloc)
    from_type_str___parse_type_str_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem from_type_str___parse_type_str_env_vtable[1];
static bool
CPyDef_from_type_str___parse_type_str_env_trait_vtable_setup(void)
{
    CPyVTableItem from_type_str___parse_type_str_env_vtable_scratch[] = {
        NULL
    };
    memcpy(from_type_str___parse_type_str_env_vtable, from_type_str___parse_type_str_env_vtable_scratch, sizeof(from_type_str___parse_type_str_env_vtable));
    return 1;
}

static PyMethodDef from_type_str___parse_type_str_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_from_type_str___parse_type_str_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "parse_type_str_env",
    .tp_new = from_type_str___parse_type_str_env_new,
    .tp_dealloc = (destructor)from_type_str___parse_type_str_env_dealloc,
    .tp_traverse = (traverseproc)from_type_str___parse_type_str_env_traverse,
    .tp_clear = (inquiry)from_type_str___parse_type_str_env_clear,
    .tp_methods = from_type_str___parse_type_str_env_methods,
    .tp_basicsize = sizeof(faster_eth_abi___from_type_str___parse_type_str_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_from_type_str___parse_type_str_env_template = &CPyType_from_type_str___parse_type_str_env_template_;

static PyObject *
from_type_str___parse_type_str_env_setup(PyTypeObject *type)
{
    faster_eth_abi___from_type_str___parse_type_str_envObject *self;
    self = (faster_eth_abi___from_type_str___parse_type_str_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = from_type_str___parse_type_str_env_vtable;
    self->_with_arrlist = 2;
    self->_None = 2;
    return (PyObject *)self;
}

PyObject *CPyDef_from_type_str___parse_type_str_env(void)
{
    PyObject *self = from_type_str___parse_type_str_env_setup(CPyType_from_type_str___parse_type_str_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *from_type_str___decorator_parse_type_str_env_setup(PyTypeObject *type);
PyObject *CPyDef_from_type_str___decorator_parse_type_str_env(void);

static PyObject *
from_type_str___decorator_parse_type_str_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_from_type_str___decorator_parse_type_str_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return from_type_str___decorator_parse_type_str_env_setup(type);
}

static int
from_type_str___decorator_parse_type_str_env_traverse(faster_eth_abi___from_type_str___decorator_parse_type_str_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->___mypyc_env__);
    Py_VISIT(self->_old_from_type_str);
    Py_VISIT(self->_new_from_type_str);
    Py_VISIT(self->_expected_base);
    Py_VISIT(self->_decorator);
    return 0;
}

static int
from_type_str___decorator_parse_type_str_env_clear(faster_eth_abi___from_type_str___decorator_parse_type_str_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->___mypyc_env__);
    Py_CLEAR(self->_old_from_type_str);
    Py_CLEAR(self->_new_from_type_str);
    Py_CLEAR(self->_expected_base);
    Py_CLEAR(self->_decorator);
    return 0;
}

static void
from_type_str___decorator_parse_type_str_env_dealloc(faster_eth_abi___from_type_str___decorator_parse_type_str_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, from_type_str___decorator_parse_type_str_env_dealloc)
    from_type_str___decorator_parse_type_str_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem from_type_str___decorator_parse_type_str_env_vtable[1];
static bool
CPyDef_from_type_str___decorator_parse_type_str_env_trait_vtable_setup(void)
{
    CPyVTableItem from_type_str___decorator_parse_type_str_env_vtable_scratch[] = {
        NULL
    };
    memcpy(from_type_str___decorator_parse_type_str_env_vtable, from_type_str___decorator_parse_type_str_env_vtable_scratch, sizeof(from_type_str___decorator_parse_type_str_env_vtable));
    return 1;
}

static PyMethodDef from_type_str___decorator_parse_type_str_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_from_type_str___decorator_parse_type_str_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "decorator_parse_type_str_env",
    .tp_new = from_type_str___decorator_parse_type_str_env_new,
    .tp_dealloc = (destructor)from_type_str___decorator_parse_type_str_env_dealloc,
    .tp_traverse = (traverseproc)from_type_str___decorator_parse_type_str_env_traverse,
    .tp_clear = (inquiry)from_type_str___decorator_parse_type_str_env_clear,
    .tp_methods = from_type_str___decorator_parse_type_str_env_methods,
    .tp_basicsize = sizeof(faster_eth_abi___from_type_str___decorator_parse_type_str_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_from_type_str___decorator_parse_type_str_env_template = &CPyType_from_type_str___decorator_parse_type_str_env_template_;

static PyObject *
from_type_str___decorator_parse_type_str_env_setup(PyTypeObject *type)
{
    faster_eth_abi___from_type_str___decorator_parse_type_str_envObject *self;
    self = (faster_eth_abi___from_type_str___decorator_parse_type_str_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = from_type_str___decorator_parse_type_str_env_vtable;
    self->_with_arrlist = 2;
    self->_None = 2;
    return (PyObject *)self;
}

PyObject *CPyDef_from_type_str___decorator_parse_type_str_env(void)
{
    PyObject *self = from_type_str___decorator_parse_type_str_env_setup(CPyType_from_type_str___decorator_parse_type_str_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *CPyDunder___get__from_type_str___decorator_parse_type_str_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef_from_type_str___decorator_parse_type_str_obj_____get__(self, instance, owner);
}
static PyObject *from_type_str___decorator_parse_type_str_obj_setup(PyTypeObject *type);
PyObject *CPyDef_from_type_str___decorator_parse_type_str_obj(void);

static PyObject *
from_type_str___decorator_parse_type_str_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_from_type_str___decorator_parse_type_str_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return from_type_str___decorator_parse_type_str_obj_setup(type);
}

static int
from_type_str___decorator_parse_type_str_obj_traverse(faster_eth_abi___from_type_str___decorator_parse_type_str_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
from_type_str___decorator_parse_type_str_obj_clear(faster_eth_abi___from_type_str___decorator_parse_type_str_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
from_type_str___decorator_parse_type_str_obj_dealloc(faster_eth_abi___from_type_str___decorator_parse_type_str_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, from_type_str___decorator_parse_type_str_obj_dealloc)
    from_type_str___decorator_parse_type_str_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem from_type_str___decorator_parse_type_str_obj_vtable[2];
static bool
CPyDef_from_type_str___decorator_parse_type_str_obj_trait_vtable_setup(void)
{
    CPyVTableItem from_type_str___decorator_parse_type_str_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_from_type_str___decorator_parse_type_str_obj_____call__,
        (CPyVTableItem)CPyDef_from_type_str___decorator_parse_type_str_obj_____get__,
    };
    memcpy(from_type_str___decorator_parse_type_str_obj_vtable, from_type_str___decorator_parse_type_str_obj_vtable_scratch, sizeof(from_type_str___decorator_parse_type_str_obj_vtable));
    return 1;
}

static PyObject *
from_type_str___decorator_parse_type_str_obj_get___3_mypyc_env__(faster_eth_abi___from_type_str___decorator_parse_type_str_objObject *self, void *closure);
static int
from_type_str___decorator_parse_type_str_obj_set___3_mypyc_env__(faster_eth_abi___from_type_str___decorator_parse_type_str_objObject *self, PyObject *value, void *closure);

static PyGetSetDef from_type_str___decorator_parse_type_str_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)from_type_str___decorator_parse_type_str_obj_get___3_mypyc_env__, (setter)from_type_str___decorator_parse_type_str_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef from_type_str___decorator_parse_type_str_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy_from_type_str___decorator_parse_type_str_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy_from_type_str___decorator_parse_type_str_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_from_type_str___decorator_parse_type_str_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "decorator_parse_type_str_obj",
    .tp_new = from_type_str___decorator_parse_type_str_obj_new,
    .tp_dealloc = (destructor)from_type_str___decorator_parse_type_str_obj_dealloc,
    .tp_traverse = (traverseproc)from_type_str___decorator_parse_type_str_obj_traverse,
    .tp_clear = (inquiry)from_type_str___decorator_parse_type_str_obj_clear,
    .tp_getset = from_type_str___decorator_parse_type_str_obj_getseters,
    .tp_methods = from_type_str___decorator_parse_type_str_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get__from_type_str___decorator_parse_type_str_obj,
    .tp_basicsize = sizeof(faster_eth_abi___from_type_str___decorator_parse_type_str_objObject),
    .tp_vectorcall_offset = offsetof(faster_eth_abi___from_type_str___decorator_parse_type_str_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType_from_type_str___decorator_parse_type_str_obj_template = &CPyType_from_type_str___decorator_parse_type_str_obj_template_;

static PyObject *
from_type_str___decorator_parse_type_str_obj_setup(PyTypeObject *type)
{
    faster_eth_abi___from_type_str___decorator_parse_type_str_objObject *self;
    self = (faster_eth_abi___from_type_str___decorator_parse_type_str_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = from_type_str___decorator_parse_type_str_obj_vtable;
    self->vectorcall = CPyPy_from_type_str___decorator_parse_type_str_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef_from_type_str___decorator_parse_type_str_obj(void)
{
    PyObject *self = from_type_str___decorator_parse_type_str_obj_setup(CPyType_from_type_str___decorator_parse_type_str_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
from_type_str___decorator_parse_type_str_obj_get___3_mypyc_env__(faster_eth_abi___from_type_str___decorator_parse_type_str_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of 'decorator_parse_type_str_obj' undefined");
        return NULL;
    }
    CPy_INCREF_NO_IMM(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
from_type_str___decorator_parse_type_str_obj_set___3_mypyc_env__(faster_eth_abi___from_type_str___decorator_parse_type_str_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'decorator_parse_type_str_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType_from_type_str___parse_type_str_env))
        tmp = value;
    else {
        CPy_TypeError("faster_eth_abi.from_type_str.parse_type_str_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF_NO_IMM(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}

static PyObject *CPyDunder___get__from_type_str___new_from_type_str_parse_type_str_decorator_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____get__(self, instance, owner);
}
static PyObject *from_type_str___new_from_type_str_parse_type_str_decorator_obj_setup(PyTypeObject *type);
PyObject *CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj(void);

static PyObject *
from_type_str___new_from_type_str_parse_type_str_decorator_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_from_type_str___new_from_type_str_parse_type_str_decorator_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return from_type_str___new_from_type_str_parse_type_str_decorator_obj_setup(type);
}

static int
from_type_str___new_from_type_str_parse_type_str_decorator_obj_traverse(faster_eth_abi___from_type_str___new_from_type_str_parse_type_str_decorator_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
from_type_str___new_from_type_str_parse_type_str_decorator_obj_clear(faster_eth_abi___from_type_str___new_from_type_str_parse_type_str_decorator_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
from_type_str___new_from_type_str_parse_type_str_decorator_obj_dealloc(faster_eth_abi___from_type_str___new_from_type_str_parse_type_str_decorator_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, from_type_str___new_from_type_str_parse_type_str_decorator_obj_dealloc)
    from_type_str___new_from_type_str_parse_type_str_decorator_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem from_type_str___new_from_type_str_parse_type_str_decorator_obj_vtable[2];
static bool
CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj_trait_vtable_setup(void)
{
    CPyVTableItem from_type_str___new_from_type_str_parse_type_str_decorator_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____call__,
        (CPyVTableItem)CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____get__,
    };
    memcpy(from_type_str___new_from_type_str_parse_type_str_decorator_obj_vtable, from_type_str___new_from_type_str_parse_type_str_decorator_obj_vtable_scratch, sizeof(from_type_str___new_from_type_str_parse_type_str_decorator_obj_vtable));
    return 1;
}

static PyObject *
from_type_str___new_from_type_str_parse_type_str_decorator_obj_get___3_mypyc_env__(faster_eth_abi___from_type_str___new_from_type_str_parse_type_str_decorator_objObject *self, void *closure);
static int
from_type_str___new_from_type_str_parse_type_str_decorator_obj_set___3_mypyc_env__(faster_eth_abi___from_type_str___new_from_type_str_parse_type_str_decorator_objObject *self, PyObject *value, void *closure);

static PyGetSetDef from_type_str___new_from_type_str_parse_type_str_decorator_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)from_type_str___new_from_type_str_parse_type_str_decorator_obj_get___3_mypyc_env__, (setter)from_type_str___new_from_type_str_parse_type_str_decorator_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef from_type_str___new_from_type_str_parse_type_str_decorator_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_from_type_str___new_from_type_str_parse_type_str_decorator_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "new_from_type_str_parse_type_str_decorator_obj",
    .tp_new = from_type_str___new_from_type_str_parse_type_str_decorator_obj_new,
    .tp_dealloc = (destructor)from_type_str___new_from_type_str_parse_type_str_decorator_obj_dealloc,
    .tp_traverse = (traverseproc)from_type_str___new_from_type_str_parse_type_str_decorator_obj_traverse,
    .tp_clear = (inquiry)from_type_str___new_from_type_str_parse_type_str_decorator_obj_clear,
    .tp_getset = from_type_str___new_from_type_str_parse_type_str_decorator_obj_getseters,
    .tp_methods = from_type_str___new_from_type_str_parse_type_str_decorator_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get__from_type_str___new_from_type_str_parse_type_str_decorator_obj,
    .tp_basicsize = sizeof(faster_eth_abi___from_type_str___new_from_type_str_parse_type_str_decorator_objObject),
    .tp_vectorcall_offset = offsetof(faster_eth_abi___from_type_str___new_from_type_str_parse_type_str_decorator_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType_from_type_str___new_from_type_str_parse_type_str_decorator_obj_template = &CPyType_from_type_str___new_from_type_str_parse_type_str_decorator_obj_template_;

static PyObject *
from_type_str___new_from_type_str_parse_type_str_decorator_obj_setup(PyTypeObject *type)
{
    faster_eth_abi___from_type_str___new_from_type_str_parse_type_str_decorator_objObject *self;
    self = (faster_eth_abi___from_type_str___new_from_type_str_parse_type_str_decorator_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = from_type_str___new_from_type_str_parse_type_str_decorator_obj_vtable;
    self->vectorcall = CPyPy_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj(void)
{
    PyObject *self = from_type_str___new_from_type_str_parse_type_str_decorator_obj_setup(CPyType_from_type_str___new_from_type_str_parse_type_str_decorator_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
from_type_str___new_from_type_str_parse_type_str_decorator_obj_get___3_mypyc_env__(faster_eth_abi___from_type_str___new_from_type_str_parse_type_str_decorator_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of 'new_from_type_str_parse_type_str_decorator_obj' undefined");
        return NULL;
    }
    CPy_INCREF_NO_IMM(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
from_type_str___new_from_type_str_parse_type_str_decorator_obj_set___3_mypyc_env__(faster_eth_abi___from_type_str___new_from_type_str_parse_type_str_decorator_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'new_from_type_str_parse_type_str_decorator_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType_from_type_str___decorator_parse_type_str_env))
        tmp = value;
    else {
        CPy_TypeError("faster_eth_abi.from_type_str.decorator_parse_type_str_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF_NO_IMM(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}

static PyObject *from_type_str___parse_tuple_type_str_env_setup(PyTypeObject *type);
PyObject *CPyDef_from_type_str___parse_tuple_type_str_env(void);

static PyObject *
from_type_str___parse_tuple_type_str_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_from_type_str___parse_tuple_type_str_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return from_type_str___parse_tuple_type_str_env_setup(type);
}

static int
from_type_str___parse_tuple_type_str_env_traverse(faster_eth_abi___from_type_str___parse_tuple_type_str_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_old_from_type_str);
    Py_VISIT(self->_new_from_type_str);
    return 0;
}

static int
from_type_str___parse_tuple_type_str_env_clear(faster_eth_abi___from_type_str___parse_tuple_type_str_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_old_from_type_str);
    Py_CLEAR(self->_new_from_type_str);
    return 0;
}

static void
from_type_str___parse_tuple_type_str_env_dealloc(faster_eth_abi___from_type_str___parse_tuple_type_str_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, from_type_str___parse_tuple_type_str_env_dealloc)
    from_type_str___parse_tuple_type_str_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem from_type_str___parse_tuple_type_str_env_vtable[1];
static bool
CPyDef_from_type_str___parse_tuple_type_str_env_trait_vtable_setup(void)
{
    CPyVTableItem from_type_str___parse_tuple_type_str_env_vtable_scratch[] = {
        NULL
    };
    memcpy(from_type_str___parse_tuple_type_str_env_vtable, from_type_str___parse_tuple_type_str_env_vtable_scratch, sizeof(from_type_str___parse_tuple_type_str_env_vtable));
    return 1;
}

static PyMethodDef from_type_str___parse_tuple_type_str_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_from_type_str___parse_tuple_type_str_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "parse_tuple_type_str_env",
    .tp_new = from_type_str___parse_tuple_type_str_env_new,
    .tp_dealloc = (destructor)from_type_str___parse_tuple_type_str_env_dealloc,
    .tp_traverse = (traverseproc)from_type_str___parse_tuple_type_str_env_traverse,
    .tp_clear = (inquiry)from_type_str___parse_tuple_type_str_env_clear,
    .tp_methods = from_type_str___parse_tuple_type_str_env_methods,
    .tp_basicsize = sizeof(faster_eth_abi___from_type_str___parse_tuple_type_str_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_from_type_str___parse_tuple_type_str_env_template = &CPyType_from_type_str___parse_tuple_type_str_env_template_;

static PyObject *
from_type_str___parse_tuple_type_str_env_setup(PyTypeObject *type)
{
    faster_eth_abi___from_type_str___parse_tuple_type_str_envObject *self;
    self = (faster_eth_abi___from_type_str___parse_tuple_type_str_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = from_type_str___parse_tuple_type_str_env_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_from_type_str___parse_tuple_type_str_env(void)
{
    PyObject *self = from_type_str___parse_tuple_type_str_env_setup(CPyType_from_type_str___parse_tuple_type_str_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *CPyDunder___get__from_type_str___new_from_type_str_parse_tuple_type_str_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____get__(self, instance, owner);
}
static PyObject *from_type_str___new_from_type_str_parse_tuple_type_str_obj_setup(PyTypeObject *type);
PyObject *CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj(void);

static PyObject *
from_type_str___new_from_type_str_parse_tuple_type_str_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_from_type_str___new_from_type_str_parse_tuple_type_str_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return from_type_str___new_from_type_str_parse_tuple_type_str_obj_setup(type);
}

static int
from_type_str___new_from_type_str_parse_tuple_type_str_obj_traverse(faster_eth_abi___from_type_str___new_from_type_str_parse_tuple_type_str_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
from_type_str___new_from_type_str_parse_tuple_type_str_obj_clear(faster_eth_abi___from_type_str___new_from_type_str_parse_tuple_type_str_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
from_type_str___new_from_type_str_parse_tuple_type_str_obj_dealloc(faster_eth_abi___from_type_str___new_from_type_str_parse_tuple_type_str_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, from_type_str___new_from_type_str_parse_tuple_type_str_obj_dealloc)
    from_type_str___new_from_type_str_parse_tuple_type_str_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem from_type_str___new_from_type_str_parse_tuple_type_str_obj_vtable[2];
static bool
CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj_trait_vtable_setup(void)
{
    CPyVTableItem from_type_str___new_from_type_str_parse_tuple_type_str_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____call__,
        (CPyVTableItem)CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____get__,
    };
    memcpy(from_type_str___new_from_type_str_parse_tuple_type_str_obj_vtable, from_type_str___new_from_type_str_parse_tuple_type_str_obj_vtable_scratch, sizeof(from_type_str___new_from_type_str_parse_tuple_type_str_obj_vtable));
    return 1;
}

static PyObject *
from_type_str___new_from_type_str_parse_tuple_type_str_obj_get___3_mypyc_env__(faster_eth_abi___from_type_str___new_from_type_str_parse_tuple_type_str_objObject *self, void *closure);
static int
from_type_str___new_from_type_str_parse_tuple_type_str_obj_set___3_mypyc_env__(faster_eth_abi___from_type_str___new_from_type_str_parse_tuple_type_str_objObject *self, PyObject *value, void *closure);

static PyGetSetDef from_type_str___new_from_type_str_parse_tuple_type_str_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)from_type_str___new_from_type_str_parse_tuple_type_str_obj_get___3_mypyc_env__, (setter)from_type_str___new_from_type_str_parse_tuple_type_str_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef from_type_str___new_from_type_str_parse_tuple_type_str_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_from_type_str___new_from_type_str_parse_tuple_type_str_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "new_from_type_str_parse_tuple_type_str_obj",
    .tp_new = from_type_str___new_from_type_str_parse_tuple_type_str_obj_new,
    .tp_dealloc = (destructor)from_type_str___new_from_type_str_parse_tuple_type_str_obj_dealloc,
    .tp_traverse = (traverseproc)from_type_str___new_from_type_str_parse_tuple_type_str_obj_traverse,
    .tp_clear = (inquiry)from_type_str___new_from_type_str_parse_tuple_type_str_obj_clear,
    .tp_getset = from_type_str___new_from_type_str_parse_tuple_type_str_obj_getseters,
    .tp_methods = from_type_str___new_from_type_str_parse_tuple_type_str_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get__from_type_str___new_from_type_str_parse_tuple_type_str_obj,
    .tp_basicsize = sizeof(faster_eth_abi___from_type_str___new_from_type_str_parse_tuple_type_str_objObject),
    .tp_vectorcall_offset = offsetof(faster_eth_abi___from_type_str___new_from_type_str_parse_tuple_type_str_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType_from_type_str___new_from_type_str_parse_tuple_type_str_obj_template = &CPyType_from_type_str___new_from_type_str_parse_tuple_type_str_obj_template_;

static PyObject *
from_type_str___new_from_type_str_parse_tuple_type_str_obj_setup(PyTypeObject *type)
{
    faster_eth_abi___from_type_str___new_from_type_str_parse_tuple_type_str_objObject *self;
    self = (faster_eth_abi___from_type_str___new_from_type_str_parse_tuple_type_str_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = from_type_str___new_from_type_str_parse_tuple_type_str_obj_vtable;
    self->vectorcall = CPyPy_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj(void)
{
    PyObject *self = from_type_str___new_from_type_str_parse_tuple_type_str_obj_setup(CPyType_from_type_str___new_from_type_str_parse_tuple_type_str_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
from_type_str___new_from_type_str_parse_tuple_type_str_obj_get___3_mypyc_env__(faster_eth_abi___from_type_str___new_from_type_str_parse_tuple_type_str_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of 'new_from_type_str_parse_tuple_type_str_obj' undefined");
        return NULL;
    }
    CPy_INCREF_NO_IMM(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
from_type_str___new_from_type_str_parse_tuple_type_str_obj_set___3_mypyc_env__(faster_eth_abi___from_type_str___new_from_type_str_parse_tuple_type_str_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'new_from_type_str_parse_tuple_type_str_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType_from_type_str___parse_tuple_type_str_env))
        tmp = value;
    else {
        CPy_TypeError("faster_eth_abi.from_type_str.parse_tuple_type_str_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF_NO_IMM(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}
static int from_type_str_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_faster_eth_abi___from_type_str_internal, "__name__");
    CPyStatic_from_type_str___globals = PyModule_GetDict(CPyModule_faster_eth_abi___from_type_str_internal);
    if (unlikely(CPyStatic_from_type_str___globals == NULL))
        goto fail;
    CPyType_from_type_str___parse_type_str_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_from_type_str___parse_type_str_env_template, NULL, modname);
    if (unlikely(!CPyType_from_type_str___parse_type_str_env))
        goto fail;
    CPyType_from_type_str___decorator_parse_type_str_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_from_type_str___decorator_parse_type_str_env_template, NULL, modname);
    if (unlikely(!CPyType_from_type_str___decorator_parse_type_str_env))
        goto fail;
    CPyType_from_type_str___decorator_parse_type_str_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_from_type_str___decorator_parse_type_str_obj_template, NULL, modname);
    if (unlikely(!CPyType_from_type_str___decorator_parse_type_str_obj))
        goto fail;
    CPyType_from_type_str___new_from_type_str_parse_type_str_decorator_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_from_type_str___new_from_type_str_parse_type_str_decorator_obj_template, NULL, modname);
    if (unlikely(!CPyType_from_type_str___new_from_type_str_parse_type_str_decorator_obj))
        goto fail;
    CPyType_from_type_str___parse_tuple_type_str_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_from_type_str___parse_tuple_type_str_env_template, NULL, modname);
    if (unlikely(!CPyType_from_type_str___parse_tuple_type_str_env))
        goto fail;
    CPyType_from_type_str___new_from_type_str_parse_tuple_type_str_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_from_type_str___new_from_type_str_parse_tuple_type_str_obj_template, NULL, modname);
    if (unlikely(!CPyType_from_type_str___new_from_type_str_parse_tuple_type_str_obj))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_from_type_str_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_faster_eth_abi___from_type_str_internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_from_type_str___parse_type_str_env);
    Py_CLEAR(CPyType_from_type_str___decorator_parse_type_str_env);
    Py_CLEAR(CPyType_from_type_str___decorator_parse_type_str_obj);
    Py_CLEAR(CPyType_from_type_str___new_from_type_str_parse_type_str_decorator_obj);
    Py_CLEAR(CPyType_from_type_str___parse_tuple_type_str_env);
    Py_CLEAR(CPyType_from_type_str___new_from_type_str_parse_tuple_type_str_obj);
    return -1;
}
static PyMethodDef from_type_strmodule_methods[] = {
    {"parse_type_str", (PyCFunction)CPyPy_from_type_str___parse_type_str, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"parse_tuple_type_str", (PyCFunction)CPyPy_from_type_str___parse_tuple_type_str, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef from_type_strmodule = {
    PyModuleDef_HEAD_INIT,
    "faster_eth_abi.from_type_str",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    from_type_strmodule_methods,
    NULL,
};

PyObject *CPyInit_faster_eth_abi___from_type_str(void)
{
    if (CPyModule_faster_eth_abi___from_type_str_internal) {
        Py_INCREF(CPyModule_faster_eth_abi___from_type_str_internal);
        return CPyModule_faster_eth_abi___from_type_str_internal;
    }
    CPyModule_faster_eth_abi___from_type_str_internal = PyModule_Create(&from_type_strmodule);
    if (unlikely(CPyModule_faster_eth_abi___from_type_str_internal == NULL))
        goto fail;
    if (from_type_str_exec(CPyModule_faster_eth_abi___from_type_str_internal) != 0)
        goto fail;
    return CPyModule_faster_eth_abi___from_type_str_internal;
    fail:
    return NULL;
}

PyObject *CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = cpy_r_instance == cpy_r_r0;
    if (!cpy_r_r1) goto CPyL2;
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
CPyL2: ;
    cpy_r_r2 = PyMethod_New(cpy_r___mypyc_self__, cpy_r_instance);
    if (cpy_r_r2 == NULL) goto CPyL4;
    return cpy_r_r2;
CPyL4: ;
    cpy_r_r3 = NULL;
    return cpy_r_r3;
}

PyObject *CPyPy_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"instance", "owner", 0};
    static CPyArg_Parser parser = {"OO:__get__", kwlist, 0};
    PyObject *obj_instance;
    PyObject *obj_owner;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_instance, &obj_owner)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_instance = obj_instance;
    PyObject *arg_owner = obj_owner;
    PyObject *retval = CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/from_type_str.py", "__get__", -1, CPyStatic_from_type_str___globals);
    return NULL;
}

PyObject *CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_cls, PyObject *cpy_r_type_str, PyObject *cpy_r_registry) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_type_str_repr;
    int32_t cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    char cpy_r_r19;
    char cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject **cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject **cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    CPyPtr cpy_r_r40;
    CPyPtr cpy_r_r41;
    CPyPtr cpy_r_r42;
    CPyPtr cpy_r_r43;
    CPyPtr cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    char cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    int32_t cpy_r_r52;
    char cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject **cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    int32_t cpy_r_r72;
    char cpy_r_r73;
    PyObject *cpy_r_r74;
    char cpy_r_r75;
    char cpy_r_r76;
    char cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject **cpy_r_r92;
    PyObject *cpy_r_r93;
    char cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    char cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject **cpy_r_r110;
    PyObject *cpy_r_r111;
    char cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    char cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject **cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject **cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject **cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    cpy_r_r0 = ((faster_eth_abi___from_type_str___new_from_type_str_parse_type_str_decorator_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("faster_eth_abi/from_type_str.py", "new_from_type_str", "new_from_type_str_parse_type_str_decorator_obj", "__mypyc_env__", 48, CPyStatic_from_type_str___globals);
        goto CPyL74;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((faster_eth_abi___from_type_str___decorator_parse_type_str_envObject *)cpy_r_r0)->___mypyc_env__;
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AttributeError("faster_eth_abi/from_type_str.py", "new_from_type_str", "decorator_parse_type_str_env", "__mypyc_env__", 48, CPyStatic_from_type_str___globals);
        goto CPyL75;
    }
    CPy_INCREF_NO_IMM(cpy_r_r1);
CPyL2: ;
    cpy_r_r2 = CPyStatic_from_type_str___globals;
    cpy_r_r3 = CPyStatics[51]; /* 'normalize' */
    cpy_r_r4 = CPyDict_GetItem(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 49, CPyStatic_from_type_str___globals);
        goto CPyL76;
    }
    PyObject *cpy_r_r5[1] = {cpy_r_type_str};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = PyObject_Vectorcall(cpy_r_r4, cpy_r_r6, 1, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 49, CPyStatic_from_type_str___globals);
        goto CPyL76;
    }
    if (likely(PyUnicode_Check(cpy_r_r7)))
        cpy_r_r8 = cpy_r_r7;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 49, CPyStatic_from_type_str___globals, "str", cpy_r_r7);
        goto CPyL76;
    }
    cpy_r_r9 = CPyStatic_from_type_str___globals;
    cpy_r_r10 = CPyStatics[52]; /* 'parse' */
    cpy_r_r11 = CPyDict_GetItem(cpy_r_r9, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 50, CPyStatic_from_type_str___globals);
        goto CPyL77;
    }
    PyObject *cpy_r_r12[1] = {cpy_r_r8};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = PyObject_Vectorcall(cpy_r_r11, cpy_r_r13, 1, 0);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 50, CPyStatic_from_type_str___globals);
        goto CPyL77;
    }
    cpy_r_r15 = PyObject_Repr(cpy_r_type_str);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 52, CPyStatic_from_type_str___globals);
        goto CPyL78;
    }
    cpy_r_type_str_repr = cpy_r_r15;
    cpy_r_r16 = PyUnicode_Compare(cpy_r_type_str, cpy_r_r8);
    cpy_r_r17 = cpy_r_r16 == -1;
    if (!cpy_r_r17) goto CPyL11;
    cpy_r_r18 = PyErr_Occurred();
    cpy_r_r19 = cpy_r_r18 != NULL;
    if (!cpy_r_r19) goto CPyL11;
    cpy_r_r20 = CPy_KeepPropagating();
    if (unlikely(!cpy_r_r20)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 53, CPyStatic_from_type_str___globals);
        goto CPyL79;
    }
CPyL11: ;
    cpy_r_r21 = cpy_r_r16 != 0;
    if (!cpy_r_r21) goto CPyL80;
    cpy_r_r22 = CPyStatics[53]; /* '' */
    cpy_r_r23 = CPyStatics[54]; /* '{:{}}' */
    cpy_r_r24 = CPyStatics[53]; /* '' */
    cpy_r_r25 = CPyStatics[55]; /* 'format' */
    PyObject *cpy_r_r26[3] = {cpy_r_r23, cpy_r_type_str_repr, cpy_r_r24};
    cpy_r_r27 = (PyObject **)&cpy_r_r26;
    cpy_r_r28 = PyObject_VectorcallMethod(cpy_r_r25, cpy_r_r27, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 55, CPyStatic_from_type_str___globals);
        goto CPyL79;
    }
    CPy_DECREF(cpy_r_type_str_repr);
    if (likely(PyUnicode_Check(cpy_r_r28)))
        cpy_r_r29 = cpy_r_r28;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 55, CPyStatic_from_type_str___globals, "str", cpy_r_r28);
        goto CPyL78;
    }
    cpy_r_r30 = CPyStatics[56]; /* ' (normalized to ' */
    cpy_r_r31 = CPyStatics[57]; /* '{!r:{}}' */
    cpy_r_r32 = CPyStatics[53]; /* '' */
    cpy_r_r33 = CPyStatics[55]; /* 'format' */
    PyObject *cpy_r_r34[3] = {cpy_r_r31, cpy_r_r8, cpy_r_r32};
    cpy_r_r35 = (PyObject **)&cpy_r_r34;
    cpy_r_r36 = PyObject_VectorcallMethod(cpy_r_r33, cpy_r_r35, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 55, CPyStatic_from_type_str___globals);
        goto CPyL81;
    }
    CPy_DECREF(cpy_r_r8);
    if (likely(PyUnicode_Check(cpy_r_r36)))
        cpy_r_r37 = cpy_r_r36;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 55, CPyStatic_from_type_str___globals, "str", cpy_r_r36);
        goto CPyL82;
    }
    cpy_r_r38 = CPyStatics[58]; /* ')' */
    cpy_r_r39 = PyList_New(4);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 55, CPyStatic_from_type_str___globals);
        goto CPyL83;
    }
    cpy_r_r40 = (CPyPtr)&((PyListObject *)cpy_r_r39)->ob_item;
    cpy_r_r41 = *(CPyPtr *)cpy_r_r40;
    *(PyObject * *)cpy_r_r41 = cpy_r_r29;
    CPy_INCREF(cpy_r_r30);
    cpy_r_r42 = cpy_r_r41 + 8;
    *(PyObject * *)cpy_r_r42 = cpy_r_r30;
    cpy_r_r43 = cpy_r_r41 + 16;
    *(PyObject * *)cpy_r_r43 = cpy_r_r37;
    CPy_INCREF(cpy_r_r38);
    cpy_r_r44 = cpy_r_r41 + 24;
    *(PyObject * *)cpy_r_r44 = cpy_r_r38;
    cpy_r_r45 = PyUnicode_Join(cpy_r_r22, cpy_r_r39);
    CPy_DECREF_NO_IMM(cpy_r_r39);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 55, CPyStatic_from_type_str___globals);
        goto CPyL84;
    }
    cpy_r_type_str_repr = cpy_r_r45;
CPyL19: ;
    cpy_r_r46 = ((faster_eth_abi___from_type_str___parse_type_str_envObject *)cpy_r_r1)->_expected_base;
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AttributeError("faster_eth_abi/from_type_str.py", "new_from_type_str", "parse_type_str_env", "expected_base", 58, CPyStatic_from_type_str___globals);
        goto CPyL85;
    }
    CPy_INCREF(cpy_r_r46);
CPyL20: ;
    cpy_r_r47 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r48 = cpy_r_r46 != cpy_r_r47;
    CPy_DECREF(cpy_r_r46);
    if (!cpy_r_r48) goto CPyL48;
    cpy_r_r49 = CPyStatic_from_type_str___globals;
    cpy_r_r50 = CPyStatics[59]; /* 'BasicType' */
    cpy_r_r51 = CPyDict_GetItem(cpy_r_r49, cpy_r_r50);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 59, CPyStatic_from_type_str___globals);
        goto CPyL85;
    }
    cpy_r_r52 = PyObject_IsInstance(cpy_r_r14, cpy_r_r51);
    CPy_DECREF(cpy_r_r51);
    cpy_r_r53 = cpy_r_r52 >= 0;
    if (unlikely(!cpy_r_r53)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 59, CPyStatic_from_type_str___globals);
        goto CPyL85;
    }
    cpy_r_r54 = cpy_r_r52;
    if (cpy_r_r54) {
        goto CPyL31;
    } else
        goto CPyL86;
CPyL24: ;
    cpy_r_r55 = CPyStatics[60]; /* '__name__' */
    cpy_r_r56 = CPyObject_GetAttr(cpy_r_cls, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 62, CPyStatic_from_type_str___globals);
        goto CPyL87;
    }
    if (likely(PyUnicode_Check(cpy_r_r56)))
        cpy_r_r57 = cpy_r_r56;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 62, CPyStatic_from_type_str___globals, "str", cpy_r_r56);
        goto CPyL87;
    }
    cpy_r_r58 = CPyStatics[61]; /* 'Cannot create ' */
    cpy_r_r59 = CPyStatics[62]; /* ' for non-basic type ' */
    cpy_r_r60 = CPyStr_Build(4, cpy_r_r58, cpy_r_r57, cpy_r_r59, cpy_r_type_str_repr);
    CPy_DECREF(cpy_r_r57);
    CPy_DECREF(cpy_r_type_str_repr);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 61, CPyStatic_from_type_str___globals);
        goto CPyL74;
    }
    cpy_r_r61 = CPyModule_builtins;
    cpy_r_r62 = CPyStatics[63]; /* 'ValueError' */
    cpy_r_r63 = CPyObject_GetAttr(cpy_r_r61, cpy_r_r62);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 60, CPyStatic_from_type_str___globals);
        goto CPyL88;
    }
    PyObject *cpy_r_r64[1] = {cpy_r_r60};
    cpy_r_r65 = (PyObject **)&cpy_r_r64;
    cpy_r_r66 = PyObject_Vectorcall(cpy_r_r63, cpy_r_r65, 1, 0);
    CPy_DECREF(cpy_r_r63);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 60, CPyStatic_from_type_str___globals);
        goto CPyL88;
    }
    CPy_DECREF(cpy_r_r60);
    CPy_Raise(cpy_r_r66);
    CPy_DECREF(cpy_r_r66);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 60, CPyStatic_from_type_str___globals);
        goto CPyL74;
    }
    CPy_Unreachable();
CPyL31: ;
    cpy_r_r67 = CPyStatics[64]; /* 'base' */
    cpy_r_r68 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 66, CPyStatic_from_type_str___globals);
        goto CPyL85;
    }
    if (likely(PyUnicode_Check(cpy_r_r68)))
        cpy_r_r69 = cpy_r_r68;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 66, CPyStatic_from_type_str___globals, "str", cpy_r_r68);
        goto CPyL85;
    }
    cpy_r_r70 = ((faster_eth_abi___from_type_str___parse_type_str_envObject *)cpy_r_r1)->_expected_base;
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AttributeError("faster_eth_abi/from_type_str.py", "new_from_type_str", "parse_type_str_env", "expected_base", 66, CPyStatic_from_type_str___globals);
        goto CPyL89;
    }
    CPy_INCREF(cpy_r_r70);
CPyL34: ;
    if (likely(cpy_r_r70 != Py_None))
        cpy_r_r71 = cpy_r_r70;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 66, CPyStatic_from_type_str___globals, "str", cpy_r_r70);
        goto CPyL89;
    }
    cpy_r_r72 = PyUnicode_Compare(cpy_r_r69, cpy_r_r71);
    CPy_DECREF(cpy_r_r69);
    CPy_DECREF(cpy_r_r71);
    cpy_r_r73 = cpy_r_r72 == -1;
    if (!cpy_r_r73) goto CPyL38;
    cpy_r_r74 = PyErr_Occurred();
    cpy_r_r75 = cpy_r_r74 != NULL;
    if (!cpy_r_r75) goto CPyL38;
    cpy_r_r76 = CPy_KeepPropagating();
    if (unlikely(!cpy_r_r76)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 66, CPyStatic_from_type_str___globals);
        goto CPyL85;
    }
CPyL38: ;
    cpy_r_r77 = cpy_r_r72 != 0;
    if (cpy_r_r77) {
        goto CPyL90;
    } else
        goto CPyL48;
CPyL39: ;
    cpy_r_r78 = CPyStatics[60]; /* '__name__' */
    cpy_r_r79 = CPyObject_GetAttr(cpy_r_cls, cpy_r_r78);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 70, CPyStatic_from_type_str___globals);
        goto CPyL91;
    }
    if (likely(PyUnicode_Check(cpy_r_r79)))
        cpy_r_r80 = cpy_r_r79;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 70, CPyStatic_from_type_str___globals, "str", cpy_r_r79);
        goto CPyL91;
    }
    cpy_r_r81 = ((faster_eth_abi___from_type_str___parse_type_str_envObject *)cpy_r_r1)->_expected_base;
    if (unlikely(cpy_r_r81 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'expected_base' of 'parse_type_str_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r81);
    }
    CPy_DECREF_NO_IMM(cpy_r_r1);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 72, CPyStatic_from_type_str___globals);
        goto CPyL92;
    }
CPyL42: ;
    if (likely(cpy_r_r81 != Py_None))
        cpy_r_r82 = cpy_r_r81;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 72, CPyStatic_from_type_str___globals, "str", cpy_r_r81);
        goto CPyL92;
    }
    cpy_r_r83 = CPyStatics[61]; /* 'Cannot create ' */
    cpy_r_r84 = CPyStatics[65]; /* ' for type ' */
    cpy_r_r85 = CPyStatics[66]; /* ": expected type with base '" */
    cpy_r_r86 = CPyStatics[67]; /* "'" */
    cpy_r_r87 = CPyStr_Build(7, cpy_r_r83, cpy_r_r80, cpy_r_r84, cpy_r_type_str_repr, cpy_r_r85, cpy_r_r82, cpy_r_r86);
    CPy_DECREF(cpy_r_r80);
    CPy_DECREF(cpy_r_type_str_repr);
    CPy_DECREF(cpy_r_r82);
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 68, CPyStatic_from_type_str___globals);
        goto CPyL74;
    }
    cpy_r_r88 = CPyModule_builtins;
    cpy_r_r89 = CPyStatics[63]; /* 'ValueError' */
    cpy_r_r90 = CPyObject_GetAttr(cpy_r_r88, cpy_r_r89);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 67, CPyStatic_from_type_str___globals);
        goto CPyL93;
    }
    PyObject *cpy_r_r91[1] = {cpy_r_r87};
    cpy_r_r92 = (PyObject **)&cpy_r_r91;
    cpy_r_r93 = PyObject_Vectorcall(cpy_r_r90, cpy_r_r92, 1, 0);
    CPy_DECREF(cpy_r_r90);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 67, CPyStatic_from_type_str___globals);
        goto CPyL93;
    }
    CPy_DECREF(cpy_r_r87);
    CPy_Raise(cpy_r_r93);
    CPy_DECREF(cpy_r_r93);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 67, CPyStatic_from_type_str___globals);
        goto CPyL74;
    }
    CPy_Unreachable();
CPyL48: ;
    cpy_r_r94 = ((faster_eth_abi___from_type_str___parse_type_str_envObject *)cpy_r_r1)->_with_arrlist;
    if (unlikely(cpy_r_r94 == 2)) {
        CPy_AttributeError("faster_eth_abi/from_type_str.py", "new_from_type_str", "parse_type_str_env", "with_arrlist", 76, CPyStatic_from_type_str___globals);
        goto CPyL85;
    }
CPyL49: ;
    if (cpy_r_r94) goto CPyL59;
CPyL50: ;
    cpy_r_r95 = CPyStatics[68]; /* 'arrlist' */
    cpy_r_r96 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r95);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 76, CPyStatic_from_type_str___globals);
        goto CPyL85;
    }
    cpy_r_r97 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r98 = cpy_r_r96 != cpy_r_r97;
    CPy_DECREF(cpy_r_r96);
    if (cpy_r_r98) {
        goto CPyL94;
    } else
        goto CPyL59;
CPyL52: ;
    cpy_r_r99 = CPyStatics[60]; /* '__name__' */
    cpy_r_r100 = CPyObject_GetAttr(cpy_r_cls, cpy_r_r99);
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 80, CPyStatic_from_type_str___globals);
        goto CPyL87;
    }
    if (likely(PyUnicode_Check(cpy_r_r100)))
        cpy_r_r101 = cpy_r_r100;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 80, CPyStatic_from_type_str___globals, "str", cpy_r_r100);
        goto CPyL87;
    }
    cpy_r_r102 = CPyStatics[61]; /* 'Cannot create ' */
    cpy_r_r103 = CPyStatics[65]; /* ' for type ' */
    cpy_r_r104 = CPyStatics[69]; /* ': expected type with no array dimension list' */
    cpy_r_r105 = CPyStr_Build(5, cpy_r_r102, cpy_r_r101, cpy_r_r103, cpy_r_type_str_repr, cpy_r_r104);
    CPy_DECREF(cpy_r_r101);
    CPy_DECREF(cpy_r_type_str_repr);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 78, CPyStatic_from_type_str___globals);
        goto CPyL74;
    }
    cpy_r_r106 = CPyModule_builtins;
    cpy_r_r107 = CPyStatics[63]; /* 'ValueError' */
    cpy_r_r108 = CPyObject_GetAttr(cpy_r_r106, cpy_r_r107);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 77, CPyStatic_from_type_str___globals);
        goto CPyL95;
    }
    PyObject *cpy_r_r109[1] = {cpy_r_r105};
    cpy_r_r110 = (PyObject **)&cpy_r_r109;
    cpy_r_r111 = PyObject_Vectorcall(cpy_r_r108, cpy_r_r110, 1, 0);
    CPy_DECREF(cpy_r_r108);
    if (unlikely(cpy_r_r111 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 77, CPyStatic_from_type_str___globals);
        goto CPyL95;
    }
    CPy_DECREF(cpy_r_r105);
    CPy_Raise(cpy_r_r111);
    CPy_DECREF(cpy_r_r111);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 77, CPyStatic_from_type_str___globals);
        goto CPyL74;
    }
    CPy_Unreachable();
CPyL59: ;
    cpy_r_r112 = ((faster_eth_abi___from_type_str___parse_type_str_envObject *)cpy_r_r1)->_with_arrlist;
    if (unlikely(cpy_r_r112 == 2)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'with_arrlist' of 'parse_type_str_env' undefined");
    }
    CPy_DECREF_NO_IMM(cpy_r_r1);
    if (unlikely(cpy_r_r112 == 2)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 84, CPyStatic_from_type_str___globals);
        goto CPyL96;
    }
CPyL60: ;
    if (!cpy_r_r112) goto CPyL97;
CPyL61: ;
    cpy_r_r113 = CPyStatics[68]; /* 'arrlist' */
    cpy_r_r114 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r113);
    if (unlikely(cpy_r_r114 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 84, CPyStatic_from_type_str___globals);
        goto CPyL96;
    }
    cpy_r_r115 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r116 = cpy_r_r114 == cpy_r_r115;
    CPy_DECREF(cpy_r_r114);
    if (cpy_r_r116) {
        goto CPyL98;
    } else
        goto CPyL97;
CPyL63: ;
    cpy_r_r117 = CPyStatics[60]; /* '__name__' */
    cpy_r_r118 = CPyObject_GetAttr(cpy_r_cls, cpy_r_r117);
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 88, CPyStatic_from_type_str___globals);
        goto CPyL87;
    }
    if (likely(PyUnicode_Check(cpy_r_r118)))
        cpy_r_r119 = cpy_r_r118;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 88, CPyStatic_from_type_str___globals, "str", cpy_r_r118);
        goto CPyL87;
    }
    cpy_r_r120 = CPyStatics[61]; /* 'Cannot create ' */
    cpy_r_r121 = CPyStatics[65]; /* ' for type ' */
    cpy_r_r122 = CPyStatics[70]; /* ': expected type with array dimension list' */
    cpy_r_r123 = CPyStr_Build(5, cpy_r_r120, cpy_r_r119, cpy_r_r121, cpy_r_type_str_repr, cpy_r_r122);
    CPy_DECREF(cpy_r_r119);
    CPy_DECREF(cpy_r_type_str_repr);
    if (unlikely(cpy_r_r123 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 86, CPyStatic_from_type_str___globals);
        goto CPyL74;
    }
    cpy_r_r124 = CPyModule_builtins;
    cpy_r_r125 = CPyStatics[63]; /* 'ValueError' */
    cpy_r_r126 = CPyObject_GetAttr(cpy_r_r124, cpy_r_r125);
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 85, CPyStatic_from_type_str___globals);
        goto CPyL99;
    }
    PyObject *cpy_r_r127[1] = {cpy_r_r123};
    cpy_r_r128 = (PyObject **)&cpy_r_r127;
    cpy_r_r129 = PyObject_Vectorcall(cpy_r_r126, cpy_r_r128, 1, 0);
    CPy_DECREF(cpy_r_r126);
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 85, CPyStatic_from_type_str___globals);
        goto CPyL99;
    }
    CPy_DECREF(cpy_r_r123);
    CPy_Raise(cpy_r_r129);
    CPy_DECREF(cpy_r_r129);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 85, CPyStatic_from_type_str___globals);
        goto CPyL74;
    }
    CPy_Unreachable();
CPyL70: ;
    cpy_r_r130 = CPyStatics[71]; /* 'validate' */
    PyObject *cpy_r_r131[1] = {cpy_r_r14};
    cpy_r_r132 = (PyObject **)&cpy_r_r131;
    cpy_r_r133 = PyObject_VectorcallMethod(cpy_r_r130, cpy_r_r132, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r133 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 94, CPyStatic_from_type_str___globals);
        goto CPyL100;
    } else
        goto CPyL101;
CPyL71: ;
    cpy_r_r134 = ((faster_eth_abi___from_type_str___decorator_parse_type_str_envObject *)cpy_r_r0)->_old_from_type_str;
    if (unlikely(cpy_r_r134 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'old_from_type_str' of 'decorator_parse_type_str_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r134);
    }
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 96, CPyStatic_from_type_str___globals);
        goto CPyL102;
    }
CPyL72: ;
    PyObject *cpy_r_r135[3] = {cpy_r_cls, cpy_r_r14, cpy_r_registry};
    cpy_r_r136 = (PyObject **)&cpy_r_r135;
    cpy_r_r137 = PyObject_Vectorcall(cpy_r_r134, cpy_r_r136, 3, 0);
    CPy_DECREF(cpy_r_r134);
    if (unlikely(cpy_r_r137 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 96, CPyStatic_from_type_str___globals);
        goto CPyL102;
    }
    CPy_DECREF(cpy_r_r14);
    return cpy_r_r137;
CPyL74: ;
    cpy_r_r138 = NULL;
    return cpy_r_r138;
CPyL75: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL74;
CPyL76: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    goto CPyL74;
CPyL77: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r8);
    goto CPyL74;
CPyL78: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r14);
    goto CPyL74;
CPyL79: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_type_str_repr);
    goto CPyL74;
CPyL80: ;
    CPy_DECREF(cpy_r_r8);
    goto CPyL19;
CPyL81: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r29);
    goto CPyL74;
CPyL82: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r29);
    goto CPyL74;
CPyL83: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r37);
    goto CPyL74;
CPyL84: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r14);
    goto CPyL74;
CPyL85: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_type_str_repr);
    goto CPyL74;
CPyL86: ;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    CPy_DECREF_NO_IMM(cpy_r_r1);
    CPy_DECREF(cpy_r_r14);
    goto CPyL24;
CPyL87: ;
    CPy_DecRef(cpy_r_type_str_repr);
    goto CPyL74;
CPyL88: ;
    CPy_DecRef(cpy_r_r60);
    goto CPyL74;
CPyL89: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_type_str_repr);
    CPy_DecRef(cpy_r_r69);
    goto CPyL74;
CPyL90: ;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    CPy_DECREF(cpy_r_r14);
    goto CPyL39;
CPyL91: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_type_str_repr);
    goto CPyL74;
CPyL92: ;
    CPy_DecRef(cpy_r_type_str_repr);
    CPy_DecRef(cpy_r_r80);
    goto CPyL74;
CPyL93: ;
    CPy_DecRef(cpy_r_r87);
    goto CPyL74;
CPyL94: ;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    CPy_DECREF_NO_IMM(cpy_r_r1);
    CPy_DECREF(cpy_r_r14);
    goto CPyL52;
CPyL95: ;
    CPy_DecRef(cpy_r_r105);
    goto CPyL74;
CPyL96: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_type_str_repr);
    goto CPyL74;
CPyL97: ;
    CPy_DECREF(cpy_r_type_str_repr);
    goto CPyL70;
CPyL98: ;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    CPy_DECREF(cpy_r_r14);
    goto CPyL63;
CPyL99: ;
    CPy_DecRef(cpy_r_r123);
    goto CPyL74;
CPyL100: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r14);
    goto CPyL74;
CPyL101: ;
    CPy_DECREF(cpy_r_r133);
    goto CPyL71;
CPyL102: ;
    CPy_DecRef(cpy_r_r14);
    goto CPyL74;
}

PyObject *CPyPy_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"cls", "type_str", "registry", 0};
    static CPyArg_Parser parser = {"OOO:__call__", kwlist, 0};
    PyObject *obj_cls;
    PyObject *obj_type_str;
    PyObject *obj_registry;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_cls, &obj_type_str, &obj_registry)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_cls = obj_cls;
    PyObject *arg_type_str;
    if (likely(PyUnicode_Check(obj_type_str)))
        arg_type_str = obj_type_str;
    else {
        CPy_TypeError("str", obj_type_str); 
        goto fail;
    }
    PyObject *arg_registry = obj_registry;
    PyObject *retval = CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____call__(arg___mypyc_self__, arg_cls, arg_type_str, arg_registry);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 48, CPyStatic_from_type_str___globals);
    return NULL;
}

PyObject *CPyDef_from_type_str___decorator_parse_type_str_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = cpy_r_instance == cpy_r_r0;
    if (!cpy_r_r1) goto CPyL2;
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
CPyL2: ;
    cpy_r_r2 = PyMethod_New(cpy_r___mypyc_self__, cpy_r_instance);
    if (cpy_r_r2 == NULL) goto CPyL4;
    return cpy_r_r2;
CPyL4: ;
    cpy_r_r3 = NULL;
    return cpy_r_r3;
}

PyObject *CPyPy_from_type_str___decorator_parse_type_str_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"instance", "owner", 0};
    static CPyArg_Parser parser = {"OO:__get__", kwlist, 0};
    PyObject *obj_instance;
    PyObject *obj_owner;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_instance, &obj_owner)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_instance = obj_instance;
    PyObject *arg_owner = obj_owner;
    PyObject *retval = CPyDef_from_type_str___decorator_parse_type_str_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/from_type_str.py", "__get__", -1, CPyStatic_from_type_str___globals);
    return NULL;
}

PyObject *CPyDef_from_type_str___decorator_parse_type_str_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_old_from_type_str) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    int32_t cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject **cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    cpy_r_r0 = ((faster_eth_abi___from_type_str___decorator_parse_type_str_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("faster_eth_abi/from_type_str.py", "decorator", "decorator_parse_type_str_obj", "__mypyc_env__", 46, CPyStatic_from_type_str___globals);
        goto CPyL14;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyDef_from_type_str___decorator_parse_type_str_env();
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "decorator", 46, CPyStatic_from_type_str___globals);
        goto CPyL15;
    }
    if (((faster_eth_abi___from_type_str___decorator_parse_type_str_envObject *)cpy_r_r1)->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(((faster_eth_abi___from_type_str___decorator_parse_type_str_envObject *)cpy_r_r1)->___mypyc_env__);
    }
    ((faster_eth_abi___from_type_str___decorator_parse_type_str_envObject *)cpy_r_r1)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "decorator", 46, CPyStatic_from_type_str___globals);
        goto CPyL16;
    }
    CPy_INCREF(cpy_r_old_from_type_str);
    if (((faster_eth_abi___from_type_str___decorator_parse_type_str_envObject *)cpy_r_r1)->_old_from_type_str != NULL) {
        CPy_DECREF(((faster_eth_abi___from_type_str___decorator_parse_type_str_envObject *)cpy_r_r1)->_old_from_type_str);
    }
    ((faster_eth_abi___from_type_str___decorator_parse_type_str_envObject *)cpy_r_r1)->_old_from_type_str = cpy_r_old_from_type_str;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "decorator", 46, CPyStatic_from_type_str___globals);
        goto CPyL16;
    }
    cpy_r_r4 = CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj();
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "decorator", 48, CPyStatic_from_type_str___globals);
        goto CPyL16;
    }
    CPy_INCREF_NO_IMM(cpy_r_r1);
    if (((faster_eth_abi___from_type_str___new_from_type_str_parse_type_str_decorator_objObject *)cpy_r_r4)->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(((faster_eth_abi___from_type_str___new_from_type_str_parse_type_str_decorator_objObject *)cpy_r_r4)->___mypyc_env__);
    }
    ((faster_eth_abi___from_type_str___new_from_type_str_parse_type_str_decorator_objObject *)cpy_r_r4)->___mypyc_env__ = cpy_r_r1;
    cpy_r_r5 = 1;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "decorator", 48, CPyStatic_from_type_str___globals);
        goto CPyL17;
    }
    cpy_r_r6 = ((faster_eth_abi___from_type_str___decorator_parse_type_str_envObject *)cpy_r_r1)->_old_from_type_str;
    if (unlikely(cpy_r_r6 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'old_from_type_str' of 'decorator_parse_type_str_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r6);
    }
    CPy_DECREF_NO_IMM(cpy_r_r1);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "decorator", 47, CPyStatic_from_type_str___globals);
        goto CPyL18;
    }
CPyL7: ;
    cpy_r_r7 = CPyModule_functools;
    cpy_r_r8 = CPyStatics[72]; /* 'wraps' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "decorator", 47, CPyStatic_from_type_str___globals);
        goto CPyL19;
    }
    PyObject *cpy_r_r10[1] = {cpy_r_r6};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = PyObject_Vectorcall(cpy_r_r9, cpy_r_r11, 1, 0);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "decorator", 47, CPyStatic_from_type_str___globals);
        goto CPyL19;
    }
    CPy_DECREF(cpy_r_r6);
    PyObject *cpy_r_r13[1] = {cpy_r_r4};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = PyObject_Vectorcall(cpy_r_r12, cpy_r_r14, 1, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "decorator", 48, CPyStatic_from_type_str___globals);
        goto CPyL18;
    }
    CPy_DECREF_NO_IMM(cpy_r_r4);
    CPy_INCREF(cpy_r_r15);
    cpy_r_r16 = CPyStatic_from_type_str___globals;
    cpy_r_r17 = CPyStatics[73]; /* 'new_from_type_str' */
    cpy_r_r18 = CPyDict_SetItem(cpy_r_r16, cpy_r_r17, cpy_r_r15);
    CPy_DECREF(cpy_r_r15);
    cpy_r_r19 = cpy_r_r18 >= 0;
    if (unlikely(!cpy_r_r19)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "decorator", 48, CPyStatic_from_type_str___globals);
        goto CPyL20;
    }
    cpy_r_r20 = CPyModule_builtins;
    cpy_r_r21 = CPyStatics[74]; /* 'classmethod' */
    cpy_r_r22 = CPyObject_GetAttr(cpy_r_r20, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "decorator", 98, CPyStatic_from_type_str___globals);
        goto CPyL20;
    }
    PyObject *cpy_r_r23[1] = {cpy_r_r15};
    cpy_r_r24 = (PyObject **)&cpy_r_r23;
    cpy_r_r25 = PyObject_Vectorcall(cpy_r_r22, cpy_r_r24, 1, 0);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "decorator", 98, CPyStatic_from_type_str___globals);
        goto CPyL20;
    }
    CPy_DECREF(cpy_r_r15);
    return cpy_r_r25;
CPyL14: ;
    cpy_r_r26 = NULL;
    return cpy_r_r26;
CPyL15: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL14;
CPyL16: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL14;
CPyL17: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r4);
    goto CPyL14;
CPyL18: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL14;
CPyL19: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r6);
    goto CPyL14;
CPyL20: ;
    CPy_DecRef(cpy_r_r15);
    goto CPyL14;
}

PyObject *CPyPy_from_type_str___decorator_parse_type_str_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"old_from_type_str", 0};
    static CPyArg_Parser parser = {"O:__call__", kwlist, 0};
    PyObject *obj_old_from_type_str;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_old_from_type_str)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_old_from_type_str = obj_old_from_type_str;
    PyObject *retval = CPyDef_from_type_str___decorator_parse_type_str_obj_____call__(arg___mypyc_self__, arg_old_from_type_str);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/from_type_str.py", "decorator", 46, CPyStatic_from_type_str___globals);
    return NULL;
}

PyObject *CPyDef_from_type_str___parse_type_str(PyObject *cpy_r_expected_base, char cpy_r_with_arrlist) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_decorator;
    PyObject *cpy_r_r6;
    if (cpy_r_expected_base != NULL) goto CPyL11;
    cpy_r_r0 = Py_None;
    cpy_r_expected_base = cpy_r_r0;
CPyL2: ;
    if (cpy_r_with_arrlist != 2) goto CPyL4;
    cpy_r_with_arrlist = 0;
CPyL4: ;
    cpy_r_r1 = CPyDef_from_type_str___parse_type_str_env();
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_type_str", 35, CPyStatic_from_type_str___globals);
        goto CPyL12;
    }
    if (((faster_eth_abi___from_type_str___parse_type_str_envObject *)cpy_r_r1)->_expected_base != NULL) {
        CPy_DECREF(((faster_eth_abi___from_type_str___parse_type_str_envObject *)cpy_r_r1)->_expected_base);
    }
    ((faster_eth_abi___from_type_str___parse_type_str_envObject *)cpy_r_r1)->_expected_base = cpy_r_expected_base;
    cpy_r_r2 = 1;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_type_str", 35, CPyStatic_from_type_str___globals);
        goto CPyL13;
    }
    ((faster_eth_abi___from_type_str___parse_type_str_envObject *)cpy_r_r1)->_with_arrlist = cpy_r_with_arrlist;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_type_str", 35, CPyStatic_from_type_str___globals);
        goto CPyL13;
    }
    cpy_r_r4 = CPyDef_from_type_str___decorator_parse_type_str_obj();
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_type_str", 46, CPyStatic_from_type_str___globals);
        goto CPyL13;
    }
    if (((faster_eth_abi___from_type_str___decorator_parse_type_str_objObject *)cpy_r_r4)->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(((faster_eth_abi___from_type_str___decorator_parse_type_str_objObject *)cpy_r_r4)->___mypyc_env__);
    }
    ((faster_eth_abi___from_type_str___decorator_parse_type_str_objObject *)cpy_r_r4)->___mypyc_env__ = cpy_r_r1;
    cpy_r_r5 = 1;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_type_str", 46, CPyStatic_from_type_str___globals);
        goto CPyL14;
    }
    cpy_r_decorator = cpy_r_r4;
    return cpy_r_decorator;
CPyL10: ;
    cpy_r_r6 = NULL;
    return cpy_r_r6;
CPyL11: ;
    CPy_INCREF(cpy_r_expected_base);
    goto CPyL2;
CPyL12: ;
    CPy_DecRef(cpy_r_expected_base);
    goto CPyL10;
CPyL13: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL10;
CPyL14: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL10;
}

PyObject *CPyPy_from_type_str___parse_type_str(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"expected_base", "with_arrlist", 0};
    static CPyArg_Parser parser = {"|OO:parse_type_str", kwlist, 0};
    PyObject *obj_expected_base = NULL;
    PyObject *obj_with_arrlist = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_expected_base, &obj_with_arrlist)) {
        return NULL;
    }
    PyObject *arg_expected_base;
    if (obj_expected_base == NULL) {
        arg_expected_base = NULL;
        goto __LL4;
    }
    if (PyUnicode_Check(obj_expected_base))
        arg_expected_base = obj_expected_base;
    else {
        arg_expected_base = NULL;
    }
    if (arg_expected_base != NULL) goto __LL4;
    if (obj_expected_base == Py_None)
        arg_expected_base = obj_expected_base;
    else {
        arg_expected_base = NULL;
    }
    if (arg_expected_base != NULL) goto __LL4;
    CPy_TypeError("str or None", obj_expected_base); 
    goto fail;
__LL4: ;
    char arg_with_arrlist;
    if (obj_with_arrlist == NULL) {
        arg_with_arrlist = 2;
    } else if (unlikely(!PyBool_Check(obj_with_arrlist))) {
        CPy_TypeError("bool", obj_with_arrlist); goto fail;
    } else
        arg_with_arrlist = obj_with_arrlist == Py_True;
    PyObject *retval = CPyDef_from_type_str___parse_type_str(arg_expected_base, arg_with_arrlist);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_type_str", 35, CPyStatic_from_type_str___globals);
    return NULL;
}

PyObject *CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = cpy_r_instance == cpy_r_r0;
    if (!cpy_r_r1) goto CPyL2;
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
CPyL2: ;
    cpy_r_r2 = PyMethod_New(cpy_r___mypyc_self__, cpy_r_instance);
    if (cpy_r_r2 == NULL) goto CPyL4;
    return cpy_r_r2;
CPyL4: ;
    cpy_r_r3 = NULL;
    return cpy_r_r3;
}

PyObject *CPyPy_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"instance", "owner", 0};
    static CPyArg_Parser parser = {"OO:__get__", kwlist, 0};
    PyObject *obj_instance;
    PyObject *obj_owner;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_instance, &obj_owner)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_instance = obj_instance;
    PyObject *arg_owner = obj_owner;
    PyObject *retval = CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/from_type_str.py", "__get__", -1, CPyStatic_from_type_str___globals);
    return NULL;
}

PyObject *CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_cls, PyObject *cpy_r_type_str, PyObject *cpy_r_registry) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    int32_t cpy_r_r17;
    char cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_type_str_repr;
    int32_t cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    char cpy_r_r24;
    char cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject **cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject **cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject **cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    cpy_r_r0 = ((faster_eth_abi___from_type_str___new_from_type_str_parse_tuple_type_str_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("faster_eth_abi/from_type_str.py", "new_from_type_str", "new_from_type_str_parse_tuple_type_str_obj", "__mypyc_env__", 113, CPyStatic_from_type_str___globals);
        goto CPyL28;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyStatic_from_type_str___globals;
    cpy_r_r2 = CPyStatics[51]; /* 'normalize' */
    cpy_r_r3 = CPyDict_GetItem(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 114, CPyStatic_from_type_str___globals);
        goto CPyL29;
    }
    PyObject *cpy_r_r4[1] = {cpy_r_type_str};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = PyObject_Vectorcall(cpy_r_r3, cpy_r_r5, 1, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 114, CPyStatic_from_type_str___globals);
        goto CPyL29;
    }
    if (likely(PyUnicode_Check(cpy_r_r6)))
        cpy_r_r7 = cpy_r_r6;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 114, CPyStatic_from_type_str___globals, "str", cpy_r_r6);
        goto CPyL29;
    }
    cpy_r_r8 = CPyStatic_from_type_str___globals;
    cpy_r_r9 = CPyStatics[52]; /* 'parse' */
    cpy_r_r10 = CPyDict_GetItem(cpy_r_r8, cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 115, CPyStatic_from_type_str___globals);
        goto CPyL30;
    }
    PyObject *cpy_r_r11[1] = {cpy_r_r7};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = PyObject_Vectorcall(cpy_r_r10, cpy_r_r12, 1, 0);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 115, CPyStatic_from_type_str___globals);
        goto CPyL30;
    }
    cpy_r_r14 = CPyStatic_from_type_str___globals;
    cpy_r_r15 = CPyStatics[75]; /* 'TupleType' */
    cpy_r_r16 = CPyDict_GetItem(cpy_r_r14, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 117, CPyStatic_from_type_str___globals);
        goto CPyL31;
    }
    cpy_r_r17 = PyObject_IsInstance(cpy_r_r13, cpy_r_r16);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r18 = cpy_r_r17 >= 0;
    if (unlikely(!cpy_r_r18)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 117, CPyStatic_from_type_str___globals);
        goto CPyL31;
    }
    cpy_r_r19 = cpy_r_r17;
    if (cpy_r_r19) {
        goto CPyL32;
    } else
        goto CPyL33;
CPyL9: ;
    cpy_r_r20 = PyObject_Repr(cpy_r_type_str);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 118, CPyStatic_from_type_str___globals);
        goto CPyL34;
    }
    cpy_r_type_str_repr = cpy_r_r20;
    cpy_r_r21 = PyUnicode_Compare(cpy_r_type_str, cpy_r_r7);
    cpy_r_r22 = cpy_r_r21 == -1;
    if (!cpy_r_r22) goto CPyL13;
    cpy_r_r23 = PyErr_Occurred();
    cpy_r_r24 = cpy_r_r23 != NULL;
    if (!cpy_r_r24) goto CPyL13;
    cpy_r_r25 = CPy_KeepPropagating();
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 119, CPyStatic_from_type_str___globals);
        goto CPyL35;
    }
CPyL13: ;
    cpy_r_r26 = cpy_r_r21 != 0;
    if (!cpy_r_r26) goto CPyL36;
    cpy_r_r27 = PyObject_Repr(cpy_r_r7);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 122, CPyStatic_from_type_str___globals);
        goto CPyL37;
    }
    cpy_r_r28 = CPyStatics[56]; /* ' (normalized to ' */
    cpy_r_r29 = CPyStatics[58]; /* ')' */
    cpy_r_r30 = CPyStr_Build(4, cpy_r_type_str_repr, cpy_r_r28, cpy_r_r27, cpy_r_r29);
    CPy_DECREF(cpy_r_type_str_repr);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 120, CPyStatic_from_type_str___globals);
        goto CPyL28;
    }
    cpy_r_type_str_repr = cpy_r_r30;
CPyL17: ;
    cpy_r_r31 = CPyStatics[60]; /* '__name__' */
    cpy_r_r32 = CPyObject_GetAttr(cpy_r_cls, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 126, CPyStatic_from_type_str___globals);
        goto CPyL37;
    }
    if (likely(PyUnicode_Check(cpy_r_r32)))
        cpy_r_r33 = cpy_r_r32;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 126, CPyStatic_from_type_str___globals, "str", cpy_r_r32);
        goto CPyL37;
    }
    cpy_r_r34 = CPyStatics[61]; /* 'Cannot create ' */
    cpy_r_r35 = CPyStatics[76]; /* ' for non-tuple type ' */
    cpy_r_r36 = CPyStr_Build(4, cpy_r_r34, cpy_r_r33, cpy_r_r35, cpy_r_type_str_repr);
    CPy_DECREF(cpy_r_r33);
    CPy_DECREF(cpy_r_type_str_repr);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 125, CPyStatic_from_type_str___globals);
        goto CPyL28;
    }
    cpy_r_r37 = CPyModule_builtins;
    cpy_r_r38 = CPyStatics[63]; /* 'ValueError' */
    cpy_r_r39 = CPyObject_GetAttr(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 124, CPyStatic_from_type_str___globals);
        goto CPyL38;
    }
    PyObject *cpy_r_r40[1] = {cpy_r_r36};
    cpy_r_r41 = (PyObject **)&cpy_r_r40;
    cpy_r_r42 = PyObject_Vectorcall(cpy_r_r39, cpy_r_r41, 1, 0);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 124, CPyStatic_from_type_str___globals);
        goto CPyL38;
    }
    CPy_DECREF(cpy_r_r36);
    CPy_Raise(cpy_r_r42);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 124, CPyStatic_from_type_str___globals);
        goto CPyL28;
    }
    CPy_Unreachable();
CPyL24: ;
    cpy_r_r43 = CPyStatics[71]; /* 'validate' */
    PyObject *cpy_r_r44[1] = {cpy_r_r13};
    cpy_r_r45 = (PyObject **)&cpy_r_r44;
    cpy_r_r46 = PyObject_VectorcallMethod(cpy_r_r43, cpy_r_r45, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 131, CPyStatic_from_type_str___globals);
        goto CPyL39;
    } else
        goto CPyL40;
CPyL25: ;
    cpy_r_r47 = ((faster_eth_abi___from_type_str___parse_tuple_type_str_envObject *)cpy_r_r0)->_old_from_type_str;
    if (unlikely(cpy_r_r47 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'old_from_type_str' of 'parse_tuple_type_str_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r47);
    }
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 133, CPyStatic_from_type_str___globals);
        goto CPyL41;
    }
CPyL26: ;
    PyObject *cpy_r_r48[3] = {cpy_r_cls, cpy_r_r13, cpy_r_registry};
    cpy_r_r49 = (PyObject **)&cpy_r_r48;
    cpy_r_r50 = PyObject_Vectorcall(cpy_r_r47, cpy_r_r49, 3, 0);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 133, CPyStatic_from_type_str___globals);
        goto CPyL41;
    }
    CPy_DECREF(cpy_r_r13);
    return cpy_r_r50;
CPyL28: ;
    cpy_r_r51 = NULL;
    return cpy_r_r51;
CPyL29: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL28;
CPyL30: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r7);
    goto CPyL28;
CPyL31: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r13);
    goto CPyL28;
CPyL32: ;
    CPy_DECREF(cpy_r_r7);
    goto CPyL24;
CPyL33: ;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    CPy_DECREF(cpy_r_r13);
    goto CPyL9;
CPyL34: ;
    CPy_DecRef(cpy_r_r7);
    goto CPyL28;
CPyL35: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_type_str_repr);
    goto CPyL28;
CPyL36: ;
    CPy_DECREF(cpy_r_r7);
    goto CPyL17;
CPyL37: ;
    CPy_DecRef(cpy_r_type_str_repr);
    goto CPyL28;
CPyL38: ;
    CPy_DecRef(cpy_r_r36);
    goto CPyL28;
CPyL39: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r13);
    goto CPyL28;
CPyL40: ;
    CPy_DECREF(cpy_r_r46);
    goto CPyL25;
CPyL41: ;
    CPy_DecRef(cpy_r_r13);
    goto CPyL28;
}

PyObject *CPyPy_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"cls", "type_str", "registry", 0};
    static CPyArg_Parser parser = {"OOO:__call__", kwlist, 0};
    PyObject *obj_cls;
    PyObject *obj_type_str;
    PyObject *obj_registry;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_cls, &obj_type_str, &obj_registry)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_cls = obj_cls;
    PyObject *arg_type_str;
    if (likely(PyUnicode_Check(obj_type_str)))
        arg_type_str = obj_type_str;
    else {
        CPy_TypeError("str", obj_type_str); 
        goto fail;
    }
    PyObject *arg_registry = obj_registry;
    PyObject *retval = CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____call__(arg___mypyc_self__, arg_cls, arg_type_str, arg_registry);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/from_type_str.py", "new_from_type_str", 113, CPyStatic_from_type_str___globals);
    return NULL;
}

PyObject *CPyDef_from_type_str___parse_tuple_type_str(PyObject *cpy_r_old_from_type_str) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    int32_t cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject **cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    cpy_r_r0 = CPyDef_from_type_str___parse_tuple_type_str_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_tuple_type_str", 103, CPyStatic_from_type_str___globals);
        goto CPyL12;
    }
    CPy_INCREF(cpy_r_old_from_type_str);
    if (((faster_eth_abi___from_type_str___parse_tuple_type_str_envObject *)cpy_r_r0)->_old_from_type_str != NULL) {
        CPy_DECREF(((faster_eth_abi___from_type_str___parse_tuple_type_str_envObject *)cpy_r_r0)->_old_from_type_str);
    }
    ((faster_eth_abi___from_type_str___parse_tuple_type_str_envObject *)cpy_r_r0)->_old_from_type_str = cpy_r_old_from_type_str;
    cpy_r_r1 = 1;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_tuple_type_str", 103, CPyStatic_from_type_str___globals);
        goto CPyL13;
    }
    cpy_r_r2 = CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj();
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_tuple_type_str", 113, CPyStatic_from_type_str___globals);
        goto CPyL13;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
    if (((faster_eth_abi___from_type_str___new_from_type_str_parse_tuple_type_str_objObject *)cpy_r_r2)->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(((faster_eth_abi___from_type_str___new_from_type_str_parse_tuple_type_str_objObject *)cpy_r_r2)->___mypyc_env__);
    }
    ((faster_eth_abi___from_type_str___new_from_type_str_parse_tuple_type_str_objObject *)cpy_r_r2)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r3 = 1;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_tuple_type_str", 113, CPyStatic_from_type_str___globals);
        goto CPyL14;
    }
    cpy_r_r4 = ((faster_eth_abi___from_type_str___parse_tuple_type_str_envObject *)cpy_r_r0)->_old_from_type_str;
    if (unlikely(cpy_r_r4 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'old_from_type_str' of 'parse_tuple_type_str_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r4);
    }
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_tuple_type_str", 112, CPyStatic_from_type_str___globals);
        goto CPyL15;
    }
CPyL5: ;
    cpy_r_r5 = CPyModule_functools;
    cpy_r_r6 = CPyStatics[72]; /* 'wraps' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_tuple_type_str", 112, CPyStatic_from_type_str___globals);
        goto CPyL16;
    }
    PyObject *cpy_r_r8[1] = {cpy_r_r4};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_Vectorcall(cpy_r_r7, cpy_r_r9, 1, 0);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_tuple_type_str", 112, CPyStatic_from_type_str___globals);
        goto CPyL16;
    }
    CPy_DECREF(cpy_r_r4);
    PyObject *cpy_r_r11[1] = {cpy_r_r2};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = PyObject_Vectorcall(cpy_r_r10, cpy_r_r12, 1, 0);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_tuple_type_str", 113, CPyStatic_from_type_str___globals);
        goto CPyL15;
    }
    CPy_DECREF_NO_IMM(cpy_r_r2);
    CPy_INCREF(cpy_r_r13);
    cpy_r_r14 = CPyStatic_from_type_str___globals;
    cpy_r_r15 = CPyStatics[73]; /* 'new_from_type_str' */
    cpy_r_r16 = CPyDict_SetItem(cpy_r_r14, cpy_r_r15, cpy_r_r13);
    CPy_DECREF(cpy_r_r13);
    cpy_r_r17 = cpy_r_r16 >= 0;
    if (unlikely(!cpy_r_r17)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_tuple_type_str", 113, CPyStatic_from_type_str___globals);
        goto CPyL17;
    }
    cpy_r_r18 = CPyModule_builtins;
    cpy_r_r19 = CPyStatics[74]; /* 'classmethod' */
    cpy_r_r20 = CPyObject_GetAttr(cpy_r_r18, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_tuple_type_str", 135, CPyStatic_from_type_str___globals);
        goto CPyL17;
    }
    PyObject *cpy_r_r21[1] = {cpy_r_r13};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = PyObject_Vectorcall(cpy_r_r20, cpy_r_r22, 1, 0);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_tuple_type_str", 135, CPyStatic_from_type_str___globals);
        goto CPyL17;
    }
    CPy_DECREF(cpy_r_r13);
    return cpy_r_r23;
CPyL12: ;
    cpy_r_r24 = NULL;
    return cpy_r_r24;
CPyL13: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL12;
CPyL14: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r2);
    goto CPyL12;
CPyL15: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL12;
CPyL16: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r4);
    goto CPyL12;
CPyL17: ;
    CPy_DecRef(cpy_r_r13);
    goto CPyL12;
}

PyObject *CPyPy_from_type_str___parse_tuple_type_str(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"old_from_type_str", 0};
    static CPyArg_Parser parser = {"O:parse_tuple_type_str", kwlist, 0};
    PyObject *obj_old_from_type_str;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_old_from_type_str)) {
        return NULL;
    }
    PyObject *arg_old_from_type_str = obj_old_from_type_str;
    PyObject *retval = CPyDef_from_type_str___parse_tuple_type_str(arg_old_from_type_str);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/from_type_str.py", "parse_tuple_type_str", 103, CPyStatic_from_type_str___globals);
    return NULL;
}

char CPyDef_from_type_str_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r5;
    void *cpy_r_r7;
    void *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject **cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    int32_t cpy_r_r42;
    char cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    CPyPtr cpy_r_r55;
    CPyPtr cpy_r_r56;
    CPyPtr cpy_r_r57;
    CPyPtr cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    tuple_T2OO cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    int32_t cpy_r_r67;
    char cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    CPyPtr cpy_r_r82;
    CPyPtr cpy_r_r83;
    CPyPtr cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    tuple_T3OOO cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    int32_t cpy_r_r93;
    char cpy_r_r94;
    char cpy_r_r95;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[11]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", -1, CPyStatic_from_type_str___globals);
        goto CPyL30;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_functools;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {1};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[213]; /* (('functools', 'functools', 'functools'),) */
    cpy_r_r11 = CPyStatic_from_type_str___globals;
    cpy_r_r12 = CPyStatics[78]; /* 'faster_eth_abi/from_type_str.py' */
    cpy_r_r13 = CPyStatics[79]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL30;
    cpy_r_r15 = CPyStatics[214]; /* ('TYPE_CHECKING', 'Any', 'Callable', 'Optional', 'Type',
                                    'TypeVar') */
    cpy_r_r16 = CPyStatics[17]; /* 'typing' */
    cpy_r_r17 = CPyStatic_from_type_str___globals;
    cpy_r_r18 = CPyImport_ImportFromMany(cpy_r_r16, cpy_r_r15, cpy_r_r15, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 2, CPyStatic_from_type_str___globals);
        goto CPyL30;
    }
    CPyModule_typing = cpy_r_r18;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = CPyStatics[215]; /* ('TypeStr',) */
    cpy_r_r20 = CPyStatics[20]; /* 'eth_typing' */
    cpy_r_r21 = CPyStatic_from_type_str___globals;
    cpy_r_r22 = CPyImport_ImportFromMany(cpy_r_r20, cpy_r_r19, cpy_r_r19, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 11, CPyStatic_from_type_str___globals);
        goto CPyL30;
    }
    CPyModule_eth_typing = cpy_r_r22;
    CPy_INCREF(CPyModule_eth_typing);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r23 = CPyStatics[216]; /* ('ABIType', 'BasicType', 'TupleType', 'normalize',
                                    'parse') */
    cpy_r_r24 = CPyStatics[82]; /* 'faster_eth_abi.grammar' */
    cpy_r_r25 = CPyStatic_from_type_str___globals;
    cpy_r_r26 = CPyImport_ImportFromMany(cpy_r_r24, cpy_r_r23, cpy_r_r23, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 15, CPyStatic_from_type_str___globals);
        goto CPyL30;
    }
    CPyModule_faster_eth_abi___grammar = cpy_r_r26;
    CPy_INCREF(CPyModule_faster_eth_abi___grammar);
    CPy_DECREF(cpy_r_r26);
    cpy_r_r27 = CPyStatics[83]; /* 'TType' */
    cpy_r_r28 = CPyStatic_from_type_str___globals;
    cpy_r_r29 = CPyStatics[80]; /* 'Type' */
    cpy_r_r30 = CPyDict_GetItem(cpy_r_r28, cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 29, CPyStatic_from_type_str___globals);
        goto CPyL30;
    }
    cpy_r_r31 = CPyStatics[84]; /* 'BaseCoder' */
    cpy_r_r32 = PyObject_GetItem(cpy_r_r30, cpy_r_r31);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 29, CPyStatic_from_type_str___globals);
        goto CPyL30;
    }
    cpy_r_r33 = CPyStatic_from_type_str___globals;
    cpy_r_r34 = CPyStatics[36]; /* 'TypeVar' */
    cpy_r_r35 = CPyDict_GetItem(cpy_r_r33, cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 29, CPyStatic_from_type_str___globals);
        goto CPyL31;
    }
    PyObject *cpy_r_r36[2] = {cpy_r_r27, cpy_r_r32};
    cpy_r_r37 = (PyObject **)&cpy_r_r36;
    cpy_r_r38 = CPyStatics[217]; /* ('bound',) */
    cpy_r_r39 = PyObject_Vectorcall(cpy_r_r35, cpy_r_r37, 1, cpy_r_r38);
    CPy_DECREF(cpy_r_r35);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 29, CPyStatic_from_type_str___globals);
        goto CPyL31;
    }
    CPy_DECREF(cpy_r_r32);
    cpy_r_r40 = CPyStatic_from_type_str___globals;
    cpy_r_r41 = CPyStatics[83]; /* 'TType' */
    cpy_r_r42 = CPyDict_SetItem(cpy_r_r40, cpy_r_r41, cpy_r_r39);
    CPy_DECREF(cpy_r_r39);
    cpy_r_r43 = cpy_r_r42 >= 0;
    if (unlikely(!cpy_r_r43)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 29, CPyStatic_from_type_str___globals);
        goto CPyL30;
    }
    cpy_r_r44 = CPyStatic_from_type_str___globals;
    cpy_r_r45 = CPyStatics[32]; /* 'Callable' */
    cpy_r_r46 = CPyDict_GetItem(cpy_r_r44, cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 30, CPyStatic_from_type_str___globals);
        goto CPyL30;
    }
    cpy_r_r47 = CPyStatics[84]; /* 'BaseCoder' */
    cpy_r_r48 = CPyStatic_from_type_str___globals;
    cpy_r_r49 = CPyStatics[81]; /* 'ABIType' */
    cpy_r_r50 = CPyDict_GetItem(cpy_r_r48, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 30, CPyStatic_from_type_str___globals);
        goto CPyL32;
    }
    cpy_r_r51 = CPyStatic_from_type_str___globals;
    cpy_r_r52 = CPyStatics[13]; /* 'Any' */
    cpy_r_r53 = CPyDict_GetItem(cpy_r_r51, cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 30, CPyStatic_from_type_str___globals);
        goto CPyL33;
    }
    cpy_r_r54 = PyList_New(3);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 30, CPyStatic_from_type_str___globals);
        goto CPyL34;
    }
    cpy_r_r55 = (CPyPtr)&((PyListObject *)cpy_r_r54)->ob_item;
    cpy_r_r56 = *(CPyPtr *)cpy_r_r55;
    CPy_INCREF(cpy_r_r47);
    *(PyObject * *)cpy_r_r56 = cpy_r_r47;
    cpy_r_r57 = cpy_r_r56 + 8;
    *(PyObject * *)cpy_r_r57 = cpy_r_r50;
    cpy_r_r58 = cpy_r_r56 + 16;
    *(PyObject * *)cpy_r_r58 = cpy_r_r53;
    cpy_r_r59 = CPyStatic_from_type_str___globals;
    cpy_r_r60 = CPyStatics[83]; /* 'TType' */
    cpy_r_r61 = CPyDict_GetItem(cpy_r_r59, cpy_r_r60);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 30, CPyStatic_from_type_str___globals);
        goto CPyL35;
    }
    cpy_r_r62.f0 = cpy_r_r54;
    cpy_r_r62.f1 = cpy_r_r61;
    cpy_r_r63 = PyTuple_New(2);
    if (unlikely(cpy_r_r63 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp5 = cpy_r_r62.f0;
    PyTuple_SET_ITEM(cpy_r_r63, 0, __tmp5);
    PyObject *__tmp6 = cpy_r_r62.f1;
    PyTuple_SET_ITEM(cpy_r_r63, 1, __tmp6);
    cpy_r_r64 = PyObject_GetItem(cpy_r_r46, cpy_r_r63);
    CPy_DECREF(cpy_r_r46);
    CPy_DECREF(cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 30, CPyStatic_from_type_str___globals);
        goto CPyL30;
    }
    cpy_r_r65 = CPyStatic_from_type_str___globals;
    cpy_r_r66 = CPyStatics[86]; /* 'OldFromTypeStr' */
    cpy_r_r67 = CPyDict_SetItem(cpy_r_r65, cpy_r_r66, cpy_r_r64);
    CPy_DECREF(cpy_r_r64);
    cpy_r_r68 = cpy_r_r67 >= 0;
    if (unlikely(!cpy_r_r68)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 30, CPyStatic_from_type_str___globals);
        goto CPyL30;
    }
    if (!0) goto CPyL29;
    cpy_r_r69 = CPyModule_builtins;
    cpy_r_r70 = CPyStatics[74]; /* 'classmethod' */
    cpy_r_r71 = CPyObject_GetAttr(cpy_r_r69, cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 32, CPyStatic_from_type_str___globals);
        goto CPyL30;
    }
    cpy_r_r72 = CPyStatic_from_type_str___globals;
    cpy_r_r73 = CPyStatics[83]; /* 'TType' */
    cpy_r_r74 = CPyDict_GetItem(cpy_r_r72, cpy_r_r73);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 32, CPyStatic_from_type_str___globals);
        goto CPyL36;
    }
    cpy_r_r75 = CPyStatic_from_type_str___globals;
    cpy_r_r76 = CPyStatics[19]; /* 'TypeStr' */
    cpy_r_r77 = CPyDict_GetItem(cpy_r_r75, cpy_r_r76);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 32, CPyStatic_from_type_str___globals);
        goto CPyL37;
    }
    cpy_r_r78 = CPyStatic_from_type_str___globals;
    cpy_r_r79 = CPyStatics[13]; /* 'Any' */
    cpy_r_r80 = CPyDict_GetItem(cpy_r_r78, cpy_r_r79);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 32, CPyStatic_from_type_str___globals);
        goto CPyL38;
    }
    cpy_r_r81 = PyList_New(2);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 32, CPyStatic_from_type_str___globals);
        goto CPyL39;
    }
    cpy_r_r82 = (CPyPtr)&((PyListObject *)cpy_r_r81)->ob_item;
    cpy_r_r83 = *(CPyPtr *)cpy_r_r82;
    *(PyObject * *)cpy_r_r83 = cpy_r_r77;
    cpy_r_r84 = cpy_r_r83 + 8;
    *(PyObject * *)cpy_r_r84 = cpy_r_r80;
    cpy_r_r85 = CPyStatic_from_type_str___globals;
    cpy_r_r86 = CPyStatics[83]; /* 'TType' */
    cpy_r_r87 = CPyDict_GetItem(cpy_r_r85, cpy_r_r86);
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 32, CPyStatic_from_type_str___globals);
        goto CPyL40;
    }
    cpy_r_r88.f0 = cpy_r_r74;
    cpy_r_r88.f1 = cpy_r_r81;
    cpy_r_r88.f2 = cpy_r_r87;
    cpy_r_r89 = PyTuple_New(3);
    if (unlikely(cpy_r_r89 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp7 = cpy_r_r88.f0;
    PyTuple_SET_ITEM(cpy_r_r89, 0, __tmp7);
    PyObject *__tmp8 = cpy_r_r88.f1;
    PyTuple_SET_ITEM(cpy_r_r89, 1, __tmp8);
    PyObject *__tmp9 = cpy_r_r88.f2;
    PyTuple_SET_ITEM(cpy_r_r89, 2, __tmp9);
    cpy_r_r90 = PyObject_GetItem(cpy_r_r71, cpy_r_r89);
    CPy_DECREF(cpy_r_r71);
    CPy_DECREF(cpy_r_r89);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 32, CPyStatic_from_type_str___globals);
        goto CPyL30;
    }
    cpy_r_r91 = CPyStatic_from_type_str___globals;
    cpy_r_r92 = CPyStatics[87]; /* 'NewFromTypeStr' */
    cpy_r_r93 = CPyDict_SetItem(cpy_r_r91, cpy_r_r92, cpy_r_r90);
    CPy_DECREF(cpy_r_r90);
    cpy_r_r94 = cpy_r_r93 >= 0;
    if (unlikely(!cpy_r_r94)) {
        CPy_AddTraceback("faster_eth_abi/from_type_str.py", "<module>", 32, CPyStatic_from_type_str___globals);
        goto CPyL30;
    }
CPyL29: ;
    return 1;
CPyL30: ;
    cpy_r_r95 = 2;
    return cpy_r_r95;
CPyL31: ;
    CPy_DecRef(cpy_r_r32);
    goto CPyL30;
CPyL32: ;
    CPy_DecRef(cpy_r_r46);
    goto CPyL30;
CPyL33: ;
    CPy_DecRef(cpy_r_r46);
    CPy_DecRef(cpy_r_r50);
    goto CPyL30;
CPyL34: ;
    CPy_DecRef(cpy_r_r46);
    CPy_DecRef(cpy_r_r50);
    CPy_DecRef(cpy_r_r53);
    goto CPyL30;
CPyL35: ;
    CPy_DecRef(cpy_r_r46);
    CPy_DecRef(cpy_r_r54);
    goto CPyL30;
CPyL36: ;
    CPy_DecRef(cpy_r_r71);
    goto CPyL30;
CPyL37: ;
    CPy_DecRef(cpy_r_r71);
    CPy_DecRef(cpy_r_r74);
    goto CPyL30;
CPyL38: ;
    CPy_DecRef(cpy_r_r71);
    CPy_DecRef(cpy_r_r74);
    CPy_DecRef(cpy_r_r77);
    goto CPyL30;
CPyL39: ;
    CPy_DecRef(cpy_r_r71);
    CPy_DecRef(cpy_r_r74);
    CPy_DecRef(cpy_r_r77);
    CPy_DecRef(cpy_r_r80);
    goto CPyL30;
CPyL40: ;
    CPy_DecRef(cpy_r_r71);
    CPy_DecRef(cpy_r_r74);
    CPy_DecRef(cpy_r_r81);
    goto CPyL30;
}
static int packed_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_faster_eth_abi___packed_internal, "__name__");
    CPyStatic_packed___globals = PyModule_GetDict(CPyModule_faster_eth_abi___packed_internal);
    if (unlikely(CPyStatic_packed___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_packed_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_faster_eth_abi___packed_internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic_packed___default_encoder_packed);
    CPyStatic_packed___default_encoder_packed = NULL;
    CPy_XDECREF(CPyStatic_packed___encode_packed);
    CPyStatic_packed___encode_packed = NULL;
    CPy_XDECREF(CPyStatic_packed___is_encodable_packed);
    CPyStatic_packed___is_encodable_packed = NULL;
    return -1;
}
static PyMethodDef packedmodule_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef packedmodule = {
    PyModuleDef_HEAD_INIT,
    "faster_eth_abi.packed",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    packedmodule_methods,
    NULL,
};

PyObject *CPyInit_faster_eth_abi___packed(void)
{
    if (CPyModule_faster_eth_abi___packed_internal) {
        Py_INCREF(CPyModule_faster_eth_abi___packed_internal);
        return CPyModule_faster_eth_abi___packed_internal;
    }
    CPyModule_faster_eth_abi___packed_internal = PyModule_Create(&packedmodule);
    if (unlikely(CPyModule_faster_eth_abi___packed_internal == NULL))
        goto fail;
    if (packed_exec(CPyModule_faster_eth_abi___packed_internal) != 0)
        goto fail;
    return CPyModule_faster_eth_abi___packed_internal;
    fail:
    return NULL;
}

char CPyDef_packed_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject **cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    int32_t cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    char cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    int32_t cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    char cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    int32_t cpy_r_r44;
    char cpy_r_r45;
    char cpy_r_r46;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[11]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/packed.py", "<module>", -1, CPyStatic_packed___globals);
        goto CPyL21;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[209]; /* ('Final',) */
    cpy_r_r6 = CPyStatics[17]; /* 'typing' */
    cpy_r_r7 = CPyStatic_packed___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/packed.py", "<module>", 1, CPyStatic_packed___globals);
        goto CPyL21;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[218]; /* ('ABIEncoder',) */
    cpy_r_r10 = CPyStatics[40]; /* 'faster_eth_abi.codec' */
    cpy_r_r11 = CPyStatic_packed___globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/packed.py", "<module>", 5, CPyStatic_packed___globals);
        goto CPyL21;
    }
    CPyModule_faster_eth_abi___codec = cpy_r_r12;
    CPy_INCREF(CPyModule_faster_eth_abi___codec);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[219]; /* ('registry_packed',) */
    cpy_r_r14 = CPyStatics[42]; /* 'faster_eth_abi.registry' */
    cpy_r_r15 = CPyStatic_packed___globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/packed.py", "<module>", 8, CPyStatic_packed___globals);
        goto CPyL21;
    }
    CPyModule_faster_eth_abi___registry = cpy_r_r16;
    CPy_INCREF(CPyModule_faster_eth_abi___registry);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r17 = CPyStatic_packed___globals;
    cpy_r_r18 = CPyStatics[89]; /* 'registry_packed' */
    cpy_r_r19 = CPyDict_GetItem(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/packed.py", "<module>", 12, CPyStatic_packed___globals);
        goto CPyL21;
    }
    cpy_r_r20 = CPyStatic_packed___globals;
    cpy_r_r21 = CPyStatics[88]; /* 'ABIEncoder' */
    cpy_r_r22 = CPyDict_GetItem(cpy_r_r20, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/packed.py", "<module>", 12, CPyStatic_packed___globals);
        goto CPyL22;
    }
    PyObject *cpy_r_r23[1] = {cpy_r_r19};
    cpy_r_r24 = (PyObject **)&cpy_r_r23;
    cpy_r_r25 = PyObject_Vectorcall(cpy_r_r22, cpy_r_r24, 1, 0);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/packed.py", "<module>", 12, CPyStatic_packed___globals);
        goto CPyL22;
    }
    CPy_DECREF(cpy_r_r19);
    CPyStatic_packed___default_encoder_packed = cpy_r_r25;
    CPy_INCREF(CPyStatic_packed___default_encoder_packed);
    cpy_r_r26 = CPyStatic_packed___globals;
    cpy_r_r27 = CPyStatics[90]; /* 'default_encoder_packed' */
    cpy_r_r28 = CPyDict_SetItem(cpy_r_r26, cpy_r_r27, cpy_r_r25);
    CPy_DECREF(cpy_r_r25);
    cpy_r_r29 = cpy_r_r28 >= 0;
    if (unlikely(!cpy_r_r29)) {
        CPy_AddTraceback("faster_eth_abi/packed.py", "<module>", 12, CPyStatic_packed___globals);
        goto CPyL21;
    }
    cpy_r_r30 = CPyStatic_packed___default_encoder_packed;
    if (likely(cpy_r_r30 != NULL)) goto CPyL13;
    PyErr_SetString(PyExc_NameError, "value for final name \"default_encoder_packed\" was not set");
    cpy_r_r31 = 0;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("faster_eth_abi/packed.py", "<module>", 14, CPyStatic_packed___globals);
        goto CPyL21;
    }
    CPy_Unreachable();
CPyL13: ;
    cpy_r_r32 = CPyStatics[44]; /* 'encode' */
    cpy_r_r33 = CPyObject_GetAttr(cpy_r_r30, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/packed.py", "<module>", 14, CPyStatic_packed___globals);
        goto CPyL21;
    }
    CPyStatic_packed___encode_packed = cpy_r_r33;
    CPy_INCREF(CPyStatic_packed___encode_packed);
    cpy_r_r34 = CPyStatic_packed___globals;
    cpy_r_r35 = CPyStatics[91]; /* 'encode_packed' */
    cpy_r_r36 = CPyDict_SetItem(cpy_r_r34, cpy_r_r35, cpy_r_r33);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r37 = cpy_r_r36 >= 0;
    if (unlikely(!cpy_r_r37)) {
        CPy_AddTraceback("faster_eth_abi/packed.py", "<module>", 14, CPyStatic_packed___globals);
        goto CPyL21;
    }
    cpy_r_r38 = CPyStatic_packed___default_encoder_packed;
    if (likely(cpy_r_r38 != NULL)) goto CPyL18;
    PyErr_SetString(PyExc_NameError, "value for final name \"default_encoder_packed\" was not set");
    cpy_r_r39 = 0;
    if (unlikely(!cpy_r_r39)) {
        CPy_AddTraceback("faster_eth_abi/packed.py", "<module>", 15, CPyStatic_packed___globals);
        goto CPyL21;
    }
    CPy_Unreachable();
CPyL18: ;
    cpy_r_r40 = CPyStatics[46]; /* 'is_encodable' */
    cpy_r_r41 = CPyObject_GetAttr(cpy_r_r38, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/packed.py", "<module>", 15, CPyStatic_packed___globals);
        goto CPyL21;
    }
    CPyStatic_packed___is_encodable_packed = cpy_r_r41;
    CPy_INCREF(CPyStatic_packed___is_encodable_packed);
    cpy_r_r42 = CPyStatic_packed___globals;
    cpy_r_r43 = CPyStatics[92]; /* 'is_encodable_packed' */
    cpy_r_r44 = CPyDict_SetItem(cpy_r_r42, cpy_r_r43, cpy_r_r41);
    CPy_DECREF(cpy_r_r41);
    cpy_r_r45 = cpy_r_r44 >= 0;
    if (unlikely(!cpy_r_r45)) {
        CPy_AddTraceback("faster_eth_abi/packed.py", "<module>", 15, CPyStatic_packed___globals);
        goto CPyL21;
    }
    return 1;
CPyL21: ;
    cpy_r_r46 = 2;
    return cpy_r_r46;
CPyL22: ;
    CPy_DecRef(cpy_r_r19);
    goto CPyL21;
}
static int tools_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_faster_eth_abi___tools_internal, "__name__");
    CPyStatic_tools___globals = PyModule_GetDict(CPyModule_faster_eth_abi___tools_internal);
    if (unlikely(CPyStatic_tools___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_tools_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_faster_eth_abi___tools_internal);
    Py_CLEAR(modname);
    return -1;
}
static PyMethodDef toolsmodule_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef toolsmodule = {
    PyModuleDef_HEAD_INIT,
    "faster_eth_abi.tools",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    toolsmodule_methods,
    NULL,
};

PyObject *CPyInit_faster_eth_abi___tools(void)
{
    if (CPyModule_faster_eth_abi___tools_internal) {
        Py_INCREF(CPyModule_faster_eth_abi___tools_internal);
        return CPyModule_faster_eth_abi___tools_internal;
    }
    CPyModule_faster_eth_abi___tools_internal = PyModule_Create(&toolsmodule);
    if (unlikely(CPyModule_faster_eth_abi___tools_internal == NULL))
        goto fail;
    if (tools_exec(CPyModule_faster_eth_abi___tools_internal) != 0)
        goto fail;
    return CPyModule_faster_eth_abi___tools_internal;
    fail:
    return NULL;
}

char CPyDef_tools_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[11]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/__init__.py", "<module>", -1, CPyStatic_tools___globals);
        goto CPyL5;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[220]; /* ('get_abi_strategy',) */
    cpy_r_r6 = CPyStatics[94]; /* 'faster_eth_abi.tools._strategies' */
    cpy_r_r7 = CPyStatic_tools___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/__init__.py", "<module>", 1, CPyStatic_tools___globals);
        goto CPyL5;
    }
    CPyModule_faster_eth_abi___tools____strategies = cpy_r_r8;
    CPy_INCREF(CPyModule_faster_eth_abi___tools____strategies);
    CPy_DECREF(cpy_r_r8);
    return 1;
CPyL5: ;
    cpy_r_r9 = 2;
    return cpy_r_r9;
}

static int
_strategies___StrategyRegistry_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
static PyObject *_strategies___StrategyRegistry_setup(PyTypeObject *type);
PyObject *CPyDef__strategies___StrategyRegistry(void);

static PyObject *
_strategies___StrategyRegistry_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType__strategies___StrategyRegistry) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = _strategies___StrategyRegistry_setup(type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy__strategies___StrategyRegistry_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
_strategies___StrategyRegistry_traverse(faster_eth_abi___tools____strategies___StrategyRegistryObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->__strategies);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
_strategies___StrategyRegistry_clear(faster_eth_abi___tools____strategies___StrategyRegistryObject *self)
{
    Py_CLEAR(self->__strategies);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
_strategies___StrategyRegistry_dealloc(faster_eth_abi___tools____strategies___StrategyRegistryObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, _strategies___StrategyRegistry_dealloc)
    _strategies___StrategyRegistry_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem _strategies___StrategyRegistry_vtable[4];
static bool
CPyDef__strategies___StrategyRegistry_trait_vtable_setup(void)
{
    CPyVTableItem _strategies___StrategyRegistry_vtable_scratch[] = {
        (CPyVTableItem)CPyDef__strategies___StrategyRegistry_____init__,
        (CPyVTableItem)CPyDef__strategies___StrategyRegistry___register_strategy,
        (CPyVTableItem)CPyDef__strategies___StrategyRegistry___unregister_strategy,
        (CPyVTableItem)CPyDef__strategies___StrategyRegistry___get_strategy,
    };
    memcpy(_strategies___StrategyRegistry_vtable, _strategies___StrategyRegistry_vtable_scratch, sizeof(_strategies___StrategyRegistry_vtable));
    return 1;
}

static PyObject *
_strategies___StrategyRegistry_get__strategies(faster_eth_abi___tools____strategies___StrategyRegistryObject *self, void *closure);
static int
_strategies___StrategyRegistry_set__strategies(faster_eth_abi___tools____strategies___StrategyRegistryObject *self, PyObject *value, void *closure);

static PyGetSetDef _strategies___StrategyRegistry_getseters[] = {
    {"_strategies",
     (getter)_strategies___StrategyRegistry_get__strategies, (setter)_strategies___StrategyRegistry_set__strategies,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef _strategies___StrategyRegistry_methods[] = {
    {"__init__",
     (PyCFunction)CPyPy__strategies___StrategyRegistry_____init__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"register_strategy",
     (PyCFunction)CPyPy__strategies___StrategyRegistry___register_strategy,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"unregister_strategy",
     (PyCFunction)CPyPy__strategies___StrategyRegistry___unregister_strategy,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"get_strategy",
     (PyCFunction)CPyPy__strategies___StrategyRegistry___get_strategy,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType__strategies___StrategyRegistry_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "StrategyRegistry",
    .tp_new = _strategies___StrategyRegistry_new,
    .tp_dealloc = (destructor)_strategies___StrategyRegistry_dealloc,
    .tp_traverse = (traverseproc)_strategies___StrategyRegistry_traverse,
    .tp_clear = (inquiry)_strategies___StrategyRegistry_clear,
    .tp_getset = _strategies___StrategyRegistry_getseters,
    .tp_methods = _strategies___StrategyRegistry_methods,
    .tp_init = _strategies___StrategyRegistry_init,
    .tp_basicsize = sizeof(faster_eth_abi___tools____strategies___StrategyRegistryObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType__strategies___StrategyRegistry_template = &CPyType__strategies___StrategyRegistry_template_;

static PyObject *
_strategies___StrategyRegistry_setup(PyTypeObject *type)
{
    faster_eth_abi___tools____strategies___StrategyRegistryObject *self;
    self = (faster_eth_abi___tools____strategies___StrategyRegistryObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = _strategies___StrategyRegistry_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef__strategies___StrategyRegistry(void)
{
    PyObject *self = _strategies___StrategyRegistry_setup(CPyType__strategies___StrategyRegistry);
    if (self == NULL)
        return NULL;
    char res = CPyDef__strategies___StrategyRegistry_____init__(self);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
_strategies___StrategyRegistry_get__strategies(faster_eth_abi___tools____strategies___StrategyRegistryObject *self, void *closure)
{
    if (unlikely(self->__strategies == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '_strategies' of 'StrategyRegistry' undefined");
        return NULL;
    }
    CPy_INCREF(self->__strategies);
    PyObject *retval = self->__strategies;
    return retval;
}

static int
_strategies___StrategyRegistry_set__strategies(faster_eth_abi___tools____strategies___StrategyRegistryObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'StrategyRegistry' object attribute '_strategies' cannot be deleted");
        return -1;
    }
    if (self->__strategies != NULL) {
        CPy_DECREF(self->__strategies);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->__strategies = tmp;
    return 0;
}
static int _strategies_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_faster_eth_abi___tools____strategies_internal, "__name__");
    CPyStatic__strategies___globals = PyModule_GetDict(CPyModule_faster_eth_abi___tools____strategies_internal);
    if (unlikely(CPyStatic__strategies___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef__strategies_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_faster_eth_abi___tools____strategies_internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic__strategies___address_strategy);
    CPyStatic__strategies___address_strategy = NULL;
    CPy_XDECREF(CPyStatic__strategies___bool_strategy);
    CPyStatic__strategies___bool_strategy = NULL;
    CPy_XDECREF(CPyStatic__strategies___bytes_strategy);
    CPyStatic__strategies___bytes_strategy = NULL;
    CPy_XDECREF(CPyStatic__strategies___string_strategy);
    CPyStatic__strategies___string_strategy = NULL;
    CPy_XDECREF_NO_IMM(CPyStatic__strategies___strategy_registry);
    CPyStatic__strategies___strategy_registry = NULL;
    CPy_XDECREF(CPyStatic__strategies___get_abi_strategy);
    CPyStatic__strategies___get_abi_strategy = NULL;
    Py_CLEAR(CPyType__strategies___StrategyRegistry);
    return -1;
}
static PyMethodDef _strategiesmodule_methods[] = {
    {"get_uint_strategy", (PyCFunction)CPyPy__strategies___get_uint_strategy, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"get_int_strategy", (PyCFunction)CPyPy__strategies___get_int_strategy, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"get_ufixed_strategy", (PyCFunction)CPyPy__strategies___get_ufixed_strategy, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"get_fixed_strategy", (PyCFunction)CPyPy__strategies___get_fixed_strategy, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"get_bytes_strategy", (PyCFunction)CPyPy__strategies___get_bytes_strategy, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"get_array_strategy", (PyCFunction)CPyPy__strategies___get_array_strategy, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"get_tuple_strategy", (PyCFunction)CPyPy__strategies___get_tuple_strategy, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef _strategiesmodule = {
    PyModuleDef_HEAD_INIT,
    "faster_eth_abi.tools._strategies",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    _strategiesmodule_methods,
    NULL,
};

PyObject *CPyInit_faster_eth_abi___tools____strategies(void)
{
    if (CPyModule_faster_eth_abi___tools____strategies_internal) {
        Py_INCREF(CPyModule_faster_eth_abi___tools____strategies_internal);
        return CPyModule_faster_eth_abi___tools____strategies_internal;
    }
    CPyModule_faster_eth_abi___tools____strategies_internal = PyModule_Create(&_strategiesmodule);
    if (unlikely(CPyModule_faster_eth_abi___tools____strategies_internal == NULL))
        goto fail;
    if (_strategies_exec(CPyModule_faster_eth_abi___tools____strategies_internal) != 0)
        goto fail;
    return CPyModule_faster_eth_abi___tools____strategies_internal;
    fail:
    return NULL;
}

char CPyDef__strategies___StrategyRegistry_____init__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    cpy_r_r0 = CPyStatics[95]; /* 'strategy registry' */
    cpy_r_r1 = CPyStatic__strategies___globals;
    cpy_r_r2 = CPyStatics[96]; /* 'PredicateMapping' */
    cpy_r_r3 = CPyDict_GetItem(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "__init__", 43, CPyStatic__strategies___globals);
        goto CPyL4;
    }
    PyObject *cpy_r_r4[1] = {cpy_r_r0};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = PyObject_Vectorcall(cpy_r_r3, cpy_r_r5, 1, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "__init__", 43, CPyStatic__strategies___globals);
        goto CPyL4;
    }
    if (((faster_eth_abi___tools____strategies___StrategyRegistryObject *)cpy_r_self)->__strategies != NULL) {
        CPy_DECREF(((faster_eth_abi___tools____strategies___StrategyRegistryObject *)cpy_r_self)->__strategies);
    }
    ((faster_eth_abi___tools____strategies___StrategyRegistryObject *)cpy_r_self)->__strategies = cpy_r_r6;
    cpy_r_r7 = 1;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "__init__", 43, CPyStatic__strategies___globals);
        goto CPyL4;
    }
    return 1;
CPyL4: ;
    cpy_r_r8 = 2;
    return cpy_r_r8;
}

PyObject *CPyPy__strategies___StrategyRegistry_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "", "__init__", kwlist)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__strategies___StrategyRegistry))
        arg_self = obj_self;
    else {
        CPy_TypeError("faster_eth_abi.tools._strategies.StrategyRegistry", obj_self); 
        goto fail;
    }
    char retval = CPyDef__strategies___StrategyRegistry_____init__(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "__init__", 42, CPyStatic__strategies___globals);
    return NULL;
}

char CPyDef__strategies___StrategyRegistry___register_strategy(PyObject *cpy_r_self, PyObject *cpy_r_lookup, PyObject *cpy_r_registration, PyObject *cpy_r_label) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    char cpy_r_r7;
    if (cpy_r_label != NULL) goto CPyL6;
    cpy_r_r0 = Py_None;
    cpy_r_label = cpy_r_r0;
CPyL2: ;
    cpy_r_r1 = ((faster_eth_abi___tools____strategies___StrategyRegistryObject *)cpy_r_self)->__strategies;
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AttributeError("faster_eth_abi/tools/_strategies.py", "register_strategy", "StrategyRegistry", "_strategies", 51, CPyStatic__strategies___globals);
        goto CPyL7;
    }
    CPy_INCREF(cpy_r_r1);
CPyL3: ;
    cpy_r_r2 = CPyStatics[97]; /* '_register' */
    PyObject *cpy_r_r3[5] = {
        cpy_r_self, cpy_r_r1, cpy_r_lookup, cpy_r_registration,
        cpy_r_label
    };
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = CPyStatics[221]; /* ('label',) */
    cpy_r_r6 = PyObject_VectorcallMethod(cpy_r_r2, cpy_r_r4, 9223372036854775812ULL, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "register_strategy", 51, CPyStatic__strategies___globals);
        goto CPyL8;
    } else
        goto CPyL9;
CPyL4: ;
    CPy_DECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_label);
    return 1;
CPyL5: ;
    cpy_r_r7 = 2;
    return cpy_r_r7;
CPyL6: ;
    CPy_INCREF(cpy_r_label);
    goto CPyL2;
CPyL7: ;
    CPy_DecRef(cpy_r_label);
    goto CPyL5;
CPyL8: ;
    CPy_DecRef(cpy_r_label);
    CPy_DecRef(cpy_r_r1);
    goto CPyL5;
CPyL9: ;
    CPy_DECREF(cpy_r_r6);
    goto CPyL4;
}

PyObject *CPyPy__strategies___StrategyRegistry___register_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"lookup", "registration", "label", 0};
    static CPyArg_Parser parser = {"OO|O:register_strategy", kwlist, 0};
    PyObject *obj_lookup;
    PyObject *obj_registration;
    PyObject *obj_label = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_lookup, &obj_registration, &obj_label)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__strategies___StrategyRegistry))
        arg_self = obj_self;
    else {
        CPy_TypeError("faster_eth_abi.tools._strategies.StrategyRegistry", obj_self); 
        goto fail;
    }
    PyObject *arg_lookup;
    if (PyUnicode_Check(obj_lookup))
        arg_lookup = obj_lookup;
    else {
        arg_lookup = NULL;
    }
    if (arg_lookup != NULL) goto __LL10;
    arg_lookup = obj_lookup;
    if (arg_lookup != NULL) goto __LL10;
    CPy_TypeError("union[str, object]", obj_lookup); 
    goto fail;
__LL10: ;
    PyObject *arg_registration = obj_registration;
    PyObject *arg_label;
    if (obj_label == NULL) {
        arg_label = NULL;
        goto __LL11;
    }
    if (PyUnicode_Check(obj_label))
        arg_label = obj_label;
    else {
        arg_label = NULL;
    }
    if (arg_label != NULL) goto __LL11;
    if (obj_label == Py_None)
        arg_label = obj_label;
    else {
        arg_label = NULL;
    }
    if (arg_label != NULL) goto __LL11;
    CPy_TypeError("str or None", obj_label); 
    goto fail;
__LL11: ;
    char retval = CPyDef__strategies___StrategyRegistry___register_strategy(arg_self, arg_lookup, arg_registration, arg_label);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "register_strategy", 45, CPyStatic__strategies___globals);
    return NULL;
}

char CPyDef__strategies___StrategyRegistry___unregister_strategy(PyObject *cpy_r_self, PyObject *cpy_r_lookup_or_label) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject **cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    cpy_r_r0 = ((faster_eth_abi___tools____strategies___StrategyRegistryObject *)cpy_r_self)->__strategies;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("faster_eth_abi/tools/_strategies.py", "unregister_strategy", "StrategyRegistry", "_strategies", 54, CPyStatic__strategies___globals);
        goto CPyL3;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyStatics[99]; /* '_unregister' */
    PyObject *cpy_r_r2[3] = {cpy_r_self, cpy_r_r0, cpy_r_lookup_or_label};
    cpy_r_r3 = (PyObject **)&cpy_r_r2;
    cpy_r_r4 = PyObject_VectorcallMethod(cpy_r_r1, cpy_r_r3, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "unregister_strategy", 54, CPyStatic__strategies___globals);
        goto CPyL4;
    } else
        goto CPyL5;
CPyL2: ;
    CPy_DECREF(cpy_r_r0);
    return 1;
CPyL3: ;
    cpy_r_r5 = 2;
    return cpy_r_r5;
CPyL4: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL3;
CPyL5: ;
    CPy_DECREF(cpy_r_r4);
    goto CPyL2;
}

PyObject *CPyPy__strategies___StrategyRegistry___unregister_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"lookup_or_label", 0};
    static CPyArg_Parser parser = {"O:unregister_strategy", kwlist, 0};
    PyObject *obj_lookup_or_label;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_lookup_or_label)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__strategies___StrategyRegistry))
        arg_self = obj_self;
    else {
        CPy_TypeError("faster_eth_abi.tools._strategies.StrategyRegistry", obj_self); 
        goto fail;
    }
    PyObject *arg_lookup_or_label;
    if (PyUnicode_Check(obj_lookup_or_label))
        arg_lookup_or_label = obj_lookup_or_label;
    else {
        arg_lookup_or_label = NULL;
    }
    if (arg_lookup_or_label != NULL) goto __LL12;
    arg_lookup_or_label = obj_lookup_or_label;
    if (arg_lookup_or_label != NULL) goto __LL12;
    CPy_TypeError("union[str, object]", obj_lookup_or_label); 
    goto fail;
__LL12: ;
    char retval = CPyDef__strategies___StrategyRegistry___unregister_strategy(arg_self, arg_lookup_or_label);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "unregister_strategy", 53, CPyStatic__strategies___globals);
    return NULL;
}

PyObject *CPyDef__strategies___StrategyRegistry___get_strategy(PyObject *cpy_r_self, PyObject *cpy_r_type_str) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject **cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    int32_t cpy_r_r10;
    char cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject **cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject **cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject **cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    cpy_r_r0 = ((faster_eth_abi___tools____strategies___StrategyRegistryObject *)cpy_r_self)->__strategies;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("faster_eth_abi/tools/_strategies.py", "get_strategy", "StrategyRegistry", "_strategies", 66, CPyStatic__strategies___globals);
        goto CPyL14;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyStatics[100]; /* '_get_registration' */
    PyObject *cpy_r_r2[3] = {cpy_r_self, cpy_r_r0, cpy_r_type_str};
    cpy_r_r3 = (PyObject **)&cpy_r_r2;
    cpy_r_r4 = PyObject_VectorcallMethod(cpy_r_r1, cpy_r_r3, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_strategy", 66, CPyStatic__strategies___globals);
        goto CPyL15;
    }
    CPy_DECREF(cpy_r_r0);
    cpy_r_r5 = CPyStatic__strategies___globals;
    cpy_r_r6 = CPyStatics[101]; /* 'st' */
    cpy_r_r7 = CPyDict_GetItem(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_strategy", 68, CPyStatic__strategies___globals);
        goto CPyL16;
    }
    cpy_r_r8 = CPyStatics[102]; /* 'SearchStrategy' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_strategy", 68, CPyStatic__strategies___globals);
        goto CPyL16;
    }
    cpy_r_r10 = PyObject_IsInstance(cpy_r_r4, cpy_r_r9);
    CPy_DECREF(cpy_r_r9);
    cpy_r_r11 = cpy_r_r10 >= 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_strategy", 68, CPyStatic__strategies___globals);
        goto CPyL16;
    }
    cpy_r_r12 = cpy_r_r10;
    if (!cpy_r_r12) goto CPyL7;
    return cpy_r_r4;
CPyL7: ;
    cpy_r_r13 = CPyStatic__strategies___globals;
    cpy_r_r14 = CPyStatics[51]; /* 'normalize' */
    cpy_r_r15 = CPyDict_GetItem(cpy_r_r13, cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_strategy", 74, CPyStatic__strategies___globals);
        goto CPyL16;
    }
    PyObject *cpy_r_r16[1] = {cpy_r_type_str};
    cpy_r_r17 = (PyObject **)&cpy_r_r16;
    cpy_r_r18 = PyObject_Vectorcall(cpy_r_r15, cpy_r_r17, 1, 0);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_strategy", 74, CPyStatic__strategies___globals);
        goto CPyL16;
    }
    if (likely(PyUnicode_Check(cpy_r_r18)))
        cpy_r_r19 = cpy_r_r18;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/tools/_strategies.py", "get_strategy", 74, CPyStatic__strategies___globals, "str", cpy_r_r18);
        goto CPyL16;
    }
    cpy_r_r20 = CPyStatic__strategies___globals;
    cpy_r_r21 = CPyStatics[52]; /* 'parse' */
    cpy_r_r22 = CPyDict_GetItem(cpy_r_r20, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_strategy", 75, CPyStatic__strategies___globals);
        goto CPyL17;
    }
    PyObject *cpy_r_r23[1] = {cpy_r_r19};
    cpy_r_r24 = (PyObject **)&cpy_r_r23;
    cpy_r_r25 = PyObject_Vectorcall(cpy_r_r22, cpy_r_r24, 1, 0);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_strategy", 75, CPyStatic__strategies___globals);
        goto CPyL17;
    }
    CPy_DECREF(cpy_r_r19);
    PyObject *cpy_r_r26[2] = {cpy_r_r25, cpy_r_self};
    cpy_r_r27 = (PyObject **)&cpy_r_r26;
    cpy_r_r28 = PyObject_Vectorcall(cpy_r_r4, cpy_r_r27, 2, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_strategy", 76, CPyStatic__strategies___globals);
        goto CPyL18;
    }
    CPy_DECREF(cpy_r_r25);
    return cpy_r_r28;
CPyL14: ;
    cpy_r_r29 = NULL;
    return cpy_r_r29;
CPyL15: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL14;
CPyL16: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL14;
CPyL17: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r19);
    goto CPyL14;
CPyL18: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL14;
}

PyObject *CPyPy__strategies___StrategyRegistry___get_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"type_str", 0};
    static CPyArg_Parser parser = {"O:get_strategy", kwlist, 0};
    PyObject *obj_type_str;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_type_str)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType__strategies___StrategyRegistry))
        arg_self = obj_self;
    else {
        CPy_TypeError("faster_eth_abi.tools._strategies.StrategyRegistry", obj_self); 
        goto fail;
    }
    PyObject *arg_type_str;
    if (likely(PyUnicode_Check(obj_type_str)))
        arg_type_str = obj_type_str;
    else {
        CPy_TypeError("str", obj_type_str); 
        goto fail;
    }
    PyObject *retval = CPyDef__strategies___StrategyRegistry___get_strategy(arg_self, arg_type_str);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_strategy", 56, CPyStatic__strategies___globals);
    return NULL;
}

PyObject *CPyDef__strategies___get_uint_strategy(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    cpy_r_r0 = CPyStatics[103]; /* 'sub' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_abi_type, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_uint_strategy", 84, CPyStatic__strategies___globals);
        goto CPyL6;
    }
    cpy_r_r2 = CPyStatic__strategies___globals;
    cpy_r_r3 = CPyStatics[101]; /* 'st' */
    cpy_r_r4 = CPyDict_GetItem(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_uint_strategy", 86, CPyStatic__strategies___globals);
        goto CPyL7;
    }
    cpy_r_r5 = CPyStatics[197]; /* 2 */
    cpy_r_r6 = CPyNumber_Power(cpy_r_r5, cpy_r_r1);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_uint_strategy", 88, CPyStatic__strategies___globals);
        goto CPyL8;
    }
    cpy_r_r7 = CPyStatics[198]; /* 1 */
    cpy_r_r8 = PyNumber_Subtract(cpy_r_r6, cpy_r_r7);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_uint_strategy", 88, CPyStatic__strategies___globals);
        goto CPyL8;
    }
    cpy_r_r9 = CPyStatics[104]; /* 'integers' */
    cpy_r_r10 = CPyStatics[192]; /* 0 */
    PyObject *cpy_r_r11[3] = {cpy_r_r4, cpy_r_r10, cpy_r_r8};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = CPyStatics[222]; /* ('min_value', 'max_value') */
    cpy_r_r14 = PyObject_VectorcallMethod(cpy_r_r9, cpy_r_r12, 9223372036854775809ULL, cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_uint_strategy", 86, CPyStatic__strategies___globals);
        goto CPyL9;
    }
    CPy_DECREF(cpy_r_r4);
    CPy_DECREF(cpy_r_r8);
    return cpy_r_r14;
CPyL6: ;
    cpy_r_r15 = NULL;
    return cpy_r_r15;
CPyL7: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL6;
CPyL8: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL6;
CPyL9: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r8);
    goto CPyL6;
}

PyObject *CPyPy__strategies___get_uint_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"abi_type", "registry", 0};
    static CPyArg_Parser parser = {"OO:get_uint_strategy", kwlist, 0};
    PyObject *obj_abi_type;
    PyObject *obj_registry;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_abi_type, &obj_registry)) {
        return NULL;
    }
    PyObject *arg_abi_type = obj_abi_type;
    PyObject *arg_registry;
    if (likely(Py_TYPE(obj_registry) == CPyType__strategies___StrategyRegistry))
        arg_registry = obj_registry;
    else {
        CPy_TypeError("faster_eth_abi.tools._strategies.StrategyRegistry", obj_registry); 
        goto fail;
    }
    PyObject *retval = CPyDef__strategies___get_uint_strategy(arg_abi_type, arg_registry);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_uint_strategy", 81, CPyStatic__strategies___globals);
    return NULL;
}

PyObject *CPyDef__strategies___get_int_strategy(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject **cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    cpy_r_r0 = CPyStatics[103]; /* 'sub' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_abi_type, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_int_strategy", 95, CPyStatic__strategies___globals);
        goto CPyL10;
    }
    cpy_r_r2 = CPyStatic__strategies___globals;
    cpy_r_r3 = CPyStatics[101]; /* 'st' */
    cpy_r_r4 = CPyDict_GetItem(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_int_strategy", 97, CPyStatic__strategies___globals);
        goto CPyL11;
    }
    cpy_r_r5 = CPyStatics[198]; /* 1 */
    cpy_r_r6 = PyNumber_Subtract(cpy_r_r1, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_int_strategy", 98, CPyStatic__strategies___globals);
        goto CPyL12;
    }
    cpy_r_r7 = CPyStatics[197]; /* 2 */
    cpy_r_r8 = CPyNumber_Power(cpy_r_r7, cpy_r_r6);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_int_strategy", 98, CPyStatic__strategies___globals);
        goto CPyL12;
    }
    cpy_r_r9 = PyNumber_Negative(cpy_r_r8);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_int_strategy", 98, CPyStatic__strategies___globals);
        goto CPyL12;
    }
    cpy_r_r10 = CPyStatics[198]; /* 1 */
    cpy_r_r11 = PyNumber_Subtract(cpy_r_r1, cpy_r_r10);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_int_strategy", 99, CPyStatic__strategies___globals);
        goto CPyL13;
    }
    cpy_r_r12 = CPyStatics[197]; /* 2 */
    cpy_r_r13 = CPyNumber_Power(cpy_r_r12, cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_int_strategy", 99, CPyStatic__strategies___globals);
        goto CPyL13;
    }
    cpy_r_r14 = CPyStatics[198]; /* 1 */
    cpy_r_r15 = PyNumber_Subtract(cpy_r_r13, cpy_r_r14);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_int_strategy", 99, CPyStatic__strategies___globals);
        goto CPyL13;
    }
    cpy_r_r16 = CPyStatics[104]; /* 'integers' */
    PyObject *cpy_r_r17[3] = {cpy_r_r4, cpy_r_r9, cpy_r_r15};
    cpy_r_r18 = (PyObject **)&cpy_r_r17;
    cpy_r_r19 = CPyStatics[222]; /* ('min_value', 'max_value') */
    cpy_r_r20 = PyObject_VectorcallMethod(cpy_r_r16, cpy_r_r18, 9223372036854775809ULL, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_int_strategy", 97, CPyStatic__strategies___globals);
        goto CPyL14;
    }
    CPy_DECREF(cpy_r_r4);
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r15);
    return cpy_r_r20;
CPyL10: ;
    cpy_r_r21 = NULL;
    return cpy_r_r21;
CPyL11: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL10;
CPyL12: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r4);
    goto CPyL10;
CPyL13: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r9);
    goto CPyL10;
CPyL14: ;
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r15);
    goto CPyL10;
}

PyObject *CPyPy__strategies___get_int_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"abi_type", "registry", 0};
    static CPyArg_Parser parser = {"OO:get_int_strategy", kwlist, 0};
    PyObject *obj_abi_type;
    PyObject *obj_registry;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_abi_type, &obj_registry)) {
        return NULL;
    }
    PyObject *arg_abi_type = obj_abi_type;
    PyObject *arg_registry;
    if (likely(Py_TYPE(obj_registry) == CPyType__strategies___StrategyRegistry))
        arg_registry = obj_registry;
    else {
        CPy_TypeError("faster_eth_abi.tools._strategies.StrategyRegistry", obj_registry); 
        goto fail;
    }
    PyObject *retval = CPyDef__strategies___get_int_strategy(arg_abi_type, arg_registry);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_int_strategy", 92, CPyStatic__strategies___globals);
    return NULL;
}

PyObject *CPyDef__strategies___get_ufixed_strategy(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject **cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    CPyTagged cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject **cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    cpy_r_r0 = CPyStatics[103]; /* 'sub' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_abi_type, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_ufixed_strategy", 110, CPyStatic__strategies___globals);
        goto CPyL19;
    }
    cpy_r_r2 = PyObject_GetIter(cpy_r_r1);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_ufixed_strategy", 110, CPyStatic__strategies___globals);
        goto CPyL19;
    }
    cpy_r_r3 = PyIter_Next(cpy_r_r2);
    if (cpy_r_r3 == NULL) {
        goto CPyL20;
    } else
        goto CPyL5;
CPyL3: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r4 = 0;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_ufixed_strategy", 110, CPyStatic__strategies___globals);
        goto CPyL19;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r5 = PyIter_Next(cpy_r_r2);
    if (cpy_r_r5 == NULL) {
        goto CPyL21;
    } else
        goto CPyL8;
CPyL6: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r6 = 0;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_ufixed_strategy", 110, CPyStatic__strategies___globals);
        goto CPyL19;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r7 = PyIter_Next(cpy_r_r2);
    CPy_DECREF(cpy_r_r2);
    if (cpy_r_r7 == NULL) {
        goto CPyL11;
    } else
        goto CPyL22;
CPyL9: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r8 = 0;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_ufixed_strategy", 110, CPyStatic__strategies___globals);
        goto CPyL19;
    }
    CPy_Unreachable();
CPyL11: ;
    cpy_r_r9 = CPyStatic__strategies___globals;
    cpy_r_r10 = CPyStatics[101]; /* 'st' */
    cpy_r_r11 = CPyDict_GetItem(cpy_r_r9, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_ufixed_strategy", 112, CPyStatic__strategies___globals);
        goto CPyL23;
    }
    cpy_r_r12 = CPyStatics[197]; /* 2 */
    cpy_r_r13 = CPyNumber_Power(cpy_r_r12, cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_ufixed_strategy", 114, CPyStatic__strategies___globals);
        goto CPyL24;
    }
    cpy_r_r14 = CPyStatics[198]; /* 1 */
    cpy_r_r15 = PyNumber_Subtract(cpy_r_r13, cpy_r_r14);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_ufixed_strategy", 114, CPyStatic__strategies___globals);
        goto CPyL24;
    }
    cpy_r_r16 = CPyStatics[107]; /* 'decimals' */
    cpy_r_r17 = CPyStatics[192]; /* 0 */
    cpy_r_r18 = CPyStatics[192]; /* 0 */
    PyObject *cpy_r_r19[4] = {cpy_r_r11, cpy_r_r17, cpy_r_r15, cpy_r_r18};
    cpy_r_r20 = (PyObject **)&cpy_r_r19;
    cpy_r_r21 = CPyStatics[223]; /* ('min_value', 'max_value', 'places') */
    cpy_r_r22 = PyObject_VectorcallMethod(cpy_r_r16, cpy_r_r20, 9223372036854775809ULL, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_ufixed_strategy", 112, CPyStatic__strategies___globals);
        goto CPyL25;
    }
    CPy_DECREF(cpy_r_r11);
    CPy_DECREF(cpy_r_r15);
    if (likely(PyLong_Check(cpy_r_r5)))
        cpy_r_r23 = CPyTagged_FromObject(cpy_r_r5);
    else {
        CPy_TypeError("int", cpy_r_r5); cpy_r_r23 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r23 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_ufixed_strategy", 116, CPyStatic__strategies___globals);
        goto CPyL26;
    }
    cpy_r_r24 = CPyDef_numeric___scale_places(cpy_r_r23);
    CPyTagged_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_ufixed_strategy", 116, CPyStatic__strategies___globals);
        goto CPyL26;
    }
    cpy_r_r25 = CPyStatics[109]; /* 'map' */
    PyObject *cpy_r_r26[2] = {cpy_r_r22, cpy_r_r24};
    cpy_r_r27 = (PyObject **)&cpy_r_r26;
    cpy_r_r28 = PyObject_VectorcallMethod(cpy_r_r25, cpy_r_r27, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_ufixed_strategy", 112, CPyStatic__strategies___globals);
        goto CPyL27;
    }
    CPy_DECREF(cpy_r_r22);
    CPy_DECREF(cpy_r_r24);
    return cpy_r_r28;
CPyL19: ;
    cpy_r_r29 = NULL;
    return cpy_r_r29;
CPyL20: ;
    CPy_DECREF(cpy_r_r2);
    goto CPyL3;
CPyL21: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r3);
    goto CPyL6;
CPyL22: ;
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r7);
    goto CPyL9;
CPyL23: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r5);
    goto CPyL19;
CPyL24: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r11);
    goto CPyL19;
CPyL25: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r15);
    goto CPyL19;
CPyL26: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL19;
CPyL27: ;
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r24);
    goto CPyL19;
}

PyObject *CPyPy__strategies___get_ufixed_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"abi_type", "registry", 0};
    static CPyArg_Parser parser = {"OO:get_ufixed_strategy", kwlist, 0};
    PyObject *obj_abi_type;
    PyObject *obj_registry;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_abi_type, &obj_registry)) {
        return NULL;
    }
    PyObject *arg_abi_type = obj_abi_type;
    PyObject *arg_registry;
    if (likely(Py_TYPE(obj_registry) == CPyType__strategies___StrategyRegistry))
        arg_registry = obj_registry;
    else {
        CPy_TypeError("faster_eth_abi.tools._strategies.StrategyRegistry", obj_registry); 
        goto fail;
    }
    PyObject *retval = CPyDef__strategies___get_ufixed_strategy(arg_abi_type, arg_registry);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_ufixed_strategy", 107, CPyStatic__strategies___globals);
    return NULL;
}

PyObject *CPyDef__strategies___get_fixed_strategy(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject **cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    CPyTagged cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject **cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    cpy_r_r0 = CPyStatics[103]; /* 'sub' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_abi_type, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 122, CPyStatic__strategies___globals);
        goto CPyL23;
    }
    cpy_r_r2 = PyObject_GetIter(cpy_r_r1);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 122, CPyStatic__strategies___globals);
        goto CPyL23;
    }
    cpy_r_r3 = PyIter_Next(cpy_r_r2);
    if (cpy_r_r3 == NULL) {
        goto CPyL24;
    } else
        goto CPyL5;
CPyL3: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r4 = 0;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 122, CPyStatic__strategies___globals);
        goto CPyL23;
    }
    CPy_Unreachable();
CPyL5: ;
    cpy_r_r5 = PyIter_Next(cpy_r_r2);
    if (cpy_r_r5 == NULL) {
        goto CPyL25;
    } else
        goto CPyL8;
CPyL6: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r6 = 0;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 122, CPyStatic__strategies___globals);
        goto CPyL23;
    }
    CPy_Unreachable();
CPyL8: ;
    cpy_r_r7 = PyIter_Next(cpy_r_r2);
    CPy_DECREF(cpy_r_r2);
    if (cpy_r_r7 == NULL) {
        goto CPyL11;
    } else
        goto CPyL26;
CPyL9: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r8 = 0;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 122, CPyStatic__strategies___globals);
        goto CPyL23;
    }
    CPy_Unreachable();
CPyL11: ;
    cpy_r_r9 = CPyStatic__strategies___globals;
    cpy_r_r10 = CPyStatics[101]; /* 'st' */
    cpy_r_r11 = CPyDict_GetItem(cpy_r_r9, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 124, CPyStatic__strategies___globals);
        goto CPyL27;
    }
    cpy_r_r12 = CPyStatics[198]; /* 1 */
    cpy_r_r13 = PyNumber_Subtract(cpy_r_r3, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 125, CPyStatic__strategies___globals);
        goto CPyL28;
    }
    cpy_r_r14 = CPyStatics[197]; /* 2 */
    cpy_r_r15 = CPyNumber_Power(cpy_r_r14, cpy_r_r13);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 125, CPyStatic__strategies___globals);
        goto CPyL28;
    }
    cpy_r_r16 = PyNumber_Negative(cpy_r_r15);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 125, CPyStatic__strategies___globals);
        goto CPyL28;
    }
    cpy_r_r17 = CPyStatics[198]; /* 1 */
    cpy_r_r18 = PyNumber_Subtract(cpy_r_r3, cpy_r_r17);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 126, CPyStatic__strategies___globals);
        goto CPyL29;
    }
    cpy_r_r19 = CPyStatics[197]; /* 2 */
    cpy_r_r20 = CPyNumber_Power(cpy_r_r19, cpy_r_r18);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 126, CPyStatic__strategies___globals);
        goto CPyL29;
    }
    cpy_r_r21 = CPyStatics[198]; /* 1 */
    cpy_r_r22 = PyNumber_Subtract(cpy_r_r20, cpy_r_r21);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 126, CPyStatic__strategies___globals);
        goto CPyL29;
    }
    cpy_r_r23 = CPyStatics[107]; /* 'decimals' */
    cpy_r_r24 = CPyStatics[192]; /* 0 */
    PyObject *cpy_r_r25[4] = {cpy_r_r11, cpy_r_r16, cpy_r_r22, cpy_r_r24};
    cpy_r_r26 = (PyObject **)&cpy_r_r25;
    cpy_r_r27 = CPyStatics[223]; /* ('min_value', 'max_value', 'places') */
    cpy_r_r28 = PyObject_VectorcallMethod(cpy_r_r23, cpy_r_r26, 9223372036854775809ULL, cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 124, CPyStatic__strategies___globals);
        goto CPyL30;
    }
    CPy_DECREF(cpy_r_r11);
    CPy_DECREF(cpy_r_r16);
    CPy_DECREF(cpy_r_r22);
    if (likely(PyLong_Check(cpy_r_r5)))
        cpy_r_r29 = CPyTagged_FromObject(cpy_r_r5);
    else {
        CPy_TypeError("int", cpy_r_r5); cpy_r_r29 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r29 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 128, CPyStatic__strategies___globals);
        goto CPyL31;
    }
    cpy_r_r30 = CPyDef_numeric___scale_places(cpy_r_r29);
    CPyTagged_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 128, CPyStatic__strategies___globals);
        goto CPyL31;
    }
    cpy_r_r31 = CPyStatics[109]; /* 'map' */
    PyObject *cpy_r_r32[2] = {cpy_r_r28, cpy_r_r30};
    cpy_r_r33 = (PyObject **)&cpy_r_r32;
    cpy_r_r34 = PyObject_VectorcallMethod(cpy_r_r31, cpy_r_r33, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 124, CPyStatic__strategies___globals);
        goto CPyL32;
    }
    CPy_DECREF(cpy_r_r28);
    CPy_DECREF(cpy_r_r30);
    return cpy_r_r34;
CPyL23: ;
    cpy_r_r35 = NULL;
    return cpy_r_r35;
CPyL24: ;
    CPy_DECREF(cpy_r_r2);
    goto CPyL3;
CPyL25: ;
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r3);
    goto CPyL6;
CPyL26: ;
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r7);
    goto CPyL9;
CPyL27: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r5);
    goto CPyL23;
CPyL28: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r11);
    goto CPyL23;
CPyL29: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r16);
    goto CPyL23;
CPyL30: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r22);
    goto CPyL23;
CPyL31: ;
    CPy_DecRef(cpy_r_r28);
    goto CPyL23;
CPyL32: ;
    CPy_DecRef(cpy_r_r28);
    CPy_DecRef(cpy_r_r30);
    goto CPyL23;
}

PyObject *CPyPy__strategies___get_fixed_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"abi_type", "registry", 0};
    static CPyArg_Parser parser = {"OO:get_fixed_strategy", kwlist, 0};
    PyObject *obj_abi_type;
    PyObject *obj_registry;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_abi_type, &obj_registry)) {
        return NULL;
    }
    PyObject *arg_abi_type = obj_abi_type;
    PyObject *arg_registry;
    if (likely(Py_TYPE(obj_registry) == CPyType__strategies___StrategyRegistry))
        arg_registry = obj_registry;
    else {
        CPy_TypeError("faster_eth_abi.tools._strategies.StrategyRegistry", obj_registry); 
        goto fail;
    }
    PyObject *retval = CPyDef__strategies___get_fixed_strategy(arg_abi_type, arg_registry);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_fixed_strategy", 119, CPyStatic__strategies___globals);
    return NULL;
}

PyObject *CPyDef__strategies___get_bytes_strategy(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject **cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    cpy_r_r0 = CPyStatics[103]; /* 'sub' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_abi_type, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_bytes_strategy", 134, CPyStatic__strategies___globals);
        goto CPyL4;
    }
    cpy_r_r2 = CPyStatic__strategies___globals;
    cpy_r_r3 = CPyStatics[101]; /* 'st' */
    cpy_r_r4 = CPyDict_GetItem(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_bytes_strategy", 136, CPyStatic__strategies___globals);
        goto CPyL5;
    }
    cpy_r_r5 = CPyStatics[110]; /* 'binary' */
    PyObject *cpy_r_r6[3] = {cpy_r_r4, cpy_r_r1, cpy_r_r1};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = CPyStatics[224]; /* ('min_size', 'max_size') */
    cpy_r_r9 = PyObject_VectorcallMethod(cpy_r_r5, cpy_r_r7, 9223372036854775809ULL, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_bytes_strategy", 136, CPyStatic__strategies___globals);
        goto CPyL6;
    }
    CPy_DECREF(cpy_r_r4);
    CPy_DECREF(cpy_r_r1);
    return cpy_r_r9;
CPyL4: ;
    cpy_r_r10 = NULL;
    return cpy_r_r10;
CPyL5: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL4;
CPyL6: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r4);
    goto CPyL4;
}

PyObject *CPyPy__strategies___get_bytes_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"abi_type", "registry", 0};
    static CPyArg_Parser parser = {"OO:get_bytes_strategy", kwlist, 0};
    PyObject *obj_abi_type;
    PyObject *obj_registry;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_abi_type, &obj_registry)) {
        return NULL;
    }
    PyObject *arg_abi_type = obj_abi_type;
    PyObject *arg_registry;
    if (likely(Py_TYPE(obj_registry) == CPyType__strategies___StrategyRegistry))
        arg_registry = obj_registry;
    else {
        CPy_TypeError("faster_eth_abi.tools._strategies.StrategyRegistry", obj_registry); 
        goto fail;
    }
    PyObject *retval = CPyDef__strategies___get_bytes_strategy(arg_abi_type, arg_registry);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_bytes_strategy", 131, CPyStatic__strategies___globals);
    return NULL;
}

PyObject *CPyDef__strategies___get_array_strategy(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    CPyTagged cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject **cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject **cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    cpy_r_r0 = CPyStatics[113]; /* 'item_type' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_abi_type, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_array_strategy", 149, CPyStatic__strategies___globals);
        goto CPyL15;
    }
    cpy_r_r2 = CPyStatics[114]; /* 'to_type_str' */
    PyObject *cpy_r_r3[1] = {cpy_r_r1};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_VectorcallMethod(cpy_r_r2, cpy_r_r4, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_array_strategy", 150, CPyStatic__strategies___globals);
        goto CPyL16;
    }
    CPy_DECREF(cpy_r_r1);
    if (likely(PyUnicode_Check(cpy_r_r5)))
        cpy_r_r6 = cpy_r_r5;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/tools/_strategies.py", "get_array_strategy", 150, CPyStatic__strategies___globals, "str", cpy_r_r5);
        goto CPyL15;
    }
    cpy_r_r7 = CPyDef__strategies___StrategyRegistry___get_strategy(cpy_r_registry, cpy_r_r6);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_array_strategy", 151, CPyStatic__strategies___globals);
        goto CPyL15;
    }
    cpy_r_r8 = CPyStatics[68]; /* 'arrlist' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_abi_type, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_array_strategy", 153, CPyStatic__strategies___globals);
        goto CPyL17;
    }
    cpy_r_r10 = CPyStatics[199]; /* -1 */
    cpy_r_r11 = PyObject_GetItem(cpy_r_r9, cpy_r_r10);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_array_strategy", 153, CPyStatic__strategies___globals);
        goto CPyL17;
    }
    cpy_r_r12 = CPyObject_Size(cpy_r_r11);
    if (unlikely(cpy_r_r12 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_array_strategy", 154, CPyStatic__strategies___globals);
        goto CPyL18;
    }
    cpy_r_r13 = cpy_r_r12 == 0;
    CPyTagged_DECREF(cpy_r_r12);
    if (cpy_r_r13) {
        goto CPyL19;
    } else
        goto CPyL11;
CPyL8: ;
    cpy_r_r14 = CPyStatic__strategies___globals;
    cpy_r_r15 = CPyStatics[101]; /* 'st' */
    cpy_r_r16 = CPyDict_GetItem(cpy_r_r14, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_array_strategy", 156, CPyStatic__strategies___globals);
        goto CPyL17;
    }
    cpy_r_r17 = CPyStatics[115]; /* 'lists' */
    PyObject *cpy_r_r18[2] = {cpy_r_r16, cpy_r_r7};
    cpy_r_r19 = (PyObject **)&cpy_r_r18;
    cpy_r_r20 = PyObject_VectorcallMethod(cpy_r_r17, cpy_r_r19, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_array_strategy", 156, CPyStatic__strategies___globals);
        goto CPyL20;
    }
    CPy_DECREF(cpy_r_r16);
    CPy_DECREF(cpy_r_r7);
    return cpy_r_r20;
CPyL11: ;
    cpy_r_r21 = CPyStatics[192]; /* 0 */
    cpy_r_r22 = PyObject_GetItem(cpy_r_r11, cpy_r_r21);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_array_strategy", 159, CPyStatic__strategies___globals);
        goto CPyL17;
    }
    cpy_r_r23 = CPyStatic__strategies___globals;
    cpy_r_r24 = CPyStatics[101]; /* 'st' */
    cpy_r_r25 = CPyDict_GetItem(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_array_strategy", 160, CPyStatic__strategies___globals);
        goto CPyL21;
    }
    cpy_r_r26 = CPyStatics[115]; /* 'lists' */
    PyObject *cpy_r_r27[4] = {cpy_r_r25, cpy_r_r7, cpy_r_r22, cpy_r_r22};
    cpy_r_r28 = (PyObject **)&cpy_r_r27;
    cpy_r_r29 = CPyStatics[224]; /* ('min_size', 'max_size') */
    cpy_r_r30 = PyObject_VectorcallMethod(cpy_r_r26, cpy_r_r28, 9223372036854775810ULL, cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_array_strategy", 160, CPyStatic__strategies___globals);
        goto CPyL22;
    }
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r22);
    return cpy_r_r30;
CPyL15: ;
    cpy_r_r31 = NULL;
    return cpy_r_r31;
CPyL16: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL15;
CPyL17: ;
    CPy_DecRef(cpy_r_r7);
    goto CPyL15;
CPyL18: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r11);
    goto CPyL15;
CPyL19: ;
    CPy_DECREF(cpy_r_r11);
    goto CPyL8;
CPyL20: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r16);
    goto CPyL15;
CPyL21: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r22);
    goto CPyL15;
CPyL22: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r25);
    goto CPyL15;
}

PyObject *CPyPy__strategies___get_array_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"abi_type", "registry", 0};
    static CPyArg_Parser parser = {"OO:get_array_strategy", kwlist, 0};
    PyObject *obj_abi_type;
    PyObject *obj_registry;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_abi_type, &obj_registry)) {
        return NULL;
    }
    PyObject *arg_abi_type = obj_abi_type;
    PyObject *arg_registry;
    if (likely(Py_TYPE(obj_registry) == CPyType__strategies___StrategyRegistry))
        arg_registry = obj_registry;
    else {
        CPy_TypeError("faster_eth_abi.tools._strategies.StrategyRegistry", obj_registry); 
        goto fail;
    }
    PyObject *retval = CPyDef__strategies___get_array_strategy(arg_abi_type, arg_registry);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_array_strategy", 146, CPyStatic__strategies___globals);
    return NULL;
}

PyObject *CPyDef__strategies___get_tuple_strategy(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    CPyPtr cpy_r_r3;
    int64_t cpy_r_r4;
    PyObject *cpy_r_r5;
    CPyTagged cpy_r_r6;
    CPyPtr cpy_r_r7;
    int64_t cpy_r_r8;
    CPyTagged cpy_r_r9;
    char cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    char cpy_r_r18;
    CPyTagged cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    cpy_r_r0 = CPyStatics[116]; /* 'components' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_abi_type, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_tuple_strategy", 168, CPyStatic__strategies___globals);
        goto CPyL19;
    }
    if (likely(PyTuple_Check(cpy_r_r1)))
        cpy_r_r2 = cpy_r_r1;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/tools/_strategies.py", "get_tuple_strategy", 168, CPyStatic__strategies___globals, "tuple", cpy_r_r1);
        goto CPyL19;
    }
    cpy_r_r3 = (CPyPtr)&((PyVarObject *)cpy_r_r2)->ob_size;
    cpy_r_r4 = *(int64_t *)cpy_r_r3;
    cpy_r_r5 = PyList_New(cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_tuple_strategy", 166, CPyStatic__strategies___globals);
        goto CPyL20;
    }
    cpy_r_r6 = 0;
CPyL4: ;
    cpy_r_r7 = (CPyPtr)&((PyVarObject *)cpy_r_r2)->ob_size;
    cpy_r_r8 = *(int64_t *)cpy_r_r7;
    cpy_r_r9 = cpy_r_r8 << 1;
    cpy_r_r10 = (Py_ssize_t)cpy_r_r6 < (Py_ssize_t)cpy_r_r9;
    if (!cpy_r_r10) goto CPyL21;
    cpy_r_r11 = CPySequenceTuple_GetItem(cpy_r_r2, cpy_r_r6);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_tuple_strategy", 166, CPyStatic__strategies___globals);
        goto CPyL22;
    }
    cpy_r_r12 = CPyStatics[114]; /* 'to_type_str' */
    PyObject *cpy_r_r13[1] = {cpy_r_r11};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = PyObject_VectorcallMethod(cpy_r_r12, cpy_r_r14, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_tuple_strategy", 167, CPyStatic__strategies___globals);
        goto CPyL23;
    }
    CPy_DECREF(cpy_r_r11);
    if (likely(PyUnicode_Check(cpy_r_r15)))
        cpy_r_r16 = cpy_r_r15;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/tools/_strategies.py", "get_tuple_strategy", 167, CPyStatic__strategies___globals, "str", cpy_r_r15);
        goto CPyL22;
    }
    cpy_r_r17 = CPyDef__strategies___StrategyRegistry___get_strategy(cpy_r_registry, cpy_r_r16);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_tuple_strategy", 167, CPyStatic__strategies___globals);
        goto CPyL22;
    }
    cpy_r_r18 = CPyList_SetItemUnsafe(cpy_r_r5, cpy_r_r6, cpy_r_r17);
    if (unlikely(!cpy_r_r18)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_tuple_strategy", 166, CPyStatic__strategies___globals);
        goto CPyL22;
    }
    cpy_r_r19 = cpy_r_r6 + 2;
    cpy_r_r6 = cpy_r_r19;
    goto CPyL4;
CPyL11: ;
    cpy_r_r20 = CPyStatic__strategies___globals;
    cpy_r_r21 = CPyStatics[101]; /* 'st' */
    cpy_r_r22 = CPyDict_GetItem(cpy_r_r20, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_tuple_strategy", 171, CPyStatic__strategies___globals);
        goto CPyL24;
    }
    cpy_r_r23 = CPyStatics[117]; /* 'tuples' */
    cpy_r_r24 = CPyObject_GetAttr(cpy_r_r22, cpy_r_r23);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_tuple_strategy", 171, CPyStatic__strategies___globals);
        goto CPyL24;
    }
    cpy_r_r25 = PyList_New(0);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_tuple_strategy", 171, CPyStatic__strategies___globals);
        goto CPyL25;
    }
    cpy_r_r26 = CPyList_Extend(cpy_r_r25, cpy_r_r5);
    CPy_DECREF_NO_IMM(cpy_r_r5);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_tuple_strategy", 171, CPyStatic__strategies___globals);
        goto CPyL26;
    } else
        goto CPyL27;
CPyL15: ;
    cpy_r_r27 = PyList_AsTuple(cpy_r_r25);
    CPy_DECREF_NO_IMM(cpy_r_r25);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_tuple_strategy", 171, CPyStatic__strategies___globals);
        goto CPyL28;
    }
    cpy_r_r28 = PyDict_New();
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_tuple_strategy", 171, CPyStatic__strategies___globals);
        goto CPyL29;
    }
    cpy_r_r29 = PyObject_Call(cpy_r_r24, cpy_r_r27, cpy_r_r28);
    CPy_DECREF(cpy_r_r24);
    CPy_DECREF(cpy_r_r27);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_tuple_strategy", 171, CPyStatic__strategies___globals);
        goto CPyL19;
    }
    return cpy_r_r29;
CPyL19: ;
    cpy_r_r30 = NULL;
    return cpy_r_r30;
CPyL20: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL19;
CPyL21: ;
    CPy_DECREF(cpy_r_r2);
    goto CPyL11;
CPyL22: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r5);
    goto CPyL19;
CPyL23: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r11);
    goto CPyL19;
CPyL24: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL19;
CPyL25: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r24);
    goto CPyL19;
CPyL26: ;
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r25);
    goto CPyL19;
CPyL27: ;
    CPy_DECREF(cpy_r_r26);
    goto CPyL15;
CPyL28: ;
    CPy_DecRef(cpy_r_r24);
    goto CPyL19;
CPyL29: ;
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r27);
    goto CPyL19;
}

PyObject *CPyPy__strategies___get_tuple_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"abi_type", "registry", 0};
    static CPyArg_Parser parser = {"OO:get_tuple_strategy", kwlist, 0};
    PyObject *obj_abi_type;
    PyObject *obj_registry;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_abi_type, &obj_registry)) {
        return NULL;
    }
    PyObject *arg_abi_type = obj_abi_type;
    PyObject *arg_registry;
    if (likely(Py_TYPE(obj_registry) == CPyType__strategies___StrategyRegistry))
        arg_registry = obj_registry;
    else {
        CPy_TypeError("faster_eth_abi.tools._strategies.StrategyRegistry", obj_registry); 
        goto fail;
    }
    PyObject *retval = CPyDef__strategies___get_tuple_strategy(arg_abi_type, arg_registry);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "get_tuple_strategy", 163, CPyStatic__strategies___globals);
    return NULL;
}

char CPyDef__strategies_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    CPyPtr cpy_r_r42;
    CPyPtr cpy_r_r43;
    CPyPtr cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    tuple_T2OO cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    int32_t cpy_r_r55;
    char cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    tuple_T2OO cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    int32_t cpy_r_r73;
    char cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    char cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    int32_t cpy_r_r87;
    char cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    int32_t cpy_r_r91;
    char cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject **cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject **cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    int32_t cpy_r_r112;
    char cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject **cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    int32_t cpy_r_r123;
    char cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject **cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    int32_t cpy_r_r137;
    char cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject **cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    int32_t cpy_r_r148;
    char cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    int32_t cpy_r_r153;
    char cpy_r_r154;
    PyObject *cpy_r_r155;
    char cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject *cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject **cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject *cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject *cpy_r_r166;
    PyObject *cpy_r_r167;
    char cpy_r_r168;
    PyObject *cpy_r_r169;
    char cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject **cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject *cpy_r_r181;
    char cpy_r_r182;
    PyObject *cpy_r_r183;
    char cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject **cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    PyObject *cpy_r_r194;
    char cpy_r_r195;
    PyObject *cpy_r_r196;
    char cpy_r_r197;
    PyObject *cpy_r_r198;
    char cpy_r_r199;
    PyObject *cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    PyObject *cpy_r_r204;
    PyObject **cpy_r_r206;
    PyObject *cpy_r_r207;
    PyObject *cpy_r_r208;
    PyObject *cpy_r_r209;
    char cpy_r_r210;
    PyObject *cpy_r_r211;
    char cpy_r_r212;
    PyObject *cpy_r_r213;
    char cpy_r_r214;
    PyObject *cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject *cpy_r_r218;
    PyObject **cpy_r_r220;
    PyObject *cpy_r_r221;
    PyObject *cpy_r_r222;
    PyObject *cpy_r_r223;
    PyObject *cpy_r_r224;
    PyObject *cpy_r_r225;
    char cpy_r_r226;
    PyObject *cpy_r_r227;
    char cpy_r_r228;
    PyObject *cpy_r_r229;
    PyObject *cpy_r_r230;
    PyObject *cpy_r_r231;
    PyObject *cpy_r_r232;
    PyObject **cpy_r_r234;
    PyObject *cpy_r_r235;
    PyObject *cpy_r_r236;
    PyObject *cpy_r_r237;
    PyObject *cpy_r_r238;
    PyObject *cpy_r_r239;
    char cpy_r_r240;
    PyObject *cpy_r_r241;
    char cpy_r_r242;
    PyObject *cpy_r_r243;
    PyObject *cpy_r_r244;
    PyObject *cpy_r_r245;
    PyObject *cpy_r_r246;
    PyObject *cpy_r_r247;
    PyObject **cpy_r_r249;
    PyObject *cpy_r_r250;
    PyObject *cpy_r_r251;
    PyObject *cpy_r_r252;
    PyObject *cpy_r_r253;
    PyObject *cpy_r_r254;
    PyObject *cpy_r_r255;
    char cpy_r_r256;
    PyObject *cpy_r_r257;
    char cpy_r_r258;
    PyObject *cpy_r_r259;
    PyObject *cpy_r_r260;
    PyObject *cpy_r_r261;
    PyObject *cpy_r_r262;
    PyObject *cpy_r_r263;
    PyObject **cpy_r_r265;
    PyObject *cpy_r_r266;
    PyObject *cpy_r_r267;
    PyObject *cpy_r_r268;
    char cpy_r_r269;
    PyObject *cpy_r_r270;
    char cpy_r_r271;
    PyObject *cpy_r_r272;
    char cpy_r_r273;
    PyObject *cpy_r_r274;
    PyObject *cpy_r_r275;
    PyObject *cpy_r_r276;
    PyObject *cpy_r_r277;
    PyObject *cpy_r_r278;
    PyObject **cpy_r_r280;
    PyObject *cpy_r_r281;
    PyObject *cpy_r_r282;
    PyObject *cpy_r_r283;
    PyObject *cpy_r_r284;
    PyObject *cpy_r_r285;
    PyObject *cpy_r_r286;
    char cpy_r_r287;
    PyObject *cpy_r_r288;
    char cpy_r_r289;
    PyObject *cpy_r_r290;
    PyObject *cpy_r_r291;
    PyObject *cpy_r_r292;
    PyObject *cpy_r_r293;
    PyObject *cpy_r_r294;
    PyObject **cpy_r_r296;
    PyObject *cpy_r_r297;
    PyObject *cpy_r_r298;
    PyObject *cpy_r_r299;
    char cpy_r_r300;
    PyObject *cpy_r_r301;
    char cpy_r_r302;
    PyObject *cpy_r_r303;
    char cpy_r_r304;
    PyObject *cpy_r_r305;
    PyObject *cpy_r_r306;
    PyObject *cpy_r_r307;
    PyObject *cpy_r_r308;
    PyObject *cpy_r_r309;
    PyObject *cpy_r_r310;
    PyObject *cpy_r_r311;
    char cpy_r_r312;
    PyObject *cpy_r_r313;
    char cpy_r_r314;
    PyObject *cpy_r_r315;
    PyObject *cpy_r_r316;
    PyObject *cpy_r_r317;
    PyObject *cpy_r_r318;
    PyObject *cpy_r_r319;
    PyObject *cpy_r_r320;
    PyObject *cpy_r_r321;
    char cpy_r_r322;
    PyObject *cpy_r_r323;
    char cpy_r_r324;
    PyObject *cpy_r_r325;
    PyObject *cpy_r_r326;
    PyObject *cpy_r_r327;
    PyObject *cpy_r_r328;
    int32_t cpy_r_r329;
    char cpy_r_r330;
    char cpy_r_r331;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[11]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", -1, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[225]; /* ('Callable', 'Final', 'Optional', 'Union') */
    cpy_r_r6 = CPyStatics[17]; /* 'typing' */
    cpy_r_r7 = CPyStatic__strategies___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 1, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[226]; /* ('to_checksum_address',) */
    cpy_r_r10 = CPyStatics[120]; /* 'cchecksum' */
    cpy_r_r11 = CPyStatic__strategies___globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 8, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPyModule_cchecksum = cpy_r_r12;
    CPy_INCREF(CPyModule_cchecksum);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[215]; /* ('TypeStr',) */
    cpy_r_r14 = CPyStatics[121]; /* 'eth_typing.abi' */
    cpy_r_r15 = CPyStatic__strategies___globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 11, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPyModule_eth_typing___abi = cpy_r_r16;
    CPy_INCREF(CPyModule_eth_typing___abi);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r17 = CPyStatics[227]; /* ('strategies',) */
    cpy_r_r18 = CPyStatics[228]; /* ('st',) */
    cpy_r_r19 = CPyStatics[123]; /* 'hypothesis' */
    cpy_r_r20 = CPyStatic__strategies___globals;
    cpy_r_r21 = CPyImport_ImportFromMany(cpy_r_r19, cpy_r_r17, cpy_r_r18, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 14, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPyModule_hypothesis = cpy_r_r21;
    CPy_INCREF(CPyModule_hypothesis);
    CPy_DECREF(cpy_r_r21);
    cpy_r_r22 = CPyStatics[216]; /* ('ABIType', 'BasicType', 'TupleType', 'normalize',
                                    'parse') */
    cpy_r_r23 = CPyStatics[82]; /* 'faster_eth_abi.grammar' */
    cpy_r_r24 = CPyStatic__strategies___globals;
    cpy_r_r25 = CPyImport_ImportFromMany(cpy_r_r23, cpy_r_r22, cpy_r_r22, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 18, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPyModule_faster_eth_abi___grammar = cpy_r_r25;
    CPy_INCREF(CPyModule_faster_eth_abi___grammar);
    CPy_DECREF(cpy_r_r25);
    cpy_r_r26 = CPyStatics[229]; /* ('BaseEquals', 'BaseRegistry', 'Lookup',
                                    'PredicateMapping', 'has_arrlist', 'is_base_tuple') */
    cpy_r_r27 = CPyStatics[42]; /* 'faster_eth_abi.registry' */
    cpy_r_r28 = CPyStatic__strategies___globals;
    cpy_r_r29 = CPyImport_ImportFromMany(cpy_r_r27, cpy_r_r26, cpy_r_r26, cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 25, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPyModule_faster_eth_abi___registry = cpy_r_r29;
    CPy_INCREF(CPyModule_faster_eth_abi___registry);
    CPy_DECREF(cpy_r_r29);
    cpy_r_r30 = CPyStatics[230]; /* ('scale_places',) */
    cpy_r_r31 = CPyStatics[130]; /* 'faster_eth_abi.utils.numeric' */
    cpy_r_r32 = CPyStatic__strategies___globals;
    cpy_r_r33 = CPyImport_ImportFromMany(cpy_r_r31, cpy_r_r30, cpy_r_r30, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 33, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPyModule_faster_eth_abi___utils___numeric = cpy_r_r33;
    CPy_INCREF(CPyModule_faster_eth_abi___utils___numeric);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r34 = CPyStatic__strategies___globals;
    cpy_r_r35 = CPyStatics[32]; /* 'Callable' */
    cpy_r_r36 = CPyDict_GetItem(cpy_r_r34, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 37, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r37 = CPyStatic__strategies___globals;
    cpy_r_r38 = CPyStatics[81]; /* 'ABIType' */
    cpy_r_r39 = CPyDict_GetItem(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 37, CPyStatic__strategies___globals);
        goto CPyL143;
    }
    cpy_r_r40 = CPyStatics[131]; /* 'StrategyRegistry' */
    cpy_r_r41 = PyList_New(2);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 37, CPyStatic__strategies___globals);
        goto CPyL144;
    }
    cpy_r_r42 = (CPyPtr)&((PyListObject *)cpy_r_r41)->ob_item;
    cpy_r_r43 = *(CPyPtr *)cpy_r_r42;
    *(PyObject * *)cpy_r_r43 = cpy_r_r39;
    CPy_INCREF(cpy_r_r40);
    cpy_r_r44 = cpy_r_r43 + 8;
    *(PyObject * *)cpy_r_r44 = cpy_r_r40;
    cpy_r_r45 = CPyStatic__strategies___globals;
    cpy_r_r46 = CPyStatics[101]; /* 'st' */
    cpy_r_r47 = CPyDict_GetItem(cpy_r_r45, cpy_r_r46);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 37, CPyStatic__strategies___globals);
        goto CPyL145;
    }
    cpy_r_r48 = CPyStatics[102]; /* 'SearchStrategy' */
    cpy_r_r49 = CPyObject_GetAttr(cpy_r_r47, cpy_r_r48);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 37, CPyStatic__strategies___globals);
        goto CPyL145;
    }
    cpy_r_r50.f0 = cpy_r_r41;
    cpy_r_r50.f1 = cpy_r_r49;
    cpy_r_r51 = PyTuple_New(2);
    if (unlikely(cpy_r_r51 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp13 = cpy_r_r50.f0;
    PyTuple_SET_ITEM(cpy_r_r51, 0, __tmp13);
    PyObject *__tmp14 = cpy_r_r50.f1;
    PyTuple_SET_ITEM(cpy_r_r51, 1, __tmp14);
    cpy_r_r52 = PyObject_GetItem(cpy_r_r36, cpy_r_r51);
    CPy_DECREF(cpy_r_r36);
    CPy_DECREF(cpy_r_r51);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 37, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r53 = CPyStatic__strategies___globals;
    cpy_r_r54 = CPyStatics[132]; /* 'StrategyFactory' */
    cpy_r_r55 = CPyDict_SetItem(cpy_r_r53, cpy_r_r54, cpy_r_r52);
    CPy_DECREF(cpy_r_r52);
    cpy_r_r56 = cpy_r_r55 >= 0;
    if (unlikely(!cpy_r_r56)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 37, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r57 = CPyStatic__strategies___globals;
    cpy_r_r58 = CPyStatics[118]; /* 'Union' */
    cpy_r_r59 = CPyDict_GetItem(cpy_r_r57, cpy_r_r58);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 38, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r60 = CPyStatic__strategies___globals;
    cpy_r_r61 = CPyStatics[101]; /* 'st' */
    cpy_r_r62 = CPyDict_GetItem(cpy_r_r60, cpy_r_r61);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 38, CPyStatic__strategies___globals);
        goto CPyL146;
    }
    cpy_r_r63 = CPyStatics[102]; /* 'SearchStrategy' */
    cpy_r_r64 = CPyObject_GetAttr(cpy_r_r62, cpy_r_r63);
    CPy_DECREF(cpy_r_r62);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 38, CPyStatic__strategies___globals);
        goto CPyL146;
    }
    cpy_r_r65 = CPyStatic__strategies___globals;
    cpy_r_r66 = CPyStatics[132]; /* 'StrategyFactory' */
    cpy_r_r67 = CPyDict_GetItem(cpy_r_r65, cpy_r_r66);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 38, CPyStatic__strategies___globals);
        goto CPyL147;
    }
    cpy_r_r68.f0 = cpy_r_r64;
    cpy_r_r68.f1 = cpy_r_r67;
    cpy_r_r69 = PyTuple_New(2);
    if (unlikely(cpy_r_r69 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp15 = cpy_r_r68.f0;
    PyTuple_SET_ITEM(cpy_r_r69, 0, __tmp15);
    PyObject *__tmp16 = cpy_r_r68.f1;
    PyTuple_SET_ITEM(cpy_r_r69, 1, __tmp16);
    cpy_r_r70 = PyObject_GetItem(cpy_r_r59, cpy_r_r69);
    CPy_DECREF(cpy_r_r59);
    CPy_DECREF(cpy_r_r69);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 38, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r71 = CPyStatic__strategies___globals;
    cpy_r_r72 = CPyStatics[133]; /* 'StrategyRegistration' */
    cpy_r_r73 = CPyDict_SetItem(cpy_r_r71, cpy_r_r72, cpy_r_r70);
    CPy_DECREF(cpy_r_r70);
    cpy_r_r74 = cpy_r_r73 >= 0;
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 38, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r75 = CPyStatic__strategies___globals;
    cpy_r_r76 = CPyStatics[125]; /* 'BaseRegistry' */
    cpy_r_r77 = CPyDict_GetItem(cpy_r_r75, cpy_r_r76);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 41, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r78 = PyTuple_Pack(1, cpy_r_r77);
    CPy_DECREF(cpy_r_r77);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 41, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r79 = CPyStatics[94]; /* 'faster_eth_abi.tools._strategies' */
    cpy_r_r80 = (PyObject *)CPyType__strategies___StrategyRegistry_template;
    cpy_r_r81 = CPyType_FromTemplate(cpy_r_r80, cpy_r_r78, cpy_r_r79);
    CPy_DECREF(cpy_r_r78);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 41, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r82 = CPyDef__strategies___StrategyRegistry_trait_vtable_setup();
    if (unlikely(cpy_r_r82 == 2)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", -1, CPyStatic__strategies___globals);
        goto CPyL148;
    }
    cpy_r_r83 = CPyStatics[134]; /* '__mypyc_attrs__' */
    cpy_r_r84 = CPyStatics[135]; /* '_strategies' */
    cpy_r_r85 = CPyStatics[136]; /* '__dict__' */
    cpy_r_r86 = PyTuple_Pack(2, cpy_r_r84, cpy_r_r85);
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 41, CPyStatic__strategies___globals);
        goto CPyL148;
    }
    cpy_r_r87 = PyObject_SetAttr(cpy_r_r81, cpy_r_r83, cpy_r_r86);
    CPy_DECREF(cpy_r_r86);
    cpy_r_r88 = cpy_r_r87 >= 0;
    if (unlikely(!cpy_r_r88)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 41, CPyStatic__strategies___globals);
        goto CPyL148;
    }
    CPyType__strategies___StrategyRegistry = (PyTypeObject *)cpy_r_r81;
    CPy_INCREF(CPyType__strategies___StrategyRegistry);
    cpy_r_r89 = CPyStatic__strategies___globals;
    cpy_r_r90 = CPyStatics[131]; /* 'StrategyRegistry' */
    cpy_r_r91 = CPyDict_SetItem(cpy_r_r89, cpy_r_r90, cpy_r_r81);
    CPy_DECREF(cpy_r_r81);
    cpy_r_r92 = cpy_r_r91 >= 0;
    if (unlikely(!cpy_r_r92)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 41, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r93 = CPyStatic__strategies___globals;
    cpy_r_r94 = CPyStatics[101]; /* 'st' */
    cpy_r_r95 = CPyDict_GetItem(cpy_r_r93, cpy_r_r94);
    if (unlikely(cpy_r_r95 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 103, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r96 = CPyStatics[110]; /* 'binary' */
    cpy_r_r97 = CPyStatics[200]; /* 20 */
    cpy_r_r98 = CPyStatics[200]; /* 20 */
    PyObject *cpy_r_r99[3] = {cpy_r_r95, cpy_r_r97, cpy_r_r98};
    cpy_r_r100 = (PyObject **)&cpy_r_r99;
    cpy_r_r101 = CPyStatics[224]; /* ('min_size', 'max_size') */
    cpy_r_r102 = PyObject_VectorcallMethod(cpy_r_r96, cpy_r_r100, 9223372036854775809ULL, cpy_r_r101);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 103, CPyStatic__strategies___globals);
        goto CPyL149;
    }
    CPy_DECREF(cpy_r_r95);
    cpy_r_r103 = CPyStatic__strategies___globals;
    cpy_r_r104 = CPyStatics[119]; /* 'to_checksum_address' */
    cpy_r_r105 = CPyDict_GetItem(cpy_r_r103, cpy_r_r104);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 103, CPyStatic__strategies___globals);
        goto CPyL150;
    }
    cpy_r_r106 = CPyStatics[109]; /* 'map' */
    PyObject *cpy_r_r107[2] = {cpy_r_r102, cpy_r_r105};
    cpy_r_r108 = (PyObject **)&cpy_r_r107;
    cpy_r_r109 = PyObject_VectorcallMethod(cpy_r_r106, cpy_r_r108, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 103, CPyStatic__strategies___globals);
        goto CPyL151;
    }
    CPy_DECREF(cpy_r_r102);
    CPy_DECREF(cpy_r_r105);
    CPyStatic__strategies___address_strategy = cpy_r_r109;
    CPy_INCREF(CPyStatic__strategies___address_strategy);
    cpy_r_r110 = CPyStatic__strategies___globals;
    cpy_r_r111 = CPyStatics[137]; /* 'address_strategy' */
    cpy_r_r112 = CPyDict_SetItem(cpy_r_r110, cpy_r_r111, cpy_r_r109);
    CPy_DECREF(cpy_r_r109);
    cpy_r_r113 = cpy_r_r112 >= 0;
    if (unlikely(!cpy_r_r113)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 103, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r114 = CPyStatic__strategies___globals;
    cpy_r_r115 = CPyStatics[101]; /* 'st' */
    cpy_r_r116 = CPyDict_GetItem(cpy_r_r114, cpy_r_r115);
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 104, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r117 = CPyStatics[138]; /* 'booleans' */
    PyObject *cpy_r_r118[1] = {cpy_r_r116};
    cpy_r_r119 = (PyObject **)&cpy_r_r118;
    cpy_r_r120 = PyObject_VectorcallMethod(cpy_r_r117, cpy_r_r119, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r120 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 104, CPyStatic__strategies___globals);
        goto CPyL152;
    }
    CPy_DECREF(cpy_r_r116);
    CPyStatic__strategies___bool_strategy = cpy_r_r120;
    CPy_INCREF(CPyStatic__strategies___bool_strategy);
    cpy_r_r121 = CPyStatic__strategies___globals;
    cpy_r_r122 = CPyStatics[139]; /* 'bool_strategy' */
    cpy_r_r123 = CPyDict_SetItem(cpy_r_r121, cpy_r_r122, cpy_r_r120);
    CPy_DECREF(cpy_r_r120);
    cpy_r_r124 = cpy_r_r123 >= 0;
    if (unlikely(!cpy_r_r124)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 104, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r125 = CPyStatic__strategies___globals;
    cpy_r_r126 = CPyStatics[101]; /* 'st' */
    cpy_r_r127 = CPyDict_GetItem(cpy_r_r125, cpy_r_r126);
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 142, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r128 = CPyStatics[110]; /* 'binary' */
    cpy_r_r129 = CPyStatics[192]; /* 0 */
    cpy_r_r130 = CPyStatics[201]; /* 4096 */
    PyObject *cpy_r_r131[3] = {cpy_r_r127, cpy_r_r129, cpy_r_r130};
    cpy_r_r132 = (PyObject **)&cpy_r_r131;
    cpy_r_r133 = CPyStatics[224]; /* ('min_size', 'max_size') */
    cpy_r_r134 = PyObject_VectorcallMethod(cpy_r_r128, cpy_r_r132, 9223372036854775809ULL, cpy_r_r133);
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 142, CPyStatic__strategies___globals);
        goto CPyL153;
    }
    CPy_DECREF(cpy_r_r127);
    CPyStatic__strategies___bytes_strategy = cpy_r_r134;
    CPy_INCREF(CPyStatic__strategies___bytes_strategy);
    cpy_r_r135 = CPyStatic__strategies___globals;
    cpy_r_r136 = CPyStatics[140]; /* 'bytes_strategy' */
    cpy_r_r137 = CPyDict_SetItem(cpy_r_r135, cpy_r_r136, cpy_r_r134);
    CPy_DECREF(cpy_r_r134);
    cpy_r_r138 = cpy_r_r137 >= 0;
    if (unlikely(!cpy_r_r138)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 142, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r139 = CPyStatic__strategies___globals;
    cpy_r_r140 = CPyStatics[101]; /* 'st' */
    cpy_r_r141 = CPyDict_GetItem(cpy_r_r139, cpy_r_r140);
    if (unlikely(cpy_r_r141 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 143, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r142 = CPyStatics[141]; /* 'text' */
    PyObject *cpy_r_r143[1] = {cpy_r_r141};
    cpy_r_r144 = (PyObject **)&cpy_r_r143;
    cpy_r_r145 = PyObject_VectorcallMethod(cpy_r_r142, cpy_r_r144, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r145 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 143, CPyStatic__strategies___globals);
        goto CPyL154;
    }
    CPy_DECREF(cpy_r_r141);
    CPyStatic__strategies___string_strategy = cpy_r_r145;
    CPy_INCREF(CPyStatic__strategies___string_strategy);
    cpy_r_r146 = CPyStatic__strategies___globals;
    cpy_r_r147 = CPyStatics[142]; /* 'string_strategy' */
    cpy_r_r148 = CPyDict_SetItem(cpy_r_r146, cpy_r_r147, cpy_r_r145);
    CPy_DECREF(cpy_r_r145);
    cpy_r_r149 = cpy_r_r148 >= 0;
    if (unlikely(!cpy_r_r149)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 143, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r150 = CPyDef__strategies___StrategyRegistry();
    if (unlikely(cpy_r_r150 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 174, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPyStatic__strategies___strategy_registry = cpy_r_r150;
    CPy_INCREF_NO_IMM(CPyStatic__strategies___strategy_registry);
    cpy_r_r151 = CPyStatic__strategies___globals;
    cpy_r_r152 = CPyStatics[143]; /* 'strategy_registry' */
    cpy_r_r153 = CPyDict_SetItem(cpy_r_r151, cpy_r_r152, cpy_r_r150);
    CPy_DECREF_NO_IMM(cpy_r_r150);
    cpy_r_r154 = cpy_r_r153 >= 0;
    if (unlikely(!cpy_r_r154)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 174, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r155 = CPyStatic__strategies___strategy_registry;
    if (likely(cpy_r_r155 != NULL)) goto CPyL49;
    PyErr_SetString(PyExc_NameError, "value for final name \"strategy_registry\" was not set");
    cpy_r_r156 = 0;
    if (unlikely(!cpy_r_r156)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 176, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL49: ;
    cpy_r_r157 = CPyStatics[144]; /* 'uint' */
    cpy_r_r158 = CPyStatic__strategies___globals;
    cpy_r_r159 = CPyStatics[124]; /* 'BaseEquals' */
    cpy_r_r160 = CPyDict_GetItem(cpy_r_r158, cpy_r_r159);
    if (unlikely(cpy_r_r160 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 177, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    PyObject *cpy_r_r161[1] = {cpy_r_r157};
    cpy_r_r162 = (PyObject **)&cpy_r_r161;
    cpy_r_r163 = PyObject_Vectorcall(cpy_r_r160, cpy_r_r162, 1, 0);
    CPy_DECREF(cpy_r_r160);
    if (unlikely(cpy_r_r163 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 177, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r164 = CPyStatic__strategies___globals;
    cpy_r_r165 = CPyStatics[145]; /* 'get_uint_strategy' */
    cpy_r_r166 = CPyDict_GetItem(cpy_r_r164, cpy_r_r165);
    if (unlikely(cpy_r_r166 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 178, CPyStatic__strategies___globals);
        goto CPyL155;
    }
    cpy_r_r167 = CPyStatics[144]; /* 'uint' */
    cpy_r_r168 = CPyDef__strategies___StrategyRegistry___register_strategy(cpy_r_r155, cpy_r_r163, cpy_r_r166, cpy_r_r167);
    CPy_DECREF(cpy_r_r163);
    CPy_DECREF(cpy_r_r166);
    if (unlikely(cpy_r_r168 == 2)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 176, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r169 = CPyStatic__strategies___strategy_registry;
    if (likely(cpy_r_r169 != NULL)) goto CPyL56;
    PyErr_SetString(PyExc_NameError, "value for final name \"strategy_registry\" was not set");
    cpy_r_r170 = 0;
    if (unlikely(!cpy_r_r170)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 181, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL56: ;
    cpy_r_r171 = CPyStatics[146]; /* 'int' */
    cpy_r_r172 = CPyStatic__strategies___globals;
    cpy_r_r173 = CPyStatics[124]; /* 'BaseEquals' */
    cpy_r_r174 = CPyDict_GetItem(cpy_r_r172, cpy_r_r173);
    if (unlikely(cpy_r_r174 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 182, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    PyObject *cpy_r_r175[1] = {cpy_r_r171};
    cpy_r_r176 = (PyObject **)&cpy_r_r175;
    cpy_r_r177 = PyObject_Vectorcall(cpy_r_r174, cpy_r_r176, 1, 0);
    CPy_DECREF(cpy_r_r174);
    if (unlikely(cpy_r_r177 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 182, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r178 = CPyStatic__strategies___globals;
    cpy_r_r179 = CPyStatics[147]; /* 'get_int_strategy' */
    cpy_r_r180 = CPyDict_GetItem(cpy_r_r178, cpy_r_r179);
    if (unlikely(cpy_r_r180 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 183, CPyStatic__strategies___globals);
        goto CPyL156;
    }
    cpy_r_r181 = CPyStatics[146]; /* 'int' */
    cpy_r_r182 = CPyDef__strategies___StrategyRegistry___register_strategy(cpy_r_r169, cpy_r_r177, cpy_r_r180, cpy_r_r181);
    CPy_DECREF(cpy_r_r177);
    CPy_DECREF(cpy_r_r180);
    if (unlikely(cpy_r_r182 == 2)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 181, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r183 = CPyStatic__strategies___strategy_registry;
    if (likely(cpy_r_r183 != NULL)) goto CPyL63;
    PyErr_SetString(PyExc_NameError, "value for final name \"strategy_registry\" was not set");
    cpy_r_r184 = 0;
    if (unlikely(!cpy_r_r184)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 186, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL63: ;
    cpy_r_r185 = CPyStatics[148]; /* 'address' */
    cpy_r_r186 = CPyStatic__strategies___globals;
    cpy_r_r187 = CPyStatics[124]; /* 'BaseEquals' */
    cpy_r_r188 = CPyDict_GetItem(cpy_r_r186, cpy_r_r187);
    if (unlikely(cpy_r_r188 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 187, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r189 = 0 ? Py_True : Py_False;
    PyObject *cpy_r_r190[2] = {cpy_r_r185, cpy_r_r189};
    cpy_r_r191 = (PyObject **)&cpy_r_r190;
    cpy_r_r192 = CPyStatics[231]; /* ('with_sub',) */
    cpy_r_r193 = PyObject_Vectorcall(cpy_r_r188, cpy_r_r191, 1, cpy_r_r192);
    CPy_DECREF(cpy_r_r188);
    if (unlikely(cpy_r_r193 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 187, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r194 = CPyStatic__strategies___address_strategy;
    if (unlikely(cpy_r_r194 == NULL)) {
        goto CPyL157;
    } else
        goto CPyL68;
CPyL66: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"address_strategy\" was not set");
    cpy_r_r195 = 0;
    if (unlikely(!cpy_r_r195)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 188, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL68: ;
    cpy_r_r196 = CPyStatics[148]; /* 'address' */
    cpy_r_r197 = CPyDef__strategies___StrategyRegistry___register_strategy(cpy_r_r183, cpy_r_r193, cpy_r_r194, cpy_r_r196);
    CPy_DECREF(cpy_r_r193);
    if (unlikely(cpy_r_r197 == 2)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 186, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r198 = CPyStatic__strategies___strategy_registry;
    if (likely(cpy_r_r198 != NULL)) goto CPyL72;
    PyErr_SetString(PyExc_NameError, "value for final name \"strategy_registry\" was not set");
    cpy_r_r199 = 0;
    if (unlikely(!cpy_r_r199)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 191, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL72: ;
    cpy_r_r200 = CPyStatics[150]; /* 'bool' */
    cpy_r_r201 = CPyStatic__strategies___globals;
    cpy_r_r202 = CPyStatics[124]; /* 'BaseEquals' */
    cpy_r_r203 = CPyDict_GetItem(cpy_r_r201, cpy_r_r202);
    if (unlikely(cpy_r_r203 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 192, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r204 = 0 ? Py_True : Py_False;
    PyObject *cpy_r_r205[2] = {cpy_r_r200, cpy_r_r204};
    cpy_r_r206 = (PyObject **)&cpy_r_r205;
    cpy_r_r207 = CPyStatics[231]; /* ('with_sub',) */
    cpy_r_r208 = PyObject_Vectorcall(cpy_r_r203, cpy_r_r206, 1, cpy_r_r207);
    CPy_DECREF(cpy_r_r203);
    if (unlikely(cpy_r_r208 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 192, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r209 = CPyStatic__strategies___bool_strategy;
    if (unlikely(cpy_r_r209 == NULL)) {
        goto CPyL158;
    } else
        goto CPyL77;
CPyL75: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"bool_strategy\" was not set");
    cpy_r_r210 = 0;
    if (unlikely(!cpy_r_r210)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 193, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL77: ;
    cpy_r_r211 = CPyStatics[150]; /* 'bool' */
    cpy_r_r212 = CPyDef__strategies___StrategyRegistry___register_strategy(cpy_r_r198, cpy_r_r208, cpy_r_r209, cpy_r_r211);
    CPy_DECREF(cpy_r_r208);
    if (unlikely(cpy_r_r212 == 2)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 191, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r213 = CPyStatic__strategies___strategy_registry;
    if (likely(cpy_r_r213 != NULL)) goto CPyL81;
    PyErr_SetString(PyExc_NameError, "value for final name \"strategy_registry\" was not set");
    cpy_r_r214 = 0;
    if (unlikely(!cpy_r_r214)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 196, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL81: ;
    cpy_r_r215 = CPyStatics[151]; /* 'ufixed' */
    cpy_r_r216 = CPyStatic__strategies___globals;
    cpy_r_r217 = CPyStatics[124]; /* 'BaseEquals' */
    cpy_r_r218 = CPyDict_GetItem(cpy_r_r216, cpy_r_r217);
    if (unlikely(cpy_r_r218 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 197, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    PyObject *cpy_r_r219[1] = {cpy_r_r215};
    cpy_r_r220 = (PyObject **)&cpy_r_r219;
    cpy_r_r221 = PyObject_Vectorcall(cpy_r_r218, cpy_r_r220, 1, 0);
    CPy_DECREF(cpy_r_r218);
    if (unlikely(cpy_r_r221 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 197, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r222 = CPyStatic__strategies___globals;
    cpy_r_r223 = CPyStatics[152]; /* 'get_ufixed_strategy' */
    cpy_r_r224 = CPyDict_GetItem(cpy_r_r222, cpy_r_r223);
    if (unlikely(cpy_r_r224 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 198, CPyStatic__strategies___globals);
        goto CPyL159;
    }
    cpy_r_r225 = CPyStatics[151]; /* 'ufixed' */
    cpy_r_r226 = CPyDef__strategies___StrategyRegistry___register_strategy(cpy_r_r213, cpy_r_r221, cpy_r_r224, cpy_r_r225);
    CPy_DECREF(cpy_r_r221);
    CPy_DECREF(cpy_r_r224);
    if (unlikely(cpy_r_r226 == 2)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 196, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r227 = CPyStatic__strategies___strategy_registry;
    if (likely(cpy_r_r227 != NULL)) goto CPyL88;
    PyErr_SetString(PyExc_NameError, "value for final name \"strategy_registry\" was not set");
    cpy_r_r228 = 0;
    if (unlikely(!cpy_r_r228)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 201, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL88: ;
    cpy_r_r229 = CPyStatics[153]; /* 'fixed' */
    cpy_r_r230 = CPyStatic__strategies___globals;
    cpy_r_r231 = CPyStatics[124]; /* 'BaseEquals' */
    cpy_r_r232 = CPyDict_GetItem(cpy_r_r230, cpy_r_r231);
    if (unlikely(cpy_r_r232 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 202, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    PyObject *cpy_r_r233[1] = {cpy_r_r229};
    cpy_r_r234 = (PyObject **)&cpy_r_r233;
    cpy_r_r235 = PyObject_Vectorcall(cpy_r_r232, cpy_r_r234, 1, 0);
    CPy_DECREF(cpy_r_r232);
    if (unlikely(cpy_r_r235 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 202, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r236 = CPyStatic__strategies___globals;
    cpy_r_r237 = CPyStatics[154]; /* 'get_fixed_strategy' */
    cpy_r_r238 = CPyDict_GetItem(cpy_r_r236, cpy_r_r237);
    if (unlikely(cpy_r_r238 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 203, CPyStatic__strategies___globals);
        goto CPyL160;
    }
    cpy_r_r239 = CPyStatics[153]; /* 'fixed' */
    cpy_r_r240 = CPyDef__strategies___StrategyRegistry___register_strategy(cpy_r_r227, cpy_r_r235, cpy_r_r238, cpy_r_r239);
    CPy_DECREF(cpy_r_r235);
    CPy_DECREF(cpy_r_r238);
    if (unlikely(cpy_r_r240 == 2)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 201, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r241 = CPyStatic__strategies___strategy_registry;
    if (likely(cpy_r_r241 != NULL)) goto CPyL95;
    PyErr_SetString(PyExc_NameError, "value for final name \"strategy_registry\" was not set");
    cpy_r_r242 = 0;
    if (unlikely(!cpy_r_r242)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 206, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL95: ;
    cpy_r_r243 = CPyStatics[155]; /* 'bytes' */
    cpy_r_r244 = CPyStatic__strategies___globals;
    cpy_r_r245 = CPyStatics[124]; /* 'BaseEquals' */
    cpy_r_r246 = CPyDict_GetItem(cpy_r_r244, cpy_r_r245);
    if (unlikely(cpy_r_r246 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 207, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r247 = 1 ? Py_True : Py_False;
    PyObject *cpy_r_r248[2] = {cpy_r_r243, cpy_r_r247};
    cpy_r_r249 = (PyObject **)&cpy_r_r248;
    cpy_r_r250 = CPyStatics[231]; /* ('with_sub',) */
    cpy_r_r251 = PyObject_Vectorcall(cpy_r_r246, cpy_r_r249, 1, cpy_r_r250);
    CPy_DECREF(cpy_r_r246);
    if (unlikely(cpy_r_r251 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 207, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r252 = CPyStatic__strategies___globals;
    cpy_r_r253 = CPyStatics[156]; /* 'get_bytes_strategy' */
    cpy_r_r254 = CPyDict_GetItem(cpy_r_r252, cpy_r_r253);
    if (unlikely(cpy_r_r254 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 208, CPyStatic__strategies___globals);
        goto CPyL161;
    }
    cpy_r_r255 = CPyStatics[157]; /* 'bytes<M>' */
    cpy_r_r256 = CPyDef__strategies___StrategyRegistry___register_strategy(cpy_r_r241, cpy_r_r251, cpy_r_r254, cpy_r_r255);
    CPy_DECREF(cpy_r_r251);
    CPy_DECREF(cpy_r_r254);
    if (unlikely(cpy_r_r256 == 2)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 206, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r257 = CPyStatic__strategies___strategy_registry;
    if (likely(cpy_r_r257 != NULL)) goto CPyL102;
    PyErr_SetString(PyExc_NameError, "value for final name \"strategy_registry\" was not set");
    cpy_r_r258 = 0;
    if (unlikely(!cpy_r_r258)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 211, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL102: ;
    cpy_r_r259 = CPyStatics[155]; /* 'bytes' */
    cpy_r_r260 = CPyStatic__strategies___globals;
    cpy_r_r261 = CPyStatics[124]; /* 'BaseEquals' */
    cpy_r_r262 = CPyDict_GetItem(cpy_r_r260, cpy_r_r261);
    if (unlikely(cpy_r_r262 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 212, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r263 = 0 ? Py_True : Py_False;
    PyObject *cpy_r_r264[2] = {cpy_r_r259, cpy_r_r263};
    cpy_r_r265 = (PyObject **)&cpy_r_r264;
    cpy_r_r266 = CPyStatics[231]; /* ('with_sub',) */
    cpy_r_r267 = PyObject_Vectorcall(cpy_r_r262, cpy_r_r265, 1, cpy_r_r266);
    CPy_DECREF(cpy_r_r262);
    if (unlikely(cpy_r_r267 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 212, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r268 = CPyStatic__strategies___bytes_strategy;
    if (unlikely(cpy_r_r268 == NULL)) {
        goto CPyL162;
    } else
        goto CPyL107;
CPyL105: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"bytes_strategy\" was not set");
    cpy_r_r269 = 0;
    if (unlikely(!cpy_r_r269)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 213, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL107: ;
    cpy_r_r270 = CPyStatics[155]; /* 'bytes' */
    cpy_r_r271 = CPyDef__strategies___StrategyRegistry___register_strategy(cpy_r_r257, cpy_r_r267, cpy_r_r268, cpy_r_r270);
    CPy_DECREF(cpy_r_r267);
    if (unlikely(cpy_r_r271 == 2)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 211, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r272 = CPyStatic__strategies___strategy_registry;
    if (likely(cpy_r_r272 != NULL)) goto CPyL111;
    PyErr_SetString(PyExc_NameError, "value for final name \"strategy_registry\" was not set");
    cpy_r_r273 = 0;
    if (unlikely(!cpy_r_r273)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 216, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL111: ;
    cpy_r_r274 = CPyStatics[158]; /* 'function' */
    cpy_r_r275 = CPyStatic__strategies___globals;
    cpy_r_r276 = CPyStatics[124]; /* 'BaseEquals' */
    cpy_r_r277 = CPyDict_GetItem(cpy_r_r275, cpy_r_r276);
    if (unlikely(cpy_r_r277 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 217, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r278 = 0 ? Py_True : Py_False;
    PyObject *cpy_r_r279[2] = {cpy_r_r274, cpy_r_r278};
    cpy_r_r280 = (PyObject **)&cpy_r_r279;
    cpy_r_r281 = CPyStatics[231]; /* ('with_sub',) */
    cpy_r_r282 = PyObject_Vectorcall(cpy_r_r277, cpy_r_r280, 1, cpy_r_r281);
    CPy_DECREF(cpy_r_r277);
    if (unlikely(cpy_r_r282 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 217, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r283 = CPyStatic__strategies___globals;
    cpy_r_r284 = CPyStatics[156]; /* 'get_bytes_strategy' */
    cpy_r_r285 = CPyDict_GetItem(cpy_r_r283, cpy_r_r284);
    if (unlikely(cpy_r_r285 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 218, CPyStatic__strategies___globals);
        goto CPyL163;
    }
    cpy_r_r286 = CPyStatics[158]; /* 'function' */
    cpy_r_r287 = CPyDef__strategies___StrategyRegistry___register_strategy(cpy_r_r272, cpy_r_r282, cpy_r_r285, cpy_r_r286);
    CPy_DECREF(cpy_r_r282);
    CPy_DECREF(cpy_r_r285);
    if (unlikely(cpy_r_r287 == 2)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 216, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r288 = CPyStatic__strategies___strategy_registry;
    if (likely(cpy_r_r288 != NULL)) goto CPyL118;
    PyErr_SetString(PyExc_NameError, "value for final name \"strategy_registry\" was not set");
    cpy_r_r289 = 0;
    if (unlikely(!cpy_r_r289)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 221, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL118: ;
    cpy_r_r290 = CPyStatics[159]; /* 'string' */
    cpy_r_r291 = CPyStatic__strategies___globals;
    cpy_r_r292 = CPyStatics[124]; /* 'BaseEquals' */
    cpy_r_r293 = CPyDict_GetItem(cpy_r_r291, cpy_r_r292);
    if (unlikely(cpy_r_r293 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 222, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r294 = 0 ? Py_True : Py_False;
    PyObject *cpy_r_r295[2] = {cpy_r_r290, cpy_r_r294};
    cpy_r_r296 = (PyObject **)&cpy_r_r295;
    cpy_r_r297 = CPyStatics[231]; /* ('with_sub',) */
    cpy_r_r298 = PyObject_Vectorcall(cpy_r_r293, cpy_r_r296, 1, cpy_r_r297);
    CPy_DECREF(cpy_r_r293);
    if (unlikely(cpy_r_r298 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 222, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r299 = CPyStatic__strategies___string_strategy;
    if (unlikely(cpy_r_r299 == NULL)) {
        goto CPyL164;
    } else
        goto CPyL123;
CPyL121: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"string_strategy\" was not set");
    cpy_r_r300 = 0;
    if (unlikely(!cpy_r_r300)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 223, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL123: ;
    cpy_r_r301 = CPyStatics[159]; /* 'string' */
    cpy_r_r302 = CPyDef__strategies___StrategyRegistry___register_strategy(cpy_r_r288, cpy_r_r298, cpy_r_r299, cpy_r_r301);
    CPy_DECREF(cpy_r_r298);
    if (unlikely(cpy_r_r302 == 2)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 221, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r303 = CPyStatic__strategies___strategy_registry;
    if (likely(cpy_r_r303 != NULL)) goto CPyL127;
    PyErr_SetString(PyExc_NameError, "value for final name \"strategy_registry\" was not set");
    cpy_r_r304 = 0;
    if (unlikely(!cpy_r_r304)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 226, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL127: ;
    cpy_r_r305 = CPyStatic__strategies___globals;
    cpy_r_r306 = CPyStatics[127]; /* 'has_arrlist' */
    cpy_r_r307 = CPyDict_GetItem(cpy_r_r305, cpy_r_r306);
    if (unlikely(cpy_r_r307 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 227, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r308 = CPyStatic__strategies___globals;
    cpy_r_r309 = CPyStatics[160]; /* 'get_array_strategy' */
    cpy_r_r310 = CPyDict_GetItem(cpy_r_r308, cpy_r_r309);
    if (unlikely(cpy_r_r310 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 228, CPyStatic__strategies___globals);
        goto CPyL165;
    }
    cpy_r_r311 = CPyStatics[127]; /* 'has_arrlist' */
    cpy_r_r312 = CPyDef__strategies___StrategyRegistry___register_strategy(cpy_r_r303, cpy_r_r307, cpy_r_r310, cpy_r_r311);
    CPy_DECREF(cpy_r_r307);
    CPy_DECREF(cpy_r_r310);
    if (unlikely(cpy_r_r312 == 2)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 226, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r313 = CPyStatic__strategies___strategy_registry;
    if (likely(cpy_r_r313 != NULL)) goto CPyL133;
    PyErr_SetString(PyExc_NameError, "value for final name \"strategy_registry\" was not set");
    cpy_r_r314 = 0;
    if (unlikely(!cpy_r_r314)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 231, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL133: ;
    cpy_r_r315 = CPyStatic__strategies___globals;
    cpy_r_r316 = CPyStatics[128]; /* 'is_base_tuple' */
    cpy_r_r317 = CPyDict_GetItem(cpy_r_r315, cpy_r_r316);
    if (unlikely(cpy_r_r317 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 232, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r318 = CPyStatic__strategies___globals;
    cpy_r_r319 = CPyStatics[161]; /* 'get_tuple_strategy' */
    cpy_r_r320 = CPyDict_GetItem(cpy_r_r318, cpy_r_r319);
    if (unlikely(cpy_r_r320 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 233, CPyStatic__strategies___globals);
        goto CPyL166;
    }
    cpy_r_r321 = CPyStatics[128]; /* 'is_base_tuple' */
    cpy_r_r322 = CPyDef__strategies___StrategyRegistry___register_strategy(cpy_r_r313, cpy_r_r317, cpy_r_r320, cpy_r_r321);
    CPy_DECREF(cpy_r_r317);
    CPy_DECREF(cpy_r_r320);
    if (unlikely(cpy_r_r322 == 2)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 231, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    cpy_r_r323 = CPyStatic__strategies___strategy_registry;
    if (likely(cpy_r_r323 != NULL)) goto CPyL139;
    PyErr_SetString(PyExc_NameError, "value for final name \"strategy_registry\" was not set");
    cpy_r_r324 = 0;
    if (unlikely(!cpy_r_r324)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 237, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPy_Unreachable();
CPyL139: ;
    cpy_r_r325 = CPyStatics[162]; /* 'get_strategy' */
    cpy_r_r326 = CPyObject_GetAttr(cpy_r_r323, cpy_r_r325);
    if (unlikely(cpy_r_r326 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 237, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    CPyStatic__strategies___get_abi_strategy = cpy_r_r326;
    CPy_INCREF(CPyStatic__strategies___get_abi_strategy);
    cpy_r_r327 = CPyStatic__strategies___globals;
    cpy_r_r328 = CPyStatics[93]; /* 'get_abi_strategy' */
    cpy_r_r329 = CPyDict_SetItem(cpy_r_r327, cpy_r_r328, cpy_r_r326);
    CPy_DECREF(cpy_r_r326);
    cpy_r_r330 = cpy_r_r329 >= 0;
    if (unlikely(!cpy_r_r330)) {
        CPy_AddTraceback("faster_eth_abi/tools/_strategies.py", "<module>", 237, CPyStatic__strategies___globals);
        goto CPyL142;
    }
    return 1;
CPyL142: ;
    cpy_r_r331 = 2;
    return cpy_r_r331;
CPyL143: ;
    CPy_DecRef(cpy_r_r36);
    goto CPyL142;
CPyL144: ;
    CPy_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_r39);
    goto CPyL142;
CPyL145: ;
    CPy_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_r41);
    goto CPyL142;
CPyL146: ;
    CPy_DecRef(cpy_r_r59);
    goto CPyL142;
CPyL147: ;
    CPy_DecRef(cpy_r_r59);
    CPy_DecRef(cpy_r_r64);
    goto CPyL142;
CPyL148: ;
    CPy_DecRef(cpy_r_r81);
    goto CPyL142;
CPyL149: ;
    CPy_DecRef(cpy_r_r95);
    goto CPyL142;
CPyL150: ;
    CPy_DecRef(cpy_r_r102);
    goto CPyL142;
CPyL151: ;
    CPy_DecRef(cpy_r_r102);
    CPy_DecRef(cpy_r_r105);
    goto CPyL142;
CPyL152: ;
    CPy_DecRef(cpy_r_r116);
    goto CPyL142;
CPyL153: ;
    CPy_DecRef(cpy_r_r127);
    goto CPyL142;
CPyL154: ;
    CPy_DecRef(cpy_r_r141);
    goto CPyL142;
CPyL155: ;
    CPy_DecRef(cpy_r_r163);
    goto CPyL142;
CPyL156: ;
    CPy_DecRef(cpy_r_r177);
    goto CPyL142;
CPyL157: ;
    CPy_DecRef(cpy_r_r193);
    goto CPyL66;
CPyL158: ;
    CPy_DecRef(cpy_r_r208);
    goto CPyL75;
CPyL159: ;
    CPy_DecRef(cpy_r_r221);
    goto CPyL142;
CPyL160: ;
    CPy_DecRef(cpy_r_r235);
    goto CPyL142;
CPyL161: ;
    CPy_DecRef(cpy_r_r251);
    goto CPyL142;
CPyL162: ;
    CPy_DecRef(cpy_r_r267);
    goto CPyL105;
CPyL163: ;
    CPy_DecRef(cpy_r_r282);
    goto CPyL142;
CPyL164: ;
    CPy_DecRef(cpy_r_r298);
    goto CPyL121;
CPyL165: ;
    CPy_DecRef(cpy_r_r307);
    goto CPyL142;
CPyL166: ;
    CPy_DecRef(cpy_r_r317);
    goto CPyL142;
}
static int utils_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_faster_eth_abi___utils_internal, "__name__");
    CPyStatic_utils___globals = PyModule_GetDict(CPyModule_faster_eth_abi___utils_internal);
    if (unlikely(CPyStatic_utils___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_utils_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_faster_eth_abi___utils_internal);
    Py_CLEAR(modname);
    return -1;
}
static PyMethodDef utilsmodule_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef utilsmodule = {
    PyModuleDef_HEAD_INIT,
    "faster_eth_abi.utils",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    utilsmodule_methods,
    NULL,
};

PyObject *CPyInit_faster_eth_abi___utils(void)
{
    if (CPyModule_faster_eth_abi___utils_internal) {
        Py_INCREF(CPyModule_faster_eth_abi___utils_internal);
        return CPyModule_faster_eth_abi___utils_internal;
    }
    CPyModule_faster_eth_abi___utils_internal = PyModule_Create(&utilsmodule);
    if (unlikely(CPyModule_faster_eth_abi___utils_internal == NULL))
        goto fail;
    if (utils_exec(CPyModule_faster_eth_abi___utils_internal) != 0)
        goto fail;
    return CPyModule_faster_eth_abi___utils_internal;
    fail:
    return NULL;
}

char CPyDef_utils_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[11]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/__init__.py", "<module>", -1, CPyStatic_utils___globals);
        goto CPyL4;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    return 1;
CPyL4: ;
    cpy_r_r5 = 2;
    return cpy_r_r5;
}

static PyObject *numeric___scale_places_env_setup(PyTypeObject *type);
PyObject *CPyDef_numeric___scale_places_env(void);

static PyObject *
numeric___scale_places_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_numeric___scale_places_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return numeric___scale_places_env_setup(type);
}

static int
numeric___scale_places_env_traverse(faster_eth_abi___utils___numeric___scale_places_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_scaling_factor);
    Py_VISIT(self->_f);
    if (CPyTagged_CheckLong(self->_places)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_places));
    }
    return 0;
}

static int
numeric___scale_places_env_clear(faster_eth_abi___utils___numeric___scale_places_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_scaling_factor);
    Py_CLEAR(self->_f);
    if (CPyTagged_CheckLong(self->_places)) {
        CPyTagged __tmp = self->_places;
        self->_places = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    return 0;
}

static void
numeric___scale_places_env_dealloc(faster_eth_abi___utils___numeric___scale_places_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, numeric___scale_places_env_dealloc)
    numeric___scale_places_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem numeric___scale_places_env_vtable[1];
static bool
CPyDef_numeric___scale_places_env_trait_vtable_setup(void)
{
    CPyVTableItem numeric___scale_places_env_vtable_scratch[] = {
        NULL
    };
    memcpy(numeric___scale_places_env_vtable, numeric___scale_places_env_vtable_scratch, sizeof(numeric___scale_places_env_vtable));
    return 1;
}

static PyMethodDef numeric___scale_places_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_numeric___scale_places_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "scale_places_env",
    .tp_new = numeric___scale_places_env_new,
    .tp_dealloc = (destructor)numeric___scale_places_env_dealloc,
    .tp_traverse = (traverseproc)numeric___scale_places_env_traverse,
    .tp_clear = (inquiry)numeric___scale_places_env_clear,
    .tp_methods = numeric___scale_places_env_methods,
    .tp_basicsize = sizeof(faster_eth_abi___utils___numeric___scale_places_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_numeric___scale_places_env_template = &CPyType_numeric___scale_places_env_template_;

static PyObject *
numeric___scale_places_env_setup(PyTypeObject *type)
{
    faster_eth_abi___utils___numeric___scale_places_envObject *self;
    self = (faster_eth_abi___utils___numeric___scale_places_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = numeric___scale_places_env_vtable;
    self->_places = CPY_INT_TAG;
    return (PyObject *)self;
}

PyObject *CPyDef_numeric___scale_places_env(void)
{
    PyObject *self = numeric___scale_places_env_setup(CPyType_numeric___scale_places_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *CPyDunder___get__numeric___f_scale_places_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef_numeric___f_scale_places_obj_____get__(self, instance, owner);
}
static PyObject *numeric___f_scale_places_obj_setup(PyTypeObject *type);
PyObject *CPyDef_numeric___f_scale_places_obj(void);

static PyObject *
numeric___f_scale_places_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_numeric___f_scale_places_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return numeric___f_scale_places_obj_setup(type);
}

static int
numeric___f_scale_places_obj_traverse(faster_eth_abi___utils___numeric___f_scale_places_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
numeric___f_scale_places_obj_clear(faster_eth_abi___utils___numeric___f_scale_places_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
numeric___f_scale_places_obj_dealloc(faster_eth_abi___utils___numeric___f_scale_places_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, numeric___f_scale_places_obj_dealloc)
    numeric___f_scale_places_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem numeric___f_scale_places_obj_vtable[2];
static bool
CPyDef_numeric___f_scale_places_obj_trait_vtable_setup(void)
{
    CPyVTableItem numeric___f_scale_places_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_numeric___f_scale_places_obj_____call__,
        (CPyVTableItem)CPyDef_numeric___f_scale_places_obj_____get__,
    };
    memcpy(numeric___f_scale_places_obj_vtable, numeric___f_scale_places_obj_vtable_scratch, sizeof(numeric___f_scale_places_obj_vtable));
    return 1;
}

static PyObject *
numeric___f_scale_places_obj_get___3_mypyc_env__(faster_eth_abi___utils___numeric___f_scale_places_objObject *self, void *closure);
static int
numeric___f_scale_places_obj_set___3_mypyc_env__(faster_eth_abi___utils___numeric___f_scale_places_objObject *self, PyObject *value, void *closure);

static PyGetSetDef numeric___f_scale_places_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)numeric___f_scale_places_obj_get___3_mypyc_env__, (setter)numeric___f_scale_places_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef numeric___f_scale_places_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy_numeric___f_scale_places_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy_numeric___f_scale_places_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_numeric___f_scale_places_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "f_scale_places_obj",
    .tp_new = numeric___f_scale_places_obj_new,
    .tp_dealloc = (destructor)numeric___f_scale_places_obj_dealloc,
    .tp_traverse = (traverseproc)numeric___f_scale_places_obj_traverse,
    .tp_clear = (inquiry)numeric___f_scale_places_obj_clear,
    .tp_getset = numeric___f_scale_places_obj_getseters,
    .tp_methods = numeric___f_scale_places_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get__numeric___f_scale_places_obj,
    .tp_basicsize = sizeof(faster_eth_abi___utils___numeric___f_scale_places_objObject),
    .tp_vectorcall_offset = offsetof(faster_eth_abi___utils___numeric___f_scale_places_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL | Py_TPFLAGS_MANAGED_DICT,
};
static PyTypeObject *CPyType_numeric___f_scale_places_obj_template = &CPyType_numeric___f_scale_places_obj_template_;

static PyObject *
numeric___f_scale_places_obj_setup(PyTypeObject *type)
{
    faster_eth_abi___utils___numeric___f_scale_places_objObject *self;
    self = (faster_eth_abi___utils___numeric___f_scale_places_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = numeric___f_scale_places_obj_vtable;
    self->vectorcall = CPyPy_numeric___f_scale_places_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef_numeric___f_scale_places_obj(void)
{
    PyObject *self = numeric___f_scale_places_obj_setup(CPyType_numeric___f_scale_places_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
numeric___f_scale_places_obj_get___3_mypyc_env__(faster_eth_abi___utils___numeric___f_scale_places_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of 'f_scale_places_obj' undefined");
        return NULL;
    }
    CPy_INCREF_NO_IMM(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
numeric___f_scale_places_obj_set___3_mypyc_env__(faster_eth_abi___utils___numeric___f_scale_places_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'f_scale_places_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType_numeric___scale_places_env))
        tmp = value;
    else {
        CPy_TypeError("faster_eth_abi.utils.numeric.scale_places_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF_NO_IMM(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}
static int numeric_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_faster_eth_abi___utils___numeric_internal, "__name__");
    CPyStatic_numeric___globals = PyModule_GetDict(CPyModule_faster_eth_abi___utils___numeric_internal);
    if (unlikely(CPyStatic_numeric___globals == NULL))
        goto fail;
    CPyType_numeric___scale_places_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_numeric___scale_places_env_template, NULL, modname);
    if (unlikely(!CPyType_numeric___scale_places_env))
        goto fail;
    CPyType_numeric___f_scale_places_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_numeric___f_scale_places_obj_template, NULL, modname);
    if (unlikely(!CPyType_numeric___f_scale_places_obj))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_numeric_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_faster_eth_abi___utils___numeric_internal);
    Py_CLEAR(modname);
    CPy_XDECREF(CPyStatic_numeric___abi_decimal_context);
    CPyStatic_numeric___abi_decimal_context = NULL;
    CPy_XDECREF(CPyStatic_numeric___ZERO);
    CPyStatic_numeric___ZERO = NULL;
    CPy_XDECREF(CPyStatic_numeric___TEN);
    CPyStatic_numeric___TEN = NULL;
    CPy_XDECREF(CPyStatic_numeric___Decimal);
    CPyStatic_numeric___Decimal = NULL;
    Py_CLEAR(CPyType_numeric___scale_places_env);
    Py_CLEAR(CPyType_numeric___f_scale_places_obj);
    return -1;
}
static PyMethodDef numericmodule_methods[] = {
    {"ceil32", (PyCFunction)CPyPy_numeric___ceil32, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"compute_unsigned_integer_bounds", (PyCFunction)CPyPy_numeric___compute_unsigned_integer_bounds, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"compute_signed_integer_bounds", (PyCFunction)CPyPy_numeric___compute_signed_integer_bounds, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"compute_unsigned_fixed_bounds", (PyCFunction)CPyPy_numeric___compute_unsigned_fixed_bounds, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"compute_signed_fixed_bounds", (PyCFunction)CPyPy_numeric___compute_signed_fixed_bounds, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"scale_places", (PyCFunction)CPyPy_numeric___scale_places, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef numericmodule = {
    PyModuleDef_HEAD_INIT,
    "faster_eth_abi.utils.numeric",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    numericmodule_methods,
    NULL,
};

PyObject *CPyInit_faster_eth_abi___utils___numeric(void)
{
    if (CPyModule_faster_eth_abi___utils___numeric_internal) {
        Py_INCREF(CPyModule_faster_eth_abi___utils___numeric_internal);
        return CPyModule_faster_eth_abi___utils___numeric_internal;
    }
    CPyModule_faster_eth_abi___utils___numeric_internal = PyModule_Create(&numericmodule);
    if (unlikely(CPyModule_faster_eth_abi___utils___numeric_internal == NULL))
        goto fail;
    if (numeric_exec(CPyModule_faster_eth_abi___utils___numeric_internal) != 0)
        goto fail;
    return CPyModule_faster_eth_abi___utils___numeric_internal;
    fail:
    return NULL;
}

CPyTagged CPyDef_numeric___ceil32(CPyTagged cpy_r_x) {
    CPyTagged cpy_r_r0;
    char cpy_r_r1;
    CPyTagged cpy_r_r2;
    CPyTagged cpy_r_r3;
    CPyTagged cpy_r_r4;
    CPyTagged cpy_r_r5;
    CPyTagged cpy_r_r6;
    cpy_r_r0 = CPyTagged_Remainder(cpy_r_x, 64);
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "ceil32", 19, CPyStatic_numeric___globals);
        goto CPyL6;
    }
    cpy_r_r1 = cpy_r_r0 == 0;
    CPyTagged_DECREF(cpy_r_r0);
    if (!cpy_r_r1) goto CPyL3;
    CPyTagged_INCREF(cpy_r_x);
    cpy_r_r2 = cpy_r_x;
    goto CPyL5;
CPyL3: ;
    cpy_r_r3 = CPyTagged_Add(cpy_r_x, 64);
    cpy_r_r4 = CPyTagged_Remainder(cpy_r_x, 64);
    if (unlikely(cpy_r_r4 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "ceil32", 19, CPyStatic_numeric___globals);
        goto CPyL7;
    }
    cpy_r_r5 = CPyTagged_Subtract(cpy_r_r3, cpy_r_r4);
    CPyTagged_DECREF(cpy_r_r3);
    CPyTagged_DECREF(cpy_r_r4);
    cpy_r_r2 = cpy_r_r5;
CPyL5: ;
    return cpy_r_r2;
CPyL6: ;
    cpy_r_r6 = CPY_INT_TAG;
    return cpy_r_r6;
CPyL7: ;
    CPyTagged_DecRef(cpy_r_r3);
    goto CPyL6;
}

PyObject *CPyPy_numeric___ceil32(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"x", 0};
    static CPyArg_Parser parser = {"O:ceil32", kwlist, 0};
    PyObject *obj_x;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_x)) {
        return NULL;
    }
    CPyTagged arg_x;
    if (likely(PyLong_Check(obj_x)))
        arg_x = CPyTagged_BorrowFromObject(obj_x);
    else {
        CPy_TypeError("int", obj_x); goto fail;
    }
    CPyTagged retval = CPyDef_numeric___ceil32(arg_x);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "ceil32", 18, CPyStatic_numeric___globals);
    return NULL;
}

tuple_T2II CPyDef_numeric___compute_unsigned_integer_bounds(CPyTagged cpy_r_num_bits) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    tuple_T2IO cpy_r_r5;
    CPyTagged cpy_r_r6;
    tuple_T2II cpy_r_r7;
    tuple_T2II cpy_r_r8;
    cpy_r_r0 = CPyStatics[197]; /* 2 */
    CPyTagged_INCREF(cpy_r_num_bits);
    cpy_r_r1 = CPyTagged_StealAsObject(cpy_r_num_bits);
    cpy_r_r2 = CPyNumber_Power(cpy_r_r0, cpy_r_r1);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_integer_bounds", 25, CPyStatic_numeric___globals);
        goto CPyL4;
    }
    cpy_r_r3 = CPyStatics[198]; /* 1 */
    cpy_r_r4 = PyNumber_Subtract(cpy_r_r2, cpy_r_r3);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_integer_bounds", 25, CPyStatic_numeric___globals);
        goto CPyL4;
    }
    CPy_INCREF(cpy_r_r4);
    cpy_r_r5.f0 = 0;
    cpy_r_r5.f1 = cpy_r_r4;
    CPyTagged_DECREF(cpy_r_r5.f0);
    CPy_DECREF(cpy_r_r5.f1);
    if (likely(PyLong_Check(cpy_r_r4)))
        cpy_r_r6 = CPyTagged_FromObject(cpy_r_r4);
    else {
        CPy_TypeError("int", cpy_r_r4); cpy_r_r6 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r6 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_integer_bounds", 23, CPyStatic_numeric___globals);
        goto CPyL4;
    }
    cpy_r_r7.f0 = 0;
    cpy_r_r7.f1 = cpy_r_r6;
    return cpy_r_r7;
CPyL4: ;
    tuple_T2II __tmp17 = { CPY_INT_TAG, CPY_INT_TAG };
    cpy_r_r8 = __tmp17;
    return cpy_r_r8;
}

PyObject *CPyPy_numeric___compute_unsigned_integer_bounds(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"num_bits", 0};
    static CPyArg_Parser parser = {"O:compute_unsigned_integer_bounds", kwlist, 0};
    PyObject *obj_num_bits;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_num_bits)) {
        return NULL;
    }
    CPyTagged arg_num_bits;
    if (likely(PyLong_Check(obj_num_bits)))
        arg_num_bits = CPyTagged_BorrowFromObject(obj_num_bits);
    else {
        CPy_TypeError("int", obj_num_bits); goto fail;
    }
    tuple_T2II retval = CPyDef_numeric___compute_unsigned_integer_bounds(arg_num_bits);
    if (retval.f0 == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = PyTuple_New(2);
    if (unlikely(retbox == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp18 = CPyTagged_StealAsObject(retval.f0);
    PyTuple_SET_ITEM(retbox, 0, __tmp18);
    PyObject *__tmp19 = CPyTagged_StealAsObject(retval.f1);
    PyTuple_SET_ITEM(retbox, 1, __tmp19);
    return retbox;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_integer_bounds", 22, CPyStatic_numeric___globals);
    return NULL;
}

tuple_T2II CPyDef_numeric___compute_signed_integer_bounds(CPyTagged cpy_r_num_bits) {
    CPyTagged cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    CPyTagged cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    tuple_T2OO cpy_r_r12;
    CPyTagged cpy_r_r13;
    CPyTagged cpy_r_r14;
    tuple_T2II cpy_r_r15;
    tuple_T2II cpy_r_r16;
    cpy_r_r0 = CPyTagged_Subtract(cpy_r_num_bits, 2);
    cpy_r_r1 = CPyStatics[197]; /* 2 */
    cpy_r_r2 = CPyTagged_StealAsObject(cpy_r_r0);
    cpy_r_r3 = CPyNumber_Power(cpy_r_r1, cpy_r_r2);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_integer_bounds", 31, CPyStatic_numeric___globals);
        goto CPyL7;
    }
    cpy_r_r4 = CPyStatics[199]; /* -1 */
    cpy_r_r5 = PyNumber_Multiply(cpy_r_r4, cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_integer_bounds", 31, CPyStatic_numeric___globals);
        goto CPyL7;
    }
    cpy_r_r6 = CPyTagged_Subtract(cpy_r_num_bits, 2);
    cpy_r_r7 = CPyStatics[197]; /* 2 */
    cpy_r_r8 = CPyTagged_StealAsObject(cpy_r_r6);
    cpy_r_r9 = CPyNumber_Power(cpy_r_r7, cpy_r_r8);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_integer_bounds", 32, CPyStatic_numeric___globals);
        goto CPyL8;
    }
    cpy_r_r10 = CPyStatics[198]; /* 1 */
    cpy_r_r11 = PyNumber_Subtract(cpy_r_r9, cpy_r_r10);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_integer_bounds", 32, CPyStatic_numeric___globals);
        goto CPyL8;
    }
    CPy_INCREF(cpy_r_r5);
    CPy_INCREF(cpy_r_r11);
    cpy_r_r12.f0 = cpy_r_r5;
    cpy_r_r12.f1 = cpy_r_r11;
    CPy_DECREF(cpy_r_r12.f0);
    CPy_DECREF(cpy_r_r12.f1);
    if (likely(PyLong_Check(cpy_r_r5)))
        cpy_r_r13 = CPyTagged_FromObject(cpy_r_r5);
    else {
        CPy_TypeError("int", cpy_r_r5); cpy_r_r13 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r13 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_integer_bounds", 30, CPyStatic_numeric___globals);
        goto CPyL9;
    }
    if (likely(PyLong_Check(cpy_r_r11)))
        cpy_r_r14 = CPyTagged_FromObject(cpy_r_r11);
    else {
        CPy_TypeError("int", cpy_r_r11); cpy_r_r14 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r14 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_integer_bounds", 30, CPyStatic_numeric___globals);
        goto CPyL10;
    }
    cpy_r_r15.f0 = cpy_r_r13;
    cpy_r_r15.f1 = cpy_r_r14;
    return cpy_r_r15;
CPyL7: ;
    tuple_T2II __tmp20 = { CPY_INT_TAG, CPY_INT_TAG };
    cpy_r_r16 = __tmp20;
    return cpy_r_r16;
CPyL8: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL7;
CPyL9: ;
    CPy_DecRef(cpy_r_r11);
    goto CPyL7;
CPyL10: ;
    CPyTagged_DecRef(cpy_r_r13);
    goto CPyL7;
}

PyObject *CPyPy_numeric___compute_signed_integer_bounds(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"num_bits", 0};
    static CPyArg_Parser parser = {"O:compute_signed_integer_bounds", kwlist, 0};
    PyObject *obj_num_bits;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_num_bits)) {
        return NULL;
    }
    CPyTagged arg_num_bits;
    if (likely(PyLong_Check(obj_num_bits)))
        arg_num_bits = CPyTagged_BorrowFromObject(obj_num_bits);
    else {
        CPy_TypeError("int", obj_num_bits); goto fail;
    }
    tuple_T2II retval = CPyDef_numeric___compute_signed_integer_bounds(arg_num_bits);
    if (retval.f0 == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = PyTuple_New(2);
    if (unlikely(retbox == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp21 = CPyTagged_StealAsObject(retval.f0);
    PyTuple_SET_ITEM(retbox, 0, __tmp21);
    PyObject *__tmp22 = CPyTagged_StealAsObject(retval.f1);
    PyTuple_SET_ITEM(retbox, 1, __tmp22);
    return retbox;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_integer_bounds", 29, CPyStatic_numeric___globals);
    return NULL;
}

tuple_T2OO CPyDef_numeric___compute_unsigned_fixed_bounds(CPyTagged cpy_r_num_bits, CPyTagged cpy_r_frac_places) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_upper;
    tuple_T2II cpy_r_r1;
    CPyTagged cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject **cpy_r_r17;
    PyObject *cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject **cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    char cpy_r_r27;
    CPyTagged cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    tuple_T3OOO cpy_r_r32;
    tuple_T3OOO cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject **cpy_r_r38;
    PyObject *cpy_r_r39;
    int32_t cpy_r_r40;
    char cpy_r_r41;
    char cpy_r_r42;
    char cpy_r_r43;
    tuple_T3OOO cpy_r_r44;
    tuple_T3OOO cpy_r_r45;
    tuple_T3OOO cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject **cpy_r_r49;
    PyObject *cpy_r_r50;
    char cpy_r_r51;
    PyObject *cpy_r_r52;
    char cpy_r_r53;
    char cpy_r_r54;
    tuple_T2OO cpy_r_r55;
    tuple_T2OO cpy_r_r56;
    cpy_r_r0 = NULL;
    cpy_r_upper = cpy_r_r0;
    cpy_r_r1 = CPyDef_numeric___compute_unsigned_integer_bounds(cpy_r_num_bits);
    if (unlikely(cpy_r_r1.f0 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 40, CPyStatic_numeric___globals);
        goto CPyL48;
    }
    cpy_r_r2 = cpy_r_r1.f1;
    CPyTagged_INCREF(cpy_r_r2);
    CPyTagged_DECREF(cpy_r_r1.f0);
    CPyTagged_DECREF(cpy_r_r1.f1);
    cpy_r_r3 = CPyStatic_numeric___abi_decimal_context;
    if (unlikely(cpy_r_r3 == NULL)) {
        goto CPyL49;
    } else
        goto CPyL4;
CPyL2: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"abi_decimal_context\" was not set");
    cpy_r_r4 = 0;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 42, CPyStatic_numeric___globals);
        goto CPyL47;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r5 = CPyModule_decimal;
    cpy_r_r6 = CPyStatics[163]; /* 'localcontext' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 42, CPyStatic_numeric___globals);
        goto CPyL50;
    }
    PyObject *cpy_r_r8[1] = {cpy_r_r3};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_Vectorcall(cpy_r_r7, cpy_r_r9, 1, 0);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 42, CPyStatic_numeric___globals);
        goto CPyL50;
    }
    cpy_r_r11 = PyObject_Type(cpy_r_r10);
    cpy_r_r12 = CPyStatics[164]; /* '__exit__' */
    cpy_r_r13 = CPyObject_GetAttr(cpy_r_r11, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 42, CPyStatic_numeric___globals);
        goto CPyL51;
    }
    cpy_r_r14 = CPyStatics[165]; /* '__enter__' */
    cpy_r_r15 = CPyObject_GetAttr(cpy_r_r11, cpy_r_r14);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 42, CPyStatic_numeric___globals);
        goto CPyL52;
    }
    PyObject *cpy_r_r16[1] = {cpy_r_r10};
    cpy_r_r17 = (PyObject **)&cpy_r_r16;
    cpy_r_r18 = PyObject_Vectorcall(cpy_r_r15, cpy_r_r17, 1, 0);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 42, CPyStatic_numeric___globals);
        goto CPyL52;
    } else
        goto CPyL53;
CPyL9: ;
    cpy_r_r19 = 1;
    cpy_r_r20 = CPyStatic_numeric___Decimal;
    if (unlikely(cpy_r_r20 == NULL)) {
        goto CPyL54;
    } else
        goto CPyL13;
CPyL11: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"Decimal\" was not set");
    cpy_r_r21 = 0;
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 43, CPyStatic_numeric___globals);
        goto CPyL20;
    } else
        goto CPyL55;
CPyL12: ;
    CPy_Unreachable();
CPyL13: ;
    cpy_r_r22 = CPyTagged_StealAsObject(cpy_r_r2);
    PyObject *cpy_r_r23[1] = {cpy_r_r22};
    cpy_r_r24 = (PyObject **)&cpy_r_r23;
    cpy_r_r25 = PyObject_Vectorcall(cpy_r_r20, cpy_r_r24, 1, 0);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 43, CPyStatic_numeric___globals);
        goto CPyL56;
    }
    CPy_DECREF(cpy_r_r22);
    cpy_r_r26 = CPyStatic_numeric___TEN;
    if (unlikely(cpy_r_r26 == NULL)) {
        goto CPyL57;
    } else
        goto CPyL17;
CPyL15: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"TEN\" was not set");
    cpy_r_r27 = 0;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 43, CPyStatic_numeric___globals);
        goto CPyL20;
    } else
        goto CPyL58;
CPyL16: ;
    CPy_Unreachable();
CPyL17: ;
    cpy_r_r28 = CPyTagged_Negate(cpy_r_frac_places);
    cpy_r_r29 = CPyTagged_StealAsObject(cpy_r_r28);
    cpy_r_r30 = CPyNumber_Power(cpy_r_r26, cpy_r_r29);
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 43, CPyStatic_numeric___globals);
        goto CPyL59;
    }
    cpy_r_r31 = PyNumber_Multiply(cpy_r_r25, cpy_r_r30);
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 43, CPyStatic_numeric___globals);
        goto CPyL20;
    } else
        goto CPyL60;
CPyL19: ;
    cpy_r_upper = cpy_r_r31;
    goto CPyL28;
CPyL20: ;
    cpy_r_r32 = CPy_CatchError();
    cpy_r_r19 = 0;
    cpy_r_r33 = CPy_GetExcInfo();
    cpy_r_r34 = cpy_r_r33.f0;
    CPy_INCREF(cpy_r_r34);
    cpy_r_r35 = cpy_r_r33.f1;
    CPy_INCREF(cpy_r_r35);
    cpy_r_r36 = cpy_r_r33.f2;
    CPy_INCREF(cpy_r_r36);
    CPy_DecRef(cpy_r_r33.f0);
    CPy_DecRef(cpy_r_r33.f1);
    CPy_DecRef(cpy_r_r33.f2);
    PyObject *cpy_r_r37[4] = {cpy_r_r10, cpy_r_r34, cpy_r_r35, cpy_r_r36};
    cpy_r_r38 = (PyObject **)&cpy_r_r37;
    cpy_r_r39 = PyObject_Vectorcall(cpy_r_r13, cpy_r_r38, 4, 0);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 42, CPyStatic_numeric___globals);
        goto CPyL61;
    }
    CPy_DecRef(cpy_r_r34);
    CPy_DecRef(cpy_r_r35);
    CPy_DecRef(cpy_r_r36);
    cpy_r_r40 = PyObject_IsTrue(cpy_r_r39);
    CPy_DecRef(cpy_r_r39);
    cpy_r_r41 = cpy_r_r40 >= 0;
    if (unlikely(!cpy_r_r41)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 42, CPyStatic_numeric___globals);
        goto CPyL26;
    }
    cpy_r_r42 = cpy_r_r40;
    if (cpy_r_r42) goto CPyL25;
    CPy_Reraise();
    if (!0) {
        goto CPyL26;
    } else
        goto CPyL62;
CPyL24: ;
    CPy_Unreachable();
CPyL25: ;
    CPy_RestoreExcInfo(cpy_r_r32);
    CPy_DecRef(cpy_r_r32.f0);
    CPy_DecRef(cpy_r_r32.f1);
    CPy_DecRef(cpy_r_r32.f2);
    goto CPyL28;
CPyL26: ;
    CPy_RestoreExcInfo(cpy_r_r32);
    CPy_DecRef(cpy_r_r32.f0);
    CPy_DecRef(cpy_r_r32.f1);
    CPy_DecRef(cpy_r_r32.f2);
    cpy_r_r43 = CPy_KeepPropagating();
    if (!cpy_r_r43) {
        goto CPyL29;
    } else
        goto CPyL63;
CPyL27: ;
    CPy_Unreachable();
CPyL28: ;
    tuple_T3OOO __tmp23 = { NULL, NULL, NULL };
    cpy_r_r44 = __tmp23;
    cpy_r_r45 = cpy_r_r44;
    goto CPyL30;
CPyL29: ;
    cpy_r_r46 = CPy_CatchError();
    cpy_r_r45 = cpy_r_r46;
CPyL30: ;
    if (!cpy_r_r19) goto CPyL64;
    cpy_r_r47 = (PyObject *)&_Py_NoneStruct;
    PyObject *cpy_r_r48[4] = {cpy_r_r10, cpy_r_r47, cpy_r_r47, cpy_r_r47};
    cpy_r_r49 = (PyObject **)&cpy_r_r48;
    cpy_r_r50 = PyObject_Vectorcall(cpy_r_r13, cpy_r_r49, 4, 0);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 42, CPyStatic_numeric___globals);
        goto CPyL65;
    } else
        goto CPyL66;
CPyL32: ;
    CPy_DECREF(cpy_r_r10);
CPyL33: ;
    if (cpy_r_r45.f0 == NULL) {
        goto CPyL40;
    } else
        goto CPyL67;
CPyL34: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL36;
    } else
        goto CPyL68;
CPyL35: ;
    CPy_Unreachable();
CPyL36: ;
    if (cpy_r_r45.f0 == NULL) goto CPyL38;
    CPy_RestoreExcInfo(cpy_r_r45);
    CPy_XDECREF(cpy_r_r45.f0);
    CPy_XDECREF(cpy_r_r45.f1);
    CPy_XDECREF(cpy_r_r45.f2);
CPyL38: ;
    cpy_r_r51 = CPy_KeepPropagating();
    if (!cpy_r_r51) goto CPyL47;
    CPy_Unreachable();
CPyL40: ;
    cpy_r_r52 = CPyStatic_numeric___ZERO;
    if (unlikely(cpy_r_r52 == NULL)) {
        goto CPyL69;
    } else
        goto CPyL43;
CPyL41: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"ZERO\" was not set");
    cpy_r_r53 = 0;
    if (unlikely(!cpy_r_r53)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 45, CPyStatic_numeric___globals);
        goto CPyL47;
    }
    CPy_Unreachable();
CPyL43: ;
    if (cpy_r_upper != NULL) goto CPyL46;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"upper\" referenced before assignment");
    cpy_r_r54 = 0;
    if (unlikely(!cpy_r_r54)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 45, CPyStatic_numeric___globals);
        goto CPyL47;
    }
    CPy_Unreachable();
CPyL46: ;
    CPy_INCREF(cpy_r_r52);
    cpy_r_r55.f0 = cpy_r_r52;
    cpy_r_r55.f1 = cpy_r_upper;
    return cpy_r_r55;
CPyL47: ;
    tuple_T2OO __tmp24 = { NULL, NULL };
    cpy_r_r56 = __tmp24;
    return cpy_r_r56;
CPyL48: ;
    CPy_XDecRef(cpy_r_upper);
    goto CPyL47;
CPyL49: ;
    CPy_XDecRef(cpy_r_upper);
    CPyTagged_DecRef(cpy_r_r2);
    goto CPyL2;
CPyL50: ;
    CPy_XDecRef(cpy_r_upper);
    CPyTagged_DecRef(cpy_r_r2);
    goto CPyL47;
CPyL51: ;
    CPy_XDecRef(cpy_r_upper);
    CPyTagged_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r11);
    goto CPyL47;
CPyL52: ;
    CPy_XDecRef(cpy_r_upper);
    CPyTagged_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r13);
    goto CPyL47;
CPyL53: ;
    CPy_DECREF(cpy_r_r18);
    goto CPyL9;
CPyL54: ;
    CPyTagged_DecRef(cpy_r_r2);
    goto CPyL11;
CPyL55: ;
    CPy_XDecRef(cpy_r_upper);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r13);
    goto CPyL12;
CPyL56: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL20;
CPyL57: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL15;
CPyL58: ;
    CPy_XDecRef(cpy_r_upper);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r13);
    goto CPyL16;
CPyL59: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL20;
CPyL60: ;
    CPy_XDECREF(cpy_r_upper);
    goto CPyL19;
CPyL61: ;
    CPy_DecRef(cpy_r_r34);
    CPy_DecRef(cpy_r_r35);
    CPy_DecRef(cpy_r_r36);
    goto CPyL26;
CPyL62: ;
    CPy_XDecRef(cpy_r_upper);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r32.f0);
    CPy_DecRef(cpy_r_r32.f1);
    CPy_DecRef(cpy_r_r32.f2);
    goto CPyL24;
CPyL63: ;
    CPy_XDecRef(cpy_r_upper);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r13);
    goto CPyL27;
CPyL64: ;
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r13);
    goto CPyL33;
CPyL65: ;
    CPy_XDecRef(cpy_r_upper);
    CPy_DecRef(cpy_r_r10);
    goto CPyL36;
CPyL66: ;
    CPy_DECREF(cpy_r_r50);
    goto CPyL32;
CPyL67: ;
    CPy_XDECREF(cpy_r_upper);
    goto CPyL34;
CPyL68: ;
    CPy_XDECREF(cpy_r_r45.f0);
    CPy_XDECREF(cpy_r_r45.f1);
    CPy_XDECREF(cpy_r_r45.f2);
    goto CPyL35;
CPyL69: ;
    CPy_XDecRef(cpy_r_upper);
    goto CPyL41;
}

PyObject *CPyPy_numeric___compute_unsigned_fixed_bounds(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"num_bits", "frac_places", 0};
    static CPyArg_Parser parser = {"OO:compute_unsigned_fixed_bounds", kwlist, 0};
    PyObject *obj_num_bits;
    PyObject *obj_frac_places;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_num_bits, &obj_frac_places)) {
        return NULL;
    }
    CPyTagged arg_num_bits;
    if (likely(PyLong_Check(obj_num_bits)))
        arg_num_bits = CPyTagged_BorrowFromObject(obj_num_bits);
    else {
        CPy_TypeError("int", obj_num_bits); goto fail;
    }
    CPyTagged arg_frac_places;
    if (likely(PyLong_Check(obj_frac_places)))
        arg_frac_places = CPyTagged_BorrowFromObject(obj_frac_places);
    else {
        CPy_TypeError("int", obj_frac_places); goto fail;
    }
    tuple_T2OO retval = CPyDef_numeric___compute_unsigned_fixed_bounds(arg_num_bits, arg_frac_places);
    if (retval.f0 == NULL) {
        return NULL;
    }
    PyObject *retbox = PyTuple_New(2);
    if (unlikely(retbox == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp25 = retval.f0;
    PyTuple_SET_ITEM(retbox, 0, __tmp25);
    PyObject *__tmp26 = retval.f1;
    PyTuple_SET_ITEM(retbox, 1, __tmp26);
    return retbox;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_unsigned_fixed_bounds", 36, CPyStatic_numeric___globals);
    return NULL;
}

tuple_T2OO CPyDef_numeric___compute_signed_fixed_bounds(CPyTagged cpy_r_num_bits, CPyTagged cpy_r_frac_places) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_lower;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_upper;
    tuple_T2II cpy_r_r2;
    CPyTagged cpy_r_r3;
    CPyTagged cpy_r_r4;
    CPyTagged cpy_r_r5;
    CPyTagged cpy_r_r6;
    PyObject *cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    char cpy_r_r25;
    CPyTagged cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    char cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject **cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject **cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    tuple_T3OOO cpy_r_r43;
    tuple_T3OOO cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject **cpy_r_r49;
    PyObject *cpy_r_r50;
    int32_t cpy_r_r51;
    char cpy_r_r52;
    char cpy_r_r53;
    char cpy_r_r54;
    tuple_T3OOO cpy_r_r55;
    tuple_T3OOO cpy_r_r56;
    tuple_T3OOO cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject **cpy_r_r60;
    PyObject *cpy_r_r61;
    char cpy_r_r62;
    char cpy_r_r63;
    char cpy_r_r64;
    tuple_T2OO cpy_r_r65;
    tuple_T2OO cpy_r_r66;
    cpy_r_r0 = NULL;
    cpy_r_lower = cpy_r_r0;
    cpy_r_r1 = NULL;
    cpy_r_upper = cpy_r_r1;
    cpy_r_r2 = CPyDef_numeric___compute_signed_integer_bounds(cpy_r_num_bits);
    if (unlikely(cpy_r_r2.f0 == CPY_INT_TAG)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 52, CPyStatic_numeric___globals);
        goto CPyL53;
    }
    cpy_r_r3 = cpy_r_r2.f0;
    cpy_r_r4 = cpy_r_r2.f1;
    cpy_r_r5 = cpy_r_r3;
    cpy_r_r6 = cpy_r_r4;
    cpy_r_r7 = CPyStatic_numeric___abi_decimal_context;
    if (unlikely(cpy_r_r7 == NULL)) {
        goto CPyL54;
    } else
        goto CPyL4;
CPyL2: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"abi_decimal_context\" was not set");
    cpy_r_r8 = 0;
    if (unlikely(!cpy_r_r8)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 54, CPyStatic_numeric___globals);
        goto CPyL52;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r9 = CPyModule_decimal;
    cpy_r_r10 = CPyStatics[163]; /* 'localcontext' */
    cpy_r_r11 = CPyObject_GetAttr(cpy_r_r9, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 54, CPyStatic_numeric___globals);
        goto CPyL55;
    }
    PyObject *cpy_r_r12[1] = {cpy_r_r7};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = PyObject_Vectorcall(cpy_r_r11, cpy_r_r13, 1, 0);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 54, CPyStatic_numeric___globals);
        goto CPyL55;
    }
    cpy_r_r15 = PyObject_Type(cpy_r_r14);
    cpy_r_r16 = CPyStatics[164]; /* '__exit__' */
    cpy_r_r17 = CPyObject_GetAttr(cpy_r_r15, cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 54, CPyStatic_numeric___globals);
        goto CPyL56;
    }
    cpy_r_r18 = CPyStatics[165]; /* '__enter__' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r15, cpy_r_r18);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 54, CPyStatic_numeric___globals);
        goto CPyL57;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r14};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 54, CPyStatic_numeric___globals);
        goto CPyL57;
    } else
        goto CPyL58;
CPyL9: ;
    cpy_r_r23 = 1;
    cpy_r_r24 = CPyStatic_numeric___TEN;
    if (unlikely(cpy_r_r24 == NULL)) {
        goto CPyL59;
    } else
        goto CPyL13;
CPyL11: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"TEN\" was not set");
    cpy_r_r25 = 0;
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 55, CPyStatic_numeric___globals);
        goto CPyL25;
    } else
        goto CPyL60;
CPyL12: ;
    CPy_Unreachable();
CPyL13: ;
    cpy_r_r26 = CPyTagged_Negate(cpy_r_frac_places);
    cpy_r_r27 = CPyTagged_StealAsObject(cpy_r_r26);
    cpy_r_r28 = CPyNumber_Power(cpy_r_r24, cpy_r_r27);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 55, CPyStatic_numeric___globals);
        goto CPyL61;
    }
    cpy_r_r29 = CPyStatic_numeric___Decimal;
    if (unlikely(cpy_r_r29 == NULL)) {
        goto CPyL62;
    } else
        goto CPyL17;
CPyL15: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"Decimal\" was not set");
    cpy_r_r30 = 0;
    if (unlikely(!cpy_r_r30)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 56, CPyStatic_numeric___globals);
        goto CPyL25;
    } else
        goto CPyL63;
CPyL16: ;
    CPy_Unreachable();
CPyL17: ;
    cpy_r_r31 = CPyTagged_StealAsObject(cpy_r_r5);
    PyObject *cpy_r_r32[1] = {cpy_r_r31};
    cpy_r_r33 = (PyObject **)&cpy_r_r32;
    cpy_r_r34 = PyObject_Vectorcall(cpy_r_r29, cpy_r_r33, 1, 0);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 56, CPyStatic_numeric___globals);
        goto CPyL64;
    }
    CPy_DECREF(cpy_r_r31);
    cpy_r_r35 = PyNumber_Multiply(cpy_r_r34, cpy_r_r28);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 56, CPyStatic_numeric___globals);
        goto CPyL65;
    } else
        goto CPyL66;
CPyL19: ;
    cpy_r_lower = cpy_r_r35;
    cpy_r_r36 = CPyStatic_numeric___Decimal;
    if (unlikely(cpy_r_r36 == NULL)) {
        goto CPyL67;
    } else
        goto CPyL22;
CPyL20: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"Decimal\" was not set");
    cpy_r_r37 = 0;
    if (unlikely(!cpy_r_r37)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 57, CPyStatic_numeric___globals);
        goto CPyL25;
    } else
        goto CPyL68;
CPyL21: ;
    CPy_Unreachable();
CPyL22: ;
    cpy_r_r38 = CPyTagged_StealAsObject(cpy_r_r6);
    PyObject *cpy_r_r39[1] = {cpy_r_r38};
    cpy_r_r40 = (PyObject **)&cpy_r_r39;
    cpy_r_r41 = PyObject_Vectorcall(cpy_r_r36, cpy_r_r40, 1, 0);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 57, CPyStatic_numeric___globals);
        goto CPyL69;
    }
    CPy_DECREF(cpy_r_r38);
    cpy_r_r42 = PyNumber_Multiply(cpy_r_r41, cpy_r_r28);
    CPy_DECREF(cpy_r_r41);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 57, CPyStatic_numeric___globals);
        goto CPyL25;
    } else
        goto CPyL70;
CPyL24: ;
    cpy_r_upper = cpy_r_r42;
    goto CPyL33;
CPyL25: ;
    cpy_r_r43 = CPy_CatchError();
    cpy_r_r23 = 0;
    cpy_r_r44 = CPy_GetExcInfo();
    cpy_r_r45 = cpy_r_r44.f0;
    CPy_INCREF(cpy_r_r45);
    cpy_r_r46 = cpy_r_r44.f1;
    CPy_INCREF(cpy_r_r46);
    cpy_r_r47 = cpy_r_r44.f2;
    CPy_INCREF(cpy_r_r47);
    CPy_DecRef(cpy_r_r44.f0);
    CPy_DecRef(cpy_r_r44.f1);
    CPy_DecRef(cpy_r_r44.f2);
    PyObject *cpy_r_r48[4] = {cpy_r_r14, cpy_r_r45, cpy_r_r46, cpy_r_r47};
    cpy_r_r49 = (PyObject **)&cpy_r_r48;
    cpy_r_r50 = PyObject_Vectorcall(cpy_r_r17, cpy_r_r49, 4, 0);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 54, CPyStatic_numeric___globals);
        goto CPyL71;
    }
    CPy_DecRef(cpy_r_r45);
    CPy_DecRef(cpy_r_r46);
    CPy_DecRef(cpy_r_r47);
    cpy_r_r51 = PyObject_IsTrue(cpy_r_r50);
    CPy_DecRef(cpy_r_r50);
    cpy_r_r52 = cpy_r_r51 >= 0;
    if (unlikely(!cpy_r_r52)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 54, CPyStatic_numeric___globals);
        goto CPyL31;
    }
    cpy_r_r53 = cpy_r_r51;
    if (cpy_r_r53) goto CPyL30;
    CPy_Reraise();
    if (!0) {
        goto CPyL31;
    } else
        goto CPyL72;
CPyL29: ;
    CPy_Unreachable();
CPyL30: ;
    CPy_RestoreExcInfo(cpy_r_r43);
    CPy_DecRef(cpy_r_r43.f0);
    CPy_DecRef(cpy_r_r43.f1);
    CPy_DecRef(cpy_r_r43.f2);
    goto CPyL33;
CPyL31: ;
    CPy_RestoreExcInfo(cpy_r_r43);
    CPy_DecRef(cpy_r_r43.f0);
    CPy_DecRef(cpy_r_r43.f1);
    CPy_DecRef(cpy_r_r43.f2);
    cpy_r_r54 = CPy_KeepPropagating();
    if (!cpy_r_r54) {
        goto CPyL34;
    } else
        goto CPyL73;
CPyL32: ;
    CPy_Unreachable();
CPyL33: ;
    tuple_T3OOO __tmp27 = { NULL, NULL, NULL };
    cpy_r_r55 = __tmp27;
    cpy_r_r56 = cpy_r_r55;
    goto CPyL35;
CPyL34: ;
    cpy_r_r57 = CPy_CatchError();
    cpy_r_r56 = cpy_r_r57;
CPyL35: ;
    if (!cpy_r_r23) goto CPyL74;
    cpy_r_r58 = (PyObject *)&_Py_NoneStruct;
    PyObject *cpy_r_r59[4] = {cpy_r_r14, cpy_r_r58, cpy_r_r58, cpy_r_r58};
    cpy_r_r60 = (PyObject **)&cpy_r_r59;
    cpy_r_r61 = PyObject_Vectorcall(cpy_r_r17, cpy_r_r60, 4, 0);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 54, CPyStatic_numeric___globals);
        goto CPyL75;
    } else
        goto CPyL76;
CPyL37: ;
    CPy_DECREF(cpy_r_r14);
CPyL38: ;
    if (cpy_r_r56.f0 == NULL) {
        goto CPyL45;
    } else
        goto CPyL77;
CPyL39: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL41;
    } else
        goto CPyL78;
CPyL40: ;
    CPy_Unreachable();
CPyL41: ;
    if (cpy_r_r56.f0 == NULL) goto CPyL43;
    CPy_RestoreExcInfo(cpy_r_r56);
    CPy_XDECREF(cpy_r_r56.f0);
    CPy_XDECREF(cpy_r_r56.f1);
    CPy_XDECREF(cpy_r_r56.f2);
CPyL43: ;
    cpy_r_r62 = CPy_KeepPropagating();
    if (!cpy_r_r62) goto CPyL52;
    CPy_Unreachable();
CPyL45: ;
    if (cpy_r_lower == NULL) {
        goto CPyL79;
    } else
        goto CPyL48;
CPyL46: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"lower\" referenced before assignment");
    cpy_r_r63 = 0;
    if (unlikely(!cpy_r_r63)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 59, CPyStatic_numeric___globals);
        goto CPyL52;
    }
    CPy_Unreachable();
CPyL48: ;
    if (cpy_r_upper == NULL) {
        goto CPyL80;
    } else
        goto CPyL51;
CPyL49: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"upper\" referenced before assignment");
    cpy_r_r64 = 0;
    if (unlikely(!cpy_r_r64)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 59, CPyStatic_numeric___globals);
        goto CPyL52;
    }
    CPy_Unreachable();
CPyL51: ;
    cpy_r_r65.f0 = cpy_r_lower;
    cpy_r_r65.f1 = cpy_r_upper;
    return cpy_r_r65;
CPyL52: ;
    tuple_T2OO __tmp28 = { NULL, NULL };
    cpy_r_r66 = __tmp28;
    return cpy_r_r66;
CPyL53: ;
    CPy_XDecRef(cpy_r_lower);
    CPy_XDecRef(cpy_r_upper);
    goto CPyL52;
CPyL54: ;
    CPy_XDecRef(cpy_r_lower);
    CPy_XDecRef(cpy_r_upper);
    CPyTagged_DecRef(cpy_r_r5);
    CPyTagged_DecRef(cpy_r_r6);
    goto CPyL2;
CPyL55: ;
    CPy_XDecRef(cpy_r_lower);
    CPy_XDecRef(cpy_r_upper);
    CPyTagged_DecRef(cpy_r_r5);
    CPyTagged_DecRef(cpy_r_r6);
    goto CPyL52;
CPyL56: ;
    CPy_XDecRef(cpy_r_lower);
    CPy_XDecRef(cpy_r_upper);
    CPyTagged_DecRef(cpy_r_r5);
    CPyTagged_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    goto CPyL52;
CPyL57: ;
    CPy_XDecRef(cpy_r_lower);
    CPy_XDecRef(cpy_r_upper);
    CPyTagged_DecRef(cpy_r_r5);
    CPyTagged_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r17);
    goto CPyL52;
CPyL58: ;
    CPy_DECREF(cpy_r_r22);
    goto CPyL9;
CPyL59: ;
    CPyTagged_DecRef(cpy_r_r5);
    CPyTagged_DecRef(cpy_r_r6);
    goto CPyL11;
CPyL60: ;
    CPy_XDecRef(cpy_r_lower);
    CPy_XDecRef(cpy_r_upper);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r17);
    goto CPyL12;
CPyL61: ;
    CPyTagged_DecRef(cpy_r_r5);
    CPyTagged_DecRef(cpy_r_r6);
    goto CPyL25;
CPyL62: ;
    CPyTagged_DecRef(cpy_r_r5);
    CPyTagged_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r28);
    goto CPyL15;
CPyL63: ;
    CPy_XDecRef(cpy_r_lower);
    CPy_XDecRef(cpy_r_upper);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r17);
    goto CPyL16;
CPyL64: ;
    CPyTagged_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r28);
    CPy_DecRef(cpy_r_r31);
    goto CPyL25;
CPyL65: ;
    CPyTagged_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r28);
    goto CPyL25;
CPyL66: ;
    CPy_XDECREF(cpy_r_lower);
    goto CPyL19;
CPyL67: ;
    CPyTagged_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r28);
    goto CPyL20;
CPyL68: ;
    CPy_DecRef(cpy_r_lower);
    CPy_XDecRef(cpy_r_upper);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r17);
    goto CPyL21;
CPyL69: ;
    CPy_DecRef(cpy_r_r28);
    CPy_DecRef(cpy_r_r38);
    goto CPyL25;
CPyL70: ;
    CPy_XDECREF(cpy_r_upper);
    goto CPyL24;
CPyL71: ;
    CPy_DecRef(cpy_r_r45);
    CPy_DecRef(cpy_r_r46);
    CPy_DecRef(cpy_r_r47);
    goto CPyL31;
CPyL72: ;
    CPy_XDecRef(cpy_r_lower);
    CPy_XDecRef(cpy_r_upper);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r43.f0);
    CPy_DecRef(cpy_r_r43.f1);
    CPy_DecRef(cpy_r_r43.f2);
    goto CPyL29;
CPyL73: ;
    CPy_XDecRef(cpy_r_lower);
    CPy_XDecRef(cpy_r_upper);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r17);
    goto CPyL32;
CPyL74: ;
    CPy_DECREF(cpy_r_r14);
    CPy_DECREF(cpy_r_r17);
    goto CPyL38;
CPyL75: ;
    CPy_XDecRef(cpy_r_lower);
    CPy_XDecRef(cpy_r_upper);
    CPy_DecRef(cpy_r_r14);
    goto CPyL41;
CPyL76: ;
    CPy_DECREF(cpy_r_r61);
    goto CPyL37;
CPyL77: ;
    CPy_XDECREF(cpy_r_lower);
    CPy_XDECREF(cpy_r_upper);
    goto CPyL39;
CPyL78: ;
    CPy_XDECREF(cpy_r_r56.f0);
    CPy_XDECREF(cpy_r_r56.f1);
    CPy_XDECREF(cpy_r_r56.f2);
    goto CPyL40;
CPyL79: ;
    CPy_XDECREF(cpy_r_upper);
    goto CPyL46;
CPyL80: ;
    CPy_XDECREF(cpy_r_lower);
    goto CPyL49;
}

PyObject *CPyPy_numeric___compute_signed_fixed_bounds(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"num_bits", "frac_places", 0};
    static CPyArg_Parser parser = {"OO:compute_signed_fixed_bounds", kwlist, 0};
    PyObject *obj_num_bits;
    PyObject *obj_frac_places;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_num_bits, &obj_frac_places)) {
        return NULL;
    }
    CPyTagged arg_num_bits;
    if (likely(PyLong_Check(obj_num_bits)))
        arg_num_bits = CPyTagged_BorrowFromObject(obj_num_bits);
    else {
        CPy_TypeError("int", obj_num_bits); goto fail;
    }
    CPyTagged arg_frac_places;
    if (likely(PyLong_Check(obj_frac_places)))
        arg_frac_places = CPyTagged_BorrowFromObject(obj_frac_places);
    else {
        CPy_TypeError("int", obj_frac_places); goto fail;
    }
    tuple_T2OO retval = CPyDef_numeric___compute_signed_fixed_bounds(arg_num_bits, arg_frac_places);
    if (retval.f0 == NULL) {
        return NULL;
    }
    PyObject *retbox = PyTuple_New(2);
    if (unlikely(retbox == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp29 = retval.f0;
    PyTuple_SET_ITEM(retbox, 0, __tmp29);
    PyObject *__tmp30 = retval.f1;
    PyTuple_SET_ITEM(retbox, 1, __tmp30);
    return retbox;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "compute_signed_fixed_bounds", 48, CPyStatic_numeric___globals);
    return NULL;
}

PyObject *CPyDef_numeric___f_scale_places_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = cpy_r_instance == cpy_r_r0;
    if (!cpy_r_r1) goto CPyL2;
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
CPyL2: ;
    cpy_r_r2 = PyMethod_New(cpy_r___mypyc_self__, cpy_r_instance);
    if (cpy_r_r2 == NULL) goto CPyL4;
    return cpy_r_r2;
CPyL4: ;
    cpy_r_r3 = NULL;
    return cpy_r_r3;
}

PyObject *CPyPy_numeric___f_scale_places_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"instance", "owner", 0};
    static CPyArg_Parser parser = {"OO:__get__", kwlist, 0};
    PyObject *obj_instance;
    PyObject *obj_owner;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_instance, &obj_owner)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_instance = obj_instance;
    PyObject *arg_owner = obj_owner;
    PyObject *retval = CPyDef_numeric___f_scale_places_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "__get__", -1, CPyStatic_numeric___globals);
    return NULL;
}

PyObject *CPyDef_numeric___f_scale_places_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_x) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject **cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject **cpy_r_r15;
    PyObject *cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    tuple_T3OOO cpy_r_r21;
    tuple_T3OOO cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject **cpy_r_r27;
    PyObject *cpy_r_r28;
    int32_t cpy_r_r29;
    char cpy_r_r30;
    char cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    tuple_T3OOO cpy_r_r34;
    tuple_T3OOO cpy_r_r35;
    PyObject *cpy_r_r36;
    tuple_T3OOO cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject **cpy_r_r40;
    PyObject *cpy_r_r41;
    char cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    cpy_r_r0 = ((faster_eth_abi___utils___numeric___f_scale_places_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("faster_eth_abi/utils/numeric.py", "f", "f_scale_places_obj", "__mypyc_env__", 76, CPyStatic_numeric___globals);
        goto CPyL37;
    }
    CPy_INCREF_NO_IMM(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyStatic_numeric___abi_decimal_context;
    if (unlikely(cpy_r_r1 == NULL)) {
        goto CPyL38;
    } else
        goto CPyL4;
CPyL2: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"abi_decimal_context\" was not set");
    cpy_r_r2 = 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "f", 77, CPyStatic_numeric___globals);
        goto CPyL37;
    }
    CPy_Unreachable();
CPyL4: ;
    cpy_r_r3 = CPyModule_decimal;
    cpy_r_r4 = CPyStatics[163]; /* 'localcontext' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "f", 77, CPyStatic_numeric___globals);
        goto CPyL39;
    }
    PyObject *cpy_r_r6[1] = {cpy_r_r1};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = PyObject_Vectorcall(cpy_r_r5, cpy_r_r7, 1, 0);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "f", 77, CPyStatic_numeric___globals);
        goto CPyL39;
    }
    cpy_r_r9 = PyObject_Type(cpy_r_r8);
    cpy_r_r10 = CPyStatics[164]; /* '__exit__' */
    cpy_r_r11 = CPyObject_GetAttr(cpy_r_r9, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "f", 77, CPyStatic_numeric___globals);
        goto CPyL40;
    }
    cpy_r_r12 = CPyStatics[165]; /* '__enter__' */
    cpy_r_r13 = CPyObject_GetAttr(cpy_r_r9, cpy_r_r12);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "f", 77, CPyStatic_numeric___globals);
        goto CPyL41;
    }
    PyObject *cpy_r_r14[1] = {cpy_r_r8};
    cpy_r_r15 = (PyObject **)&cpy_r_r14;
    cpy_r_r16 = PyObject_Vectorcall(cpy_r_r13, cpy_r_r15, 1, 0);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "f", 77, CPyStatic_numeric___globals);
        goto CPyL41;
    } else
        goto CPyL42;
CPyL9: ;
    cpy_r_r17 = 1;
    cpy_r_r18 = ((faster_eth_abi___utils___numeric___scale_places_envObject *)cpy_r_r0)->_scaling_factor;
    if (unlikely(cpy_r_r18 == NULL)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'scaling_factor' of 'scale_places_env' undefined");
    } else {
        CPy_INCREF(cpy_r_r18);
    }
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "f", 78, CPyStatic_numeric___globals);
        goto CPyL13;
    }
CPyL11: ;
    cpy_r_r19 = PyNumber_Multiply(cpy_r_x, cpy_r_r18);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "f", 78, CPyStatic_numeric___globals);
        goto CPyL13;
    }
    cpy_r_r20 = cpy_r_r19;
    goto CPyL22;
CPyL13: ;
    cpy_r_r21 = CPy_CatchError();
    cpy_r_r17 = 0;
    cpy_r_r22 = CPy_GetExcInfo();
    cpy_r_r23 = cpy_r_r22.f0;
    CPy_INCREF(cpy_r_r23);
    cpy_r_r24 = cpy_r_r22.f1;
    CPy_INCREF(cpy_r_r24);
    cpy_r_r25 = cpy_r_r22.f2;
    CPy_INCREF(cpy_r_r25);
    CPy_DecRef(cpy_r_r22.f0);
    CPy_DecRef(cpy_r_r22.f1);
    CPy_DecRef(cpy_r_r22.f2);
    PyObject *cpy_r_r26[4] = {cpy_r_r8, cpy_r_r23, cpy_r_r24, cpy_r_r25};
    cpy_r_r27 = (PyObject **)&cpy_r_r26;
    cpy_r_r28 = PyObject_Vectorcall(cpy_r_r11, cpy_r_r27, 4, 0);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "f", 77, CPyStatic_numeric___globals);
        goto CPyL43;
    }
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r25);
    cpy_r_r29 = PyObject_IsTrue(cpy_r_r28);
    CPy_DecRef(cpy_r_r28);
    cpy_r_r30 = cpy_r_r29 >= 0;
    if (unlikely(!cpy_r_r30)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "f", 77, CPyStatic_numeric___globals);
        goto CPyL19;
    }
    cpy_r_r31 = cpy_r_r29;
    if (cpy_r_r31) goto CPyL18;
    CPy_Reraise();
    if (!0) {
        goto CPyL19;
    } else
        goto CPyL44;
CPyL17: ;
    CPy_Unreachable();
CPyL18: ;
    CPy_RestoreExcInfo(cpy_r_r21);
    CPy_DecRef(cpy_r_r21.f0);
    CPy_DecRef(cpy_r_r21.f1);
    CPy_DecRef(cpy_r_r21.f2);
    goto CPyL21;
CPyL19: ;
    CPy_RestoreExcInfo(cpy_r_r21);
    CPy_DecRef(cpy_r_r21.f0);
    CPy_DecRef(cpy_r_r21.f1);
    CPy_DecRef(cpy_r_r21.f2);
    cpy_r_r32 = CPy_KeepPropagating();
    if (!cpy_r_r32) {
        goto CPyL23;
    } else
        goto CPyL45;
CPyL20: ;
    CPy_Unreachable();
CPyL21: ;
    cpy_r_r33 = NULL;
    cpy_r_r20 = cpy_r_r33;
CPyL22: ;
    tuple_T3OOO __tmp31 = { NULL, NULL, NULL };
    cpy_r_r34 = __tmp31;
    cpy_r_r35 = cpy_r_r34;
    goto CPyL24;
CPyL23: ;
    cpy_r_r36 = NULL;
    cpy_r_r20 = cpy_r_r36;
    cpy_r_r37 = CPy_CatchError();
    cpy_r_r35 = cpy_r_r37;
CPyL24: ;
    if (!cpy_r_r17) goto CPyL46;
    cpy_r_r38 = (PyObject *)&_Py_NoneStruct;
    PyObject *cpy_r_r39[4] = {cpy_r_r8, cpy_r_r38, cpy_r_r38, cpy_r_r38};
    cpy_r_r40 = (PyObject **)&cpy_r_r39;
    cpy_r_r41 = PyObject_Vectorcall(cpy_r_r11, cpy_r_r40, 4, 0);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "f", 77, CPyStatic_numeric___globals);
        goto CPyL47;
    } else
        goto CPyL48;
CPyL26: ;
    CPy_DECREF(cpy_r_r8);
CPyL27: ;
    if (cpy_r_r35.f0 == NULL) {
        goto CPyL30;
    } else
        goto CPyL49;
CPyL28: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL32;
    } else
        goto CPyL50;
CPyL29: ;
    CPy_Unreachable();
CPyL30: ;
    if (cpy_r_r20 == NULL) goto CPyL36;
    return cpy_r_r20;
CPyL32: ;
    if (cpy_r_r35.f0 == NULL) goto CPyL34;
    CPy_RestoreExcInfo(cpy_r_r35);
    CPy_XDECREF(cpy_r_r35.f0);
    CPy_XDECREF(cpy_r_r35.f1);
    CPy_XDECREF(cpy_r_r35.f2);
CPyL34: ;
    cpy_r_r42 = CPy_KeepPropagating();
    if (!cpy_r_r42) goto CPyL37;
    CPy_Unreachable();
CPyL36: ;
    cpy_r_r43 = Py_None;
    return cpy_r_r43;
CPyL37: ;
    cpy_r_r44 = NULL;
    return cpy_r_r44;
CPyL38: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL2;
CPyL39: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL37;
CPyL40: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    goto CPyL37;
CPyL41: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r11);
    goto CPyL37;
CPyL42: ;
    CPy_DECREF(cpy_r_r16);
    goto CPyL9;
CPyL43: ;
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r25);
    goto CPyL19;
CPyL44: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r21.f0);
    CPy_DecRef(cpy_r_r21.f1);
    CPy_DecRef(cpy_r_r21.f2);
    goto CPyL17;
CPyL45: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r11);
    goto CPyL20;
CPyL46: ;
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r11);
    goto CPyL27;
CPyL47: ;
    CPy_DecRef(cpy_r_r8);
    CPy_XDecRef(cpy_r_r20);
    goto CPyL32;
CPyL48: ;
    CPy_DECREF(cpy_r_r41);
    goto CPyL26;
CPyL49: ;
    CPy_XDECREF(cpy_r_r20);
    goto CPyL28;
CPyL50: ;
    CPy_XDECREF(cpy_r_r35.f0);
    CPy_XDECREF(cpy_r_r35.f1);
    CPy_XDECREF(cpy_r_r35.f2);
    goto CPyL29;
}

PyObject *CPyPy_numeric___f_scale_places_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"x", 0};
    static CPyArg_Parser parser = {"O:__call__", kwlist, 0};
    PyObject *obj_x;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_x)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_x = obj_x;
    PyObject *retval = CPyDef_numeric___f_scale_places_obj_____call__(arg___mypyc_self__, arg_x);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "f", 76, CPyStatic_numeric___globals);
    return NULL;
}

PyObject *CPyDef_numeric___scale_places(CPyTagged cpy_r_places) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    int32_t cpy_r_r3;
    char cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject **cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    CPyPtr cpy_r_r26;
    CPyPtr cpy_r_r27;
    CPyPtr cpy_r_r28;
    CPyPtr cpy_r_r29;
    CPyPtr cpy_r_r30;
    CPyPtr cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject **cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    char cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject **cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject **cpy_r_r53;
    PyObject *cpy_r_r54;
    char cpy_r_r55;
    PyObject *cpy_r_r56;
    char cpy_r_r57;
    CPyTagged cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    char cpy_r_r61;
    tuple_T3OOO cpy_r_r62;
    tuple_T3OOO cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject **cpy_r_r68;
    PyObject *cpy_r_r69;
    int32_t cpy_r_r70;
    char cpy_r_r71;
    char cpy_r_r72;
    char cpy_r_r73;
    tuple_T3OOO cpy_r_r74;
    tuple_T3OOO cpy_r_r75;
    tuple_T3OOO cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject **cpy_r_r79;
    PyObject *cpy_r_r80;
    char cpy_r_r81;
    PyObject *cpy_r_r82;
    char cpy_r_r83;
    PyObject *cpy_r_f;
    int64_t cpy_r_r84;
    char cpy_r_r85;
    int64_t cpy_r_r86;
    char cpy_r_r87;
    char cpy_r_r88;
    char cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    CPyTagged cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_places_repr;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    int32_t cpy_r_r101;
    char cpy_r_r102;
    PyObject *cpy_r_r103;
    int32_t cpy_r_r104;
    char cpy_r_r105;
    PyObject *cpy_r_r106;
    cpy_r_r0 = CPyDef_numeric___scale_places_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 62, CPyStatic_numeric___globals);
        goto CPyL61;
    }
    CPyTagged_INCREF(cpy_r_places);
    cpy_r_r1 = CPyTagged_StealAsObject(cpy_r_places);
    cpy_r_r2 = (PyObject *)&PyLong_Type;
    cpy_r_r3 = PyObject_IsInstance(cpy_r_r1, cpy_r_r2);
    CPy_DECREF(cpy_r_r1);
    cpy_r_r4 = cpy_r_r3 >= 0;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 67, CPyStatic_numeric___globals);
        goto CPyL62;
    }
    cpy_r_r5 = cpy_r_r3;
    if (cpy_r_r5) {
        goto CPyL11;
    } else
        goto CPyL63;
CPyL3: ;
    cpy_r_r6 = CPyStatics[53]; /* '' */
    cpy_r_r7 = CPyStatics[166]; /* 'Argument `places` must be int.  Got value ' */
    cpy_r_r8 = CPyStatics[54]; /* '{:{}}' */
    CPyTagged_INCREF(cpy_r_places);
    cpy_r_r9 = CPyTagged_StealAsObject(cpy_r_places);
    cpy_r_r10 = CPyStatics[53]; /* '' */
    cpy_r_r11 = CPyStatics[55]; /* 'format' */
    PyObject *cpy_r_r12[3] = {cpy_r_r8, cpy_r_r9, cpy_r_r10};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = PyObject_VectorcallMethod(cpy_r_r11, cpy_r_r13, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 69, CPyStatic_numeric___globals);
        goto CPyL64;
    }
    CPy_DECREF(cpy_r_r9);
    cpy_r_r15 = CPyStatics[167]; /* ' of type ' */
    cpy_r_r16 = CPyStatics[54]; /* '{:{}}' */
    CPyTagged_INCREF(cpy_r_places);
    cpy_r_r17 = CPyTagged_StealAsObject(cpy_r_places);
    cpy_r_r18 = PyObject_Type(cpy_r_r17);
    CPy_DECREF(cpy_r_r17);
    cpy_r_r19 = CPyStatics[53]; /* '' */
    cpy_r_r20 = CPyStatics[55]; /* 'format' */
    PyObject *cpy_r_r21[3] = {cpy_r_r16, cpy_r_r18, cpy_r_r19};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = PyObject_VectorcallMethod(cpy_r_r20, cpy_r_r22, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 70, CPyStatic_numeric___globals);
        goto CPyL65;
    }
    CPy_DECREF(cpy_r_r18);
    cpy_r_r24 = CPyStatics[168]; /* '.' */
    cpy_r_r25 = PyList_New(5);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 69, CPyStatic_numeric___globals);
        goto CPyL66;
    }
    cpy_r_r26 = (CPyPtr)&((PyListObject *)cpy_r_r25)->ob_item;
    cpy_r_r27 = *(CPyPtr *)cpy_r_r26;
    CPy_INCREF(cpy_r_r7);
    *(PyObject * *)cpy_r_r27 = cpy_r_r7;
    cpy_r_r28 = cpy_r_r27 + 8;
    *(PyObject * *)cpy_r_r28 = cpy_r_r14;
    CPy_INCREF(cpy_r_r15);
    cpy_r_r29 = cpy_r_r27 + 16;
    *(PyObject * *)cpy_r_r29 = cpy_r_r15;
    cpy_r_r30 = cpy_r_r27 + 24;
    *(PyObject * *)cpy_r_r30 = cpy_r_r23;
    CPy_INCREF(cpy_r_r24);
    cpy_r_r31 = cpy_r_r27 + 32;
    *(PyObject * *)cpy_r_r31 = cpy_r_r24;
    cpy_r_r32 = PyUnicode_Join(cpy_r_r6, cpy_r_r25);
    CPy_DECREF_NO_IMM(cpy_r_r25);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 69, CPyStatic_numeric___globals);
        goto CPyL61;
    }
    cpy_r_r33 = CPyModule_builtins;
    cpy_r_r34 = CPyStatics[63]; /* 'ValueError' */
    cpy_r_r35 = CPyObject_GetAttr(cpy_r_r33, cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 68, CPyStatic_numeric___globals);
        goto CPyL67;
    }
    PyObject *cpy_r_r36[1] = {cpy_r_r32};
    cpy_r_r37 = (PyObject **)&cpy_r_r36;
    cpy_r_r38 = PyObject_Vectorcall(cpy_r_r35, cpy_r_r37, 1, 0);
    CPy_DECREF(cpy_r_r35);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 68, CPyStatic_numeric___globals);
        goto CPyL67;
    }
    CPy_DECREF(cpy_r_r32);
    CPy_Raise(cpy_r_r38);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 68, CPyStatic_numeric___globals);
        goto CPyL61;
    }
    CPy_Unreachable();
CPyL11: ;
    cpy_r_r39 = CPyStatic_numeric___abi_decimal_context;
    if (unlikely(cpy_r_r39 == NULL)) {
        goto CPyL68;
    } else
        goto CPyL14;
CPyL12: ;
    PyErr_SetString(PyExc_NameError, "value for final name \"abi_decimal_context\" was not set");
    cpy_r_r40 = 0;
    if (unlikely(!cpy_r_r40)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 73, CPyStatic_numeric___globals);
        goto CPyL61;
    }
    CPy_Unreachable();
CPyL14: ;
    cpy_r_r41 = CPyModule_decimal;
    cpy_r_r42 = CPyStatics[163]; /* 'localcontext' */
    cpy_r_r43 = CPyObject_GetAttr(cpy_r_r41, cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 73, CPyStatic_numeric___globals);
        goto CPyL62;
    }
    PyObject *cpy_r_r44[1] = {cpy_r_r39};
    cpy_r_r45 = (PyObject **)&cpy_r_r44;
    cpy_r_r46 = PyObject_Vectorcall(cpy_r_r43, cpy_r_r45, 1, 0);
    CPy_DECREF(cpy_r_r43);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 73, CPyStatic_numeric___globals);
        goto CPyL62;
    }
    cpy_r_r47 = PyObject_Type(cpy_r_r46);
    cpy_r_r48 = CPyStatics[164]; /* '__exit__' */
    cpy_r_r49 = CPyObject_GetAttr(cpy_r_r47, cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 73, CPyStatic_numeric___globals);
        goto CPyL69;
    }
    cpy_r_r50 = CPyStatics[165]; /* '__enter__' */
    cpy_r_r51 = CPyObject_GetAttr(cpy_r_r47, cpy_r_r50);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 73, CPyStatic_numeric___globals);
        goto CPyL70;
    }
    PyObject *cpy_r_r52[1] = {cpy_r_r46};
    cpy_r_r53 = (PyObject **)&cpy_r_r52;
    cpy_r_r54 = PyObject_Vectorcall(cpy_r_r51, cpy_r_r53, 1, 0);
    CPy_DECREF(cpy_r_r51);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 73, CPyStatic_numeric___globals);
        goto CPyL70;
    } else
        goto CPyL71;
CPyL19: ;
    cpy_r_r55 = 1;
    cpy_r_r56 = CPyStatic_numeric___TEN;
    if (likely(cpy_r_r56 != NULL)) goto CPyL23;
    PyErr_SetString(PyExc_NameError, "value for final name \"TEN\" was not set");
    cpy_r_r57 = 0;
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 74, CPyStatic_numeric___globals);
        goto CPyL25;
    } else
        goto CPyL72;
CPyL22: ;
    CPy_Unreachable();
CPyL23: ;
    cpy_r_r58 = CPyTagged_Negate(cpy_r_places);
    cpy_r_r59 = CPyTagged_StealAsObject(cpy_r_r58);
    cpy_r_r60 = CPyNumber_Power(cpy_r_r56, cpy_r_r59);
    CPy_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 74, CPyStatic_numeric___globals);
        goto CPyL25;
    }
    if (((faster_eth_abi___utils___numeric___scale_places_envObject *)cpy_r_r0)->_scaling_factor != NULL) {
        CPy_DECREF(((faster_eth_abi___utils___numeric___scale_places_envObject *)cpy_r_r0)->_scaling_factor);
    }
    ((faster_eth_abi___utils___numeric___scale_places_envObject *)cpy_r_r0)->_scaling_factor = cpy_r_r60;
    cpy_r_r61 = 1;
    if (unlikely(!cpy_r_r61)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 74, CPyStatic_numeric___globals);
    } else
        goto CPyL33;
CPyL25: ;
    cpy_r_r62 = CPy_CatchError();
    cpy_r_r55 = 0;
    cpy_r_r63 = CPy_GetExcInfo();
    cpy_r_r64 = cpy_r_r63.f0;
    CPy_INCREF(cpy_r_r64);
    cpy_r_r65 = cpy_r_r63.f1;
    CPy_INCREF(cpy_r_r65);
    cpy_r_r66 = cpy_r_r63.f2;
    CPy_INCREF(cpy_r_r66);
    CPy_DecRef(cpy_r_r63.f0);
    CPy_DecRef(cpy_r_r63.f1);
    CPy_DecRef(cpy_r_r63.f2);
    PyObject *cpy_r_r67[4] = {cpy_r_r46, cpy_r_r64, cpy_r_r65, cpy_r_r66};
    cpy_r_r68 = (PyObject **)&cpy_r_r67;
    cpy_r_r69 = PyObject_Vectorcall(cpy_r_r49, cpy_r_r68, 4, 0);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 73, CPyStatic_numeric___globals);
        goto CPyL73;
    }
    CPy_DecRef(cpy_r_r64);
    CPy_DecRef(cpy_r_r65);
    CPy_DecRef(cpy_r_r66);
    cpy_r_r70 = PyObject_IsTrue(cpy_r_r69);
    CPy_DecRef(cpy_r_r69);
    cpy_r_r71 = cpy_r_r70 >= 0;
    if (unlikely(!cpy_r_r71)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 73, CPyStatic_numeric___globals);
        goto CPyL31;
    }
    cpy_r_r72 = cpy_r_r70;
    if (cpy_r_r72) goto CPyL30;
    CPy_Reraise();
    if (!0) {
        goto CPyL31;
    } else
        goto CPyL74;
CPyL29: ;
    CPy_Unreachable();
CPyL30: ;
    CPy_RestoreExcInfo(cpy_r_r62);
    CPy_DecRef(cpy_r_r62.f0);
    CPy_DecRef(cpy_r_r62.f1);
    CPy_DecRef(cpy_r_r62.f2);
    goto CPyL33;
CPyL31: ;
    CPy_RestoreExcInfo(cpy_r_r62);
    CPy_DecRef(cpy_r_r62.f0);
    CPy_DecRef(cpy_r_r62.f1);
    CPy_DecRef(cpy_r_r62.f2);
    cpy_r_r73 = CPy_KeepPropagating();
    if (!cpy_r_r73) {
        goto CPyL34;
    } else
        goto CPyL75;
CPyL32: ;
    CPy_Unreachable();
CPyL33: ;
    tuple_T3OOO __tmp32 = { NULL, NULL, NULL };
    cpy_r_r74 = __tmp32;
    cpy_r_r75 = cpy_r_r74;
    goto CPyL35;
CPyL34: ;
    cpy_r_r76 = CPy_CatchError();
    cpy_r_r75 = cpy_r_r76;
CPyL35: ;
    if (!cpy_r_r55) goto CPyL76;
    cpy_r_r77 = (PyObject *)&_Py_NoneStruct;
    PyObject *cpy_r_r78[4] = {cpy_r_r46, cpy_r_r77, cpy_r_r77, cpy_r_r77};
    cpy_r_r79 = (PyObject **)&cpy_r_r78;
    cpy_r_r80 = PyObject_Vectorcall(cpy_r_r49, cpy_r_r79, 4, 0);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 73, CPyStatic_numeric___globals);
        goto CPyL77;
    } else
        goto CPyL78;
CPyL37: ;
    CPy_DECREF(cpy_r_r46);
CPyL38: ;
    if (cpy_r_r75.f0 == NULL) {
        goto CPyL45;
    } else
        goto CPyL79;
CPyL39: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL41;
    } else
        goto CPyL80;
CPyL40: ;
    CPy_Unreachable();
CPyL41: ;
    if (cpy_r_r75.f0 == NULL) goto CPyL43;
    CPy_RestoreExcInfo(cpy_r_r75);
    CPy_XDECREF(cpy_r_r75.f0);
    CPy_XDECREF(cpy_r_r75.f1);
    CPy_XDECREF(cpy_r_r75.f2);
CPyL43: ;
    cpy_r_r81 = CPy_KeepPropagating();
    if (!cpy_r_r81) goto CPyL61;
    CPy_Unreachable();
CPyL45: ;
    cpy_r_r82 = CPyDef_numeric___f_scale_places_obj();
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 76, CPyStatic_numeric___globals);
        goto CPyL62;
    }
    if (((faster_eth_abi___utils___numeric___f_scale_places_objObject *)cpy_r_r82)->___mypyc_env__ != NULL) {
        CPy_DECREF_NO_IMM(((faster_eth_abi___utils___numeric___f_scale_places_objObject *)cpy_r_r82)->___mypyc_env__);
    }
    ((faster_eth_abi___utils___numeric___f_scale_places_objObject *)cpy_r_r82)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r83 = 1;
    if (unlikely(!cpy_r_r83)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 76, CPyStatic_numeric___globals);
        goto CPyL81;
    }
    cpy_r_f = cpy_r_r82;
    cpy_r_r84 = cpy_r_places & 1;
    cpy_r_r85 = cpy_r_r84 != 0;
    if (cpy_r_r85) goto CPyL49;
    cpy_r_r86 = 0 & 1;
    cpy_r_r87 = cpy_r_r86 != 0;
    if (!cpy_r_r87) goto CPyL50;
CPyL49: ;
    cpy_r_r88 = CPyTagged_IsLt_(0, cpy_r_places);
    if (cpy_r_r88) {
        goto CPyL51;
    } else
        goto CPyL54;
CPyL50: ;
    cpy_r_r89 = (Py_ssize_t)cpy_r_places > (Py_ssize_t)0;
    if (!cpy_r_r89) goto CPyL54;
CPyL51: ;
    cpy_r_r90 = CPyStatics[169]; /* 'Eneg' */
    cpy_r_r91 = CPyTagged_Str(cpy_r_places);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 80, CPyStatic_numeric___globals);
        goto CPyL82;
    }
    cpy_r_r92 = CPyStr_Build(2, cpy_r_r90, cpy_r_r91);
    CPy_DECREF(cpy_r_r91);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 80, CPyStatic_numeric___globals);
        goto CPyL82;
    }
    cpy_r_r93 = cpy_r_r92;
    goto CPyL57;
CPyL54: ;
    cpy_r_r94 = CPyStatics[170]; /* 'Epos' */
    cpy_r_r95 = CPyTagged_Negate(cpy_r_places);
    cpy_r_r96 = CPyTagged_Str(cpy_r_r95);
    CPyTagged_DECREF(cpy_r_r95);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 80, CPyStatic_numeric___globals);
        goto CPyL82;
    }
    cpy_r_r97 = CPyStr_Build(2, cpy_r_r94, cpy_r_r96);
    CPy_DECREF(cpy_r_r96);
    if (unlikely(cpy_r_r97 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 80, CPyStatic_numeric___globals);
        goto CPyL82;
    }
    cpy_r_r93 = cpy_r_r97;
CPyL57: ;
    cpy_r_places_repr = cpy_r_r93;
    cpy_r_r98 = CPyStatics[171]; /* 'scale_by_' */
    cpy_r_r99 = CPyStr_Build(2, cpy_r_r98, cpy_r_places_repr);
    CPy_DECREF(cpy_r_places_repr);
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 81, CPyStatic_numeric___globals);
        goto CPyL82;
    }
    cpy_r_r100 = CPyStatics[60]; /* '__name__' */
    cpy_r_r101 = PyObject_SetAttr(cpy_r_f, cpy_r_r100, cpy_r_r99);
    cpy_r_r102 = cpy_r_r101 >= 0;
    if (unlikely(!cpy_r_r102)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 83, CPyStatic_numeric___globals);
        goto CPyL83;
    }
    cpy_r_r103 = CPyStatics[172]; /* '__qualname__' */
    cpy_r_r104 = PyObject_SetAttr(cpy_r_f, cpy_r_r103, cpy_r_r99);
    CPy_DECREF(cpy_r_r99);
    cpy_r_r105 = cpy_r_r104 >= 0;
    if (unlikely(!cpy_r_r105)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 84, CPyStatic_numeric___globals);
        goto CPyL82;
    }
    return cpy_r_f;
CPyL61: ;
    cpy_r_r106 = NULL;
    return cpy_r_r106;
CPyL62: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL61;
CPyL63: ;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    goto CPyL3;
CPyL64: ;
    CPy_DecRef(cpy_r_r9);
    goto CPyL61;
CPyL65: ;
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r18);
    goto CPyL61;
CPyL66: ;
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r23);
    goto CPyL61;
CPyL67: ;
    CPy_DecRef(cpy_r_r32);
    goto CPyL61;
CPyL68: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL12;
CPyL69: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r46);
    CPy_DecRef(cpy_r_r47);
    goto CPyL61;
CPyL70: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r46);
    CPy_DecRef(cpy_r_r49);
    goto CPyL61;
CPyL71: ;
    CPy_DECREF(cpy_r_r54);
    goto CPyL19;
CPyL72: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r46);
    CPy_DecRef(cpy_r_r49);
    goto CPyL22;
CPyL73: ;
    CPy_DecRef(cpy_r_r64);
    CPy_DecRef(cpy_r_r65);
    CPy_DecRef(cpy_r_r66);
    goto CPyL31;
CPyL74: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r46);
    CPy_DecRef(cpy_r_r49);
    CPy_DecRef(cpy_r_r62.f0);
    CPy_DecRef(cpy_r_r62.f1);
    CPy_DecRef(cpy_r_r62.f2);
    goto CPyL29;
CPyL75: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r46);
    CPy_DecRef(cpy_r_r49);
    goto CPyL32;
CPyL76: ;
    CPy_DECREF(cpy_r_r46);
    CPy_DECREF(cpy_r_r49);
    goto CPyL38;
CPyL77: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r46);
    goto CPyL41;
CPyL78: ;
    CPy_DECREF(cpy_r_r80);
    goto CPyL37;
CPyL79: ;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    goto CPyL39;
CPyL80: ;
    CPy_XDECREF(cpy_r_r75.f0);
    CPy_XDECREF(cpy_r_r75.f1);
    CPy_XDECREF(cpy_r_r75.f2);
    goto CPyL40;
CPyL81: ;
    CPy_DecRef(cpy_r_r82);
    goto CPyL61;
CPyL82: ;
    CPy_DecRef(cpy_r_f);
    goto CPyL61;
CPyL83: ;
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r99);
    goto CPyL61;
}

PyObject *CPyPy_numeric___scale_places(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"places", 0};
    static CPyArg_Parser parser = {"O:scale_places", kwlist, 0};
    PyObject *obj_places;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_places)) {
        return NULL;
    }
    CPyTagged arg_places;
    if (likely(PyLong_Check(obj_places)))
        arg_places = CPyTagged_BorrowFromObject(obj_places);
    else {
        CPy_TypeError("int", obj_places); goto fail;
    }
    PyObject *retval = CPyDef_numeric___scale_places(arg_places);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "scale_places", 62, CPyStatic_numeric___globals);
    return NULL;
}

char CPyDef_numeric_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r5;
    void *cpy_r_r7;
    void *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    int32_t cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject **cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    int32_t cpy_r_r34;
    char cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject **cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    int32_t cpy_r_r45;
    char cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject **cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    int32_t cpy_r_r56;
    char cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    int32_t cpy_r_r63;
    char cpy_r_r64;
    char cpy_r_r65;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[11]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "<module>", -1, CPyStatic_numeric___globals);
        goto CPyL18;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_decimal;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {1};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[233]; /* (('decimal', 'decimal', 'decimal'),) */
    cpy_r_r11 = CPyStatic_numeric___globals;
    cpy_r_r12 = CPyStatics[174]; /* 'faster_eth_abi/utils/numeric.py' */
    cpy_r_r13 = CPyStatics[79]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL18;
    cpy_r_r15 = CPyStatics[234]; /* ('Callable', 'Final', 'Tuple') */
    cpy_r_r16 = CPyStatics[17]; /* 'typing' */
    cpy_r_r17 = CPyStatic_numeric___globals;
    cpy_r_r18 = CPyImport_ImportFromMany(cpy_r_r16, cpy_r_r15, cpy_r_r15, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "<module>", 2, CPyStatic_numeric___globals);
        goto CPyL18;
    }
    CPyModule_typing = cpy_r_r18;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = CPyStatic_numeric___globals;
    cpy_r_r20 = CPyStatics[175]; /* 'ABI_DECIMAL_PREC' */
    cpy_r_r21 = CPyStatics[202]; /* 999 */
    cpy_r_r22 = CPyDict_SetItem(cpy_r_r19, cpy_r_r20, cpy_r_r21);
    cpy_r_r23 = cpy_r_r22 >= 0;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "<module>", 8, CPyStatic_numeric___globals);
        goto CPyL18;
    }
    cpy_r_r24 = CPyModule_decimal;
    cpy_r_r25 = CPyStatics[176]; /* 'Context' */
    cpy_r_r26 = CPyObject_GetAttr(cpy_r_r24, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "<module>", 10, CPyStatic_numeric___globals);
        goto CPyL18;
    }
    cpy_r_r27 = CPyStatics[202]; /* 999 */
    PyObject *cpy_r_r28[1] = {cpy_r_r27};
    cpy_r_r29 = (PyObject **)&cpy_r_r28;
    cpy_r_r30 = CPyStatics[235]; /* ('prec',) */
    cpy_r_r31 = PyObject_Vectorcall(cpy_r_r26, cpy_r_r29, 0, cpy_r_r30);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "<module>", 10, CPyStatic_numeric___globals);
        goto CPyL18;
    }
    CPyStatic_numeric___abi_decimal_context = cpy_r_r31;
    CPy_INCREF(CPyStatic_numeric___abi_decimal_context);
    cpy_r_r32 = CPyStatic_numeric___globals;
    cpy_r_r33 = CPyStatics[178]; /* 'abi_decimal_context' */
    cpy_r_r34 = CPyDict_SetItem(cpy_r_r32, cpy_r_r33, cpy_r_r31);
    CPy_DECREF(cpy_r_r31);
    cpy_r_r35 = cpy_r_r34 >= 0;
    if (unlikely(!cpy_r_r35)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "<module>", 10, CPyStatic_numeric___globals);
        goto CPyL18;
    }
    cpy_r_r36 = CPyModule_decimal;
    cpy_r_r37 = CPyStatics[179]; /* 'Decimal' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_r36, cpy_r_r37);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "<module>", 12, CPyStatic_numeric___globals);
        goto CPyL18;
    }
    cpy_r_r39 = CPyStatics[192]; /* 0 */
    PyObject *cpy_r_r40[1] = {cpy_r_r39};
    cpy_r_r41 = (PyObject **)&cpy_r_r40;
    cpy_r_r42 = PyObject_Vectorcall(cpy_r_r38, cpy_r_r41, 1, 0);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "<module>", 12, CPyStatic_numeric___globals);
        goto CPyL18;
    }
    CPyStatic_numeric___ZERO = cpy_r_r42;
    CPy_INCREF(CPyStatic_numeric___ZERO);
    cpy_r_r43 = CPyStatic_numeric___globals;
    cpy_r_r44 = CPyStatics[180]; /* 'ZERO' */
    cpy_r_r45 = CPyDict_SetItem(cpy_r_r43, cpy_r_r44, cpy_r_r42);
    CPy_DECREF(cpy_r_r42);
    cpy_r_r46 = cpy_r_r45 >= 0;
    if (unlikely(!cpy_r_r46)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "<module>", 12, CPyStatic_numeric___globals);
        goto CPyL18;
    }
    cpy_r_r47 = CPyModule_decimal;
    cpy_r_r48 = CPyStatics[179]; /* 'Decimal' */
    cpy_r_r49 = CPyObject_GetAttr(cpy_r_r47, cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "<module>", 13, CPyStatic_numeric___globals);
        goto CPyL18;
    }
    cpy_r_r50 = CPyStatics[203]; /* 10 */
    PyObject *cpy_r_r51[1] = {cpy_r_r50};
    cpy_r_r52 = (PyObject **)&cpy_r_r51;
    cpy_r_r53 = PyObject_Vectorcall(cpy_r_r49, cpy_r_r52, 1, 0);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "<module>", 13, CPyStatic_numeric___globals);
        goto CPyL18;
    }
    CPyStatic_numeric___TEN = cpy_r_r53;
    CPy_INCREF(CPyStatic_numeric___TEN);
    cpy_r_r54 = CPyStatic_numeric___globals;
    cpy_r_r55 = CPyStatics[181]; /* 'TEN' */
    cpy_r_r56 = CPyDict_SetItem(cpy_r_r54, cpy_r_r55, cpy_r_r53);
    CPy_DECREF(cpy_r_r53);
    cpy_r_r57 = cpy_r_r56 >= 0;
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "<module>", 13, CPyStatic_numeric___globals);
        goto CPyL18;
    }
    cpy_r_r58 = CPyModule_decimal;
    cpy_r_r59 = CPyStatics[179]; /* 'Decimal' */
    cpy_r_r60 = CPyObject_GetAttr(cpy_r_r58, cpy_r_r59);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "<module>", 15, CPyStatic_numeric___globals);
        goto CPyL18;
    }
    CPyStatic_numeric___Decimal = cpy_r_r60;
    CPy_INCREF(CPyStatic_numeric___Decimal);
    cpy_r_r61 = CPyStatic_numeric___globals;
    cpy_r_r62 = CPyStatics[179]; /* 'Decimal' */
    cpy_r_r63 = CPyDict_SetItem(cpy_r_r61, cpy_r_r62, cpy_r_r60);
    CPy_DECREF(cpy_r_r60);
    cpy_r_r64 = cpy_r_r63 >= 0;
    if (unlikely(!cpy_r_r64)) {
        CPy_AddTraceback("faster_eth_abi/utils/numeric.py", "<module>", 15, CPyStatic_numeric___globals);
        goto CPyL18;
    }
    return 1;
CPyL18: ;
    cpy_r_r65 = 2;
    return cpy_r_r65;
}
static int padding_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_faster_eth_abi___utils___padding_internal, "__name__");
    CPyStatic_padding___globals = PyModule_GetDict(CPyModule_faster_eth_abi___utils___padding_internal);
    if (unlikely(CPyStatic_padding___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_padding_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_faster_eth_abi___utils___padding_internal);
    Py_CLEAR(modname);
    return -1;
}
static PyMethodDef paddingmodule_methods[] = {
    {"zpad", (PyCFunction)CPyPy_padding___zpad, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"zpad32", (PyCFunction)CPyPy_padding___zpad32, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"zpad_right", (PyCFunction)CPyPy_padding___zpad_right, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"zpad32_right", (PyCFunction)CPyPy_padding___zpad32_right, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"fpad", (PyCFunction)CPyPy_padding___fpad, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"fpad32", (PyCFunction)CPyPy_padding___fpad32, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef paddingmodule = {
    PyModuleDef_HEAD_INIT,
    "faster_eth_abi.utils.padding",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    paddingmodule_methods,
    NULL,
};

PyObject *CPyInit_faster_eth_abi___utils___padding(void)
{
    if (CPyModule_faster_eth_abi___utils___padding_internal) {
        Py_INCREF(CPyModule_faster_eth_abi___utils___padding_internal);
        return CPyModule_faster_eth_abi___utils___padding_internal;
    }
    CPyModule_faster_eth_abi___utils___padding_internal = PyModule_Create(&paddingmodule);
    if (unlikely(CPyModule_faster_eth_abi___utils___padding_internal == NULL))
        goto fail;
    if (padding_exec(CPyModule_faster_eth_abi___utils___padding_internal) != 0)
        goto fail;
    return CPyModule_faster_eth_abi___utils___padding_internal;
    fail:
    return NULL;
}

PyObject *CPyDef_padding___zpad(PyObject *cpy_r_value, CPyTagged cpy_r_length) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    cpy_r_r0 = CPyStatics[190]; /* b'\x00' */
    cpy_r_r1 = CPyStatics[26]; /* 'rjust' */
    CPyTagged_INCREF(cpy_r_length);
    cpy_r_r2 = CPyTagged_StealAsObject(cpy_r_length);
    PyObject *cpy_r_r3[3] = {cpy_r_value, cpy_r_r2, cpy_r_r0};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_VectorcallMethod(cpy_r_r1, cpy_r_r4, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/padding.py", "zpad", 2, CPyStatic_padding___globals);
        goto CPyL4;
    }
    CPy_DECREF(cpy_r_r2);
    if (likely(PyBytes_Check(cpy_r_r5) || PyByteArray_Check(cpy_r_r5)))
        cpy_r_r6 = cpy_r_r5;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/utils/padding.py", "zpad", 2, CPyStatic_padding___globals, "bytes", cpy_r_r5);
        goto CPyL3;
    }
    return cpy_r_r6;
CPyL3: ;
    cpy_r_r7 = NULL;
    return cpy_r_r7;
CPyL4: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL3;
}

PyObject *CPyPy_padding___zpad(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"value", "length", 0};
    static CPyArg_Parser parser = {"OO:zpad", kwlist, 0};
    PyObject *obj_value;
    PyObject *obj_length;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_value, &obj_length)) {
        return NULL;
    }
    PyObject *arg_value;
    if (likely(PyBytes_Check(obj_value) || PyByteArray_Check(obj_value)))
        arg_value = obj_value;
    else {
        CPy_TypeError("bytes", obj_value); 
        goto fail;
    }
    CPyTagged arg_length;
    if (likely(PyLong_Check(obj_length)))
        arg_length = CPyTagged_BorrowFromObject(obj_length);
    else {
        CPy_TypeError("int", obj_length); goto fail;
    }
    PyObject *retval = CPyDef_padding___zpad(arg_value, arg_length);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/padding.py", "zpad", 1, CPyStatic_padding___globals);
    return NULL;
}

PyObject *CPyDef_padding___zpad32(PyObject *cpy_r_value) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    cpy_r_r0 = CPyDef_padding___zpad(cpy_r_value, 64);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/padding.py", "zpad32", 6, CPyStatic_padding___globals);
        goto CPyL2;
    }
    return cpy_r_r0;
CPyL2: ;
    cpy_r_r1 = NULL;
    return cpy_r_r1;
}

PyObject *CPyPy_padding___zpad32(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"value", 0};
    static CPyArg_Parser parser = {"O:zpad32", kwlist, 0};
    PyObject *obj_value;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_value)) {
        return NULL;
    }
    PyObject *arg_value;
    if (likely(PyBytes_Check(obj_value) || PyByteArray_Check(obj_value)))
        arg_value = obj_value;
    else {
        CPy_TypeError("bytes", obj_value); 
        goto fail;
    }
    PyObject *retval = CPyDef_padding___zpad32(arg_value);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/padding.py", "zpad32", 5, CPyStatic_padding___globals);
    return NULL;
}

PyObject *CPyDef_padding___zpad_right(PyObject *cpy_r_value, CPyTagged cpy_r_length) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    cpy_r_r0 = CPyStatics[190]; /* b'\x00' */
    cpy_r_r1 = CPyStatics[27]; /* 'ljust' */
    CPyTagged_INCREF(cpy_r_length);
    cpy_r_r2 = CPyTagged_StealAsObject(cpy_r_length);
    PyObject *cpy_r_r3[3] = {cpy_r_value, cpy_r_r2, cpy_r_r0};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_VectorcallMethod(cpy_r_r1, cpy_r_r4, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/padding.py", "zpad_right", 10, CPyStatic_padding___globals);
        goto CPyL4;
    }
    CPy_DECREF(cpy_r_r2);
    if (likely(PyBytes_Check(cpy_r_r5) || PyByteArray_Check(cpy_r_r5)))
        cpy_r_r6 = cpy_r_r5;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/utils/padding.py", "zpad_right", 10, CPyStatic_padding___globals, "bytes", cpy_r_r5);
        goto CPyL3;
    }
    return cpy_r_r6;
CPyL3: ;
    cpy_r_r7 = NULL;
    return cpy_r_r7;
CPyL4: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL3;
}

PyObject *CPyPy_padding___zpad_right(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"value", "length", 0};
    static CPyArg_Parser parser = {"OO:zpad_right", kwlist, 0};
    PyObject *obj_value;
    PyObject *obj_length;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_value, &obj_length)) {
        return NULL;
    }
    PyObject *arg_value;
    if (likely(PyBytes_Check(obj_value) || PyByteArray_Check(obj_value)))
        arg_value = obj_value;
    else {
        CPy_TypeError("bytes", obj_value); 
        goto fail;
    }
    CPyTagged arg_length;
    if (likely(PyLong_Check(obj_length)))
        arg_length = CPyTagged_BorrowFromObject(obj_length);
    else {
        CPy_TypeError("int", obj_length); goto fail;
    }
    PyObject *retval = CPyDef_padding___zpad_right(arg_value, arg_length);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/padding.py", "zpad_right", 9, CPyStatic_padding___globals);
    return NULL;
}

PyObject *CPyDef_padding___zpad32_right(PyObject *cpy_r_value) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    cpy_r_r0 = CPyDef_padding___zpad_right(cpy_r_value, 64);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/padding.py", "zpad32_right", 14, CPyStatic_padding___globals);
        goto CPyL2;
    }
    return cpy_r_r0;
CPyL2: ;
    cpy_r_r1 = NULL;
    return cpy_r_r1;
}

PyObject *CPyPy_padding___zpad32_right(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"value", 0};
    static CPyArg_Parser parser = {"O:zpad32_right", kwlist, 0};
    PyObject *obj_value;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_value)) {
        return NULL;
    }
    PyObject *arg_value;
    if (likely(PyBytes_Check(obj_value) || PyByteArray_Check(obj_value)))
        arg_value = obj_value;
    else {
        CPy_TypeError("bytes", obj_value); 
        goto fail;
    }
    PyObject *retval = CPyDef_padding___zpad32_right(arg_value);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/padding.py", "zpad32_right", 13, CPyStatic_padding___globals);
    return NULL;
}

PyObject *CPyDef_padding___fpad(PyObject *cpy_r_value, CPyTagged cpy_r_length) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    cpy_r_r0 = CPyStatics[191]; /* b'\xff' */
    cpy_r_r1 = CPyStatics[26]; /* 'rjust' */
    CPyTagged_INCREF(cpy_r_length);
    cpy_r_r2 = CPyTagged_StealAsObject(cpy_r_length);
    PyObject *cpy_r_r3[3] = {cpy_r_value, cpy_r_r2, cpy_r_r0};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_VectorcallMethod(cpy_r_r1, cpy_r_r4, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/padding.py", "fpad", 18, CPyStatic_padding___globals);
        goto CPyL4;
    }
    CPy_DECREF(cpy_r_r2);
    if (likely(PyBytes_Check(cpy_r_r5) || PyByteArray_Check(cpy_r_r5)))
        cpy_r_r6 = cpy_r_r5;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/utils/padding.py", "fpad", 18, CPyStatic_padding___globals, "bytes", cpy_r_r5);
        goto CPyL3;
    }
    return cpy_r_r6;
CPyL3: ;
    cpy_r_r7 = NULL;
    return cpy_r_r7;
CPyL4: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL3;
}

PyObject *CPyPy_padding___fpad(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"value", "length", 0};
    static CPyArg_Parser parser = {"OO:fpad", kwlist, 0};
    PyObject *obj_value;
    PyObject *obj_length;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_value, &obj_length)) {
        return NULL;
    }
    PyObject *arg_value;
    if (likely(PyBytes_Check(obj_value) || PyByteArray_Check(obj_value)))
        arg_value = obj_value;
    else {
        CPy_TypeError("bytes", obj_value); 
        goto fail;
    }
    CPyTagged arg_length;
    if (likely(PyLong_Check(obj_length)))
        arg_length = CPyTagged_BorrowFromObject(obj_length);
    else {
        CPy_TypeError("int", obj_length); goto fail;
    }
    PyObject *retval = CPyDef_padding___fpad(arg_value, arg_length);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/padding.py", "fpad", 17, CPyStatic_padding___globals);
    return NULL;
}

PyObject *CPyDef_padding___fpad32(PyObject *cpy_r_value) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    cpy_r_r0 = CPyDef_padding___fpad(cpy_r_value, 64);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/padding.py", "fpad32", 22, CPyStatic_padding___globals);
        goto CPyL2;
    }
    return cpy_r_r0;
CPyL2: ;
    cpy_r_r1 = NULL;
    return cpy_r_r1;
}

PyObject *CPyPy_padding___fpad32(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"value", 0};
    static CPyArg_Parser parser = {"O:fpad32", kwlist, 0};
    PyObject *obj_value;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_value)) {
        return NULL;
    }
    PyObject *arg_value;
    if (likely(PyBytes_Check(obj_value) || PyByteArray_Check(obj_value)))
        arg_value = obj_value;
    else {
        CPy_TypeError("bytes", obj_value); 
        goto fail;
    }
    PyObject *retval = CPyDef_padding___fpad32(arg_value);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/padding.py", "fpad32", 21, CPyStatic_padding___globals);
    return NULL;
}

char CPyDef_padding_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[11]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/padding.py", "<module>", -1, CPyStatic_padding___globals);
        goto CPyL4;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    return 1;
CPyL4: ;
    cpy_r_r5 = 2;
    return cpy_r_r5;
}
static int string_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_faster_eth_abi___utils___string_internal, "__name__");
    CPyStatic_string___globals = PyModule_GetDict(CPyModule_faster_eth_abi___utils___string_internal);
    if (unlikely(CPyStatic_string___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_string_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_faster_eth_abi___utils___string_internal);
    Py_CLEAR(modname);
    return -1;
}
static PyMethodDef stringmodule_methods[] = {
    {"abbr", (PyCFunction)CPyPy_string___abbr, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef stringmodule = {
    PyModuleDef_HEAD_INIT,
    "faster_eth_abi.utils.string",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    stringmodule_methods,
    NULL,
};

PyObject *CPyInit_faster_eth_abi___utils___string(void)
{
    if (CPyModule_faster_eth_abi___utils___string_internal) {
        Py_INCREF(CPyModule_faster_eth_abi___utils___string_internal);
        return CPyModule_faster_eth_abi___utils___string_internal;
    }
    CPyModule_faster_eth_abi___utils___string_internal = PyModule_Create(&stringmodule);
    if (unlikely(CPyModule_faster_eth_abi___utils___string_internal == NULL))
        goto fail;
    if (string_exec(CPyModule_faster_eth_abi___utils___string_internal) != 0)
        goto fail;
    return CPyModule_faster_eth_abi___utils___string_internal;
    fail:
    return NULL;
}

PyObject *CPyDef_string___abbr(PyObject *cpy_r_value, CPyTagged cpy_r_limit) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_rep;
    int64_t cpy_r_r1;
    char cpy_r_r2;
    CPyTagged cpy_r_r3;
    int64_t cpy_r_r4;
    char cpy_r_r5;
    int64_t cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    char cpy_r_r9;
    int64_t cpy_r_r10;
    char cpy_r_r11;
    int64_t cpy_r_r12;
    char cpy_r_r13;
    char cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    CPyTagged cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    if (cpy_r_limit != CPY_INT_TAG) goto CPyL22;
    cpy_r_limit = 158;
CPyL2: ;
    cpy_r_r0 = PyObject_Repr(cpy_r_value);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/string.py", "abbr", 11, CPyStatic_string___globals);
        goto CPyL23;
    }
    cpy_r_rep = cpy_r_r0;
    cpy_r_r1 = CPyStr_Size_size_t(cpy_r_rep);
    cpy_r_r2 = cpy_r_r1 >= 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("faster_eth_abi/utils/string.py", "abbr", 13, CPyStatic_string___globals);
        goto CPyL24;
    }
    cpy_r_r3 = cpy_r_r1 << 1;
    cpy_r_r4 = cpy_r_r3 & 1;
    cpy_r_r5 = cpy_r_r4 != 0;
    if (cpy_r_r5) goto CPyL6;
    cpy_r_r6 = cpy_r_limit & 1;
    cpy_r_r7 = cpy_r_r6 != 0;
    if (!cpy_r_r7) goto CPyL7;
CPyL6: ;
    cpy_r_r8 = CPyTagged_IsLt_(cpy_r_limit, cpy_r_r3);
    if (cpy_r_r8) {
        goto CPyL8;
    } else
        goto CPyL25;
CPyL7: ;
    cpy_r_r9 = (Py_ssize_t)cpy_r_r3 > (Py_ssize_t)cpy_r_limit;
    if (!cpy_r_r9) goto CPyL25;
CPyL8: ;
    cpy_r_r10 = cpy_r_limit & 1;
    cpy_r_r11 = cpy_r_r10 != 0;
    if (cpy_r_r11) goto CPyL10;
    cpy_r_r12 = 6 & 1;
    cpy_r_r13 = cpy_r_r12 != 0;
    if (!cpy_r_r13) goto CPyL11;
CPyL10: ;
    cpy_r_r14 = CPyTagged_IsLt_(cpy_r_limit, 6);
    if (cpy_r_r14) {
        goto CPyL26;
    } else
        goto CPyL16;
CPyL11: ;
    cpy_r_r15 = (Py_ssize_t)cpy_r_limit < (Py_ssize_t)6;
    if (cpy_r_r15) {
        goto CPyL26;
    } else
        goto CPyL16;
CPyL12: ;
    cpy_r_r16 = CPyStatics[182]; /* 'Abbreviation limit may not be less than 3' */
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[63]; /* 'ValueError' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/string.py", "abbr", 15, CPyStatic_string___globals);
        goto CPyL21;
    }
    PyObject *cpy_r_r20[1] = {cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/string.py", "abbr", 15, CPyStatic_string___globals);
        goto CPyL21;
    }
    CPy_Raise(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_eth_abi/utils/string.py", "abbr", 15, CPyStatic_string___globals);
        goto CPyL21;
    }
    CPy_Unreachable();
CPyL16: ;
    cpy_r_r23 = CPyTagged_Subtract(cpy_r_limit, 6);
    CPyTagged_DECREF(cpy_r_limit);
    cpy_r_r24 = CPyStr_GetSlice(cpy_r_rep, 0, cpy_r_r23);
    CPy_DECREF(cpy_r_rep);
    CPyTagged_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/string.py", "abbr", 17, CPyStatic_string___globals);
        goto CPyL21;
    }
    if (likely(PyUnicode_Check(cpy_r_r24)))
        cpy_r_r25 = cpy_r_r24;
    else {
        CPy_TypeErrorTraceback("faster_eth_abi/utils/string.py", "abbr", 17, CPyStatic_string___globals, "str", cpy_r_r24);
        goto CPyL21;
    }
    cpy_r_r26 = CPyStatics[183]; /* '...' */
    cpy_r_r27 = PyUnicode_Concat(cpy_r_r25, cpy_r_r26);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/string.py", "abbr", 17, CPyStatic_string___globals);
        goto CPyL21;
    }
    cpy_r_rep = cpy_r_r27;
CPyL20: ;
    return cpy_r_rep;
CPyL21: ;
    cpy_r_r28 = NULL;
    return cpy_r_r28;
CPyL22: ;
    CPyTagged_INCREF(cpy_r_limit);
    goto CPyL2;
CPyL23: ;
    CPyTagged_DecRef(cpy_r_limit);
    goto CPyL21;
CPyL24: ;
    CPyTagged_DecRef(cpy_r_limit);
    CPy_DecRef(cpy_r_rep);
    goto CPyL21;
CPyL25: ;
    CPyTagged_DECREF(cpy_r_limit);
    goto CPyL20;
CPyL26: ;
    CPyTagged_DECREF(cpy_r_limit);
    CPy_DECREF(cpy_r_rep);
    goto CPyL12;
}

PyObject *CPyPy_string___abbr(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"value", "limit", 0};
    static CPyArg_Parser parser = {"O|O:abbr", kwlist, 0};
    PyObject *obj_value;
    PyObject *obj_limit = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_value, &obj_limit)) {
        return NULL;
    }
    PyObject *arg_value = obj_value;
    CPyTagged arg_limit;
    if (obj_limit == NULL) {
        arg_limit = CPY_INT_TAG;
    } else if (likely(PyLong_Check(obj_limit)))
        arg_limit = CPyTagged_BorrowFromObject(obj_limit);
    else {
        CPy_TypeError("int", obj_limit); goto fail;
    }
    PyObject *retval = CPyDef_string___abbr(arg_value, arg_limit);
    return retval;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/string.py", "abbr", 6, CPyStatic_string___globals);
    return NULL;
}

char CPyDef_string_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[11]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/string.py", "<module>", -1, CPyStatic_string___globals);
        goto CPyL5;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[236]; /* ('Any',) */
    cpy_r_r6 = CPyStatics[17]; /* 'typing' */
    cpy_r_r7 = CPyStatic_string___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/string.py", "<module>", 1, CPyStatic_string___globals);
        goto CPyL5;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    return 1;
CPyL5: ;
    cpy_r_r9 = 2;
    return cpy_r_r9;
}
static int validation_exec(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_faster_eth_abi___utils___validation_internal, "__name__");
    CPyStatic_validation___globals = PyModule_GetDict(CPyModule_faster_eth_abi___utils___validation_internal);
    if (unlikely(CPyStatic_validation___globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef_validation_____top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_faster_eth_abi___utils___validation_internal);
    Py_CLEAR(modname);
    return -1;
}
static PyMethodDef validationmodule_methods[] = {
    {"validate_bytes_param", (PyCFunction)CPyPy_validation___validate_bytes_param, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"validate_list_like_param", (PyCFunction)CPyPy_validation___validate_list_like_param, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef validationmodule = {
    PyModuleDef_HEAD_INIT,
    "faster_eth_abi.utils.validation",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    validationmodule_methods,
    NULL,
};

PyObject *CPyInit_faster_eth_abi___utils___validation(void)
{
    if (CPyModule_faster_eth_abi___utils___validation_internal) {
        Py_INCREF(CPyModule_faster_eth_abi___utils___validation_internal);
        return CPyModule_faster_eth_abi___utils___validation_internal;
    }
    CPyModule_faster_eth_abi___utils___validation_internal = PyModule_Create(&validationmodule);
    if (unlikely(CPyModule_faster_eth_abi___utils___validation_internal == NULL))
        goto fail;
    if (validation_exec(CPyModule_faster_eth_abi___utils___validation_internal) != 0)
        goto fail;
    return CPyModule_faster_eth_abi___utils___validation_internal;
    fail:
    return NULL;
}

char CPyDef_validation___validate_bytes_param(PyObject *cpy_r_param, PyObject *cpy_r_param_name) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    tuple_T2OO cpy_r_r4;
    PyObject *cpy_r_r5;
    int32_t cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject **cpy_r_r18;
    PyObject *cpy_r_r19;
    char cpy_r_r20;
    cpy_r_r0 = (PyObject *)&PyBytes_Type;
    cpy_r_r1 = CPyModule_builtins;
    cpy_r_r2 = CPyStatics[184]; /* 'bytearray' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/validation.py", "validate_bytes_param", 7, CPyStatic_validation___globals);
        goto CPyL10;
    }
    CPy_INCREF(cpy_r_r0);
    cpy_r_r4.f0 = cpy_r_r0;
    cpy_r_r4.f1 = cpy_r_r3;
    cpy_r_r5 = PyTuple_New(2);
    if (unlikely(cpy_r_r5 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp33 = cpy_r_r4.f0;
    PyTuple_SET_ITEM(cpy_r_r5, 0, __tmp33);
    PyObject *__tmp34 = cpy_r_r4.f1;
    PyTuple_SET_ITEM(cpy_r_r5, 1, __tmp34);
    cpy_r_r6 = PyObject_IsInstance(cpy_r_param, cpy_r_r5);
    CPy_DECREF(cpy_r_r5);
    cpy_r_r7 = cpy_r_r6 >= 0;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("faster_eth_abi/utils/validation.py", "validate_bytes_param", 7, CPyStatic_validation___globals);
        goto CPyL10;
    }
    cpy_r_r8 = cpy_r_r6;
    if (cpy_r_r8) goto CPyL9;
    cpy_r_r9 = CPyStatics[185]; /* 'The `' */
    cpy_r_r10 = CPyStatics[186]; /* '` value must be of bytes type. Got ' */
    cpy_r_r11 = PyObject_Type(cpy_r_param);
    cpy_r_r12 = PyObject_Str(cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/validation.py", "validate_bytes_param", 9, CPyStatic_validation___globals);
        goto CPyL10;
    }
    cpy_r_r13 = CPyStr_Build(4, cpy_r_r9, cpy_r_param_name, cpy_r_r10, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/validation.py", "validate_bytes_param", 9, CPyStatic_validation___globals);
        goto CPyL10;
    }
    cpy_r_r14 = CPyModule_builtins;
    cpy_r_r15 = CPyStatics[187]; /* 'TypeError' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/validation.py", "validate_bytes_param", 8, CPyStatic_validation___globals);
        goto CPyL11;
    }
    PyObject *cpy_r_r17[1] = {cpy_r_r13};
    cpy_r_r18 = (PyObject **)&cpy_r_r17;
    cpy_r_r19 = PyObject_Vectorcall(cpy_r_r16, cpy_r_r18, 1, 0);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/validation.py", "validate_bytes_param", 8, CPyStatic_validation___globals);
        goto CPyL11;
    }
    CPy_DECREF(cpy_r_r13);
    CPy_Raise(cpy_r_r19);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_eth_abi/utils/validation.py", "validate_bytes_param", 8, CPyStatic_validation___globals);
        goto CPyL10;
    }
    CPy_Unreachable();
CPyL9: ;
    return 1;
CPyL10: ;
    cpy_r_r20 = 2;
    return cpy_r_r20;
CPyL11: ;
    CPy_DecRef(cpy_r_r13);
    goto CPyL10;
}

PyObject *CPyPy_validation___validate_bytes_param(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"param", "param_name", 0};
    static CPyArg_Parser parser = {"OO:validate_bytes_param", kwlist, 0};
    PyObject *obj_param;
    PyObject *obj_param_name;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_param, &obj_param_name)) {
        return NULL;
    }
    PyObject *arg_param = obj_param;
    PyObject *arg_param_name;
    if (likely(PyUnicode_Check(obj_param_name)))
        arg_param_name = obj_param_name;
    else {
        CPy_TypeError("str", obj_param_name); 
        goto fail;
    }
    char retval = CPyDef_validation___validate_bytes_param(arg_param, arg_param_name);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/validation.py", "validate_bytes_param", 6, CPyStatic_validation___globals);
    return NULL;
}

char CPyDef_validation___validate_list_like_param(PyObject *cpy_r_param, PyObject *cpy_r_param_name) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    tuple_T2OO cpy_r_r2;
    PyObject *cpy_r_r3;
    int32_t cpy_r_r4;
    char cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject **cpy_r_r16;
    PyObject *cpy_r_r17;
    char cpy_r_r18;
    cpy_r_r0 = (PyObject *)&PyList_Type;
    cpy_r_r1 = (PyObject *)&PyTuple_Type;
    CPy_INCREF(cpy_r_r0);
    CPy_INCREF(cpy_r_r1);
    cpy_r_r2.f0 = cpy_r_r0;
    cpy_r_r2.f1 = cpy_r_r1;
    cpy_r_r3 = PyTuple_New(2);
    if (unlikely(cpy_r_r3 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp35 = cpy_r_r2.f0;
    PyTuple_SET_ITEM(cpy_r_r3, 0, __tmp35);
    PyObject *__tmp36 = cpy_r_r2.f1;
    PyTuple_SET_ITEM(cpy_r_r3, 1, __tmp36);
    cpy_r_r4 = PyObject_IsInstance(cpy_r_param, cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    cpy_r_r5 = cpy_r_r4 >= 0;
    if (unlikely(!cpy_r_r5)) {
        CPy_AddTraceback("faster_eth_abi/utils/validation.py", "validate_list_like_param", 14, CPyStatic_validation___globals);
        goto CPyL9;
    }
    cpy_r_r6 = cpy_r_r4;
    if (cpy_r_r6) goto CPyL8;
    cpy_r_r7 = CPyStatics[185]; /* 'The `' */
    cpy_r_r8 = CPyStatics[188]; /* '` value type must be one of list or tuple. Got ' */
    cpy_r_r9 = PyObject_Type(cpy_r_param);
    cpy_r_r10 = PyObject_Str(cpy_r_r9);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/validation.py", "validate_list_like_param", 16, CPyStatic_validation___globals);
        goto CPyL9;
    }
    cpy_r_r11 = CPyStr_Build(4, cpy_r_r7, cpy_r_param_name, cpy_r_r8, cpy_r_r10);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/validation.py", "validate_list_like_param", 16, CPyStatic_validation___globals);
        goto CPyL9;
    }
    cpy_r_r12 = CPyModule_builtins;
    cpy_r_r13 = CPyStatics[187]; /* 'TypeError' */
    cpy_r_r14 = CPyObject_GetAttr(cpy_r_r12, cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/validation.py", "validate_list_like_param", 15, CPyStatic_validation___globals);
        goto CPyL10;
    }
    PyObject *cpy_r_r15[1] = {cpy_r_r11};
    cpy_r_r16 = (PyObject **)&cpy_r_r15;
    cpy_r_r17 = PyObject_Vectorcall(cpy_r_r14, cpy_r_r16, 1, 0);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/validation.py", "validate_list_like_param", 15, CPyStatic_validation___globals);
        goto CPyL10;
    }
    CPy_DECREF(cpy_r_r11);
    CPy_Raise(cpy_r_r17);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(!0)) {
        CPy_AddTraceback("faster_eth_abi/utils/validation.py", "validate_list_like_param", 15, CPyStatic_validation___globals);
        goto CPyL9;
    }
    CPy_Unreachable();
CPyL8: ;
    return 1;
CPyL9: ;
    cpy_r_r18 = 2;
    return cpy_r_r18;
CPyL10: ;
    CPy_DecRef(cpy_r_r11);
    goto CPyL9;
}

PyObject *CPyPy_validation___validate_list_like_param(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"param", "param_name", 0};
    static CPyArg_Parser parser = {"OO:validate_list_like_param", kwlist, 0};
    PyObject *obj_param;
    PyObject *obj_param_name;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_param, &obj_param_name)) {
        return NULL;
    }
    PyObject *arg_param = obj_param;
    PyObject *arg_param_name;
    if (likely(PyUnicode_Check(obj_param_name)))
        arg_param_name = obj_param_name;
    else {
        CPy_TypeError("str", obj_param_name); 
        goto fail;
    }
    char retval = CPyDef_validation___validate_list_like_param(arg_param, arg_param_name);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("faster_eth_abi/utils/validation.py", "validate_list_like_param", 13, CPyStatic_validation___globals);
    return NULL;
}

char CPyDef_validation_____top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[11]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/validation.py", "<module>", -1, CPyStatic_validation___globals);
        goto CPyL5;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[236]; /* ('Any',) */
    cpy_r_r6 = CPyStatics[17]; /* 'typing' */
    cpy_r_r7 = CPyStatic_validation___globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("faster_eth_abi/utils/validation.py", "<module>", 1, CPyStatic_validation___globals);
        goto CPyL5;
    }
    CPyModule_typing = cpy_r_r8;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r8);
    return 1;
CPyL5: ;
    cpy_r_r9 = 2;
    return cpy_r_r9;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_faster_eth_abi____codec = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_eth_typing = Py_None;
    CPyModule_faster_eth_abi___utils___validation = Py_None;
    CPyModule_faster_eth_abi____encoding = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_itertools = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_faster_eth_abi___abi = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_faster_eth_abi___codec = Py_None;
    CPyModule_faster_eth_abi___registry = Py_None;
    CPyModule_faster_eth_abi___constants = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_faster_eth_abi___from_type_str = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_functools = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_eth_typing = Py_None;
    CPyModule_faster_eth_abi___grammar = Py_None;
    CPyModule_faster_eth_abi___packed = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_faster_eth_abi___codec = Py_None;
    CPyModule_faster_eth_abi___registry = Py_None;
    CPyModule_faster_eth_abi___tools = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_faster_eth_abi___tools____strategies = Py_None;
    CPyModule_faster_eth_abi___tools____strategies = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_cchecksum = Py_None;
    CPyModule_eth_typing___abi = Py_None;
    CPyModule_hypothesis = Py_None;
    CPyModule_faster_eth_abi___grammar = Py_None;
    CPyModule_faster_eth_abi___registry = Py_None;
    CPyModule_faster_eth_abi___utils___numeric = Py_None;
    CPyModule_faster_eth_abi___utils = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_faster_eth_abi___utils___numeric = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_decimal = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_faster_eth_abi___utils___padding = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_faster_eth_abi___utils___string = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_faster_eth_abi___utils___validation = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_typing = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[237];
const char * const CPyLit_Str[] = {
    "\a\005types\004args\t_registry\021get_tuple_encoder\004data\021get_tuple_decoder\006strict",
    "\b\fstream_class\bbuiltins\rTYPE_CHECKING\003Any\bIterable\005Tuple\004cast\006typing",
    "\004\tDecodable\aTypeStr\neth_typing\024validate_bytes_param",
    "\003\030validate_list_like_param\037faster_eth_abi.utils.validation\nis_dynamic",
    "\b\naccumulate\005rjust\005ljust\nbit_length\003big\bto_bytes\titertools\bCallable",
    "\b\004List\bOptional\bSequence\aTypeVar\001T\005Final\bABICodec\024faster_eth_abi.codec",
    "\005\bregistry\027faster_eth_abi.registry\rdefault_codec\006encode\006decode",
    "\b\fis_encodable\021is_encodable_type\005TT256\aTT256M1\005TT255\tnormalize\005parse\000",
    "\a\005{:{}}\006format\020 (normalized to \a{!r:{}}\001)\tBasicType\b__name__",
    "\005\016Cannot create \024 for non-basic type \nValueError\004base\n for type ",
    "\003\033: expected type with base \'\001\'\aarrlist",
    "\001,: expected type with no array dimension list",
    "\003): expected type with array dimension list\bvalidate\005wraps",
    "\004\021new_from_type_str\vclassmethod\tTupleType\024 for non-tuple type ",
    "\005\tfunctools\037faster_eth_abi/from_type_str.py\b<module>\004Type\aABIType",
    "\005\026faster_eth_abi.grammar\005TType\tBaseCoder\005bound\016OldFromTypeStr",
    "\004\016NewFromTypeStr\nABIEncoder\017registry_packed\026default_encoder_packed",
    "\003\rencode_packed\023is_encodable_packed\020get_abi_strategy",
    "\003 faster_eth_abi.tools._strategies\021strategy registry\020PredicateMapping",
    "\a\t_register\005label\v_unregister\021_get_registration\002st\016SearchStrategy\003sub",
    "\b\bintegers\tmin_value\tmax_value\bdecimals\006places\003map\006binary\bmin_size",
    "\a\bmax_size\titem_type\vto_type_str\005lists\ncomponents\006tuples\005Union",
    "\005\023to_checksum_address\tcchecksum\016eth_typing.abi\nstrategies\nhypothesis",
    "\006\nBaseEquals\fBaseRegistry\006Lookup\vhas_arrlist\ris_base_tuple\fscale_places",
    "\003\034faster_eth_abi.utils.numeric\020StrategyRegistry\017StrategyFactory",
    "\004\024StrategyRegistration\017__mypyc_attrs__\v_strategies\b__dict__",
    "\005\020address_strategy\bbooleans\rbool_strategy\016bytes_strategy\004text",
    "\005\017string_strategy\021strategy_registry\004uint\021get_uint_strategy\003int",
    "\006\020get_int_strategy\aaddress\bwith_sub\004bool\006ufixed\023get_ufixed_strategy",
    "\006\005fixed\022get_fixed_strategy\005bytes\022get_bytes_strategy\bbytes<M>\bfunction",
    "\004\006string\022get_array_strategy\022get_tuple_strategy\fget_strategy",
    "\003\flocalcontext\b__exit__\t__enter__",
    "\005*Argument `places` must be int.  Got value \t of type \001.\004Eneg\004Epos",
    "\004\tscale_by_\f__qualname__\adecimal\037faster_eth_abi/utils/numeric.py",
    "\a\020ABI_DECIMAL_PREC\aContext\004prec\023abi_decimal_context\aDecimal\004ZERO\003TEN",
    "\004)Abbreviation limit may not be less than 3\003...\tbytearray\005The `",
    "\002#` value must be of bytes type. Got \tTypeError",
    "\001/` value type must be one of list or tuple. Got ",
    "",
};
const char * const CPyLit_Bytes[] = {
    "\003\000\001\000\001\377",
    "",
};
const char * const CPyLit_Int[] = {
    "\0020\00032",
    "\001115792089237316195423570985008687907853269984665640564039457584007913129639936",
    "\001115792089237316195423570985008687907853269984665640564039457584007913129639935",
    "\00157896044618658097711785492504343953926634992332820282019728792003956564819968",
    "\a2\0001\000-1\00020\0004096\000999\00010",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    33, 5, 12, 13, 14, 15, 16, 2, 18, 19, 2, 21, 22, 1, 25, 7, 12, 13,
    32, 33, 34, 35, 36, 1, 38, 1, 39, 1, 41, 3, 77, 77, 77, 1, 212, 6, 12,
    13, 32, 34, 80, 36, 1, 19, 5, 81, 59, 75, 51, 52, 1, 85, 1, 88, 1, 89,
    1, 93, 1, 98, 2, 105, 106, 3, 105, 106, 108, 2, 111, 112, 4, 32, 38,
    34, 118, 1, 119, 1, 122, 1, 101, 6, 124, 125, 126, 96, 127, 128, 1,
    129, 1, 149, 3, 173, 173, 173, 1, 232, 3, 32, 38, 15, 1, 177, 1, 13
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_faster_eth_abi____codec_internal = NULL;
CPyModule *CPyModule_faster_eth_abi____codec;
PyObject *CPyStatic__codec___globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_eth_typing;
CPyModule *CPyModule_faster_eth_abi___utils___validation_internal = NULL;
CPyModule *CPyModule_faster_eth_abi___utils___validation;
CPyModule *CPyModule_faster_eth_abi____encoding_internal = NULL;
CPyModule *CPyModule_faster_eth_abi____encoding;
PyObject *CPyStatic__encoding___globals;
CPyModule *CPyModule_itertools;
CPyModule *CPyModule_faster_eth_abi___abi_internal = NULL;
CPyModule *CPyModule_faster_eth_abi___abi;
PyObject *CPyStatic_abi___globals;
CPyModule *CPyModule_faster_eth_abi___codec;
CPyModule *CPyModule_faster_eth_abi___registry;
CPyModule *CPyModule_faster_eth_abi___constants_internal = NULL;
CPyModule *CPyModule_faster_eth_abi___constants;
PyObject *CPyStatic_constants___globals;
CPyModule *CPyModule_faster_eth_abi___from_type_str_internal = NULL;
CPyModule *CPyModule_faster_eth_abi___from_type_str;
PyObject *CPyStatic_from_type_str___globals;
CPyModule *CPyModule_functools;
CPyModule *CPyModule_faster_eth_abi___grammar;
CPyModule *CPyModule_faster_eth_abi___packed_internal = NULL;
CPyModule *CPyModule_faster_eth_abi___packed;
PyObject *CPyStatic_packed___globals;
CPyModule *CPyModule_faster_eth_abi___tools_internal = NULL;
CPyModule *CPyModule_faster_eth_abi___tools;
PyObject *CPyStatic_tools___globals;
CPyModule *CPyModule_faster_eth_abi___tools____strategies_internal = NULL;
CPyModule *CPyModule_faster_eth_abi___tools____strategies;
PyObject *CPyStatic__strategies___globals;
CPyModule *CPyModule_cchecksum;
CPyModule *CPyModule_eth_typing___abi;
CPyModule *CPyModule_hypothesis;
CPyModule *CPyModule_faster_eth_abi___utils___numeric_internal = NULL;
CPyModule *CPyModule_faster_eth_abi___utils___numeric;
CPyModule *CPyModule_faster_eth_abi___utils_internal = NULL;
CPyModule *CPyModule_faster_eth_abi___utils;
PyObject *CPyStatic_utils___globals;
PyObject *CPyStatic_numeric___globals;
CPyModule *CPyModule_decimal;
CPyModule *CPyModule_faster_eth_abi___utils___padding_internal = NULL;
CPyModule *CPyModule_faster_eth_abi___utils___padding;
PyObject *CPyStatic_padding___globals;
CPyModule *CPyModule_faster_eth_abi___utils___string_internal = NULL;
CPyModule *CPyModule_faster_eth_abi___utils___string;
PyObject *CPyStatic_string___globals;
PyObject *CPyStatic_validation___globals;
PyObject *CPyDef__codec___encode_c(PyObject *cpy_r_self, PyObject *cpy_r_types, PyObject *cpy_r_args);
PyObject *CPyPy__codec___encode_c(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__codec___decode_c(PyObject *cpy_r_self, PyObject *cpy_r_types, PyObject *cpy_r_data, char cpy_r_strict);
PyObject *CPyPy__codec___decode_c(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__codec_____top_level__(void);
PyObject *CPyDef__encoding___encode_tuple(PyObject *cpy_r_values, PyObject *cpy_r_encoders);
PyObject *CPyPy__encoding___encode_tuple(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__encoding___encode_fixed(PyObject *cpy_r_value, PyObject *cpy_r_encode_fn, char cpy_r_is_big_endian, CPyTagged cpy_r_data_byte_size);
PyObject *CPyPy__encoding___encode_fixed(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__encoding___encode_signed(PyObject *cpy_r_value, PyObject *cpy_r_encode_fn, CPyTagged cpy_r_data_byte_size);
PyObject *CPyPy__encoding___encode_signed(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__encoding___encode_elements(PyObject *cpy_r_item_encoder, PyObject *cpy_r_value);
PyObject *CPyPy__encoding___encode_elements(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__encoding___encode_elements_dynamic(PyObject *cpy_r_item_encoder, PyObject *cpy_r_value);
PyObject *CPyPy__encoding___encode_elements_dynamic(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__encoding___encode_uint_256(CPyTagged cpy_r_i);
PyObject *CPyPy__encoding___encode_uint_256(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__encoding___int_to_big_endian(CPyTagged cpy_r_value);
PyObject *CPyPy__encoding___int_to_big_endian(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__encoding_____top_level__(void);
PyObject *CPyStatic_abi___default_codec = NULL;
PyObject *CPyStatic_abi___encode = NULL;
PyObject *CPyStatic_abi___decode = NULL;
PyObject *CPyStatic_abi___is_encodable = NULL;
PyObject *CPyStatic_abi___is_encodable_type = NULL;
char CPyDef_abi_____top_level__(void);
char CPyDef_constants_____top_level__(void);
PyTypeObject *CPyType_from_type_str___parse_type_str_env;
PyObject *CPyDef_from_type_str___parse_type_str_env(void);
PyTypeObject *CPyType_from_type_str___decorator_parse_type_str_env;
PyObject *CPyDef_from_type_str___decorator_parse_type_str_env(void);
PyTypeObject *CPyType_from_type_str___decorator_parse_type_str_obj;
PyObject *CPyDef_from_type_str___decorator_parse_type_str_obj(void);
PyTypeObject *CPyType_from_type_str___new_from_type_str_parse_type_str_decorator_obj;
PyObject *CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj(void);
PyTypeObject *CPyType_from_type_str___parse_tuple_type_str_env;
PyObject *CPyDef_from_type_str___parse_tuple_type_str_env(void);
PyTypeObject *CPyType_from_type_str___new_from_type_str_parse_tuple_type_str_obj;
PyObject *CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj(void);
PyObject *CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_cls, PyObject *cpy_r_type_str, PyObject *cpy_r_registry);
PyObject *CPyPy_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_from_type_str___decorator_parse_type_str_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy_from_type_str___decorator_parse_type_str_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_from_type_str___decorator_parse_type_str_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_old_from_type_str);
PyObject *CPyPy_from_type_str___decorator_parse_type_str_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_from_type_str___parse_type_str(PyObject *cpy_r_expected_base, char cpy_r_with_arrlist);
PyObject *CPyPy_from_type_str___parse_type_str(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_cls, PyObject *cpy_r_type_str, PyObject *cpy_r_registry);
PyObject *CPyPy_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_from_type_str___parse_tuple_type_str(PyObject *cpy_r_old_from_type_str);
PyObject *CPyPy_from_type_str___parse_tuple_type_str(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_from_type_str_____top_level__(void);
PyObject *CPyStatic_packed___default_encoder_packed = NULL;
PyObject *CPyStatic_packed___encode_packed = NULL;
PyObject *CPyStatic_packed___is_encodable_packed = NULL;
char CPyDef_packed_____top_level__(void);
char CPyDef_tools_____top_level__(void);
PyObject *CPyStatic__strategies___address_strategy = NULL;
PyObject *CPyStatic__strategies___bool_strategy = NULL;
PyObject *CPyStatic__strategies___bytes_strategy = NULL;
PyObject *CPyStatic__strategies___string_strategy = NULL;
PyObject *CPyStatic__strategies___strategy_registry = NULL;
PyObject *CPyStatic__strategies___get_abi_strategy = NULL;
PyTypeObject *CPyType__strategies___StrategyRegistry;
PyObject *CPyDef__strategies___StrategyRegistry(void);
char CPyDef__strategies___StrategyRegistry_____init__(PyObject *cpy_r_self);
PyObject *CPyPy__strategies___StrategyRegistry_____init__(PyObject *self, PyObject *args, PyObject *kw);
char CPyDef__strategies___StrategyRegistry___register_strategy(PyObject *cpy_r_self, PyObject *cpy_r_lookup, PyObject *cpy_r_registration, PyObject *cpy_r_label);
PyObject *CPyPy__strategies___StrategyRegistry___register_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__strategies___StrategyRegistry___unregister_strategy(PyObject *cpy_r_self, PyObject *cpy_r_lookup_or_label);
PyObject *CPyPy__strategies___StrategyRegistry___unregister_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__strategies___StrategyRegistry___get_strategy(PyObject *cpy_r_self, PyObject *cpy_r_type_str);
PyObject *CPyPy__strategies___StrategyRegistry___get_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__strategies___get_uint_strategy(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry);
PyObject *CPyPy__strategies___get_uint_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__strategies___get_int_strategy(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry);
PyObject *CPyPy__strategies___get_int_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__strategies___get_ufixed_strategy(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry);
PyObject *CPyPy__strategies___get_ufixed_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__strategies___get_fixed_strategy(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry);
PyObject *CPyPy__strategies___get_fixed_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__strategies___get_bytes_strategy(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry);
PyObject *CPyPy__strategies___get_bytes_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__strategies___get_array_strategy(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry);
PyObject *CPyPy__strategies___get_array_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef__strategies___get_tuple_strategy(PyObject *cpy_r_abi_type, PyObject *cpy_r_registry);
PyObject *CPyPy__strategies___get_tuple_strategy(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef__strategies_____top_level__(void);
char CPyDef_utils_____top_level__(void);
PyObject *CPyStatic_numeric___abi_decimal_context = NULL;
PyObject *CPyStatic_numeric___ZERO = NULL;
PyObject *CPyStatic_numeric___TEN = NULL;
PyObject *CPyStatic_numeric___Decimal = NULL;
PyTypeObject *CPyType_numeric___scale_places_env;
PyObject *CPyDef_numeric___scale_places_env(void);
PyTypeObject *CPyType_numeric___f_scale_places_obj;
PyObject *CPyDef_numeric___f_scale_places_obj(void);
CPyTagged CPyDef_numeric___ceil32(CPyTagged cpy_r_x);
PyObject *CPyPy_numeric___ceil32(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
tuple_T2II CPyDef_numeric___compute_unsigned_integer_bounds(CPyTagged cpy_r_num_bits);
PyObject *CPyPy_numeric___compute_unsigned_integer_bounds(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
tuple_T2II CPyDef_numeric___compute_signed_integer_bounds(CPyTagged cpy_r_num_bits);
PyObject *CPyPy_numeric___compute_signed_integer_bounds(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
tuple_T2OO CPyDef_numeric___compute_unsigned_fixed_bounds(CPyTagged cpy_r_num_bits, CPyTagged cpy_r_frac_places);
PyObject *CPyPy_numeric___compute_unsigned_fixed_bounds(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
tuple_T2OO CPyDef_numeric___compute_signed_fixed_bounds(CPyTagged cpy_r_num_bits, CPyTagged cpy_r_frac_places);
PyObject *CPyPy_numeric___compute_signed_fixed_bounds(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_numeric___f_scale_places_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy_numeric___f_scale_places_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_numeric___f_scale_places_obj_____call__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_x);
PyObject *CPyPy_numeric___f_scale_places_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_numeric___scale_places(CPyTagged cpy_r_places);
PyObject *CPyPy_numeric___scale_places(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_numeric_____top_level__(void);
PyObject *CPyDef_padding___zpad(PyObject *cpy_r_value, CPyTagged cpy_r_length);
PyObject *CPyPy_padding___zpad(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_padding___zpad32(PyObject *cpy_r_value);
PyObject *CPyPy_padding___zpad32(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_padding___zpad_right(PyObject *cpy_r_value, CPyTagged cpy_r_length);
PyObject *CPyPy_padding___zpad_right(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_padding___zpad32_right(PyObject *cpy_r_value);
PyObject *CPyPy_padding___zpad32_right(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_padding___fpad(PyObject *cpy_r_value, CPyTagged cpy_r_length);
PyObject *CPyPy_padding___fpad(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_padding___fpad32(PyObject *cpy_r_value);
PyObject *CPyPy_padding___fpad32(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_padding_____top_level__(void);
PyObject *CPyDef_string___abbr(PyObject *cpy_r_value, CPyTagged cpy_r_limit);
PyObject *CPyPy_string___abbr(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_string_____top_level__(void);
char CPyDef_validation___validate_bytes_param(PyObject *cpy_r_param, PyObject *cpy_r_param_name);
PyObject *CPyPy_validation___validate_bytes_param(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_validation___validate_list_like_param(PyObject *cpy_r_param, PyObject *cpy_r_param_name);
PyObject *CPyPy_validation___validate_list_like_param(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_validation_____top_level__(void);

static struct export_table_c42f5c78bc058f310136 exports = {
    &CPyDef__codec___encode_c,
    &CPyDef__codec___decode_c,
    &CPyDef__codec_____top_level__,
    &CPyDef__encoding___encode_tuple,
    &CPyDef__encoding___encode_fixed,
    &CPyDef__encoding___encode_signed,
    &CPyDef__encoding___encode_elements,
    &CPyDef__encoding___encode_elements_dynamic,
    &CPyDef__encoding___encode_uint_256,
    &CPyDef__encoding___int_to_big_endian,
    &CPyDef__encoding_____top_level__,
    &CPyStatic_abi___default_codec,
    &CPyStatic_abi___encode,
    &CPyStatic_abi___decode,
    &CPyStatic_abi___is_encodable,
    &CPyStatic_abi___is_encodable_type,
    &CPyDef_abi_____top_level__,
    &CPyDef_constants_____top_level__,
    &CPyType_from_type_str___parse_type_str_env,
    &CPyDef_from_type_str___parse_type_str_env,
    &CPyType_from_type_str___decorator_parse_type_str_env,
    &CPyDef_from_type_str___decorator_parse_type_str_env,
    &CPyType_from_type_str___decorator_parse_type_str_obj,
    &CPyDef_from_type_str___decorator_parse_type_str_obj,
    &CPyType_from_type_str___new_from_type_str_parse_type_str_decorator_obj,
    &CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj,
    &CPyType_from_type_str___parse_tuple_type_str_env,
    &CPyDef_from_type_str___parse_tuple_type_str_env,
    &CPyType_from_type_str___new_from_type_str_parse_tuple_type_str_obj,
    &CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj,
    &CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____get__,
    &CPyDef_from_type_str___new_from_type_str_parse_type_str_decorator_obj_____call__,
    &CPyDef_from_type_str___decorator_parse_type_str_obj_____get__,
    &CPyDef_from_type_str___decorator_parse_type_str_obj_____call__,
    &CPyDef_from_type_str___parse_type_str,
    &CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____get__,
    &CPyDef_from_type_str___new_from_type_str_parse_tuple_type_str_obj_____call__,
    &CPyDef_from_type_str___parse_tuple_type_str,
    &CPyDef_from_type_str_____top_level__,
    &CPyStatic_packed___default_encoder_packed,
    &CPyStatic_packed___encode_packed,
    &CPyStatic_packed___is_encodable_packed,
    &CPyDef_packed_____top_level__,
    &CPyDef_tools_____top_level__,
    &CPyStatic__strategies___address_strategy,
    &CPyStatic__strategies___bool_strategy,
    &CPyStatic__strategies___bytes_strategy,
    &CPyStatic__strategies___string_strategy,
    &CPyStatic__strategies___strategy_registry,
    &CPyStatic__strategies___get_abi_strategy,
    &CPyType__strategies___StrategyRegistry,
    &CPyDef__strategies___StrategyRegistry,
    &CPyDef__strategies___StrategyRegistry_____init__,
    &CPyDef__strategies___StrategyRegistry___register_strategy,
    &CPyDef__strategies___StrategyRegistry___unregister_strategy,
    &CPyDef__strategies___StrategyRegistry___get_strategy,
    &CPyDef__strategies___get_uint_strategy,
    &CPyDef__strategies___get_int_strategy,
    &CPyDef__strategies___get_ufixed_strategy,
    &CPyDef__strategies___get_fixed_strategy,
    &CPyDef__strategies___get_bytes_strategy,
    &CPyDef__strategies___get_array_strategy,
    &CPyDef__strategies___get_tuple_strategy,
    &CPyDef__strategies_____top_level__,
    &CPyDef_utils_____top_level__,
    &CPyStatic_numeric___abi_decimal_context,
    &CPyStatic_numeric___ZERO,
    &CPyStatic_numeric___TEN,
    &CPyStatic_numeric___Decimal,
    &CPyType_numeric___scale_places_env,
    &CPyDef_numeric___scale_places_env,
    &CPyType_numeric___f_scale_places_obj,
    &CPyDef_numeric___f_scale_places_obj,
    &CPyDef_numeric___ceil32,
    &CPyDef_numeric___compute_unsigned_integer_bounds,
    &CPyDef_numeric___compute_signed_integer_bounds,
    &CPyDef_numeric___compute_unsigned_fixed_bounds,
    &CPyDef_numeric___compute_signed_fixed_bounds,
    &CPyDef_numeric___f_scale_places_obj_____get__,
    &CPyDef_numeric___f_scale_places_obj_____call__,
    &CPyDef_numeric___scale_places,
    &CPyDef_numeric_____top_level__,
    &CPyDef_padding___zpad,
    &CPyDef_padding___zpad32,
    &CPyDef_padding___zpad_right,
    &CPyDef_padding___zpad32_right,
    &CPyDef_padding___fpad,
    &CPyDef_padding___fpad32,
    &CPyDef_padding_____top_level__,
    &CPyDef_string___abbr,
    &CPyDef_string_____top_level__,
    &CPyDef_validation___validate_bytes_param,
    &CPyDef_validation___validate_list_like_param,
    &CPyDef_validation_____top_level__,
};

PyMODINIT_FUNC PyInit_c42f5c78bc058f310136__mypyc(void)
{
    static PyModuleDef def = { PyModuleDef_HEAD_INIT, "c42f5c78bc058f310136__mypyc", NULL, -1, NULL, NULL };
    int res;
    PyObject *capsule;
    PyObject *tmp;
    static PyObject *module;
    if (module) {
        Py_INCREF(module);
        return module;
    }
    module = PyModule_Create(&def);
    if (!module) {
        goto fail;
    }
    
    capsule = PyCapsule_New(&exports, "c42f5c78bc058f310136__mypyc.exports", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "exports", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_faster_eth_abi____codec(void);
    capsule = PyCapsule_New((void *)CPyInit_faster_eth_abi____codec, "c42f5c78bc058f310136__mypyc.init_faster_eth_abi____codec", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_faster_eth_abi____codec", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_faster_eth_abi____encoding(void);
    capsule = PyCapsule_New((void *)CPyInit_faster_eth_abi____encoding, "c42f5c78bc058f310136__mypyc.init_faster_eth_abi____encoding", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_faster_eth_abi____encoding", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_faster_eth_abi___abi(void);
    capsule = PyCapsule_New((void *)CPyInit_faster_eth_abi___abi, "c42f5c78bc058f310136__mypyc.init_faster_eth_abi___abi", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_faster_eth_abi___abi", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_faster_eth_abi___constants(void);
    capsule = PyCapsule_New((void *)CPyInit_faster_eth_abi___constants, "c42f5c78bc058f310136__mypyc.init_faster_eth_abi___constants", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_faster_eth_abi___constants", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_faster_eth_abi___from_type_str(void);
    capsule = PyCapsule_New((void *)CPyInit_faster_eth_abi___from_type_str, "c42f5c78bc058f310136__mypyc.init_faster_eth_abi___from_type_str", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_faster_eth_abi___from_type_str", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_faster_eth_abi___packed(void);
    capsule = PyCapsule_New((void *)CPyInit_faster_eth_abi___packed, "c42f5c78bc058f310136__mypyc.init_faster_eth_abi___packed", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_faster_eth_abi___packed", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_faster_eth_abi___tools(void);
    capsule = PyCapsule_New((void *)CPyInit_faster_eth_abi___tools, "c42f5c78bc058f310136__mypyc.init_faster_eth_abi___tools", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_faster_eth_abi___tools", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_faster_eth_abi___tools____strategies(void);
    capsule = PyCapsule_New((void *)CPyInit_faster_eth_abi___tools____strategies, "c42f5c78bc058f310136__mypyc.init_faster_eth_abi___tools____strategies", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_faster_eth_abi___tools____strategies", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_faster_eth_abi___utils(void);
    capsule = PyCapsule_New((void *)CPyInit_faster_eth_abi___utils, "c42f5c78bc058f310136__mypyc.init_faster_eth_abi___utils", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_faster_eth_abi___utils", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_faster_eth_abi___utils___numeric(void);
    capsule = PyCapsule_New((void *)CPyInit_faster_eth_abi___utils___numeric, "c42f5c78bc058f310136__mypyc.init_faster_eth_abi___utils___numeric", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_faster_eth_abi___utils___numeric", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_faster_eth_abi___utils___padding(void);
    capsule = PyCapsule_New((void *)CPyInit_faster_eth_abi___utils___padding, "c42f5c78bc058f310136__mypyc.init_faster_eth_abi___utils___padding", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_faster_eth_abi___utils___padding", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_faster_eth_abi___utils___string(void);
    capsule = PyCapsule_New((void *)CPyInit_faster_eth_abi___utils___string, "c42f5c78bc058f310136__mypyc.init_faster_eth_abi___utils___string", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_faster_eth_abi___utils___string", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    extern PyObject *CPyInit_faster_eth_abi___utils___validation(void);
    capsule = PyCapsule_New((void *)CPyInit_faster_eth_abi___utils___validation, "c42f5c78bc058f310136__mypyc.init_faster_eth_abi___utils___validation", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_faster_eth_abi___utils___validation", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return module;
    fail:
    Py_XDECREF(module);
    return NULL;
}
