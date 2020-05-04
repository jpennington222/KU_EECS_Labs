Lab07: main.o Executive.o BSTEntry.o
	g++ -std=c++11 -g -Wall main.o Executive.o BSTEntry.o -o Lab07

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h minHeap.h minHeap.cpp maxHeap.h maxHeap.cpp BSTEntry.h BSTEntry.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o Lab07
