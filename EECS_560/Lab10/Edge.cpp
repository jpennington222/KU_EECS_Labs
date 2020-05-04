/*
 * @Author: Joseph Pennington
 * @File Name: Edge.cpp
 * @Assignment: EECS 560 Lab 10
 * @Brief: Implementation file for the Edge class
 */

#include "Edge.h"

Edge::Edge(int start, int end, int cost)
{
    m_cost = cost;
    m_start = start;
    m_end = end;
}

Edge::Edge()
{
    m_cost = 0;
    m_start = 0;
    m_end = 0;
}


Edge::~Edge()
{

};


ostream & operator << (ostream &out, const Edge &c)
{
    out << '(' << c.m_start << ", ";
    out << c.m_end;
    out << "){" << c.m_cost << '}';
    return out;
}

bool Edge::operator>(const Edge rhs)
{
  return m_cost > rhs.m_cost;
};

bool Edge::operator>=(const Edge rhs)
{
  return m_cost >= rhs.m_cost;
};

bool Edge::operator<(const Edge rhs)
{
  return m_cost < rhs.m_cost;
};

bool Edge::operator<=(const Edge rhs)
{
  return m_cost <= rhs.m_cost;
};

bool Edge::operator==(const Edge rhs)
{
  return ((m_start == rhs.m_start) && (m_end == rhs.m_end)) ||((m_start == rhs.m_end) && (m_end == rhs.m_start));
};

Edge::operator int() const
{
  return m_cost;
}
