/* Hiep Tran - Playlist.cpp - CS010C */

#include "Playlist.h"

//Default Constructor that sets the data members to "none" and 0
PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}

//Constructor that takes in parameters that will be set to the values of the node
PlaylistNode::PlaylistNode(const string uniqueID, const string songName, const string artistName, const int songLength) {
    this->uniqueID = uniqueID;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songLength;
    this->nextNodePtr = nullptr;
}

//Constructor that copies from a passed in node
PlaylistNode::PlaylistNode(const PlaylistNode* newNode) {
    uniqueID = newNode->GetID();
    songName = newNode->GetSongName();
    artistName = newNode->GetArtistName();
    songLength = newNode->GetSongLength();
    nextNodePtr = nullptr;
} 

//Inserts a node after the current node
void PlaylistNode::InsertAfter(PlaylistNode* currNode) {
    //Set passed in node's next to object's next
    //Set object's next to the passed in node
    currNode->SetNext(this->nextNodePtr);
    this->SetNext(currNode);
}

//Sets the next node in the list
void PlaylistNode::SetNext(PlaylistNode* nextNode) {
    nextNodePtr = nextNode; //Sets the data member to the passed in node
}

//Returns the uniqueID of the node
const string& PlaylistNode::GetID() const {
    return uniqueID; 
}

//Returns the songName of the node
const string& PlaylistNode::GetSongName() const {
    return songName;
}

//Returns the artistName of the node
const string& PlaylistNode::GetArtistName() const {
    return artistName;
}

//Returns the songLength of the node
int PlaylistNode::GetSongLength() const {
    return songLength;
}

//Returns the next node in the list
PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr;
}

//Prints the description of the node
const void PlaylistNode::PrintPlaylistNode() const {
    cout << "Unique ID: " << this->uniqueID << endl;
    cout << "Song Name: " << this->songName << endl;
    cout << "Artist Name: " << this->artistName << endl;
    cout << "Song Length (in seconds): " << this->songLength << endl;
}

//Default Constructor that sets the head and tail to nullptr
Playlist::Playlist() {
    head = nullptr;
    tail = nullptr;
}

//Copy Constructor that copies the nodes from the copyList to the current list
Playlist::Playlist(const Playlist& copyList) {
    head = nullptr;
    tail = nullptr;
    PlaylistNode* newNode = copyList.head;
    //Copy Constructor that iterates through a playlist and adds each node
    while (newNode) {
        //Creates a newNode based on the copyList Head
        PlaylistNode* copyNode = new PlaylistNode(newNode);
        if (head == nullptr) {
            head = copyNode;
        }
        else {
            tail->SetNext(copyNode);
        }
        tail = copyNode;
        newNode = newNode->GetNext();
    }
}

//Copy Assignment Operator that copies the nodes from the copyList to the current list
Playlist& Playlist::operator=(const Playlist& copyList) {
    //Don't self-assign and deletes each node in the list
    if (this != &copyList) {
        while (head != nullptr) {
            PlaylistNode* nextNode = head->GetNext();
            delete head;
            head = nextNode;
        }
        //Avoids Dangling Pointer after deleting each Head
        head = nullptr;
        tail = nullptr;
        PlaylistNode* copyNode = copyList.head;
        //Copies each node from the copyList and adds it 
        while (copyNode) {
            PlaylistNode* newNode = new PlaylistNode(copyNode);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->SetNext(newNode);
                tail = newNode;
            }
            copyNode = copyNode->GetNext();
        }
    }
    return *this;
}

Playlist::~Playlist() {
    //Deletes each node from the playlist by iteratation
    PlaylistNode* nextNode = head->GetNext();
    while (nextNode) {
        delete head;
        head = nextNode;
        nextNode = nextNode->GetNext();
    }
    delete head;
    head = nullptr;
    tail = nullptr;

}

//Prints the Given Menu Automatically (Constant O(1))
const void Playlist::PrintMenu(const string& playlistTitle) const {
    cout << playlistTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit\n" << endl;
    cout << "Choose an option:" << endl;
}

//Adds a song to the playlist (Constant O(1))
void Playlist::addSong(const string& uniqueID, const string& songName, const string& artistName, int songLength) {
    //Creates a new PlaylistNode that is added to the list 
    PlaylistNode* currNode = new PlaylistNode(uniqueID, songName, artistName, songLength);
    //Checks if list is empty before changing Head & Tail
    if (head == nullptr) {
        head = currNode;
        tail = currNode;
    }
    else {
        //Adds the new node after the tail
        tail->SetNext(currNode);
        tail = currNode;
    }
}

//Removes a song from the playlist (Best Case: O(1) - Worst Case O(n))
void Playlist::removeSong(const string& uniqueID) {
    //Checks if there's anything in the playlist 
    if (head == nullptr) {
        cout << "REMOVE SONG" << endl;
        cout << "Playlist is empty, nothing to remove." << endl;
        return;
    }

    PlaylistNode* tempNode = head;
    if (head->GetID() == uniqueID) {
        //Checks if there's only one node in the list
        if (head == tail)  {
            cout << "\"" << (head)->GetSongName() << "\"" << " removed.\n"; 
            cout << endl;
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            //Removes the Head in a list with more than one node
            tempNode = head;
            head = head->GetNext();
            cout << "\"" << tempNode->GetSongName() << "\"" << " removed.\n"; 
            cout << endl;
            delete tempNode;
        }
    }
    else {
        //Iterates through the list and checks for same ID 
        tempNode = head;
        while (tempNode->GetNext() != nullptr) {
            if ((tempNode->GetNext()->GetID()) == uniqueID) {
                PlaylistNode* removeNode = tempNode->GetNext();
                //Sets tempNode to the next-next node and deletes the node in the middle
                tempNode->SetNext((tempNode->GetNext()->GetNext()));
                cout << "\"" << removeNode->GetSongName() << "\"" << " removed.\n"; 
                cout << endl;
                delete removeNode;
                //Sets the tempNode to Tail if the node removed is the last
                if (tempNode->GetNext() == nullptr) {
                    tail = tempNode;
                }
                //Return to avoid checking the rest of the list after deletion
                return; 
            }
            tempNode = tempNode->GetNext();
        }
    }
    cout << "Song ID not found in playlist" << endl;
}

//Changes the position of a song in the playlist (Best Case: O(1) - Worst Case O(n))
void Playlist::changePosition(int currPosition, int newPosition) {
    //Checks if there's anything in the playlist 
    if (head == nullptr) {
        cout << "Playlist is empty, nothing to change." << endl;
        return;
    }   

    //Used to check if the Position Chosen is Out of Range & Changes it
    PlaylistNode* countNodes = head;
    int nodeCnt = 0;
    while (countNodes) { //Counts the amount of nodes in the list
        ++nodeCnt;
        countNodes = countNodes->GetNext();
    }

    //Checks if the current position is out of range
    while (currPosition > nodeCnt || currPosition < 1) {
        cout << "Current Position doesn't exist. Enter another position." << endl;
        cin >> currPosition;
    }

    //Changes the newPosition to the Head if less than 1
    if (newPosition < 1) { 
        newPosition = 1;
    }
    //Changes the newPosition to the Tail if greater than the # of nodes 
    else if (newPosition > nodeCnt) { 
        newPosition = nodeCnt;
    }

    //Declare new playlistNodes to keep track of the position of the nodes
    PlaylistNode* tempNode = head;
    PlaylistNode* prevNode = nullptr;
    PlaylistNode* changeNode = nullptr;
    int songLoc = 1;

    // Iterates through the nodes to find the correct node to move
    while (tempNode != nullptr && songLoc != currPosition) {
        prevNode = tempNode;
        tempNode = tempNode->GetNext();
        ++songLoc;
    }
    changeNode = tempNode; //Sets the nde to move as changeNode

    //If the node to move is at the Head
    if (changeNode == head) {
        head = head->GetNext(); //Moves the up list 
    } 
    else {
        prevNode->SetNext(changeNode->GetNext()); //Skips changeNode 
    }

    //If the node to move is at the Tail
    if (changeNode == tail) {
        tail = prevNode; //Set prevNode to tail
    }

    //Resets the nodes to find newPosition instead of which node to move
    tempNode = head; //tempNode keeps track of the newPosition when found
    prevNode = nullptr;
    songLoc = 1;

    //Iterates through until the newPosition is found
    while (tempNode != nullptr && songLoc != newPosition) {
        prevNode = tempNode;
        tempNode = tempNode->GetNext();
        ++songLoc;
    }

    //If the newPosition of the node is at the Head
    if (prevNode == nullptr) {
        changeNode->SetNext(head);
        head = changeNode;
    } 
    else {
        prevNode->SetNext(changeNode);
        changeNode->SetNext(tempNode);
    }

    // If the newPosition of the node is at the Tail
    if (changeNode->GetNext() == nullptr) {
        tail = changeNode;
    }

    cout << "\"" << changeNode->GetSongName() << "\" moved to position " << newPosition << endl << endl;
}

//Outputs the songs by a specific artist (Best Case O(1) - Worst Case O(n))
const void Playlist::specificArtist(const string& artistName) const {
    //Checks if there's anything in the playlist 
    if (head == nullptr) {
        cout << "Playlist is empty" << endl;
        return;
    }
    PlaylistNode* tempNode = head;
    int songCnt = 1;
    //Outputs each description of the correct node with the same artistName
    while (tempNode) {
        if (tempNode->GetArtistName() == artistName) {
            cout << songCnt << '.' << endl;
            tempNode->PrintPlaylistNode();
            cout << endl;
        }
        tempNode = tempNode->GetNext();
        ++songCnt;
    }
}

//Outputs the total time of the playlist (Best Case O(1) - Worst Case O(n))
const void Playlist::totalTime() const {
    //Checks if there's anything in the playlist 
    if (head == nullptr) {
        cout << "Playlist is empty" << endl;
        cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
        cout << "Total time: 0 seconds\n";
        cout << endl;
        return;
    }
    PlaylistNode* tempNode = head;
    int totalTime = 0;
    //Adds up the time of each node's songLength
    while (tempNode) {
        totalTime += tempNode->GetSongLength();
        tempNode = tempNode->GetNext();
    }
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
    cout << "Total time: " << totalTime << " seconds\n";
    cout << endl;
}

//Outputs the full playlist (Best Case O(1) - Worst Case O(n))
const void Playlist::outputFullPlaylist(const string& playlistTitle) const {
    //Checks if there's anything in the playlist
    cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl; 
    if (head == nullptr) {
        cout << "Playlist is empty\n";
        cout << endl;
    }
    else {
        //Iterates through the playlist while outputting each description
        int songCnt = 1;
        PlaylistNode* tempNode = head;
        while (tempNode) { //Outputs each node's description
            cout << songCnt << '.' << endl;
            tempNode->PrintPlaylistNode();
            cout << endl;
            tempNode = tempNode->GetNext();
            ++songCnt;
        }
    }
}