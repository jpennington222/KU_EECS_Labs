/*
 * @Author: Joseph Pennington
 * @File Name: maxHeap.cpp
 * @Assignment: EECS 560 Lab 07
 * @Brief: This program is the cpp file for the maxHeap class.
 */

#include "BSTEntry.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

template<typename T>
maxHeap<T>::maxHeap()
{
  itemCount = 0;
}
template<typename T>
maxHeap<T>::~maxHeap()
{

}
template<typename T>
void maxHeap<T>::buildHeap(std::string filename)
{
  ifstream inFile;
  string tempFirst;
  string tempLast;
  string tempKey;
  string temp;

  inFile.open(filename);
  while(inFile >> temp)
  {
    bool comma1 = false;
    bool comma2 = false;
    int tempSize = temp.size();
    for(int i = 0; i < tempSize; i++)
    {
      if(temp[i] != ',' && comma1 == false)
      {
        tempFirst = tempFirst + temp[i];
      }

      else if(temp[i] == ',' && comma1 == false)
      {
        comma1 = true;
      }

      else if(temp[i] != ',' && comma1 == true && comma2 == false)
      {
        tempLast = tempLast + temp[i];
      }
      else if(temp[i] == ',' && comma1 == true && comma2 == false)
      {
        comma2 = true;
      }
      else if(comma1 == true && comma2 == true)
      {
        tempKey = tempKey + temp[i];
      }
    }

    int numberKey = stoi(tempKey);

    BSTEntry bste(tempFirst, tempLast, numberKey);
    //cout << bste.getFirst() <<" "<< bste.getLast() <<" "<<bste.getKey() << '\n';
    insert(bste);

    temp == "";
    tempFirst = "";
    tempLast = "";
    tempKey = "";
  }
  heapify();
  inFile.close();
}

template<typename T>
void maxHeap<T>::heapify()
{
  int startValue = lastParent();
  for(int x = startValue; x>=0; x--){
    swap(x);
  }
  for(int j=0; j<=lastParent(); j++){
    swap(j);
  }
}

template<typename T>
void maxHeap<T>::swap(int parent){
  int maxValue = m_arr[3*parent+1].getKey();
  int location = 3*parent+1;
  for(int i=2; i<=3; i++){
    if((3*parent)+i<itemCount){
      if(m_arr[3*parent+i].getKey()>maxValue){
        maxValue = m_arr[3*parent+i].getKey();
        location= 3*parent + i;
      }
    }
  }
  if(maxValue>m_arr[parent].getKey()){
    BSTEntry temp = m_arr[parent];
    m_arr[parent]=m_arr[location];
    m_arr[location]= temp;
  }
}

template<typename T>
void maxHeap<T>::insert(T entry)
{
  added = true;
  for(int i = 0; i<itemCount; i++)
  {
    if(entry.getFirst() == m_arr[i].getFirst() && entry.getLast() == m_arr[i].getLast())
    {
      cout << "Entry Not Added. Duplicate Entry\n";
      added = false;
      return;
    }
  }
  m_arr[itemCount] = entry;
  itemCount++;
}

template<typename T>
int maxHeap<T>::getParent(int childLocation)
{
  if(((childLocation-1)/3)<0){
    return -1;
  }
  return ((childLocation-1)/3);
}

template<typename T>
int maxHeap<T>::getFirstChild(int parentLocation)
{
  if(((3*parentLocation)+1)>itemCount-1){
    return -1;
  }
  return ((3*parentLocation)+1);
}

template<typename T>
int maxHeap<T>::numberOfChildren(int parentLocation)
{
  if((itemCount - getFirstChild(parentLocation))>3){
    return 3;
  }
  return (itemCount-getFirstChild(parentLocation));
}

template<typename T>
int maxHeap<T>::firstLeafLocation()
{
  return (((itemCount-2)/3)+1);
}

template<typename T>
int maxHeap<T>::lastParent()
{
  return firstLeafLocation()-1;
}

template<typename T>
bool maxHeap<T>::isParent(int location)
{
  return (getFirstChild(location)!=-1);
}

template<typename T>
bool maxHeap<T>::isLeaf(int location)
{
  return (getFirstChild(location)==-1);
}

template<typename T>
bool maxHeap<T>::deleteMin()
{
  if(itemCount==0){
    return false;
  }
  int firstLeaf = m_arr[firstLeafLocation()].getKey();
  int maxLocation = firstLeafLocation();
  for(int i=firstLeafLocation(); i<itemCount; i++){
    if(m_arr[i].getKey()<firstLeaf){
      firstLeaf = m_arr[i];
      maxLocation = i;
    }
  }
  m_arr[maxLocation]= m_arr[itemCount-1];
  itemCount--;
  heapify();
  return true;
}

template<typename T>
bool maxHeap<T>::deleteMax()
{
  if(itemCount==0){
    return false;
  }
  cout << "High priority patient successfully treated\n";
  cout << "Patient Details: " << m_arr[0].getFirst() <<", "<<m_arr[0].getLast()<<", "<<m_arr[0].getKey()<<'\n';
  m_arr[0]= m_arr[itemCount-1];
  itemCount--;
  heapify();
  return true;
}

template<typename T>
void maxHeap<T>::findMin()
{
  BSTEntry firstLeaf = m_arr[firstLeafLocation()];
  int maxLocation = firstLeafLocation();
  for(int i=firstLeafLocation(); i<itemCount; i++){
    if(m_arr[i].getKey()<firstLeaf.getKey()){
      firstLeaf = m_arr[i];
      maxLocation = i;
    }
  }
  cout << "Last Patient Details: ";
  cout << m_arr[maxLocation].getFirst()<<", "<<m_arr[maxLocation].getLast()<<", "<<m_arr[maxLocation].getKey()<<'\n';

}

template<typename T>
void maxHeap<T>::findMax()
{
  cout << "Next Patient: ";
  cout<<m_arr[0].getFirst()<<", " << m_arr[0].getLast() << ", " << m_arr[0].getKey()<<'\n';
}

template<typename T>
void maxHeap<T>::levelOrder()
{
  cout<<m_arr[0].getFirst()<<", " << m_arr[0].getLast() << ", " << m_arr[0].getKey()<<'\n';
  int i=1;
  while(i<itemCount && i<4){
    cout<<m_arr[i].getFirst()<<", " << m_arr[i].getLast() << ", " << m_arr[i].getKey() << '\n';
    i++;
  }

  int j=4;
  while(j<itemCount && j<10){
    cout<<m_arr[j].getFirst()<<", " << m_arr[j].getLast() << ", " << m_arr[j].getKey() << '\n';
    j++;
  }

  int x=10;
  while(x<itemCount && x<28){
    cout<<m_arr[x].getFirst()<<", " << m_arr[x].getLast() << ", " << m_arr[x].getKey() << '\n';
    x++;
  }

  int y=28;
  while(y<itemCount && y<=82){
    cout<<m_arr[y].getFirst()<<", " << m_arr[y].getLast() << ", " << m_arr[y].getKey() << '\n';
    y++;
  }

}


template<typename T>
bool maxHeap<T>::getAdded()
{
  return(added);
}

template<typename T>
int maxHeap<T>::getItemCount()
{
  return(itemCount);
}

template<typename T>
int maxHeap<T>::position(string first, string last)
{
  BSTEntry temp[500];
  for(int i = 0; i<itemCount; i++)
  {
    temp[i] = m_arr[i];
  }

  //sort
  BSTEntry bste("","",0);
  for(int i=0; i<itemCount; i++)
  {
    for(int j=0; j<itemCount-1; j++)
    {
      bste = temp[i];
      if(temp[i].getKey() < temp[j+1].getKey())
      {
        bste = temp[j];
        temp[j] = temp[j+1];
        temp[j+1] = bste;
      }
    }
  }

  for(int i = 0; i<itemCount; i++)
  {
    if(first == temp[i].getFirst() && last == temp[i].getLast())
    {
      return(i);
    }
  }
  return(-1);
}

template<typename T>
bool maxHeap<T>::current(string first, string last)
{
  for(int i = 0; i<itemCount; i++)
  {
    if(first == m_arr[i].getFirst() && last == m_arr[i].getLast())
    {
      cout << "Current Patient Details: ";
      cout<<m_arr[i].getFirst()<<", " << m_arr[i].getLast() << ", " << m_arr[i].getKey() << '\n';
      return(true);
    }
  }
  return(false);
}


template<typename T>
void maxHeap<T>::deleteEntry(T entry)
{
  for(int i = 0; i<itemCount; i++)
  {
    if(entry.getFirst() == m_arr[i].getFirst() && entry.getLast() == m_arr[i].getLast())
    {
      m_arr[i].setFirst(m_arr[itemCount-1].getFirst());
      m_arr[i].setLast(m_arr[itemCount-1].getLast());
      m_arr[i].setKey(m_arr[itemCount-1].getKey());


      m_arr[itemCount-1].setFirst(entry.getFirst());
      m_arr[itemCount-1].setLast(entry.getLast());
      m_arr[itemCount-1].setKey(entry.getKey());
      return;
    }
  }
  return;
}
