/* Hiep Tran - Node.cpp - CS010C */

#include "Node.h"
#include <iostream>

//Default Constructor that sets the parent, left, and right pointers to nullptr
Node::Node() : parent(nullptr), left(nullptr), right(nullptr) {}

//Constructor that takes a string parameter
Node::Node(const string& data) : data(data), parent(nullptr), left(nullptr), right(nullptr) {}

//Destructor that deletes the left and right pointers
Node::~Node() {
    delete left;
    delete right;
}

//Copy Constructor that creates a deep copy of the Node passed in
Node::Node(const Node& copyNode) {
    this->data = copyNode.data;
    //Create a deep copy of the left pointer
    if (copyNode.left != nullptr) {
        this->left = new Node(*copyNode.left);
    }
    else {
        this->left = nullptr;
    }
    //Create a deep copy of the right pointer
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
        this->data = rhs.data;
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
