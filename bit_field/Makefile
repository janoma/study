BOOST=/usr/local/Cellar/boost/1.55.0

CXX=clang++
CXXFLAGS=-std=c++11 -O3 -Wall -Werror -Wextra -I$(BOOST)/include

all: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o test
