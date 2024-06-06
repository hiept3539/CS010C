/* Hiep Tran - main.cpp- CS010C */

#include "Jug.h"

using namespace std;

int main() {
	{
		//Creates a Jug object with the following parameters
		string solution;
		Jug head(3, 5, 4, 1, 2, 3, 4, 5, 6);
		//If no solution, then print out an error message
		if (head.solve(solution) != 1) {
			cout << "Error 3" << endl;
		}
		cout << solution << endl << endl;
	}
	{
		//Creates a Jug object with the following parameters
		string solution;
		Jug head(3, 5, 4, 1, 1, 1, 1, 1, 2);
		//If no solution, then print out an error message
		if (head.solve(solution) != 1) {
			cout << "Error 3" << endl;
		}
		cout << solution << endl;
	}
}
