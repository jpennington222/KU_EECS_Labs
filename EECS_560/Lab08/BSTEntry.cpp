/*
 * @Author: Joseph Pennington
 * @File Name: BSTEntry.cpp
 * @Assignment: EECS 560 Lab 08
 * @Brief: This program is the cpp for the BSTEntry class.
 */

#include "BSTEntry.h"

BSTEntry::BSTEntry(std::string name, int key)
{
	m_name = name;
	m_key = key;
}

BSTEntry::BSTEntry()
{
	m_name;
	m_key;
}

std::string BSTEntry::getName()
{
	return(m_name);
}

int BSTEntry::getKey()
{
	return(m_key);
}

void BSTEntry::setName(std::string name)
{
	m_name = name;
}

void BSTEntry::setKey(int key)
{
  m_key = key;
}
