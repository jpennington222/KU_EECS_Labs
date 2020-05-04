/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 560 Lab 02
 * @Brief: This program is the Executive.cpp file for the lab. It passes the inFile contents to the respective functions.
 */

#include "Executive.h"
#include "Node.h"
#include "LinkedList.h"
#include "HashTable.h"
#include "HashTableEntry.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

Executive::Executive(std::string Filename)
{
	m_HashTable = new HashTable<HashTableEntry>(7);
	file = Filename;
	ifstream inFile;
	inFile.open(file);
	string temp;
	string tempName;
	int swap = 1;
	int tempKey;
	int tempLength = 0;
	while(inFile >> temp)
	{

		if(swap % 2 == 1)
		{
			temp.pop_back();
			tempName = temp;
			swap++;
		}
		else
		{
			tempLength = temp.length();
			for(int i = 0; i<tempLength; i++)
			{
				if(temp[i] == ',')
				{
					temp.pop_back();
				}
			}
			tempKey = stoi(temp);
			tempLength = 0;
			swap++;
			HashTableEntry hte(tempName, tempKey);
			m_HashTable -> AddPlayer(hte);
		}


	}
	inFile.close();
}

void Executive::run()
{
	string choice = "0";
	while(choice != "7")
	{
		cout << "Choose one operation from the options below:\n";
		cout << "1- AddPlayer\n";
		cout << "2- RemovePlayer\n";
		cout << "3- PrintPlayersList\n";
		cout << "4- PlayerWithGoalCountEqualTo(g)\n";
		cout << "5- PlayerWithNumGoalsGreaterThan(h)\n";
		cout << "6- PlayerWithNumGoalsLessThan(i)\n";
		cout << "7- Exit\n";
		cin >> choice;
		cout << '\n';

		//Add Player
		if(choice == "1")
		{
			string tempRecord;
			string tempName;
			string tempKeyString;
			int tempLength;
			bool colon = false;
			cout << "Enter the record to be inserted:\n";
			cin.ignore();
			getline(cin, tempRecord, '\n');
			tempLength = tempRecord.length();
			for(int i = 0; i<tempLength; i++)
			{
				if(tempRecord[i] != ':' && colon == false)
				{
					tempName = tempName + tempRecord[i];
				}
				else if(tempRecord[i] == ':')
				{
					colon = true;
				}
				else if(colon == true)
				{
					tempKeyString = tempKeyString + tempRecord[i+1];
				}
			}

			bool added;
			int tempKey = atoi(tempKeyString.c_str());

			HashTableEntry hte(tempName, tempKey);
			added =	m_HashTable -> AddPlayer(hte);
			if(added == true)
			{
				cout << "Record is successfully inserted.\n";
			}
			else
			{
				cout << "Record not inserted. It is a duplicate entry.\n";
			}
			cout << '\n';
		}

		//Remove Player
		else if(choice == "2")
		{
			string tempRecord;
			string tempName;
			string tempKeyString;
			int tempLength;
			bool colon = false;
			cout << "Enter the record to be removed:\n";
			cin.ignore();
			getline(cin, tempRecord, '\n');
			tempLength = tempRecord.length();
			for(int i = 0; i<tempLength; i++)
			{
				if(tempRecord[i] != ':' && colon == false)
				{
					tempName = tempName + tempRecord[i];
				}
				else if(tempRecord[i] == ':')
				{
					colon = true;
				}
				else if(colon == true)
				{
					tempKeyString = tempKeyString + tempRecord[i+1];
				}
			}

			bool added;
			int tempKey = atoi(tempKeyString.c_str());

			HashTableEntry hte(tempName, tempKey);
			added =	m_HashTable -> RemovePlayer(hte);
			if(added == true)
			{
				cout << "Record successfully removed.\n";
			}
			else
			{
				cout << "Record not removed. No record found.\n";
			}
			cout << '\n';
		}

		//Print List
		else if(choice == "3")
		{
			m_HashTable -> PrintPlayerList();
		}

		//Equal To
		else if(choice == "4")
		{
			int goalCount;
			cout << "Enter the goal count:\n";
			cin >> goalCount;
			m_HashTable -> PlayerWithGoalCountEqualTo(goalCount);
			cout << '\n';
			cout << '\n';
		}

		//Greater Than
		else if(choice == "5")
		{
			int goalCount;
			cout << "Enter the goal count:\n";
			cin >> goalCount;
			m_HashTable -> PlayerWithNumGoalsGreaterThan(goalCount);
			cout<<'\n';
			cout<<'\n';
		}

		//Less Than
		else if(choice == "6")
		{
			int goalCount;
			cout << "Enter the goal count:\n";
			cin >> goalCount;
			m_HashTable -> PlayerWithNumGoalsLessThan(goalCount);
			cout<<'\n';
			cout<<'\n';
		}

		//Exit
		else if(choice == "7")
		{
			cout << "Bye Bye!\n";
			cout << '\n';
		}

		//Bad Input
		else
		{
			cout << "Please enter a number between 1 and 7.\n";
			cout << '\n';
		}
	}
}

Executive::~Executive()
{
	delete m_HashTable;
}
