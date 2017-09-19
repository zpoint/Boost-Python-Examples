# Boost Python Examples

- - -

* [C++ Boost](#C++-Boost)

- - -

### C++ Boost Python

* [Installation](#Boost-Installation)
* [Demo](#Demo)
	* [python3 hello_ext example](#python3-hello_ext)
	* [python2 hello_ext example](#python2-hello_ext)
* Examples
	* [hello_ext](https://github.com/zpoint/Boost-Python-Examples/tree/master/Examples/hello_ext)
	* [class_hello](https://github.com/zpoint/Boost-Python-Examples/tree/master/Examples/class_hello)
	* [class_member](https://github.com/zpoint/Boost-Python-Examples/tree/master/Examples/class_member)
	* [class_property](https://github.com/zpoint/Boost-Python-Examples/tree/master/Examples/class_property)
	* [inheritance](https://github.com/zpoint/Boost-Python-Examples/tree/master/Examples/inheritance)
	* [class_virtual](https://github.com/zpoint/Boost-Python-Examples/tree/master/Examples/class_virtual)
	* [class_virtual_nopure](https://github.com/zpoint/Boost-Python-Examples/tree/master/Examples/class_virtual_nopure)
	* [operators](https://github.com/zpoint/Boost-Python-Examples/tree/master/Examples/operators)
	* [special_operators](https://github.com/zpoint/Boost-Python-Examples/tree/master/Examples/special_operators)

##### Boost Installation with python3 support

* OS Ubuntu 16.10

* From source
    * Download the latest version [here](http://www.boost.org/)
    * Description of **user-config.jam** please refer to [here](http://www.boost.org/build/doc/html/bbv2/overview/configuration.html)

            tar -xzvf boost_1_65_1.tar.gz
            cd boost_1_65_1

            # sudo find / -name "python3.5m" # If you don't know where python3.5m is
            # which python3 # If you don't know your python3 install directory
            echo "using mpi ;
            using gcc :  : g++ ;
            using python : 3.5 : /usr/bin/python3 : /usr/include/python3.5m : /usr/local/lib ;" > ~/user-config.jam

            ./bootstrap.sh --with-python=/usr/bin/python3 --with-python-version=3.5 --with-python-root=/usr/local/lib/python3.5 --prefix=/usr/local
            sudo ./b2 install -a --with=all
            sudo ldconfig

* From apt

	  sudo apt-get install libboost-all-dev
      # link python3.so
	  sudo find / -name "libpython3.5m.so"
      # cd to where you find it
      cd /usr/lib/x86_64-linux-gnu/
	  sudo ln -s libboost_python-py35.so libboost_python3.so

##### Demo

* If you install from source, and you change the prefix path when install, you need also change the **BOOST_INC** and **BOOST_LIB** in **makefile**
* My default python version is python3.5, if you want to use with python 2.7, change **"PYTHON_VERSION"** in makefile

###### python3 hello_ext

	git clone https://github.com/zpoint/Boost-Python-Examples.git
	cd Boost-Python-Examples/Examples/hello_ext
    make

	python3
    Python 3.5.2 (default, Nov 17 2016, 17:05:23)
    [GCC 5.4.0 20160609] on linux
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import hello_ext
    >>> hello_ext.greet()
    'hello, world'



###### python2 hello_ext

	git clone https://github.com/zpoint/Boost-Python-Examples.git
	cd Boost-Python-Examples/Examples/hello_ext
    vim makefile # change the first line "PYTHON_VERSION = 3.5" to "PYTHON_VERSION = 2.7"
    make

	python
	Python 2.7.12 (default, Nov 19 2016, 06:48:10)
    [GCC 5.4.0 20160609] on linux2
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import hello_ext
    >>> hello_ext.greet()
    'hello, world'
