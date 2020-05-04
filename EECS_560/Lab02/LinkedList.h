/*
 * @Author: Joseph Pennington
 * @File Name: LinkedList.h
 * @Assignment: EECS 560 Lab 02
 * @Brief: This program is the header file for the Linked List Class.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <fstream>
#include <iostream>

template <typename T>
class LinkedList
{
	public:

		/*
		* @pre: Program launched successfully
		* @post: A Linked List is created
		* @return: none
		*/

		LinkedList();

		/*
		* @pre: A Linked List must have been created
		* @post: The length of the list is determined
		* @return: The length of the list is returned as an int
		*/

		int getLength()const;

		/*
		* @pre: A Linked List must have been created
		* @post: The entry is inserted into the list at the the front
		* @param new_entry: A new entry to be added to the list
		* @return: none
		*/

		void insert(T new_entry);

		/*
		* @pre: A Linked List must have been created
		* @post: One of the list entries is removed
		* @param numDelete: The entry to be deleted
		* @return: none
		*/

		void remove(T numDelete);

		/*
		* @pre: A Linked List must have been created
		* @post: The list is printed
		* @return: none
		*/

		void print()const;

		/*
		* @pre: A Linked List must have been created
		* @post: A Linked List is deleted from memory
		* @return: None
		*/

		~LinkedList();

		/*
		* @pre: A Linked List must have been created
		* @post: The list is evaluated to be empty or not
		* @return: True if empty, otherwise false
		*/

		bool isEmpty();

		/*
		* @pre: A Linked List must have been created
		* @post: The entry is found in the list
		* @param numFind: the entry to find in the list
		* @return: True if in numFind is in the list, otherwise false
		*/

		bool find(T numFind);

		/*
		* @pre: A Linked List must have been created
		* @post: The next entry after the parameter is found in the list
		* @param numFindNext: the entry to find in the list and return the next element
		* @return: The next element after numFindNext if there is one
		*/

		T findNext(T numFindNext);

		/*
		* @pre: A Linked List must have been created
		* @post: The item at the position is printed
		* @param position: the position in the list to print
		* @return: none
		*/

		void printAt(int position);

		/*
		* @pre: A Linked List must have been created
		* @post: Deletes the Linked List to prevent leaks
		* @param position: the position in the list to delete
		* @return: none
		*/

		void deleteList(int position);

		/*
		* @pre: A Linked List must have been created
		* @post: The list is printed in reverse order
		* @return: none
		*/

		void printReverse();

		/*
		* @pre: A Linked List must have been created
		* @post: The function is called recursively to print the reversed list
		* @param temp: current node that will be printed
		* @return: none
		*/

		void printRev(Node<T>* temp);

		/*
		* @pre: A Linked List must have been created
		* @post: The last occurence(s) of duplicate entries are deleted
		* @return: none
		*/

		void deleteDuplicates();

		/*
		* @pre: A Linked List must have been created
		* @post: The entry at the posiiton is found
		* @param position: The index that the entry is at in the list
		* @return: The entry at that position in the list
		*/

		T getEntry(int position);
	private:

		//Length of the list
		int length;

		//Header Node
		Node<T>* m_front;
};
#include "LinkedList.cpp"
#endif
