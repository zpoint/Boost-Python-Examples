# enums

###### python3 enums

    Python 3.5.2 (default, Sep 14 2017, 22:51:06)
    [GCC 5.4.0 20160609] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import enums
    >>> c = enums.choice(enums.choice.red)
    >>> c
    enums.choice(0)
    >>> c = enums.choice(enums.choice.blue)
    >>> c
    enums.choice(1)

    >>> n = enums.X.nested(enums.X.nested.red)
    >>> n = enums.X.nested(enums.X.nested.blue)
    >>> n
    enums.nested(1)
    >>>
