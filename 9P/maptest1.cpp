#include "map.h"
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    Map<string, string> m;
    string str;
    stringstream ss;
    int n = 200;
    for (int i=0; i<n; i++){
        ss << i << ' ';
        ss >> str;
        m[str] = str;
	m.insert(str, str);
    }

    for (int i=0; i<n; i++){
        str = "";
        ss << i << ' ';
        ss >> str;
        assert(m[str]==str);
    }
}
