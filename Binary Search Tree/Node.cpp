/* Hiep Tran - Node.cpp - CS010C */

#include "Node.h"
#include <iostream>

using namespace std;

//Default Constructor that sets count to 0 and left and right pointers to nullptr
Node::Node() : count(0), left(nullptr), right(nullptr) {}

//Constructor that takes a string parameter and sets the key to the parameter, count to 1, and left and right pointers to nullptr
Node::Node(const string& data) : key(data), count(1), left(nullptr), right(nullptr) {}

//Destructor that deletes the left and right pointers
Node::~Node() {
    delete left;
    delete right;
}

//Copy Constructor that creates a deep copy of the Node passed in
Node::Node(const Node& copyNode) {
    this->key = copyNode.key;
    this->count = copyNode.count;
    //Create a deep copy of the left and right pointers
    if (copyNode.left != nullptr) {
        this->left = new Node(*copyNode.left);
    }
    else {
        this->left = nullptr;
    }
    if (copyNode.right != nullptr) {
        this->right = new Node(*copyNode.right);
    }
    else {
        this->right = nullptr;
    }
}

//Copy Assignment Operator that creates a deep copy of the Node passed in
Node& Node::operator=(const Node& rhs) {
    if (this != &rhs) { //Check for self-assignment
        this->key = rhs.key;
        this->count = rhs.count;
        //Delete the left and right pointers
        delete this->left;
        delete this->right;
        //Create a deep copy of the left and right pointers
        if (rhs.left != nullptr) {
            this->left = new Node(*rhs.left);
        }
        if (rhs.right != nullptr) {
            this->right = new Node(*rhs.left);
        }
    }
    //Return the Node
    return *this;
}

//Overloads the stream insertion operator to cout Node information
ostream& operator<<(ostream& outFS, const Node& tree) {
    outFS << tree.key << "(" << tree.count << ")";
    return outFS;
}