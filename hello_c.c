#include <Python.h>

static char docstring[] = "Hello world module for Python written in C";
static PyObject	*hello (PyObject *self)
{
	return Py_BuildValue("s", "Hello Pythonista");
}

static PyMethodDef	module_methods[] = {

	/* nome ,       método       , opções     , documentação */
	{"hello", (PyCFunction) hello, METH_NOARGS, docstring},
	{NULL, NULL, 0, NULL} /* sentinela */

	/*	Interface options
		1.METH_NOARGS	Function without parameters.
		2.METH_VARARGS	Function with parameter list.
		3.METH_KEYWORDS	Function with named parameters.
	*/
};

static struct PyModuleDef cModPyDem =
{
	PyModuleDef_HEAD_INIT,
	"module", /* name of module */
	docstring,          /* module documentation, may be NULL */
	-1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
	module_methods
};

PyMODINIT_FUNC PyInit_module(void)
{
	PyModule_Create(&cModPyDem);
}
