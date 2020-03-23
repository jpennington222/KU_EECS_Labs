/*
 * @Author: Joseph Pennington
 * @File Name: LinkedList.cpp
 * @Assignment: EECS 268 Lab 03
 * @Date: 09/24/2018
 * @Brief: This program is the cpp file for the LinkedList class. It has the constructor, isEmpty, getLength, insert, remove, clear, getEntry, replace, and the destructor functions
 */

#include <stdexcept>

template <typename T>
LinkedList<T>::LinkedList()
{
	length = 0;
	m_front = nullptr;
}

template <typename T>
bool LinkedList<T>::isEmpty()const
{
	if(length == 0)
	{
		return(true);
	}

	else
	{
		return(false);
	}
}

template <typename T>
int LinkedList<T>::getLength()const
{
	return(length);
}

template <typename T>
void LinkedList<T>::insert(int position, T new_entry) throw(std::runtime_error)
{
	if(position < 1 || position > length+1)
	{
		throw std::runtime_error("Insert Error");
	}

	else
	{
		T entry = new_entry;
		Node<T>* newNode = new Node<T>(new_entry);

		if(position == 1)
		{
			newNode -> setNext(m_front);
			m_front = newNode;
		}

		else if(position == length+1)
		{
			Node<T>* temp = m_front;
			for(int i=0; i<length-1; i++)
			{
				temp = temp -> getNext();
			}
			temp -> setNext(newNode);
		}

		else
		{
			Node<T>* temp = m_front;
			for(int i=0; i<(position-2); i++)
			{
				temp = temp -> getNext();
			}

			Node<T>* temp2 = temp -> getNext() -> getNext();
			temp -> setNext(newNode);
			temp -> getNext() -> setNext(temp2);
		}

		length++;
	}
}

template <typename T>
void LinkedList<T>::remove(int position) throw(std::runtime_error)
{
	if((position >= 1) && (position <= length))
	{
		Node<T>* temp = m_front;
		if(position == 1)
		{
			if(length > 1)
			{
				m_front = m_front -> getNext();
				delete temp;
				length--;
			}
			else if(length == 1)
			{
				delete m_front;
				length--;
			}
		}

		else
		{
			for(int i=0; i<(position-2); i++)
			{
				temp = temp -> getNext();
			}

			Node<T>* temp2 = temp -> getNext() -> getNext();
			delete temp -> getNext();
			temp -> setNext(temp2);
			length--;
		}
	}

	else
	{
		throw std::runtime_error("Remove Error");
	}
}

template <typename T>
void LinkedList<T>::clear()
{
	while(!isEmpty())
	{
		remove(1);
	}
	length = 0;
	m_front = nullptr;
}

template <typename T>
T LinkedList<T>::getEntry(int position)const throw(std::runtime_error)
{
	if((position > 0) && (position <= length))
	{
		Node<T>* temp = m_front;
		for(int i=0; i<position-1; i++)
		{
			temp = temp -> getNext();
		}

		return (temp -> getValue());
	}

	else
	{
		throw std::runtime_error("Get Entry Error");
	}
}

template <typename T>
void LinkedList<T>::replace(int position, T new_entry) throw(std::runtime_error)
{
	if(isEmpty() || position >= length || position < 0)
	{
		throw std::runtime_error("Replace Error");
	}

	Node<T>* temp = m_front;
	for(int i=0; i<position-1; i++)
	{
		temp = temp -> getNext();
	}

	temp -> setValue(new_entry);
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		remove(1);
	}

	length = 0;
	m_front = nullptr;
}
