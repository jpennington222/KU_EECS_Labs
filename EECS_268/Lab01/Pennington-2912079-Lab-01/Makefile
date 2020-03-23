
main: main.o StudentRecordDriver.o StudentRecord.o
	g++ -std=c++11 -g -Wall main.o StudentRecordDriver.o StudentRecord.o -o main

main.o: main.cpp StudentRecordDriver.h StudentRecord.h
	g++ -std=c++11 -g -Wall -c main.cpp

StudentRecordDriver.o: StudentRecordDriver.h StudentRecordDriver.cpp
	g++ -std=c++11 -g -Wall -c StudentRecordDriver.cpp

StudentRecord.o: StudentRecord.h StudentRecord.cpp
	g++ -std=c++11 -g -Wall -c StudentRecord.cpp

clean:
	rm *.o main


