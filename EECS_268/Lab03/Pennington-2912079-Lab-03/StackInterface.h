/*
 * @Author: Joseph Pennington
 * @File Name: StackInterface.h
 * @Assignment: EECS 268 Lab 03
 * @Date: 09/18/2018
 * @Brief: This program is the template for the StackInterface. It declares the destructor, isEmpty, push, pop, and peek functions
 */

 #ifndef _STACK_INTERFACE
 #define _STACK_INTERFACE

 #include "PrecondViolatedExcep.h"

 template <typename T>
 class StackInterface
 {
 public:
   virtual ~StackInterface() {}
   virtual bool isEmpty() const = 0;
   virtual void push(const T& newEntry) = 0;
   virtual void pop() throw(PrecondViolatedExcep) = 0;
   virtual T peek() const throw(PrecondViolatedExcep) = 0;
 };
 #endif
