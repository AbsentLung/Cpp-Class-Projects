#include "set.h"
#include <cassert>
#include <iostream>
#include <stdlib.h>
using namespace std;


int main(){
    Set s1;
    srand ( time(NULL) );
    for (int i = 0; i < 20; i++)
	    s1.insert(rand() % 100 + 1);
    
    //assert(s1.size()==8);
    cout << s1; 
   
    cout << "Depth First In Order Traverse: " << endl;
    s1.depthFirstInOrder();
    cout << "\nBreadth First Traverse: " << endl;
    s1.breadthFirst();
    cout << endl; 
}
