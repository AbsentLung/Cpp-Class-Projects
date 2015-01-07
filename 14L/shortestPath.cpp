/** CS515 Lab 14
 * File: shortestPath.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 12/12/14
 * Collaboration Declaration:
 * Lab Partner: none
 * Collaboration: none
 */

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>

using namespace std;

int main(){
	string line; //Declare Variables
	getline(cin, line);
	stringstream s(line);
	int size;
	s >> size;
	char value[256];
	const double infinity = numeric_limits<double>::infinity();
	double points[size][size];
	for (int i = 0; i < size; i++) { //For each row
		getline(cin, line); //Get a line
		stringstream s(line);
		for (int j = 0; s >> value; j++) //Read in each point
			if (value[0] == '*') //An asterisk resembles infinity
				points[i][j] = infinity;
			else
				points[i][j] = atoi(value);
	}
	for (int i = 0; i < size; i++) //Sorting algorithm
		for (int j = 0; j < size; j++)
			for (int k = 0; k < size; k++)
				if(points[j][k] > points[j][i] + points[i][k])
					points[j][k] = points[j][i] + points[i][k];
	for (int i = 0; i < size; i++) //Check for negative loops
		for (int j = 0; j < size; j++)
			if (points[i][j] != infinity && points[j][i] != infinity && ( points[j][i] + points[i][j] < 0) ) {
				cout << "Negative loops found." << endl;
				return 0;
			}
	for(int i = 0; i < size; i++) { //Printing algorithm
		for(int j = 0; j < size; j++)
			if (points[i][j] == infinity)
				cout << '*' << '\t';
			else
				cout << points[i][j] << '\t';
		cout << endl;
	}
	return 0;
}
