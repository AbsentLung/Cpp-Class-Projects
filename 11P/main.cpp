/**	CS515 Assignment 11
	File: main.cpp
	Name: Joseph Bennett
	Section: 3
	Date: 12/03/14
	Collaboration Declaration: None
*/
#include "kruskal.h"
#include <cstdlib>
#include <fstream>

int main(int argc, char** argv) {
	if (argc != 2) { //If a valid number of arguments
		cerr << "invalid number of arguments" << endl;
		exit(1);
	}
	ifstream inFile(argv[1]);
	if (!inFile) { //If file was opened properly
		cout << "Can not open " << argv[1] << " for input" << endl;
		exit(1);
	}
	int weight; //Declare variables
	bool firstConnection = true;
	forest f;
	string line;
	string s1;
	string s2;
	string in;
	string inSplit;
	while (getline(inFile, line)) { //Get each line in the file
		stringstream s(line); //Create a stringstream of the line
		while (s >> s1) { //Output the string, first string is s1
			s >> s2; //Second is s2
			s >> weight; //Third is the weight
			f.insert(s1, s2, weight); //Insert a node from the two strings and the weight
			if (firstConnection) //If it is the first connection
				f.connectTo(s1, true); //First connect to the first connection
			firstConnection = false; //First must have already been ran through
		}
	}
	f.sort(); //Sort the forest
	cout << "<" << f.cur.value << "># "; //Read in the current value to the user
	while(getline(cin, in)) { //Get the line input from the user
		stringstream s(in); //Turn it into a stringstream so that it can be seperated for each string
		while(s >> inSplit) { //Split the string, first string is read in
			if (inSplit == "ping") { //If the word read in is "ping"
				s >> inSplit; //Second word read in is the value that it is pinged to
				if (f.ifExists(inSplit)) { //If the value exists
					f.reset(); //Reset the path
					f.travelNext(f.cur.value); //Travel starting at the current node
					f.findPath("", inSplit, f.cur); //Create a path and read it out to the user
				}
			}
			else if (inSplit == "ssh") { //If the first word read in is "ssh"
				s >> inSplit; //The second word read in is the new node being connected to
				if (f.ifExists(inSplit)) //If it exists
					f.connectTo(inSplit, true); //Connect to the node
			}
			else if (inSplit == "exit") //If the first word read in is "exit"
				f.exit(); //Exit the program
		}
		if (f.connectionPoints.empty()) //If the forest is now empty
			exit(1); //Exit the program
		cout << "<" << f.cur.value << "># "; //Otherwise the current value is promprted to the user for the next command
	}
	return 0;
}
