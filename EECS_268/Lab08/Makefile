Lab8: main.o Executive.o PrecondViolatedExcep.o
	g++ -std=c++11 -g -Wall main.o Executive.o PrecondViolatedExcep.o -o Lab8

main.o: main.cpp Executive.h BinaryNode.h BinaryNode.cpp BinaryNodeTree.h BinaryNodeTree.cpp BinaryTreeInterface.h Stack.h Stack.cpp StackInterface.h PrecondViolatedExcep.h Node.h Node.cpp LinkedList.cpp LinkedList.h ListInterface.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp

clean:
	rm *.o Lab8
