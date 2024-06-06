/* Hiep Tran - Tree.cpp - CS010C */

#include "Tree.h"
#include <iostream>
#include <string>

using namespace std;

//Default Constructor
Tree::Tree() {
    root = nullptr;
}

//Destructor
Tree::~Tree() {
    clearTree(root);
}

//Copy Constructor
Tree::Tree(const Tree& copyTree) {
    //Calls the deepCopy function to create a deep copy of the tree
    root = deepCopy(copyTree.root);
}

//Assignment Operator
Tree& Tree::operator=(const Tree& copyTree) {
    if (this != &copyTree) { //Check for self-assignment
        clearTree(root); //Calls the clearTree function to delete the current tree
        root = deepCopy(copyTree.root); //Calls the deepCopy function to create a deep copy of the tree
    }
    return *this;
}

//Function that deletes the tree
void Tree::clearTree(Node* currNode) {
    if (currNode != nullptr) {
        //Recursively deletes the tree
        clearTree(currNode->left);
        clearTree(currNode->middle);
        clearTree(currNode->right);
        delete currNode;
    }
}

//Function that creates a deep copy of the tree
Node* Tree::deepCopy(const Node* currNode) {
    //Base case if the node is null
    if (currNode == nullptr) {
        return nullptr;
    }
    //Creates a new node and copies the data members of the current node
    Node* newNode = new Node;
    newNode->small = currNode->small;
    newNode->large = currNode->large;
    newNode->numData = currNode->numData;
    //Recursively creates a deep copy of the left, middle, and right child nodes
    newNode->left = deepCopy(currNode->left);
    newNode->middle = deepCopy(currNode->middle);
    newNode->right = deepCopy(currNode->right);
    return newNode;
}

//Function that inserts a word into the tree
void Tree::insert(const string& word) {
    if (root == nullptr) {
        //Creates a new node if the tree is empty
        root = new Node(word);
    }
    else {
        //Calls the insert function to insert the word into the tree
        insert(root, word);
    }
}

//Function that inserts a word into the tree
void Tree::insert(Node* currNode, const string& word) {
    //Cause if the node has no children
    if (noChildren(currNode)) {
        //Case if the node has one data
        if (currNode->numData == 1) {
            addData(currNode, word); //Calls the addData function to add the word to the node
        }
        //Case if the node has two data
        else if (currNode->numData == 2) {
            Node* oldParent = nullptr;
            //Case if the parent node is not null
            if (currNode->parent != nullptr) {
                oldParent = currNode->parent; //Sets the old parent node to the current node's parent
            }
            Node* newParent = nodeSplit(currNode, word); //Calls the nodeSplit function to split the node since full
            //Case if the old parent node is not null and has one data
            if (oldParent != nullptr && oldParent->numData == 1) {
                addData(oldParent, newParent->small); //Calls the addData function to add the small string to the oldParent
                //Case if the old parent's large string is the same as the new parent's small string
                if (oldParent->large == newParent->small) {
                    //Copy the middle and right child nodes of the new parent to the oldParent
                    oldParent->middle = newParent->left;
                    oldParent->right = newParent->right;
                }
                //Case if the old parent's small string is the same as the new parent's small string
                else if (oldParent->small == newParent->small) {
                    //Copy the middle and right child nodes of the new parent to the oldParent
                    oldParent->middle = newParent->right;
                    oldParent->left = newParent->left;
                }
            }
            //Case if the old parent node is not null and has two data
            else if (oldParent != nullptr && oldParent->numData == 2) {
                Node* grandParent = nodeSplit(oldParent, newParent->small); //Calls the nodeSplit function to split the oldParent
                //Case if the grandParent doesn't have a parent
                if (grandParent->parent == nullptr) {
                    root = grandParent;
                }
                //Case if the grandParent has a parent
                else {
                    //Swtiches the left and right child nodes of the grandParent's Parent
                    if (grandParent->parent->left == oldParent) {
                        grandParent->parent->left = grandParent;
                    }
                    else if (grandParent->parent->right == oldParent) {
                        grandParent->parent->right = grandParent;
                    }
                }
            }
            //Sets the root to the new parentNode
            if (currNode == root) {
                root = newParent;
            }
        }
    }
    //Case if the node has one data and the word is smaller than the small string
    else if (currNode->numData == 1 && word < currNode->small) {
        insert(currNode->left, word); //Recursively inserts the word into the left child node
    }
    //Case if the node has one data and the word is larger than the small string
    else if (currNode->numData == 1 && word > currNode->small) {
        insert(currNode->right, word); //Recursively inserts the word into the right child node
    }
    //Case if the node has two data and the word is smaller than the small string
    else if (currNode->numData == 2 && word < currNode->small) {
        insert(currNode->left, word); //Recursively inserts the word into the left child node
    }
    //Case if the node has two data and the word is larger than the large string
    else if (currNode->numData == 2 && word > currNode->large) {
        insert(currNode->right, word); //Recursively inserts the word into the right child node
    }
    //Case if the node has two data and the word is between the small and large string
    else if (currNode->numData == 2 && word > currNode->small && word < currNode->large) {
        insert(currNode->middle, word); //Recursively inserts the word into the middle child node
    }
}

//Function that splits a node into two nodes when full
Node* Tree::nodeSplit(Node* currNode, const string& word) {
    Node* newParent = nullptr;
    Node* newChild = nullptr;
    if (currNode->numData == 2) {
        //Case if the word is between the small and large string
        if (currNode->small < word && word < currNode->large) {
            //Creates a new parent node and a new child node (Splits Separately)
            newParent = new Node(word); //Sets the new parent node to the word
            newChild = new Node(currNode->large); //Sets the new child node to the large string 
            currNode->large = "";
            --currNode->numData;
            //Sets the left and right child nodes of the new parent node
            newParent->left = currNode;
            newParent->right = newChild;
            //Sets the parent node of the current node and the new child node
            newChild->parent = newParent;
            currNode->parent = newParent;
        }
        //Case if the word is smaller than the small string
        else if (word < currNode->small) {
            //Creates a new parent node and a new child node (Splits Separately)
            newParent = new Node(currNode->small);
            newChild = new Node(word);
            //Sets the small string to the word and the large string to empty
            currNode->small = currNode->large;
            currNode->large = "";
            --currNode->numData;
            //Sets the left and right child nodes of the new parent node
            newParent->left = newChild;
            newParent->right = currNode;
            //Sets the parent node of the current node and the new child node
            newChild->parent = newParent;
            currNode->parent = newParent;
        }
        //Case if the word is larger than the large string
        else {
            //Creates a new parent node and a new child node (Splits Separately)
            newParent = new Node(currNode->large);
            newChild = new Node(word);
            currNode->large = "";
            --currNode->numData;
            //Sets the left and right child nodes of the new parent node
            newParent->right = newChild;
            newParent->left = currNode;
            //Sets the parent node of the current node and the new child node
            newChild->parent = newParent;
            currNode->parent = newParent;
        }
    }
    return newParent;
}

//Function that adds a word to the node
void Tree::addData(Node* addHere, const string& word) {
    //Adds the word to the node if the word is smaller than the current word
    if (addHere->small < word) {
        addHere->large = word;
        ++addHere->numData;
    }
    //Adds the word to the node if the word is larger than the current word
    else {
        addHere->large = addHere->small;
        addHere->small = word;
        ++addHere->numData;
    }
}

//Function that prints the preorder, inorder, and postorder of the tree
void Tree::preOrder() const {
    preOrder(root);
}

//Helper function that prints the preorder of the tree
void Tree::preOrder(const Node* currNode) const {
    if (currNode == nullptr) {
        return;
    }
    //Case if the node has one data
    if (currNode->numData == 1) {
        cout << currNode->small << ", ";
        //Recursively prints the left and right child nodes
        preOrder(currNode->left);
        preOrder(currNode->right);
    }
    //Case if the node has two data
    else if (currNode->numData == 2) {
        cout << currNode->small << ", ";
        //Recursively prints the left, middle, and right child nodes
        preOrder(currNode->left);
        cout << currNode->large << ", ";
        preOrder(currNode->middle);
        preOrder(currNode->right);
    }
}

//Function that prints the inorder of the tree
void Tree::inOrder() const {
    inOrder(root);
}

//Helper function that prints the inorder of the tree
void Tree::inOrder(const Node* currNode) const {
    //Base case if the node is null
    if (currNode == nullptr) {
        return;
    }
    //Case if the node has one data
    if (currNode->numData == 1) {
        //Recursively prints the left child node and the right child node
        inOrder(currNode->left);
        cout << currNode->small << ", ";
        inOrder(currNode->right);
    }
    //Case if the node has two data
    else if (currNode->numData == 2) {
        //Recursively prints the left, middle, and right child nodes
        inOrder(currNode->left);
        cout << currNode->small << ", ";
        inOrder(currNode->middle);
        cout << currNode->large << ", ";
        inOrder(currNode->right);
    }
}

//Function that prints the postorder of the tree
void Tree::postOrder() const {
    postOrder(root);
}

//Helper function that prints the postorder of the tree
void Tree::postOrder(const Node* currNode) const {
    //Base case if the node is null
    if (currNode == nullptr) {
        return;
    }
    //Case if the node has one data
    if (currNode->numData == 1) {
        //Recursively prints the left and right child nodes
        postOrder(currNode->left);
        postOrder(currNode->right);
        cout << currNode->small << ", ";
    }
    //Case if the node has two data
    else if (currNode->numData == 2) {
        //Recursively prints the left, middle, and right child nodes
        postOrder(currNode->left);
        postOrder(currNode->middle);
        cout << currNode->small << ", ";
        postOrder(currNode->right);
        cout << currNode->large << ", ";
    }
}

//Function that removes a word from the tree
void Tree::remove(const string& word) {
    remove(root, word);
}

//Helper function that removes a word from the tree
void Tree::remove(Node* currNode, const string& word) {
    //Base case if the node is null
    if (currNode == nullptr) {
        return;
    }
    //Case if the node has one data and the word is the same as the small string
    if (currNode->numData == 1 && currNode->small == word) {
        //Case if the node has no children
        if (noChildren(currNode)) {
            if (currNode == root) {
                root = nullptr;
            }
            else {
                //Case if the node is the left child of the parent
                if (currNode->parent->left == currNode) {
                    currNode->parent->left = nullptr;
                    fix(currNode->parent); //Calls the fix function to adjust the tree
                }
                //Case if the node is the right child of the parent
                else if (currNode->parent->right == currNode) {
                    currNode->parent->right = nullptr;
                    fix(currNode->parent); //Calls the fix function to adjust the tree
                }
            }
        }
        else {
            fix(currNode); //Calls the fix function to adjust the tree
        }
    }
    //Case if the node has two data and the word is the same as the small string
    else if (currNode->numData == 2 && currNode->small == word) {
        //Case if the node has no children
        if (noChildren(currNode)) {
            //Case if the node is the root
            if (currNode == root) {
                currNode->small = currNode->large;
                currNode->large = "";
                --currNode->numData;
            }
            else {
                //Case if the node is the left child of the parent
                if (currNode->parent->left == currNode) {
                    currNode->parent->left = nullptr;
                }
                //Case if the node is the right child of the parent
                else if (currNode->parent->right == currNode) {
                    currNode->parent->right = nullptr;
                }
            }
        }
    }
    //Case if the node has two data and the word is the same as the large string
    else if (currNode->numData == 2 && currNode->large == word) {
        //Case if the node has no children
        if (noChildren(currNode)) {
            if (currNode == root) {
                currNode->large = "";
                --currNode->numData;
            }
            else if (currNode->numData == 2) {
                //Case if the node is full and is the smaller string, swtich for larger string
                if (currNode->small == word) {
                    currNode->small = currNode->large;
                    currNode->large = "";
                    --currNode->numData;
                }
                //Case if the node is full and is the larger string, set to empty
                if (currNode->large == word) {
                    currNode->large = "";
                    --currNode->numData;
                }
            }
        }
    }
    //Case if the node has one data and the word is smaller than the small string
    else if (currNode->numData == 1 && word < currNode->small) {
        remove(currNode->left, word);
    }
    //Case if the node has one data and the word is larger than the small string
    else if (currNode->numData == 1 && word > currNode->small) {
        remove(currNode->right, word);
    }
    //Case if the node has two data and the word is smaller than the small string
    else if (currNode->numData == 2 && word < currNode->small) {
        remove(currNode->left, word);
    }
    //Case if the node has two data and the word is larger than the large string
    else if (currNode->numData == 2 && word > currNode->large) {
        remove(currNode->right, word);
    }
    //Case if the node has two data and the word is between the small and large string
    else if (currNode->numData == 2 && word > currNode->small && word < currNode->large) {
        remove(currNode->middle, word);
    }
}

//Function that adjusts the tree after a node is removed
void Tree::fix(Node* emptyNode) {
    //Base case if the node is null
    if (emptyNode == nullptr) {
        return;
    }
    //Case if the node has one data
    if (emptyNode == root) {
        if (emptyNode->left != nullptr && emptyNode->right != nullptr) {
            //Case if the left child has two children of size 1
            if (emptyNode->left->numData == 1 && emptyNode->right->numData == 1) {
                //Combine the left and right child nodes
                emptyNode->left->large = emptyNode->right->small;
                emptyNode->left->numData = 2;
                //Set the left child as the new root
                Node* newRoot = emptyNode->left; 
                emptyNode->right = nullptr;
                delete emptyNode; //Delete the previous single node
                root = newRoot;
            }
        }
        else if (emptyNode->left != nullptr) {
            //Case if the emptyNode has one left child, needs to merge
            if (emptyNode->left->numData == 1) {
                emptyNode->left->large = emptyNode->small;
                emptyNode->left->numData = 2;
                //Set the left child as the new root
                Node* newRoot = emptyNode->left;
                delete emptyNode; //Delete the previous single node
                root = newRoot;
            }
        }
        else if (emptyNode->right != nullptr) {
            //Case if the emptyNode has one right child, needs to merge
            if (emptyNode->right->numData == 1) {
                emptyNode->right->large = emptyNode->right->small;
                emptyNode->right->small = emptyNode->small;
                emptyNode->right->numData = 2;
                //Set the right child as the new root
                Node* newRoot = emptyNode->right;
                delete emptyNode; //Delete the previous single node
                root = newRoot;
            }
        }
    }
}

//Function that searches for a word in the tree
Node* Tree::search(const string& word) {
    return search(root, word);
}

//Helper function that searches for a word in the tree
Node* Tree::search(Node* currNode, const string& word) {
    //Base case if the node is null
    if (currNode == nullptr) {
        return nullptr;
    }
    //Case if the node has one data
    if (currNode->numData == 1) {
        //Case if the word is the same as the small string
        if (currNode->small == word) {
            return currNode;
        }
        else if (word < currNode->small) {
            //Recursively searches the left child node if the word is smaller than the small string
            return search(currNode->left, word);
        }
        else {
            //Recursively searches the right child node if the word is larger than the small string
            return search(currNode->right, word);
        }
    }
    else {
        //Case if the node has two data
        if (currNode->small == word) {
            return currNode;
        }
        else if (word < currNode->small) {
            //Recursively searches the left child node if the word is smaller than the small string
            return search(currNode->left, word);
        }
        //Case if the word is the same as the large string
        else if (currNode->large == word) {
            return currNode;
        }
        else if (word < currNode->large) {
            //Recursively searches the middle child node if the word is between the small and large string
            return search(currNode->middle, word);
        }
        else {
            //Recursively searches the right child node if the word is larger than the large string
            return search(currNode->right, word);
        }
    }
}

//Function that checks if a node has no children
bool Tree::noChildren(Node* currNode) const {
    //Case if the node has no children, having no left, middle, and right child nodes
    if (currNode->left == nullptr && currNode->middle == nullptr && currNode->right == nullptr) {
        return true;
    }
    return false;
}

//Function that checks if a node has two children
bool Tree::hasTwoChildSibling(Node* siblingNode) const {
    int childCount = 0; //Counter for the number of children
    //Checks the left, middle, and right child nodes of the sibling node
    if (siblingNode->left != nullptr) {
        ++childCount;
    }
    if (siblingNode->middle != nullptr) {
        ++childCount;
    }
    if (siblingNode->right != nullptr) {
        ++childCount;
    }
    //Returns true if the sibling node has two children
    return childCount == 2;
}
