/*
 * @Author: Joseph Pennington
 * @File Name: BST.cpp
 * @Assignment: EECS 560 Lab 06
 * @Brief: This is the BinaryNodeTree cpp file
 */

#include "BST.h"
#include "BinaryNode.h"
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

template<typename ItemType>
BST<ItemType>::BST()
{
  m_root=nullptr;
}

template <typename ItemType>
bool BST<ItemType>::add(ItemType item)
{
  return(recAdd(item, m_root));
}

template <typename ItemType>
bool BST<ItemType>::recAdd(ItemType item, BinaryNode<ItemType>* position)
{
  if(m_root == nullptr)
  {
    m_root = new BinaryNode<ItemType>(item);
    m_nodes++;
    return(true);
  }
  else
  {
    if(item >= position -> getEntry())
    {
      if(position -> getRight() == nullptr)
      {
        position -> setRight(new BinaryNode<ItemType>(item));
        m_nodes++;
        return(true);
      }
      else
      {
        recAdd(item, position -> getRight());
      }
    }
    else
    {
      if(position -> getLeft() == nullptr)
      {
        position -> setLeft(new BinaryNode<ItemType>(item));
        m_nodes++;
        return(true);
      }
      else
      {
        recAdd(item, position -> getLeft());
      }
    }
  }
  return(true);
}


template <typename ItemType>
int BST<ItemType>::getHeight()
{
  if(m_root == nullptr)
  {
    return(0);
  }
  else
  {
    return(getHeightRec(m_root));
  }
}

template <typename ItemType>
int BST<ItemType>::getHeightRec(BinaryNode<ItemType>* position)const
{
  if(position != nullptr)
  {
    return (getHeightRec(position -> getLeft())+1);
  }
  return(-1);
}


template <typename ItemType>
void BST<ItemType>::inOrder(BinaryNode<ItemType>* start)
{
  if(start != nullptr)
  {
    inOrder(start -> getLeft());
    cout << start -> getEntry() << " ";
    inOrder(start -> getRight());
  }
}

template <typename ItemType>
void BST<ItemType>::spiralTraversal(BinaryNode<ItemType>* root)
{
  if(root == nullptr)
  {
    return;
  }
  int level = 1;
  while(spiralOrderLR(root, level++) && spiralOrderRL(root, level++));
}


template <typename ItemType>
bool BST<ItemType>::spiralOrderLR(BinaryNode<ItemType>* root, int level)
{
  if(root == nullptr)
  {
    return(false);
  }
  if(level == 1)
  {
    cout << root -> getEntry() << " ";
    return(true);
  }
  bool left = spiralOrderLR(root -> getLeft(), level-1);
  bool right = spiralOrderLR(root -> getRight(), level-1);
  return(left || right);
}

template <typename ItemType>
bool BST<ItemType>::spiralOrderRL(BinaryNode<ItemType>* root, int level)
{
  if(root == nullptr)
  {
    return(false);
  }
  if(level == 1)
  {
    cout << root -> getEntry() << " ";
    return(true);
  }
  bool left = spiralOrderRL(root -> getRight(), level-1);
  bool right = spiralOrderRL(root -> getLeft(), level-1);
  return(left || right);
}

template <typename ItemType>
void BST<ItemType>::levelOrder()const
{
  for(int i = 0; i <= m_nodes+1; i++)
  {
    level(m_root, i);
  }
}

template <typename ItemType>
void BST<ItemType>::level(const BinaryNode<ItemType>* tree, int i)const
{
  if(tree == nullptr)
  {
    return;
  }
  if(i == 1)
  {
    cout<< tree -> getEntry()<< " ";
  }
  else if(i > 1)
  {
    level(tree -> getLeft(), i-1);
    level(tree -> getRight(), i-1);
  }
}

template <typename ItemType>
void BST<ItemType>::leftView(BinaryNode<ItemType>* root)
{
  int max_level = 0;
  leftViewRec(root, 1, &max_level);
}

template <typename ItemType>
void BST<ItemType>::leftViewRec(BinaryNode<ItemType>* root, int level, int* max_level)
{
  if(root == nullptr)
  {
    return;
  }

  if(*max_level < level)
  {
    cout << root -> getEntry() << " ";
    *max_level = level;
  }

  leftViewRec(root -> getLeft(), level + 1, max_level);
  leftViewRec(root -> getRight(), level + 1, max_level);
}

template <typename ItemType>
void BST<ItemType>::rightView(BinaryNode<ItemType>* root)
{
  int max_level = 0;
  rightViewRec(root, 1, &max_level);
}

template <typename ItemType>
void BST<ItemType>::rightViewRec(BinaryNode<ItemType>* root, int level, int* max_level)
{
  if(root == nullptr)
  {
    return;
  }

  if(*max_level < level)
  {
    cout << root -> getEntry() << " ";
    *max_level = level;
  }

  rightViewRec(root -> getRight(), level + 1, max_level);
  rightViewRec(root -> getLeft(), level + 1, max_level);
}

template <typename ItemType>
void BST<ItemType>::remove(ItemType item)
{
  deleted = false;
  removeValue(m_root, item);
}

template <typename ItemType>
BinaryNode<ItemType>* BST<ItemType>::removeValue(BinaryNode<ItemType>* tree, ItemType item)
{
  if(tree == nullptr)
  {
    deleted = false;
    return(nullptr);
  }
  else if(tree -> getEntry() > item)
  {
    BinaryNode<ItemType>* temp = removeValue(tree -> getLeft(), item);
    tree -> setLeft(temp);
  }
  else if(tree -> getEntry() == item)
  {
    tree = recRemoveNode(tree);
  }
  else
  {
    BinaryNode<ItemType>* temp = removeValue(tree -> getRight(), item);
    tree -> setRight(temp);
  }
  return tree;
}

template<typename ItemType>
BinaryNode<ItemType>* BST<ItemType>::recRemoveNode(BinaryNode<ItemType>* position)
{
  if(position -> getLeft() == nullptr && position -> getRight()==nullptr)
  {
    delete position;
    position = nullptr;
    deleted = true;
    return position;
  }
  else if(position -> getLeft() !=nullptr && position -> getRight() == nullptr)
  {
    BinaryNode<ItemType>* temp = position->getLeft();
    delete position;
    deleted = true;
    return temp;
  }
  else if(position -> getRight() != nullptr && position -> getLeft() == nullptr)
  {
    BinaryNode<ItemType>* temp = position -> getRight();
    delete position;
    deleted = true;
    return temp;
  }
  else
  {
    ItemType newNode;
    BinaryNode<ItemType>* temp = removeLeftMost(position -> getRight(), newNode);
    position -> setRight(temp);
    position -> setEntry(newNode);
    return position;
  }
}

template<typename ItemType>
BinaryNode<ItemType>* BST<ItemType>::removeLeftMost(BinaryNode<ItemType>* subtree, ItemType& item)
{
  if(subtree -> getLeft()==nullptr)
  {
    item = subtree -> getEntry();
    return(recRemoveNode(subtree));
  }
  else
    {
      BinaryNode<ItemType>* temp = removeLeftMost(subtree -> getLeft(), item);
      subtree -> setLeft(temp);
      return(subtree);
    }
}


template <typename ItemType>
BinaryNode<ItemType>* BST<ItemType>::getRoot()
{
  return(m_root);
}

template <typename ItemType>
bool BST<ItemType>::getDeleted()
{
  return(deleted);
}

template <typename ItemType>
void BST<ItemType>::recDestroy(BinaryNode<ItemType>* position)
{
  if(position -> getLeft() != nullptr)
  {
    recDestroy(position -> getLeft());
  }
  if(position -> getRight() != nullptr)
  {
    recDestroy(position -> getRight());
  }
  delete position;
}

template <typename ItemType>
void BST<ItemType>::destroyTree()
{
    if(m_root != nullptr)
    {
      recDestroy(m_root);
    }
}

template <typename ItemType>
BST<ItemType>::~BST()
{
  destroyTree();
}
