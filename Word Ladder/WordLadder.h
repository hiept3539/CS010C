/* Hiep Tran - WordLadder.h - CS010C */

#pragma once
#include <list>
#include <string>
#include <stack>
#include <fstream>

using std::list;
using std::string;
using std::ofstream;
using std::stack;

class WordLadder {
    public:
        //Constructor that extracts words from a file
        WordLadder(const string& fileName); 
        //Creates the ladder from the starting word to the ending word to an ostream
        void outputLadder(const string &start, const string& end, const string &outputFile);
    private:
        //List of words created by the constructor
        list<string> dict;
        //Helper function to the outputLadder function
        bool oneLetterOff(const string& start, const string& end);
        //Helper function to display ladder at a current time
        void displayCurrentLadder(stack<string>& currStack, ofstream& outFS);
};
