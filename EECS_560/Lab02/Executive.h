/*
 * @Author: Joseph Pennington
 * @File Name: Executive.h
 * @Assignment: EECS 560 Lab 02
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
	private:

		//Filename
		std::string file;

		//HashTable
		HashTable<HashTableEntry>* m_HashTable;
};
#endif
