#include <string>
#include <iostream>
#include <boost/python.hpp>
using namespace boost::python;

struct Base
{
		Base() { std::cout << "Default constructor of Base" << std::endl; }
		float get_val() { std::cout << "get_val from Base" << std::endl; return 10.0; }
		virtual ~Base() { std::cout << "Destructor of Base" << std::endl; }
};

struct Derived : Base
{
		Derived() { std::cout << "Deault constructor of Derived" << std::endl; }
		virtual ~Derived()  override { std::cout << "Destructor of Derived" << std::endl; }
};

void b(Base *)
{
		std::cout << "Function b(Base *)" << std::endl;
}

void d(Derived *)
{
		std::cout << "Function d(Derived *)" << std::endl;
}

Base* factory()
{
		return new Derived;
}

BOOST_PYTHON_MODULE(inheritance)
{
		class_<Base>("Base")
				.def("get_val", &Base::get_val);

		class_<Derived, bases<Base> >("Derived");
		def("b", b);
		def("d", d);
		def("factory", factory, return_value_policy<manage_new_object>());
}
