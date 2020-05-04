/*
 * @Author: Joseph Pennington
 * @File Name: BinaryNode.h
 * @Assignment: EECS 560 Lab 09
 * @Brief: This program is the header file for the BinaryNode Class.
 */

#ifndef BINARYNODE_H
#define BINARYNODE_H

template<typename T>
class BinaryNode
{
  public:

    /*
    * @pre: None
    * @post: Binary Node made
    * @param value: Data to store
    * @return: none
    */

    BinaryNode(T value);

    /*
    * @pre: None
    * @post: Binary Node made
    * @return: none
    */

    BinaryNode();

    /*
    * @pre: Binary Node made
    * @post: Data is saved
    * @param newEntry: Data to save
    * @return: none
    */

    void setEntry(T newEntry);

    /*
    * @pre: Binary Node made
    * @post: Left pointer set
    * @param entryPointer: Node to point at
    * @return: none
    */

    void setLeft(BinaryNode<T>* entryPointer);

    /*
    * @pre: Binary Node made
    * @post: Right pointer set
    * @param entryPointer: Node to point at
    * @return: none
    */

    void setRight(BinaryNode<T>* entryPointer);

    /*
    * @pre: Binary Node made
    * @post: Left node retrieved
    * @return: Left node
    */

    BinaryNode<T>* getLeft() const;

    /*
    * @pre: Binary Node made
    * @post: Right node retrieved
    * @return: Right node
    */

    BinaryNode<T>* getRight() const;

    /*
    * @pre: Binary Node made
    * @post: Data is retrieved
    * @return: Data saved in node
    */

    T getEntry()const;

  private:

    //Data saved in node
    T m_entry;

    //Right pointer
    BinaryNode<T>* m_right;

    //Left pointer
    BinaryNode<T>* m_left;
    
  };
  #include "BinaryNode.cpp"
  #endif
