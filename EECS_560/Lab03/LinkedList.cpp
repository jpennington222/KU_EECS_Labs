/*
 * @Author: Joseph Pennington
 * @File Name: LinkedList.cpp
 * @Assignment: EECS 560 Lab 03
 * @Brief: This program is the cpp file for the LinkedList class.
 */

#include <iostream>
#include "HashTableEntry.h"
using namespace std;

template <typename T>
LinkedList<T>::LinkedList()
{
	length = 0;
	m_front = nullptr;
}

template <typename T>
bool LinkedList<T>::isEmpty()
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
void LinkedList<T>::insert(T new_entry)
{
	if(m_front ==nullptr)
	{
    m_front = new Node<T>(new_entry);
  }
  else
	{
    Node<T>* temp = m_front;
    while(temp->getNext()!=nullptr)
		{
      temp=temp->getNext();
    }
    temp->setNext(new Node<T>(new_entry));
  }
  length++;
}

template <typename T>
void LinkedList<T>::remove(T numDelete)
{
	if(length == 0)
	{
		cout << "Empty list. Nothing to remove.\n";
		return;
	}
	int index = 0;
	Node<T>* tempFind = m_front;

	for(int i = 0; i<length; i++)
	{
		if(tempFind -> getValue().getName() == numDelete.getName() && tempFind -> getValue().getKey() == numDelete.getKey())
		{
			index = i;
		}
		tempFind = tempFind -> getNext();
	}

	index++;
	if((index >= 1) && (index <= length))
	{
		Node<T>* temp = m_front;
		if(index == 1)
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
				m_front = nullptr;
				length--;
			}
		}

		else
		{
			for(int i=0; i<(index-2); i++)
			{
				temp = temp -> getNext();
			}

			Node<T>* temp2 = temp -> getNext() -> getNext();
			delete temp -> getNext();
			temp -> setNext(temp2);
			length--;
		}
	}
}

template <typename T>
void LinkedList<T>::deleteDuplicates()
{
	if(length == 0 || length == 1)
	{
		cout << "The length of the list must be >= 2 to delete duplicates.\n";
		return;
	}

	Node<T>* temp1 = m_front;
	Node<T>* temp2 = m_front;

	while(temp1 != nullptr)
	{
		while(temp2 -> getNext()  != nullptr)
		{
			if(temp1 -> getValue() == temp2 -> getNext() -> getValue())
			{
				remove(temp2 -> getNext() -> getValue());
			}
			else
			{
				temp2 = temp2 -> getNext();
			}
		}
		temp1 = temp1 -> getNext();
		temp2 = temp1;
	}
	cout << "Duplicates Deleted.\n";
}

template <typename T>
bool LinkedList<T>::find(T numFind)
{
	if(length == 0)
	{
		cout << "Empty list. Nothing to find.\n";
		return(false);
	}
	Node<T>* temp = m_front;
	while(temp != nullptr)
	{
		if(temp -> getValue() == numFind)
		{
			return(true);
		}

		else
		{
			temp = temp -> getNext();
		}
	}
	cout << numFind << " is not found in the list.\n";
	return(false);
}

template <typename T>
T LinkedList<T>::findNext(T numFindNext)
{
	if(length == 0)
	{
		cout << "Empty list. Nothing to remove.\n";
		return(0);
	}
	Node<T>* temp = m_front;
	while(temp != nullptr)
	{
		if(temp -> getValue() == numFindNext)
		{
			if(temp -> getNext() != nullptr)
			{
				return(temp -> getNext() -> getValue());
			}
			else
			{
				return(0);
			}
		}

		else
		{
			temp = temp -> getNext();
		}
	}
	return(0);
}

template <typename T>
void LinkedList<T>::print()const
{
	Node<T>* temp = m_front;
	while(temp != nullptr)
	{

	}
}

template <typename T>
void LinkedList<T>::printReverse()
{
	if(length == 0)
	{
		cout << "Empty list. Nothing to print.\n";
		return;
	}
	cout << "Reversed list: ";
	Node<T>* temp = m_front;
	printRev(temp);
}

template <typename T>
void LinkedList<T>::printRev(Node<T>* temp)
{
	if(temp == nullptr)
	{
		return;
	}
	printRev(temp -> getNext());
	cout << temp -> getValue() << " ";
}

template <typename T>
void LinkedList<T>::printAt(int position)
{
	if(length == 0)
	{
		cout << "Empty list. Nothing to print.\n";
		return;
	}
	if(position > length || position < 0)
	{
		cout << "Position out of range.\n";
		return;
	}

	cout << "The element at position " << position << " is: ";
	Node<T>* temp = m_front;

	for(int i = 0; i<length; i++)
	{
		if(i == position -1)
		{
			cout << temp -> getValue();
		}
		else
		{
			temp = temp -> getNext();
		}
	}
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		deleteList(1);
	}

	length = 0;
	m_front = nullptr;
}

template <typename T>
void LinkedList<T>::deleteList(int position)
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
}

template <typename T>
T LinkedList<T>::getEntry(int position)
{
	Node<T>* temp = m_front;
	if((position>=0) && (position<=length))
	{
		for(int i=0; i<position; i++)
		{
			temp = temp -> getNext();
		}
	}
	return(temp -> getValue());
}
