PYTHON_VERSION = 3.5
TARGET = hello_ext

PYTHON_INCLUDE = /usr/include/python$(PYTHON_VERSION)
 
# location of the Boost Python include files and library

# install step
# tar -xzvf boost_1_65_0.tar.gz
# ./bootstrap.sh --with-python=/usr/bin/python3 --with-python-version=3.5 --with-python-root=/usr/local/lib/python3.5 --prefix=/usr/local
# sudo ./b2 install -a --with=all
# sudo ldconfig

BOOST_INC = /usr/local/include/boost
BOOST_LIB = /usr/local/lib


ifeq ($(PYTHON_VERSION), 3.5)
	BOOST = lboost_python3
	PYTHON_VERSION_FINAL = $(PYTHON_VERSION)m
else
	BOOST = lboost_python
	PYTHON_VERSION_FINAL = $(PYTHON_VERSION)
endif

 
$(TARGET).so: $(TARGET).o
	g++ -shared -Wl,--export-dynamic $(TARGET).o -L$(BOOST_LIB) -$(BOOST) -L/usr/lib/python$(PYTHON_VERSION)/config -lpython$(PYTHON_VERSION_FINAL) -o $(TARGET).so
 
$(TARGET).o: $(TARGET).cpp
	g++ -I$(PYTHON_INCLUDE) -I$(BOOST_INC) -fPIC -c $(TARGET).cpp
