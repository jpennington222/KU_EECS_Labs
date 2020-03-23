/*                                                                              
 * @Author: Joseph Pennington
 * @File Name: Node.h
 * @Assignment: EECS 268 Lab 02
 * @Date: 09/17/2018
 * @Brief: This program is the h file for the Node class
 */

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
	public:
		Node(T& value);

		/*
		* @pre: none
		* @post: A node is made
		* @param value: Value that is stored in the Node
		* @return: none
		*/

		T getValue()const;

		/*
		* @pre: A Node must be created and filled
		* @post: The value of the Node is found
		* @return: The value of the Node as T
		*/

		Node<T>* getNext()const;
	
		/*
		* @pre: A Node must be created and filled
		* @post: The pointer to the next Node is found
		* @return: The pointer to the next Node
		*/
		
		void setValue(T& value);

		/*
		* @pre: A Node must be created and filled
		* @post: The value of the Node is set
		* @param value: Value that is stored in the Node
		* @return: none
		*/

		void setNext(Node<T>* next);

		/*
		* @pre: A Node must be created and filled
		* @post: The pointer to the next Node is set
		* @param value: Pointer that is stored in the Node
		* @return: none
		*/
		
	private:
		Node<T>* m_next;
		T m_value;
};
#include "Node.cpp"
#endif
