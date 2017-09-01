# class_property

###### python3 class_property

	cd Boost-Python-Examples/Examples/class_property
    make
    python3

    Python 3.5.2 (default, Nov 17 2016, 17:05:23)
    [GCC 5.4.0 20160609] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import class_property
    >>> num = class_property.Num()
    >>> num.rovalue
    10.0
    >>> num.value
    10.0
    >>> num.value = 3
    >>> num.value
    3.0
    >>> num.rovalue = 3
    Traceback (most recent call last):
      File "<stdin>", line 1, in <module>
    AttributeError: can't set attribute
