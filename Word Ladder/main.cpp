/* Hiep Tran - main.cpp - CS010C */

#include "WordLadder.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::runtime_error;

int main() {
    string dictFile, wordBegin, wordEnd, outFile;
    cout << "Enter the name of the Dictionary File: ";
    cin >> dictFile;
    if (cin.fail()) { //Checks the input operation success of cin
        throw runtime_error("Error: Input Failure");
    }
    cout << endl;
    cout << "Enter the name of the Output File: ";
    cin >> outFile;
    if (cin.fail()) { //Checks the input operation success of cin
        throw runtime_error("Error: Input Failure");
    }
    cout << endl;
    cout << "Enter the First Word: "; 
    cin >> wordBegin;
    if (cin.fail()) { //Checks the input operation success of cin
        throw runtime_error("Error: Input Failure");
    }
    cout << endl;

    //Executes if the size of the starting word is not 5
    while (wordBegin.size() != 5) {
        cout << "Word must have exactly 5 characters." << endl;
        cout << "Please RE-ENTER the First Word: ";
        if (!(cin >> wordBegin)) { //Checks the input operation success of cin
            throw runtime_error("Error: Could not read 5 character First Word");
        }
        cout << endl;
    }
    
    cout << "Enter the Last Word: ";
    if (!(cin >> wordEnd)) { //Checks the input operation success of cin
        throw runtime_error("Error: Could not read 5 character Last Word");
    }
    cout << endl;
    //Executes if the size of the ending word is not 5
    while (wordEnd.size() != 5) {
        cout << "Word must have exactly 5 characters." << endl;
        cout << "Please RE-ENTER the Last Word: ";
        if (!(cin >> wordEnd)) { //Checks the input operation success of cin
            throw runtime_error("Error: Could not read 5 character First Word");
        }
        cout << endl;
    }

    //Creates a new ladder with the given dictionary and start/end words
    WordLadder w1(dictFile);
    w1.outputLadder(wordBegin, wordEnd, outFile);
    return 0;
}