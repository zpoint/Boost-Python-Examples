#include <iostream>
#include <boost/python.hpp>
using namespace boost::python;

enum choice { red, blue };

struct X
{
		enum nested { red, blue };
};

BOOST_PYTHON_MODULE(enums)
{
		enum_<choice>("choice")
				.value("red", red)
				.value("blue", blue)
				;

		scope in_X = class_<X>("X");
		enum_<X::nested>("nested")
				.value("red", X::red)
				.value("blue", X::blue);
}
