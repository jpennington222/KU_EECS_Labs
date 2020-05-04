/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 560 Lab 03
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
using namespace std;

Executive::Executive(std::string Filename)
{
	m_HashTableLinear = new HashTable<HashTableEntry>(11);
	m_HashTableQuadratic = new HashTable<HashTableEntry>(11);\

	string temp;
	string tempUser;
	string tempPassword;
	int tempKey = 0;

	file = Filename;
	ifstream inFile;
	inFile.open(file);
	int swap = 1;
	while(inFile >> temp)
	{
		if(swap % 2 == 1)
		{
			temp.pop_back();
			tempUser = temp;
			swap++;
		}
		else
		{
			tempPassword = temp;
			tempKey = castStringToInt(tempPassword);
			HashTableEntry hte(tempUser, tempPassword, tempKey);
			swap++;
			tempKey = 0;
			tempUser = "";
			tempPassword = "";
			// cout << hte.getName() << '\n';
			// cout << hte.getPassword() << '\n';
			// cout << hte.getKey() << '\n';
			if(m_HashTableLinear -> isDuplicateLinear(hte) == false)
			{
				m_HashTableLinear -> AddUserLinear(hte);
			}

			if(m_HashTableQuadratic -> isDuplicateQuadratic(hte) == false)
			{
				m_HashTableQuadratic -> AddUserQuadratic(hte);
			}
		}


	}
	inFile.close();
}

void Executive::run()
{
	string choice = "0";
	while(choice != "6")
	{
		cout << "Choose one operation from the options below:\n";
		cout << "1- Add User\n";
		cout << "2- Remove User\n";
		cout << "3- Forgot Password\n";
		cout << "4- Forgot Username\n";
		cout << "5- Print Users\n";
		cout << "6- Exit\n";
		cin >> choice;
		cout << '\n';

		//Add User
		if(choice == "1")
		{

			cout << "Enter user details to be added:\n";
			string tempUser;
			string tempPassword;
			int tempKey = 0;
			tempUser = checkUsername();
			tempPassword = checkPassword();

			cout << '\n';

			tempKey = castStringToInt(tempPassword);
			HashTableEntry hte(tempUser, tempPassword, tempKey);
			if(m_HashTableLinear -> isDuplicateLinear(hte) == false)
			{
				if(m_HashTableLinear -> AddUserLinear(hte))
				{
					cout << "Linear Probing:\n";
					cout << "Record successfully inserted\n";
				}
				else
				{
					cout << "Linear Probing:\n";
					cout << "Record not inserted\n";
				}
			}

			cout << '\n';
			if(m_HashTableQuadratic -> isDuplicateQuadratic(hte) == false)
			{
				if(m_HashTableQuadratic -> AddUserQuadratic(hte))
				{
					cout << "Quadratic Probing:\n";
					cout << "Record successfully inserted\n";
				}
				else
				{
					cout << "Quadratic Probing:\n";
					cout << "Record not inserted\n";
				}
			}
			cout << '\n';
		}

		//Remove User
		else if(choice == "2")
		{
			cout << "Enter user and password to be removed:\n";
			string tempUser;
			string tempPassword;
			int tempKey = 0;
			tempUser = checkUsername();
			tempPassword = checkPassword();

			cout << '\n';
			tempKey = castStringToInt(tempPassword);
			HashTableEntry hte(tempUser, tempPassword, tempKey);

			if(m_HashTableLinear -> RemoveUserLinear(hte))
			{
				cout << "Linear Probing:\n";
				cout << "Record successfully removed\n";
			}
			else
			{
				cout << "Linear Probing:\n";
				cout << "Record not removed. Entry not found\n";
			}

			cout << '\n';
			if(m_HashTableQuadratic -> RemoveUserQuadratic(hte))
			{
				cout << "Quadratic Probing:\n";
				cout << "Record successfully removed\n";
			}
			else
			{
				cout << "Quadratic Probing:\n";
				cout << "Record not removed. Entry not found\n";
			}
			cout << '\n';
		}

		//Forgot Password
		else if(choice == "3")
		{
			string username;
			username = checkUsername();
			cout << '\n';
			m_HashTableLinear -> forgotPasswordLinear(username);
			cout << '\n';
			m_HashTableQuadratic -> forgotPasswordQuadratic(username);
			cout << '\n';
		}

		//Forgot Username
		else if(choice == "4")
		{
			string password;
			password = checkPassword();
			cout << '\n';
			m_HashTableLinear -> forgotUsernameLinear(password);
			cout << '\n';
			m_HashTableQuadratic -> forgotUsernameQuadratic(password);
			cout << '\n';
		}

		//Print Users
		else if(choice == "5")
		{
			cout << "Linear Probing:\n";
			m_HashTableLinear -> PrintUsersLinear();
			cout << '\n';
			cout << "Quadratic Probing:\n";
			m_HashTableQuadratic -> PrintUsersQuadratic();
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
			cout << "Please enter a number between 1 and 7.\n";
			cout << '\n';
		}
	}
}

Executive::~Executive()
{
	delete m_HashTableLinear;
	delete m_HashTableQuadratic;
}

int Executive::castStringToInt(std::string password)
{
	int castValue = 0;
	int length = password.length();
	for(int i=0; i<length; i++)
	{
		if(password[i] == '0')
		{
			castValue = castValue + 0;
		}

		else if(password[i] == '1')
		{
			castValue = castValue + 1;
		}
		else if(password[i] == '2')
		{
			castValue = castValue + 2;
		}
		else if(password[i] == '3')
		{
			castValue = castValue + 3;
		}
		else if(password[i] == '4')
		{
			castValue = castValue + 4;
		}
		else if(password[i] == '5')
		{
			castValue = castValue + 5;
		}
		else if(password[i] == '6')
		{
			castValue = castValue + 6;
		}
		else if(password[i] == '7')
		{
			castValue = castValue + 7;
		}
		else if(password[i] == '8')
		{
			castValue = castValue + 8;
		}
		else if(password[i] == '9')
		{
			castValue = castValue + 9;
		}
		else
		{
			castValue = castValue + (int)password[i];
		}
	}
	return(castValue);
}

string Executive::checkUsername()
{
	string tempUser;
	int length = 0;
	bool goodInput = false;

	while(goodInput == false)
	{
		length = 0;
		cout << "Enter username: ";
		cin >> tempUser;
		length = tempUser.length();
		if(length >= 1 && length <= 6)
		{
			for(int i=0; length; i++)
			{
				if((int)tempUser[i] >= 97 && (int)tempUser[i] <= 122)
				{
					if(i == length-1)
					{
						return(tempUser);
					}
				}
				else
				{
					cout << "Invalid Username. Only lowercase letters allowed\n";
					break;
				}
			}
		}
		else
		{
			cout << "Invalid length of Username. Length needs to be between 1-6\n";
		}
	}
	return("0");
}

string Executive::checkPassword()
{
	string tempPassword;
	int nums = 0;
	int letters = 0;
	int length = 0;
	bool goodInput = false;

	while(goodInput == false)
	{
		length = 0;
		letters = 0;
		nums = 0;
		cout << "Enter user password: ";
		cin >> tempPassword;
		length = tempPassword.length();
		if(length >= 5 && length <= 7)
		{
			for(int i=0; i<length; i++)
			{

				if((int)tempPassword[i] >= 48 && (int)tempPassword[i] <= 57)
				{
					nums++;
				}

				else if((int)tempPassword[i] >= 97 && (int)tempPassword[i] <= 122)
				{
					letters++;
				}

				else if((int)tempPassword[i] <= 48 || (int)tempPassword[i] >= 57)
				{
					cout << "Invalid Password. At least 2 numbers and 3 lowercase letters allowed\n";
					break;
				}

				else if((int)tempPassword[i] <= 97 || (int)tempPassword[i] >= 122)
				{
					cout << "Invalid Password. At least 2 numbers and 3 lowercase letters allowed\n";
					break;
				}

				if(i == length-1 && (letters < 3 || nums < 2))
				{
					cout << "Invalid Password. At least 2 numbers and 3 lowercase letters allowed\n";
					break;
				}

				if(i == length-1 && letters >= 3 && nums >= 2)
				{
					return(tempPassword);
				}
			}
		}
		else
		{
			cout << "Invalid length of Password. Length needs to be between 5-7\n";
		}
	}
	return("0");
}
