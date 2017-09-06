# call_policies

###### python3 call_policies

	cd Boost-Python-Examples/Examples/call_policies
	make
    python3

    Python 3.5.2 (default, Nov 17 2016, 17:05:23)
    [GCC 5.4.0 20160609] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import call_policies
    >>> y = call_policies.Y()
    >>> z = call_policies.Z()
    >>> x = call_policies.f(y, z)
    In function f
    >>> x.pr()
    pr val: 3 from x
    >>> del y
    >>> x.pr()
    pr val: 32 from x # the memory used to store x.val has been freed and currently store something else

    >>> y = call_policies.Y()
    >>> x = call_policies.f(y, z)
    In function f
    >>> x.pr()
    pr val: 3 from x
    >>> y.z_value()
    2
    >>> del z
    >>> y.z_value() # same reason as before
    0
    >>>




