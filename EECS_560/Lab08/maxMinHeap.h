/*
 * @Author: Joseph Pennington
 * @File Name: maxMinHeap.cpp
 * @Assignment: EECS 560 Lab 08
 * @Brief: This is the h file for the maxMinHeap class.
 */

#ifndef maxMinHeap_H
#define maxMinHeap_H
#include "math.h"
#include "BSTEntry.h"
using namespace std;
template<typename T>
class maxMinHeap
{
  public:

    /*
  	* @pre: none
  	* @post: A heap is made
  	* @return: none
  	*/

    maxMinHeap();

    /*
    * @pre: none
    * @post: A heap is deleted
    * @return: none
    */

    ~maxMinHeap();

    /*
    * @pre: Heap made
    * @post: Private variable added is returned
    * @return: True if true, otherwise false
    */

    bool getAdded();

    /*
    * @pre: Heap made
    * @post: Private variable itemCount is returned
    * @return: itemCount
    */

    int getItemCount();

    /*
    * @pre: Heap made
    * @post: Heap is reordered
    * @return: None
    */

    void heapify();

    /*
    * @pre: Heap made
    * @post: Entries on minimum levels are swapped if needed
    * @param parent: Index of parent
    * @return: None
    */

    void swapMin(int parent);

    /*
    * @pre: Heap made
    * @post: Entries on maximum levels are swapped if needed
    * @param parent: Index of parent
    * @return: None
    */

    void swapMax(int parent);

    /*
    * @pre: Heap made
    * @post: Entries in the heap are swapped
    * @param one: Index one to swap
    * @param two: Index two to swap
    * @return: None
    */

    void swapLocations(int one, int two);

    /*
    * @pre: Heap made
    * @post: Determines which of two entries is smaller
    * @param entryOne: Index one to compare
    * @param entryTwo: Index two to compare
    * @return: None
    */

    int min(int entryOne, int entryTwo);

    /*
    * @pre: Heap made
    * @post: Determines which of two entries is larger
    * @param entryOne: Index one to compare
    * @param entryTwo: Index two to compare
    * @return: None
    */

    int max(int entryOne, int entryTwo);

    /*
    * @pre: Heap made
    * @post: Finds index of the largest grandchild
    * @param grandparent: Index of grandparent
    * @return: Index of largest grandchild
    */

    int maxGrandChild(int grandparent);

    /*
    * @pre: Heap made
    * @post: Finds index of the smalles grandchild
    * @param grandparent: Index of grandparent
    * @return: Index of smallest grandchild
    */

    int minGrandChild(int grandparent);

    /*
    * @pre: Heap made
    * @post: Inserts entry into heap
    * @param entry: Entry to be added
    * @return: None
    */

    void insert(T entry);

    /*
    * @pre: Heap made
    * @post: Removes the entry at the location
    * @param location: Index to remove
    * @return: None
    */

    void deleteLocation(int location);

    /*
    * @pre: Heap made
    * @post: Finds index of the last parent
    * @return: Index of the last parent
    */

    int lastParent();

    /*
    * @pre: Heap made
    * @post: Deletes max priority item
    * @return: True if added, otherwise false
    */

    bool deleteMax();

    /*
    * @pre: Heap made
    * @post: Finds index of the entry to delete
    * @param name: Name of game
    * @param key: Key of game
    * @return: True if found, otherwise false
    */

    bool generalDelete(std::string name, int key);

    /*
    * @pre: Heap made
    * @post: Finds maximum priority item
    * @return: Max priority item
    */

    T findMax();

    /*
    * @pre: Heap made
    * @post: Finds minimum priority item
    * @return: Min priority item
    */

    T findMin();

    /*
    * @pre: Heap made
    * @post: Prints heap in level order
    * @return: None
    */

    void levelOrder();

    /*
    * @pre: Heap made
    * @post: Prints min level items
    * @return: None
    */

    void printMins();

    /*
    * @pre: Heap made
    * @post: Prints max level items
    * @return: None
    */

    void printMaxs();

    /*
    * @pre: Heap made
    * @post: Adds keys from min levels
    * @return: Sum of keys
    */

    int totalMins();

    /*
    * @pre: Heap made
    * @post: Adds keys from max levels
    * @return: Sum of keys
    */

    int totalMaxs();

    /*
    * @pre: Heap made
    * @post: Returns if itemcount is 0
    * @return: True if empty, otherwise false
    */

    bool isEmpty();

  private:

    //MaxMin Array
    T m_arr[20];

    //Total number of entries
    int itemCount;

    //If an entry was added
    bool added;
  };
  #include "maxMinHeap.cpp"
  #endif
