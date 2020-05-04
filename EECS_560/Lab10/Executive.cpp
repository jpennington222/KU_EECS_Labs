/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 560 Lab 10
 * @Brief: This program is the Executive.cpp file for the lab. It passes the inFile contents to the respective functions.
 */

#include "Executive.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Executive::Executive(std::string Filename, std::string Filename2)
{
	string temp;
	bool size = false;
	int count = 0;

	file1 = Filename; //Disjoint set
	file2 = Filename2; //Graph

	ifstream inFile(file2);
	if(inFile.is_open())
	{
		while(!inFile.eof())
		{
			inFile >> temp;
			if(temp.size() != 1)
			{
				m_names[count] = temp;
				count++;
			}
			if(temp == "n" && size == false)
			{
				inFile >> m_size;
				size = true;
				m_arr = new int*[m_size];
				int test = 0;
				for(int i = 0; i < m_size; i++)
				{
					m_arr[i] = new int[m_size];
					for(int j = 0; j < m_size; j++)
					{
						if(inFile >> test)
						{
							m_arr[i][j] = test;
						}
					}
				}
			}
		}
	}
	m_graph = new Graph(m_arr,m_size);
	inFile.close();
}

void Executive::run()
{
	string choice = "0";
	while(choice != "10")
	{
		cout << "Choose one operation from the options below:\n";
		cout << "1- Make Set\n";
		cout << "2- Union\n";
		cout << "3- Find\n";
		cout << "4- Path Compression\n";
		cout << "5- Print Path\n";
		cout << "6- BFS\n";
		cout << "7- DFS\n";
		cout << "8- Kruskal MST\n";
		cout << "9- Prim MST\n";
		cout << "10- Exit\n";

		cin >> choice;
		cout << '\n';

		//Make Set
		if(choice == "1")
		{
			ifstream inFile;
			inFile.open(file1);
			int temp;
			vector<int> nums;
			while(!inFile.eof())
			{
				inFile >> temp;
				nums.push_back(temp);
			}
			m_disjointSet = new DisjointSet(nums.size());
			int vSize = nums.size();
			for(int i=0; i<vSize; i++)
			{
				m_disjointSet -> makeSet(nums.front());
				nums.erase(nums.begin());
			}
			cout << "The disjoint sets have been constructed\n";
			cout << '\n';
		}

		//Union
		else if(choice == "2")
		{
			int num1 = 0;
			int num2 = 0;
			cout << "Enter representative 1: ";
			cin >> num1;
			cout << "Enter representative 2: ";
			cin >> num2;
			m_disjointSet -> Union(num1, num2);
			int rep = m_disjointSet -> find(num1);
			cout << num1 << " and " << num2 << " have been merged\n";
			cout << "The representative element is: " << rep << '\n';
			cout << '\n';
		}

		//Find
		else if(choice == "3")
		{
			int num = 0;
			int rep = 0;
			cout << "Enter the element to find: ";
			cin >> num;
			rep = m_disjointSet -> find(num);
			if(rep != -1)
			{
				cout << "Element " << num << " has been found successfully\n";
				cout << "The representative element is: " << rep << '\n';
			}
			else
			{
				cout << "Element not found\n";
			}
			cout << '\n';
		}

		//Path Compression
		else if(choice == "4")
		{
			int num;
			cout << "Enter the element to perform path compression: ";
			cin >> num;
			m_disjointSet -> pathCompression(num);
			cout << "Path compression completed\n";
			cout << '\n';
		}

		//Print Path
		else if(choice == "5")
		{
			int num;
			cout << "Enter an element to find its path: ";
			cin >> num;
			m_disjointSet -> printPath(num);
			cout << '\n';
			cout << '\n';
		}

		//BFS
		else if(choice == "6")
		{
			m_graph -> BFS(m_names);
			cout << '\n';
			cout << '\n';
		}

		//DFS
		else if(choice == "7")
		{
			m_graph -> DFS(m_names);
			cout << '\n';
			cout << '\n';
		}

		//Kruskal
		else if(choice == "8")
		{
			m_graph -> Kruskal(m_names);
			cout << '\n';
		}

		//Prim
		else if(choice == "9")
		{
			m_graph -> Prim(m_names);
			cout << '\n';
		}

		//Exit
		else if(choice == "10")
		{
			cout << "Bye Bye!\n";
		}

		//Bad Input
		else
		{
			cout << "Please enter a number between 1 and 10.\n";
			cout << '\n';
		}
	}
}


Executive::~Executive()
{
	for(int i = 0; i < m_size; i++)
	{
		delete[] m_arr[i];
	}
	delete[] m_arr;
	delete m_graph;
	delete m_disjointSet;
}
