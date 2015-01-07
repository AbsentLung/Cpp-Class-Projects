/*
 * CS515 Assignment 3
 * File: image.cpp
 * Name: Joseph Bennett
 * Section: 03
 * Date: 09/29/14
 * Collaboration Declaration:
 * Lab Partner: none
 * Collaboration: none
 */

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int grabInt(stringstream s) {
	int num;
	if (s>>num)
		return num;
	cout << "Bad Data" << endl;
	exit(1);
}

int main(int argc, char** argv){
    if (argc != 4){//If wrong number of arguments
		cout << "Usage: image <input image> <neg image> <rotate image>" << endl;
		exit(1);
    }
    ifstream inptImg(argv[1]);
    if (!inptImg){//If file cannot be opened
		cout << "Can not open " << argv[1] << " for input" << endl;
		exit(1);
    }
    ofstream negImg;//Declare variables
    ofstream rotImg;
    negImg.open(argv[2]);
    rotImg.open(argv[3]);
    string line;
    int num;
    int width;
    int height;
	int temp;
    int grayMax;
	getline(inptImg, line);//Get the first line
	negImg << line << endl;//First line is the same for the negative image
	rotImg << line << endl;//and the rotated image
	getline(inptImg, line);//Get the second line
	negImg << line << endl;//Second line is the same for the negative image
	stringstream s(line);
	s >> width;//First variable is the width
	s >> height;//Second variable is the height
	rotImg << height << "  " << width << endl;//Rotated image swaps the width and the height
	getline(inptImg, line);//Get the third line
	negImg << line << endl;//The third line is the same for the negative image
	rotImg << line << endl;//And the rotated image
	stringstream ss(line);
	ss >> grayMax;//Max grayscale
	int** values = new int* [height];//2D array for the values
	for (int i = 0; i < height; i++)
		values[i] = new int [width];//Assign size of array
	for (int i = 0; i < height; i++) {//For each value
		for (int j = 0; j < width; j++) {
			inptImg >> values[i][j];//Number in input is saved
			negImg << grayMax - values[i][j] << " ";//The opposite amount of gray
		}
		negImg << endl;//Next line
	}
	temp = width;//Replace width and height for rotated image
	width = height;
	height = temp;
	for (int i = 0; i < height; i++) {//For each value
		for (int j = 0; j < width; j++)
			rotImg << values[j][i] << " ";//Rows and columns are swapped then assigned
		rotImg << endl;//Next line
	}
	for (int i = 0; i < width; i++)//Each pointer is deleted
		delete[] values[i];
	delete[] values;//The pointer to the pointers is deleted
	inptImg.close();//Close all of the files
	negImg.close();
	rotImg.close();
	return 0;
}
