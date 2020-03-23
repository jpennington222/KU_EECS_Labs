/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 268 Lab 05
 * @Date: 10/08/2018
 * @Brief: This program is the Executive.cpp file for the lab. It passes the map to floodRec to be flooded.
 */

#include "Executive.h"
#include <iostream>
#include <fstream>

Executive::Executive(std::string file)
{
  int temp = 0;

  Filename = file;
  std::ifstream inFile;
  inFile.open(Filename);
  inFile>>temp;
	if(temp < 0)
	{
		std::cout<<"Invalid Map Size\n";
		exit(0);
	}
  m_row = temp+1;
  inFile>>temp;
	if(temp < 0)
	{
		std::cout<<"Invalid Map Size\n";
		exit(0);
	}
  m_col = temp+1;
  inFile>>temp;
  if(temp < 0)
	{
		std::cout<<"Invalid starting position\n";
		exit(0);
	}
  m_startR = temp;
  inFile>>temp;
  if(temp < 0)
  {
    std::cout<<"Invalid starting position\n";
    exit(0);
  }
  m_startC = temp;
  inFile>>temp;
  water = temp;

  inFile>>std::noskipws;
  m_map = new char*[m_row];
  for(int i=0; i<m_row; i++)
  {
    m_map[i] = new char[m_col];
  }

  for(int i=0; i<m_row; i++)
  {
    for(int j=0; j<m_col; j++)
    {
      inFile>>m_map[i][j];
    }
  }
  inFile.close();
}

void Executive::run()
{
  bool temp = false;
  temp = floodRec(m_startR, m_startC+1);
  std::cout<<"Size: "<<m_row-1<<","<<m_col-1<<'\n';
  std::cout<<"Starting position: "<<m_startR<<","<<m_startC;
  for(int i=0; i<m_row; i++)
  {
    for(int j=0; j<m_col; j++)
    {
      std::cout<<m_map[i][j];
    }
  }

  if(temp == true)
  {
    std::cout<<'\n'<<"Flood complete.\n";
  }

  else
  {
    std::cout<<'\n'<<"Flood ran out of water.\n";
  }
}

bool Executive::floodRec(int row, int col)
{
  if(water <= 0) //base case
  {
    return(false);
  }

  if(water > 0)
  {
    m_map[row][col] = '~';
    water = water - 1;
  }

  if(isValid(row-1, col)) //up
  {
    floodRec(row-1, col);
  }

  if(isValid(row, col+1)) //right
  {
    floodRec(row, col+1);
  }

  if(isValid(row+1, col)) //down
  {
    floodRec(row+1, col);
  }

  if(isValid(row, col-1)) //left
  {
    floodRec(row, col-1);
  }

  if(water <= 0) //used last water
  {
    return(false);
  }

  else //finished flooding and still have water
  {
    return(true);
  }
}

bool Executive::isValid(int row, int col)
{
	char space = ' ';
  if((row >= 0 && row < m_row) && (col >= 0 && col < m_row) && (m_map[row][col] == space))
  {
    return(true);
  }

  else
  {
    return(false);
  }
}

int Executive::getRow()
{
	return(m_row);
}

int Executive::getCol()
{
	return(m_col);
}

int Executive::getStartR()
{
	return(m_startR);
}

int Executive::getStartC()
{
	return(m_startC);
}

Executive::~Executive()
{
  for(int i=0; i<m_row; i++)
  {
    delete[] m_map[i];
  }

  delete[] m_map;
}
