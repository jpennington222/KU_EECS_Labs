Lab01: main.o Executive.o
	g++ -std=c++11 -g -Wall main.o Executive.o -o Lab01

main.o: main.cpp Executive.h LinkedList.h LinkedList.cpp ListInterface.h Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o Lab01
