/* Hiep Tran - main.cpp - CS010C */

#include "stack.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main() {
    cout << "Enter a test number(1-7): ";
    int test;
    cin >> test;
    cout << endl;
    //Tests Constructor - Push - Pop - Top - Empty
    if (test == 1) {
        try {
            //Construct a new stack
            cout << "\nstack1 constructor called";
            stack<int> stack1;
            //Check if empty function works
            if (stack1.empty()) {
                cout << "\nstack1 is empty.";
            } 
            else {
                cout << "\nstack1 is not empty";
            }
            //Add elements to the stack
            cout << "\npush 10";
            stack1.push(10);
            cout << "\npush 20";
            stack1.push(20);
            cout << "\npush 30";
            stack1.push(30);
            //Display the top element
            cout << "\nstack1 top: ";
            cout << stack1.top();
            //Remove the top element
            cout << "\npop";
            stack1.pop();
            cout << "\nstack1 top: ";
            cout << stack1.top();
            cout << "\npop";
            stack1.pop();
            cout << "\nstack1 top: ";
            cout << stack1.top();
            cout << "\npop";
            stack1.pop();
            //Check if the stack is empty after popping all
            if (stack1.empty()) {
                cout << "\nstack1 is empty.";
            } 
            else {
                cout << "\nstack1 is not empty";
            }
            cout << endl;
        } 
        //Catch the exceptions thrown by the functions
        catch (underflow_error & e) {
            cout << e.what() << endl;
        } 
        catch (overflow_error & e) {
            cout << e.what() << endl;
        } 
        catch (out_of_range & e) {
            cout << e.what() << endl;
        }
    }
    
    //Tests Top on Empty Stack
    if (test == 2) {
        try {
            //Construct a new stack
            cout << "\nstack2 constructor called";
            stack<int> stack2;
            //Tries to display the top element of an empty stack
            cout << "\nstack2 top: ";
            cout << stack2.top();
            cout << endl;
        } 
        //Catch the exceptions thrown by the functions
        catch (underflow_error & e) {
            cout << e.what() << endl;
        } 
        catch (overflow_error & e) {
            cout << e.what() << endl;
        } 
        catch (out_of_range & e) {
            cout << e.what() << endl;
        }
    }

    //Tests Pop on Empty Stack
    if (test == 3) {
        try {
            //Construct a new stack
            cout << "\nstack3 constructor called";
            stack<int> stack3;
            //Tries to remove the top element of an empty stack
            cout << "\npop from empty stack\n";
            stack3.pop();
            cout << endl;
        } 
        //Catch the exceptions thrown by the functions
        catch (underflow_error & e) {
            cout << e.what() << endl;
        } 
        catch (overflow_error & e) {
            cout << e.what() << endl;
        } 
        catch (out_of_range & e) {
            cout << e.what() << endl;
        }
    }

    //Tests Pop_Two on Empty Stack  
    if (test == 4) {
        try {
            //Construct a new stack
            cout << "\nstack4 constructor called";
            stack<int> stack4;
            //Tries to remove two top elements of an empty stack
            cout << "\npop_two from empty stack\n";
            stack4.pop_two();
            cout << endl;
        } 
        //Catch the exceptions thrown by the functions
        catch (underflow_error & e) {
            cout << e.what() << endl;
        } 
        catch (overflow_error & e) {
            cout << e.what() << endl;
        } 
        catch (out_of_range & e) {
            cout << e.what() << endl;
        }
    }

    //Tests Push on Full Stack
    if (test == 5) {
        try {
            //Construct a new stack
            cout << "\nstack5 constructor called";
            stack<int> stack5;
            //Add 20 elements to the stack
            cout << "\npush 20 elements";
            for (int i = 1; i <= 20; ++i) {
                stack5.push(i);
            }
            //Try to add one more element to the full stack
            cout << "\nstack5 top: ";
            cout << stack5.top();
            cout << "\npush 21\n";
            stack5.push(21);
            cout << endl;
        } 
        //Catch the exceptions thrown by the functions
        catch (underflow_error & e) {
            cout << e.what() << endl;
        } 
        catch (overflow_error & e) {
            cout << e.what() << endl;
        } 
        catch (out_of_range & e) {
            cout << e.what() << endl;
        }
    }

    //Tests Stack of Strings (Pop)
    if (test == 6) {
        try {
            //Construct a new stack
            cout << "\nstack6 constructor called";
            stack<string> stack6;
            //Add elements to the stack
            cout << "\npush A";
            stack6.push("A");
            cout << "\npush B";
            stack6.push("B");
            cout << "\npush C";
            stack6.push("C");
            cout << "\nstack6 top: ";
            cout << stack6.top();
            //Remove the top element
            cout << "\npop";
            stack6.pop();
            cout << "\nstack6 top: ";
            cout << stack6.top();
            cout << "\npop";
            stack6.pop();
            cout << "\nstack6 top: ";
            cout << stack6.top();
            cout << "\npop";
            stack6.pop();
            //Check if the stack is empty after popping all
            if (stack6.empty()) {
                cout << "\nstack6 is empty.";
            } 
            else {
                cout << "\nstack6 is not empty";
            }
            //Try to display the top element of an empty stack
            cout << "\nstack6 top: \n";
            stack6.top();
            cout << endl;
        } 
        //Catch the exceptions thrown by the functions
        catch (underflow_error & e) {
            cout << e.what() << endl;
        } 
        catch (overflow_error & e) {
            cout << e.what() << endl;
        } 
        catch (out_of_range & e) {
            cout << e.what() << endl;
        }
    }

    //Tests Stack of Strings (Pop_Two)
    if (test == 7) {
        try {
            //Construct a new stack
            cout << "\nstack7 constructor called";
            stack<string> stack7;
            //Add elements to the stack
            cout << "\npush A";
            stack7.push("A");
            cout << "\npush B";
            stack7.push("B");
            cout << "\npush C";
            stack7.push("C");
            cout << "\nstack7 top: ";
            cout << stack7.top();
            //Remove the two top elements
            cout << "\npopping two items";
            stack7.pop_two();
            cout << "\nstack7 top: ";
            cout << stack7.top();
            cout << "\npopping two items";
            stack7.pop_two();
            cout << "\npopping two items";
            stack7.pop_two();
            // Check if the stack is empty after popping all
            if (stack7.empty()) {
                cout << "\nstack7 is empty.";
            } 
            else {
                cout << "\nstack7 is not empty";
            }
            //Try to display the top element of an empty stack
            cout << "\nstack7 top: \n";
            stack7.top();
            cout << endl;
        } 
        //Catch the exceptions thrown by the functions
        catch (underflow_error & e) {
            cout << e.what() << endl;
        } 
        catch (overflow_error & e) {
            cout << e.what() << endl;
        } 
        catch (out_of_range & e) {
            cout << e.what() << endl;
        }
    }
}