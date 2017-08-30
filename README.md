# Python-Cpp

- - -

* [C++ Boost](#C++-Boost)

- - -

### C++ Boost Python

* [Installation](#Boost-Installation)
* [Tutorial](#Tutorial)
	* [python3 hello_ext example](#python3-hello_ext)
	* [python2 hello_ext example](#python2-hello_ext)
	* [other cpp example](https://github.com/zpoint/Python-Cpp/tree/master/boost_python)

##### Boost Installation

* OS Ubuntu 16.10

* Download the latest version [here](http://www.boost.org/)

    	tar -xzvf boost_1_65_0.tar.gz
        cd boost_1_65_0
        ./bootstrap.sh --with-python=/usr/bin/python3 --with-python-version=3.5 --with-python-root=/usr/local/lib/python3.5 --prefix=/usr/local
        sudo ./b2 install -a --with=all
        sudo ldconfig

##### Tutorial

* If you change the prefix path when install, you need also change the **BOOST_INC** and **BOOST_LIB** in **./boost_python/makefile**


###### python3 hello_ext

	git clone https://github.com/zpoint/Python-Cpp.git
	cd boost_python
    make

	python3
    Python 3.5.2 (default, Nov 17 2016, 17:05:23)
    [GCC 5.4.0 20160609] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import hello_ext
    >>> hello_ext.greet()
    'hello, world'



###### python2 hello_ext

	git clone https://github.com/zpoint/Python-Cpp.git
	cd boost_python
    vim makefile # change the first line "PYTHON_VERSION = 3.5" to "PYTHON_VERSION = 2.7"
    make

	python
	Python 2.7.12 (default, Nov 19 2016, 06:48:10)
    [GCC 5.4.0 20160609] on linux2
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import hello_ext
    >>> hello_ext.greet()
    'hello, world'
