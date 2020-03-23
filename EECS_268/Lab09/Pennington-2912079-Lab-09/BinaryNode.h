/*
 * @Author: Joseph Pennington
 * @File Name: BinaryNode.h
 * @Assignment: EECS 268 Lab 09
 * @Date: 12/04/2018
 * @Brief: This is the BinaryNode header file
 */

#ifndef _BINARY_NODE
#define _BINARY_NODE

template<class ItemType>
class BinaryNode
{
private:
   ItemType              item;           // Data portion
   BinaryNode<ItemType>* leftChildPtr;   // Pointer to left child
   BinaryNode<ItemType>* rightChildPtr;  // Pointer to right child

public:

   /*
    * @pre: none
    * @post: sets binary node with item and left and right pointers
    * @param anItem: item read from file
    * @return: none
    */

   BinaryNode(const ItemType& anItem);

   /*
    * @pre: none
    * @post: sets binary node with item and sets left and right pointers
    * @param anItem: item read from file
    * @param leftPtr: node to be on the left
    * @param rightPtr: node to be on the right
    * @return: none
    */

   BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr);

   /*
    * @pre: item read from file
    * @post: sets item
    * @param anItem: item read from file
    * @return: none
    */

   void setItem(const ItemType& anItem);

   /*
    * @pre: item is set
    * @post: item is returned
    * @return: item
    */

   ItemType getItem() const;

   /*
    * @pre: right and left childs are set
    * @post: checks of left and right children are nullptr
    * @return: true if child and false if not
    */

   bool isLeaf() const;

   /*
    * @pre: left child ptr set
    * @post: pointer is get
    * @return: ptr to left child
    */

   BinaryNode<ItemType>* getLeftChildPtr() const;

   /*
    * @pre: right child ptr is set
    * @post: pointer is get
    * @return: ptr to right child
    */

   BinaryNode<ItemType>* getRightChildPtr() const;

   /*
    * @pre: ptr value is saved
    * @post: ptr value is set
    * @param leftPtr: pointer to left item
    * @return: none
    */

   void setLeftChildPtr(BinaryNode<ItemType>* leftPtr);

   /*
    * @pre: ptr value is saved
    * @post: ptr value is set
    * @param rightPtr: pointer to right item
    * @return: none
    */

   void setRightChildPtr(BinaryNode<ItemType>* rightPtr);
}; // end BinaryNode

#include "BinaryNode.cpp"

#endif
