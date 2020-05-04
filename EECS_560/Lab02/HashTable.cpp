/*
 * @Author: Joseph Pennington
 * @File Name: HashTable.cpp
 * @Assignment: EECS 560 Lab 02
 * @Brief: This program is the cpp file for the HashTable class.
 */

template <typename T>
HashTable<T>::HashTable(int size)
{
	m_bucketCount = size;
	m_elements = 0;
	m_array = new LinkedList<T>[m_bucketCount];
}

template <typename T>
HashTable<T>::~HashTable()
{
	delete [] m_array;
}

template <typename T>
bool HashTable<T>::AddPlayer(T x)
{
	int index = Hashfunction(x.getKey(), m_bucketCount);
	for(int i=0; i<m_bucketCount; i++)
	{
		for(int j=0; j<m_array[i].getLength();j++)
		{
			if(m_array[i].getEntry(j).getName() == x.getName())
			{
				return(false);
			}
		}
	}
	m_array[index].insert(x);
	return(true);
}

template <typename T>
bool HashTable<T>::RemovePlayer(T x)
{
	int index = Hashfunction(x.getKey(), m_bucketCount);
	for(int i=0; i<m_bucketCount; i++)
	{
		for(int j=0; j<m_array[i].getLength();j++)
		{
			if(m_array[i].getEntry(j).getName() == x.getName() && m_array[i].getEntry(j).getKey() == x.getKey())
			{
				m_array[index].remove(x);
				return(true);
			}
		}
	}
	return(false);
}

template <typename T>
void HashTable<T>::PrintPlayerList()
{
	for(int i=0; i<m_bucketCount; i++)
	{
		cout<<i<<": ";
		for(int j=0; j<m_array[i].getLength();j++)
		{
			cout << "-> ";

			cout<<m_array[i].getEntry(j).getName()<< " " <<m_array[i].getEntry(j).getKey()<<" ";
		}
		cout<<'\n';
	}
}

template <typename T>
int HashTable<T>::Hashfunction(int goalcount, int bucketsize)
{
	return(goalcount % bucketsize);
}

template <typename T>
void HashTable<T>::PlayerWithGoalCountEqualTo(int g)
{
	bool playersFound = false;
	for(int i=0; i<m_bucketCount; i++)
	{
		for(int j=0; j<m_array[i].getLength();j++)
		{
			if(m_array[i].getEntry(j).getKey() == g)
			{
				cout<<m_array[i].getEntry(j).getName()<< ", ";
				playersFound = true;

			}
		}
	}
	if(playersFound == false)
	{
		cout << "No players found";
	}
}

template <typename T>
void HashTable<T>::PlayerWithNumGoalsGreaterThan(int h)
{
	bool playersFound = false;
	for(int i=0; i<m_bucketCount; i++)
	{
		for(int j=0; j<m_array[i].getLength();j++)
		{
			if(m_array[i].getEntry(j).getKey() >= h)
			{
				cout<<m_array[i].getEntry(j).getName()<<", ";;
				playersFound = true;
			}
		}
	}
	if(playersFound == false)
	{
		cout << "No players found";
	}
}

template <typename T>
void HashTable<T>::PlayerWithNumGoalsLessThan(int h)
{
	bool playersFound = false;
	for(int i=0; i<m_bucketCount; i++)
	{
		for(int j=0; j<m_array[i].getLength();j++)
		{
			if(m_array[i].getEntry(j).getKey() <= h)
			{
				cout<<m_array[i].getEntry(j).getName()<<", ";
				playersFound = true;
			}
		}
	}
	if(playersFound == false)
	{
		cout << "No players found";
	}
}
