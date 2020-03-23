main: main.o CircleDriver.o Circle.o
	g++ -std=c++11 -g -Wall main.o CircleDriver.o Circle.o -o main

main.o: main.cpp CircleDriver.h Circle.h
	g++ -std=c++11 -g -Wall -c main.cpp

CircleDriver.o: CircleDriver.h CircleDriver.cpp
	g++ -std=c++11 -g -Wall -c CircleDriver.cpp

Circle.o: Circle.h Circle.cpp
	g++ -std=c++11 -g -Wall -c Circle.cpp

clean:
	rm *.o main
