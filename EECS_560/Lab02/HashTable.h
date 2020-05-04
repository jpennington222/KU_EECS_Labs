/*
 * @Author: Joseph Pennington
 * @File Name: HashTable.h
 * @Assignment: EECS 560 Lab 02
 * @Brief: This program is the header file for the HashTable Class
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <fstream>
#include <iostream>
#include "LinkedList.h"
#include "HashTableEntry.h"
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
		* @return: True if added, false if duplicate entry
		*/

    bool AddPlayer(T x);

    /*
		* @pre: A HashTable must have been created
		* @post: The entry is removed from the table/linkedlist
		* @param x: An entry to be removed to the table/linked/list
		* @return: True if removed, false if entry not found
		*/

    bool RemovePlayer(T x);

    /*
		* @pre: HashTable made
		* @post: The table and all entries are printed
		* @return: none
		*/

    void PrintPlayerList();

    /*
		* @pre: A HashTable must have been created
		* @post: The index is determined
		* @param goalcount: The key from the entry
    * @param bucketsize: how many buckets in the array
		* @return: The index the entry is found in
		*/

    int Hashfunction(int goalcount, int bucketsize);

    /*
		* @pre: A HashTable must have been created
		* @post: The players with goals equal to the score is printed
		* @param g: Score to be comapred to
		* @return: none
		*/

    void PlayerWithGoalCountEqualTo(int g);

    /*
		* @pre: A HashTable must have been created
		* @post: The players with goals greater than the score is printed
		* @param h: Score to be comapred to
		* @return: none
		*/

    void PlayerWithNumGoalsGreaterThan(int h);

    /*
		* @pre: A HashTable must have been created
		* @post: The players with goals less than the score is printed
		* @param i: Score to be comapred to
		* @return: none
		*/

    void PlayerWithNumGoalsLessThan(int i);

  private:

    //size of the array
    int m_bucketCount;

    //How many elements in the table (lambda)
    int m_elements;

    //Pointer to the linked list stored in the array
    LinkedList<T>* m_array;
};
#include "HashTable.cpp"
#endif
