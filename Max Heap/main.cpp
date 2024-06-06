/* Hiep Tran - main.cpp - CS010C */

#include <iostream>
#include "Heap.h"

using namespace std;

//Function to display the menu
int menu() {
    int choice = 0;
    cout << endl << "Enter menu choice: ";
    cout << endl;
    cout 
        << "1. Enqueue" << endl
        << "2. Print" << endl
        << "3. Dequeue" << endl
        << "4. Quit" << endl;
    cin >> choice; //Get user input
    if (cin.fail()) { //Check if input is invalid before throwing error
        throw runtime_error("Error: Invalid Input)");
    }
    cin.clear(); //Clear buffer if input is in error state
    cin.ignore(256, '\n'); //Ignore newline character
    return choice;
}

int main() {
    Heap max_Heap;

    int choice = menu(); //Get user input for menu

    while (choice != 4) {
        if (choice == 1) {
            int priority, jobNumber, numPages;
            cout << "Enter print job to enqueue (priority, job Number, number of pages): ";
            cin >> priority >> jobNumber >> numPages;
            if (cin.fail()) { //Check if input is invalid before throwing error
                throw runtime_error("Error: Invalid Input)");
            }
            cout << endl;
            //Enqueue the print job by allocating a new PrintJob object
            max_Heap.enqueue(new PrintJob(priority, jobNumber, numPages));
        } 
        else if (choice == 2) { 
            max_Heap.print(); //Print the heap
        } 
        else if (choice == 3) {
            max_Heap.dequeue(); //Dequeue the highest priority print job
        }
        choice = menu(); //Get user input for menu
    }
    return 0;
}