#include "HuffTree.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    HuffTree h;
    char c[13] = {'z', 'a', 'e', 'b', 'f', 'i', 's', 't', ' ', '\n', '*', '$', '?'};
    int f[13] = {2, 10, 15, 12, 9, 7, 3, 4, 13, 1, 20, 15, 25};
    h.buildTree(c,f,13);

    cout << h.getCode('z') << endl;
    cout << h.getCode('a') << endl;
    cout << h.getCode('e') << endl;
    cout << h.getCode('b') << endl;
    cout << h.getCode('f') << endl;
    cout << h.getCode('i') << endl;
    cout << h.getCode('s') << endl;
    cout << h.getCode('t') << endl;
    cout << h.getCode(' ') << endl;
    cout << h.getCode('\n') << endl;
    cout << h.getCode('*') << endl;
    cout << h.getCode('$') << endl;
    cout << h.getCode('?') << endl;
}

