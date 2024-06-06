/* Hiep Tran - main.cpp - CS010C */

#include <iostream>

#include "AVLTree.h"

using namespace std;

// Displays the menu
int menu() {
    int choice = 0;
    cout << endl << "Enter menu choice: ";
    cout << endl;
    cout 
        << "1. Insert" << endl
        << "2. Print" << endl
        << "3. Quit" << endl;
    cin >> choice;
    //Checks the state of cin before throwing error if needed
    if (cin.fail()) {
        throw runtime_error("Error: Invalid Input");
    }
    //Fix buffer just in case non-numeric choice entered
    cin.clear();
    cin.ignore(256, '\n');
    return choice;
}

int main( ) {
    AVLTree tree;

    int choice = menu();

    string entry;
    //Loop until user chooses to quit
    while (choice != 3) {
        //Insert a string into the tree
        if (choice == 1) {
            cout << "Enter string to insert: ";
            getline(cin, entry);
            //Checks the state of cin before throwing error if needed
            if (cin.fail()) {
                throw runtime_error("Error: Invalid Input");
            }
            cout << endl;
            tree.insert(entry);
        }
        //Print the balance factors of all nodes in the tree
        else if (choice == 2) {
            tree.printBalanceFactors();
            cout << endl;
        }
        //Display the menu again
        choice = menu();
    }
    return 0;
}