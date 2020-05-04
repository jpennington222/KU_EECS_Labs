/*
 * @Author: Joseph Pennington
 * @File Name: BinaryNode.cpp
 * @Assignment: EECS 560 Lab 10
 * @Brief: This program is the cpp file for the BinaryNode Class.
 */

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(ItemType& anItem)
{
  item = anItem;
  parentPtr = nullptr;
  rank = 0;
}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode( ItemType& anItem,BinaryNode<ItemType>* parent,int anRank)
{
  parentPtr = parent;
  item = anItem;
  rank = anRank;
}

template<class ItemType>
void BinaryNode<ItemType>::setItem( ItemType& anItem)
{
  item = anItem;
}

template<class ItemType>
ItemType BinaryNode<ItemType>::getItem()
{
  return item;
}


template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getParentPtr()
{
 return parentPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setParentPtr(BinaryNode<ItemType>* parent)
{
  parentPtr = parent;
}

template<class ItemType>
int BinaryNode<ItemType>::getRank()
{
  return rank;
}

template<class ItemType>
void BinaryNode<ItemType>::setRank(int anRank)
{
  rank = anRank;
}

template<class ItemType>
BinaryNode<ItemType>::~BinaryNode()
{
  
}
