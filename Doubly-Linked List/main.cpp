/* Hiep Tran - main.cpp - CS010C */

#include <iostream>
#include "IntList.h"

using namespace std;

int main() {
    //Checks empty() function
    IntList emptyTest;
    cout << "Is the list empty? " << (emptyTest.empty() ? "Yes" : "No") << endl;
    emptyTest.push_front(1);
    cout << "Is the list empty? " << (emptyTest.empty() ? "Yes" : "No") << endl;

    //Checks push_front() & push_back() functions
    IntList pushFrontTest;
    cout << "Push Front Test" << endl;
    pushFrontTest.push_front(1);
    cout << pushFrontTest << endl;
    pushFrontTest.push_front(2);
    cout << pushFrontTest << endl;
    
    IntList pushBackTest;
    cout << "Push Back Test" << endl;
    pushBackTest.push_back(-1);
    cout << pushBackTest << endl;
    pushBackTest.push_back(-2);
    cout << pushBackTest << endl;

    //Checks pop_front() & pop_back() functions
    IntList popFrontTest;
    cout << "Pop Front Test" << endl;
    popFrontTest.push_front(1);
    popFrontTest.push_back(2);
    cout << popFrontTest << endl;
    popFrontTest.pop_front();
    cout << popFrontTest << endl;
    
    IntList popBackTest;
    cout << "Pop Back Test" << endl;
    popBackTest.push_front(-100);
    popBackTest.push_back(-200);
    cout << popBackTest << endl;
    popBackTest.pop_back();
    cout << popBackTest << endl;

    //Checks printReverse() function
    IntList reverseTest;
    cout << "Reverse Test" << endl;
    reverseTest.push_back(1);
    reverseTest.push_front(4);
    reverseTest.push_back(3);
    reverseTest.push_back(-101);
    reverseTest.push_front(-7);
    cout << reverseTest << endl;
    reverseTest.printReverse();
    cout << endl;

    //Checks Copy Constructor
    cout << "Copy Constructor Test" << endl;
    IntList copyList;
    copyList.push_front(1);
    copyList.push_back(2);
    copyList.push_back(-293);
    cout << copyList << endl;
    IntList newList(copyList);
    cout << newList << endl;

    //Checks Assignment Operator
    cout << "Assignment Operator Test" << endl;
    IntList test1;
    test1.push_front(-20);
    test1.push_back(5);
    test1.push_back(0);
    cout << test1 << endl;
    IntList test2;
    test2 = test1;
    cout << test2 << endl;

    //Checks to see if all function works properly
    IntList list;

    cout << "empty: " << list << endl;
    list.push_front(3);
    cout << "push front 3: " << list << endl;
    list.push_back(1);
    cout << "push back 1: " << list << endl;
    list.push_back(5);
    cout << "push back 5: " << list << endl;
    list.push_front(2);
    cout << "push front 2: " << list << endl;
    list.pop_back();
    cout << "pop back: " << list << endl;
    list.pop_front();
    cout << "pop front: " << list << endl;

    return 0;
}