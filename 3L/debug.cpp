/**
CS515 Lab 3
File: debug.cpp
Name: Joseph Bennett
Section: 3
Date: 09/25/14
Collaboration Declaration: none
Lab  Partner:  none
Collaboration:  none
*/ 
#include <iostream>
#include <cstdlib>
using namespace std;

int* initArray(int);
int fillArray(int *, int);
int* doubleArray(int *, int);
void displayArray(int *, int);

/* The program will create an array of given size
 * populate the array with random number from (0-99)
 * and display the array; then the program will double
 * the size of the array, repopulate the array and 
 * display it again.
 */


int main(int argc, char ** argv){
    if (argc != 2){
        cout << "wrong number of arguments" << endl;
        exit(1);
    }
    
    int n = atoi(argv[1]); // get size
    srand(time(0));
    
    // create initial array and display it
    int* ptr = initArray(n);
    fillArray(ptr, n);
    displayArray(ptr, n);
    
    // create the double sized array and display it
    ptr = doubleArray(ptr, n);//ptr is equal to the returned value
    fillArray(ptr, 2*n);
    displayArray(ptr, 2*n);
    delete []ptr;//Delete the ptr array
}

// Create an array of size n and return its address
int* initArray(int n){
    int *ptr = new int[n];//An array of integers the size of 'n' is returned.  "arr" is deleted because it isn't used
    return ptr;
}

// Fill array ptr with n random numbers
int fillArray(int *ptr, int n){
    for(int i=0; i<n; i++){
        ptr[i] = rand() % 100;
    }
}

// Double the size of the array, make sure no memory leak
int* doubleArray(int *ptr, int n){
    delete []ptr;//Delete pointer array rather than just the pointer 
    int size = 2*n;
    int * tmp = new int[size];
    ptr = tmp;
    return ptr;//tmp is used and should not be deleted
}

// Display n array elements
void displayArray(int *ptr, int n){
    for(int i=0; i<n; i++){
        cout << ptr[i] << " ";
    }
    cout << endl;
}
