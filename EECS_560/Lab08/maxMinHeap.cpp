/*
 * @Author: Joseph Pennington
 * @File Name: maxMinHeap.cpp
 * @Assignment: EECS 560 Lab 08
 * @Brief: This is the cpp file for the maxMinHeap class.
 */

#include "BSTEntry.h"
using namespace std;

template<typename T>
maxMinHeap<T>::maxMinHeap()
{
  itemCount = 0;
}

template<typename T>
maxMinHeap<T>::~maxMinHeap()
{

}

template<typename T>
void maxMinHeap<T>::heapify()
{
  for(int x = lastParent(); x >= 1; x--){
    int xFloor = log2(x);
    if(xFloor % 2 == 0){
      swapMax(x);
    }
    else{
      swapMin(x);
    }
  }
}

template<typename T>
void maxMinHeap<T>::swapMin(int parent)
{
  int childOne =2*parent;
  int childTwo =2*parent+1;
  if(minGrandChild(parent) != -1)
  {
    if(m_arr[minGrandChild(parent)].getKey() < m_arr[min(childOne, childTwo)].getKey())
    {
      if(m_arr[minGrandChild(parent)].getKey() < m_arr[parent].getKey())
      {
        swapLocations(minGrandChild(parent), parent);
        if(m_arr[minGrandChild(parent)].getKey() > m_arr[minGrandChild(parent)/2].getKey())
        {
          swapLocations(minGrandChild(parent), minGrandChild(parent)/2);
        }
        swapMin(minGrandChild(parent));
      }
    }
    else if (m_arr[parent].getKey() > m_arr[min(childOne, childTwo)].getKey())
    {
      swapLocations(parent, min(childOne, childTwo));
    }
  }
  else if(childTwo <= itemCount)
  {
    if(m_arr[parent].getKey() > m_arr[min(childOne, childTwo)].getKey())
    {
      swapLocations(parent, min(childOne, childTwo));
    }
  }
  else if(childOne<=itemCount)
  {
    if(m_arr[childOne].getKey() < m_arr[parent].getKey())
    {
      swapLocations(childOne, parent);
    }
  }
}

template<typename T>
void maxMinHeap<T>::swapMax(int parent)
{
  int childOne =2*parent;
  int childTwo =2*parent+1;
  if(maxGrandChild(parent) != -1)
  {
    if(m_arr[maxGrandChild(parent)].getKey() > m_arr[max(childOne, childTwo)].getKey())
    {
      if(m_arr[maxGrandChild(parent)].getKey() > m_arr[parent].getKey())
      {
        swapLocations(maxGrandChild(parent), parent);
        if(m_arr[maxGrandChild(parent)].getKey() < m_arr[maxGrandChild(parent)/2].getKey())
        {
          swapLocations(maxGrandChild(parent), maxGrandChild(parent)/2);
        }
        swapMax(maxGrandChild(parent));
      }
    }
    else if (m_arr[parent].getKey()  < m_arr[max(childOne, childTwo)].getKey())
    {
      swapLocations(parent, max(childOne, childTwo));
    }
  }
  else if(childTwo <= itemCount)
  {
    if(m_arr[parent].getKey() < m_arr[max(childOne, childTwo)].getKey())
    {
      swapLocations(parent, max(childOne, childTwo));
    }
  }
  else if(childOne<=itemCount)
  {
    if(m_arr[childOne].getKey() > m_arr[parent].getKey())
    {
      swapLocations(childOne, parent);
    }
  }
}

template<typename T>
int maxMinHeap<T>::min(int entryOne, int entryTwo)
{
  if(m_arr[entryOne].getKey()<m_arr[entryTwo].getKey()){
    return entryOne;
  }
  return entryTwo;
}

template<typename T>
int maxMinHeap<T>::max(int entryOne, int entryTwo)
{
  if(m_arr[entryOne].getKey() > m_arr[entryTwo].getKey()){
    return entryOne;
  }
  return entryTwo;
}

template<typename T>
int maxMinHeap<T>::minGrandChild(int parent)
{

  int first = 4*parent;
  int second = 4*parent+1;
  int third = 4*parent+2;
  int fourth = 4*parent+3;

  int min = -1;
  if(first<=itemCount)
  {
    min = first;
  }
  else
  {
    return -1;
  }
  if(second<=itemCount)
  {
    if(m_arr[second].getKey() < m_arr[min].getKey())
    {
      min = second;
    }
  }
  if(third<=itemCount)
  {
    if(m_arr[third].getKey() < m_arr[min].getKey())
    {
      min = third;
    }
  }
  if(fourth<=itemCount)
  {
    if(m_arr[fourth].getKey() < m_arr[min].getKey())
    {
      min = fourth;
    }
  }
  return min;
}

template<typename T>
int maxMinHeap<T>::maxGrandChild(int parent){
  int first = 4*parent;
  int second = 4*parent+1;
  int third = 4*parent+2;
  int fourth = 4*parent+3;

  int max = -1;
  if(first<=itemCount)
  {
    max = first;
  }
  else
  {
    return -1;
  }
  if(second<=itemCount)
  {
    if(m_arr[second].getKey() >m_arr[max].getKey())
    {
      max = second;
    }
  }
  if(third<=itemCount)
  {
    if(m_arr[third].getKey() > m_arr[max].getKey())
    {
      max = third;
    }
  }
  if(fourth<=itemCount)
  {
    if(m_arr[fourth].getKey() > m_arr[max].getKey())
    {
      max = fourth;
    }
  }
  return max;
}


template<typename T>
void maxMinHeap<T>::swapLocations(int one, int two)
{
  T temp = m_arr[one];
  m_arr[one] = m_arr[two];
  m_arr[two] = temp;
}

template<typename T>
void maxMinHeap<T>::insert(T entry)
{
  added = true;
  for(int i=0; i<itemCount; i++)
  {
    if(m_arr[i].getName() == entry.getName())
    {
      cout << "The name of the game is already in the heap\n";
      added = false;
      return;
    }
  }
  itemCount++;
  m_arr[itemCount]= entry;
  heapify();
}

template<typename T>
void maxMinHeap<T>::deleteLocation(int location)
{
  m_arr[location]=m_arr[itemCount];
  itemCount--;

  int height = log2(location);
  if(height % 2 == 0)
  {
    swapMax(location);
  }
  else
  {
    swapMin(location);
  }

}

template<typename T>
int maxMinHeap<T>::getItemCount()
{
  return itemCount;
}

template<typename T>
bool maxMinHeap<T>::getAdded()
{
  return added;
}

template<typename T>
int maxMinHeap<T>::lastParent()
{
  return (itemCount/2);
}

template<typename T>
bool maxMinHeap<T>::generalDelete(string name, int key)
{
  if(itemCount==0)
  {
    return(false);
  }
  for(int i=0; i<itemCount; i++)
  {
    if(m_arr[i].getName() == name && m_arr[i].getKey() == key)
    {
      deleteLocation(i);
      cout << name << " with " << key << "k downloads successfully removed\n";
      return(true);
    }
  }
  cout << "Game not found\n";
  return(false);
}

template<typename T>
bool maxMinHeap<T>::deleteMax()
{
  if(itemCount==0)
  {
    return false;
  }
  cout << m_arr[1].getName() << " " << m_arr[1].getKey() << '\n';
  deleteLocation(1);
  return true;
}

template<typename T>
T maxMinHeap<T>::findMin()
{
  if(itemCount==1)
  {
    return m_arr[1];
  }
  if(m_arr[2].getKey() < m_arr[3].getKey())
  {
    return(m_arr[2]);
  }
  else
  {
    return(m_arr[3]);
  }
}

template<typename T>
T maxMinHeap<T>::findMax()
{
  return m_arr[1];
}

template<typename T>
void maxMinHeap<T>::levelOrder()
{
  if(itemCount!=0)
  {
    cout << m_arr[1].getKey() << endl;
    for(int i = 1; i <= log2(itemCount); i++)
    {
      int level = pow(2,i);
      int levelAbove = level*2;
      for(int i = level; i <= itemCount && i < levelAbove; i++)
      {
        cout<< m_arr[i].getKey() << "\t";
      }
      cout<<endl;
    }
  }
  else
  {
    cout << "Heap is empty\n";
  }
}

template<typename T>
void maxMinHeap<T>::printMins()
{
  if(itemCount!=0)
  {
    for(int i = 1; i <= log2(itemCount); i++)
    {
      int level = pow(2,i);
      int levelAbove = level*2;
      for(int i = level; i <= itemCount && i < levelAbove; i++)
      {
        if(level == 2 || level == 8 || level == 32 || level == 128 || level == 512)
        {
          cout<< m_arr[i].getName() << " ";
        }
      }
    }
  }
  else
  {
    cout << "Heap is empty\n";
  }
}

template<typename T>
void maxMinHeap<T>::printMaxs()
{
  if(itemCount!=0)
  {
    cout << m_arr[1].getName() << " ";
    for(int i = 1; i <= log2(itemCount); i++)
    {
      int level = pow(2,i);
      int levelAbove = level*2;
      for(int i = level; i <= itemCount && i < levelAbove; i++)
      {
        if(level == 4 || level == 16 || level == 64 || level == 256 || level == 1024)
        {
          cout<< m_arr[i].getName() << " ";
        }
      }
    }
  }
  else
  {
    cout << "Heap is empty\n";
  }
}

template<typename T>
int maxMinHeap<T>::totalMins()
{
  int total = 0;
  if(itemCount!=0)
  {
    for(int i = 1; i <= log2(itemCount); i++)
    {
      int level = pow(2,i);
      int levelAbove = level*2;
      for(int i = level; i <= itemCount && i < levelAbove; i++)
      {
        if(level == 2 || level == 8 || level == 32 || level == 128 || level == 512)
        {
          total = total + m_arr[i].getKey();
        }
      }
    }
  }
  else
  {
    cout << "Heap is empty\n";
  }
  return(total);
}

template<typename T>
int maxMinHeap<T>::totalMaxs()
{
  int total = 0;
  if(itemCount!=0)
  {
    total = total + m_arr[1].getKey();
    for(int i = 1; i <= log2(itemCount); i++)
    {
      int level = pow(2,i);
      int levelAbove = level*2;
      for(int i = level; i <= itemCount && i < levelAbove; i++)
      {
        if(level == 4 || level == 16 || level == 64 || level == 256 || level == 1024)
        {
          total = total + m_arr[i].getKey();
        }
      }
    }
  }
  else
  {
    cout << "Heap is empty\n";
  }
  return(total);
}

template<typename T>
bool maxMinHeap<T>::isEmpty()
{
  return(itemCount==0);
}
