/*
 * @Author: Joseph Pennington
 * @File Name: BinaryNode.h
 * @Assignment: EECS 560 Lab 10
 * @Brief: This program is the h file for the BinaryNode Class.
 */

#ifndef BinaryNode_h
#define BinaryNode_h

template<class ItemType>
class BinaryNode
{
public:

  /*
  * @pre: Disjoint set made
  * @post: Creates a new node
  * @param anItem: Item to be stored in the node
  * @return: none
  */

  BinaryNode(ItemType& anItem);

  /*
  * @pre: Disjoint set made
  * @post: Sets data and pointer info
  * @param anItem: Item to be stored
  * @param parent: Parent pointer
  * @param anRank: Rank of node
  * @return: none
  */

  BinaryNode(ItemType& anItem, BinaryNode<ItemType>* parent, int anRank);

  /*
  * @pre: Node made
  * @post: Saves data
  * @param anItem: Item to be stored
  * @return: none
  */

  void setItem(ItemType& anItem);

  /*
  * @pre: Node made
  * @post: Data is retrieved
  * @return: Data in the node
  */

  ItemType getItem();

  /*
  * @pre: Node made
  * @post: Finds parent pointer
  * @return: Parent pointer
  */

  BinaryNode<ItemType>* getParentPtr();

  /*
  * @pre: Node made
  * @post: Retrieves rank info
  * @return: Rank of the node
  */

  int getRank();

  /*
  * @pre: Node made
  * @post: Sets rank of node
  * @param anRank: Rank of node
  * @return: none
  */

  void setRank(int anRank);

  /*
  * @pre: Node made
  * @post: Sets node's parent
  * @param parent: Pointer to parent
  * @return: none
  */

  void setParentPtr(BinaryNode<ItemType>* parent);

  /*
  * @pre: Node made
  * @post: Deletes node
  * @return: none
  */

  ~BinaryNode();

 private:

  //Data in the node
  ItemType item;

  //Parent pointer
  BinaryNode<ItemType>* parentPtr;

  //Rank of node
  int rank;

};
#include "BinaryNode.cpp"
#endif
