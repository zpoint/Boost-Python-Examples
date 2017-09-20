#include <iostream>
#include <boost/python.hpp>
using namespace boost::python;

struct test
{
		list to_list(object x, object y)
		{
				list lst;
				lst.append(x);
				lst.append(y);
				return lst;
		}
		tuple to_tuple()
		{
				return make_tuple(123, 'D', "Hello, World", 0.0);
		}
		object to_str(str name)
		{
				str name2 = name.upper();
				object msg = "%s is bigger than %s" % make_tuple(name2, name);
				return msg;
		}
};

BOOST_PYTHON_MODULE(derived_object_types)
{
		class_<test>("test")
				.def("to_list", &test::to_list)
				.def("to_tuple", &test::to_tuple)
				.def("to_str", &test::to_str);
}
