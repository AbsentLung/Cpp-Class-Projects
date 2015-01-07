/** CS515 Assignment 6
 * File: wordcheck.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 10/27/14
 * Collaboration Declaration: none
 * Lab  Partner: none 
 * Collaboration: none
 * */

#include "map.h"
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
using namespace std;

int main(int argc, char *argv[]){
	if (argc != 3 && argc != 4) { //If the number of arguments isn't 3 or 4
		cout << "wordcheck <dictionary file> <min length> <max length>" << endl; //User is notified
		return 0; //Program exits
	}
	string line; //Initialize variables
	ifstream words(argv[1]);
	stringstream s1(argv[2]);
	stringstream s2;
	int min;
	int max;
	bool boo;
	Map<string, int> dicMap;
	s1>>min;
	if (argc==3)
		max=min;
	else {
		s2<<argv[3];
		s2>>max;
	}
	if (!words) { //If file cannot be found
		cout << "file cannot be found" << endl;
		return 0;
	}
	if (min>max) { //If the minimum is greater than the maximum
		cout << "error min or max length" << endl;
		return 0;
	}
	while (getline (words,line)) { //Grab every line in "words"
		boo = true;
		if (line.length() >= min && line.length() <= max) { //If line length is in between the minimum and maximum
			for (int i=0; line[i]; i++) { //Go through every character in the line
				if (line[i] >= 'A' && line[i] <= 'Z') //If uppercase, make it lower case
					line[i] = line[i]+32;
				if (line[i] < 'a' || line[i] > 'z') //If alphabetic character
					boo = false;
			}
			if (boo) //If insertable
				dicMap.insert(line, line.length()); //Insert into the map
		}
	}
	while (cin) { //While data comes in
		string userWord;
		if (argc==3) //If only one amount of characters
			cout << "Please input a " << argv[2] << " letter word: ";
		else
			cout << "Please input a " << argv[2] << " - " << argv[3] << " letter word: ";
		Map<string, int>::Iterator iter = dicMap.begin(); //Create iterator
		int totWrd = 0; //Total starts at zero
		if(!(cin >> userWord))
			return 0;
		if (userWord.length() < min || userWord.length() > max) //If the word length doesn't match
			cout << "wrong length" << endl;
		else {
			for (int i = 0; i < userWord.length(); i++) { //Go through each letter
				iter=dicMap.begin(); //Iterator starts at the beginning
				while (iter->next) { //Go through each word
					if (iter->key.length()==userWord.length()) { //If the lengths match
						boo = true;
						for (int j = 0; j < userWord.length(); j++) //For each letter
							if (j!=i) //If not the current letter
								if (userWord[j] != iter->key[j]) //If the letter doesn't match
									boo = false; //return False
						if (boo && userWord != iter->key) { //If the word isn't the same and a match is made
							totWrd++; //Increase the count
							cout << iter->key << " "; //Print out the word
						}
					}
					iter++; //Iterate to the next word
				}
			}
			cout << endl << "Total " << totWrd << " words." << endl; //The total is printed out
		}
	}
	return 0;
}
