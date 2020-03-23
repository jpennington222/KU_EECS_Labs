/*
 * @Author: Joseph Pennington
 * @File Name: BinaryNode.cpp
 * @Assignment: EECS 268 Lab 09
 * @Date: 12/04/2018
 * @Brief: This is the BinarySearchTree cpp file
 */

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode)
{
  if(subTreePtr==nullptr)
  {
    return newNode;
  }
  else if(newNode->getItem()==subTreePtr->getItem())
  {
    delete newNode;
    return(subTreePtr);
  }
  else if(newNode->getItem()>subTreePtr->getItem())
  {
    BinaryNode<ItemType>* tempPtr=insertInorder(subTreePtr->getRightChildPtr(), newNode);
    subTreePtr->setRightChildPtr(tempPtr);
  }
  else
  {
    BinaryNode<ItemType>* tempPtr=insertInorder(subTreePtr->getLeftChildPtr(), newNode);
    subTreePtr->setLeftChildPtr(tempPtr);
  }
  return subTreePtr;
}

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, KeyType target, bool& success)
{
  if(subTreePtr==nullptr)
  {
    success=false;
  }
  else if(subTreePtr->getItem()==target)
  {
    subTreePtr=removeNode(subTreePtr);
    success=true;
  }
  else if(subTreePtr->getItem()>target)
  {
    BinaryNode<ItemType>* tempy = removeValue(subTreePtr->getLeftChildPtr(), target, success);
    subTreePtr->setLeftChildPtr(tempy);
  }
  else
  {
    BinaryNode<ItemType>* tempy =removeValue(subTreePtr->getRightChildPtr(), target, success);
    subTreePtr->setRightChildPtr(tempy);
  }
  return subTreePtr;
}

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeNode(BinaryNode<ItemType>* nodePtr)
{
  if(nodePtr==nullptr)
  {
    return(nullptr);
  }
  if(nodePtr->isLeaf())
  {
    delete nodePtr;
    return nullptr;
  }
  else if((nodePtr->getLeftChildPtr()==nullptr && nodePtr->getRightChildPtr() !=nullptr) || (nodePtr->getRightChildPtr() ==nullptr && nodePtr->getLeftChildPtr() !=nullptr))
  {
    BinaryNode<ItemType>* connection;
    if(nodePtr->getLeftChildPtr() !=nullptr)
    {
      connection =nodePtr->getLeftChildPtr();
    }
    else
    {
      connection=nodePtr->getRightChildPtr();
    }
    delete nodePtr;
    nodePtr=nullptr;
    return connection;
  }
  else
  {
    ItemType inorder;
    BinaryNode<ItemType>* tempy = removeLeftmostNode(nodePtr->getRightChildPtr(), inorder);
    nodePtr->setRightChildPtr(tempy);
    nodePtr->setItem(inorder);
    return(nodePtr);
  }
}

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor)
{
  if(subTreePtr->getLeftChildPtr()==nullptr)
  {
    inorderSuccessor=subTreePtr->getItem();
    return removeNode(subTreePtr);
  }
  else
  {
    subTreePtr->setLeftChildPtr(removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor));
    return subTreePtr;
  }
}

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::findNode(BinaryNode<ItemType>* treePtr, KeyType key) const
{
  if(treePtr==nullptr)
  {
    return nullptr;
  }
  else if(treePtr->getItem()==key)
  {
    return treePtr;
  }
  else if(treePtr->getItem()>key)
  {
    return findNode(treePtr->getLeftChildPtr(), key);
  }
  else
  {
    return findNode(treePtr->getRightChildPtr(), key);
  }
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getHeightRecurs(BinaryNode<ItemType>* subTreePtr) const
{
  if(subTreePtr==nullptr)
  {
    return 0;
  }
  else
  {
    return(1+max(getHeightRecurs(subTreePtr->getLeftChildPtr()), getHeightRecurs(subTreePtr->getRightChildPtr())));
  }
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getNumberRecurs(BinaryNode<ItemType>* subTreePtr) const
{
  if(subTreePtr==nullptr)
  {
    return 0;
  }
  else
  {
    return(1+getNumberRecurs(subTreePtr->getLeftChildPtr()+getNumberRecurs(subTreePtr->getRightChildPtr())));
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType,ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if(treePtr!=nullptr)
  {
    inorder(visit, treePtr->getLeftChildPtr());
    ItemType temp=treePtr->getItem();

    visit(temp);
    inorder(visit, treePtr->getRightChildPtr());
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType,ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if(treePtr!=nullptr)
  {
    ItemType temp=treePtr->getItem();

    visit(temp);
    preorder(visit, treePtr->getLeftChildPtr());
    preorder(visit, treePtr->getRightChildPtr());
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType,ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if(treePtr!=nullptr)
  {
    postorder(visit, treePtr->getLeftChildPtr());
    postorder(visit, treePtr->getRightChildPtr());
    ItemType temp=treePtr->getItem();
    visit(temp);
  }
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType,ItemType>::BinarySearchTree()
{
  rootPtr=nullptr;
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType,ItemType>::BinarySearchTree(const ItemType& rootItem)
{
  rootPtr=new BinaryNode<ItemType>(rootItem);
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType,ItemType>::BinarySearchTree(const BinarySearchTree& tree)
{
  rootPtr=copyTree(tree.rootPtr);
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType,ItemType>::~BinarySearchTree()
{
  clear();
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType,ItemType>::isEmpty() const
{
  return(rootPtr==nullptr);
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType,ItemType>::getHeight() const
{
  return getHeightRecurs(rootPtr);
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType,ItemType>::getNumberOfNodes() const
{
  return getNumberRecurs(rootPtr);
}

template<typename KeyType, typename ItemType>
void setEntry(const KeyType& aKey, const ItemType& item)  throw(NotFoundException, InvalidSetEntryRequest)
{
  if(item == aKey)
  {
    if(contains(aKey)==false)
    {
      throw NotFoundException("NotFound setEntry Error");
    }
  }

  else
  {
    throw InvalidSetEntryRequest("Invalid SetEntry Error");
  }
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType,ItemType>::add(const ItemType& newEntry)
{
  BinaryNode<ItemType>* newPtr = new BinaryNode<ItemType>(newEntry);
  rootPtr = insertInorder(rootPtr, newPtr);
  if(rootPtr==nullptr)
  {
    return false;
  }
  return(true);
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType,ItemType>::remove(const KeyType& anEntry)
{
  bool done = false;
  rootPtr=removeValue(rootPtr, anEntry, done);
  return done;
}

template<typename KeyType, typename ItemType>
ItemType BinarySearchTree<KeyType, ItemType>::getEntry(const KeyType& anEntry) const throw(NotFoundException)
{
  BinaryNode<ItemType>* tempyptr=findNode(rootPtr,anEntry);
  if(tempyptr==nullptr)
  {
    throw NotFoundException("getEntry Error");
  }
  else
  {
    return tempyptr->getItem();
  }
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::contains(const KeyType& anEntry) const
{
  if(findNode(rootPtr,anEntry) !=nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType,ItemType>::clear()
{
  while(!isEmpty())
  {
    rootPtr=removeNode(rootPtr);
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType,ItemType>::inorderTraverse(void visit(ItemType&)) const
{
  inorder(visit, rootPtr);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType,ItemType>::preorderTraverse(void visit(ItemType&)) const
{
  preorder(visit, rootPtr);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType,ItemType>::postorderTraverse(void visit(ItemType&)) const
{
  postorder(visit, rootPtr);
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType,ItemType>& BinarySearchTree<KeyType,ItemType>::operator=(const BinarySearchTree<KeyType,ItemType>& rightHandSide)
{
  rootPtr=copyTree(rightHandSide.rootPtr);
}

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType,ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{
  BinaryNode<ItemType>* sample=nullptr;
  if(treePtr!=nullptr)
  {
    sample=new BinaryNode<ItemType>(treePtr->getItem());
    sample->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
    sample->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
  }
  return(sample);
}

template<typename KeyType, typename ItemType>
 void BinarySearchTree<KeyType,ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
 {
   if(subTreePtr!=nullptr)
   {
     destroyTree(subTreePtr->getLeftChildPtr());
     destroyTree(subTreePtr->getRightChildPtr());
     delete subTreePtr;
   }
 }
