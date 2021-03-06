/*
 * @Author: Joseph Pennington
 * @File Name: Node.h
 * @Assignment: EECS 560 Lab01
 * @Brief: This program is the h file for the Node class
 */

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
	public:

		/*
		* @pre: none
		* @post: A node is made
		* @param value: Value that is stored in the Node
		* @return: none
		*/

		Node(T& value);

		/*
		* @pre: A Node must be created and filled
		* @post: The value of the Node is found
		* @return: The value of the Node as T
		*/

		T getValue()const;

		/*
		* @pre: A Node must be created and filled
		* @post: The pointer to the next Node is found
		* @return: The pointer to the next Node
		*/

		Node<T>* getNext()const;

		/*
		* @pre: A Node must be created and filled
		* @post: The value of the Node is set
		* @param value: Value that is stored in the Node
		* @return: none
		*/

		void setValue(T& value);

		/*
		* @pre: A Node must be created and filled
		* @post: The pointer to the next Node is set
		* @param next: Pointer that is stored in the Node
		* @return: none
		*/

		void setNext(Node<T>* next);
	private:

		//Next Node
		Node<T>* m_next;

		//The Node's value
		T m_value;
};
#include "Node.cpp"
#endif
