Lab05: main.o Executive.o
	g++ -std=c++11 -g -Wall main.o Executive.o -o Lab05

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp LinkedList.h LinkedList.cpp Node.h Node.cpp HashTable.h HashTable.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o Lab05
