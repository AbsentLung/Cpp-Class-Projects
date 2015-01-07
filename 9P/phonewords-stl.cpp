/** CS515 Assignment 9
 * File: phonewords-st1.cpp
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
#include <map>
#include <stdlib.h>

using namespace std;

void outString(string outputString, string numberIn, int placeHolder, map<string,string> m) {
	map<string,string>::iterator it;
	if (placeHolder==10) //If the length of the words put together is 10 then it is complete
		cerr << outputString << endl;
	else if (numberIn[placeHolder]=='1') //If a 1 then the next output is a dash
		outString(outputString + " -", numberIn, placeHolder+1, m);
	else if (numberIn[placeHolder]=='0') //If a 0 then the next output is a 0
		outString(outputString + " 0", numberIn, placeHolder+1, m);
	else //Otherwise the next output word is a string
		for (int i = placeHolder; i <= numberIn.length(); i++) //So that the shortest phone number is first
			for (it=m.begin(); it!=m.end(); ++it) //Iterate through every word
				if (placeHolder+it->second.length()<=10&&it->second==numberIn.substr(placeHolder, i-placeHolder))
					outString(outputString + " " + it->first, numberIn, placeHolder + it->second.length(), m); //Recursive repeat
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
	map<string,string> m; //Create map
	map<string,string>::iterator it; //Create iterator for the map
	string word;
	string numberIn;
	while (infile >> word) //Take ever word
		m[word] = convert(word); //And map a phone number to the word
	cout << "Input a 10 digit number" << endl; //Prompt the user to input a 10 digit number
	while (cin >> numberIn) {
		if (numberIn[0]=='1') //If it starts with 1, recursive method starts with a -
			outString("-", numberIn, 1, m);
		else if (numberIn[0]=='0') //If it starts with 1, recursive method starts with a 0
			outString("0", numberIn, 1, m);
		else //Otherwise it starts with a word
			for (int i = 0; i <= numberIn.length(); i++) //The whole map is iterated through until the first matching word is found
				for (it=m.begin(); it!=m.end(); ++it) //The whole map is iterated through until the first matching word is found
					if (it->second.length()<=10&&it->second==numberIn.substr(0, i)) //If the phone number matches
						outString(it->first, numberIn,  it->second.length(), m);
		cout << "Input a 10 digit number" << endl; //Prompt the user to input a 10 digit number
	}
	return 0;
}
