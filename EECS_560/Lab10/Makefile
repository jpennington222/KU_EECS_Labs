#Makefile
Lab10: main.o Executive.o Graph.o Vertex.o Edge.o DisjointSet.o
	g++ -Wall -g -std=c++11 main.o Graph.o Vertex.o Edge.o Executive.o DisjointSet.o -o Lab10
Executive.o: Executive.h Executive.cpp Graph.h DisjointSet.h
	g++ -Wall -std=c++11 -c Executive.cpp
DisjointSet.o: DisjointSet.h DisjointSet.cpp BinaryNode.h BinaryNode.cpp
	g++ -Wall -std=c++11 -c DisjointSet.cpp
main.o: main.cpp Executive.h
	g++ -Wall -std=c++11  -c main.cpp
Graph.o: Graph.h Graph.cpp Edge.h minHeap.h minHeap.cpp Vertex.h
	g++ -Wall -std=c++11  -c Graph.cpp
Vertex.o: Vertex.h Vertex.cpp
	g++ -Wall -std=c++11  -c Vertex.cpp
Edge.o: Edge.h Edge.cpp
	g++ -Wall -std=c++11  -c Edge.cpp
clean:
	rm *.o Lab10
