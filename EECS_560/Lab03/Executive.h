/*
 * @Author: Joseph Pennington
 * @File Name: Executive.h
 * @Assignment: EECS 560 Lab 03
 * @Brief: This program is the header file for the Exeuctive Class.
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <fstream>
#include <iostream>
#include "HashTable.h"
#include "HashTableEntry.h"

class Executive
{
	public:

		/*
		* @pre: none
		* @post: The file name is stored into the private member variable
		* @param url: A string represting the file name
		* @return: none
		*/

		Executive(std::string Filename);

		/*
		* @pre: The file name must have been saved
		* @post: Handles all function calls depending on file contents
		* @return: none
		*/

		void run();

		/*
		* @pre: HashTable made
		* @post: Deletes the HashTable object
		* @return: none
		*/

		~Executive();

		/*
		* @pre: New entry is being added
		* @post: The password is casted to an int for the key
		* @param password: password to be casted
		* @return: the int value
		*/

		int castStringToInt(std::string password);

		/*
		* @pre: New entry is being added
		* @post: Saves valid username (see README)
		* @return: username
		*/

		std::string checkUsername();

		/*
		* @pre: New entry is being added
		* @post: Saves valid password (see README)
		* @return: password
		*/

		std::string checkPassword();

	private:

		//Filename
		std::string file;

		//HashTables
		HashTable<HashTableEntry>* m_HashTableLinear;
		HashTable<HashTableEntry>* m_HashTableQuadratic;
};
#endif
