// a simple test driver for testing insertion to Red Black tree


#include "map.h"

int main(){
    int i;
    Map<int, string> t;
    cout << t;
    
    i = 3;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    cout << "****insert " << i << "************************************" << endl;
    if(t.insert(i, "ele"))
	cout << t;
    else
	cout<<"duplicate insertion" <<endl;

    i = 22;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 15;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;

    i = 2;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 12;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 8;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 9;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 14;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 6;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 21;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 19;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 10;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 31;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;
    
    i = 4;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;

    i = 7;
    cout << "****insert " << i << "************************************" << endl;
    t.insert(i, "ele");
    cout << t;

	cout << "***** iterator ************************************" << endl;
	Map<int, string>::Iterator it = t.find(7);
	for (int j = 0; j < 20; j++) {
		cout << it->key << endl;
		it++;
	}
}
