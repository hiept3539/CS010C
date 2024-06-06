/* Hiep Tran - BSTree.cpp - CS010C */

#include "BSTree.h"
#include <iostream>
#include <stdexcept>

using namespace std;

//Default Constructor that sets the root to nullptr
BSTree::BSTree() {
    root = nullptr;
}

//Destructor that deletes the tree with the remove function
BSTree::~BSTree() {
    while(root != nullptr) {
        remove(root->key);
    }
}

//Copy Constructor that creates a deep copy of the tree
BSTree::BSTree(const BSTree& copyTree) {
    //Calls the deepCopy helper function
    root = deepCopy(copyTree.root);
}

//Copy Assignment Operator that creates a deep copy of the tree
BSTree& BSTree::operator=(const BSTree& rhs) {
    if (this != &rhs) { //Check for self-assignment
        clearTree(root);
        root = deepCopy(rhs.root); 
    }
    return *this;
}

//Helper function for Copy Constructor & Copy Assignment Operator
Node* BSTree::deepCopy(const Node* currNode) {
    //Returns nullptr if the tree to copy is empty
    if (currNode == nullptr) {
        return nullptr;
    }
    //Creates a new Node with the key and count of the current Node
    Node* newNode = new Node(currNode->key);
    newNode->count = currNode->count;
    //Recursively creates a deep copy of the left and right pointers
    newNode->left = deepCopy(currNode->left);
    newNode->right = deepCopy(currNode->right);
    return newNode;
}

//Helper function for Copy Assignment Operator 
void BSTree::clearTree(Node* currNode) {
    //Recursively deletes the tree before copying the new one
    if (currNode != nullptr) {
        clearTree(currNode->left);
        clearTree(currNode->right);
        delete currNode;
    }
}

//Function that Inserts a node into the tree
void BSTree::insert(const string& key) { 
    //Base case if the tree is empty, sets root to a new Node with the key
    if (root == nullptr) {
        root = new Node(key);
        return;
    }
    //Traverses the tree to find the correct spot to insert the key
    for (Node* currNode = root; currNode != nullptr;) {
        //Case if the key is already in the tree, increment the count
        if (currNode->key == key) {
            ++currNode->count;
            return;
        }
        //Case if the key is less than the current Node's key, go left
        if (currNode->key > key) {
            //If the left pointer is nullptr, insert the key
            if (currNode->left == nullptr) {
                currNode->left = new Node(key);
                return;
            }
            else {
                currNode = currNode->left;
            }
        }
        //Case if the key is greater than the current Node's key, go right
        else {
            //If the right pointer is nullptr, insert the key
            if (currNode->right == nullptr) {
                currNode->right = new Node(key);
                return;
            }
            else {
                currNode = currNode->right;
            }
        }
    }
}

//Function that Searches for a node in the tree and returns true or false
bool BSTree::search(const string& key) const {
    //Calls the helper function to search for the key
    return search(root, key);
}

//Function that Searches for a node in the tree and returns true or false
bool BSTree::search(const Node* currNode, const string& key) const {
    //Base case if the tree is empty
    if (currNode == nullptr) {
        return false;
    }
    //Case if the key is found, return true
    if (currNode->key == key) {
        return true;
    }
    //Case if the key is less than the current Node's key, go left
    else if (currNode->key < key) {
        return search(currNode->right, key);
    }
    //Case if the key is greater than the current Node's key, go right
    else {
        return search(currNode->left, key);
    }
}

//Function that Searches for a node in the tree and returns a pointer to the node
Node* BSTree::searchNode(Node* currNode, const string& key) const {
    //Base case if the tree is empty
    if (currNode == nullptr) {
        return nullptr;
    }
    //Case if the key is found, return the pointer to the node
    if (currNode->key == key) {
        return currNode;
    }
    //Case if the key is less than the current Node's key, go left
    else if (currNode->key < key) {
        return searchNode(currNode->right, key);
    }
    //Case if the key is greater than the current Node's key, go right
    else {
        return searchNode(currNode->left, key);
    }
}

//Function that Searches for the parent of a node in the tree and returns a pointer to the parent
Node* BSTree::searchParent(const Node* childNode) const {
    //Base case if the tree is empty
    Node* currNode = root;
    if (childNode == nullptr) {
        return nullptr;
    }
    //Case if the childNode is the root, return nullpr
    else if (childNode == root) {
        return nullptr;
    }
    //Traverses the tree to find the parent of the childNode
    while (currNode != nullptr) {
        //Case if the currNode's left or right pointer is the childNode, return the currNode
        if (currNode->left == childNode || currNode->right == childNode) {
            return currNode;
        }
        //Case if the childNode's key is greater than the currNode's key, go right
        else if (currNode->key < childNode->key) {
            currNode = currNode->right;
        }
        //Case if the childNode's key is greater than the currNode's key, go left
        else {
            currNode = currNode->left;
        }
    }
    return nullptr;
}

//Function that returns the largest node in the tree
string BSTree::largest() const {
    //Base case if the tree is empty
    if (root == nullptr) {
        return "";
    }
    //Traverses the tree to find the largest node
    Node* currNode = root;
    while (currNode->right != nullptr) {
        currNode = currNode->right;
    }
    return currNode->key;
}

//Function that returns the smallest node in the tree
string BSTree::smallest() const {
    //Base case if the tree is empty
    if (root == nullptr) {
        return "";
    }
    //Traverses the tree to find the smallest node
    Node* currNode = root;
    while (currNode->left != nullptr) {
        currNode = currNode->left;
    }
    return currNode->key;
}

//Function that returns the height of a node in the tree
int BSTree::height(const string& key) const {
    //Checks if the key is in the tree
    Node* currNode = searchNode(root, key);
    // If the key is not in the tree, return -1
    if (currNode == nullptr) {
        return -1;
    }
    //Calls the helper function to find the height of the node
    else {
        //Subtract 1 from the height to account for the root
        return height_of(currNode) - 1;
    }
}

//Helper function for height
int BSTree::height_of(const Node* currNode) const {
    //Base case if the tree is empty
    if (currNode == nullptr) {
        return 0;
    }
    //Recursively finds the height of the tree
    int treeHeightLeft = height_of(currNode->left);
    int treeHeightRight = height_of(currNode->right);
    int maxHeight;
    //Returns the maximum height of the left and right subtrees
    if (treeHeightLeft > treeHeightRight) {
        maxHeight = treeHeightLeft;
    }
    else {
        maxHeight = treeHeightRight;
    }
    //Add 1 to the height to account for the currNode
    return maxHeight + 1;
}

//Function that removes a node from the tree
void BSTree::remove(const string& key) {
    //Base case if the key is not in the tree
    if (!search(key)) {
        return;
    }
    //Calls the helper function to remove the key
    if (root!= nullptr) {
        Node* removeNode = searchNode(root, key);
        if (removeNode!= nullptr) {
            //Finds the parentNode of the removeNode
            Node* parentNode = searchParent(removeNode);
            recursiveRemove(parentNode, removeNode, key);
        }
    }
}

//Helper function for remove
void BSTree::recursiveRemove(Node* parentNode, Node* currNode, const string& key) {
    //Base case if the tree is empty
    if (currNode == nullptr) {
        return;
    }
    //Case if the key is less than the current Node's key, go left
    if (currNode->key < key) {
        recursiveRemove(currNode, currNode->right, key);
    } 
    //Case if the key is greater than the current Node's key, go right
    else if (currNode->key > key) {
        recursiveRemove(currNode, currNode->left, key);
    } 
    //Case if the key is found
    else {
        //Case if the count is greater than 1, decrement the count
        if (currNode->count > 1) {
            --currNode->count;
            return;
        }
        //Case if the node is a leaf, delete the node
        if (currNode->left == nullptr && currNode->right == nullptr) {
            if (parentNode == nullptr) {
                delete currNode;
                root = nullptr; 
            } 
            else {
                //Case if the node is the left child of the parentNode
                if (parentNode->left == currNode) {
                    parentNode->left = nullptr;
                } 
                //Case if the node is the right child of the parentNode
                else {
                    parentNode->right = nullptr;
                }
                delete currNode;
            }
            return;
        }
        //Case if the node has one child, replace the node with the child
        Node* targetNode = nullptr;
        if (currNode->left != nullptr) {
            //Find the largest node in the left subtree
            targetNode = currNode->left;
            while (targetNode->right!= nullptr) {
                targetNode = targetNode->right;
            }
        } 
        //Find the smallest node in the right subtree
        else {
            targetNode = currNode->right;
            while (targetNode->left != nullptr) {
                targetNode = targetNode->left;
            }
        }
        //Replace the node with the targetNode
        currNode->key = targetNode->key;
        currNode->count = targetNode->count;
        targetNode->count = 1;  //Reset the count to 1 to avoid duplicates
        //Recursively remove the targetNode
        if (currNode->left != nullptr) {
            recursiveRemove(currNode, currNode->left, targetNode->key);
        }
        else {
            recursiveRemove(currNode, currNode->right, targetNode->key);
        }
    }
}

//Function that prints the tree in pre-order
void BSTree::preOrder() const {
    preOrder(root);
    cout << endl;
}

//Helper function for preOrder
void BSTree::preOrder(const Node* currNode) const {
    if (currNode != nullptr) {
        //Prints before recursively calling the left and right subtrees
        cout << currNode->key << "(" << currNode->count << "), ";
        preOrder(currNode->left);
        preOrder(currNode->right);
    }
}

//Function that prints the tree in post-order
void BSTree::postOrder() const {
    postOrder(root);
    cout << endl;
}

//Helper function for postOrder
void BSTree::postOrder(const Node* currNode) const {
    if (currNode != nullptr) {
        //Recursively calls the left and right subtrees before printing
        postOrder(currNode->left);
        postOrder(currNode->right);
        cout << currNode->key << "(" << currNode->count << "), ";
    }
}

//Function that prints the tree in in-order
void BSTree::inOrder() const {
    inOrder(root);
    cout << endl;
}

//Helper function for inOrder
void BSTree::inOrder(const Node* currNode) const {
    if (currNode != nullptr) {
        //Recursively calls the left subtree, prints, then calls the right subtree
        inOrder(currNode->left);
        cout << currNode->key << "(" << currNode->count << "), ";
        inOrder(currNode->right);
    }
}
