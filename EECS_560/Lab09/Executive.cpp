/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 560 Lab 09
 * @Brief: This program is the Executive.cpp file for the lab. It passes the inFile contents to the respective functions.
 */

#include "Executive.h"
#include "BinaryNode.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Executive::Executive(std::string Filename)
{
	ifstream inFile(Filename);
	int temp = 0;
	m_left = new LeftistHeap<int, int>();
  m_skew = new SkewHeap<int, int>();
  while(inFile >> temp)
	{
    m_left->add(temp);
    m_skew->add(temp);
  }
  inFile.close();
}

void Executive::run()
{
	string choice = "0";
	while(choice != "6")
	{
		//myHeap.levelOrder();
		cout << "Choose one operation from the options below:\n";
		cout << "1- Test Build - Min Leftist Heap\n";
		cout << "2- Test Delete Min - Min Leftist Heap\n";
		cout << "3- Test Build - Min Skew Heap\n";
		cout << "4- Test Delete Min - Min Skew Heap\n";
		cout << "5- Test Performance of Heaps\n";
		cout << "6- Exit\n";
		cin >> choice;
		cout << '\n';

		//Test Build Leftist
		if(choice == "1")
		{
			cout << "Level order of Min Leftist Heap:\n";
			m_left -> levelOrder();
			cout << '\n';
			cout << '\n';
		}

		//Test Delete Leftist
		else if(choice == "2")
		{
			cout << "Minimum element deleted\n";
			m_left -> removeMin();
			cout << "Level order of Min Leftist Heap:\n";
			m_left -> levelOrder();
			cout << '\n';
			cout << '\n';
		}

		//Test Build Skew
		else if(choice == "3")
		{
			cout << "Level order of Min Skew Heap:\n";
			m_skew -> levelOrder();
			cout << '\n';
			cout << '\n';
		}

		//Test Delete Skew
		else if(choice == "4")
		{
			cout << "Minimum element deleted\n";
			m_skew -> removeMin();
			cout << "Level order of Min Skew Heap:\n";
			m_skew -> levelOrder();
			cout << '\n';
			cout << '\n';
		}

		//Test Performance
		else if(choice == "5")
		{
			int random = 0;
			int inputSize = 0;

		//----------------------Build Size = 100,000-------------------------------------

			srand(time(NULL));
			inputSize = 100000;

			m_left1 = new LeftistHeap<int, int>();
			m_skew1 = new SkewHeap<int, int>();

			//Leftist Build
			clock_t start = clock();
			for(int i=0; i<inputSize; i++)
			{
				random = rand() % 5000000 + 1;
				m_left1 -> add(random);
			}
			clock_t stop = clock();
			double leftInsert1 = (double)(stop-start) / CLOCKS_PER_SEC;


			//Leftist Delete
			start = clock();
			m_left1 -> removeMin();
			stop = clock();
			double leftRemove1 = (double)(stop-start) / CLOCKS_PER_SEC;


			//Skew Build
			start = clock();
			for(int i=0; i<inputSize; i++)
			{
				random = rand() % 5000000 + 1;
				m_skew1 -> add(random);
			}
			stop = clock();
			double skewInsert1 = (double)(stop-start) / CLOCKS_PER_SEC;


			//Skew Delete
			start = clock();
			m_skew1 -> removeMin();
			stop = clock();
			double skewRemove1 = (double)(stop-start) / CLOCKS_PER_SEC;
			cout << "Set 1 Complete\n";

		//----------------------Build Size = 200,000-------------------------------------

			srand(time(NULL));
			inputSize = 200000;

			m_left2 = new LeftistHeap<int, int>();
			m_skew2 = new SkewHeap<int, int>();

			//Leftist Build
			start = clock();
			for(int i=0; i<inputSize; i++)
			{
				random = rand() % 5000000 + 1;
				m_left2 -> add(random);
			}
			stop = clock();
			double leftInsert2 = (double)(stop-start) / CLOCKS_PER_SEC;


			//Leftist Delete
			start = clock();
			m_left2 -> removeMin();
			stop = clock();
			double leftRemove2 = (double)(stop-start) / CLOCKS_PER_SEC;


			//Skew Build
			start = clock();
			for(int i=0; i<inputSize; i++)
			{
				random = rand() % 5000000 + 1;
				m_skew2 -> add(random);
			}
			stop = clock();
			double skewInsert2 = (double)(stop-start) / CLOCKS_PER_SEC;


			//Skew Delete
			start = clock();
			m_skew2 -> removeMin();
			stop = clock();
			double skewRemove2 = (double)(stop-start) / CLOCKS_PER_SEC;
			cout << "Set 2 Complete\n";

			//----------------------Build Size = 300,000-------------------------------------

			srand(time(NULL));
			inputSize = 300000;

			m_left3 = new LeftistHeap<int, int>();
			m_skew3 = new SkewHeap<int, int>();

			//Leftist Build
			start = clock();
			for(int i=0; i<inputSize; i++)
			{
				random = rand() % 5000000 + 1;
				m_left3 -> add(random);
			}
			stop = clock();
			double leftInsert3 = (double)(stop-start) / CLOCKS_PER_SEC;


			//Leftist Delete
			start = clock();
			m_left3 -> removeMin();
			stop = clock();
			double leftRemove3 = (double)(stop-start) / CLOCKS_PER_SEC;


			//Skew Build
			start = clock();
			for(int i=0; i<inputSize; i++)
			{
				random = rand() % 5000000 + 1;
				m_skew3 -> add(random);
			}
			stop = clock();
			double skewInsert3 = (double)(stop-start) / CLOCKS_PER_SEC;


			//Skew Delete
			start = clock();
			m_skew3 -> removeMin();
			stop = clock();
			double skewRemove3 = (double)(stop-start) / CLOCKS_PER_SEC;
			cout << "Set 3 Complete\n";

			//----------------------Build Size = 400,000-------------------------------------

			srand(time(NULL));
			inputSize = 400000;

			m_left4 = new LeftistHeap<int, int>();
			m_skew4 = new SkewHeap<int, int>();

			//Leftist Build
			start = clock();
			for(int i=0; i<inputSize; i++)
			{
				random = rand() % 5000000 + 1;
				m_left4 -> add(random);
			}
			stop = clock();
			double leftInsert4 = (double)(stop-start) / CLOCKS_PER_SEC;


			//Leftist Delete
			start = clock();
			m_left4 -> removeMin();
			stop = clock();
			double leftRemove4 = (double)(stop-start) / CLOCKS_PER_SEC;


			//Skew Build
			start = clock();
			for(int i=0; i<inputSize; i++)
			{
				random = rand() % 5000000 + 1;
				m_skew4 -> add(random);
			}
			stop = clock();
			double skewInsert4 = (double)(stop-start) / CLOCKS_PER_SEC;


			//Skew Delete
			start = clock();
			m_skew4 -> removeMin();
			stop = clock();
			double skewRemove4 = (double)(stop-start) / CLOCKS_PER_SEC;
			cout << "Set 4 Complete\n";

		//----------------------Build Size = 500,000-------------------------------------

			srand(time(NULL));
			inputSize = 500000;

			m_left5 = new LeftistHeap<int, int>();
			m_skew5 = new SkewHeap<int, int>();

			//Leftist Build
			start = clock();
			for(int i=0; i<inputSize; i++)
			{
				random = rand() % 5000000 + 1;
				m_left5 -> add(random);
			}
			stop = clock();
			double leftInsert5 = (double)(stop-start) / CLOCKS_PER_SEC;


			//Leftist Delete
			start = clock();
			m_left5 -> removeMin();
			stop = clock();
			double leftRemove5 = (double)(stop-start) / CLOCKS_PER_SEC;


			//Skew Build
			start = clock();
			for(int i=0; i<inputSize; i++)
			{
				random = rand() % 5000000 + 1;
				m_skew5 -> add(random);
			}
			stop = clock();
			double skewInsert5 = (double)(stop-start) / CLOCKS_PER_SEC;


			//Skew Delete
			start = clock();
			m_skew5 -> removeMin();
			stop = clock();
			double skewRemove5 = (double)(stop-start) / CLOCKS_PER_SEC;
			cout << "Set 5 Complete\n";

		//----------------------End Data Collection------------------------------------


			cout << "                     Performance Min Leftist Heap\n";
			cout << "____________________________________________________________________________________________\n\n";
			cout << "Input Size                 | 100,000 | 200,000 | 300,000 | 400,000 | 500,000 |\n";
			cout << "Build(s)                   | " << leftInsert1 << " | " << leftInsert2 << " | " << leftInsert3 << " | " << leftInsert4 << " | " << leftInsert5 << " |\n";
			cout << "Delete Min (s)             | " << leftRemove1 << " | " << leftRemove2 << " | " << leftRemove3 << " | " << leftRemove4 << " | " << leftRemove5 << " |\n";
			cout <<  "____________________________________________________________________________________________\n";


			cout << '\n';
			cout << '\n';


			cout << "                     Performance Min Skew Heap\n";
			cout << "____________________________________________________________________________________________\n\n";
			cout << "Input Size                 | 100,000 | 200,000 | 300,000 | 400,000 | 500,000 |\n";
			cout << "Build(s)                   | " << skewInsert1 << " | " << skewInsert2 << " | " << skewInsert3 << " | " << skewInsert4 << " | " << skewInsert5 << " |\n";
			cout << "Delete Min (s)             | " << skewRemove1 << " | " << skewRemove2 << " | " << skewRemove3 << " | " << skewRemove4 << " | " << skewRemove5 << " |\n";
			cout <<  "____________________________________________________________________________________________\n";

			cout << '\n';

		}

		//Exit
		else if(choice == "6")
		{
			cout << "Bye Bye!\n";
			cout << '\n';
		}

		//Bad Input
		else
		{
			cout << "Please enter a number between 1 and 8.\n";
			cout << '\n';
		}
	}
}

Executive::~Executive()
{
	delete m_left;
	delete m_skew;
	delete m_left1;
	delete m_skew1;
	delete m_left2;
	delete m_skew2;
	delete m_left3;
	delete m_skew3;
	delete m_left4;
	delete m_skew4;
	delete m_left5;
	delete m_skew5;
}
