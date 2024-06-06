/* Hiep Tran - IntList.cpp - CS010C */

#include "IntList.h"
#include <iostream>
using namespace std;

IntList::IntList() {
    //Assigns a value to the dH & dT
    dummyHead = new IntNode(-1);
    dummyTail = new IntNode(-1);
    
    //dummyHead points to dummyTail
    dummyHead->next = dummyTail;
    dummyHead->prev = nullptr;
    
    //dummyTail points back to dummyHead
    dummyTail->prev = dummyHead;
    dummyTail->next = nullptr;
}

//Destructor while calls pop_front() to delete the rest of the nodes in the list
IntList::~IntList() {
    while (!empty()) {
        pop_front();
    }
}

//Copy Constructor to copy another passed in list
IntList::IntList(const IntList& copyList) {
    dummyHead = new IntNode(-1);
    dummyTail = new IntNode(-1);
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
    //Assigns a newNode to start at the copyList's head
    IntNode* copyNode = copyList.dummyHead->next;
    while (copyNode != copyList.dummyTail) {
        //Loops through the list to copy & add the nodes from the copyList 
        push_back(copyNode->data);
        copyNode = copyNode->next;
    }
}

//Assignment Operator that overloads the = to allow the comparison of lists
IntList& IntList::operator=(const IntList& copyList) {
    if (this != &copyList) { //Don't self-assign
        while (!empty()) {
            pop_front(); //Deletes the old list if not empty
        }
        IntNode* copyNode = copyList.dummyHead->next;
        while (copyNode != copyList.dummyTail) {
            //Starts at the head of the copyList and adds each node to the new list
            push_back(copyNode->data);
            copyNode = copyNode->next;
        }
    }
    return *this;
} 

//Pushes a newNode containing the value passed in to the front of the list (Mutator)
void IntList::push_front(int value) { //O(1)
    //Creates a newNode and sets it's prev & next valuee to dH's next and dH
    IntNode* newNode = new IntNode(value);
    newNode->next = dummyHead->next;
    newNode->prev = dummyHead;
    //Reassigns the previous dH's prev & next values
    dummyHead->next->prev = newNode; 
    dummyHead->next = newNode;
}

//Deletes the first node of the list (Mutator)
void IntList::pop_front() { //O(1)
    if (!empty()) { //Checks if not empty before executing
        IntNode* frontNode = dummyHead->next;
        //Skips over the original dH's next and sets a new dH's next
        dummyHead->next = frontNode->next;
        dummyHead->next->prev = dummyHead;
        delete frontNode;
        return;
    }
    else {
        //Throws an error if the function is called on an empty list
        throw runtime_error("Error: pop_front on an empty list");
    }
}

//Pushes a newNode containing the value passed in to the back of the list (Mutator)
void IntList::push_back(int value) { //O(1)
    //Creates a newNode with the passed in value
    IntNode* newNode = new IntNode(value);
    //Sets the newNode's next to be the dT to be the last node in the list
    //Connects the dT's old prev's next to newNode and newNode's prev to the old prev
    newNode->prev = dummyTail->prev;
    newNode->next = dummyTail;
    dummyTail->prev->next = newNode;
    dummyTail->prev = newNode;
}

//Deletes the last node of the list (Mutator)
void IntList::pop_back() { //O(1)
    if (!empty()) { //Checks if not empty before executing
        IntNode* backNode = dummyTail->prev;
        //Skips the last node and assigns the dT's prev to the prev of the last node
        dummyTail->prev = backNode->prev;
        dummyTail->prev->next = dummyTail;  
        delete backNode;
        return;
    }
    else {
        //Throws an error if the function is called on an empty list
        throw runtime_error("Error: pop_back on an empty list");
    }
}

//Checks if the list doesn't contain any nodes
bool IntList::empty() const { //O(1)
    //Checks if the only nodes are the dH & dT
    return dummyHead->next == dummyTail;
}

//Overloads the << operator to output to the stream
ostream& operator<<(ostream& out, const IntList& rhs) { //O(n)
    IntNode* writeNode = rhs.dummyHead->next;
    //Iterates through the list to output to the stream 
    while (writeNode != rhs.dummyTail) {
        //Checks if the last node is read to avoid an extra space
        if (writeNode == rhs.dummyTail->prev) {
            out << writeNode->data;
        }
        else {
            out << writeNode->data << ' ';
        }
        writeNode = writeNode->next;
    }
    return out;
}

//Outputs the values of the list of each node from the tail to head
void IntList::printReverse() const { //O(n)
    IntNode* reverseNode = dummyTail->prev;
    //Checks if there are nodes in the list before executing
    while (reverseNode != dummyHead) {
        //Avoids an extra space at the end if the last node is read
        if (reverseNode == dummyHead->next) {
            cout << reverseNode->data;
        }
        else {
            cout << reverseNode->data << ' ';
        }
        reverseNode = reverseNode->prev;
    }
}