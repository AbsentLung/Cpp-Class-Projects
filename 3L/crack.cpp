/**
CS515 Lab 3
File: crack.cpp
Name: Joseph Bennett
Section: 3
Date: 09/26/14
Collaboration Declaration: none
Lab  Partner:  none
Collaboration:  none
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

//This program reads from a file storing binary numbers and searches for a secret number
int main(int argc, char** argv){
	if (argc != 2){//If wrong number of arguments
		cout << "wrong number of arguments" << endl;
		exit(1);
	}
	ifstream inFile(argv[1], ios::in | ios::binary);
	if (!inFile){//If file cannot be opened
		cout << "Can't open " << argv[1] << "." << endl;
		exit(1);
	}
	int tmp;//Decalre Variables
	int index;
	inFile.seekg(sizeof(int), inFile.beg);//Seek to second integer
	inFile.read((char*)&index, sizeof(int));//The index is equal to the second integer
	inFile.seekg((index+2)*sizeof(int), inFile.beg);//Seek to the index
	inFile.read((char*)&tmp, sizeof(int));//Number read in is from the index
	cout<<"Value at index "<<index<<" is "<<tmp<<endl;
	return 0;
}
