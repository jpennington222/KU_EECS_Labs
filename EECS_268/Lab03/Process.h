/*
 * @Author: Joseph Pennington
 * @File Name: Process.h
 * @Assignment: EECS 268 Lab 03
 * @Date: 09/24/2018
 * @Brief: This program is the Process.h file for the lab.
 */

#ifndef PROCESS_H
#define PROCESS_H
#include "StackInterface.h"
#include "Stack.h"
#include <string>

class Process
{
public:

  /*
  * @pre: none
  * @post: A Process is made
  * @param process: string that is stored in the Stack
  * @return: none
  */

  Process(std::string process);

  /*
  * @pre: Process must be made
  * @post: Process is deleted
  * @return: none
  */

  ~Process();

  /*
  * @pre: Process must be made and not empty
  * @post: A function is pushed onto the stack of a process
  * @param function: string that is pushed onto the stack
  * @return: none
  */

  void Call(std::string function);

  /*
  * @pre: Process must be made and not empty
  * @post: Prints what process is at the top of the stack and pops it
  * @return: none
  */

  void Return();

  /*
  * @pre: Process must be made and not empty
  * @post: If the stack is empty, return true
  * @return: True if the stack is empty and false if it is not
  */

  bool checkReturn();

  /*
  * @pre: Process must be made and not empty
  * @post: A copy of the procecss is made
  * @param original: Process that is being copied
  * @return: none
  */

  Process(const Process& original);

  /*
  * @pre: Process must be made and not empty
  * @post: Defines "="
  * @param Process: What is being copied
  * @return: none
  */

  void operator=(const Process& rhs);
private:
  std::string name;
  StackInterface<std::string*>* stringstack;
  std::string* stringptr1;
  std::string* stringptr2;
};
#endif
