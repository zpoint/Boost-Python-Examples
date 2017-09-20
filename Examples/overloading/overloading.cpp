#include <boost/python.hpp>
#include <iostream>
#include <string>

using namespace boost::python;

struct X
{
		X() = default;
		X(int a, char b = 'D', std::string c = "constructor", double d = 0.0) { std::cout << "other constructor" << std::endl;}
		bool f(int a)
		{
				std::cout << "f(int a)" << std::endl;
				return true;
		}

		bool f(int a, double b)
		{
				std::cout << "f(int a, double b)" << std::endl;
				return true;
		}

		bool f(int a, double b, char c)
		{
				std::cout << "f(int a, double b, char c)" << std::endl;
				return true;
		}

		int f(int a, int b, int c)
		{
				int result = a + b + c;
				std::cout << "int(a, b, c), a + b + c is: " << result << std::endl;
				return a + b + c;
		}

		bool mem_func(int a, char b = 1, unsigned c = 2, double d = 3)
		{
				std::cout << "variable argument: a: " << a << " b: " << b << " c: " << c << " d: " << d << std::endl;
				return true;
		}
};

bool not_mem_func(int a, char b = 1, unsigned c = 2, double d = 3)
{
		std::cout << "not mem func: a: " << a << " b: " << b << " c: " << c << " d: " << d << std::endl;
		return true;
}

bool (X::*fx1)(int) = &X::f;
bool (X::*fx2)(int, double) = &X::f;
bool (X::*fx3)(int, double, char) = &X::f;
int (X::*fx4)(int, int, int) = &X::f;

/*
// pointer name should be same as member function name, or compile error will be reported
bool (X::*mem_func)(int, char, unsigned, double) = &X::mem_func;
*/

BOOST_PYTHON_FUNCTION_OVERLOADS(not_member_func_overloads, not_mem_func, 1, 4);
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(mem_func_overloads, X::mem_func, 1, 4);

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(f_mem_overloads, X::f, 1, 3);

BOOST_PYTHON_MODULE(overloading)
{
		class_<X>("X")
				.def("f", fx1)
				.def("f", fx2)
				.def("f", fx3)
				.def("f", fx4)
				.def(init<>())
				.def(init<int, optional<char, std::string, double>>())
				.def("mem_func", &X::mem_func, mem_func_overloads())
				// the overloaded functions must have a common sequence of initial arguments
				.def("f_mem_func", fx3, f_mem_overloads());
		def("not_member_func", not_mem_func, not_member_func_overloads());
}
