/*
 * @Author: Joseph Pennington
 * @File Name: BinaryNodeTree.cpp
 * @Assignment: EECS 268 Lab 08
 * @Date: 11/13/2018
 * @Brief: This is the BinaryNodeTree cpp file
 */

 #include "BinaryNodeTree.h"
 #include "BinaryNode.h"
 #include <iostream>

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree()
{
  rootPtr = nullptr;
}

 template<class ItemType>
 BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
 {
   rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
 }  // end constructor

 template<class ItemType>
 BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem, const BinaryNodeTree<ItemType>* leftTreePtr, const BinaryNodeTree<ItemType>* rightTreePtr)
 {
   rootPtr = new BinaryNode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr),
   copyTree(rightTreePtr->rootPtr));
 }  // end constructor

 template<class ItemType>
 BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& tree)
 {
   rootPtr = copyTree(tree.rootPtr);
 }  // end copy constructor

 template<class ItemType>
 BinaryNodeTree<ItemType>::~BinaryNodeTree()
 {
   destroyTree(rootPtr);
 }  // end destructor

 template<class ItemType>
 void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
 {
   if(subTreePtr!=nullptr)
   {
     destroyTree(subTreePtr->getLeftChildPtr());
     destroyTree(subTreePtr->getRightChildPtr());
     delete subTreePtr;
   }
 }

 template<class ItemType>
 void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
 {
   inorder(visit, rootPtr);
 }  // end inorderTraverse

 template<class ItemType>
 void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
 {
   preorder(visit, rootPtr);
 } // end preorderTraverse

template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
  postorder(visit, rootPtr);
}  // end postorderTraverse

template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if(treePtr!=nullptr)
  {
    string temp;
    inorder(visit, treePtr->getLeftChildPtr());
    temp=treePtr->getItem();
    visit(temp);
    inorder(visit, treePtr->getRightChildPtr());
  }
}

template<class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if(treePtr!=nullptr)
  {
    string temp;
    temp=treePtr->getItem();
    visit(temp);
    preorder(visit, treePtr->getLeftChildPtr());
    preorder(visit, treePtr->getRightChildPtr());
  }
}

template<class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if(treePtr!=nullptr)
  {
    string temp;
    postorder(visit, treePtr->getLeftChildPtr());
    postorder(visit, treePtr->getRightChildPtr());
    temp=treePtr->getItem();
    visit(temp);
  }
}

template<class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
  return(rootPtr==nullptr);
}

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const throw(PrecondViolatedExcep)
{
  if(rootPtr==nullptr)
  {
    throw PrecondViolatedExcep("Cannot get Root Data");
  }
  return(rootPtr->getItem());
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{
  BinaryNode<ItemType>* sample=nullptr;
  if(treePtr!=nullptr)
  {
    sample=new BinaryNode<string>(treePtr->getItem());
    sample->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
    sample->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
  }
  return(sample);
}

template<class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree& rightHandSide)
{
  rootPtr=copyTree(rightHandSide.rootPtr);
  return(*this);
}
