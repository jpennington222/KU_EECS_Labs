/*
 * @Author: Joseph Pennington
 * @File Name: minHeap.h
 * @Assignment: EECS 560 Lab 10
 * @Brief: This program is the h file for the minHeap class.
 */

#ifndef minHeap_H
#define minHeap_H
using namespace std;
template<typename T>
class minHeap
{
  public:

   /*
   * @pre: none
   * @post: minHeap is created
   * @return: none
   */

    minHeap();

    /*
    * @pre: minHeap built
    * @post: minHeap deleted
    * @return: none
    */

    ~minHeap();

    /*
    * @pre: none
    * @post: Array implementation of heap
    * @return: none
    */

    minHeap(T arr[], int size);

    /*
    * @pre: Heap made
    * @post: Computes if heap is empty
    * @return: True if empty, otherwise false
    */

    bool isEmpty();

    /*
		* @pre: none
		* @post: Contents are read from file and saved to heap
		* @param filename: A string represting the file name
		* @return: none
		*/

    void buildHeap(char* filename);

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

    T findMax();

    /*
    * @pre: Heap built
    * @post: The minimum value is found
    * @return: none
    */

    T findMin();

    /*
    * @pre: Heap built
    * @post: Prints heap in level order
    * @return: none
    */

    void levelOrder();

    /*
    * @pre: Heap built
    * @post: Prints heap in level order
    * @return: none
    */

    void testPrint();

    /*
    * @pre: Heap built
    * @post: Entries are swapped to maintain heap order
    * @param parent: Index of parent
    * @return: none
    */
    void swap(int parent);

  private:

    //Heap Array
    T* m_arr;

    //How many entries in the heap
    int itemCount;

    /*
    * @pre: Heap built
    * @post: Moves down heap array
    * @index: Current index
    * @return: none
    */

    void downHeap(int index);

    /*
    * @pre: Heap built
    * @post: Finds location of first leaf
    * @return: Index of leaf
    */

    int firstLeafLocation();

  };
  #include "minHeap.cpp"
  #endif
