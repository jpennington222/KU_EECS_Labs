Lab04: main.o Executive.o BSTEntry.o
	g++ -std=c++11 -g -Wall main.o Executive.o BSTEntry.o -o Lab04

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h BST.cpp BST.h BinaryNode.cpp BinaryNode.h BSTEntry.h BSTEntry.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o Lab04
