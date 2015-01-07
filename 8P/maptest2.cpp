#include "map.h"
#include <cassert>
using namespace std;

int main(){
    Map<int, int> m;
    int i;
    
    i = 1;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    i = 5;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;

    i = 55;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    i = 58;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    i = 60;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    i = 20;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
     cout << m;
    
    
    i = 35;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;

    i = 40;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;

    i = 45;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    i = 48;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    i = 22;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    i = 25;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    i = 30;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;

    
    i = 50;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    
    i = 62;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    i = 7;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    i = 15;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    assert(m.size() == 17);
    
    
   
    /*
    cout << m[5] << endl;
    m[5] = 5;
    cout << m[5] << endl;
    
    i = 30;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    m[20] = 2;
    cout << m;
     */
    
}