/*
 * @Author: Joseph Pennington
 * @File Name: HashTableEntry.cpp
 * @Assignment: EECS 560 Lab 02
 * @Brief: This program is the cpp for the HashTableEntry class.
 */

#include "HashTableEntry.h"

HashTableEntry::HashTableEntry(std::string name, int key)
{
	m_name = name;
	m_key = key;
	searched = false;
}

HashTableEntry::HashTableEntry()
{
	searched = false;
}

std::string HashTableEntry::getName()
{
	return(m_name);
}


int HashTableEntry::getKey()
{
	return(m_key);
}


void HashTableEntry::setName(std::string name)
{
	m_name = name;
}


void HashTableEntry::setKey(int key)
{
  m_key = key;
}
