/* Hiep Tran - WordEntry.cpp - CS010C */

#include "WordEntry.h"

//Default Constructor for WordEntry
WordEntry::WordEntry(const string &word, int score) {
    this->word = word;
    numAppearances = 1;
    totalScore = score;
}

//Function that adds a new appearance of the word with the given score
void WordEntry::addNewAppearance(int score) {
    totalScore += score; //Add the score to the total score
    ++numAppearances;
}

//Function that returns the word
const string & WordEntry::getWord() const {
    return word;
}

//Function that returns the average score of the word
double WordEntry::getAverage() const {
    return static_cast<double>(totalScore) / numAppearances;
}