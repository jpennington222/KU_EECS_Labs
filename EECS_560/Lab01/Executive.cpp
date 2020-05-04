/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 560 Lab 01
 * @Brief: This program is the Executive.cpp file for the lab. It passes the inFile contents to the respective functions.
 */

#include "Executive.h"
#include "ListInterface.h"
#include "Node.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Executive::Executive(std::string Filename)
{
	file = Filename;
	m_list = new LinkedList<int>();
	ifstream inFile;
	inFile.open(file);

	if(inFile.is_open() == false)
	{
		std::cout<<"Error Opening File"<<"\n";
		exit(0);
	}

	int temp;
	while(inFile >> temp)
	{
		m_list -> insert(temp);
	}
	inFile.close();
}

void Executive::run()
{
	string choice = "0";
	while(choice != "11")
	{
		cout << "Choose one operation from the options below:\n";
		cout << "1. Is Empty\n";
		cout << "2. Length\n";
		cout << "3. Insert\n";
		cout << "4. Delete\n";
		cout << "5. Delete Duplicates\n";
		cout << "6. Find\n";
		cout << "7. Find Next\n";
		cout << "8. Print\n";
		cout << "9. Reverse List\n";
		cout << "10. Print At\n";
		cout << "11. Exit\n";
		cin >> choice;
		cout << '\n';

		//Is Empty
		if(choice == "1")
		{
			if(m_list -> isEmpty())
			{
				cout << "The list is empty.\n";
			}
			else
			{
				cout << "The list is not empty.\n";
			}
			cout << '\n';
		}

		//Length
		else if(choice == "2")
		{
			cout << "The length of the list is: " << m_list -> getLength();
			cout << '\n';
			cout << '\n';
		}

		//Insert
		else if(choice == "3")
		{
			int insertNum = 0;
			cout << "Choose a number to be inserted:\n";
			cin >> insertNum;
			m_list -> insert(insertNum);
			cout << insertNum << " is inserted.\n";
			cout << '\n';
		}

		//Delete
		else if(choice == "4")
		{
			int numDelete = 0;
			cout << "Choose a number to be deleted from the list: \n";
			cin >> numDelete;
			if(m_list -> find(numDelete))
			{
				m_list -> remove(numDelete);
				cout << "The last occurence of " << numDelete <<" has been deleted from the list.\n";
				cout << '\n';
			}
			else
			{
				cout << '\n';
			}
		}

		//Delete Duplicates
		else if(choice == "5")
		{
			m_list -> deleteDuplicates();
			cout << '\n';
		}

		//Find
		else if(choice == "6")
		{
			int numFind = 0;
			cout << "Enter the number to find:\n";
			cin >> numFind;
			if(m_list -> find(numFind))
			{
				cout << numFind << " is found in the list.\n";
			}
			cout << '\n';
		}

		//Find Next
		else if(choice == "7")
		{
			int numFindNext = 0;
			cout << "Enter the number to find its next element:\n";
			cin >> numFindNext;
			if(m_list -> find(numFindNext))
			{
				if(m_list -> findNext(numFindNext) != 0)
				{
					cout << m_list -> findNext(numFindNext) << " is next after " << numFindNext << '\n';
				}
				else
				{
					cout << numFindNext << " is the last element of the list.\n";
				}
			}
			else
			{
				cout << "Hence there is no next element.\n";
			}
			cout << '\n';
		}
		//Print
		else if(choice == "8")
		{
			m_list -> print();
			cout << '\n';
			cout << '\n';
		}

		//Print Reverse
		else if(choice == "9")
		{
			m_list -> printReverse();
			cout << '\n';
			cout << '\n';
		}

		//Print At
		else if(choice == "10")
		{
			int position = 0;
			cout << "Choose a position to print element:\n";
			cin >> position;
			m_list -> printAt(position);
			cout << '\n';
			cout << '\n';
		}

		//Exit
		else if(choice == "11")
		{
			cout << "Program execution completed!\n";
			cout << '\n';
		}

		//Bad Input
		else
		{
			cout << "Please enter a number between 1 and 11.\n";
			cout << '\n';
		}
	}
}

Executive::~Executive()
{
	delete m_list;
}
