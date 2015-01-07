/** CS515 Assignment 5
 * File: sites.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 10/17/14
 * Collaboration Declaration: none
 * Lab  Partner: none 
 * Collaboration: none
 * */
#include "set.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


int main(int argc, char *argv[]){
	Set s[argc]; //Initialize variables
	int count = 0;
	int inEach [argc];
	string line [argc];
	ifstream inputFiles [argc];
	stringstream ss [argc];
	stringstream anySS;
	stringstream allSS;
	string countWords;
	Set inter;
	for (int i = 1; i < argc; i++) { //For each file
		inputFiles[i].open (argv[i]); //Open the file
		while (getline (inputFiles[i],line[i])) //Get every line in the file
			s[i].insert(line[i]); //Insert each line as an IP Address
	}
	Set any = s[1];
	for (int j = 2; j < argc; j++) //Union all sets
		any = any | s[j];
	anySS << any;
	while (anySS >> countWords) //Count each IP
		count++;
	cerr << "visitors of ANY 3 sites: " << count << endl;
	Set all = s[1];
	for (int j = 2; j < argc; j++) //Intersect all sets
		all = all & s[j];
	count = 0; //Reset count
	allSS << all;
	while (allSS >> countWords) //Count each IP
		count++;
	cerr << "visitors of ALL 3 sites: " << count << endl;
	for (int i = 1; i < argc; i++) { //For each file
		count = 0; //Reset count
		inter = s[i];
		for (int j = 1; j < argc; j++) {
			if (j != i) //If not the current set
				inter = inter - s[j]; //Difference each set
		}
		ss[i] << inter;
		while (ss[i] >> countWords) //Count each IP
			count++;
		cerr << "visitors of " << argv[i] << " but not of any other sites: " << count << endl;
	}
}
