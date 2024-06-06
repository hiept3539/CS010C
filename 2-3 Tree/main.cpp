/* Hiep Tran - main.cpp - CS010C */

#define A "Aliens"
#define B "Clerks"
#define C "Die Hard"
#define D "Enemy of the State"
#define E "Gladiator"
#define F "Happy Gilmore"
#define G "Kill Bill Volume 1"
#define H "Kill Bill Volume 2"
#define I "Matrix"
#define J "Meet the Parents"
#define K "Pirates of the Caribbean"
#define L "Silence of the Lambs"
#define M "Spaceballs"
#define N "Star Wars"
#define O "Terminator"
#define P "The Lord of the Rings"
#define Q "The Usual Suspects"
#define R "Top Gun"

#include "Tree.h"
#include <iostream>

using namespace std;

//Prints the preorder, inorder, and postorder of the tree
void printOrders(Tree* tree) {
    cout << "Preorder = ";
    tree->preOrder();
    cout << endl;
    cout << "Inorder = ";
    tree->inOrder();
    cout << endl;
    cout << "Postorder = ";
    tree->postOrder();
    cout << endl;
}

//Displays the menu and returns the user's choice
int menu() {
    int choice = 0;
    cout << endl << "Enter menu choice: ";
    cout << endl;
    cout 
        << "1. Insert" << endl
        << "2. Remove" << endl
        << "3. Print" << endl
        << "4. Search" << endl
        << "5. Quit" << endl;
    cin >> choice;
    //Check if the input is valid
    if (cin.fail()) {
        throw runtime_error("Error: Invalid Input");
    }
    cin.clear();
    cin.ignore(256, '\n');
    return choice;
}

int main() {
    Tree tree;

    int choice = menu();

    string entry;
    //Loop until the user chooses to quit
    while (choice != 5) {
        switch (choice) {
            case 1:
                cout << "Enter movie title to insert: ";
                getline(cin, entry);
                //Check if the input is valid before inserting
                if (cin.fail()) {
                    throw runtime_error("Error: Invalid Input");
                }
                cout << endl;
                //Insert the movie title
                tree.insert(entry);
                break;
            case 2:
                cout << "Enter movie title to remove: ";
                getline(cin, entry);
                //Check if the input is valid before removing
                if (cin.fail()) {
                    throw runtime_error("Error: Invalid Input");
                }
                cout << endl;
                //Remove the movie title
                tree.remove(entry);
                break;
            case 3:
                //Print the preorder, inorder, and postorder of the tree
                printOrders(&tree);
                break;
            case 4:
                cout << "Enter movie title to search for: ";
                getline(cin, entry);
                //Check if the input is valid before searching
                if (cin.fail()) {
                    throw runtime_error("Error: Invalid Input");
                }
                cout << endl;
                //Search for the movie title
                if (tree.search(entry) != nullptr) {
                    cout << "Found" << endl;
                } 
                else {
                    cout << "Not Found" << endl;
                }
                break;
            default:
                //Display an error message if the user's choice is invalid
                cout << "Invalid choice" << endl;
        }
        //Display the menu again
        choice = menu();
    }
}
