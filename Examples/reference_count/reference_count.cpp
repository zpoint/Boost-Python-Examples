#include <boost/python.hpp>
using namespace boost::python;

struct py_pointer
{
		py_pointer(PyObject *pyobj): p(handle<>(pyobj)) { }
		object p;
};

struct py_object
{
		py_object(PyObject *pyobj): p(handle<>(borrowed(pyobj))) { }
		object p;
};

BOOST_PYTHON_MODULE(reference_count)
{
		class_<py_pointer>("py_pointer", init<PyObject *>());
		class_<py_object>("py_object", init<PyObject *>());
}
