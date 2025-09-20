#include <Python.h>

PyMODINIT_FUNC
PyInit_from_type_str(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("96ed7ed3d355cd18e89b__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_faster_eth_abi___from_type_str");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "96ed7ed3d355cd18e89b__mypyc.init_faster_eth_abi___from_type_str");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_from_type_str(); }
