/* Hiep Tran - WordEntry.h - CS010C */

#pragma once
#include <string>
#include <vector>
#include <iostream>

using std::string;

//WordEntry class that stores a word and its score
class WordEntry {
    public:
        WordEntry(const string &word, int score); //Default Constructor
        void addNewAppearance(int score); //Add a new appearance of the word with the given score
        const string & getWord() const; //Return the word
        double getAverage() const; //Return the average score of the word
    private:
        string word; //String to store the word
        int numAppearances; //Integer to store the number of appearances of the word
        int totalScore; //Integer to store the total score of the word
};