/*
 * @Author: Joseph Pennington
 * @File Name: Executive.h
 * @Assignment: EECS 268 Lab 09
 * @Date: 12/04/2018
 * @Brief: This is the Executive header file
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <fstream>
#include <iostream>
#include "BinarySearchTree.h"
#include "Task.h"
using namespace std;

class Executive
{
public:

  /*
   * @pre: none
   * @post: file name is saved
   * @param file: file name
   * @return: none
   */

  Executive(string file);

  /* @pre: tree created
   * @post: all entries are flushed
   * @param ID: task object
   * @return: none
   */

   static void visit(Task& ID);

  /*
   * @pre: tree created
   * @post: deletes tree
   * @return: none
   */

  ~Executive();

  /*
   * @pre: tree created
   * @post: parses file and handles other functions
   * @return: none
   */

  void run();

  /*
   * @pre: tree created
   * @post: finishes tasks
   * @return: none
   */

  void finish(int tempID);

  /*
   * @pre: tree created
   * @post: starts tasks
   * @return: none
   */

  void start(int tempID);

  /*
   * @pre: tree created
   * @post: starts and finishes all tasks in the tree
   * @return: none
   */

  void flush();

  /*
   * @pre: none
   * @post: saves static object
   * @return: none
   */

  Executive();

private:
  string m_file;
  int m_time;
  BinarySearchTree<int, Task>* tree;
  int nodes;
  static Executive *theExec;
};
#endif
