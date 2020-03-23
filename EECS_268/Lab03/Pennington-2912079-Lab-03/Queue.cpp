/*
 * @Author: Joseph Pennington
 * @File Name: Queue.cpp
 * @Assignment: EECS 268 Lab 03
 * @Date: 09/24/2018
 * @Brief: This program is cpp file for the Queue Class. It declares the destructor, isEmpty, enqueue, dequeue, and peekfront functions
 */

 #include "PrecondViolatedExcep.h"
 #include "Node.h"
 #include "Queue.h"
 #include "QueueInterface.h"
 #include "Stack.h"
 #include "StackInterface.h"
 #include <string>

template <typename T>
Queue<T>::Queue()
{
  m_list = new LinkedList<T>;
  length = 0;
}

template <typename T>
bool Queue<T>::isEmpty()const
{
  return(length == 0);
}

template<typename T>
void Queue<T>::enqueue(const T& newEntry) throw(PrecondViolatedExcep)
{
  T enqueueEntry = newEntry;
  try
  {
    m_list -> insert(length+1, enqueueEntry);
    length++;
  }

  catch(PrecondViolatedExcep error)
  {
    throw PrecondViolatedExcep("Enqueue Error\n");
  }
}

template<typename T>
void Queue<T>::dequeue() throw(PrecondViolatedExcep)
{
  try
  {
    m_list -> remove(1);
    length--;
  }

  catch (PrecondViolatedExcep error)
  {
    throw PrecondViolatedExcep("Dequeue Error\n");
  }
}

template<typename T>
T Queue<T>::peekFront()const throw(PrecondViolatedExcep)
{
  try
  {
    return(m_list -> getEntry(1));
  }

  catch(PrecondViolatedExcep error)
  {
    throw PrecondViolatedExcep("Peek Queue Error\n");
  }
}

template<typename T>
Queue<T>::~Queue()
{
  delete m_list;
}
