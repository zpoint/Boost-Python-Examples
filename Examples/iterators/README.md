# iterators

###### python3 iterators

    make
	python3

    Python 3.5.2 (default, Sep 14 2017, 22:51:06)
    [GCC 5.4.0 20160609] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>> from iterators import *
    >>> f = Field()
    >>> for i in f.pions:
    ...     print(i)
    ... 
    1
    2
    3
    4
    5
    >>> for i in f.bogons:
    ...     print(i)
    ...
    1
    2
    3
    4
    5

    >>> x = list_int()
    >>> x
    <iterators.list_int object at 0x7fb07cabd6f8>
    >>> x.assign([1,2,3,4,6])
    >>>

