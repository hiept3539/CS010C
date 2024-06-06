/* Hiep Tran - Node.h - CS010C */

#pragma once
#include <iostream>
#include <string>

using std::string;
using std::ostream;

//Node class that contains a string key, an integer count, and two Node pointers
struct Node {
    string key;
    int count; //Keep track of the # of times the key appears
    Node* left; //Keep track of the left child
    Node* right; //Keep track of the right child

    Node(); //Default Constructor
    Node(const string& data); //Constructor that takes a string parameter
    ~Node(); //Destructor 
    Node(const Node& copyNode); //Copy Constructor
    Node& operator=(const Node& rhs); //Copy Assignment Operator
    //Overloads the stream insertion operator to cout Node information
    friend ostream& operator<<(ostream &outFS, const Node& tree); //Global Friend Function for Outputting to Stream
};
