CXX=g++
CXXFLAGS=-O3 -Wall -Werror -Wextra

INC_DIR=-I /usr/local/include
LIB_DIR=-L /usr/local/lib
LIBS=-lboost_timer -lboost_chrono -lboost_system

all: cache

cache: cache.cpp
	$(CXX) cache.cpp $(CXXFLAGS) $(INC_DIR) $(LIB_DIR) $(LIBS) -o cache

clean:
	rm -f cache *.o
