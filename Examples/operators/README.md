# operators

###### python3 operators

	make
    python3

    Python 3.5.2 (default, Nov 17 2016, 17:05:23) 
    [GCC 5.4.0 20160609] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import operators
    >>> f1 = operators.FilePos()
    FilePos default constructor
    >>> f2 = operators.FilePos()
    FilePos default constructor
    >>> 
    >>> f1 + 3
    FilePos copy constructor
    FilePos default constructor
    FilePos copy constructor
    <operators.FilePos object at 0x7f3aa30c9c10>
    >>> 3 + f2
    FilePos copy constructor
    FilePos copy constructor
    FilePos default constructor
    FilePos copy constructor
    <operators.FilePos object at 0x7f3aa30d4440>
    >>> 
    >>> f1 - f2
    FilePos copy constructor
    FilePos copy constructor
    0
    >>> 
    >>> f1 - 3
    FilePos copy constructor
    FilePos default constructor
    FilePos copy constructor
    <operators.FilePos object at 0x7f3aa30c9c10>
    >>> 
    >>> f1 += 3
    >>> f1 -= 5
    >>> f1 < f2
    FilePos copy constructor
    FilePos copy constructor


