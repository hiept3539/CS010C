/* Hiep Tran - WordLadder.cpp - CS010C */

#include "WordLadder.h" 
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//Function that reads each word into the stream from a file
WordLadder::WordLadder(const string& fileName) { //O(n) Runtime Complexity
    //Check if file is opened successfully and throws error if not
    ifstream inFS(fileName);
    if (inFS.fail()) { //Checks input operation of the ifstream opening the file
        throw runtime_error("Error: Input File not opened properly");
        return;
    }
    string dictWord;
    while (inFS >> dictWord) { //Checks input operation of extracting a string from the file
        if (dictWord.size() != 5) {
            throw runtime_error("Error: Word is not 5 characters");
            return;
        }
        dict.push_back(dictWord); //Adds the valid word to the dictionary
    }
    inFS.close(); 
}

//Function that finds and outputs the shortest ladder of words onto a file
void WordLadder::outputLadder(const string& start, const string& end, const string& outputFile) { //O(n^2) Runtime Complexity
    //Checks to see if the given start and end words are present in the dictionary
    if (std::find(dict.begin(), dict.end(), start) == dict.end() || std::find(dict.begin(), dict.end(), end) == dict.end()) {
        throw runtime_error("Error: Start or End word not found");
    }

    //Creates an output file to store the ladder of words
    ofstream outFS(outputFile);
    if (outFS.fail()) { //Checks the input operator of the ofstream opening the file;
        throw runtime_error("Error: Output File not opened properly");
        return;
    }

    //Special case where the start & end word are the same, so only one word is inserted
    if (start == end) {
        outFS << start << endl;
        return;
    }

    //Creates a new stack of strings and adds the start word to the stack
    stack<string> stackBegin; 
    stackBegin.push(start);
    //Creates a new queue for the stack of strings and adds stackBegin to the queue
    queue<stack<string>> queueStack;
    queueStack.push(stackBegin);

    //Checks if the queue isn't empty before executing 
    while (!queueStack.empty()) {
        stack<string> currStack = queueStack.front(); //Stack that has the same elements as the first stack in the queue
        string topWord = queueStack.front().top(); //Gets the top element of the first stack in the queue

        //Loops from the beginning to the end of dictionary, each being an iterator pointing to a position
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            if (topWord != *it) { 
                //Uses a helper function to determine the difference of elements
                if (oneLetterOff(currStack.top(), *it)) {
                    stack<string> newStack = queueStack.front(); //Creates a copy of the first stack in the queue
                    newStack.push(*it); 
                    //Condition to output the ladder if current word is the end word
                    if (*it == end) {
                        displayCurrentLadder(newStack, outFS); //Helper function to display the ladder 
                    }
                    else {
                        //Adds the newStack to the queue before deleting the word from the dictionary
                        queueStack.push(newStack);
                        it = dict.erase(it);
                        //--it; //Decrements the iterator as the last element was removed
                    }
                }
            }
        }
        //Removes the first stack of the queue
        queueStack.pop();
    }
    //Condition if the queue is empty and no word ladder was found
    if (queueStack.empty()) {
        outFS << "No Word Ladder Found." << endl;
        outFS.close();
    }
}

//Helper Function that checks if there's only one letter difference between two words
bool WordLadder::oneLetterOff(const string& dictWord1, const string& dictWord2) { //O(n) Runtime Complexity
    int wordOff = 0;
    //Loop that iterates the size of the given word and compares each index element
    for (long unsigned int i = 0; i < dictWord1.size(); ++i) {
        if (dictWord1[i] != dictWord2[i]) {
            ++wordOff;
        }
    }
    //Returns either true or false if only one difference is found
    return wordOff == 1;
}

//Helper Function that outputs the ladder if the iterated word is the end word
void WordLadder::displayCurrentLadder(stack<string>& currStack, ofstream& outFS) { //O(n) Runtime Complexity
    stack<string> reverseStack;
    //Checks to see if the stack is empty before executing
    while(!currStack.empty()) {
        reverseStack.push(currStack.top()); //Adds the top value of the stack to the reverseStack which flips the order
        currStack.pop(); //Deletes the top value so the new top value is the next element
    }
    //Outputs to the stream the new reverseStack
    while (!reverseStack.empty()) {
        outFS << reverseStack.top() << " " << endl;
        reverseStack.pop(); 
    }
    outFS << endl;
    outFS.close();
    return;
}