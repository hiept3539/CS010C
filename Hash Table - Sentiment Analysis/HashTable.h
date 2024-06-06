/* Hiep Tran - HashTable.h - CS010C */

#pragma once
#include "WordEntry.h"
#include <string>
#include <list>
#include <iostream>


using std::string;
using std::list;

//HashTable class that stores a list of WordEntry objects
class HashTable {   
    public:
        HashTable(int size); //Default Constructor
        ~HashTable(); //Destructor
        HashTable(const HashTable& copyHash); //Copy Constructor
        HashTable& operator=(const HashTable& copyHash); //Assignment Operator
        bool contains(const string& word) const; //Check if the word is in the hash table
        double getAverage(const string& word) const; //Return the average score of the word
        void put(const string& word, int score); //Add a new word to the hash table
    private:
        list<WordEntry> *hashTable; //List of WordEntry objects
        int size; //Size of the hash table
    private:
        int computeHash(const string& word) const; //Compute the hash value of the word
};
