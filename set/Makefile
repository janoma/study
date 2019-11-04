CXX=g++
CXXFLAGS=-std=c++11 -O3 -Wall -Werror -Wextra

all: compare iterator

compare: set_compare.cpp
	$(CXX) $(CXXFLAGS) set_compare.cpp -o set_compare

iterator: set_iterator.cpp
	$(CXX) $(CXXFLAGS) set_iterator.cpp -o set_iterator

clean:
	rm -f set_compare set_iterator *.o
