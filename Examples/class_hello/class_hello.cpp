#include <string>
#include <iostream>

struct World
{
		World() { std::cout << "default constructor" << std::endl; }
		World(std::string msg): msg(msg) { std::cout << "constructor of struct World" << std::endl; }
		void set(std::string msg) { this->msg = msg; }
		std::string greet() { return msg; }
		std::string msg;
};

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(class_hello)
{
		class_<World>("World")
				.def("greet", &World::greet)
				.def("set", &World::set)
				.def(init<std::string>());
}
