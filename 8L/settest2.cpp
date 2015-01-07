#include "set.h"
#include <cassert>
#include <iostream>
#include <stdlib.h>
using namespace std;


int main(){
    Set s1;
    s1.insert(5);
    s1.insert(2);
    s1.insert(8);
    s1.insert(1);
    s1.insert(7);
    s1.insert(4);
    s1.insert(3);
    
    cout << s1; 
   
    s1.insert(6);
    
    cout << s1; 
   
    s1.insert(15);
    
    cout << s1; 
   
    s1.insert(9);
    
    cout << s1; 
   
    cout << "Depth First In Order Traverse: " << endl;
    s1.depthFirstInOrder();
    cout << "\nBreadth First Traverse: " << endl;
    s1.breadthFirst();
    cout << endl; 
}
