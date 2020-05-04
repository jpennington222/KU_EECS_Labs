/*
 * @Author: Joseph Pennington
 * @File Name: ListInterface.h
 * @Assignment: EECS 560 Lab 01
 * @Brief: This program is the template for the List Interface.
 */

#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H

template <typename T>
class ListInterface
{
	public:

		/*
		* @pre: A Linked List must have been created
		* @post: A Linked List is deleted from memory
		* @return: None
		*/

		virtual ~ListInterface(){}

		/*
		* @pre: A Linked List must have been created
		* @post: The length of the list is determined
		* @return: The length of the list is returned as an int
		*/

		virtual int getLength() const = 0;

		/*
		* @pre: A Linked List must have been created
		* @post: The entry is inserted into the list at the the front
		* @return: none
		* @param entry: A new entry to be added to the list
		* @return: none
		*/

		virtual void insert(T entry) = 0;

		/*
		* @pre: A Linked List must have been created
		* @post: One of the list entries is removed
		* @param numDelete: The entry to be deleted
		* @return: none
		*/

		virtual void remove(T numDelete) = 0;

		/*
		* @pre: A Linked List must have been created
		* @post: The list is printed
		* @return: none
		*/

		virtual void print() const = 0;

		/*
		* @pre: A Linked List must have been created
		* @post: The list is evaluated to be empty or not
		* @return: True if empty, otherwise false
		*/

		virtual bool isEmpty() = 0;

		/*
		* @pre: A Linked List must have been created
		* @post: The entry is found in the list
		* @param numFind: the entry to find in the list
		* @return: True if in numFind is in the list, otherwise false
		*/

		virtual bool find(T numFind) = 0;

		/*
		* @pre: A Linked List must have been created
		* @post: The next entry after the parameter is found in the list
		* @param numFindNext: the entry to find in the list and return the next element
		* @return: The next element after numFindNext if there is one
		*/

		virtual T findNext(T numFindNext) = 0;

		/*
		* @pre: A Linked List must have been created
		* @post: The item at the position is printed
		* @param position: the position in the list to print
		* @return: none
		*/

		virtual void printAt(int posiiton) = 0;

		/*
		* @pre: A Linked List must have been created
		* @post: The list is printed in reverse order
		* @return: none
		*/

		virtual void printReverse() = 0;

		/*
		* @pre: A Linked List must have been created
		* @post: The last occurence(s) of duplicate numbers are deleted
		* @return: none
		*/

		virtual void deleteDuplicates() = 0;
};

#endif
