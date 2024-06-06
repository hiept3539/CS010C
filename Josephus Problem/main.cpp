/* Hiep Tran - main.cpp - CS010C */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Node struct that contains the payload and the next node
struct Node {
    string payload;
    Node* next;
};

//Function that creates a new node with the given payload
Node* newNode(const string& payload) {
    Node* insertNode = new Node();
    //Sets value of curr payload to the parameter payload
    insertNode->payload = payload; 
    insertNode->next = nullptr;
    return insertNode;
}

//Function to add in the n amount of names with nodes to the list
Node* loadGame(int n, const vector<string>& names) {
    Node* head = nullptr;
    Node* tail = nullptr;
    string name;
    //Iterates all the names in the list and adds the nodes
    for (int i = 0; i < n; ++i) {
        name = names.at(i);
	    //Special edge case when the list is initially empty
        if (head == nullptr) {
            //Sets the first node to be both head and prev (Circular)
            head = newNode(name);
            tail = head;
        } 
        else { 
            //Sets the currPrev's next to be the newNode and the prev to be the newNode
            tail->next = newNode(name);
            tail = tail->next;
        }
    }
    //Makes the linked list circular by connecting the lastNode to the head
    if (tail != nullptr) {
        tail->next = head;
    }
    return head;
}

//Function that prints out all the nodes in the circular list
void print(const Node* start) {
    const Node* curr = start;
    //Avoids dereferencing a nullptr & checks if list isn't empty before executing
    while (curr != nullptr) {
        cout << curr->payload << endl;
        curr = curr->next;
        if (curr == start) {
        break; //Exits circular list
        }
    }
}

//Josephus with circular list, k = num skips
Node* runGame(Node* start, int k) {
    Node* curr = start;
    Node* prev = curr;
    //Iterates until there's only one person left
    while (curr->next != nullptr && curr->next != curr) { 
        //Skips over k amount before deleting
        for (int i = 0; i < k; ++i) { 
          prev = curr;
          curr = curr->next;
        }
        //Deletes the currNode and updates to it's nextNode
        prev->next = curr->next;
        delete curr;
        curr = prev->next;
    }
    return curr;
}

// Driver program to test above functions 
int main() {
    int n = 1, k = 1; // n = # of names; k = # of skips (minus 1)
    string name;
    vector<string> names;

    //Get inputs and checks if the input are in a good state before executing
    cout << "Enter the number of people in the initial circle: ";
    cin >> n;
    cout << "Enter the amount of skips per name: ";
    cin >> k;
    if (!cin) {
    throw runtime_error("Error: Reading n and k from input");
    }

    while (cin >> name && name != ".") { 
        if (!cin) {
            throw runtime_error("Error: Reading name from input");
        }
        names.push_back(name); 
    } // EOF or . ends input

    //Initialize and run game
    Node* startPerson = loadGame(n, names);
    print(startPerson);
    cout << endl;
    Node* lastPerson = runGame(startPerson, k);

    //Prints the winner of the game
    if (lastPerson != nullptr) {
        cout << lastPerson->payload << " wins!" << endl;
        delete lastPerson; //Deletes the last person
    } 
    else { //Checks if the list is empty with no winner
        cout << "Error: Null game" << endl;
    }

    return 0;
}

