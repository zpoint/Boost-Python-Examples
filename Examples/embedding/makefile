PYTHON_VERSION = 3.5
TARGET = embdding

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

 
$(TARGET): $(TARGET).cpp
	g++ $(CFLAGS) -I$(PYTHON_INCLUDE) -I$(BOOST_INC) -L/usr/lib/python$(PYTHON_VERSION)/config $(TARGET).cpp -o $(TARGET) -lpython$(PYTHON_VERSION_FINAL) -$(BOOST) -lboost_system
