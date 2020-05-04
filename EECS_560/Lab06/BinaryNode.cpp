/*
 * @Author: Joseph Pennington
 * @File Name: BinaryNode.cpp
 * @Assignment: EECS 560 Lab 06
 * @Brief: This is the BinaryNode cpp file
 */

template<typename T>
BinaryNode<T>::BinaryNode()
{
  m_entry;
  m_right = nullptr;
  m_left = nullptr;
}

template<typename T>
BinaryNode<T>::BinaryNode(T entry)
{
  m_entry = entry;
  m_right = nullptr;
  m_left = nullptr;
}

template<typename T>
BinaryNode<T>* BinaryNode<T>::getLeft() const
{
  return(m_left);
}

template<typename T>
BinaryNode<T>* BinaryNode<T>::getRight() const
{
  return(m_right);
}

template<typename T>
void BinaryNode<T>::setLeft(BinaryNode<T>* entryPointer)
{
  m_left = entryPointer;
}

template<typename T>
void BinaryNode<T>::setRight(BinaryNode<T>* entryPointer)
{
  m_right = entryPointer;
}

template<typename T>
T BinaryNode<T>::getEntry()const
{
  return(m_entry);
}

template<typename T>
void BinaryNode<T>::setEntry(T newEntry)
{
  m_entry = newEntry;
}
