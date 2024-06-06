/* Hiep Tran - Node.cpp - CS010C */

#include "Node.h"

//Default Constructor that initializes the data members
Node::Node() : numData(1), parent(nullptr), left(nullptr), middle(nullptr), right(nullptr) {}

//Constructor that initializes the data members and sets the small string to the key
Node::Node(const string& word) : small(word), numData(1), parent(nullptr), left(nullptr), middle(nullptr), right(nullptr) {}