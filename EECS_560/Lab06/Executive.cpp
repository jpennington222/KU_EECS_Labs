/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 560 Lab 06
 * @Brief: This program is the Executive.cpp file for the lab. It passes the inFile contents to the respective functions.
 */

#include "Executive.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

Executive::Executive(std::string Filename)
{
	m_Tree = new BST<int>();
	int temp;

	file = Filename;
	ifstream inFile;
	inFile.open(file);
	while(inFile >> temp)
	{
		m_Tree -> add(temp);
	}
	inFile.close();
}

void Executive::run()
{
	vector<int> nums;
	int temp;
	ifstream inFile;
	inFile.open(file);
	while(inFile >> temp)
	{
		nums.push_back(temp);
	}
	sort(nums.begin(), nums.end(), less<int>());
	inFile.close();

	string choice = "0";
	while(choice != "9")
	{
		// for(const auto &i: nums)
		// {
		// 	cout << i << ' ';
		// }
		// cout << '\n';
		// cout << "Printing in In order\n";
		// m_Tree -> inOrder(m_Tree -> getRoot());
		// cout << '\n';


		cout << "Choose one operation from the options below:\n";
		cout << "1- Add Item\n";
		cout << "2- Delete Item\n";
		cout << "3- In-Order Successor\n"; //print in order and the next one is the successor (duplicate count as 1)
		cout << "4- Level Order\n"; //normal level order
		cout << "5- Spiral Level Order\n"; //start from left and spiral around tree
		cout << "6- Left Side View\n"; //first element of each level
		cout << "7- Right Side View\n"; //last element of each level
		cout << "8- Kth Smallest Item\n"; //inorder traversal and print the xth element (duplicate counts as 1)
		cout << "9- Exit\n";
		cin >> choice;
		cout << '\n';

		//Add Item
		if(choice == "1")
		{
			int temp;
			cout << "Enter the element to be added: ";
			cin >> temp;
			if(m_Tree -> add(temp))
			{
				nums.push_back(temp);
				sort(nums.begin(), nums.end(), less<int>());
				cout << "Element " << temp << " was successfully added\n";
			}
			else
			{
				cout << "Element " << temp << " was not successfully added\n";
			}
			cout << '\n';
		}

		//Delete Item
		else if(choice == "2")
		{
			if(!nums.empty())
			{
				int temp;
				cout << "Enter the element to be deleted: ";
				cin >> temp;
				m_Tree -> remove(temp);
				if(m_Tree -> getDeleted() == true)
				{
					auto it = find(nums.begin(), nums.end(), temp);
					if(it != nums.end())
					{
						nums.erase(it);
					}
					cout << "Element " << temp << " was successfully deleted\n";
				}
				else
				{
					cout << "Element " << temp << " was not successfully deleted\n";
				}
			}
			else
			{
				cout << "Empty Tree\n";
			}
			cout << '\n';
		}

		//In-Order Successor
		else if(choice == "3")
		{
			if(!nums.empty())
			{
				bool found = false;
				int succ;
				cout << "Enter the element to which you want to know the inorder successor: ";
				cin >> succ;

				vector<int> temp = nums;
				temp.erase(unique(temp.begin(), temp.end() ), temp.end());
				for(size_t i=0; i<temp.size(); ++i)
				{
	    		if(temp[i] == succ)
					{
						if(i != temp.size()-1)
						{
							cout << "The In Order Successor of " << succ << " is " << temp[++i] << '\n';
							found = true;
						}
						else if(i == temp.size()-1)
						{
							cout << succ << " is the last element and has no successor\n";
							found = true;
						}
	        }
					else if(i == temp.size()-1 && found == false)
					{
						cout << succ << " is not found in the tree\n";
					}
	    	}
			}
			else
			{
				cout << "Empty Tree\n";
			}
			cout << '\n';
		}

		//Level Order
		else if(choice == "4")
		{
			if(!nums.empty())
			{
				cout << "Printing the Tree in Level Order\n";
				m_Tree -> levelOrder();
				cout << '\n';
			}
			else
			{
				cout << "Empty Tree\n";
			}
			cout << '\n';
		}

		//Spiral Level Order
		else if(choice == "5")
		{
			if(!nums.empty())
			{
				cout << "Printing the Tree in Spiral Level Order\n";
				m_Tree -> spiralTraversal(m_Tree -> getRoot());
				cout << '\n';
			}
			else
			{
				cout << "Empty Tree\n";
			}
			cout << '\n';
		}

		//Left Side View
		else if(choice == "6")
		{
			if(!nums.empty())
			{
				cout << "Printing Tree from Left Side View\n";
				m_Tree -> leftView(m_Tree -> getRoot());
			}
			else
			{
				cout << "Empty Tree\n";
			}
			cout << '\n';
			cout << '\n';
		}

		//Right Side View
		else if(choice == "7")
		{
			if(!nums.empty())
			{
				cout << "Printing Tree from Right Side View\n";
				m_Tree -> rightView(m_Tree -> getRoot());
			}
			else
			{
				cout << "Empty Tree\n";
			}
			cout << '\n';
			cout << '\n';
		}

		//Kth Smallest Item
		else if(choice == "8")
		{
			if(!nums.empty())
			{

				std::vector<int> temp;
				int size = nums.size();
    		for (int i = 0; i < size; i++)
				{
        	if (i > 0 && nums[i] == nums[i - 1])
					{
            continue;
					}
        	temp.push_back(nums[i]);
    		}
				bool good = false;
				int k = 0;
				while(!good)
				{
					cout << "Enter the value of K: ";;
					cin >> k;
					if(k <= 0)
					{
						cout << "Enter a value greater than 0\n";
					}
					else
					{
						good = true;
					}
				}
				size = temp.size();
				if(k <= size)
				{
					cout << "The " << k << "th smallest entry is: " << temp[k-1] << '\n';
				}
				else
				{
					cout << "K value out of range\n";
				}
			}
			else
			{
				cout << "Empty Tree\n";
			}
			cout << '\n';
		}

		//Exit
		else if(choice == "9")
		{
			cout << "Bye Bye!\n";
		}

		//Bad Input
		else
		{
			cout << "Please enter a number between 1 and 9.\n";
			cout << '\n';
		}
	}
}

Executive::~Executive()
{
	delete m_Tree;
}
