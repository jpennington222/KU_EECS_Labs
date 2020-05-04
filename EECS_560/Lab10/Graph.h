/*
 * @Author: Joseph Pennington
 * @File Name: Graph.h
 * @Assignment: EECS 560 Lab 10
 * @Brief: This program is the header file for the Graph Class.
 */

#ifndef GRAPH_H
#define GRAPH_H

#include"Edge.h"
#include"minHeap.h"
#include"Vertex.h"
#include<iostream>
using namespace std;

class Graph
{
  public:

    /*
		* @pre: none
		* @post: Graph object made
		* @param array: Matrix from file
    * @param size: Size of the array
		* @return: none
		*/

    Graph(int** array, int size);

    /*
		* @pre: Graph made
		* @post: Graph is deleted
		* @return: none
		*/

    ~Graph();

    /*
		* @pre: Graph made
		* @post: MST is computed
		* @param m_names: Names of dinosaurs
		* @return: none
		*/

    void Kruskal(string m_names[]);

    /*
		* @pre: Graph made
		* @post: MST is computed
		* @param m_names: Names of dinosaurs
		* @return: none
		*/

    void Prim(string m_names[]);

    /*
		* @pre: Graph made
		* @post: BFS path, tree edges, and cross edges computed
		* @param m_names: Names of dinosaurs
		* @return: none
		*/

    void BFS(string m_names[]);

    /*
		* @pre: Graph made
		* @post: BFS path, tree edges, and back edges computed
		* @param m_names: Names of dinosaurs
		* @return: none
		*/

    void DFS(string m_names[]);
  private:

    //Edge pointer
    Edge* m_edges;

    //Size
    int m_size;

    //Current edge cost
    int currentEdges;
};
#endif
