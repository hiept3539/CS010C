/* Hiep Tran - Node.h - CS010C */

#pragma once
#include <iostream>
#include <string>

using std::string;
using std::ostream;

//Node class that contains a string data and three Node pointers
struct Node {
    string data;
    Node* parent; //Keep track of the parent
    Node* left; //Keep track of the left child
    Node* right; //Keep track of the right child

    Node(); //Default Constructor
    Node(const string& data); //Constructor that takes a string parameter
    ~Node(); //Destructor 
    Node(const Node& copyNode); //Copy Constructor
    Node& operator=(const Node& rhs); //Copy Assignment Operator
};