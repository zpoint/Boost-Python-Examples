# enums

###### python3 enums

    Python 3.5.2 (default, Sep 14 2017, 22:51:06) 
    [GCC 5.4.0 20160609] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>> from reference_count import *
    >>> import sys
    >>> a = []
    >>> sys.getrefcount(a)
    2
    >>> py_pointer(a)
    <reference_count.py_pointer object at 0x7fb95c4046f8>
    >>> sys.getrefcount(a)
    2
    >>> py_object(a)
    <reference_count.py_object object at 0x7fb95c404768>
    >>> sys.getrefcount(a)
    4
    >>> sys.getrefcount(a)
    3
    >>> sys.getrefcount(a)
    3
    >>> sys.getrefcount(a)
    3
    >>> sys.getrefcount(a)
    3
    >>>
