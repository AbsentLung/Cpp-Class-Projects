/** CS515 Lab 7
 * File: words.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 10/25/14
 * Collaboration Declaration: None
 * Lab Partner: None
 * Collaboration: None
 * */
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

int main (int argc, char *argv[]) {
	if (argc != 2) {//This error must be checked before inFile and outFile are created
		cout << "wrong number of arguments" << endl;//Number of arguments checked and is wrong
		return 0;
	}
	string inFileStr = argv[1]; //Initialize variables
	ifstream inFile (inFileStr.c_str());
	string uWord;
	string uYear;
	int yr;
	stringstream s;
	map<string, map<int, string> > words; //3-dimensional map
	for (string word, frequency, other; inFile >> word >> yr >> frequency >> other;) //Grab the 4 strings on each line
		words[word][yr] = frequency; //Assign frequency
	cout << "Which word starting in which year? (q to quit) "; //Prompt the user to enter
	while (cin >> uWord && uWord != "q") { //While input comes in and "q" isn't pressed
		if (cin >> yr && yr>1800) { //If the input is an integer greater than 1800
			if (words[uWord][yr].empty()) //If the lowercase word isn't found then try it with an uppercase first letter
				uWord[0] = uWord[0]-32;
			while (yr!=2013) { //While the year isn't 2013
				if (words[uWord][yr].empty()) //If there is no count
					cout << yr << " 0" << endl; //0 words are found
				else
					cout << yr << " " << words[uWord][yr] << endl; //Otherwise the specified count is found
				yr++; //Increment the year
			}
		}
		cout << "Which word starting in which year? (q to quit) "; //Prompt the user to enter again
	}
	return 0;//End the program
}
