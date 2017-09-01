# class_member

###### python3 class_member

	make
    python3

    Python 3.5.2 (default, Nov 17 2016, 17:05:23)
    [GCC 5.4.0 20160609] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import class_member
    >>> var = class_member.Var("I am Var")
    >>> var.name
    'I am Var'
    >>> var.value
    0.0
    >>> var.value = 3
    >>> var.value
    3.0
    >>> var.name = "!"
    Traceback (most recent call last):
      File "<stdin>", line 1, in <module>
    AttributeError: can't set attribute



