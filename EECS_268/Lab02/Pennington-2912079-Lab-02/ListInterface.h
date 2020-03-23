/*                                                                              
 * @Author: Joseph Pennington                                            
 * @File Name: ListInterface.h                                                  
 * @Assignment: EECS 268 Lab 02
 * @Date: 09/17/2018                                        
 * @Brief: This program is the template for the List Interface. It declares the destructor, getLength, insert, remove, clear, getEntry, and replace functions
 */

#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H
#include <stdexcept>

template <typename T>
class ListInterface
{
	public:
		virtual ~ListInterface(){}

		/*
		* @pre: A Linked List must have been created
		* @post: A Linked List is deleted from memory
		* @return: None
		*/

		virtual int getLength() const = 0;

		/*
		* @pre: A Linked List must have been created with at least one entry
		* @post: The length of the list is determined
		* @return: The length of the list is returned as an int
		*/

		virtual void insert(int position, T entry) throw(std::runtime_error) = 0;

		/*
		* @pre: A Linked List must have been created and the position must be valid
		* @post: The entry is inserted into the list at the given position
		* @return: none
		* @param position: 1 <= position <= length
		* @param entry: A new entry to be added to the list
		* @throw std::runtime_error if the position is not valid
		* @return: none
		*/

		virtual void remove(int position) throw(std::runtime_error) = 0;

		/*
		* @pre: A Linked List must have been created and the position must be valid
		* @post: One of the list entries is removed at the given position
		* @param position: 1 <= position <= length
		* @throw std::runtime_error if the position is invalid
		* @return: none
		*/

		virtual void clear() = 0;

		/*
		* @pre: A Linked List must have been created and not empty
		* @post: The list is cleared of all entries
		* @return: none
		*/

		virtual T getEntry(int position) const throw(std::runtime_error) = 0;

		/*
		* @pre: A Linked List must have been created and the position must be valid
		* @post: The entry at the given position is found
		* @param position: 1 <= position <= length
		* @throw std::runtime_error if the position is invalid
		* @return: The entry at the position is returned as a type T
		*/

		virtual void replace(int position, T newEntry) throw (std::runtime_error) = 0;

		/*
		* @pre: A Linked List must have been created with at least one entry and the position must be valid
		* @post: The new entry replaces the entry at the given position
		* @param position: 1 <= length <= position
		* @param newEntry: The new entry that will replace the current entry
		* @throw std::runtime_error if the position is invalid
		* @return: none
		*/
};

#endif
