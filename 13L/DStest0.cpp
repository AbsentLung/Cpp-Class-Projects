/**	CS515 Lab 13
	File: DStest0.cpp
	Name: Joseph Bennett
	Section: 3
	Date: 12/03/14
	Collaboration Declaration: None
	Lab Partner: None
	Collaboration:None
*/

#include "DisjointSet.h"
#include <iostream>
#include <cassert>
using namespace std;

int main(){
    DisjointSet<int> s;

        s.createSet(1); //Create Sets
        s.createSet(3);
        s.createSet(5);
        s.createSet(6);
        s.createSet(9);

        s.unionSets(1, 6); //Join 1 and 6
        s.unionSets(3, 5); //Join 3 and 5
        s.unionSets(1, 5); //Join 1 and 5

    assert(s.findSet(1) == s.findSet(6)); // 1 and 6 are connected.
    assert(s.findSet(3) == s.findSet(6)); // 3 and 6 are connected.
    assert(s.findSet(1) == s.findSet(1)); // 1 and 1 are connected.
    assert(s.findSet(3) == s.findSet(5)); // 3 and 5 are connected.
    assert(s.findSet(3) != s.findSet(9)); // 3 and 9 are not connected.

}
