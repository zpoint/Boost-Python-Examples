#include <string>

struct Num
{
		Num();
		float get() const { return value; }
		void set(float val) { value = val; }
		float value;
};

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(class_property)
{
		class_<Num>("Num")
				.add_properpy("rovalue", &Num::get)
				.add_properpy("value", &Num::get, &Num::set);
}
