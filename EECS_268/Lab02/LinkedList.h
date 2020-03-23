/*                                                                              
 * @Author: Joseph Pennington
 * @File Name: LinkedList.h 
 * @Assignment: EECS 268 Lab 02
 * @Date: 09/17/2018
 * @Brief: This program is the header file for the Linked List Class.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ListInterface.h"
#include "Node.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList : public ListInterface<T>
{
	public:
		LinkedList();

		/*
		* @pre: none
		* @post: A LinkedList is made
		* @return: none
		*/

		bool isEmpty()const;

		/*
		* @pre: A LinkedList must be made
		* @post: The function checks to see if the list is empty
		* @return: True if emtpy and false if not empty
		*/

		int getLength()const;

		/*
		* @pre: A LinkedList must be made
		* @post: The function gets the length of the list
		* @return: An int of the length of the list
		*/

		void insert(int position, T new_entry) throw(std::runtime_error);

		/*
		* @pre: A LinkedList must be made and filled and the position is between 1 and the length
		* @post: The browser inserts a new entry
		* @param position: 1<= position <= length
		* @param new_entry: A new entry to be put in the list
		* @throw std::runtime_error if the position is invalid
		* @return: none
		*/

		void remove(int position) throw(std::runtime_error);
	
		/*
		* @pre: A LinkedList must be made and filled and the position is between 1 and the length
		* @post: The browser removes an entry
		* @param position: 1<= position <= length
		* @throw std::runtime_error if the position is invalid
		* @return: none
		*/
		
		void clear();

		/*
		* @pre: A LinkedList must be made
		* @post: The browser deletes the contents of the list
		* @return: none
		*/

		T getEntry(int position)const throw(std::runtime_error);

		/*
		* @pre: A LinkedList must be made and filled and the position is between 1 and the length
		* @post: The function gets the entry at a position
		* @param position: 1<= position <= length
		* @throw std::runtime_error if the position is invalid
		* @return: A T of the entry at the position
		*/

		void replace(int position, T new_entry) throw(std::runtime_error);

		/*
		* @pre The position is between 1 and the list's length
    		* @post The entry at the given position is replaced with the new entry
     		* @param position:  1<= position <= length
     		* @param newEntry: A new entry to put in the list
     		* @throw std::runtime_error if the position is invalid.
		*/
		~LinkedList();

		/*
		* @pre: LinkedList must be made
		* @post: LinkedList is deleted
		* @return: none
		*/
	private:
		int length;
		Node<T>* m_front;
};
#include "LinkedList.cpp"
#endif
