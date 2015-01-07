// test driver that uses Binary Search Tree insert
// You can use this driver to test your rotation methods


#include "map.h"
#include <iostream>

using namespace std;

int main(){
    int i;
    Map<int, string> t;
    
    i = 3;
    t.insert(i, "a");
    cout << "****insert " << i << "************************************" << endl;
    cout << t;
    
    i = 22;
    t.insert(i, "b");
    cout << "****insert " << i << "************************************" << endl;
    cout << t;
    
    i = 15;
    t.insert(i, "c");
    cout << "****insert " << i << "************************************" << endl;
    cout << t;

    i = 2;
    t.insert(i, "d");
    cout << "****insert " << i << "************************************" << endl;
    cout << t;
    
    i = 12;
    t.insert(i, "e");
    cout << "****insert " << i << "************************************" << endl;
    cout << t;
    
    i = 25;
    t.insert(i, "f");
    cout << "****insert " << i << "************************************" << endl;
    cout << t;

    cout << "****alter 25 ************************************" << endl;
	t[25] = "derrrrpppp";
    cout << t;

    cout << "****insert 7 ************************************" << endl;
	t[7] = "yep!";
    cout << t;

	cout << "***** iterator ************************************" << endl;
	Map<int, string>::Iterator it = t.find(5);
	for (int j = 0; j < 20; j++) {
		cout << it->key << endl;
		it++;
	}
}
