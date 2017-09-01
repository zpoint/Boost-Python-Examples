#include <iostream>
#include <boost/python.hpp>
using namespace boost::python;

struct Base
{
		virtual ~Base() {}
		virtual int f() { return 0; }
};

struct BaseWrap : Base, wrapper<Base>
{
		int f()
		{
				if (override f = this->get_override("f"))
						return f();
				return Base::f();
		}
		int default_f() { return this->Base::f(); }
};

BOOST_PYTHON_MODULE(class_virtual_nopure)
{
		class_<BaseWrap, boost::noncopyable>("Base")
				.def("f", &Base::f, &BaseWrap::default_f);
}
