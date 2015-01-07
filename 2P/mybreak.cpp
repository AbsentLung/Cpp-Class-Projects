/** CS515 Assignment 2
 * File: mybreak.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 9/15/13
 * Collaboration Declaration: No assistance recieved
 * */ 
//This program takes in an encrypted text and guesses the password
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

int main (int argc, char *argv[]) {
	ifstream inFile (argv[2]);//Initialize variables
	string line;
	string word;
	string wordCode="";
	char codeWord;
	int number = atoi(argv[1]);
	int letterCount;
	float total=0;
	float highestNumber=0;
	float W[number][26];//Each position in the passcode has an array of probabilities for the frequency in which each letter occurs
	float A[26] = {0.0821, 0.0150, 0.0230, 0.0479, 0.1237, 0.0225, 0.0208, //The rate at which a letter appears in the English language
			0.0645, 0.0676, 0.0018, 0.0087, 0.0393, 0.0254, 0.0705,
			0.0767, 0.0163, 0.0009, 0.0550, 0.0617, 0.0921, 0.0291,
			0.0087, 0.0254, 0.0013, 0.0195, 0.0006};
	float temp;
	while ( getline (inFile,line) ) {//Grab each line in the text
		stringstream ss(line);
		while (ss>>word){//Grab each word in the line
			for (int i=0;word[i];i++) {//Go through each character in the word
				W[letterCount%number][word[i]-97]++;//Increment the count of the letter in its position
				letterCount++;//Increment the count of the letters
			}
		}
	}
	for (int i = 0; i < number; i++) {//Create the probabilities and determine the best letter
		if (i<letterCount%number) {//Determining the amount of times that the letter in the codeword is used
			for(int j = 0; j < 26; j++)
				W[i][j]=W[i][j]/(letterCount/number);
		}
		else {
			for(int j = 0; j < 26; j++)
				W[i][j]=W[i][j]/(letterCount/number+1);
		}
		highestNumber=0;
		for(int j = 0; j < 26; j++) {//Get a dot product from each variation of A and assign the position in the code
			total=0;
			for(int k = 0; k < 26; k++)
				total+=W[i][k]*A[j];
			if(total>highestNumber) {
				highestNumber=total;
				codeWord=j+97;
				cerr << "Most likely letter for position " << i << " is " << codeWord << endl;
			}
		}
		temp=A[25];
		for(int j = 24; j >= 0; j--)//Shift the A array
			A[j+1]=A[j];
		A[0]=temp;
		wordCode+=codeWord;
	}
	cout << wordCode << endl;
	inFile.close();
	return 0;
}
