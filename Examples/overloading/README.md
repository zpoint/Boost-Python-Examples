# overloading

###### python3 overloading

	cd Boost-Python-Examples/Examples/overloading
	make
    python3

    Python 3.5.2 (default, Aug 18 2017, 17:48:00)
    [GCC 5.4.0 20160609] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>> from overloading import *
    >>> x = X()
    >>> x.f(1)
    f(int a)
    True
    >>> x.f(1, 2)
    f(int a, double b)
    True
    >>> x.f(1,2,3.3)
    Traceback (most recent call last):
      File "<stdin>", line 1, in <module>
    Boost.Python.ArgumentError: Python argument types in
        X.f(X, int, int, float)
    did not match C++ signature:
        f(X {lvalue}, int, int, int)
        f(X {lvalue}, int, double, char)
        f(X {lvalue}, int, double)
        f(X {lvalue}, int)
    >>> x.f(1,2,3)
    int(a, b, c), a + b + c is: 6
    6


    >>> not_member_func(4, "z", 2, 1)
    not mem func: a: 4 b: z c: 2 d: 1
    True
    >>> not_member_func(4, "z", 2, 1)
    not mem func: a: 4 b: z c: 2 d: 1
    True
    >>> not_member_func(4, "z")
    not mem func: a: 4 b: z c: 2 d: 3
    True
    >>> not_member_func(4, "z", 1)
    not mem func: a: 4 b: z c: 1 d: 3
    True
    >>> not_member_func(4, "z", 1, 3)
    not mem func: a: 4 b: z c: 1 d: 3
    True

    >>> xx = X()
    >>> xx.mem_func(1)
    variable argument: a: 1 b:  c: 2 d: 3
    True

    >>> xxx = X(1)
    other constructor
    >>> xxx = X(1, "s")
    other constructor
    >>>

    >>> xxx = X(1)
    other constructor
    >>> xxx.mem_func(4)
    variable argument: a: 4 b:  c: 2 d: 3
    True
    >>> xxx.mem_func(4, "z")
    variable argument: a: 4 b: z c: 2 d: 3
    True
    >>> 




