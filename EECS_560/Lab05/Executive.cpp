/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 560 Lab 05
 * @Brief: This program is the Executive.cpp file for the lab. It passes the inFile contents to the respective functions.
 */

#include "Executive.h"
#include "Node.h"
#include "LinkedList.h"
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;


//do the find stuff after each insert
Executive::Executive(int x)
{
	//cout << "Generating Results. This may take a few minutes.\n";
	int random;
	int inputSize;
	int findSize;

//----------------------Build Size = 0.1m-------------------------------------

	srand(time(NULL));
	m_HashTableLinear = new HashTable<int>(1000003);
	m_HashTableQuadratic = new HashTable<int>(1000003);
	inputSize = 0.1 * 1000003;
	//cout << inputSize <<'\n';

	//Double Hashing Size = 0.1m
	clock_t start = clock();
	for(int i=0; i<inputSize; i++)
	{
		random = rand() % 5000000 + 1;
		m_HashTableLinear -> AddUserLinear(random);
	}
	clock_t stop = clock();
	double doubleInsert1 = (double)(stop-start) / CLOCKS_PER_SEC;
	//cout << "DH Size = 0.1m: ";
	//cout << doubleInsert1 << '\n';
	//cout << '\n';

	//DH Find
	findSize = 0.01 * 1000003;
	//cout << findSize << '\n';
	int countLinear1 = 0;
	for(int i=0; i<findSize; i++)
	{
		random = rand() % 5000000 + 1;
		if(m_HashTableLinear -> findLinear(random))
		{
			countLinear1++;
		}
	}
	//cout << countLinear1 << '\n';

	//Quadratic Hashing Size = 0.1m
	start = clock();
	for(int i=0; i<inputSize; i++)
	{
		random = rand() % 5000000 + 1;
		m_HashTableQuadratic -> AddUserQuadratic(random);
	}
	stop = clock();
	double quadraticInsert1 = (double)(stop-start) / CLOCKS_PER_SEC;
	//cout << "QH Size = 0.1m: ";
	//cout << quadraticInsert1 << '\n';
	//cout << '\n';

	//QH Find
	int countQuadratic1 = 0;
	for(int i=0; i<findSize; i++)
	{
		random = rand() % 5000000 + 1;
		if(m_HashTableQuadratic -> findQuadratic(random))
		{
			countQuadratic1++;
		}
	}
	//cout << countQuadratic1 << '\n';
	cout << "Set 1 Complete\n";

//----------------------Build Size = 0.2m-------------------------------------

	srand(time(NULL));
	m_HashTableLinear2 = new HashTable<int>(1000003);
	m_HashTableQuadratic2 = new HashTable<int>(1000003);

	inputSize = 0.2 * 1000003;
	//cout << inputSize <<'\n';

	//Double Hashing Size = 0.2m
	start = clock();
	for(int i=0; i<inputSize; i++)
	{
		random = rand() % 5000000 + 1;
		m_HashTableLinear2 -> AddUserLinear(random);
	}
	stop = clock();
	double doubleInsert2 = (double)(stop-start) / CLOCKS_PER_SEC;
	//cout << "DH Size = 0.2m: ";
	//cout << doubleInsert2 << '\n';
	//cout << '\n';

	//DH Find
	findSize = 0.02 * 1000003;
	//cout << findSize << '\n';
	int countLinear2 = 0;
	for(int i=0; i<findSize; i++)
	{
		random = rand() % 5000000 + 1;
		if(m_HashTableLinear2 -> findLinear(random))
		{
			countLinear2++;
		}
	}
	//cout << countLinear2 << '\n';

	//Quadratic Hashing Size = 0.2m
	start = clock();
	for(int i=0; i<inputSize; i++)
	{
		random = rand() % 5000000 + 1;
		m_HashTableQuadratic2 -> AddUserQuadratic(random);
	}
	stop = clock();
	double quadraticInsert2 = (double)(stop-start) / CLOCKS_PER_SEC;
	//cout << "QH Size = 0.2m: ";
	//cout << quadraticInsert2 << '\n';
	//cout << '\n';

	//QH Find
	int countQuadratic2 = 0;
	for(int i=0; i<findSize; i++)
	{
		random = rand() % 5000000 + 1;
		if(m_HashTableQuadratic2 -> findQuadratic(random))
		{
			countQuadratic2++;
		}
	}
	//cout << countQuadratic2 << '\n';
	cout << "Set 2 Complete\n";

//----------------------Build Size = 0.3m-------------------------------------

	srand(time(NULL));
	m_HashTableLinear3 = new HashTable<int>(1000003);
	m_HashTableQuadratic3 = new HashTable<int>(1000003);

	inputSize = 0.3 * 1000003;
	//cout << inputSize <<'\n';

	//Double Hashing Size = 0.3m
	start = clock();
	for(int i=0; i<inputSize; i++)
	{
		random = rand() % 5000000 + 1;
		m_HashTableLinear3 -> AddUserLinear(random);
	}
	stop = clock();
	double doubleInsert3 = (double)(stop-start) / CLOCKS_PER_SEC;
	//cout << "DH Size = 0.3m: ";
	//cout << doubleInsert3 << '\n';
	//cout << '\n';

	//DH Find
	findSize = 0.03 * 1000003;
	//cout << findSize << '\n';
	int countLinear3 = 0;
	for(int i=0; i<findSize; i++)
	{
		random = rand() % 5000000 + 1;
		if(m_HashTableLinear3 -> findLinear(random))
		{
			countLinear3++;
		}
	}
	//cout << countLinear3 << '\n';

	//Quadratic Hashing Size = 0.3m
	start = clock();
	for(int i=0; i<inputSize; i++)
	{
		random = rand() % 5000000 + 1;
		m_HashTableQuadratic3 -> AddUserQuadratic(random);
	}
	stop = clock();
	double quadraticInsert3 = (double)(stop-start) / CLOCKS_PER_SEC;
	//cout << "QH Size = 0.3m: ";
	//cout << quadraticInsert3 << '\n';
	//cout << '\n';

	//QH Find
	int countQuadratic3 = 0;
	for(int i=0; i<findSize; i++)
	{
		random = rand() % 5000000 + 1;
		if(m_HashTableQuadratic3 -> findQuadratic(random))
		{
			countQuadratic3++;
		}
	}
	//cout << countQuadratic3 << '\n';
	cout << "Set 3 Complete\n";

//----------------------Build Size = 0.4m-------------------------------------

	srand(time(NULL));
	m_HashTableLinear4 = new HashTable<int>(1000003);
	m_HashTableQuadratic4 = new HashTable<int>(1000003);

	inputSize = 0.4 * 1000003 -1;
	//cout << inputSize <<'\n';

	//Double Hashing Size = 0.4m
	start = clock();
	for(int i=0; i<inputSize; i++)
	{
		random = rand() % 5000000 + 1;
		m_HashTableLinear4 -> AddUserLinear(random);
	}
	stop = clock();
	double doubleInsert4 = (double)(stop-start) / CLOCKS_PER_SEC;
	//cout << "DH Size = 0.4m: ";
	//cout << doubleInsert4 << '\n';
	//cout << '\n';

	//DH Find
	findSize = 0.04 * 1000003;
	//cout << findSize << '\n';
	int countLinear4 = 0;
	for(int i=0; i<findSize; i++)
	{
		random = rand() % 5000000 + 1;
		if(m_HashTableLinear4 -> findLinear(random))
		{
			countLinear4++;
		}
	}
	//cout << countLinear4 << '\n';


	//Quadratic Hashing Size = 0.4m
	start = clock();
	for(int i=0; i<inputSize; i++)
	{
		random = rand() % 5000000 + 1;
		m_HashTableQuadratic4 -> AddUserQuadratic(random);
	}
	stop = clock();
	double quadraticInsert4 = (double)(stop-start) / CLOCKS_PER_SEC;
	//cout << "QH Size = 0.4m: ";
	//cout << quadraticInsert4 << '\n';
	//cout << '\n';

	//QH Find
	int countQuadratic4 = 0;
	for(int i=0; i<findSize; i++)
	{
		random = rand() % 5000000 + 1;
		if(m_HashTableQuadratic4 -> findQuadratic(random))
		{
			countQuadratic4++;
		}
	}
	//cout << countQuadratic4 << '\n';
	cout << "Set 4 Complete\n";

//----------------------Build Size = 0.5m-------------------------------------

	srand(time(NULL));
	m_HashTableLinear5 = new HashTable<int>(1000003);
	m_HashTableQuadratic5 = new HashTable<int>(1000003);

	inputSize = 0.5 * 1000003 -1;
	//cout << inputSize <<'\n';

	//Double Hashing Size = 0.5m
	start = clock();
	for(int i=0; i<inputSize; i++)
	{
		random = rand() % 5000000 + 1;
		m_HashTableLinear5 -> AddUserLinear(random);
	}
	stop = clock();
	double doubleInsert5 = (double)(stop-start) / CLOCKS_PER_SEC;
	//cout << "DH Size = 0.5m: ";
	//cout << doubleInsert5 << '\n';
	//cout << '\n';

	//DH Find
	findSize = 0.05 * 1000003;
	//cout << findSize << '\n';
	int countLinear5 = 0;
	for(int i=0; i<findSize; i++)
	{
		random = rand() % 5000000 + 1;
		if(m_HashTableLinear5 -> findLinear(random))
		{
			countLinear5++;
		}
	}
	//cout << countLinear5 << '\n';

	//Quadratic Hashing Size = 0.5m
	start = clock();
	for(int i=0; i<inputSize; i++)
	{
		random = rand() % 5000000 + 1;
		m_HashTableQuadratic5 -> AddUserQuadratic(random);
	}
	stop = clock();
	double quadraticInsert5 = (double)(stop-start) / CLOCKS_PER_SEC;
	//cout << "QH Size = 0.5m: ";
	//cout << quadraticInsert5 << '\n';
	//cout << '\n';

	//QH Find
	int countQuadratic5 = 0;
	for(int i=0; i<findSize; i++)
	{
		random = rand() % 5000000 + 1;
		if(m_HashTableQuadratic5 -> findQuadratic(random))
		{
			countQuadratic5++;
		}
	}
	//cout << countQuadratic5 << '\n';
	cout << "Set 5 Complete\n";
	cout << '\n';

//----------------------End Data Collection------------------------------------


	cout << "                     Performance Quadratic Probing\n";
	cout << "____________________________________________________________________________________________\n\n";
	cout << "Input Size                 | 100,000 | 200,000 | 300,000 | 400,000 | 500,000 |\n";
	cout << "Build(s)                   | " << quadraticInsert1 << " | " << quadraticInsert2 << " | " << quadraticInsert3 << " | " << quadraticInsert4 << " | " << quadraticInsert5 << " |\n";
	cout << "Number of items found      | " << countQuadratic1 << " | " << countQuadratic2 << " | " << countQuadratic3 << " | " << countQuadratic4 << " | " << countQuadratic5 << " |\n";
	cout << "Number of items not found  | " << 10000 - countQuadratic1 << " | " << 20000 - countQuadratic2 << " | " << 30000 - countQuadratic3 << " | " << 40000 - countQuadratic4 << " | " << 50000 - countQuadratic5 << " |\n";
	cout <<  "____________________________________________________________________________________________\n";


	cout << '\n';
	cout << '\n';


	cout << "                     Performance Double Hashing\n";
	cout << "____________________________________________________________________________________________\n\n";
	cout << "Input Size                 | 100,000 | 200,000 | 300,000 | 400,000 | 500,000 |\n";
	cout << "Build(s)                   | " << doubleInsert1 << " | " << doubleInsert2 << " | " << doubleInsert3 << " | " << doubleInsert4 << " | " << doubleInsert5 << " |\n";
	cout << "Number of items found      | " << countLinear1 << " | " << countLinear2 << " | " << countLinear3 << " | " << countLinear4 << " | " << countLinear5 << " |\n";
	cout << "Number of items not found  | " << 10000 - countLinear1 << " | " << 20000 - countLinear2 << " | " << 30000 - countLinear3 << " | " << 40000 - countLinear4 << " | " << 50000 - countLinear5 << " |\n";
	cout <<  "____________________________________________________________________________________________\n";


}

void Executive::run()
{

}

Executive::~Executive()
{
	delete m_HashTableLinear;
	delete m_HashTableQuadratic;
	delete m_HashTableLinear2;
	delete m_HashTableQuadratic2;
	delete m_HashTableLinear3;
	delete m_HashTableQuadratic3;
	delete m_HashTableLinear4;
	delete m_HashTableQuadratic4;
	delete m_HashTableLinear5;
	delete m_HashTableQuadratic5;
}
