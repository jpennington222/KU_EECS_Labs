/*
 * @Author: Joseph Pennington
 * @File Name: DisjointSet.h
 * @Assignment: EECS 560 Lab 10
 * @Brief: This program is the h file for the DisjointSet Class.
 */

#ifndef DisjointSet_h
#define DisjointSet_h
#include <string>
#include <iostream>
#include "BinaryNode.h"
#include <vector>
using namespace std;

class DisjointSet
{
public:

  /*
  * @pre: none
  * @post: New disjoint set made
  * @param size: Size of the array
  * @return: none
  */

  DisjointSet(int size);

  /*
  * @pre: Disjoint set made
  * @post: Each entry is made into a set of 1 entry
  * @param value: Value in the set
  * @return: none
  */

  void makeSet(int value);

  /*
  * @pre: Disjoint set made
  * @post: Sets are unioned
  * @param x: Representative 1
  * @param y: Representative 2
  * @return: Representative of union
  */

  int Union(int x, int y);

  /*
  * @pre: Disjoint set made
  * @post: Recursively find root
  * @param subTreePtr: Pointer in the set
  * @return: Pointer to a different node
  */

  BinaryNode<int>* findSameRoot(BinaryNode<int>* subTreePtr);

  /*
  * @pre: Disjoint set made
  * @post: Finds root of set
  * @param x: Value to find in the set
  * @return: Representative of the value, -1 if not in the set
  */

  int find(int x);

  /*
  * @pre: Disjoint set made
  * @post: Performs path compression on a node
  * @param x: Value to perform compression on
  * @return: none
  */

  void pathCompression(int x);

  /*
  * @pre: Disjoint set made
  * @post: Path from the node to the representative is printed
  * @param x: Starting value
  * @return: none
  */

  void printPath(int x);

  /*
  * @pre: Disjoint set made
  * @post: Deletes disjoint set
  * @return: none
  */

  ~DisjointSet();

private:

  //BinaryNode Array Pointer
  BinaryNode<int>** m_set;

  //Size of the array
  int m_size;

  //Position in array
  int m_length;
};
#endif
