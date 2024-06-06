/* Hiep Tran - Heap.h - CS010C */

#pragma once    
#include "PrintJob.h"

const int MAX_HEAP_SIZE = 10; //Max size of the heap

class Heap {
    private:
        PrintJob* arr[MAX_HEAP_SIZE]; //Array of PrintJob pointers
        int numItems; //Current number of items in heap
    public:
        Heap(); //Default Constructor
        ~Heap(); //Destructor
        Heap(const Heap& copyHeap); //Copy Constructor
        Heap& operator=(const Heap& copyHeap); //Copy Assignment Operator
        void enqueue(PrintJob* job); //Insert a PrintJob to the heap
        void dequeue(); //Remove the node with highest priority
        PrintJob* highest() const; //Return the node with highest priority
        void print() const; //Print the PrintJob with highest priority
    private:
        void trickleDown(int); //Move the new root down the heap to the appropriate location
};