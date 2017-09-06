#include <iostream>
#include <boost/python.hpp>
using namespace boost::python;

struct Z {
		void set(const int i) { val = i; }
		int get() const { return val; }
		int val = 2;
};

struct X {
		void pr() { std::cout << "pr val: " << val << " from x" << std::endl; }
		void set(const int i) { val = i; }
		int get() const { return val; }
		int val = 3;
};

struct Y {
		X x; Z* z;
		int z_value() { return z->get(); }
};


X &f(Y &y, Z *z)
{
		std::cout << "In function f" << std::endl;
		y.z = z;
		return y.x;
}

BOOST_PYTHON_MODULE(call_policies)
{
		class_<X>("X")
				.def("pr", &X::pr)
				.def("get", &X::get)
				.def("set", &X::set);
		class_<Y>("Y")
				.add_property("x", &Y::x)
				.def("z_value", &Y::z_value);
		class_<Z>("Z")
				.def("get", &Z::get)
				.def("set", &Z::set);
		def("f", f, return_value_policy<reference_existing_object>());
		def("ff", f, return_internal_reference<1
						with_custodian_and_ward<1, 2> >());
}
