/* Hiep Tran - AVLTree.cpp - CS010C */

#include "AVLTree.h"
#include <iostream>

using namespace std;

//Default Constructor that sets the root to nullptr
AVLTree::AVLTree() : root(nullptr) {}

//Destructor that clears the tree
AVLTree::~AVLTree() {
    clearTree(root); //Call the helper function to clear the tree
}

//Copy Constructor that creates a deep copy of the AVLTree passed in
AVLTree::AVLTree(const AVLTree& copyTree) {
    root = deepCopy(copyTree.root);
}

//Copy Assignment Operator that creates a deep copy of the AVLTree passed in
AVLTree& AVLTree::operator=(const AVLTree& rhs) {
    if (this != &rhs) { //Check for self-assignment
        clearTree(root); //Call the clearTree helper function
        root = deepCopy(rhs.root);
    }
    return *this;
}

//Helper function for Copy Assignment Operator
void AVLTree::clearTree(Node* currNode) { 
    while (root) {
        //Iteratively go to the farthest on the left subtree
        if (root->left) {
            root = root->left;
        }
        //Iteratively go to the farthest on the right subtree
        else if (root->right) {
            root = root->right;
        }
        else {
            //If the parent is not nullptr, set the left or right child to nullptr
            Node* parent = root->parent;
            if (parent) {
                if (parent->left == root) {
                    parent->left = nullptr;
                }
                else {
                    parent->right = nullptr;
                }
            }
            //Delete the current node and set the root to the parent
            delete root;
            root = parent;
        }
    }
}

//Helper function for Copy Constructor & Copy Assignment Operator
Node* AVLTree::deepCopy(const Node* currNode) {
    if (currNode) {
        //Create a new node with the data of the current node
        Node* newNode = new Node(currNode->data);
        //Recursively create deep copies of the left and right pointers
        newNode->left = deepCopy(currNode->left);
        newNode->right = deepCopy(currNode->right);
        return newNode;
    }
    return nullptr;
}

//Function that Inserts a node into the tree
void AVLTree::insert(const string& key) {
    //If the root is nullptr, create a new node with the key and set it as the root
    if (root == nullptr) {
        root = new Node(key);
        return;
    }
    Node* currNode = root;
    Node* parentNode = nullptr;
    //Find the correct position to insert the new node
    while (currNode != nullptr) {
        parentNode = currNode;
        //If the key is less than the current node, go to the left child
        if (key < currNode->data) {
            currNode = currNode->left;
        } 
        //If the key is greater than the current node, go to the right child
        else if (key > currNode->data) {
            currNode = currNode->right;
        } 
        else {
            //Case where the key is already in the tree
            return;
        }
    }
    //Insert the new node as a child of the parent node
    Node* newNode = new Node(key);
    newNode->parent = parentNode;
    //If the key is less than the parent node, set the new node as the left child
    if (key < parentNode->data) {
        parentNode->left = newNode;
    } 
    else {
        //If the key is greater than the parent node, set the new node as the right child
        parentNode->right = newNode;
    }
    //Find the first unbalanced node
    Node* unbalancedNode = findUnbalancedNode(newNode);
    //If the unbalanced node is not nullptr, rotate the tree at the unbalanced node
    if (unbalancedNode != nullptr) {
        rotate(unbalancedNode);
    }
}

//Function that returns the height of a node
int AVLTree::nodeHeight(const Node* currNode) const {
    //Base case if the node is nullptr, return -1
    if (currNode == nullptr) {
        return -1;
    }
    //Return 1 + the maximum height of the left and right subtrees
    return 1 + max(nodeHeight(currNode->left), nodeHeight(currNode->right));
}



//Function that returns the balance factor of a node
int AVLTree::balanceFactor(const Node* currNode) const {
    //Base case if the node is nullptr, return -1
    if (currNode == nullptr) {
        return -1;
    }
    //Return the difference in height of the left and right subtrees
    return nodeHeight(currNode->left) - nodeHeight(currNode->right);
}

//Function that finds the first unbalanced node
Node* AVLTree::findUnbalancedNode(Node* currNode) {
    while (currNode) {
        //If the balance factor of the current node is greater than 1 or less than -1, return the current node
        if (balanceFactor(currNode) > 1 || balanceFactor(currNode) < -1) {
            return currNode;
        }
        //Set the current node as the parent
        currNode = currNode->parent;
    }
    return nullptr;
}

//Function that rotates the tree at the node, either right or left
void AVLTree::rotate(Node* currNode) {
    //If the current node is nullptr, return
    if (currNode == nullptr) {
        return;
    }
    //If the balance factor is greater than 1, rotate right (Heavy on the left)
    if (balanceFactor(currNode) == 2) {
        //If the balance factor of the left child is less than 0, rotate left (Zig-Zag)
        if (balanceFactor(currNode->left) == -1) {
            rotateLeft(currNode->left);
        }
        rotateRight(currNode);
    }
    //If the balance factor is less than -1, rotate left (Heavy on the right)
    else if (balanceFactor(currNode) == -2) {
        //If the balance factor of the right child is greater than 0, rotate right (Zig-Zag)
        if (balanceFactor(currNode->right) == 1) {
            rotateRight(currNode->right);
        }
        rotateLeft(currNode);
    }
}

//Function that rotates the tree to the left at the node
void AVLTree::rotateLeft(Node* currNode) {
    //If the current node is nullptr, return
    if (currNode == nullptr) {
        return;
    }
    Node* rightNode = currNode->right;
    Node* rightLeftNode = rightNode->left;
    Node* parent = currNode->parent;
    //If the parent is nullptr, set the right node as the root
    if (parent == nullptr) {
        root = rightNode;
    }
    else {
        //If the current node is the left child, set the right node as the left child
        if (currNode == parent->left) {
            parent->left = rightNode;
        }
        //If the current node is the right child, set the right node as the right child
        else {
            parent->right = rightNode;
        }
    }
    //Set the current node as the left child of the right node
    rightNode->left = currNode;
    currNode->parent = rightNode;
    //Set the left child of the right node as the right left node
    currNode->right = rightLeftNode;
    //If the right left node is not nullptr, set the parent to the current node
    if (rightLeftNode) {
        rightLeftNode->parent = currNode;
    }
    rightNode->parent = parent;
}

//Function that rotates the tree to the right at the node
void AVLTree::rotateRight(Node* currNode) {
    //If the current node is nullptr, return
    if (currNode == nullptr) {
        return;
    }
    Node* leftNode = currNode->left;
    Node* leftRightNode = leftNode->right;
    Node* parent = currNode->parent;
    //If the parent is nullptr, set the left node as the root
    if (parent == nullptr) {
        root = leftNode;
    }
    else {
        //If the current node is the left child, set the left node as the left child
        if (currNode == parent->left) {
            parent->left = leftNode;
        }
        //If the current node is the right child, set the left node as the right child
        else {
            parent->right = leftNode;
        }
    }
    //Set the current node as the right child of the left node
    leftNode->right = currNode;
    currNode->parent = leftNode;
    //Set the right child of the left node as the left right node
    currNode->left = leftRightNode;
    //If the left right node is not nullptr, set the parent to the current node
    if (leftRightNode) {
        leftRightNode->parent = currNode;
    }
    leftNode->parent = parent;
}

//Function that prints the balance factors of all nodes in the tree
void AVLTree::printBalanceFactors() const {
    printBalanceFactors(root); //Call the helper function to print the balance factors
}

//Helper function to print the balance factors of all nodes in the tree
void AVLTree::printBalanceFactors(const Node* currNode) const {
    if (currNode) {
        //Recursively print the balance factors of the left and right subtrees
        printBalanceFactors(currNode->left);
        cout << currNode->data << "(" << balanceFactor(currNode) << "), ";
        printBalanceFactors(currNode->right);
    }
}

