CXX=g++

all: debug crack game

debug: debug.cpp
	$(CXX) debug.cpp -o debug

crack: crack.cpp
	$(CXX) crack.cpp -o crack

game: main.cpp life.cpp life.h
	$(CXX) main.cpp life.cpp -o game

clean: 
	rm -f debug crack game
