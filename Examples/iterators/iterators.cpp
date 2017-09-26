#include <boost/python.hpp>
#include <iostream>
#include <vector>
#include <list>
/*
 * If you want to use stl_input_iterator, boost version  should be higher than boost 1.58
 */
using namespace boost::python;

std::vector<int> ivec = { 1, 2, 3, 4, 5 };

struct Field
{
		std::vector<int>::iterator b_begin() { return ivec.begin(); }
		std::vector<int>::iterator b_end() { return ivec.end(); }
		std::vector<int>::iterator p_begin = ivec.begin();
		std::vector<int>::iterator p_end = ivec.end();
};

void cpp_iterator()
{
		object get_iterator = iterator<std::vector<int>>();
		object iter = get_iterator(ivec);
		// object first = iter.next();	 // no member named 'next' in 'boost::python::api::object'
}

template<typename T>
void list_assign(std::list<T>& l, object o)
{
		// Turn a Python sequence into a STL input range
		boost::python::stl_input_iterator<T> begin(o), end;
		l.assign(begin, end);
}

BOOST_PYTHON_MODULE(iterators)
{
		// def("__iter__", iterator<vector<int>>())
		def("cpp_iterator", cpp_iterator);
		class_<Field>("Field")
				.add_property("pions", range(&Field::p_begin, &Field::p_end))
				.add_property("bogons", range(&Field::b_begin, &Field::b_end));
			
		class_<std::list<int>>("list_int")
				.def("assign", &list_assign<int>);
}
