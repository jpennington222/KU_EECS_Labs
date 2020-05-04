/*
 * @Author: Joseph Pennington
 * @File Name: Executive.h
 * @Assignment: EECS 560 Lab 05
 * @Brief: This program is the header file for the Exeuctive Class.
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <fstream>
#include <iostream>
#include "HashTable.h"

class Executive
{
	public:

		/*
		* @pre: none
		* @post: The file name is stored into the private member variable
		* @param url: A string represting the file name
		* @return: none
		*/

		Executive(int x);

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


		//HashTables
		HashTable<int>* m_HashTableLinear;
		HashTable<int>* m_HashTableQuadratic;

		HashTable<int>* m_HashTableLinear2;
		HashTable<int>* m_HashTableQuadratic2;

		HashTable<int>* m_HashTableLinear3;
		HashTable<int>* m_HashTableQuadratic3;

		HashTable<int>* m_HashTableLinear4;
		HashTable<int>* m_HashTableQuadratic4;

		HashTable<int>* m_HashTableLinear5;
		HashTable<int>* m_HashTableQuadratic5;
};
#endif
