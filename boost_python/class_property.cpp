#include <string>

struct Num
{
		float get() const { return value; }
		void set(float val) { value = val; }
		float value = 10.0;
};

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(class_property)
{
		class_<Num>("Num")
				.add_property("rovalue", &Num::get)
				.add_property("value", &Num::get, &Num::set);
}
