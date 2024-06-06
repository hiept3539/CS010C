/* Hiep Tran - BSTree.h - CS010C */

#pragma once
#include "Node.h"

//Binary Search Tree class that contains a root Node pointer
class BSTree {
    Node* root; //Keep track of the root of the tree

    public:
        BSTree();//Default Constructor
        ~BSTree(); //Destructor
        BSTree(const BSTree&); //Copy Constructor
        BSTree& operator=(const BSTree&); //Copy Assignmnet Operator

        //Public Member Functions
        void insert(const string& key); //Insert a node into the tree
        bool search(const string& key) const; //Search for a node in the tree
        string largest() const; //Return the largest node in the tree
        string smallest() const; //Return the smallest node in the tree
        int height(const string& key) const; //Return the height of a node in the tree
        void remove(const string& key); //Remove a node from the tree

        void preOrder() const; //Print the tree in pre-order
        void postOrder() const; //Print the tree in post-order
        void inOrder() const; //Print the tree in in-order

    private:
        //Private Member Functions
        Node* deepCopy(const Node* currNode); //Helper function for Copy Constructor
        void clearTree(Node* currNode); //Helper function for Copy Assignment Operator
        
        bool search(const Node* currNode, const string& key) const; //Helper function for search
        Node* searchNode(Node* currNode, const string& key) const; //Search function that returns a pointer to the node
        Node* searchParent(const Node* childNode) const; //Search function that returns a pointer to the parent of the node
        void recursiveRemove(Node* parentNode, Node* currNode, const string& key); //Helper function for remove
        int height_of(const Node* currNode) const; //Helper function for height
        
        void preOrder(const Node* currNode) const; //Helper function for preOrder
        void postOrder(const Node* currNode) const; //Helper function for postOrder
        void inOrder(const Node* currNode) const; //Helper function for inOrder
};