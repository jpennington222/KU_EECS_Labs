/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 560 Lab 08
 * @Brief: This program is the Executive.cpp file for the lab. It passes the inFile contents to the respective functions.
 */

#include "Executive.h"
#include "BSTEntry.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Executive::Executive(std::string Filename)
{
	ifstream inFile;
	inFile.open(Filename);
	string tempName;
	string tempKey;
	string temp;

	while(inFile >> temp)
	{
		bool comma1 = false;
		int tempSize = temp.size();
		for(int i = 0; i < tempSize; i++)
    {
      if(temp[i] != ',' && comma1 == false)
      {
        tempName = tempName + temp[i];
      }

      else if(temp[i] == ',' && comma1 == false)
      {
        comma1 = true;
      }
			else if(comma1 == true)
      {
        tempKey = tempKey + temp[i];
      }
		}

		int numberKey = stoi(tempKey);
		BSTEntry bste(tempName, numberKey);
		//cout << bste.getName() << " " << bste.getKey() << '\n';
		myHeap.insert(bste);
		temp = "";
		tempName = "";
		tempKey = "";
	}
	inFile.close();
	//myHeap.levelOrder();
}

void Executive::run()
{
	string choice = "0";
	while(choice != "8")
	{
		//myHeap.levelOrder();
		cout << "Choose one operation from the options below:\n";
		cout << "1- Add Game\n";
		cout << "2- Delete Max Downloaded Game\n";
		cout << "3- Delete Game\n";
		cout << "4- Print Games at Minimum Levels\n";
		cout << "5- Print Games at Maximum Levels\n";
		cout << "6- Total Minimum Downloaded Games\n";
		cout << "7- Total Maximum Downloaded Games\n";
		cout << "8- Exit\n";
		cin >> choice;
		cout << '\n';

		//Add Game
		if(choice == "1")
		{
			string tempName;
			int tempKey;
			cout << "Enter the name of the game: ";
			cin >> tempName;
			cout << "Enter the number of downloads in thousands: ";
			cin >> tempKey;
			BSTEntry bste(tempName, tempKey);
			myHeap.insert(bste);
			if(myHeap.getAdded() == true)
			{
				cout << "New game added\n";
			}
			else
			{
				cout << "The game was not added\n";
			}
			cout << '\n';
		}

		//Delete Max
		else if(choice == "2")
		{
			if(myHeap.getItemCount() == 0)
			{
				cout << "Empty Heap\n";
			}
			else
			{
				cout << "The game with the maximum downloads has been deleted\n";
				cout << "Game details: \n";
				myHeap.deleteMax();
				myHeap.heapify();
			}
			cout << '\n';
		}

		//General Delete
		else if(choice == "3")
		{
			if(myHeap.getItemCount() == 0)
			{
				cout << "Empty Heap\n";
			}
			else
			{
				string tempName;
				int tempKey;
				cout << "Enter the name of the game to delete: ";
				cin >> tempName;
				cout << "Enter the number of downloads in thousands to delete: ";
				cin >> tempKey;
				myHeap.generalDelete(tempName, tempKey);
				myHeap.heapify();
			}
		}

		//Minimum Level Print
		else if(choice == "4")
		{
			if(myHeap.getItemCount() == 0)
			{
				cout << "Empty Heap\n";
			}
			else
			{
				cout << "Games on minimum levels: ";
				myHeap.printMins();
				cout << '\n';
			}
			cout << '\n';
		}

		//Maximum Level Print
		else if(choice == "5")
		{
			if(myHeap.getItemCount() == 0)
			{
				cout << "Empty Heap\n";
			}
			else
			{
				cout << "Games on maximum levels: ";
				myHeap.printMaxs();
				cout << '\n';
			}
			cout << '\n';
		}

		//Total Minimum
		else if(choice == "6")
		{
			if(myHeap.getItemCount() == 0)
			{
				cout << "Empty Heap\n";
			}
			else
			{
				cout << "Total sum of downloads on minimum levels: " << myHeap.totalMins() << '\n';
			}
			cout << '\n';
		}

		//Total Maximum
		else if(choice == "7")
		{
			if(myHeap.getItemCount() == 0)
			{
				cout << "Empty Heap\n";
			}
			else
			{
				cout << "Total sum of downloads on maximum levels: " << myHeap.totalMaxs() << '\n';
			}
			cout << '\n';
		}

		//Exit
		else if(choice == "8")
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

}
