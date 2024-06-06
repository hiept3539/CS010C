/* Hiep Tran - Jug.h - CS010C */

#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <vector>

using std::string;
using std::vector;

//Creates a constant integer that represents infinity
const int infinity = std::numeric_limits<int>::max();

//Struct that represents a vertex in the graph
struct Vertex {
    int distance; //Distance from the source vertex
    Vertex* previous; //Pointer to the previous vertex
    string actionChoice; //String that represents the action taken to get to this vertex
    Vertex() : distance(infinity), previous(nullptr), actionChoice("") {} //Default constructor
};

class Jug {
    public:
        Jug(int, int, int, int, int, int, int, int, int); //Default Constructor
        ~Jug(); //Destructor
        Jug(const Jug&); //Copy constructor
        Jug& operator=(const Jug&); //Assignment operator
        int solve(string &); //Solves the jug problem
    private:
        int capacityA; //Capacity of jug A
        int capacityB; //Capacity of jug B
        int goalCapacity; //Final goal capacity
        int costFillA; //Cost to fill jug A
        int costFillB; //Cost to fill jug B
        int costEmptyA; //Cost to empty jug A
        int costEmptyB; //Cost to empty jug B
        int costPourAB; //Cost to pour from jug A to jug B
        int costPourBA; //Cost to pour from jug B to jug A
    private:
        vector<vector<Vertex*>> jugGraph; //2D Vector that represents the graph
        bool validInput() const; //Function that checks if the input is valid
        void createGraph(int, int, int, Vertex*, string); //Function that creates the graph
        void printSolution(Vertex*, string&) const; //Function that prints the solution
};