/*
 * @Author: Joseph Pennington
 * @File Name: Stack.h
 * @Assignment: EECS 268 Lab 03
 * @Date: 09/18/2018
 * @Brief: This program is the header file for the stack class. It has the destructor, isEmpty, push, pop, and peek frunctions
 */

#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include "StackInterface.h"
#include "PrecondViolatedExcep.h"
#include "ListInterface.h"
#include "LinkedList.h"

template <typename T>
class Stack : public StackInterface<T>
{
public:

  /*
  * @pre: None
  * @post: A Stack is made
  * @return: none
  */

 Stack();


  /*
  * @pre: Stack must be made
  * @post: Determines if stack is empty
  * @return: Return true if the stack is empty and false if not
  */

 bool isEmpty()const;

 /*
 * @pre: Stack must be made
 * @post: Entry is added to the top of the stack
 * @param newEntry: Entry that is being added to the stack
 * @throw PrecondViolatedExcep: Throw error if no memory is available
 * @return: none
 */

 void push(const T& newEntry) throw(PrecondViolatedExcep);


 /*
 * @pre: Stack is made and not empty
 * @post: Entry at the top of the stack is removed
 * @throw PrecondViolatedExcep: Throw error if the stack is empty
 * @return: none
 */

 void pop() throw(PrecondViolatedExcep);

 /*
 * @pre: Stack is made and not empty
 * @post: Entry at the top of the stacl is returned
 * @throw PrecondViolatedExcep: Throw error if the stack is empty
 * @return: Entry at the top of the stack as a T
 */

 T peek()const throw(PrecondViolatedExcep);

 /*
 * @pre: Stack is made
 * @post: Stack is deleted
 * @return: none
 */

 ~Stack();
private:
  ListInterface<T>* m_list;
};
#include "Stack.cpp"
#endif
