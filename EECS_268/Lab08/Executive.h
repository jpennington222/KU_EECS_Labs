/*
 * @Author: Joseph Pennington
 * @File Name: Executive.h
 * @Assignment: EECS 268 Lab 08
 * @Date: 11/13/2018
 * @Brief: This is the Executive header file
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <fstream>
#include "BinaryNodeTree.h"
#include "Stack.h"
using namespace std;

class Executive
{
public:

  /*
   * @pre: none
   * @post: variables are saved and the trees are made
   * @param order: prefix or postfix
   * @param file: file namespace
   * @return: none
   */

  Executive(string order, string file);

  /*
   * @pre: tree created
   * @post: Passes tree to the print function
   * @return: none
   */

  void run();

  /*
   * @pre: tree created
   * @post: contents of tree printed in pre order
   * @param bt: binary treePtr
   * @return: none
   */

  void printTreePreorder(BinaryNodeTree<string>* bt);

  /*
   * @pre: tree created
   * @post: contents of tree printed in in order
   * @param bt: binary treePtr
   * @return: none
   */

  void printTreeInorder(BinaryNodeTree<string>* bt);

  /*
   * @pre: tree created
   * @post: contents of tree printed in post order
   * @param bt: binary treePtr
   * @return: none
   */

  void printTreePostorder(BinaryNodeTree<string>* bt);

  /* @pre: tree created
   * @post: prints content of tree
   * @param str: string of tree contents
   * @return: none
   */

  static void visit(string& str);

  /*
   * @pre: recursive function to build prefix tree
   * @post: tree created
   * @param: inFile: ifstream object
   * @return: tree with file contents
   */

  BinaryNodeTree<string>* BuildTree(ifstream& inFile);

  /*
   * @pre: tree or stack created
   * @post: deletes tree and stack
   * @return: none
   */

  ~Executive();

private:
  string m_order;
  string m_file;
  BinaryNodeTree<string>* mytree;
  StackInterface<BinaryNodeTree<string>*>* mystack;
};
#endif
