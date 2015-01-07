#include "HuffTree.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    HuffTree h;
    char c[11] = {'a', 'e', 'i', 's', 't', ' ', 'z', 'p', 'w', '\n', '*'};
    int f[11] = {10, 15, 12, 3, 4, 13, 1, 20, 2, 9, 15};
    h.buildTree(c,f,11);

    cout << h.getCode('a') << endl;
    cout << h.getCode('e') << endl;
    cout << h.getCode('i') << endl;
    cout << h.getCode('s') << endl;
    cout << h.getCode('t') << endl;
    cout << h.getCode(' ') << endl;
    cout << h.getCode('z') << endl;
    cout << h.getCode('p') << endl;
    cout << h.getCode('w') << endl;
    cout << h.getCode('\n') << endl;
    cout << h.getCode('*') << endl;

}

