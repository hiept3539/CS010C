/* Hiep Tran - Playlist.h - CS010C */

#pragma once

#include <iostream>
#include <string>
using namespace std;

class PlaylistNode { 
    public:
        //Default Constructor
        PlaylistNode();
        //Parameterzied Constructor
        PlaylistNode(const string, const string, const string, const int); //Used for adding a song
        PlaylistNode(const PlaylistNode*); //Used for Copy Constructor of Playlist Class
        //Public Member Functions
        void InsertAfter(PlaylistNode*); //Inserts a node after the current node
        void SetNext(PlaylistNode*); //Sets the next node
        const string& GetID() const; //Returns the unique ID of the song
        const string& GetSongName() const; //Returns the name of the song
        const string& GetArtistName() const; //Returns the name of the artist
        int GetSongLength() const; //Returns the length of the song
        PlaylistNode* GetNext() const; //Returns the next node 
        const void PrintPlaylistNode() const; //Prints the song's information

    private: 
        //Private Data Members
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
};

class Playlist {
    public:
        //Default Constructor
        Playlist();
        //Copy Constructor
        Playlist(const Playlist&);
        //Copy Assignment Operator
        Playlist& operator=(const Playlist&);
        //Destructor
        ~Playlist();
        //Public Member Function
        const void PrintMenu(const string&) const; //Prints the menu
        void addSong(const string&, const string&, const string&, int); //Adds a song to the playlist
        void removeSong(const string&); //Removes a song from the playlist
        void changePosition(int, int); //Changes the position of a song in the playlist
        const void specificArtist(const string&) const; //Prints all songs by a specific artist
        const void totalTime() const; //Prints the total time of the playlist
        const void outputFullPlaylist(const string&) const; //Prints the full playlist
    private:
        PlaylistNode* head;
        PlaylistNode* tail;
};
