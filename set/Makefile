CXX=clang++
# The -static-libstdc++ flag is just so it compiles in the server I tested this on
CXXFLAGS=-std=c++11 -static-libstdc++ -O3 -Wall -Werror -Wextra

all: compare iterator

compare: set_compare.cpp
	$(CXX) $(CXXFLAGS) set_compare.cpp -o set_compare

iterator: set_iterator.cpp
	$(CXX) $(CXXFLAGS) set_iterator.cpp -o set_iterator
