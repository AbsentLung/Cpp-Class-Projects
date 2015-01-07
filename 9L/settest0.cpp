#include <iostream>
#include <cstdlib>
#include <cassert>
#include "set.h"
using namespace std;

int main(){
    Set t;
    int numbers[] = {50, 25, 75, 10, 30, 60, 80, 5, 15, 27, 55, 1};
    // try a sorted set of numbers and see the results
    // int numbers[] = {1, 5, 10, 15, 25, 27, 30, 50, 55, 60, 75, 80};     
    
    int size = 12;
    // try to insert a sorted set of numbers   
    for(int i = 0; i < size; i++){
        t.insert( numbers[i]);
        assert(t.size() == i+1); 
        t.printTree();
        cout << "************************************" << endl;
    }
    
    t.insert(80); // re-insert 80
    assert(t.size() == 12);
    t.printTree();
    cout << "************************************" << endl;
}
