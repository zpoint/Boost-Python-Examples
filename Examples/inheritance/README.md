# inheritance

###### python3 inheritance

	cd Boost-Python-Examples/Examples/inheritance
	make
    python3

    Python 3.5.2 (default, Nov 17 2016, 17:05:23)
    [GCC 5.4.0 20160609] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import inheritance
    >>> base = inheritance.Base()
    Default constructor of Base

    >>> derived = inheritance.Derived()
    Default constructor of Base
    Deault constructor of Derived

    >>> inheritance.b(base)
    Function b(Base *)
    >>> inheritance.b(derived)
    Function b(Base *)
    >>> inheritance.d(base)
    Traceback (most recent call last):
      File "<stdin>", line 1, in <module>
    Boost.Python.ArgumentError: Python argument types in
        inheritance.d(Base)
    did not match C++ signature:
        d(Derived*)
    >>> inheritance.d(derived)
    Function d(Derived *)

    >>> inheritance.factory()
    Default constructor of Base
    Deault constructor of Derived
    <inheritance.Derived object at 0x7f24a17668a0>

    >>> quit()
    Destructor of Derived
    Destructor of Base
    Destructor of Base
    Destructor of Derived
    Destructor of Base

