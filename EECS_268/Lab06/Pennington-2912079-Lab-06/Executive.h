/*
 * @Author: Joseph Pennington
 * @File Name: main.cpp
 * @Assignment: EECS 268 Lab 06
 * @Date: 10/16/2018
 * @Brief: This program is the header file for the Executive class
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Grammar.h"
#include <string>
using namespace std;

class Executive
{
public:

  /*
  * @pre: none
  * @post: The input file strings are stored and other functions are called
  * @param questionF: Question file
  * @param answerF: Answer file
  * @return: none
  */

  Executive(string questionF, string answerF);

  /*
  * @pre: Executive object made
  * @post: Grammars are created and the results are printed to the screen
  * @return: none
  */

  void run();

  /*
  * @pre: Executive object made
  * @post: Executive object deleted
  * @return: none
  */

  ~Executive();
private:
  string QF;
  string AF;
};
#endif
