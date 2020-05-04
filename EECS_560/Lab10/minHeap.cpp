/*
 * @Author: Joseph Pennington
 * @File Name: minHeap.cpp
 * @Assignment: EECS 560 Lab 10
 * @Brief: Implementation file for the minHeap class
 */

#include<fstream>

template<typename T>
minHeap<T>::minHeap()
{
  m_arr = new T[1000];
  itemCount = 0;
}
template<typename T>
minHeap<T>::minHeap(T arr[], int size)
{
  m_arr = new T[1000];
  itemCount = size;
  for(int i=0; i<size; i++){
    m_arr[i]=arr[i];
  }
}
template<typename T>
minHeap<T>::~minHeap()
{
  delete[] m_arr;
}
template<typename T>
void minHeap<T>::buildHeap(char* filename)
{
  ifstream infile(filename);
  T temp = 0;
  while(infile >> temp){
    insert(temp);
  }
  heapify();
  infile.close();
}

template <typename T>
void minHeap<T>::downHeap(int index) {
  int minChild = index*5 + 1;

  if(minChild < itemCount) {
    for(int i = minChild + 1; i < minChild + 5 && i < itemCount; i++) {
      if(m_arr[minChild] > m_arr[i]) {
        minChild = i;
      }
    }

    if (m_arr[minChild] <  m_arr[index]) {
      T temp = m_arr[index];
      m_arr[index] = m_arr[minChild];
      m_arr[minChild] = temp;
      downHeap(minChild);
    }
  }
}


template<typename T>
void minHeap<T>::heapify()
{
  int startValue = lastParent();
  for(int x = startValue; x>=0; x--){
    downHeap(x);
  }
  //for(int j=0; j<=lastParent(); j++){
  //  swap(j);
  //}
}
template<typename T>
void minHeap<T>::swap(int parent){
  T minValue = m_arr[5*parent+1];
  int location = 5*parent+1;
  for(int i=2; i<=5; i++){
    if((5*parent)+i<itemCount){
      if(m_arr[5*parent+i]<minValue){
        minValue = m_arr[5*parent+i];
        location= 5*parent + i;
      }
    }
  }
  if(minValue<m_arr[parent]){
    T temp = m_arr[parent];
    m_arr[parent]=m_arr[location];
    m_arr[location] = temp;
  }
}

template<typename T>
bool minHeap<T>::isEmpty()
{
  return itemCount==0;
}

template<typename T>
void minHeap<T>::insert(T entry)
{
  m_arr[itemCount]= entry;
  itemCount++;
  heapify();
}

template<typename T>
int minHeap<T>::getParent(int childLocation)
{
  if(((childLocation-1)/5)<0){
    return -1;
  }
  return ((childLocation-1)/5);
}

template<typename T>
int minHeap<T>::getFirstChild(int parentLocation)
{
  if(((5*parentLocation)+1)>itemCount-1){
    return -1;
  }
  return ((5*parentLocation)+1);
}

template<typename T>
int minHeap<T>::numberOfChildren(int parentLocation)
{
  if((itemCount - getFirstChild(parentLocation))>5){
    return 5;
  }
  return (itemCount-getFirstChild(parentLocation));
}

template<typename T>
int minHeap<T>::firstLeafLocation()
{
  return ( ((itemCount-2) / 5)+1);
}

template<typename T>
int minHeap<T>::lastParent()
{
  return firstLeafLocation()-1;
}

template<typename T>
bool minHeap<T>::isParent(int location)
{
  return (getFirstChild(location)!=-1);
}

template<typename T>
bool minHeap<T>::isLeaf(int location)
{
  return (getFirstChild(location)==-1);
}

template<typename T>
bool minHeap<T>::deleteMax()
{
  if(itemCount==0){
    return false;
  }

  int firstLeafIndex = firstLeafLocation();
  int maxLocation = itemCount-1;
  for(int i = maxLocation-1; i >= firstLeafIndex; i--){
    if(m_arr[i]>m_arr[maxLocation]){
      maxLocation = i;
    }
  }
  m_arr[maxLocation]= m_arr[itemCount-1];
  itemCount--;
  downHeap(maxLocation);
  return true;
}

template<typename T>
bool minHeap<T>::deleteMin()
{
  if(itemCount==0){
    return false;
  }
  m_arr[0]= m_arr[itemCount-1];
  itemCount--;
  downHeap(0);
  return true;
}

template<typename T>
T minHeap<T>::findMax()
{
  T firstLeaf = m_arr[firstLeafLocation()];
  int maxLocation = firstLeafLocation();
  for(int i=firstLeafLocation(); i<itemCount; i++){
    if(m_arr[i]>firstLeaf){
      firstLeaf = m_arr[i];
      maxLocation = i;
    }
  }
  return m_arr[maxLocation];
}

template<typename T>
T minHeap<T>::findMin()
{
  return m_arr[0];
}

template<typename T>
void minHeap<T>::levelOrder()
{
  cout<<m_arr[0]<<endl;
  int i=1;
  while(i<itemCount && i<6){
    cout<<m_arr[i]<<"\t";
    i++;
  }
  cout<<endl;
  int j=6;
  while(j<itemCount && j<26){
    cout<<m_arr[j]<<"\t";
    j++;
  }
  cout<<endl;
  int x=26;
  while(x<itemCount && x<126){
    cout<<m_arr[x]<<"\t";
    x++;
  }
  cout<<endl;
  int y=126;
  while(y<itemCount && y<=500){
    cout<<m_arr[y]<<"\t";
    y++;
  }
  cout<<endl;
}

template<typename T>
void minHeap<T>::testPrint()
{
  for(int i =0; i<itemCount; i++){
    cout<<m_arr[i]<<"\t";
  }
  cout<<endl;
  cout<<findMin();
  cout<<endl<<findMax()<<endl;
  // cout<<itemCount<<endl;
  // cout<<firstLeafLocation()<<endl;
  // cout<<lastParent()<<endl;
  // levelOrder();
}
