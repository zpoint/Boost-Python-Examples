#include <iostream>
#include <boost/python.hpp>
using namespace boost::python;

class FilePos
{
		friend FilePos& operator+=(FilePos&, int);
		friend FilePos& operator-=(FilePos&, int);
		public:
			FilePos(int val = 1):value(val) { std::cout << "FilePos default constructor" << std::endl; }
			FilePos(const FilePos& f): value(f.get_val()) { std::cout << "FilePos copy constructor" << std::endl;}
			int get_val() const { return value; }
		private:
			int value;
};

FilePos operator+(FilePos f, int v)
{
		return FilePos(v + f.get_val());
}

FilePos operator+(int v, FilePos f)
{
		return f + v;
}

int operator-(FilePos f1, FilePos f2)
{
		return f1.get_val() - f2.get_val();
}

FilePos operator-(FilePos f, int i)
{
		return f.get_val() - i;
}

FilePos& operator+=(FilePos &f, int i)
{
		f.value += i;
		return f;
}

FilePos& operator-=(FilePos &f, int i)
{
		f.value -= i;
		return f;
}

bool operator<(FilePos f1, FilePos f2)
{
		return f1.get_val() < f2.get_val();
}


BOOST_PYTHON_MODULE(operators)
{
		class_<FilePos>("FilePos")
				.def(init<int>())
				.def(self + int()) // __add__
				.def(int() + self) // __radd__
				.def(self - self) // __sub__
				.def(self - int()) // __sub__
				.def(self += int()) // __iadd__
				.def(self -= other<int>()) // when type does not support default-constructor
				.def(self < self);  // __lt__
}

