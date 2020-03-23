Lab03: main.o Executive.o PrecondViolatedExcep.o Process.o
	g++ -std=c++11 -g -Wall main.o Executive.o PrecondViolatedExcep.o  Process.o -o Lab03

main.o: main.cpp Executive.h LinkedList.h ListInterface.h Node.h PrecondViolatedExcep.h Process.h Queue.h QueueInterface.h Stack.h StackInterface.h Queue.cpp Stack.cpp LinkedList.cpp Node.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp

Process.o: Process.h Process.cpp
	g++ -std=c++11 -g -Wall -c Process.cpp

clean:
	rm *.o Lab03
