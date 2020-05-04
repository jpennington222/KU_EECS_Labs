/*
 * @Author: Joseph Pennington
 * @File Name: DisjointSet.cpp
 * @Assignment: EECS 560 Lab 10
 * @Brief: This program is the cpp file for the DisjointSet Class.
 */

#include "DisjointSet.h"

DisjointSet::DisjointSet(int size)
{
  m_size = size;
  m_set = new BinaryNode<int>*[m_size];
  m_length = 0;
}

void DisjointSet::makeSet(int value)
{
  m_set[m_length] = new BinaryNode<int>(value);
  m_length++;
}

int DisjointSet::Union(int x, int y)
{
    BinaryNode<int>* xPtr = nullptr;
    BinaryNode<int>* yPtr = nullptr;

    for (int i = 0; i < m_length; i++)
    {
        if (m_set[i]->getItem()==x)
        {
            xPtr = m_set[i];
            break;
        }
    }
    for (int i = 0; i < m_length; i++)
    {
        if (m_set[i]->getItem()==y)
        {
            yPtr = m_set[i];
            break;
        }
    }

    xPtr = findSameRoot(xPtr);
    yPtr = findSameRoot(yPtr);

    if (xPtr != nullptr && yPtr != nullptr)
    {
        if (xPtr -> getRank() <= yPtr -> getRank())
        {
            xPtr -> setParentPtr(yPtr);

            if (xPtr -> getRank() == yPtr -> getRank())
            {
                yPtr -> setRank(yPtr -> getRank() + 1);
            }
            return(yPtr->getItem());
        }
        else
        {
            yPtr -> setParentPtr(xPtr);
            return(xPtr->getItem());

        }
    }
    return -1;
  }

BinaryNode<int>* DisjointSet::findSameRoot(BinaryNode<int>* subTreePtr)
{
  if(subTreePtr->getParentPtr() == nullptr)
  {
    return subTreePtr;
  }
  else
  {
    return (findSameRoot(subTreePtr->getParentPtr()));
  }
}

int DisjointSet::find(int x)
{
  BinaryNode<int>* xPtr = nullptr;

  for (int i = 0; i < m_length; i++)
  {
      if (m_set[i]->getItem()==x)
      {
          xPtr = m_set[i];
          break;
      }
  }
  if(xPtr == nullptr)
  {
    return -1;
  }
  return (findSameRoot(xPtr)->getItem());
}

void DisjointSet::pathCompression(int x)
{
  BinaryNode<int>* subTreePtr = nullptr;
  for (int i = 0; i < m_length; i++)
  {
      if (m_set[i] -> getItem()==x)
      {
          subTreePtr = findSameRoot(m_set[i]);
          if(subTreePtr -> getItem() == m_set[i] -> getItem())
          {

          }
          else
          {
            m_set[i] -> setParentPtr(subTreePtr);
          }
          break;
      }
  }

}

void DisjointSet::printPath(int x)
{
  std::cout << " " << x << " ->";
  BinaryNode<int>* xPtr = nullptr;

  for (int i = 0; i < m_length; i++)
  {
      if (m_set[i]->getItem()==x)
      {
          xPtr = m_set[i];
          break;
      }
  }

  if(xPtr->getParentPtr() == nullptr)
  {
    return;
  }
  else
  {
    printPath(xPtr->getParentPtr()->getItem());
  }
}

DisjointSet::~DisjointSet()
{
  for(int i=0; i<m_length; i++)
  {
    delete m_set[i]; //delete pointers in the array
  }
  delete[] m_set; //delete array
}
