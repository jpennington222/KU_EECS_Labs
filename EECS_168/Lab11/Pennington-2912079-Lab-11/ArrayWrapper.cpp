#include <iostream>
#include <string>
#include <fstream>
#include "ArrayWrapper.h"

ArrayWrapper::ArrayWrapper(int size) //throw(std::runtime_error)
{
	if(size >= 1)
	{
		m_arr = new double[size];
		m_size = size;
	}
	else
	{
		throw(std::runtime_error("Invalid Size"));
	}
}

ArrayWrapper::ArrayWrapper(const ArrayWrapper& original) //deep copying
{
	m_arr = new double[original.getSize()];
	m_size = original.getSize();
	for(int i=0; i<m_size; i++)
	{
		m_arr[i] = original.m_arr[i];
	}
}

ArrayWrapper& ArrayWrapper::operator= (const ArrayWrapper& original)
{
	m_arr = new double[original.getSize()];
	m_size = original.getSize();
	for(int i=0; i<m_size; i++)
	{
		m_arr[i] = original.m_arr[i];
	}
	return *this;
}

ArrayWrapper::~ArrayWrapper()
{
	
	delete[] m_arr;
}

void ArrayWrapper::setEntry(int index, double value) //throw(std::runtime_error)
{
	if(index >=0 && index < m_size)
	{
		m_arr[index] = value;
	}
	else
	{
		throw(std::runtime_error("Invalid Index"));
	}
}

int ArrayWrapper::getSize() const
{
	return (m_size);
}

double ArrayWrapper::getEntry(int index) //throw(std::runtime_error)
{
	if(index >= 0 && index < m_size)
	{
		return (m_arr[index]);
	}
	else
	{
		throw(std::runtime_error("Invalid Index"));
	}
}





