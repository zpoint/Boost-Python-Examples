#include <boost/python.hpp>
#include <assert.h>
#include <iostream>
#include <string>
using namespace boost::python;

class MyCPPException : public std::exception
{
		private:
			std::string message;
			std::string extraData;
		public:
			MyCPPException(std::string message, std::string extraData)
			{
					this->message = message;
					this->extraData = extraData;
			}
			
			const char *what() const throw()
			{
					return this->message.c_str();
			}

			~MyCPPException() throw()
			{
					std::cout << "destructor of MyCPPException" << std::endl;
			}

			std::string getMessage()
			{
					return this->message;
			}

			std::string getExtraData()
			{
					return this->extraData;
			}
};

void func_from_cpp(bool throwException)
{
		std::cout << "Call from func_from_cpp" << std::endl;
		if (throwException)
		{
				throw MyCPPException("Throwing an exception as requested.", "This is the extra data.");
		}
}

PyObject *createExceptionClass(const char* name, PyObject* baseTypeObj = PyExc_Exception)
{
	std::string scopeName = extract<std::string>(scope().attr("__name__"));
	std::string qualifiedName0 = scopeName + "." + name;
    char* qualifiedName1 = const_cast<char*>(qualifiedName0.c_str());

    PyObject* typeObj = PyErr_NewException(qualifiedName1, baseTypeObj, 0);
    if(!typeObj) throw_error_already_set();
    scope().attr(name) = handle<>(borrowed(typeObj));
    return typeObj;
}

PyObject *myCPPExceptionType = nullptr;

void translateMyCPPException(const MyCPPException &e)
{
		std::cout << "translating exception" << std::endl;
		assert(myCPPExceptionType != nullptr);
		object pythonExceptionInstance(e);
		object exception_new(handle<>(borrowed(myCPPExceptionType)));
		exception_new.attr("message") = pythonExceptionInstance.attr("message");
		exception_new.attr("extraData") = pythonExceptionInstance.attr("extraData");
		PyErr_SetObject(myCPPExceptionType, exception_new.ptr());
}

BOOST_PYTHON_MODULE(exception_translation)
{
		class_<MyCPPException> myCPPExceptionClass("MyCPPException", init<std::string, std::string>());
		myCPPExceptionClass
				.add_property("message", &MyCPPException::getMessage)
				.add_property("extraData", &MyCPPException::getExtraData);

		myCPPExceptionType = createExceptionClass("MyCPPException");
		register_exception_translator<MyCPPException>(translateMyCPPException);
		def("func_from_cpp", func_from_cpp);
}
