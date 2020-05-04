/*
 * @Author: Joseph Pennington
 * @File Name: HashTable.cpp
 * @Assignment: EECS 560 Lab 03
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

template <typename T>
bool HashTable<T>::AddUserLinear(T x)
{
	if(loadFactor(m_elementsLinear, m_bucketCountLinear) > 0.5)
	{
		rehashLinear();
	}
	int temp = 0;
	for(int i=0; i<m_bucketCountLinear; i++)
	{
		temp = (Hashfunction(x.getKey(), m_bucketCountLinear) + i) % m_bucketCountLinear;
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
	if(loadFactor(m_elementsQuadratic, m_bucketCountQuadratic) > 0.5)
	{
		rehashQuadratic();
	}
	for(int i=0; i<m_bucketCountQuadratic; i++)
	{
		temp = ((Hashfunction(x.getKey(), m_bucketCountQuadratic) + (i*i)) % m_bucketCountQuadratic);
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
bool HashTable<T>::RemoveUserLinear(T x)
{
	//int index = Hashfunction(x.getKey(), m_bucketCountLinear);
	for(int i=0; i<m_bucketCountLinear; i++)
	{
		for(int j=0; j<m_array[i].getLength();j++)
		{
			if(m_array[i].getEntry(j).getName() == x.getName() && m_array[i].getEntry(j).getKey() == x.getKey())
			{
				m_array[i].remove(x);
				m_elementsLinear--;
				return(true);
			}
		}
	}
	return(false);
}

template <typename T>
bool HashTable<T>::RemoveUserQuadratic(T x)
{
	//int index = Hashfunction(x.getKey(), m_bucketCountQuadratic);
	for(int i=0; i<m_bucketCountQuadratic; i++)
	{
		for(int j=0; j<m_array[i].getLength();j++)
		{
			if(m_array[i].getEntry(j).getName() == x.getName() && m_array[i].getEntry(j).getKey() == x.getKey())
			{
				m_array[i].remove(x);
				m_elementsQuadratic--;
				return(true);
			}
		}
	}
	return(false);
}


template <typename T>
void HashTable<T>::PrintUsersLinear()
{
	for(int i=0; i<m_bucketCountLinear; i++)
	{
		cout<<i<<": ";
		for(int j=0; j<m_array[i].getLength();j++)
		{
			cout << " ";

			cout<<m_array[i].getEntry(j).getName()<< ":" <<m_array[i].getEntry(j).getPassword()<<" ";
		}
		cout<<'\n';
	}
}

template <typename T>
void HashTable<T>::PrintUsersQuadratic()
{
	for(int i=0; i<m_bucketCountQuadratic; i++)
	{
		cout<<i<<": ";
		for(int j=0; j<m_array[i].getLength();j++)
		{
			cout << " ";

			cout<<m_array[i].getEntry(j).getName()<< ":" <<m_array[i].getEntry(j).getPassword()<<" ";
		}
		cout<<'\n';
	}
}

template <typename T>
int HashTable<T>::Hashfunction(int castValue, int bucketsize)
{
	return(castValue % bucketsize);
}

template <typename T>
double HashTable<T>::loadFactor(int elements, int buckets)
{
	return(elements/(double)buckets);
}

template <typename T>
bool HashTable<T>::isDuplicateLinear(T x)
{
	for(int i=0; i<m_bucketCountLinear; i++)
	{
		for(int j=0; j<m_array[i].getLength();j++)
		{
			if(m_array[i].getEntry(j).getName() == x.getName())
			{
				cout << "Linear Probing:\n";
				cout << "Record not inserted. Duplicate Entry.\n";
				return(true);
			}
		}
	}
	return(false);
}

template <typename T>
bool HashTable<T>::isDuplicateQuadratic(T x)
{
	for(int i=0; i<m_bucketCountQuadratic; i++)
	{
		for(int j=0; j<m_array[i].getLength();j++)
		{
			if(m_array[i].getEntry(j).getName() == x.getName())
			{
				cout << "Quadratic Probing:\n";
				cout << "Record not inserted. Duplicate Entry.\n";
				return(true);
			}
		}
	}
	return(false);
}

template <typename T>
int HashTable<T>::nextPrimeLinear()
{
	bool readyToBreak = false;
  int prime = m_bucketCountLinear*2;
  while(readyToBreak == false){
    if(isPrime(prime)){
      readyToBreak = true;
    }
    else{
      prime++;
    }
  }
  return prime;
}

template <typename T>
int HashTable<T>::nextPrimeQuadratic()
{
	bool readyToBreak = false;
  int prime = m_bucketCountQuadratic*2;
  while(readyToBreak == false)
	{
    if(isPrime(prime)){
      readyToBreak = true;
    }
    else
		{
      prime++;
    }
  }
  return prime;
}

template <typename T>
bool HashTable<T>::isPrime(int test)
{
	bool prime = true;
  for(int i=2; i<=(test/2); i++)
	{
    if(test%i==0)
		{
      prime = false;
    }
  }
  return prime;
}

template <typename T>
void HashTable<T>::rehashLinear()
{
	int prime = nextPrimeLinear();
	bool good = false;
	int col = 0;
  LinkedList<T>* temp = new LinkedList<T>[prime];

	for(int i=0; i<m_bucketCountLinear; i++)
	{
    for(int j=0; j<m_array[i].getLength(); j++)
		{
			while(good == false)
			{
				int index = (Hashfunction(m_array[i].getEntry(j).getKey(), prime) + col) % prime;
				if(temp[index].isEmpty())
				{
					temp[index].insert(m_array[i].getEntry(j));
					col = 0;
					good = true;
				}
				else
				{
					col++;
				}
			}
    }
		good = false;
  }
  delete[] m_array;
  m_array = temp;
  m_bucketCountLinear = prime;
  cout<<"Linear probing hash table is rehashed\n";
}

template <typename T>
void HashTable<T>::rehashQuadratic()
{
	int prime = nextPrimeQuadratic();
	bool good = false;
	int col = 0;
  LinkedList<T>* temp = new LinkedList<T>[prime];

	for(int i=0; i<m_bucketCountQuadratic; i++)
	{
    for(int j=0; j<m_array[i].getLength(); j++)
		{
			while(good == false)
			{
				int index = (Hashfunction(m_array[i].getEntry(j).getKey(), prime) + col*col) % prime;
				if(temp[index].isEmpty())
				{
					temp[index].insert(m_array[i].getEntry(j));
					col = 0;
					good = true;
				}
				else
				{
					col++;
				}
			}
    }
		good = false;
  }
  delete[] m_array;
  m_array = temp;
  m_bucketCountQuadratic = prime;
  cout<<"Quadratic probing hash table is rehashed\n";
}

template <typename T>
void HashTable<T>::forgotPasswordLinear(string username)
{
	for(int i=0; i<m_bucketCountLinear; i++)
	{
		for(int j=0; j<m_array[i].getLength();j++)
		{
			if(m_array[i].getEntry(j).getName() == username)
			{
				cout << "Linear Probing:\n";
				cout << username << ":" << m_array[i].getEntry(j).getPassword() << '\n';
				return;
			}
		}
	}
	cout << "Linear Probing:\n";
	cout << "No record found\n";
	return;
}

template <typename T>
void HashTable<T>::forgotPasswordQuadratic(string username)
{
	for(int i=0; i<m_bucketCountQuadratic; i++)
	{
		for(int j=0; j<m_array[i].getLength();j++)
		{
			if(m_array[i].getEntry(j).getName() == username)
			{
				cout << "Quadratic Probing:\n";
				cout << username << ":" << m_array[i].getEntry(j).getPassword() << '\n';
				return;
			}
		}
	}
	cout << "Quadratic Probing:\n";
	cout << "No record found\n";
	return;
}

template <typename T>
void HashTable<T>::forgotUsernameLinear(string password)
{
	for(int i=0; i<m_bucketCountLinear; i++)
	{
		for(int j=0; j<m_array[i].getLength();j++)
		{
			if(m_array[i].getEntry(j).getPassword() == password)
			{
				cout << "Linear Probing:\n";
				cout << m_array[i].getEntry(j).getName() << ":" << password << '\n';
				return;
			}
		}
	}
	cout << "Linear Probing:\n";
	cout << "No record found\n";
	return;
}

template <typename T>
void HashTable<T>::forgotUsernameQuadratic(string password)
{
	for(int i=0; i<m_bucketCountQuadratic; i++)
	{
		for(int j=0; j<m_array[i].getLength();j++)
		{
			if(m_array[i].getEntry(j).getPassword() == password)
			{
				cout << "Quadratic Probing:\n";
				cout << m_array[i].getEntry(j).getName() << ":" << password << '\n';
				return;
			}
		}
	}
	cout << "Quadratic Probing:\n";
	cout << "No record found\n";
	return;
}
