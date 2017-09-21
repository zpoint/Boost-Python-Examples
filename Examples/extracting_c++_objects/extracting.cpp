#include <iostream>
//#include <cassert>
#include <boost/python.hpp>
using namespace boost::python;

struct Vec2
{
		Vec2(double x, double y): length(x), angle(y) { std::cout << "length: " << length << " angle: " << angle << std::endl; }
		const double length;
		const double angle;
};


void test(object vec345)
{
		double l = extract<double>(vec345.attr("length"));
		Vec2& v = extract<Vec2&>(vec345);
		assert(l == v.length);
		extract<Vec2&> x(vec345);
		if (x.check())
				std::cout << "l: " << l << " v.length: " << v.length << std::endl;
}

BOOST_PYTHON_MODULE(extracting)
{
	object vec345 = (
			class_<Vec2>("Vec2", init<double, double>())
					.def_readonly("length", &Vec2::length)
					.def_readonly("angle", &Vec2::angle)
			)(3.0, 4.0);
	def("test", test);
}

