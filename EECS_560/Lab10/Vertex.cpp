/*
 * @Author: Joseph Pennington
 * @File Name: Vertex.cpp
 * @Assignment: EECS 560 Lab 10
 * @Brief: Implementation file for the Vertex class
 */

#include "Vertex.h"

Vertex::Vertex(int num)
{
    m_connections = 0;
    m_traversed = false;
    m_number = num;
}

int Vertex::getNum()
{
  return m_number;
}

void Vertex::BFS(Edge* arr, int& index)
{
    for(int i = 0; i < m_connections; i++)
    {
        if(alreadyConnected[i]->m_traversed != true)
        {
            alreadyConnected[i]->m_traversed = true;
            Edge temp(m_number, alreadyConnected[i]->m_number, 0);
            arr[index] = temp;
            index++;
        }
    }
    for(int i = 0; i < m_connections; i++)
    {
        alreadyConnected[i]->BFS(arr, index);
    }
}

int Vertex::DFS(Edge* arr)
{
    int index = 0;
    m_traversed = true;
    for(int i = 0; i < m_connections; i++)
    {
        alreadyConnected[i]->DFS(this, arr, index);
    }
    return index;
}

void Vertex::DFS(Vertex* v, Edge* arr, int& index)
{
    if(m_traversed==false)
    {
        Edge temp(v->m_number, m_number,0);
        arr[index] = temp;
        index=index+1;
        m_traversed = true;
        for(int i = 0; i < m_connections; i++)
        {
            alreadyConnected[i]->DFS(this, arr, index);
        }
    }
}

void Vertex::connectTo(Vertex* v)
{
    for(int i = 0; i < m_connections; i++)
    {
        if(alreadyConnected[i] == v)
        {
            return;
        }
    }
    alreadyConnected[m_connections] = v;
    m_connections=m_connections+1;
}

int Vertex::BFS(Edge* arr)
{
    int arrIndex = 0;
    m_traversed = true;
    for(int i = 0; i < m_connections; i++)
    {
        alreadyConnected[i]->m_traversed = true;
        Edge temp(m_number, alreadyConnected[i]->m_number, 0);
        arr[arrIndex] = temp;
        arrIndex++;
    }
    for(int i = 0; i < m_connections; i++)
    {
        alreadyConnected[i]->BFS(arr, arrIndex);
    }
    return arrIndex;
}
