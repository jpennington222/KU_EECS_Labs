/*
 * @Author: Joseph Pennington
 * @File Name: BinaryNodeTree.cpp
 * @Assignment: EECS 560 Lab 04
 * @Brief: This is the BinaryNodeTree cpp file
 */

#include "BST.h"
#include "BinaryNode.h"
#include "BSTEntry.h"
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
  int height = getHeight();
  added = false;
  if(item.getRating() < 0 || item.getRating() > 5)
  {
    cout << "Rating Invalid\n";
    return(false);
  }
  else
  {
    isDuplicate(item.getMovie());
    if(duplicated == false)
    {
      if(isFull())
      {
        return(recAdd(item, m_root, height));
      }
      else
      {
        return(recAdd(item, m_root, height-1));
      }
    }
    else
    {
      cout << "Duplicate Entry\n";
      return(false);
    }
  }
}

template <typename ItemType>
bool BST<ItemType>::recAdd(ItemType item, BinaryNode<ItemType>* position, int direction)
{

  if(m_root == nullptr)
  {
      m_root = new BinaryNode<ItemType>(item);
      m_nodes++;
      return(true);
  }
  if(direction == 0)
  {
    addNode(item, position);
    return(true);
  }
  recAdd(item, position -> getLeft(), direction-1);
  if(added)
  {
    return(true);
  }
  recAdd(item, position -> getRight(), direction-1);
}

template <typename ItemType>
void BST<ItemType>::addNode(ItemType item, BinaryNode<ItemType>* position)
{
  if(checkLast(position))
  {
    if(position == nullptr)
    {
      cout << "Error adding\n";
    }
    else if(position -> getLeft() == nullptr)
    {
      position -> setLeft(new BinaryNode<ItemType>(item));
      m_nodes++;
      added = true;
    }
    else if(position -> getRight() == nullptr)
    {
      position -> setRight(new BinaryNode<ItemType>(item));
      m_nodes++;
      added = true;
    }
    else
    {
      cout << "Error adding 2\n";
    }
  }
}

template <typename ItemType>
bool BST<ItemType>::checkLast(BinaryNode<ItemType>* position)
{
  if((position -> getLeft() == nullptr && position -> getRight() == nullptr) || (position -> getLeft() != nullptr && position -> getRight() == nullptr))
  {
    return(true);
  }
  else
  {
    return(false);
  }
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
void BST<ItemType>::preOrder(BinaryNode<ItemType>* start)
{
  if(start != nullptr)
  {
    cout << start -> getEntry().getRating() << " ";
    preOrder(start -> getLeft());
    preOrder(start -> getRight());
  }
}

template <typename ItemType>
void BST<ItemType>::postOrder(BinaryNode<ItemType>* start)
{
  if(start != nullptr)
  {
    postOrder(start -> getLeft());
    postOrder(start -> getRight());
    cout << start -> getEntry().getRating() << " ";
  }
}

template <typename ItemType>
void BST<ItemType>::inOrder(BinaryNode<ItemType>* start)
{
  if(start != nullptr)
  {
    inOrder(start -> getLeft());
    cout << start -> getEntry().getRating() << " ";
    inOrder(start -> getRight());
  }
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
    cout<< tree -> getEntry().getMovie()<< " ";
  }
  else if(i > 1)
  {
    level(tree -> getLeft(), i-1);
    level(tree -> getRight(), i-1);
  }
}

template <typename ItemType>
BinaryNode<ItemType>* BST<ItemType>::getRoot()
{
  return(m_root);
}

template <typename ItemType>
bool BST<ItemType>::isFull()
{
  int height = getHeight()+1;
  int full = 0;
  full = pow(2, height)-1;
  if(full == m_nodes)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

template <typename ItemType>
void BST<ItemType>::printLeaves(BinaryNode<ItemType>* start)
{
  if(start == nullptr)
  {
    cout << "Empty tree. Nothing to print\n";
    return;
  }
  if(start -> getLeft() == nullptr && start -> getRight() == nullptr)
  {
    cout << start -> getEntry().getMovie() << " ";
    return;
  }
  if(start -> getLeft() != nullptr)
  {
    printLeaves(start -> getLeft());
  }
  if(start -> getRight() != nullptr)
  {
    printLeaves(start -> getRight());
  }
}

template <typename ItemType>
void BST<ItemType>::isLeaf(BinaryNode<ItemType>* start, string movie)
{
  foundLeaf = false;
  getLeaves(start, movie);
}

template <typename ItemType>
void BST<ItemType>::getLeaves(BinaryNode<ItemType>* start, string movie)
{
  if(start == nullptr)
  {
    cout << "Empty tree. Nothing to print\n";
    return;
  }
  if(start -> getLeft() == nullptr && start -> getRight() == nullptr && start -> getEntry().getMovie() == movie)
  {
    foundLeaf = true;
    return;
  }
  if(start -> getLeft() != nullptr)
  {
    getLeaves(start -> getLeft(),movie);
  }
  if(start -> getRight() != nullptr)
  {
    getLeaves(start -> getRight(),movie);
  }
}

template <typename ItemType>
bool BST<ItemType>::getFoundLeaf()
{
  return(foundLeaf);
}

template <typename ItemType>
bool BST<ItemType>::getDuplicated()
{
  return(duplicated);
}

template <typename ItemType>
bool BST<ItemType>::getRemoved()
{
  return(removed);
}

template <typename ItemType>
bool BST<ItemType>::getAdded()
{
  return(added);
}

template <typename ItemType>
void BST<ItemType>::isDuplicate(string movie)
{
  duplicated = false;
  recDuplicate(m_root, movie);
}

template <typename ItemType>
void BST<ItemType>::recDuplicate(BinaryNode<ItemType>* start, std::string movie)
{
  if(start == nullptr)
  {
    return;
  }
  if(start -> getEntry().getMovie() == movie)
  {
    duplicated = true;
    return;
  }
  if(start -> getLeft() != nullptr)
  {
    recDuplicate(start -> getLeft(),movie);
  }
  if(start -> getRight() != nullptr)
  {
    recDuplicate(start -> getRight(),movie);
  }
}

template <typename ItemType>
void BST<ItemType>::remove()
{
  removed = false;

  if(m_root == nullptr)
  {
    cout << "Empty Tree. Nothing to remove.\n";
  }
  else if(m_root -> getLeft() == nullptr && m_root -> getRight() == nullptr)
  {
    BinaryNode<ItemType>* temp = m_root;
    m_root = nullptr;
    delete temp;
  }
  else
  if(!removeLast())
  {
    cout << "Failed to remove.\n";
  }
}

template <typename ItemType>
bool BST<ItemType>::removeLast()
{
  if(isFull() && (getHeightRec(m_root -> getLeft()) == getHeightRec(m_root -> getRight())))
  {
    recRemove(m_root, getHeightRec(m_root -> getRight()));
    return(true);
  }
  else
  {
    recRemove(m_root, getHeightRec(m_root -> getLeft()));
    return(true);
  }
  return(false);
}


template <typename ItemType>
void BST<ItemType>::recRemove(BinaryNode<ItemType>* root, int level)
{
  if(level == 0)
  {
    removeNode(root);
    return;
  }
  recRemove(root -> getRight(), level-1);
  if(removed)
  {
    return;
  }
  recRemove(root -> getLeft(), level-1);
}

template <typename ItemType>
void BST<ItemType>::removeNode(BinaryNode<ItemType>* root)
{
  if(checkLastAdded(root))
  {
    if(root == nullptr)
    {
      cout << "Error deleting\n";
    }
    else if(root -> getRight () != nullptr)
    {
      BinaryNode<ItemType>* temp = root -> getRight();
      root -> setRight(nullptr);
      cout << "The last movie with title " << temp -> getEntry().getMovie() << " and rating " << temp -> getEntry().getRating() << " has been deleted\n";
      delete temp;
      removed = true;
      m_nodes--;
    }
    else if(root -> getLeft() != nullptr)
    {
      BinaryNode<ItemType>* temp = root -> getLeft();
      root -> setLeft(nullptr);
      cout << "The last movie with title " << temp -> getEntry().getMovie() << " and rating " << temp -> getEntry().getRating() << " has been deleted\n";
      delete temp;
      removed = true;
      m_nodes--;
    }
    else
    {
      cout << "Error removing\n";
    }
  }
}

template <typename ItemType>
bool BST<ItemType>::checkLastAdded(BinaryNode<ItemType>* root)
{
  if((root -> getLeft() != nullptr && root -> getRight() != nullptr) || (root -> getLeft() != nullptr && root -> getRight() == nullptr))
  {
    return(true);
  }
  else
  {
    return(false);
  }
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
