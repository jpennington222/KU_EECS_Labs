/*
 * @Author: Joseph Pennington
 * @File Name: maxHeap.h
 * @Assignment: EECS 560 Lab 07
 * @Brief: This program is the h file for the maxHeap class.
 */

#ifndef maxHeap_H
#define maxHeap_H
using namespace std;
#include "BSTEntry.h"

template<typename T>
class maxHeap
{
  public:

    /*
		* @pre: none
		* @post: maxHeap is created
		* @return: none
		*/
    maxHeap();

    /*
		* @pre: maxHeap built
		* @post: maxHeap deleted
		* @return: none
		*/

    ~maxHeap();

    /*
		* @pre: none
		* @post: Contents are read from file and saved to heap
		* @param filename: A string represting the file name
		* @return: none
		*/

    void buildHeap(std::string filename);

    /*
		* @pre: Heap built
		* @post: Heap is sorted
		* @return: none
		*/

    void heapify();

    /*
		* @pre: Heap built
		* @post: Entry inserted into the heap
		* @param entry: Entry to be added
		* @return: none
		*/

    void insert(T entry);

    /*
		* @pre: Heap built
		* @post: An entry is deleted and another entry's key is updated
		* @param entry: Entry to be re-add/key updated
		* @return: none
		*/

    void deleteEntry(T entry);

    /*
		* @pre: Heap built
		* @post: Computes parent location
		* @param childLocation: Location of the child
		* @return: Index of the parent
		*/

    int getParent(int childLocation);

    /*
		* @pre: Heap built
		* @post: Computes the first child location
		* @param parentLocation" Location of the parent
		* @return: Index of first child
		*/

    int getFirstChild(int parentLocation);

    /*
		* @pre: Heap built
		* @post: Computes how mant children an entry has
		* @param parentLocation: Location of the parent
		* @return: Number of children
		*/

    int numberOfChildren(int parentLocation);

    /*
		* @pre: Heap built
		* @post: Computes the index of the first leaf
		* @return: Index of first leaf
		*/

    int firstLeafLocation();

    /*
		* @pre: Heap built
		* @post: Computes the index of the last parent
		* @return: Index of the last parent
		*/

    int lastParent();

    /*
    * @pre: Heap built
    * @post: Computes if an entry has children
    * @param location: Index to check
    * @return: True if has children, otherwise false
    */

    bool isParent(int location);

    /*
		* @pre: Heap built
		* @post: Computes if an entry is a leaf
		* @param location: Index to check
		* @return: True if a leaf, otherwise false
		*/

    bool isLeaf(int location);

    /*
    * @pre: Heap built
    * @post: Maximum value is deleted
    * @return: True if deleted, otherwise false
    */

    bool deleteMax();

    /*
		* @pre: Heap built
		* @post: Minimum value is deleted
		* @return: True if deleted, otherwise false
		*/

    bool deleteMin();

    /*
		* @pre: Heap built
		* @post: The maximum value is found
		* @return: none
		*/

    void findMax();

    /*
		* @pre: Heap built
		* @post: The minimum value is found
		* @return: none
		*/

    void findMin();

    /*
		* @pre: Heap built
		* @post: The heap is printed in level order
		* @return: none
		*/

    void levelOrder();

    /*
    * @pre: Heap built
    * @post: Entries are swapped to maintain heap order
    * @param parent: Index of parent
    * @return: none
    */

    void swap(int parent);

    /*
		* @pre: Heap built
		* @post: added is returned
		* @return: True if true, otherwise false
		*/

    bool getAdded();

    /*
		* @pre: Heap built
		* @post: itemCount is returned
		* @return: How many entries in the heap
		*/

    int getItemCount();

    /*
		* @pre: Heap built
		* @post: Computes the position in the heap
		* @param first: First name
    * @param last: Last name
		* @return: The position in the heap
		*/

    int position(std::string first, std::string last);

    /*
		* @pre: Heap built
		* @post: Computes if an entry is in the heap and prints contents
		* @param first: First name
    * @param last: Last name
		* @return: True if in the heap, otherwise false
		*/

    bool current(std::string first, std::string last);

  private:

    //Heap Array
    T m_arr[500];

    //How many entries in the heap
    int itemCount;

    //If an entry was added
    bool added = true;

  };
  #include "maxHeap.cpp"
  #endif
