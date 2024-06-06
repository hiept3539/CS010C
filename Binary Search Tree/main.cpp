/* Hiep Tran - main.cpp - CS010C */

#include "BSTree.h"
#include <iostream>
#include <stdexcept>

using namespace std;

//Prints the tree in pre-order, in-order, and post-order
void printOrders(BSTree *tree) {
    cout << "Preorder = ";
    tree->preOrder( );
    cout << "Inorder = ";
    tree->inOrder( );
    cout << "Postorder = ";
    tree->postOrder( );
}

//Displays the menu
int menu() {
    int choice = 0;
    cout << endl << "Enter menu choice: ";
    cout << endl;
    cout 
        << "1. Insert" << endl
        << "2. Remove" << endl
        << "3. Print" << endl
        << "4. Search" << endl
        << "5. Smallest" << endl
        << "6. Largest" << endl
        << "7. Height" << endl
        << "8. Quit" << endl;
    cin >> choice;
    //Checks the state of cin before throwing error if needed
    if (cin.fail()) {
        throw runtime_error("Error: Invalid choice");
    }
    //Fix buffer just in case non-numeric choice entered
    cin.clear();
    cin.ignore(256, '\n');
    return choice;
}

int main() {
    BSTree tree;
    
    int choice = menu();

    string entry;

    //Loop until user chooses to quit
    while (choice != 8) {
        //Choice 1 to insert a node into the BST
        if (choice == 1) {
            cout << "Enter string to insert: ";
            //Check for invalid input
            if (!getline(cin, entry)) {
                throw runtime_error("Error: Invalid input");
            }
            cout << endl;
            //Insert the string into the BST
            tree.insert(entry);
        }
        else if (choice == 2) {
            //Choice 2 to remove a node from the BST
            cout << "Enter string to remove: ";
            if (!getline(cin, entry)) {
                throw runtime_error("Error: Invalid input");
            }
            cout << endl;
            //Remove the string from the BST
            tree.remove(entry);
        }
        else if (choice == 3) {
            //Choice 3 to print the tree in pre-order, in-order, and post-order
            printOrders(&tree);
        }
        else if (choice == 4) {
            //Choice 4 to search for a node in the BST
            cout << "Enter string to search for: ";
            if (!getline(cin, entry)) {
                throw runtime_error("Error: Invalid input");
            }
            cout << endl;
            //Search for the string in the BST
            if (tree.search(entry)) {
                cout << "Found" << endl;
            }
            else {
                cout << "Not Found" << endl;
            }
        }
        else if (choice == 5) {
            //Choice 5 to find the smallest node in the BST
            cout << "Smallest: " << tree.smallest() << endl;
        }
        else if (choice == 6) {
            //Choice 6 to find the largest node in the BST
            cout << "Largest: " << tree.largest() << endl;
        }
        else if (choice == 7) {
            //Choice 7 to find the height of a node in the BST
            cout << "Enter string: ";
            if (!getline(cin, entry)) {
                throw runtime_error("Error: Invalid input");
            }
            cout << endl;
            //Print the height of the node 
            cout << "Height of subtree rooted at " << entry << ": " << tree.height(entry) << endl;
        }
        else {
            cout << "Invalid choice" << endl;
        }
        choice = menu();
    }

    return 0;
}