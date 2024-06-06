/* Hiep Tran - main.cpp - CS010C */

#include <iostream>
#include "Playlist.h"
using namespace std;

int main() {
    string playlistTitle;
    Playlist newPlaylist;
    
    string uniqueID;
    string songName;
    string artistName;
    int songLength;   
    
    cout << "Enter playlist's title:" << endl;
    getline(cin, playlistTitle);
    cout << endl;
    
    newPlaylist.PrintMenu(playlistTitle);

    //Checks if the Option is Valid
    char option;
    do {
        cin >> option;
        option = tolower(option);
        //Uses the appropriate function for the option inputted
        switch (option) {
        
        case 'a': 
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin.ignore(); //Used to ignore the newline of the previous line'ss buffer to avoid reading the newline
            getline(cin, uniqueID);
            //The following if statements check if the input is not blank
            if (uniqueID.empty()) { 
                throw runtime_error("Error: uniqueID is empty");
            }
            cout << "Enter song's name:" << endl;
            getline(cin, songName);
            if (songName.empty()) {
                throw runtime_error("Error: songName is empty");
            }
            cout << "Enter artist's name:" << endl;
            getline(cin, artistName);
            if (artistName.empty()) { 
                throw runtime_error("Error: artistName is empty");
            }
            cout << "Enter song's length (in seconds):" << endl;
            cin >> songLength;
            cout << endl;
            if (cin.fail()) { //Checks the last integer input and prompts to re-enter if invalid
                throw runtime_error("Error: songLength is not in integer form");
            } 
            newPlaylist.addSong(uniqueID, songName, artistName, songLength);
            break;
        
        case 'd':
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin.ignore();
            getline(cin, uniqueID);
            newPlaylist.removeSong(uniqueID);
            break;
        
        case 'c':
            int currPosition, newPosition;
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            
            cin >> currPosition;
            if (cin.fail()) { //Checks the last integer input and prompts to re-enter if invalid
                throw runtime_error("Error: currPosition is not in integer form");
            } 

            cout << "Enter new position for song:" << endl;
            cin >> newPosition;
            if (cin.fail()) { //Checks the last integer input and prompts to re-enter if invalid
                throw runtime_error("Error: newPosition is not in integer form");
            } 
            
            newPlaylist.changePosition(currPosition, newPosition);
            break;
        
        case 's':
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:\n";
            cout << endl;
            cin.ignore();
            getline(cin, artistName);
            newPlaylist.specificArtist(artistName);
            break;
        
        case 't':
            newPlaylist.totalTime();
            break;
        
        case 'o':
            newPlaylist.outputFullPlaylist(playlistTitle);
            break;
        
        case 'q':
            break;
        
        //Repeats the option until a correct one is chosen
        default:
            cout << "Invalid Option - Enter Again\n";
            cout << endl;
            break;
        }
        newPlaylist.PrintMenu(playlistTitle);
    } while (option != 'q');
    
    return 0;
}