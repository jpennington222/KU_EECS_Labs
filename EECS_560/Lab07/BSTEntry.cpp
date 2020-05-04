/*
 * @Author: Joseph Pennington
 * @File Name: BSTEntry.cpp
 * @Assignment: EECS 560 Lab 07
 * @Brief: This program is the cpp for the BSTEntry class.
 */

#include "BSTEntry.h"

BSTEntry::BSTEntry(std::string first, std::string last, int key)
{
	m_first = first;
	m_last = last;
	m_key = key;
}

BSTEntry::BSTEntry()
{
	m_first;
	m_last;
	m_key;
}

std::string BSTEntry::getFirst()
{
	return(m_first);
}

std::string BSTEntry::getLast()
{
	return(m_last);
}

int BSTEntry::getKey()
{
	return(m_key);
}


void BSTEntry::setFirst(std::string first)
{
	m_first = first;
}

void BSTEntry::setLast(std::string last)
{
	m_last = last;
}

void BSTEntry::setKey(int key)
{
	m_key = key;
}
