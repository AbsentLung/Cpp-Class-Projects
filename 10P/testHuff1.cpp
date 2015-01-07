#include "HuffTree.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    HuffTree h;
    char c[6] = {'s', 'f', 'd', 'a', 'g', 'e'};
    int f[6] = {12, 4, 2, 3, 1, 25};
    
    h.buildTree(c,f,6);

    cout << h.getCode('s') << endl;
    cout << h.getCode('f') << endl;
    cout << h.getCode('d') << endl;
    cout << h.getCode('a') << endl;
    cout << h.getCode('g') << endl;
    cout << h.getCode('e') << endl;
    
}

