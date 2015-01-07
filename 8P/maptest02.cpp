// a simple test driver for testing insertion to Red Black tree


#include "map.h"

int main(){
    int i;
    Map<int, string> t;
    cout << t;
    
    i = 10;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 85;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 15;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;

    i = 70;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 20;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 60;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 30;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 50;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 65;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 80;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 90;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 40;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 5;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 55;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;

	cout << "***** iterator ************************************" << endl;
	Map<int, string>::Iterator it = t.find(5);
	for (int j = 0; j < 20; j++) {
		cout << it->key << endl;
		it++;
	}
}
