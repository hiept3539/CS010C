/* Hiep Tran - Tree.h - CS010C */

#pragma once
#include "Node.h"

using std::string;

class Tree {
    public: 
        Tree(); //Default Constructor
        ~Tree(); //Destructor
        Tree(const Tree&); //Copy Constructor
        Tree& operator=(const Tree&); //Copy Assignment
        void insert(const string &); //Inserts a word into the tree
        void preOrder() const; //Prints the tree in pre-order recursively
        void inOrder() const; //Prints the tree in in-order recursively    
        void postOrder() const; //Prints the tree in post-order recursively
        void remove(const string &); //Removes a word from the tree
        Node* search(const string &); //Searches for a word in the tree
    private:
        Node* root; //Root of the tree
    private:
        Node* nodeSplit(Node* currNode, const string& word); //Splits a node when full
        void clearTree(Node* currNode); //Clears the tree
        Node* deepCopy(const Node* curr); //Deep copy helper function for copy constructor and copy assignment
        bool noChildren(Node* currNode) const; //Checks if a node has no children
        void insert(Node* currNode, const string& word); //Helper function for insert
        void addData(Node* addHere, const string& word); //Adds a word to a node
        void preOrder(const Node* currNode) const; //Helper function for preOrder
        void inOrder(const Node* currNode) const; //Helper function for inOrder
        void postOrder(const Node* currNode) const; //Helper function for postOrder
        void fix(Node* emptyNode); //Fixes the tree after a node is removed
        bool hasTwoChildSibling(Node* siblingNode) const; //Checks if a node has two children
        void remove(Node* currNode, const string& word); //Helper function for remove
        Node* search(Node* currNode, const string& word); //Helper function for search
};