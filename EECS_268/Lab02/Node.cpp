/*                                                                              
 * @Author: Joseph Pennington
 * @File Name: Node.cpp
 * @Assignment: EECS 268 Lab 02
 * @Date: 09/17/2018
 * @Brief: This program is the cpp for the Node class. It contains the constructor, getValue, getNext, setValue, and setNext functions to make a Node.
 */

template<typename T>
Node<T>::Node(T& value)
{
	m_value = value;
	m_next = nullptr;
}

template<typename T>
T Node<T>::getValue()const
{
	return(m_value);
}

template<typename T>
Node<T>* Node<T>::getNext()const
{
	return(m_next);
}

template<typename T>
void Node<T>::setValue(T& value)
{
	m_value = value;
}

template<typename T>
void Node<T>::setNext(Node<T>* next)
{
	m_next = next;
}
