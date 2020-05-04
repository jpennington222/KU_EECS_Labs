/*
 * @Author: Joseph Pennington
 * @File Name: HashTableEntry.cpp
 * @Assignment: EECS 560 Lab 03
 * @Brief: This program is the cpp for the HashTableEntry class.
 */

#include "HashTableEntry.h"

HashTableEntry::HashTableEntry(std::string name, std::string password, int key)
{
	m_name = name;
	m_password = password;
	m_key = key;
	m_searched = false;
}

HashTableEntry::HashTableEntry()
{
	m_searched = false;
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

std::string HashTableEntry::getPassword()
{
	return(m_password);
}

bool HashTableEntry::getSearched()
{
	return(m_searched);
}

void HashTableEntry::setPassword(std::string password)
{
	m_password = password;
}

void HashTableEntry::setSearched(bool searched)
{
	m_searched = searched;
}
