Lab02: main.o Executive.o WebBrowser.o
	g++ -std=c++11 -g -Wall main.o Executive.o WebBrowser.o -o Lab02

main.o: main.cpp Executive.h WebBrowser.h WebBrowserInterface.h LinkedList.h LinkedList.cpp ListInterface.h Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

WebBrowser.o: WebBrowser.h WebBrowser.cpp
	g++ -std=c++11 -g -Wall -c WebBrowser.cpp

clean:
	rm *.o Lab02
