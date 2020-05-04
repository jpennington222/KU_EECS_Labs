/*
 * @Author: Joseph Pennington
 * @File Name: Edge.h
 * @Assignment: EECS 560 Lab 10
 * @Brief: This program is the header file for the Edge Class.
 */

#ifndef Edge_H
#define Edge_H

#include<iostream>
using namespace std;

class Edge
{
  public:

    /*
		* @pre: Graph made
		* @post: Saves edge data
		* @param start: Starting vertex
    * @param end: Ending vertex
    * @param cost: Cost
		* @return: none
		*/

    Edge(int start, int end, int cost);

    /*
		* @pre: Graph made
		* @post: Initialize edge
		* @return: none
		*/

    Edge();

    /*
		* @pre: Graph made
		* @post: Deletes edges
		* @return: none
		*/

    ~Edge();

    /*
		* @pre: Graph made
		* @post: Prints links
    * @param out: Operator overload
    * @param c: Edge
		* @return: none
		*/

    friend ostream & operator << (std::ostream &out, const Edge &c);

    /*
		* @pre: Graph made
		* @post: Computes if edge is >
    * @param rhs: Right Hand Side
		* @return: True if >, otherwise false
		*/

    bool operator>(const Edge rhs);

    /*
		* @pre: Graph made
		* @post: Computes if edge is >=
    * @param rhs: Right Hand Side
		* @return: True if >=, otherwise false
		*/

    bool operator>=(const Edge rhs);

    /*
		* @pre: Graph made
		* @post: Computes if edge is <
    * @param rhs: Right Hand Side
		* @return: True if <, otherwise false
		*/

    bool operator<(const Edge rhs);

    /*
		* @pre: Graph made
		* @post: Computes if edge is <=
    * @param rhs: Right Hand Side
		* @return: True if <=, otherwise false
		*/

    bool operator<=(const Edge rhs);

    /*
		* @pre: Graph made
		* @post: Computes if edge is ==
    * @param rhs: Right Hand Side
		* @return: True if ==, otherwise false
		*/

    bool operator==(const Edge rhs);

    /*
		* @pre: Graph made
		* @post: Gets m_cost
		* @return: m_cost
		*/

    operator int() const;

    //Starting vertex
    int m_start;

    //Ending vertex
    int m_end;

    //Cost of edge
    int m_cost;
    
    private: //none
};
#endif
