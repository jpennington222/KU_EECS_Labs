/*
 * @Author: Joseph Pennington
 * @File Name: BinaryNode.h
 * @Assignment: EECS 560 Lab 06
 * @Brief: This is the BinaryNode header file
 */

 #ifndef BINARYNODE_H
 #define BINARYNODE_H

 template<typename T>
 class BinaryNode
 {
   public:

     /*
        Pre:user passes T value to a node
        Post: none
        Return: none
     */

     BinaryNode(T value);

     /*
        Pre:none
        Post: none
        Return: none
     */

     BinaryNode();

     /*
        Pre:have a node to set = to next
        Post: nodes are connectedm_root;
        param: T entry
        Return: none
     */

     void setEntry(T newEntry);

     /*
        Pre:have a node to set = to next
        Post: nodes are connectedm_root
        Return: none
     */

     void setLeft(BinaryNode<T>* entryPointer);

     /*
        Pre:have a node to set = to next
        Post: nodes are connected
        Return: none;
     */

     void setRight(BinaryNode<T>* entryPointer);

     /*
        Pre:node with T value available to get
        Post: none
        Return: T value within node
     */

     BinaryNode<T>* getLeft() const;

     /*
        Pre:node with T value available to get
        Post: none
        Return: T value within node
     */

     BinaryNode<T>* getRight() const;

     /*
        Pre:node with T value available to get
        Post: none
        Return: T value within node
     */

     T getEntry()const;

   private:
     //Entry to be added
     T m_entry;

     //Right Pointer
     BinaryNode<T>* m_right;

     //Left Pointer
     BinaryNode<T>* m_left;
   };
   #include "BinaryNode.cpp"
   #endif
