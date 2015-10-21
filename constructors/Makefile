CXX=g++
CXXFLAGS=-std=c++11 -O3 -Wall -Werror -Wextra

INC_DIR=-I /usr/local/include
LIB_DIR=-L /usr/local/lib
LIBS=

all: constructors

constructors: constructors.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIR) $(LIB_DIR) $(LIBS) constructors.cpp -o constructors

clean:
	rm -f constructors *.o
