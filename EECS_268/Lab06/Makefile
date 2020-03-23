
Lab06: main.o Executive.o Grammar.o
	g++ -std=c++11 -g -Wall main.o Executive.o Grammar.o -o Lab06

main.o: main.cpp Executive.h Grammar.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Grammar.o: Grammar.h Grammar.cpp
	g++ -std=c++11 -g -Wall -c Grammar.cpp

clean:
	rm *.o Lab06
