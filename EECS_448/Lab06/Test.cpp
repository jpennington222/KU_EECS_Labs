/**
*	@file Test.cpp
*	@author Joseph Pennington
*	@date 11/18/2019
*/

#include "Test.h"
#include "QueueInterface.h"
#include "Node.h"
#include "Queue.h"
#include <iostream>
 using namespace std;

void Test::run()
{
	Queue* q = new Queue;

	//test 1: make new queue
	if(q -> isEmpty())
	{
		cout << "Test 1: New queue created and is empty: PASSED\n";
	}
	else
	{
		cout << "Test 1: New queue created and is empty: FAILED\n";

	}

	//test 2: enqueue 0 and check if empty
	q -> enqueue(0);
	if(q -> isEmpty() == false)
	{
		cout << "Test 2: 0 enqueued and queue is not empty: PASSED\n";
	}
	else
	{
		cout << "Test 2: 0 enqueued and queue is not empty: FAILED\n";
	}

	//test 3: check peekFront == 0
	if(q -> peekFront() == 0)
	{
		cout << "Test 3: peekFront == 0: PASSED\n";
	}
	else
	{
		cout << "Test 3: peekFront == 0: FAILED\n";
	}

	//test 4: enqueue 1 and check if empty
	q -> enqueue(1);
	if(q -> isEmpty() == false)
	{
		cout << "Test 4: 1 enqueued and queue is not empty: PASSED\n";
	}
	else
	{
		cout << "Test 4: 1 enqueued and queue is not empty: FAILED\n";
	}

	//test 5: check peekFront == 0
	if(q -> peekFront() == 0)
	{
		cout << "Test 5: peekFront == 0: PASSED\n";
	}
	else
	{
		cout << "Test 5: peekFront == 0: FAILED\n";
	}

	//test 6: enqueue 1 and check if empty
	q -> enqueue(2);
	if(q -> isEmpty() == false)
	{
		cout << "Test 6: 2 enqueued and queue is not empty: PASSED\n";
	}
	else
	{
		cout << "Test 6: 2 enqueued and queue is not empty: FAILED\n";
	}

	//test 7: check peekFront == 0
	if(q -> peekFront() == 0)
	{
		cout << "Test 7: peekFront == 0: PASSED\n";
	}
	else
	{
		cout << "Test 7: peekFront == 0: FAILED\n";
	}

	//test 8: enqueue 3 and check if empty
	q -> enqueue(3);
	if(q -> isEmpty() == false)
	{
		cout << "Test 8: 3 enqueued and queue is not empty: PASSED\n";
	}
	else
	{
		cout << "Test 8: 3 enqueued and queue is not empty: FAILED\n";
	}

	//test 9: check peekFront == 0
	if(q -> peekFront() == 0)
	{
		cout << "Test 9: peekFront == 0: PASSED\n";
	}
	else
	{
		cout << "Test 9: peekFront == 0: FAILED\n";
	}

	//test 10: enqueue -1
	q -> enqueue(-1);
	if(q -> isEmpty() == false)
	{
		cout << "Test 10: -1 enqueued and queue is not empty: PASSED\n";
	}
	else
	{
		cout << "Test 10: -1 enqueued and queue is not empty: FAILED\n";
	}

	//test 11: check peekFront == 0
	if(q -> peekFront() == 0)
	{
		cout << "Test 11: peekFront == 0: PASSED\n";
	}
	else
	{
		cout << "Test 11: peekFront == 0: FAILED\n";
	}

	//test 12: dequeue 0
	q -> dequeue();
	if(q -> isEmpty() == false)
	{
		cout << "Test 12: Number dequeued and queue is not empty: PASSED\n";
	}
	else
	{
		cout << "Test 12: Number dequeued and queue is not empty: FAILED\n";
	}

	//test 13: peekFront == 1
	if(q -> peekFront() == 1)
	{
		cout << "Test 13: peekFront == 1: PASSED\n";
	}
	else
	{
		cout << "Test 13: peekFront == 1: FAILED\n";
		cout << "peekFront() returns: " << q -> peekFront() << '\n';
	}

	//test 14: dequeue 1
	q -> dequeue();
	if(q -> isEmpty() == false)
	{
		cout << "Test 14: Number dequeued and queue is not empty: PASSED\n";
	}
	else
	{
		cout << "Test 14: Number dequeued and queue is not empty: FAILED\n";
		cout << "peekFront() returns: " << q -> peekFront() << '\n';
	}

	//test 15: peekFront == 2
	if(q -> peekFront() == 2)
	{
		cout << "Test 15: peekFront == 2: PASSED\n";
	}
	else
	{
		cout << "Test 15: peekFront == 2: FAILED\n";
		cout << "peekFront() returns: " << q -> peekFront() << '\n';
	}

	//test 16: dequeue 2
	q -> dequeue();
	if(q -> isEmpty() == false)
	{
		cout << "Test 16: Number dequeued and queue is not empty: PASSED\n";
	}
	else
	{
		cout << "Test 16: Number dequeued and queue is not empty: FAILED\n";
	}

	//test 17: peekFront == 3
	if(q -> peekFront() == 3)
	{
		cout << "Test 17: peekFront == 3: PASSED\n";
	}
	else
	{
		cout << "Test 17: peekFront == 3: FAILED\n";
		cout << "peekFront() returns: " << q -> peekFront() << '\n';
	}

	//test 18: dequeue 3
	q -> dequeue();
	if(q -> isEmpty() == false)
	{
		cout << "Test 18: Number dequeued and queue is not empty: PASSED\n";
	}
	else
	{
		cout << "Test 18: Number dequeued and queue is not empty: FAILED\n";
	}

	//test 19: peekFront == -1
	if(q -> peekFront() == -1)
	{
		cout << "Test 19: peekFront == -1: PASSED\n";
	}
	else
	{
		cout << "Test 19: peekFront == -1: FAILED\n";
		cout << "peekFront() returns: " << q -> peekFront() << '\n';
	}

	//test 20: dequeue -1
	q -> dequeue();
	if(q -> isEmpty() == true)
	{
		cout << "Test 20: Number dequeued and queue is empty: PASSED\n";
	}
	else
	{
		cout << "Test 20: Number dequeued and queue is not empty: FAILED\n";
	}

	//test 21: peekFront == error
	try
	{
		q -> peekFront();
	}
	catch(...)
	{
		cout << "Test 21: peekFront throws an error if queue is empty: PASSED\n";
	}

	//test 22: dequeue == error
	try
	{
		q -> dequeue();
	}
	catch(...)
	{
		cout << "Test 22: dequeue throws an error if queue is empty: PASSED\n";
	}

	delete q;
  Queue* q1 = new Queue;
  q1 -> enqueue(1);
  delete q1;
}
