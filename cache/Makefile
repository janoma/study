CXX=g++
CXXFLAGS=-std=c++11 -O3 -Wall -Werror -Wextra

LIBS=-lboost_timer -lboost_chrono -lboost_system

all: cache

cache: cache.cpp
	$(CXX) cache.cpp $(CXXFLAGS) $(LIBS) -o cache

clean:
	rm -f cache *.o
