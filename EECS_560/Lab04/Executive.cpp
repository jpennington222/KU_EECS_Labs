/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 560 Lab 04
 * @Brief: This program is the Executive.cpp file for the lab. It passes the inFile contents to the respective functions.
 */

#include "Executive.h"
#include "BSTEntry.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

Executive::Executive(std::string Filename)
{
	m_Tree = new BST<BSTEntry>();

	string tempMovie;
	float tempRating;
	string temp;

	file = Filename;
	ifstream inFile;
	inFile.open(file);
	int swap = 1;

	while(inFile >> temp)
	{
		if(swap % 2 == 1)
		{
			temp.pop_back();
			tempMovie = temp;
			swap++;
		}
		else
		{
			stringstream s;
			s << temp;
			s >> tempRating;
	 		BSTEntry bste(tempMovie, tempRating);

			m_Tree -> add(bste);
			swap++;
			tempRating = 0;
			tempMovie = "";

			// cout << bste.getMovie() << '\n';
			// cout << bste.getRating() << '\n';
		}

	}
	inFile.close();
}

void Executive::run()
{
	string choice = "0";
	while(choice != "11")
	{
		cout << "Choose one operation from the options below:\n";
		cout << "1- Is Full\n";
		cout << "2- Add Movie\n";
		cout << "3- Remove Movie\n";
		cout << "4- Leaf\n";
		cout << "5- Print Leaves\n";
		cout << "6- Print Tree Height\n";
		cout << "7- Preorder\n";
		cout << "8- Postorder\n";
		cout << "9- Inorder\n";
		cout << "10- Levelorder\n";
		cout << "11- Exit\n";
		cin >> choice;
		cout << '\n';

		//Is Full
		if(choice == "1")
		{
			if(m_Tree -> isFull() == true)
			{
				cout << "The tree is full\n";
			}
			else
			{
				cout << "The tree is not full\n";
			}
			cout << '\n';
		}

		//Add Movie
		else if(choice == "2")
		{
			string title;
			float rating;
			cout << "Enter movie title: ";
			cin >> title;
			cout << "Enter rating: ";
			cin >> rating;
			BSTEntry bste(title, rating);
			m_Tree -> add(bste);
			if(m_Tree -> getAdded() == true)
			{
				cout << "Record succesfully added\n";
			}
			else
			{
				cout << "Record not added\n";
			}
			cout << '\n';
		}

		//Remove Movie
		else if(choice == "3")
		{
			m_Tree -> remove();
			cout << '\n';
		}

		//Leaf
		else if(choice == "4")
		{
			string tempMovie;
			cout << "Input movie title: ";
			cin >> tempMovie;
			m_Tree -> isLeaf(m_Tree -> getRoot(),tempMovie);
			if(m_Tree -> getFoundLeaf() == true)
			{
				cout << tempMovie << " is a leaf node\n";
			}
			else
			{
				cout << tempMovie << " is not a leaf node\n";
			}
			cout << '\n';
		}

		//Print Leaves
		else if(choice == "5")
		{
			cout << "The leaf nodes are: \n";
			m_Tree -> printLeaves(m_Tree -> getRoot());
			cout << '\n';
			cout << '\n';
		}

		//Print Tree Height
		else if(choice == "6")
		{
			cout << "The height of the tree is " << m_Tree -> getHeight() << '\n';
			cout << '\n';
		}

		//Preorder
		else if(choice == "7")
		{
			cout << "Printing in Pre-Order:\n";
			m_Tree -> preOrder(m_Tree -> getRoot());
			cout << '\n';
			cout << '\n';
		}

		//Postorder
		else if(choice == "8")
		{
			cout << "Printing in Post-Order:\n";
			m_Tree -> postOrder(m_Tree -> getRoot());
			cout << '\n';
			cout << '\n';
		}

		//Inorder
		else if(choice == "9")
		{
			cout << "Printing in In-Order:\n";
			m_Tree -> inOrder(m_Tree -> getRoot());
			cout << '\n';
			cout << '\n';
		}

		//Levelorder
		else if(choice == "10")
		{
			cout << "Printing in Level Order:\n";
			m_Tree -> levelOrder();
			cout << '\n';
			cout << '\n';
		}

		//Exit
		else if(choice == "11")
		{
			cout << "Bye Bye!\n";
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
	delete m_Tree;
}
