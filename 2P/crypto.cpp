/** CS515 Assignment 2
 * File: crypto.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 9/15/13
 * Collaboration Declaration: No assistance recieved
 * */ 
//This program takes all of the characters in an input file and converts
//it to a different set of encrypted characters in an output file.  A
//password is then used to decrypt the characters.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void errFound(ifstream& file1, ofstream& file2, string errMsg){//Error is found, close the files and display a message
	cout<<errMsg<<endl;
	file1.close();
	file2.close();
}

int main (int argc, char *argv[]) {
	if (argc != 5) {//This error must be checked before inFile and outFile are created
		cout << "wrong number of arguments" << endl;//Number of arguments checked and is wrong
		return 0;
	}
	string line;//Declare variables
	string encDec = argv[1];
	string psswd = argv[2];
	string inFileStr = argv[3];
	ifstream inFile (inFileStr.c_str());
	ofstream outFile (argv[4]);
	int psswdInt[psswd.length()];
	int i = 0;
	int j = 0;
	int ASCode;
	bool nLC = true;
	while (psswd[i]){//Search through password
		if (psswd[i] < 97 || psswd[i] > 122)//If a capital letter
			nLC = false;
		psswdInt[i] = psswd[i] - 97;
		i++;
	}
	if (encDec != "e" && encDec != "d")
		errFound(inFile, outFile, "must enter e for encryption or d for decryption");
	else if (psswd.length() > 10 || nLC == false)
		errFound(inFile, outFile, "key must have less than 10 all lower case letters");
	else if (!inFile.is_open())
		errFound(inFile, outFile, "can not open " + inFileStr + " for input");
	else {
		while ( getline (inFile,line) ) {
			for(i=0; line[i]; i++) {
				if (line[i] <= 90 && line[i] >= 65)
					line[i] += 32;
				if (line[i] <= 122 && line[i] >= 97) {
					if (encDec == "e") {
						ASCode = psswdInt[j] + line[i];
						if (ASCode > 122)
							ASCode -= 26;
						line[i] = ASCode;
					}
					else {
						ASCode = line[i] - psswdInt[j];
						if (ASCode < 97)
							ASCode += 26;
						line[i] = ASCode;
					}
					if (j < psswd.length())
						j++;
					else
						j = 0;
				}
			}
			outFile << line << endl;
		}
		inFile.close();
		outFile.close();
	}
	return 0;
}
