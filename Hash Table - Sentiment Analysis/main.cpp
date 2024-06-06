/* Hiep Tran - main.cpp - CS010C */

#include "HashTable.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    //Declare a few needed variables for inputing the data
    string line;
    int score;
    string message = " ";

    //Open the input file
    ifstream myfile("movieReviews.txt");
    if (myfile.fail()) { //Check if the state of the stream is good
        cout << "could not open file" << endl;
        exit(1);
    }

    //Create Hash Table
    HashTable table(20071);

	//Read the data from the file
    while (true) {
        myfile >> score; //Get score
        myfile.get(); //Get blank space
        getline(myfile, line);
        if (!myfile) { 
            if (myfile.eof()) break; // Doesn't return true unless we tried input
            throw runtime_error("Error: Input Failed");
        }
        int len = line.size(); //Get the size of the line
        while(len > 0) { //Identify all individual strings
            string sub;
            len = line.find(" ");
            if (len > 0) {
				//Get the substring from the line 
                sub = line.substr(0, len);
                line = line.substr(len + 1, line.size());
            }
            else {
                sub = line.substr(0, line.size() - 1);
            }
            table.put(sub, score); //Insert the string with the score
        }
    }

    //Prompt user for a new movie review after data is entered in hash function
	while(message.length() > 0) {
	    cout << "Enter a Review -- Press return to exit: " << endl;
	    getline(cin, message);
		if (cin.fail()) { //Check if the input is successful before continuing
			throw runtime_error("Error: Input Failed");
		}
	    //Used for calculating the average
	    double sum = 0;
	    int count = 0;
	    
	    double sentiment = 0.0;
	    
	    size_t len = message.size();
	    //Get each individual word from the input
	    while(len != string::npos) {
	        string sub;
	        len = message.find(" ");
	        if (len != string::npos) {
				//Get the substring from the message
	            sub = message.substr(0, len);
	            message = message.substr(len + 1, message.size());
	        }
	        else {
	            sub = message;
	        }
	        //Calculate the score of each word
	        sum += table.getAverage(sub);
	        ++count;
	    }
		//Check if the message has any words
	    if (message.size() > 0) {
	    	sentiment = sum / count;
	        cout << "The review has an average value of " << sentiment << endl;
	        if (sentiment >= 3.0) { //Check if the sentiment is positive
	        	cout << "Positive Sentiment" << endl;
	        }
	        else if (sentiment >= 2.0) { //Check if the sentiment is somewhat positive
	        	cout << "Somewhat Positive Sentiment" << endl;
	        }
	        else if (sentiment >= 1.0) { //Check if the sentiment is somewhat negative
	        	cout << "Somewhat Negative Sentiment" << endl;
	        }
	        else { //Check if the sentiment is negative
	        	cout << "Negative Sentiment" << endl;
	        }
	        cout << endl;
	    }
	}
}