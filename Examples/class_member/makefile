PYTHON_VERSION = 3.5
TARGET = class_member

CFLAGS = -lm -pthread -O3 -std=c++11 -march=native -Wall -funroll-loops -Wno-unused-result

PYTHON_INCLUDE = /usr/include/python$(PYTHON_VERSION)
 
# Only need if install from source
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
	g++ $(CFLAGS) -shared -Wl,--export-dynamic $(TARGET).o -L$(BOOST_LIB) -$(BOOST) -L/usr/lib/python$(PYTHON_VERSION)/config -lpython$(PYTHON_VERSION_FINAL) -o $(TARGET).so
 
$(TARGET).o: $(TARGET).cpp
	g++ $(CFLAGS) -I$(PYTHON_INCLUDE) -I$(BOOST_INC) -fPIC -c $(TARGET).cpp
