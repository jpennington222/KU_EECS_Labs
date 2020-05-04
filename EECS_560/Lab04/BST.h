/*
 * @Author: Joseph Pennington
 * @File Name: BST.h
 * @Assignment: EECS 560 Lab 04
 * @Brief: This is the BST header file
 */

#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE

#include "BinaryNode.h"
#include "BSTEntry.h"
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
  * @post: The tree is evaluated if true or not
  * @return: True if full, otherwise false
  */

  bool isFull();

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
  * @post: Starts the removing last node process
  * @return: none
  */

  void remove();

  /*
  * @pre: BST made
  * @post: Tree is printed in PreOrder
  * @param start: The root of the tree
  * @return: none
  */

  void preOrder(BinaryNode<ItemType>* start);

  /*
  * @pre: BST made
  * @post: Tree is printed in PostOrder
  * @param start: The root of the tree
  * @return: none
  */

  void postOrder(BinaryNode<ItemType>* start);

  /*
  * @pre: BST made
  * @post: Tree is printed in InOrder
  * @param start: The root of the tree
  * @return: none
  */

  void inOrder(BinaryNode<ItemType>* start);

  /*
  * @pre: BST made
  * @post: Leaves are printed
  * @param start: The root of the tree
  * @return: none
  */

  void printLeaves(BinaryNode<ItemType>* start);

  /*
  * @pre: BST made
  * @post: Checks if a node is a leaf
  * @param start: The root of the tree
  * @param movie: Compare user input to tree
  * @return: none
  */

  void isLeaf(BinaryNode<ItemType>* start, std::string movie);

  /*
  * @pre: BST made
  * @post: Determines if a node is a leaf
  * @param start: The root of the tree
  * @param movie: Movie to compare to the leaves
  * @return: none
  */

  void getLeaves(BinaryNode<ItemType>* start, std::string movie);

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
  * @post: foundLeaf returned
  * @return: foundLeaf
  */

  bool getFoundLeaf();

  /*
  * @pre: BST made
  * @post: Determines if an entry is a duplicate
  * @param movie: Movie title to be added
  * @return: True if duplicate, otherwise false
  */

  void isDuplicate(std::string movie);

  /*
  * @pre: BST made
  * @post: duplicated returned
  * @return: duplicated
  */

  bool getDuplicated();

  /*
  * @pre: BST made
  * @post: removed returned
  * @return: removed
  */

  bool getRemoved();

  /*
  * @pre: BST made
  * @post: added returned
  * @return: added
  */

  bool getAdded();

  /*
  * @pre: BST made
  * @post: Entry is added
  * @param item: Entry to be added
  * @param position: Position in the tree
  * @return: none
  */

  void addNode(ItemType item, BinaryNode<ItemType>* position);

  /*
  * @pre: BST made
  * @post: Checks if a node is last
  * @param position: Position in the tree
  * @return: True if last, otherwise false
  */

  bool checkLast(BinaryNode<ItemType>* position);

  /*
  * @pre: BST made
  * @post: Starts destruction process
  * @return: True if last, otherwise false
  */

  void destroyTree();

  /*
  * @pre: BST made
  * @post: Checks if the last node was removed
  * @return: True if removed, otherwise false
  */

  bool removeLast();

  /*
  * @pre: BST made
  * @post: Removes the last node
  * @param root: Position in the tree
  * @return: none
  */

  void removeNode(BinaryNode<ItemType>* root);

  /*
  * @pre: BST made
  * @post: Checks if a node was added last
  * @param root: Position in the tree
  * @return: True if last, otherwise false
  */

  bool checkLastAdded(BinaryNode<ItemType>* root);

private:

    /*
    * @pre: BST made
    * @post: Entry recursively added into the tree
    * @param item: Entry to be added
    * @param position: Position in the tree
    * @param direction: ignore
    * @return: True if last, otherwise false
    */

    bool recAdd(ItemType item, BinaryNode<ItemType>* position, int direction);

    /*
    * @pre: BST made
    * @post: Entry recursively checked if duplicated
    * @param start: Position in the tree
    * @param movie: Movie to compare
    * @return: none
    */

    void recDuplicate(BinaryNode<ItemType>* start, std::string movie);

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
    * @post: Entry recursively removes last node
    * @param root: Position in the tree
    * @param level: Height of the tree
    * @return: none
    */

    void recRemove(BinaryNode<ItemType>* root, int level);

    //Root of the tree
    BinaryNode<ItemType>* m_root;

    //Number of nodes
    int m_nodes;

    //If a node was added
    bool added = false;

    //If a node is a leaf
    bool foundLeaf = false;

    //Height of the tree
    int m_height;

    //If a node was removed
    bool removed = false;

    //If a node is a duplicate
    bool duplicated = false;
};
#include "BST.cpp"
#endif
