/** CS515 Lab 15
 * File: floyd.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 12/2/13
 * Collaboration Declaration:
 * Partner: none
 * Collaboration: none
 */

#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void printOut(int d, int n, vector<vector<int> > v)
{
	cerr<<"D"<<d<<":"<<endl<<endl;
	for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cerr << v[i][j] << '\t';
			cerr << endl;
		}
	cerr << endl;
}

int main(){
	string line;
	getline(cin, line);
	stringstream s(line);
	int t;
	int n;
	s >> n;
	vector<vector<int> > v(20, vector<int>(20,999));
	for (int a = 0; a < n; a++)
	{
		getline(cin, line);
		stringstream s(line);
		for (int b = 0; b < n; b++)
		{
			s>>v[a][b];
		}
	}
	int k;
	for (k=0;k<n;k++)
	{
		printOut(k, n, v);
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if(v[i][j]>(v[i][k]+v[k][j]))
					v[i][j]=(v[i][k]+v[k][j]);
			}
		}
	}
	printOut(k, n, v);
	return 0;
}
