#include "map.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    Map<string, string> m;
    bool yesNo = m.erase("");
    if (yesNo)
	cout << "yes" << endl;
    else
	cout << "no" << endl;
}
