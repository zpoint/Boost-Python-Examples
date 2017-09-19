# call_policies

###### python3 call_policies

	cd Boost-Python-Examples/Examples/call_policies
	make
    python3

    Python 3.5.2 (default, Nov 17 2016, 17:05:23)
    [GCC 5.4.0 20160609] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>> from call_policies import *
    >>> y = Y()
    >>> z = Z()
    >>> r = f(y, z)
	In function f
    >>> y.x.get()
    3
    >>> r.get()
    3
    >>> y.x.set(2)
    >>> r.get()
    2



