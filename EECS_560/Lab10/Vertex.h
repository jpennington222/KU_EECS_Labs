/*
 * @Author: Joseph Pennington
 * @File Name: Vertex.h
 * @Assignment: EECS 560 Lab 10
 * @Brief: This program is the header file for the Vertex Class.
 */

#ifndef VERTEX_H
#define VERTEX_H
#include<iostream>
#include"Edge.h"
using namespace std;
class Vertex
{
  public:

    /*
		* @pre: Graph made
		* @post: Vertex made
    * @param num: Vertex number
		* @return: none
		*/

    Vertex(int num);

    /*
		* @pre: Graph made
		* @post: Gets vertex number
		* @return: m_number
		*/

    int getNum();

    /*
		* @pre: Graph made
		* @post: Connects vertices
    * @param v: Vertex
		* @return: none
		*/

    void connectTo(Vertex* v);

    /*
		* @pre: Graph made
		* @post: Determines if vertex was visited
    * @param arr: Array of edges
		* @return: Current index
		*/

    int BFS(Edge* arr);

    /*
		* @pre: Graph made
		* @post: Finds connections
    * @param arr: Array of edges
    * @index: Current index
		* @return: none
		*/

    void BFS(Edge* arr, int& index);

    /*
		* @pre: Graph made
		* @post: Determines if vertex was visited
    * @param arr: Array of edges
		* @return: Current index
		*/

    int DFS(Edge* arr);

    /*
		* @pre: Graph made
		* @post: Finds connections
    * @param v: Current vertex
    * @param arr: Array of edges
    * @param index: Current index
    * @index: Current index
		* @return: none
		*/

    void DFS(Vertex* v, Edge* arr, int& index);

    //If vertex was visited
    bool m_traversed;

    //If vertices were already connected
    Vertex* alreadyConnected[100];

  private:
    //Vertex number
    int m_number;

    //Number of connections at a vertex
    int m_connections;
};
#endif
