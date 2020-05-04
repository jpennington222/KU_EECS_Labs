Lab08: main.o Executive.o BSTEntry.o
	g++ -std=c++11 -g -Wall main.o Executive.o BSTEntry.o -o Lab08

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h maxMinHeap.h maxMinHeap.cpp BSTEntry.h BSTEntry.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o Lab08
