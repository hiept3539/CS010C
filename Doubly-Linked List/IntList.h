/* Hiep Tran - IntList.h - CS010C */

#pragma once

#include <iostream>
#include <string>

struct IntNode {
    int data;
    IntNode *prev;
    IntNode *next;
    IntNode(int data) : data(data), prev(0), next(0) {}
};

class IntList {
    public:
        //Constructor, Destructor, Copy Constructr, and Copy Assignment Operator
        IntList();
        ~IntList();
        IntList(const IntList&);
        IntList& operator=(const IntList&);
        //Public Member Functions
        void push_front(int); //Adds a node to the front of the list
        void pop_front(); //Removes a node from the front of the list
        void push_back(int); //Adds a node to the back of the list
        void pop_back(); //Removes a node from the back of the list
        bool empty() const; //Checks if the list is empty
        //Global Friend Function for Outputting to Stream
        friend std::ostream & operator<<(std::ostream &out, const IntList &rhs);
        void printReverse() const; //Prints the list in reverse
    private:
        //Non-Pointers which are automatically created & destroyed
        IntNode* dummyHead;
        IntNode* dummyTail;
};