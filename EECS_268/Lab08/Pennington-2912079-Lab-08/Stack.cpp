/*
 * @Author: Joseph Pennington
 * @File Name: Stack.cpp
 * @Assignment: EECS 268 Lab 08
 * @Date: 11/13/2018
 * @Brief: This program is the cpp file for the stack class. It has the destructor, isEmpty, push, pop, and peek frunctions
 */

#include "PrecondViolatedExcep.h"
#include "Node.h"
//#include "Queue.h"
//#include "QueueInterface.h"
#include "Stack.h"
#include "StackInterface.h"
#include "ListInterface.h"
#include "LinkedList.h"
#include <string>

template <typename T>
Stack<T>::Stack()
{
  m_list = new LinkedList<T>;
}

template <typename T>
bool Stack<T>::isEmpty()const
{
  return(m_list -> isEmpty());
}

template <typename T>
void Stack<T>::push(const T& newEntry) throw(PrecondViolatedExcep)
{
  T pushEntry = newEntry;
  try
  {
    m_list -> insert(1, pushEntry);
  }
  catch(PrecondViolatedExcep error)
  {
    throw PrecondViolatedExcep("Push Error\n");
  }
}

template<typename T>
void Stack<T>::pop() throw(PrecondViolatedExcep)
{
  try
  {
    m_list -> remove(1);
  }

  catch (PrecondViolatedExcep error)
  {
    throw PrecondViolatedExcep("Pop Error\n");
  }
}

template<typename T>
T Stack<T>::peek()const throw(PrecondViolatedExcep)
{
  if(m_list -> isEmpty())
  {
    throw PrecondViolatedExcep("Peek Error\n");
  }

  else
  {
    return(m_list -> getEntry(1));
  }
}

template<typename T>
Stack<T>::~Stack()
{
  delete m_list;
}
