/** CS515 Assignment 9
 * File: phonewords.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 11/15/14
 * Collaboration Declaration: none
 * Lab  Partner: none 
 * Collaboration: none
 * */
#include <iostream>
#include <fstream>
#include <string>
#include "map.h"
#include <stdlib.h>

Map<string,string> m;

void outString(string outputString, string numberIn, int placeHolder) {
	cerr << outputString << endl;
	if (placeHolder==10) //If the length of the words put together is 10 then it is complete
		cerr << outputString << endl;
	else if (numberIn[placeHolder]=='1') //If a 1 then the next output is a dash
		outString(outputString + " -", numberIn, placeHolder+1);
	else if (numberIn[placeHolder]=='0') //If a 0 then the next output is a 0
		outString(outputString + " 0", numberIn, placeHolder+1);
	else //Otherwise the next output word is a string
		for (int i = placeHolder; i <= numberIn.length(); i++) //So that the shortest phone number is first
			for (Set<string>::Iterator it = m.allKeys.begin(); it != m.allKeys.end(); it++) //Iterate through every word
				if (placeHolder + it->info.length() <= 10 && m.find(it->info)->data == numberIn.substr(placeHolder, i-placeHolder))
					outString(outputString + " " + it->info, numberIn, placeHolder + it->info.length());
}

string convert(string str) { //Convert from word to phone word
	string returnNumber = "";
	for(int i = 0; i < str.length(); i++) //Search through every character in the string
		switch(tolower(str[i])) { //Attach the number with the key on the phone
			case 'a':
			case 'b':
			case 'c':
				returnNumber+='2';
				break;
			case 'd':
			case 'e':
			case 'f':
				returnNumber+='3';
				break;
			case 'g':
			case 'h':
			case 'i':
				returnNumber+='4';
				break;
			case 'j':
			case 'k':
			case 'l':
				returnNumber+='5';
				break;
			case 'm':
			case 'n':
			case 'o':
				returnNumber+='6';
				break;
			case 'p':
			case 'q':
			case 'r':
			case 's':
				returnNumber+='7';
				break;
			case 't':
			case 'u':
			case 'v':
				returnNumber+='8';
				break;
			case 'w':
			case 'x':
			case 'y':
			case 'z':
				returnNumber+='9';
				break;
			default:
				break;
		}
	return returnNumber;
}

int main(int argc, char** argv) {
	if (argc != 2){ //If wrong number of arguments entered, alert the user
		cout << "wrong number of arguments" << endl;
		return 1;
	}
	ifstream infile(argv[1]);
	if (!infile){ //If file cannot be opened, alert the user
		cout << "can not open " << argv[1] << " for input." << endl;
		return 1;
	}
	Map<string,string> m; //Create map
	string word;
	string numberIn;
	while (infile >> word) //Take ever word
		m[word] = convert(word); //And map a phone number to the word
	cout << "Input a 10 digit number" << endl; //Prompt the user to input a 10 digit number
	while (cin >> numberIn) {
		if (numberIn[0]=='1') //If it starts with 1, recursive method starts with a -
			outString("-", numberIn, 1);
		else if (numberIn[0]=='0') //If it starts with 1, recursive method starts with a 0
			outString("0", numberIn, 1);
		else //Otherwise it starts with a word
			for (int i = 0; i <= numberIn.length(); i++) //The whole map is iterated through until the first matching word is found
				for (Set<string>::Iterator it=m.allKeys.begin(); it!=m.allKeys.end(); it++)
					if (it->info.length()<=10&&m.find(it->info)->data==numberIn.substr(0, i)) //If the phone number matches
						outString(m.find(it->info)->key, numberIn, it->info.length());
		cout << "Input a 10 digit number" << endl; //Prompt the user to input a 10 digit number
	}
	return 0;
}
