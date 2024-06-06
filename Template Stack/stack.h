/* Hiep Tran - stack.h - CS010C */

#pragma once
#include <stdexcept>
#define MAX_SIZE 20

using std::overflow_error;
using std::out_of_range;
using std::underflow_error;

//Creates a template of the class Stack of a given type (T)
template<typename T>
class stack {
    public:
        //Constructs an Empty Stack with size 0
        stack() : size(0) {}
        
        //Push Function that inserts a new element of type T into the data
        void push(T val) {
            //Checks if the current size is greater than the MAX_SIZE set & throws error if needed
            if (size >= MAX_SIZE) {
                throw overflow_error("Called push on full stack.");
            }
            //Inserts the element at size position before incrementing size 
            data[size] = val;
            ++size;
        }
        
        //Pop Function used to remove the last(top) element from the data
        void pop() {
            //Uses empty() function to check size of the stack & throws error if size == 0
            if (empty()) {
                throw out_of_range("Called pop on empty stack.");
            }
            --size; //Decrements the size as the element is removed
        }
        
        //Pop Function used to remove the two last(top) elements from the data
        void pop_two() {
            //Uses empty() function to check size of the stack & throws error if size == 0
            if (empty()) {
                throw out_of_range("Called pop_two on empty stack.");
            }
            //Checks the size as removing two elements leads to out_of_range error
            if (size == 1) {
                throw out_of_range("Called pop_two on a stack of size 1.");
            }
            size -= 2; //Decrements the size as two elements are removed
        }
        
        //Top Function to get the last element added to the data
        T& top() {
            //Uses empty() function to check size of the stack & throws error if size == 0
            if (empty()) {
                throw underflow_error("Called top on empty stack.");
            }
            //Gets the index of the last element 
            return data[size-1];
        }

        const T& top() const {
            //Uses empty() function to check size of the stack & throws error if size == 0
            if (empty()) {
                throw underflow_error("Called top on empty stack.");
            }
            //Gets the index of the last element 
            return data[size-1];
        }
        
        //Empty Function that returns true or false if the size == 0
        bool empty() const {
            return size == 0;
        }
    
    private:
        //An array of type T with the given MAX_SIZE 
        T data[MAX_SIZE];
        int size;
};