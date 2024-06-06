/* Hiep Tran - Node.h - CS010C */

#pragma once
#include <string> 

using std::string;

class Node {
    friend class Tree; //Allows Tree class to access private members
    public:
        Node(); //Default Constructor
        explicit Node(const string& key); //Constructor 
    private:
        string small; //Stores the smaller string
        string large; //Stores the larger string
        int numData; //Stores the number of data in the node
        Node* parent; //Stores the parent node
        Node* left; //Stores the left child node
        Node* middle; //Stores the middle child node
        Node* right; //Stores the right child node
};