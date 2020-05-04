Lab06: main.o Executive.o
	g++ -std=c++11 -g -Wall main.o Executive.o -o Lab06

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h BST.cpp BST.h BinaryNode.cpp BinaryNode.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o Lab06
