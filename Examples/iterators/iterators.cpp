#include <boost/python.hpp>
#include <vector>
using namespace boost::python;

std::vector<int> ivec = { 1, 2, 3, 4, 5 };

void cpp_iterator()
{
		object get_iterator = iterator<std::vector<int>>();
		object iter = get_iterator(ivec);
		object 
}

BOOST_PYTHON_MODULE(iterators)
{
		// def("__iter__", iterator<vector<int>>())
		def("cpp_iterator", cpp_iterator);
}
