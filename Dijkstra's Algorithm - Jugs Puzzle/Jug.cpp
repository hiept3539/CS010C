/* Hiep Tran - Jug.cpp - CS010C */

#include "Jug.h"

//Default Constructor that takes in characteristics of the jugs and creates a graph
Jug::Jug(int capacityA, int capacityB, int goalCapacity, int costFillA, int costFillB, int costEmptyA, int costEmptyB, int costPourAB, int costPourBA) {
    //Assigns the parameter inputs to the member variables
    this->capacityA = capacityA;
    this->capacityB = capacityB;
    this->goalCapacity = goalCapacity;
    this->costFillA = costFillA;
    this->costFillB = costFillB;
    this->costEmptyA = costEmptyA;
    this->costEmptyB = costEmptyB;
    this->costPourAB = costPourAB;
    this->costPourBA = costPourBA;

    //If the input is invalid, then set the graph to an empty graph
    if(!validInput()) {
        jugGraph = {};
        return;
    }
    
    // Creates a 2D vector that represents the graph. The size of the graph is determined by the capacities of the two jugs (capacityA and capacityB)
    // Each cell in the 2D vector initially contains a nullptr, indicating that no Vertex object has been assigned to that cell yet
    jugGraph = vector<vector<Vertex*>>(capacityA + 1, vector<Vertex*>(capacityB + 1, nullptr));
    for (int i = 0; i <= capacityA; ++i) {
        for (int j = 0; j <= capacityB; ++j) {
            // Creates a new Vertex object and assigns it to the current cell in the 2D vector
            // This means that each cell in the 2D vector will contain a pointer to a Vertex object
            jugGraph[i][j] = new Vertex();
        } 
    }  
    // Calls the createGraph function to populate the graph with vertices and edges with an intial empty state
    createGraph(0, 0, 0, nullptr, "");
}

//Destructor that deletes all the Vertex objects in the graph
Jug::~Jug() {
    //Iterates through the 2D vector and deletes each Vertex object going through each row and column
    for (unsigned vectorRow = 0; vectorRow < jugGraph.size(); ++vectorRow) {
        for (unsigned rowVertex = 0; rowVertex < jugGraph[vectorRow].size(); ++rowVertex) {
            delete jugGraph[vectorRow][rowVertex]; //Deletes the Vertex object
        }
    }
}

//Copy Constructor that creates a deep copy of the Jug object
Jug::Jug(const Jug& copyGraph) {
    //Assigns the member variables of the Jug object to the member variables of the copied Jug object
    capacityA = copyGraph.capacityA;
    capacityB = copyGraph.capacityB;
    goalCapacity = copyGraph.goalCapacity;
    costFillA = copyGraph.costFillA;
    costFillB = copyGraph.costFillB;
    costEmptyA = copyGraph.costEmptyA;
    costEmptyB = copyGraph.costEmptyB;
    costPourAB = copyGraph.costPourAB;
    costPourBA = copyGraph.costPourBA;

    //Creates a 2D vector that represents the graph with the same size as the copied Jug object
    jugGraph = vector<vector<Vertex*>>(capacityA + 1, vector<Vertex*>(capacityB + 1, nullptr));
    //Iterates through the 2D vector and creates a deep copy of each Vertex object in the copied Jug object
    for (int i = 0; i <= capacityA; ++i) {
        for (int j = 0; j <= capacityB; ++j) {
            //Creates a deep copy of the Vertex object in the copied Jug object and assigns it to the current cell in the 2D vector
            jugGraph[i][j] = new Vertex(*copyGraph.jugGraph[i][j]);
        }
    }  
}

//Assignment Operator that assigns the Jug object to another Jug object
Jug& Jug::operator=(const Jug& copyGraph) {
    if (this != &copyGraph) { //Checks for self-assignment
        //Deletes all the Vertex objects in the graph
        for (unsigned vectorRow = 0; vectorRow < jugGraph.size(); ++vectorRow) {
            for (unsigned rowVertex = 0; rowVertex < jugGraph[vectorRow].size(); ++rowVertex) {
                delete jugGraph[vectorRow][rowVertex];
            }
        }
        //Assigns the member variables of the Jug object to the member variables of the copied Jug object
        capacityA = copyGraph.capacityA;
        capacityB = copyGraph.capacityB;
        goalCapacity = copyGraph.goalCapacity;
        costFillA = copyGraph.costFillA;
        costFillB = copyGraph.costFillB;
        costEmptyA = copyGraph.costEmptyA;
        costEmptyB = copyGraph.costEmptyB;
        costPourAB = copyGraph.costPourAB;
        costPourBA = copyGraph.costPourBA;

        //Creates a 2D vector that represents the graph with the same size as the copied Jug object
        jugGraph = vector<vector<Vertex*>>(capacityA + 1, vector<Vertex*>(capacityB + 1, nullptr));
        for (int i = 0; i <= capacityA; ++i) {
            for (int j = 0; j <= capacityB; ++j) {
                //Creates a deep copy of the Vertex object in the copied Jug object and assigns it to the current cell in the 2D vector
                jugGraph[i][j] = new Vertex(*copyGraph.jugGraph[i][j]);
            }
        }
    }  
    return *this;
}

//Function that checks if the input is valid
bool Jug::validInput() const {
    //Conditions that the input must satisfy
    return capacityA >= 0 && capacityB >= 0 && goalCapacity >= 0 && costFillA >= 0 && costFillB >= 0 && costEmptyA >= 0 && costEmptyB >= 0 && costPourAB >= 0 && costPourBA >= 0 && capacityA <= capacityB && goalCapacity <= capacityB && capacityB <= 1000;
}

//Function that solves the jug problem
int Jug::solve(string& solution) {
    //If the input is invalid, then clear the solution and return -1
    if (!validInput()) {
        solution.clear(); //Clears the solution
        return -1;
    }
    
    solution.clear(); 
    //Sets the shortest path to infinity and the end vertex to nullptr
    int shortestPath = infinity;
    Vertex* endVertex = nullptr;

    //Iterates through the 2D vector and finds the shortest path to the goal capacity for the first jug
    for (int i = 0; i < capacityA; ++i) {
        //If the distance of the current vertex is less than the shortest path, then update the shortest path and the end vertex
        if (jugGraph[i][goalCapacity]->distance < shortestPath) {
            shortestPath = jugGraph[i][goalCapacity]->distance;
            endVertex = jugGraph[i][goalCapacity];
        }
    }
    
    //Iterates through the 2D vector and finds the shortest path to the goal capacity for the second jug
    for (int j = 0; j < capacityB; ++j) {
        //If the distance of the current vertex is less than the shortest path, then update the shortest path and the end vertex
        if (goalCapacity <= capacityA && jugGraph[goalCapacity][j]->distance < shortestPath) {
            shortestPath = jugGraph[goalCapacity][j]->distance;
            endVertex = jugGraph[goalCapacity][j];
        }
    }
    
    //If the end vertex is nullptr or the distance of the end vertex is infinity, then return 0
    if (!endVertex || endVertex->distance == infinity) {
        return 0;
    }

    //Calls the printSolution function to print the solution
    printSolution(endVertex, solution);
    //Appends the solution with the success message and the shortest path
    solution += "success " + std::to_string(shortestPath);
    return 1;
}

//Function that creates the graph
void Jug::createGraph(int jugA, int jugB, int cost, Vertex* prev, string action) {
    Vertex* currentVertex = jugGraph[jugA][jugB]; //Gets the current vertex in the graph
    
    //If the cost is less than the distance of the current vertex, then update the distance, previous vertex, and action choice
    if (cost < currentVertex->distance) {
        currentVertex->distance = cost;
        currentVertex->previous = prev;
        currentVertex->actionChoice = action;
        
        //If jugA or jugB is not at its capacity, then recursively call the createGraph function to create the graph
        if (jugA != capacityA) {
            //If the jug A is not at its capacity, then fill jug A
            createGraph(capacityA, jugB, cost + costFillA, currentVertex, "fill A");
        }
        if (jugB != capacityB) {
            //If the jug B is not at its capacity, then fill jug B
            createGraph(jugA, capacityB, cost + costFillB, currentVertex, "fill B");
        }
        //If the jug A is not empty or the jug B is not empty, then recursively call the createGraph function to create the graph
        if (jugA != 0) {
            //If jug A is not empty, then empty jug A
            createGraph(0, jugB, cost + costEmptyA, currentVertex, "empty A");
        }
        if (jugB != 0) {
            //If jug B is not empty, then empty jug B
            createGraph(jugA, 0, cost + costEmptyB, currentVertex, "empty B");
        }
        
        
        int amountPourAB;
        if (jugA < capacityB - jugB) {
            //If jug A is less than the capacity of jug B minus jug B, then pour all of jug A into jug B
            amountPourAB = jugA;
        }
        else {
            //If jug A is greater than the capacity of jug B minus jug B, then pour the capacity of jug B minus jug B into jug B
            amountPourAB = capacityB - jugB;
        }
        
        //If the amount to pour from jug A to jug B is greater than 0, then recursively call the createGraph function to create the graph
        if (amountPourAB > 0) {
            //Pour from jug A to jug B the amount determined by the amountPourAB
            createGraph(jugA - amountPourAB, jugB + amountPourAB, cost + costPourAB, currentVertex, "pour A B");
        }

        int amountPourBA;
        if (jugB < capacityA - jugA) {
            //If jug B is less than the capacity of jug A minus jug A, then pour all of jug B into jug A
            amountPourBA = jugB;
        } else {
            //If jug B is greater than the capacity of jug A minus jug A, then pour the capacity of jug A minus jug A into jug A
            amountPourBA = capacityA - jugA;
        }

        //If the amount to pour from jug B to jug A is greater than 0, then recursively call the createGraph function to create the graph
        if (amountPourBA > 0) {
            //Pour from jug B to jug A the amount determined by the amountPourBA
            createGraph(jugA + amountPourBA, jugB - amountPourBA, cost + costPourBA, currentVertex, "pour B A");
        }
    }
}

//Function that prints the solution
void Jug::printSolution(Vertex* currentVertex, string& solution) const {
    //If the previous vertex is nullptr, then return
    if (currentVertex->previous == nullptr) {
        return;
    }
    //Recursively calls the printSolution function to print the solution
    printSolution(currentVertex->previous, solution);
    //Appends the solution with the action choice
    solution += currentVertex->actionChoice + '\n';
}