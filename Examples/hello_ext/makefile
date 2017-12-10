# default PTRHON_VERSION is 3.6 on Mac, 3.5 in other os
# if you installed other python version, Please specific your Python Version below
PYTHON_VERSION = None
TARGET = hello_ext

CFLAGS = -lm -pthread -O3 -std=c++11 -march=native -Wall -funroll-loops -Wno-unused-result
osname := $(shell uname)

# Only need to change if you install boost-python from source
BOOST_INC = /usr/local/include/boost
BOOST_LIB = /usr/local/lib

# $(info $$osname is [${osname}])

# if PYTHON_VERSION not set, set default PYTHON_VERSION
ifeq ($(osname), Darwin)
	EXPORT_DYNAMIC_NAME = export_dynamic
	ifeq ($(PYTHON_VERSION), None)
		PYTHON_VERSION = 3.6
	endif
else
	EXPORT_DYNAMIC_NAME = -export-dynamic
	ifeq ($(PYTHON_VERSION), None)
		PYTHON_VERSION = 3.5
	endif
endif	

$(eval REMAINDER := $$$(PYTHON_VERSION))
FIRST := $(subst $(REMAINDER),,$(PYTHON_VERSION))

# set default PYTHON_INCLUDE and LIBPYTHON_PATH for different os
# PYTHON_INCLUDE should be the path contain pyconfig.h
# LIBPYTHON_PATH should be the path contain libpython3.6 or libpython3.5 or libpython2.7 or whichever your python version
ifeq ($(osname), Darwin)
	ifeq ($(FIRST), 3)
		PYTHON_INCLUDE = /usr/local/Cellar/python3/3.6.3/Frameworks/Python.framework/Versions/3.6/include/python3.6m/
		LIBPYTHON_PATH = /usr/local/Cellar/python3/3.6.3/Frameworks/Python.framework/Versions/3.6/lib/
	else
		PYTHON_INCLUDE = /usr/local/Cellar/python/2.7.14/Frameworks/Python.framework/Versions/2.7/include/python2.7/
		LIBPYTHON_PATH = /usr/local/Cellar/python/2.7.14/Frameworks/Python.framework/Versions/2.7/lib/
	endif
else
	PYTHON_INCLUDE = /usr/include/python$(PYTHON_VERSION)
	LIBPYTHON_PATH = /usr/lib/python$(PYTHON_VERSION)/config
endif

# boost python lib, on mac, default is lboost_python for python2.x, lboost_python3 for python3.x
# on ubuntu, name ===> python3.5m
# on mac, name ===> python3.6
ifeq ($(FIRST), 3)
	BOOST = lboost_python3
	ifeq ($(osname), Darwin)
		PYTHON_VERSION_FINAL = $(PYTHON_VERSION)
	else
		PYTHON_VERSION_FINAL = $(PYTHON_VERSION)m
	endif
else
	BOOST = lboost_python
	PYTHON_VERSION_FINAL = $(PYTHON_VERSION)
endif

 
$(TARGET).so: $(TARGET).o
	g++ $(CFLAGS) -shared -Wl,-$(EXPORT_DYNAMIC_NAME) $(TARGET).o -L$(BOOST_LIB) -$(BOOST) -L$(LIBPYTHON_PATH) -lpython$(PYTHON_VERSION_FINAL) -o $(TARGET).so
 
$(TARGET).o: $(TARGET).cpp
	g++ $(CFLAGS) -I$(PYTHON_INCLUDE) -I$(BOOST_INC) -fPIC -c $(TARGET).cpp
