/*
 * @Author: Joseph Pennington
 * @File Name: QueueInterface.h
 * @Assignment: EECS 268 Lab 03
 * @Date: 09/24/2018
 * @Brief: This program is the template for the QueueInterface. It declares the destructor, isEmpty, enqueue, dequeue, and peekfront functions
 */

 #ifndef QUEUEINTERFACE_H
 #define QUEUEINTERFACE_H

 #include "PrecondViolatedExcep.h"

 template<typename T>
 class QueueInterface
 {
 public:

   /*
   * @pre: Queue is made and not empty
   * @post: Entry at the top of the queue is removed
   * @throw PrecondViolatedExcep: Throw error if the queue is empty
   * @return: none
   */

   virtual ~QueueInterface() {}

   /*
   * @pre: Queue must be made
   * @post: Determines if Queue is empty
   * @return: Return true if the queue is empty and false if not
   */

   virtual bool isEmpty() const = 0;

   /*
   * @pre: Queue must be made
   * @post: Entry is added to the back of the queue
   * @param newEntry: Entry that is being added to the queue
   * @throw PrecondViolatedExcep: Throw error if no memory is available
   * @return: none
   */

   virtual void enqueue(const T& newEntry) throw(PrecondViolatedExcep) = 0;

   /*
   * @pre: Queue is made and not empty
   * @post: Entry at the top of the queue is removed
   * @throw PrecondViolatedExcep: Throw error if the queue is empty
   * @return: none
   */

   virtual void dequeue() throw(PrecondViolatedExcep) = 0;

   /*
   * @pre: Queue is made and not empty
   * @post: Entry at the top of the queue is returned
   * @throw PrecondViolatedExcep: Throw error if the queue is empty
   * @return: Entry at the top of the queue as a T
   */

   virtual T peekFront() const throw(PrecondViolatedExcep) = 0;
 };
 #endif
