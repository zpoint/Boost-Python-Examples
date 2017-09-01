#include <iostream>
#include <cmath>
#include <string>
#include <boost/python.hpp>

using namespace boost::python;
class Rational
{
		friend Rational abs(Rational);
		friend std::ostream& operator<<(std::ostream&, Rational);
		public:
			Rational(int numerator, int denominator):numerator(numerator), denominator(denominator) 
			{ std::cout << "Default constructor of Rational" << std::endl; }
			operator double() const { return static_cast<double>(numerator) / static_cast<double>(denominator); }
			std::string str() const { return "I am Rational"; }
		private:
			int numerator;
			int denominator;
};

double pow(Rational r1, Rational r2)
{
		return pow(double(r1), double(r2));
}

Rational abs(Rational r)
{
		if (r.numerator > 0 and r.denominator < 0)
				return Rational(r.numerator, -r.denominator);
		else if (r.numerator < 0 and r.denominator > 0)
				return Rational(-r.numerator, r.denominator);
		else
				return r;
}

std::ostream& operator<<(std::ostream &os, Rational r)
{
		os << r.numerator << " / " << r.denominator << " is " << double(r) << std::endl;
		return os;
}



BOOST_PYTHON_MODULE(special_operators)
{
		class_<Rational>("Rational", init<int, int>())
				.def(float_(self)) // __float__
				.def(pow(self, other<Rational>())) // __pow__
				.def(abs(self)) // abs
				// .def(str(self)); // seems not work, don't know why yet
				.def("__str__", &Rational::str);

}
