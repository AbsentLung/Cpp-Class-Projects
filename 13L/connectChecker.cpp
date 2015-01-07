/**	CS515 Lab 13
	File: connectChecker.cpp
	Name: Joseph Bennett
	Section: 3
	Date: 12/03/14
	Collaboration Declaration: None
	Lab Partner: None
	Collaboration:None
*/

#include <map>
#include <list>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
map<char, list<char> > m; //Assign static variables
list<char> checked;

bool findPath(char c, char c1){ //Returns true if the path is found
	list<char>::iterator listIt1; //Assign variables
	list<char>::iterator listIt2;
	bool performRecursion;
	if (c==c1) //If the two characters already match
		return true; //Return true
	else //Otherwise
		for(listIt1=m[c].begin(); listIt1 != m[c].end() ; listIt1++) { //Search through the character's list
			performRecursion=true;
			for(listIt2=checked.begin(); listIt2 != checked.end() ; listIt2++) //Search through the list of already checked characters
				if (*listIt1==*listIt2) { //If the character has already been checked
					performRecursion=false; //Do not perform recursion
					break; //Do not bother checking other characters
				}
			if(performRecursion) { //If character has not yet been checked, call recursion
				checked.push_back(*listIt1); //Mark as a checked character
				if (findPath(*listIt1, c1)) //Call recursion
					return true; //If character is found, return true
			}
		}
	return false; //If entire list is searched and path isn't found, return false
}

int main() {
	string line; //Assign variables
	char ch1;
	char ch2;
	char ch3;
	while (getline(cin, line)) { //Get every line
		stringstream s(line);
		s >> ch1; //The first character entered
		s >> ch2; //The second character entered
		if (ch1 == '?') { //If the first character is a question mark then it is to be checked for
			s >> ch3; //The third characer entered
			checked.clear(); //Clear the list of checked items
			checked.push_back(ch2); //Character currently added as checked
			cerr << "from " << ch2 << " to " << ch3 << " : ";
			if (findPath(ch2, ch3)) //If path is found
				cerr<<"path found."<<endl;
			else //If it isn't found
				cerr<<"path not found."<<endl;
		}
		else //Otherwise a path is meant to be inserted
			m[ch1].push_back(ch2); //Add the character to the list of paths
	}
	return 0;
}
