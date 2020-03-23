Lab9: main.o Executive.o PrecondViolatedExcep.o NotFoundException.o Task.o
	g++ -std=c++11 -g -Wall main.o Executive.o PrecondViolatedExcep.o NotFoundException.o Task.o -o Lab9

main.o: main.cpp Executive.h BinaryNode.h BinaryNode.cpp BinaryTreeInterface.h BinarySearchTree.h BinarySearchTree.cpp PrecondViolatedExcep.h NotFoundException.h Node.h Node.cpp Task.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

NotFoundException.o: NotFoundException.h NotFoundException.cpp
	g++ -std=c++11 -g -Wall -c NotFoundException.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp

Task.o: Task.h Task.cpp
		g++ -std=c++11 -g -Wall -c Task.cpp

clean:
	rm *.o Lab9
