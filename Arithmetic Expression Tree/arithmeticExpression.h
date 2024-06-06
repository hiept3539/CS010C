/* Hiep Tran - arithmeticExpression.h - CS010C */

#pragma once
#include <iostream>
#include <cstdlib>

using std::string;

struct TreeNode {
    char data;
    char key;
    TreeNode *left;
    TreeNode *right;
    //Constructor that sets the key to the parameter and left and right to nullptr
    TreeNode(char key) : key(key), left(nullptr), right(nullptr) {} 
};

class arithmeticExpression {
    public: 
        arithmeticExpression(const string&); //Default Constructor that sets the infixExpression to the parameter and root to nullptr
        ~arithmeticExpression(); //Destructor that deletes the tree
        arithmeticExpression(const arithmeticExpression&); //Copy Constructor that copies the infixExpression and root from the parameter
        arithmeticExpression &operator=(const arithmeticExpression&); //Assignment Operator for arithmeticExpression
        void buildTree(); //Builds the tree from the infixExpression
        void infix(); //Function that returns an integer according to the priority of the given operator
        void prefix(); //Function that outputs the prefix notation of the arithmetic expression tree by performing the preorder traversal of the tree
        void postfix(); //Function that outputs the postfix notation of the arithmetic expression tree by performing the postorder traversal of the tree
    private:
        string infixExpression;
        TreeNode* root;
    private:
        void deleteTree(TreeNode*); //Helper function that deletes the tree
        int priority(char); //Helper function that returns an integer according to the priority of the given operator
        string infix_to_postfix(); //Function that returns the postfix notation equivalent to the given infix expression
        void infix(TreeNode*); //Helper function for infix notation
        void prefix(TreeNode*); //Helper function for prefix notation
        void postfix(TreeNode*); //Helper function for postfix notation
};