/*
 * CS515 Assignment 3
 * File: imagestackcpp
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
#include <algorithm>

using namespace std;

int main(int argc, char** argv){
	if (argc < 3) {//If wrong number of arguments
                cout << "User must provide at least 1 input file and the output file" << endl;
                exit(1);
    }
	int total=argc-2;//Initialize Variables
	int width;
	int height;
	int median;
	string line;
	ifstream imgs[total];
	ofstream backImg;
	backImg.open(argv[argc-1]);
	imgs[0].open(argv[2]);
    if (!imgs[0]) {//If file cannot be opened
                cout << "Can not open " << argv[2] << " for input" << endl;
                exit(1);
    }
	for (int i = 0; i < 3; i++) {
		getline(imgs[0], line);
		backImg << line << endl;//First 3 lines are the same for all images
		if (i==1) {
			stringstream s(line);
			s >> width;
			s >> height;
		}
	}
	for (int i = 1; i < total; i++) {//Each file after the first file
		imgs[i].open(argv[i+2]);//is opened
		imgs[i].seekg(0, imgs[0].cur);//is given the same position as the first file
		if (!imgs[i]) {//If file cannot be opened
					cout << "Can not open " << argv[i+2] << " for input" << endl;
					exit(1);
		}
	}
	int*** values = new int** [height];//3D array for the values
	for (int i = 0; i < height; i++) {
		values[i] = new int* [width];//Assign size of 2D arrays
		for (int j = 0; j < width; j++)
			values[i][j] = new int [total];//Assign size of each 1D array
	}
	for (int i = 0; i < total; i++) {//For each file
		int x=0;//Initialize height and width
		int y=0;
		while(y!=height&&getline(imgs[i], line)) {//If Y isn't greater than height and lines may be read in
			stringstream s(line);//Create stringstream of line
			while(y!=height&&s>>values[y][x][i])//If Y isn't greater than height and values remain in stringstream
				if (x!=width-1)//If width hasn't been reached
					x++;
				else {
					x=0;
					y++;//Next row
				}
		}
	}
	for (int i = 0; i < height; i++)//For each width and height
		for (int j = 0; j < width; j++) {
			sort(values[i][j], values[i][j]+total);//Sort the values for each file
			if (total%2==0) {//If even number
				median = values[i][j][total/2];//Pull middle value
				backImg << median << '\t';//Insert to output file
			}
			else {
				median = (values[i][j][total/2]+values[i][j][total/2+1])/2;//Create middle value
				backImg << median << '\t';//Insert to output file
			}
		}
	for (int i = 0; i < height; i++) {//Each pointer is deleted
		for (int j = 0; j < width; j++)
			delete[] values[i][j];
		delete[] values[i];
	}
	delete[] values;//The pointer to the pointers is deleted
	for (int i = 0; i < total; i++)//Close all input files
		imgs[i].close();
	backImg.close();//Close output
	return 0;
}
