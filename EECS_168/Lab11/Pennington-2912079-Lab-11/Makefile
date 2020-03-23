main: main.o ArrayWrapperDriver.o ArrayWrapper.o
	g++ -std=c++11 -g -Wall main.o ArrayWrapperDriver.o ArrayWrapper.o -o main

main.o: main.cpp ArrayWrapperDriver.h ArrayWrapper.h
	g++ -std=c++11 -g -Wall -c main.cpp

ArrayWrapperDriver.o: ArrayWrapperDriver.h ArrayWrapperDriver.cpp
	g++ -std=c++11 -g -Wall -c ArrayWrapperDriver.cpp

ArrayWrapper.o: ArrayWrapper.h ArrayWrapper.cpp
	g++ -std=c++11 -g -Wall -c ArrayWrapper.cpp

clean:
	rm *.o main
