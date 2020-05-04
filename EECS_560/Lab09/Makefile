Lab09: main.o Executive.o
	g++ -std=c++11 -g -Wall main.o Executive.o -o Lab09

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h LeftistHeap.cpp LeftistHeap.h SkewHeap.h SkewHeap.cpp BinaryNode.cpp BinaryNode.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o Lab09
