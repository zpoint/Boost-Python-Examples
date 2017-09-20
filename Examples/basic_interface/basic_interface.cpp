#include <boost/python.hpp>
#include <iostream>
using namespace boost::python;

object f(object x, object y)
{
		if (y == "foo")
				x.slice(3, 7) = "bar";
		else
				x.attr("items") += y(3, x);
		return x;
}

object getfunc()
{
		return object(f);
}

BOOST_PYTHON_MODULE(basic_interface)
{
		def("f", f);
		def("getfunc", getfunc);
}
