CXX=g++

jumble: jumble.cpp charlist.cpp charlist.h
	$(CXX) jumble.cpp  charlist.cpp -o jumble

settest: set.o settest.o
	$(CXX) set.o settest.o -o settest

set.o: set.cpp set.h
	$(CXX) -c set.cpp

settest.o: settest.cpp set.h
	$(CXX) -c settest.cpp
clean:
	rm -f *.o settest
