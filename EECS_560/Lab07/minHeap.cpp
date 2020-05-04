/*
 * @Author: Joseph Pennington
 * @File Name: minHeap.cpp
 * @Assignment: EECS 560 Lab 07
 * @Brief: This program is the cpp file for the minHeap class.
 */

#include "BSTEntry.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

template<typename T>
minHeap<T>::minHeap()
{
  itemCount = 0;
}
template<typename T>
minHeap<T>::~minHeap()
{

}
template<typename T>
void minHeap<T>::buildHeap(std::string filename)
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
void minHeap<T>::heapify()
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
void minHeap<T>::swap(int parent){
  int minValue = m_arr[3*parent+1].getKey();
  int location = 3*parent+1;
  for(int i=2; i<=3; i++){
    if((3*parent)+i<itemCount){
      if(m_arr[3*parent+i].getKey()<minValue){
        minValue = m_arr[3*parent+i].getKey();
        location= 3*parent + i;
      }
    }
  }
  if(minValue<m_arr[parent].getKey()){
    BSTEntry temp = m_arr[parent];
    m_arr[parent]=m_arr[location];
    m_arr[location] = temp;
  }
}

template<typename T>
void minHeap<T>::insert(T entry)
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
    if(entry.getKey() > 25)
    {
      cout << "Entry Not Added. Too many patients\n";
      added = false;
      return;
    }
  }
  m_arr[itemCount] = entry;
  itemCount++;
}

template<typename T>
int minHeap<T>::getParent(int childLocation)
{
  if(((childLocation-1)/3)<0){
    return -1;
  }
  return ((childLocation-1)/3);
}

template<typename T>
int minHeap<T>::getFirstChild(int parentLocation)
{
  if(((3*parentLocation)+1)>itemCount-1){
    return -1;
  }
  return ((3*parentLocation)+1);
}

template<typename T>
int minHeap<T>::numberOfChildren(int parentLocation)
{
  if((itemCount - getFirstChild(parentLocation))>3){
    return 3;
  }
  return (itemCount-getFirstChild(parentLocation));
}

template<typename T>
int minHeap<T>::firstLeafLocation()
{
  return (((itemCount-2)/3)+1);
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

// template<typename T>
// bool minHeap<T>::deleteMax()
// {
//   if(itemCount==0){
//     return false;
//   }
//   BSTEntry firstLeaf = m_arr[firstLeafLocation()];
//   int maxLocation = firstLeafLocation();
//   for(int i=firstLeafLocation(); i<itemCount; i++){
//     if(m_arr[i].getKey()>firstLeaf.getKey()){
//       firstLeaf = m_arr[i];
//       maxLocation = i;
//     }
//   }
//   m_arr[maxLocation]= m_arr[itemCount-1];
//   itemCount--;
//   heapify();
//   return true;
// }

template<typename T>
bool minHeap<T>::deleteMin()
{
  if(itemCount==0){
    return false;
  }
  cout << "Doctor with lowest patient count successfully removed\n";
  cout << "Doctor Details: " << m_arr[0].getFirst() <<", "<<m_arr[0].getLast()<<", "<<m_arr[0].getKey()<<'\n';
  m_arr[0]= m_arr[itemCount-1];
  itemCount--;
  heapify();
  return true;
}

template<typename T>
void minHeap<T>::findMax()
{
  BSTEntry firstLeaf = m_arr[firstLeafLocation()];
  int maxLocation = firstLeafLocation();
  for(int i=firstLeafLocation(); i<itemCount; i++){
    if(m_arr[i].getKey()>firstLeaf.getKey()){
      firstLeaf = m_arr[i];
      maxLocation = i;
    }
  }
  cout << m_arr[maxLocation].getFirst() << '\n';
}

template<typename T>
void minHeap<T>::findMin()
{
  cout << "The next available doctor is: ";
  cout<<m_arr[0].getFirst()<<", " << m_arr[0].getLast() << ", " << m_arr[0].getKey()<<'\n';
}

template<typename T>
void minHeap<T>::levelOrderAvailable()
{
  if(m_arr[0].getKey() < 22)
  {
    cout<<m_arr[0].getFirst()<<", " << m_arr[0].getLast() << ", " << m_arr[0].getKey()<<'\n';
  }

  int i=1;
  while(i<itemCount && i<4){
    if(m_arr[i].getKey() < 22){
    cout<<m_arr[i].getFirst()<<", " << m_arr[i].getLast() << ", " << m_arr[i].getKey() << '\n';
    }
    i++;
  }

  int j=4;
  while(j<itemCount && j<10){
    if(m_arr[j].getKey() < 22){
    cout<<m_arr[j].getFirst()<<", " << m_arr[j].getLast() << ", " << m_arr[j].getKey() << '\n';
    }
    j++;
  }

  int x=10;
  while(x<itemCount && x<28){
    if(m_arr[x].getKey() < 22){
    cout<<m_arr[x].getFirst()<<", " << m_arr[x].getLast() << ", " << m_arr[x].getKey() << '\n';
    }
    x++;
  }

  int y=28;
  while(y<itemCount && y<=82){
    if(m_arr[y].getKey() < 22){
    cout<<m_arr[y].getFirst()<<", " << m_arr[y].getLast() << ", " << m_arr[y].getKey() << '\n';
    }
    y++;
  }
}

template<typename T>
void minHeap<T>::levelOrderBusy()
{
  if(m_arr[0].getKey() >= 22)
  {
    cout<<m_arr[0].getFirst()<<", " << m_arr[0].getLast() << ", " << m_arr[0].getKey()<<'\n';
  }

  int i=1;
  while(i<itemCount && i<4){
    if(m_arr[i].getKey() >= 22){
    cout<<m_arr[i].getFirst()<<", " << m_arr[i].getLast() << ", " << m_arr[i].getKey() << '\n';
    }
    i++;
  }

  int j=4;
  while(j<itemCount && j<10){
    if(m_arr[j].getKey() >= 22){
    cout<<m_arr[j].getFirst()<<", " << m_arr[j].getLast() << ", " << m_arr[j].getKey() << '\n';
    }
    j++;
  }

  int x=10;
  while(x<itemCount && x<28){
    if(m_arr[x].getKey() >= 22){
    cout<<m_arr[x].getFirst()<<", " << m_arr[x].getLast() << ", " << m_arr[x].getKey() << '\n';
    }
    x++;
  }

  int y=28;
  while(y<itemCount && y<=82){
    if(m_arr[y].getKey() >= 22){
    cout<<m_arr[y].getFirst()<<", " << m_arr[y].getLast() << ", " << m_arr[y].getKey() << '\n';
    }
    y++;
  }
}


template<typename T>
bool minHeap<T>::getAdded()
{
  return(added);
}

template<typename T>
int minHeap<T>::getItemCount()
{
  return(itemCount);
}

template<typename T>
bool minHeap<T>::checkDoctor(string first, string last)
{
  for(int i = 0; i<itemCount; i++)
  {
    if(first == m_arr[i].getFirst() && last == m_arr[i].getLast() && m_arr[i].getKey() < 22)
    {
      return(true);
    }
  }
  return(false);
}

template<typename T>
int minHeap<T>::availableDoctorCount()
{
  int count = 0;
  for(int i = 0; i<itemCount; i++)
  {
    if(m_arr[i].getKey() < 22)
    {
      count++;
    }
  }
  return(count);
}

template<typename T>
int minHeap<T>::current(string first, string last)
{
  for(int i = 0; i<itemCount; i++)
  {
    if(first == m_arr[i].getFirst() && last == m_arr[i].getLast())
    {
      cout << "Current Patient Count: " << m_arr[i].getKey() << '\n';
      return(m_arr[i].getKey());
    }
  }
  cout << "Doctor not found\n";
  return(-1);
}

template<typename T>
void minHeap<T>::deleteEntry(T entry)
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
