/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 268 Lab 04 Exercise 3
 * @Date: 10/01/2018
 * @Brief: This program is the Executive.cpp file for the lab. It saves the flag and number
 */

#include "Executive.h"
#include <iostream>
#include <string>
#include <cstring>
#include <time.h>
using namespace std;

Executive::Executive(int size, string order, string method)
{
  m_size = size;
  m_order = order;
  m_method = method;
  //srand48(time(NULL));
}

void Executive::run()
{
  cout<<'\n';
  double number = 0.0;

  //srand(time(NULL));
  m_arr = new double[m_size];
  for(int i=0; i<m_size; i++)
  {
    if(m_order == "ascending")
    {
      m_arr[i] = 0.001*static_cast<double>(i);
    }

    else if(m_order == "descending")
    {
      m_arr[i] = 0.001*static_cast<double>(m_size - i - 1);
    }

    else if(m_order == "random")
    {

      number = drand48()*100000;
      m_arr[i] = number;
    }
  }

  cout<<"Size: "<<m_size<<'\n';
  cout<<"Sorting Algorithm: "<<m_method<<'\n';
  cout<<"Initial Array Condition: "<<m_order<<'\n';
  cout<<"Time Taken to Perform Sort: ";
  if(m_method == "selection")
  {
    clock_t start = clock();
    selectionSort(m_arr, m_size);
    clock_t end = clock();
    double time = (double)(end-start) / CLOCKS_PER_SEC;
    cout<<time;
  }

  else if(m_method == "insertion")
  {
    clock_t start = clock();
    insertionSort(m_arr, m_size);
    clock_t end = clock();
    double time = (double)(end-start) / CLOCKS_PER_SEC;
    cout<<time;
  }

  else if(m_method == "bubble")
  {
    clock_t start = clock();
    bubbleSort(m_arr, m_size);
    clock_t end = clock();
    double time = (double)(end-start) / CLOCKS_PER_SEC;
    cout<<time;
  }

  else if(m_method == "merge")
  {
    clock_t start = clock();
    mergeSort(m_arr, m_size);
    clock_t end = clock();
    double time = (double)(end-start) / CLOCKS_PER_SEC;
    cout<<time;
  }

  else if(m_method == "quick")
  {
    clock_t start = clock();
    quickSort(m_arr, 0, m_size-1);
    clock_t end = clock();
    double time = (double)(end-start) / CLOCKS_PER_SEC;
    cout<<time;
  }

  cout<<' '<<"seconds"<<"\n\n";
}

Executive::~Executive()
{
  delete[] m_arr;
}

//divide clock ticks by clock per second
