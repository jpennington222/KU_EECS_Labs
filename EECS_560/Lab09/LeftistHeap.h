/*
 * @Author: Joseph Pennington
 * @File Name: LeaftistHeap.cpp
 * @Assignment: EECS 560 Lab 09
 * @Brief: This program is the header file for the LeftistHeap Class.
 */
#ifndef LeftistHeap_H
#define LeftistHeap_H
#include "BinaryNode.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
using namespace std;

template<typename ItemType, typename SearchType>
class LeftistHeap
{
  public:

    /*
    * @pre: None
    * @post: Leftist heap made
    * @return: None
    */

    LeftistHeap();

    /*
    * @pre: Leftist heap made
    * @post: Entry added to the heap
    * @param item: Item to add to the heap
    * @return: True if added, otherwise false
    */

    bool add(ItemType item);

    /*
    * @pre: Leftist heap made
    * @post: Retrieves root of the heap
    * @return: Root of the heap
    */

    BinaryNode<ItemType>* getRoot();

    /*
    * @pre: Leftist heap made
    * @post: Begins level order printing
    * @return: None
    */

    void levelOrder()const;

    /*
    * @pre: Leftist heap made
    * @post: Recursively prints heap in level order
    * @param tree: BinaryNode in the heap
    * @param i: Level of the heap
    * @return: BinaryNode in the heap
    */

    bool level(const BinaryNode<ItemType>* tree, int i)const;

    /*
    * @pre: Leftist heap made
    * @post: Merges heaps together
    * @param h1: Heap 1
    * @param h2: Heap 2
    * @return: The root of the merged heap
    */

    BinaryNode<ItemType>* merge(BinaryNode<ItemType>* h1, BinaryNode<ItemType>* h2);

    /*
    * @pre: Leftist heap made
    * @post: Removes root of the heap and calls merge
    * @return: True if removed, otherwise false
    */

    bool removeMin();

    /*
    * @pre: Leftist heap made
    * @post: Recursively deletes heap
    * @return: None
    */

    ~LeftistHeap();

  private:

    //Root of the heap
    BinaryNode<ItemType>* m_root;

    //Recursively deletes heap
    void recDestroy(BinaryNode<ItemType>* start);

    //Recursively computes the rank
    int getRank(BinaryNode<ItemType>* node);

  };
  #include "LeftistHeap.cpp"
  #endif
