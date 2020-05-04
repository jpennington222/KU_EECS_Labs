/*
 * @Author: Joseph Pennington
 * @File Name: BST.h
 * @Assignment: EECS 560 Lab 06
 * @Brief: This is the BST header file
 */

#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE

#include "BinaryNode.h"
#include <string>

template<class ItemType>
class BST
{
public:

  /*
  * @pre: Program ran
  * @post: New BST made
  * @return: none
  */

  BST();

  /*
  * @pre: BST made
  * @post: Node added to BST
  * @param item: The entry to be added
  * @return: True if added, otherwise false
  */

  bool add(ItemType item);


  /*
  * @pre: BST made
  * @post: Height is evaluated
  * @return: Height of the tree
  */

  int getHeight();

  /*
  * @pre: BST made
  * @post: m_root is returned
  * @return: m_root
  */

  BinaryNode<ItemType>* getRoot();



  /*
  * @pre: BST made
  * @post: Tree is printed in InOrder
  * @param start: The root of the tree
  * @return: none
  */

  void inOrder(BinaryNode<ItemType>* start);

  /*
  * @pre: BST made
  * @post: Tree is deleted
  * @return: none
  */

   ~BST();

   /*
   * @pre: BST made
   * @post: Starts LevelOrder printing
   * @return: none
   */

  void levelOrder()const;

  /*
  * @pre: BST made
  * @post: Tree is printed in LevelOrder
  * @param tree: root of the tree
  * @param i: The amount of nodes, used for looping
  * @return: none
  */

  void level(const BinaryNode<ItemType>* tree, int i)const;

  /*
  * @pre: BST made
  * @post: Starts destruction process
  * @return: True if last, otherwise false
  */

  void destroyTree();

  /*
  * @pre: BST made
  * @post: Starts process to remove single node
  * @param item: Key to be removed
  * @return: none
  */

  void remove(ItemType item);

  /*
  * @pre: BST made
  * @post: Starts destruction process
  * @param tree: Root pointer
  * @item: Key to be deleted
  * @return: Side of tree to traverse
  */

  BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* tree, ItemType item);

  /*
  * @pre: BST made
  * @post: Returns bool deleted
  * @return: True if deleted, otherwise false
  */

  bool getDeleted();

  /*
  * @pre: BST made
  * @post: Starts spiral order printing process
  * @param root: Root pointer
  * @return: none
  */

  void spiralTraversal(BinaryNode<ItemType>* root);

  /*
  * @pre: BST made
  * @post: Prints row left to right
  * @param root: Root pointer
  * @param level: Level being printed
  * @return: True if printed, otherwise false
  */

  bool spiralOrderLR(BinaryNode<ItemType>* root, int level);

  /*
  * @pre: BST made
  * @post: Prints row right to left
  * @param root: Root pointer
  * @param level: Level being printed
  * @return: True if printed, otherwise false
  */

  bool spiralOrderRL(BinaryNode<ItemType>* root, int level);

  /*
  * @pre: BST made
  * @post: Starts left side view printing process
  * @param root: Root pointer
  * @return: none
  */

  void leftView(BinaryNode<ItemType>* root);

  /*
  * @pre: BST made
  * @post: Prints left side view
  * @param root: Root pointer
  * @param level: Level being printed
  * @param max_level: Max number of levels
  * @return: none
  */

  void leftViewRec(BinaryNode<ItemType>* root, int level, int* max_level);

  /*
  * @pre: BST made
  * @post: Starts right side view printing process
  * @param root: Root pointer
  * @return: none
  */

  void rightView(BinaryNode<ItemType>* root);

  /*
  * @pre: BST made
  * @post: Prints left side view
  * @param root: Root pointer
  * @param level: Level being printed
  * @param max_level: Max number of levels
  * @return: none
  */

  void rightViewRec(BinaryNode<ItemType>* root, int level, int* max_level);

private:

    /*
    * @pre: BST made
    * @post: Entry recursively added into the tree
    * @param item: Entry to be added
    * @param position: Position in the tree
    * @param direction: ignore
    * @return: True if last, otherwise false
    */

    bool recAdd(ItemType item, BinaryNode<ItemType>* position);


    /*
    * @pre: BST made
    * @post: Height recursively found
    * @param Position: Position in the tree
    * @return: Height of the tree
    */

    int getHeightRec(BinaryNode<ItemType>* position)const;

    /*
    * @pre: BST made
    * @post: Entry recursively deleted
    * @param position: Position in the tree
    * @return: none
    */

    void recDestroy(BinaryNode<ItemType>* position);

    /*
    * @pre: BST made
    * @post: Removes node and sets pointers
    * @param position: Root pointer
    * @return: The BST
    */

    BinaryNode<ItemType>* recRemoveNode(BinaryNode<ItemType>* position);

    /*
    * @pre: BST made
    * @post: Removes leftmost node
    * @param subtree: Root pointer
    * @param item: Item to delete
    * @return: The BST
    */

    BinaryNode<ItemType>* removeLeftMost(BinaryNode<ItemType>* subtree, ItemType& item);

    //Root of the tree
    BinaryNode<ItemType>* m_root;

    //Number of nodes
    int m_nodes;

    //If a node was added
    bool added = false;

    //Height of the tree
    int m_height;

    //If deleted
    bool deleted;


};
#include "BST.cpp"
#endif
