#include <string>
#include <iostream>
#include <boost/python.hpp>
using namespace boost::python;

struct Base
{
		Base() { std::cout << "Default constructor of Base" << std::endl; }
		float get_val() { std::cout << "get_val from Base" << std::endl; return 10.0; }
		virtual ~Base() { std::cout << "Destructor of Base" << std::endl; }
		virtual int f() = 0;
};

struct BaseWrap : Base, wrapper<Base> // wrapping classes that are meant to override in Python easier
{
		int f() override { std::cout << "Calling f() in BaseWrap" << std::endl; return this->get_override("f")();}
};

BOOST_PYTHON_MODULE(class_virtual)
{
		class_<BaseWrap, boost::noncopyable>("Base")
				.def("f", pure_virtual(&Base::f));
}
