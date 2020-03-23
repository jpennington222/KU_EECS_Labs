/*
 * @Author: Joseph Pennington
 * @File Name: Queue.h
 * @Assignment: EECS 268 Lab 03
 * @Date: 09/24/2018
 * @Brief: This program is header file for the Queue Class. It declares the destructor, isEmpty, enqueue, dequeue, and peekfront functions
 */

 #ifndef QUEUE_H
 #define QUEUE_H
 #include "Node.h"
 #include "QueueInterface.h"
 #include "ListInterface.h"
 #include "LinkedList.h"
 #include "PrecondViolatedExcep.h"

 template <typename T>
 class Queue : public QueueInterface<T>
 {
 public:

   /*
   * @pre: None
   * @post: A Queue is made
   * @return: none
   */

   Queue();

   /*
   * @pre: Queue must be made
   * @post: Determines if Queue is empty
   * @return: Return true if the queue is empty and false if not
   */

   bool isEmpty()const;

   /*
   * @pre: Queue must be made
   * @post: Entry is added to the back of the queue
   * @param newEntry: Entry that is being added to the queue
   * @throw PrecondViolatedExcep: Throw error if no memory is available
   * @return: none
   */

   void enqueue(const T& newEntry) throw(PrecondViolatedExcep);

   /*
   * @pre: Queue is made and not empty
   * @post: Entry at the top of the queue is removed
   * @throw PrecondViolatedExcep: Throw error if the queue is empty
   * @return: none
   */

   void dequeue() throw(PrecondViolatedExcep);

   /*
   * @pre: Queue is made and not empty
   * @post: Entry at the top of the queue is returned
   * @throw PrecondViolatedExcep: Throw error if the queue is empty
   * @return: Entry at the top of the queue as a T
   */

   T peekFront()const throw(PrecondViolatedExcep);

   /*
   * @pre: Queue is made
   * @post: Queue is deleted
   * @return: none
   */

   ~Queue();
 private:
   ListInterface<T>* m_list;
   int length;
 };
 #include "Queue.cpp"
 #endif
