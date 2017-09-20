# derived_object_types

###### python3 derived_object_types

	cd Boost-Python-Examples/Examples/derived_object_types
	make
    python3 example.py

    Python 3.5.2 (default, Aug 18 2017, 17:48:00)
    [GCC 5.4.0 20160609] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>> from derived_object_types import *
    >>> t = test()
    >>> print(t.to_list(1, "ss"))
    [1, 'ss']
    >>> print(t.to_tuple())
    (123, 'D', 'Hello, World', 0.0)
    >>> print(t.to_str("hello!"))
    HELLO! is bigger than hello!
