/** CS515 Assignment 10
 * File: HuffmanCoder.cpp
 * Name: Joseph Bennett
 * Section: 03
 * Date: 11/24/14
 * Collaboration Declaration: None
 * */
#include "HuffTree.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
using namespace std;

int main(int argc, char ** argv){
	char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	// 81 means 8.1% etc.
	int f[26] = { 81, 15, 28, 43, 128, 23, 20, 61, 71, 2, 1, 40, 24, 69, 76, 20, 1, 61, 64, 91, 28, 10, 24, 1, 20, 1 };
	// fill in below
	if (argc != 2) {//This error must be checked before inFile and outFile are created
		cout << "wrong number of arguments" << endl;//Number of arguments checked and is wrong
		return 0;
	}
	string inFName = argv[1];
	ifstream infile(inFName.c_str());
	string line;
	double sizeUncompressed = 0;
	double sizeCompressed = 0;
	HuffTree h;
	h.buildTree(letters, f, 26);
	while (getline(infile, line)) {
		for (int i = 0; line[i]; i++) {
			if (line[i] >= 'A' && line[i] <= 'Z')
				line[i] += 'a' - 'A';
			if (line[i] >= 'a' && line[i] <= 'z')
				sizeCompressed+=h.getCode(line[i]).length();
			else
				sizeCompressed+=8;
			sizeUncompressed+=8;
		}
		sizeUncompressed+=8;
		sizeCompressed+=8;
	}
	int compressionRate = 100 - sizeCompressed / sizeUncompressed * 100;
	cout << "original bits: " << sizeUncompressed << endl << "bits after compression:" << sizeCompressed << endl << "compression rate:" << compressionRate << "%" << endl;
	return 0;
}
