/*
 * @Author: Joseph Pennington
 * @File Name: HashTable.cpp
 * @Assignment: EECS 560 Lab 05
 * @Brief: This program is the cpp file for the HashTable class.
 */

template <typename T>
HashTable<T>::HashTable(int size)
{
	m_bucketCountLinear = size;
	m_bucketCountQuadratic = size;
	m_elementsLinear = 0;
	m_elementsQuadratic = 0;
	m_array = new LinkedList<T>[m_bucketCountLinear];
}

template <typename T>
HashTable<T>::~HashTable()
{
	delete [] m_array;
}

//Double Hashing
template <typename T>
bool HashTable<T>::AddUserLinear(T x)
{

	int temp = 0;
	for(int i=0; i<25; i++)
	{
		temp = ((x%m_bucketCountLinear) + i*(773-(x%773))) % m_bucketCountLinear;
		if(m_array[temp].isEmpty())
		{
			m_array[temp].insert(x);
			m_elementsLinear++;
			return(true);
		}
	}
	return(false);
}

template <typename T>
bool HashTable<T>::AddUserQuadratic(T x)
{
	int temp = 0;
	for(int i=0; i<25; i++)
	{
		temp = (x%m_bucketCountQuadratic + (i*i)) % m_bucketCountQuadratic;
		if(m_array[temp].isEmpty())
		{
			m_array[temp].insert(x);
			m_elementsQuadratic++;
			return(true);
		}
	}
	return(false);
}

template <typename T>
bool HashTable<T>::findLinear(T x)
{
	int temp = 0;
	for(int i=0; i<25; i++)
	{
		temp = ((x%m_bucketCountLinear) + i*(773-(x%773))) % m_bucketCountLinear;
		for(int j=0; j<m_array[temp].getLength(); j++)
		{
			if(m_array[temp].getEntry(j) == x)
			{
				return(true);
			}
		}
	}
	return(false);
}

template <typename T>
bool HashTable<T>::findQuadratic(T x)
{
	int temp = 0;
	for(int i=0; i<25; i++)
	{
		temp = (x%m_bucketCountQuadratic + (i*i)) % m_bucketCountQuadratic;
		for(int j=0; j<m_array[temp].getLength(); j++)
		{
			if(m_array[temp].getEntry(j) == x)
			{
				return(true);
			}
		}
	}
	return(false);
}
