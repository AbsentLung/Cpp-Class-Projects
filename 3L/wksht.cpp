/* CS515 Assignment 1
File: calgrade.cpp
Name: Joseph Bennett
Section: 
Date: 09/11/14
Collaboration Declaration: My brain
*/
#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
using namespace std;

//Problem 4 cont......
char* f(char * str){//Cannot modify constant character
	for(int i = 0; str[i]; i++)
		str[i] = toupper(str[i]); // change to upper case
	return str;
}

int main(){
/*	//Problem 1.........
	string s1, *s2[2];//3.  There is a stack-based string created then 2 string pointers.
	string *s3 = new string("abc");//2.  The pointer is created and points to a new stack-based string "abc"
	string *s4 = new string[5];//6.  The pointer is created and points to the start of a new stack-based array of 5 strings
	string &s5 = s4[4];//1.  s5 is created and the address of s5 is equal to the address of s4's fourth string.

	//Problem 2........
	int D1=1, D2=3, D3=3;
	string thrD[D1][D2][D3];
	for(int i = 0; i < D1; i++)
		for(int j = 0; j < D2; j++)
			for(int k = 0; k < D3; k++)
				thrD[i][j][k]=0;
	//Problem 3.......
	 
		1) A "const" reference variable is already in memory and does not need to be compiled.  This makes things more efficient.
		2) A "const" cannot be changed so we don't have to worry about a glitch in which it does get changed.
	*/

	//Problem 4........
	char str[6] = "hello";//"char str[5]" creates 4 characters rather than 5;
	cout << f(str);
	return 0;
	/*
	practice.cpp: In function ‘char* f(const char*)’:
	practice.cpp:17:10: error: assignment of read-only location ‘*(str + ((sizetype)i))’
	   str[i] = toupper(str[i]); // change to upper case
		  ^
	practice.cpp:18:9: error: invalid conversion from ‘const char*’ to ‘char*’ [-fpermissive]
	  return str;
		 ^
	practice.cpp: In function ‘int main()’:
	practice.cpp:38:16: error: initializer-string for array of chars is too long [-fpermissive]
	  char str[5] = "hello";
			^
	*/
}

