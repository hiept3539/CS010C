/* Hiep Tran - AVLTree.h - CS010C */

#pragma once
#include "Node.h"

//AVL Tree class that contains a root Node pointer
class AVLTree {
    Node* root; //Keep track of the root of the tree
    
    public:
        AVLTree(); //Default Constructor
        ~AVLTree(); //Destructor
        AVLTree(const AVLTree&); //Copy Constructor
        AVLTree& operator=(const AVLTree&); //Copy Assignment Operator
        void insert(const string&); //Insert a node into the tree
        int balanceFactor(const Node*) const; //Return the balance factor of a node
        void printBalanceFactors() const; //Print the balance factors of all nodes in the tree
    
    private:
        void clearTree(Node*); //Function to clear the tree
        Node* deepCopy(const Node*); //Function to deep copy the tree
        
        Node* findUnbalancedNode(Node*); //Find the first unbalanced node
        void rotate(Node*); //Rotate the tree at the node
        void rotateLeft(Node*); //Rotate the tree to the left at the node
        void rotateRight(Node*); //Rotate the tree to the right at the node
        
        void printBalanceFactors(const Node*) const; //Helper function to print the balance factors of all nodes in the tree
        int nodeHeight(const Node*) const; //Function to get the height of the node
};