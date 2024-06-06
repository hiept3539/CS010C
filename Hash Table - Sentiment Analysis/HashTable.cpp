/* Hiep Tran - HashTable.cpp - CS010C */

#include "HashTable.h"
#include "WordEntry.h"

//Default Constructor
HashTable::HashTable(int s) {
    size = s; //Size of the hash table
    hashTable = new list<WordEntry>[size]; //Allocates new memory for the hash table
}

//Destructor
HashTable::~HashTable() {
    delete[] hashTable; //Deallocates memory for the hash table
}

//Copy Constructor
HashTable::HashTable(const HashTable &copyHash) {
    size = copyHash.size; //Copy the size of the hash table
    hashTable = new list<WordEntry>[size];
    //Iteratesthrough the hash table and copies the WordEntry objects
    for (int i = 0; i < size; ++i) {
        hashTable[i] = copyHash.hashTable[i];
    }
}

//Assignment Operator
HashTable &HashTable::operator=(const HashTable &copyHash) {
    if (this != &copyHash) { //Checks for self-assignment
        delete[] hashTable; //Deallocates memory for the hash table
        size = copyHash.size;
        hashTable = new list<WordEntry>[size];
        //Iterates through the hash table and copies the WordEntry objects
        for (int i = 0; i < size; ++i) {
            hashTable[i] = copyHash.hashTable[i];
        }
    }
    return *this;
}

//Function that computes the hash value of the word
int HashTable::computeHash(const string &word) const {
    int hash = 0;
    int prime = 31; //Prime number used for hashing
    //Iterates through the word and computes the hash value
    for (long unsigned int i = 0;i < word.length(); ++i) {
        hash = (prime * hash + word[i]) % size; //Simple hashing algorithm
    }
    return hash;
}

//Function that adds a new word to the hash table
void HashTable::put(const string &word, int score) {
    int hashValue = computeHash(word); //Calls the computeHash function to get the hash value
    if (contains(word)) { //Checks if the word is already in the hash table
        //Iterates through the hash table and adds a new appearance of the word
        for (list<WordEntry>::iterator it = hashTable[hashValue].begin(); it != hashTable[hashValue].end(); ++it) {
            if (it->getWord() == word) {
                //Calls the addNewAppearance function from the WordEntry class
                it->addNewAppearance(score);
                return;
            }
        }
    }
    //Creates a new WordEntry object and adds it to the hash table
    WordEntry newEntry(word, score);
    hashTable[hashValue].push_back(newEntry);
}

//Function that returns the average score of the word
double HashTable::getAverage(const string &word) const {
    int index = computeHash(word); //Calls the computeHash function to get the hash value
    if (contains(word)) { //Checks if the word is in the hash table
        //Iterates through the hash table and returns the average score of the word
        for (list<WordEntry>::const_iterator it = hashTable[index].begin(); it != hashTable[index].end(); ++it) {
            if (it->getWord() == word) { 
                //Calls the getAverage function from the WordEntry class
                return it->getAverage();
            }
        }
    }
    return 2.0; //Returns 2.0 if the word is not in the hash table
}

//Function that checks if the word is in the hash table
bool HashTable::contains(const string &word) const {
    int index = computeHash(word); //Calls the computeHash function to get the hash value
    //Iterates through the hash table and checks if the word is in the hash table
    for (list<WordEntry>::const_iterator it = hashTable[index].begin(); it != hashTable[index].end(); ++it) {
        if (it->getWord() == word) {
            return true;
        }
    }
    return false;
}