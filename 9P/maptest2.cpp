#include "map.h"

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#define SIZE 1000

using namespace std;

int main(){
	Map<string, int> m1;
	string str;
	for (int i = 0; i < SIZE; i++)
	{
		stringstream ss;
		ss << i << ' ';
        ss >> str;
        m1.insert(str, i);
		assert(m1[str] == i);
	}

	/*Test the following:
		-size()
		-find()
		-end()
	*/
	assert(m1.size() == SIZE);
	for (int i = 0; i < m1.size(); i++)
	{
		stringstream ss;
		ss << i << ' ';
        ss >> str;
		assert(m1.find(str) != m1.end());
	}
	
	/*Test the following:
		- different template types
	*/
	Map<string, double> m2;
	for (int i = 0; i < 1000; i++)
	{
		stringstream ss;
		ss << i << ' ';
        ss >> str;
        double db = i;
		m2.insert(str, db);
		assert(m2[str] == db);
	}
}