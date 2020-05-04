/*
 * @Author: Joseph Pennington
 * @File Name: HashTable.h
 * @Assignment: EECS 560 Lab 03
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
		* @post: The entry is removed from the table/linkedlist
		* @param x: An entry to be removed to the table/linked/list
		* @return: True if removed, false if entry not found
		*/

    bool RemoveUserLinear(T x);

    /*
		* @pre: A HashTable must have been created
		* @post: The entry is removed from the table/linkedlist
		* @param x: An entry to be removed to the table/linked/list
		* @return: True if removed, false if entry not found
		*/

    bool RemoveUserQuadratic(T x);

    /*
		* @pre: HashTable made
		* @post: The table and all entries are printed
		* @return: none
		*/

    void PrintUsersLinear();

    /*
		* @pre: HashTable made
		* @post: The table and all entries are printed
		* @return: none
		*/

    void PrintUsersQuadratic();

    /*
		* @pre: A HashTable must have been created
		* @post: The index is determined
		* @param castValue: The key from the entry
    * @param bucketsize: how many buckets in the array
		* @return: The index the entry is found in
		*/

    int Hashfunction(int castValue, int bucketsize);

    /*
		* @pre: A HashTable must have been created
		* @post: Load factor is determined
		* @param elements: How many elements are in the table
    * @param bucket: Size of the array
		* @return: Load factor
		*/

    double loadFactor(int elements, int buckets);

    /*
		* @pre: A HashTable must have been created
		* @post: Determines if entry is duplicate
		* @param x: An entry to be test
		* @return: True if duplicate, false if not
		*/

    bool isDuplicateLinear(T x);

    /*
    * @pre: A HashTable must have been created
    * @post: Determines if entry is duplicate
    * @param x: An entry to be test
    * @return: True if duplicate, false if not
    */

    bool isDuplicateQuadratic(T x);

    /*
		* @pre: HashTable made
		* @post: The next largest prime number >2m is found
		* @return: The prime number
		*/

    int nextPrimeLinear();

    /*
		* @pre: HashTable made
		* @post: The next largest prime number >2m is found
		* @return: The prime number
		*/

    int nextPrimeQuadratic();

    /*
		* @pre: HashTable made
		* @post: Tests if number is a prime number
    * @param test: The number to test
		* @return: True if prime, otherwise false
		*/

    bool isPrime(int test);

    /*
		* @pre: HashTable made
		* @post: The table is rehashed
		* @return: none
		*/

    void rehashLinear();

    /*
		* @pre: HashTable made
		* @post: The table is rehashed
		* @return: none
		*/

    void rehashQuadratic();

    /*
		* @pre: HashTable made
		* @post: Finds password based on username
    * @param username: Key to find record
		* @return: none
		*/

    void forgotPasswordLinear(string username);

    /*
		* @pre: HashTable made
		* @post: Finds password based on username
    * @param username: Key to find record
		* @return: none
		*/

    void forgotPasswordQuadratic(string username);

    /*
		* @pre: HashTable made
		* @post: Finds username based on username
    * @param password: Key to find record
		* @return: none
		*/

    void forgotUsernameLinear(string password);

    /*
		* @pre: HashTable made
		* @post: Finds username based on username
    * @param password: Key to find record
		* @return: none
		*/

    void forgotUsernameQuadratic(string password);

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
