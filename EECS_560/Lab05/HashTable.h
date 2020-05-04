/*
 * @Author: Joseph Pennington
 * @File Name: HashTable.h
 * @Assignment: EECS 560 Lab 05
 * @Brief: This program is the header file for the HashTable Class
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <fstream>
#include <iostream>
#include "LinkedList.h"
using namespace std;

template <typename T>
class HashTable
{
  public:

    /*
		* @pre: Program ran
		* @post: HashTable of size size made
		* @param size: size of the HashTable array
		* @return: none
		*/

    HashTable(int size);

    /*
		* @pre: HashTable made
		* @post: The table and all entries are deleted from memory
		* @return: none
		*/

    ~HashTable();

    /*
		* @pre: A HashTable must have been created
		* @post: The entry is inserted into the table/linkedlist at the the back
		* @param x: A new entry to be added to the table/linked/list
		* @return: True if added, false if not added
		*/

    bool AddUserLinear(T x);

    /*
		* @pre: A HashTable must have been created
		* @post: The entry is inserted into the table/linkedlist at the the back
		* @param x: A new entry to be added to the table/linked/list
		* @return: True if added, false if not added
		*/

    bool AddUserQuadratic(T x);

    /*
    * @pre: A HashTable must have been created
    * @post: The entry is found in the table
    * @param x: Entry to find
    * @return: True if found, false if not found
    */

    bool findLinear(T x);

    /*
    * @pre: A HashTable must have been created
    * @post: The entry is found in the table
    * @param x: Entry to find
    * @return: True if found, false if not found
    */
    
    bool findQuadratic(T x);

  private:

    //size of the array
    int m_bucketCountLinear;
    int m_bucketCountQuadratic;

    //How many elements in the table (lambda)
    int m_elementsLinear;
    int m_elementsQuadratic;

    //Pointer to the linked list stored in the array
    LinkedList<T>* m_array;
};
#include "HashTable.cpp"
#endif
