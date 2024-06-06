/* Hiep Tran - Heap.cpp - CS010C */

#include "Heap.h"
#include <iostream>

using namespace std;

//Default Constructor for Heap setting numItems to 0
Heap::Heap() : numItems(0) {}

//Destructor for Heap
Heap::~Heap() {
    //Delete all PrintJob pointers in the array by iteration
    for (int i = 0; i < numItems; i++) {
        delete arr[i];
        arr[i] = nullptr; //Avoid dangling pointers
    }
}

//Copy Constructor for Heap
Heap::Heap(const Heap& copyHeap) {
    //Copy the number of items from the copyHeap
    numItems = copyHeap.numItems;
    //Loop to copy the PrintJob pointers
    for (int i = 0; i < numItems; i++) {
        //Create a new PrintJob pointer and copy the PrintJob from the copyHeap
        this->arr[i] = new PrintJob(*copyHeap.arr[i]);
    }
}

//Copy Assignment Operator for Heap
Heap& Heap::operator=(const Heap& copyHeap) {
    //Check for selfassignment before copying
    if (this == &copyHeap) {
        return *this;
    }
    //Delete all PrintJob pointers in the array by iteration
    for (int i = 0; i < numItems; i++) {
        delete arr[i];
    }
    //Copy the number of items from the copyHeap
    numItems = copyHeap.numItems;
    //Loop to copy the PrintJob pointers
    for (int i = 0; i < numItems; i++) {
        //Create a new PrintJob pointer and copy the PrintJob from the copyHeap
        this->arr[i] = new PrintJob(*copyHeap.arr[i]);
    }
    return *this;
}

//Function to insert a PrintJob to the heap
void Heap::enqueue(PrintJob* job) {
    //Check if the heap is full
    if (numItems == MAX_HEAP_SIZE) {
        return;
    }
    //Insert the PrintJob to the end of the array
    arr[numItems] = job;
    int currIndex = numItems;
    //Loop to move the new node up the heap to the appropriate location
    while (arr[currIndex]->getPriority() > arr[(currIndex - 1) / 2]->getPriority() && currIndex > 0) {
        //Swap the PrintJob pointers if the new node has higher priority than its parent
        PrintJob* switchNode = arr[currIndex];
        arr[currIndex] = arr[(currIndex - 1) / 2];
        arr[(currIndex - 1) / 2] = switchNode;
        currIndex = (currIndex - 1) / 2;
    }
    //Increment the number of items in the heap
    ++numItems;
}

//Function to remove the node with highest priority from the heap
void Heap::dequeue() {
    //Check if the heap is empty
    if (numItems == 0) {
        return;
    }
    delete arr[0]; //Delete the PrintJob with highest priority
    arr[0] = arr[numItems - 1]; //Move the last node to the root
    --numItems;
    trickleDown(0); //Calls trickleDown function to move root to correct spot
}

//Function to return the node with highest priority
PrintJob* Heap::highest() const {
    //Check if the heap is empty
    if (numItems == 0) {
        return nullptr;
    }
    return arr[0]; 
}

//Function to print the PrintJob with highest priority
void Heap::print() const {
    //Check if the heap is empty
    if (numItems == 0) {
        return;
    }
    cout << "Priority: " << arr[0]->getPriority() << ", Job Number: " << arr[0]->getJobNumber() << ", Number of Pages: " << arr[0]->getPages() << endl;
}

//Function to move the new root down the heap to the appropriate location
void Heap::trickleDown(int index) {
    //Calculate the left and right child index based on the root index
    int leftIndex = (2 * index) + 1;
    int rightIndex = (2 * index) + 2;
    int maxIndex = index; //Set the maxIndex to the root index
    //Check if the left or right child has higher priority than the root
    if (numItems > leftIndex && arr[leftIndex]->getPriority() > arr[maxIndex]->getPriority()) {
        maxIndex = leftIndex;
    }
    //Check if the right child has higher priority than the root or left child
    if (numItems > rightIndex && arr[rightIndex]->getPriority() > arr[maxIndex]->getPriority()) {
        maxIndex = rightIndex;
    }
    //Swap the root with the child with higher priority
    if (maxIndex != index) {
        PrintJob* switchNode = arr[index];
        arr[index] = arr[maxIndex];
        arr[maxIndex] = switchNode;
        trickleDown(maxIndex); //Recursively call trickleDown function for the swapped node
    }
}
