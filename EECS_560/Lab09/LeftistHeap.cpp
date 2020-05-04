/*
 * @Author: Joseph Pennington
 * @File Name: LeftistHeap.cpp
 * @Assignment: EECS 560 Lab 09
 * @Brief: This program is the cpp file for the LeftistHeap class.
 */

template<typename ItemType, typename SearchType>
LeftistHeap<ItemType, SearchType>::LeftistHeap()
{
  m_root=nullptr;
}


template<typename ItemType, typename SearchType>
bool LeftistHeap<ItemType, SearchType>::add(ItemType item)
{
  m_root= merge(m_root, new BinaryNode<ItemType>(item));
  return true;
}

template<typename ItemType, typename SearchType>
LeftistHeap<ItemType, SearchType>::~LeftistHeap()
{
  recDestroy(m_root);
}

template<typename ItemType, typename SearchType>
void LeftistHeap<ItemType, SearchType>::recDestroy(BinaryNode<ItemType>* start)
{
  if(start!=nullptr)
  {
    recDestroy(start->getLeft());
    recDestroy(start->getRight());
    delete start;
  }
}

template<typename ItemType, typename SearchType>
BinaryNode<ItemType>* LeftistHeap<ItemType, SearchType>::getRoot()
{
  return(m_root);
}

template<typename ItemType, typename SearchType>
void LeftistHeap<ItemType, SearchType>::levelOrder()const
{
  int i=0;
  while(level(m_root, i))
  {
    i++;
  }
}

template<typename ItemType, typename SearchType>
bool LeftistHeap<ItemType, SearchType>::level(const BinaryNode<ItemType>* tree, int i)const
{
  if(tree==nullptr)
  {
    return false;
  }

  if(i==0)
  {
    cout<<tree->getEntry()<<" ";
    return true;
  }

  bool left = level(tree->getLeft(), i-1);
  bool right = level(tree->getRight(), i-1);
  return left || right;
}

template<typename ItemType, typename SearchType>
BinaryNode<ItemType>* LeftistHeap<ItemType, SearchType>::merge(BinaryNode<ItemType>* h1, BinaryNode<ItemType>* h2)
{
  if(h1==nullptr)
  {
    return h2;
  }

  if(h2==nullptr)
  {
    return h1;
  }

  if(h1->getEntry() > h2->getEntry())
  {
    BinaryNode<ItemType>* temp = h1;
    h1 = h2;
    h2 = temp;
  }

  if(h1->getLeft() == nullptr)
  {
    h1->setLeft(h2);
  }

  else
  {
    h1->setRight(merge(h1->getRight(), h2));
  }

  if(getRank(h1->getLeft()) < getRank(h1->getRight()))
  {
    BinaryNode<ItemType>* temp2 = h1->getRight();
    h1->setRight(h1->getLeft());
    h1->setLeft(temp2);
  }
  return h1;
}

template<typename ItemType, typename SearchType>
int LeftistHeap<ItemType, SearchType>::getRank(BinaryNode<ItemType>* node)
{
  if(node==nullptr)
  {
    return 0;
  }

  else
  {
    return (getRank(node->getRight())+1);
  }
}

template<typename ItemType, typename SearchType>
bool LeftistHeap<ItemType, SearchType>::removeMin()
{
  if(m_root==nullptr)
  {
    return false;
  }

  else
  {
    BinaryNode<ItemType>* temp = m_root;
    m_root = merge(m_root->getLeft(), m_root->getRight());
    delete temp;
  }
  return true;
}
