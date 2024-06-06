/* Hiep Tran - arithmeticExpression.cpp - CS010C */

#include "arithmeticExpression.h"
#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

//Default Constructor that sets the infixExpression to the parameter and root to nullptr
arithmeticExpression::arithmeticExpression(const string& expression) : infixExpression(expression), root(nullptr) {}

//Destructor that deletes the tree
arithmeticExpression::~arithmeticExpression() {
    deleteTree(root); //Calls the helper function to delete the tree
}

//Helper function that deletes the tree
void arithmeticExpression::deleteTree(TreeNode* root) {
    if (root != nullptr) { //Checks if the root is not nullptr before recursively deleting the tree
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = nullptr;
    }
}

//Copy Constructor that copies the infixExpression and root from the parameter
arithmeticExpression::arithmeticExpression(const arithmeticExpression& rhs) {
    this->infixExpression = rhs.infixExpression;
    this->root = rhs.root;
}

//Assignment Operator for arithmeticExpression
arithmeticExpression& arithmeticExpression::operator=(const arithmeticExpression& rhs) {
    if (this != &rhs) { //Checks for self-assignment before copying
        this->infixExpression = rhs.infixExpression;
        this->root = rhs.root;
    }
    return *this; 
}

void arithmeticExpression::buildTree() {
    string postfixExpression = infix_to_postfix();
    stack<TreeNode*> expressionStack;

    for (unsigned i = 0; i < postfixExpression.size(); ++i) {
        if (priority(postfixExpression.at(i)) > 0) { //If the character is an operator
            TreeNode *operatorNode = new TreeNode(postfixExpression.at(i)); //Creates a new node with the operator
            operatorNode->right = expressionStack.top(); //Sets the right child to the top of the stack
            expressionStack.pop(); //Pops the top of the stack
            operatorNode->left = expressionStack.top(); //Sets the left child to the new top of the stack
            expressionStack.pop(); //Pops the top of the stack
            expressionStack.push(operatorNode); //Pushes the new node back to the stack
        }
        else { //If the character is an operand or space
            TreeNode *operandNode = new TreeNode(postfixExpression.at(i)); //Creates a new node with the operand
            expressionStack.push(operandNode); //Pushes the new node to the stack
        }
    }
    root = expressionStack.top(); //Sets the root to the top of the stack
}

//Infix function that calls the recursive infix function
void arithmeticExpression::infix() {
    infix(root);
}

//Recursive infix helper function that outputs the infix notation of the arithmetic expression tree
void arithmeticExpression::infix(TreeNode* currNode) {
    if (currNode == nullptr) { //Base case to return if the current node is nullptr
        return;
    }
    //Checks if the current node has children before adding parentheses
    if (currNode->left != nullptr || currNode->right != nullptr) {
        cout << "(";
    }
    //Recursively calls the left child, outputs the key, and then recursively calls the right child
    infix(currNode->left);
    cout << currNode->key;
    infix(currNode->right);
    //Checks if the current node has children before adding parentheses
    if (currNode->left != nullptr || currNode->right != nullptr) {
        cout << ")";
    }
}

//Prefix function that calls the recursive prefix function
void arithmeticExpression::prefix() {
    prefix(root);
}

//Recursive prefix helper function that outputs the prefix notation of the arithmetic expression tree
void arithmeticExpression::prefix(TreeNode* currNode) {
    if (currNode == nullptr) { //Base case to return if the current node is nullptr
        return;
    }
    //Outputs the key, then recursively calls the left child and right child
    cout << currNode->key;
    prefix(currNode->left);
    prefix(currNode->right);
}

//Postfix function that calls the recursive postfix function
void arithmeticExpression::postfix() {
    postfix(root);
}

//Recursive postfix helper function that outputs the postfix notation of the arithmetic expression tree
void arithmeticExpression::postfix(TreeNode* currNode) {
    if (currNode == nullptr) { //Base case to return if the current node is nullptr
        return;
    }
    //Recursively calls the left child, right child, and then outputs the key
    postfix(currNode->left);
    postfix(currNode->right);
    cout << currNode->key;
}

//Helper function that returns an integer according to the priority of the given operator
int arithmeticExpression::priority(char operation) {
    int priority = 0;
    //Sets the priority based on the operator
    if (operation == '(') {
        priority = 3;
    } else if (operation == '*' || operation == '/') {
        priority = 2;
    } else if (operation == '+' || operation == '-') {
        priority = 1;
    }
    return priority;
}

//Helper function that returns the postfix notation equivalent to the given infix expression
string arithmeticExpression::infix_to_postfix() {
    stack<char> charStack;
    ostringstream oss;
    char operation;
    //Iterates through the infix expression
    for (unsigned i = 0; i < infixExpression.size(); ++i) {
        operation = infixExpression.at(i); 
        if (operation == ' ') { 
            continue; //Skips the space
        }
        //Checks if the character is an operator
        if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '(' || operation == ')') {
            //Checks if the character is an opening parenthesis
            if (operation == '(') {
                charStack.push(operation);
            } 
            //Checks if the character is a closing parenthesis
            else if (operation == ')') {
                //Pops the operators from the stack until the opening parenthesis
                while (charStack.top() != '(') {
                    oss << charStack.top();
                    charStack.pop();
                }
                charStack.pop();
            } 
            //Checks if the character is an operator
            else {
                //Pops the operators with higher or equal priority from the stack
                while (!charStack.empty() && priority(operation) <= priority(charStack.top())) {
                    if (charStack.top() == '(') {
                        break;
                    }
                    oss << charStack.top();
                    charStack.pop();
                }
                charStack.push(operation);
            }
        } 
        else {
            oss << operation;
        }
    }
    //Pops the remaining operators from the stack
    while (!charStack.empty()) {
        oss << charStack.top();
        charStack.pop();
    }
    return oss.str();
}