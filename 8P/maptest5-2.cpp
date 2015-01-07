#include "map.h"

#include <iostream>

using namespace std;
int main(){
	Map<int, int> m1;
	for (int i = 0; i < 100; i++)
	{
		m1.insert(i, i);
	}
	cout << "--------------- insert evens ---------------" << endl;
	cout << m1 << endl;

	//test left implementation
	Map<int, int> m2;
	m2.insert(25, 0);
	cout << "--------------- test _root ---------------" << endl;
	cout << m2 << endl;
	m2.insert(15, 0);
	m2.insert(35, 0);
	cout << "--------------- test BST insert ---------------" << endl;
	cout << m2 << endl;
	m2.insert(20, 0);
	cout << "--------------- test uncle and parent red ---------------" << endl;
	cout << m2 << endl;
	m2.insert(21, 0);

	cout << "--------------- test left rotate ---------------" << endl;
	cout << m2 << endl;
	m2.insert(22, 0);

	//test right implementation
	Map<int, int> m3;
	m3.insert(25, 0);
	cout << "--------------- test _root ---------------" << endl;
	cout << m3 << endl;
	m3.insert(15, 0);
	m3.insert(35, 0);
	cout << "--------------- test BST insert ---------------" << endl;
	cout << m3 << endl;
	m3.insert(30, 0);
	cout << "--------------- test uncle and parent red ---------------" << endl;
	cout << m3 << endl;
	m3.insert(29, 0);

	cout << "--------------- test left rotate ---------------" << endl;
	cout << m3 << endl;
	m3.insert(28, 0);

}