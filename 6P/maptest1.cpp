#include "map.h"
#include "set.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main(){
    Map<string, int> m1;
    cout << "\nMap test 1\n";
    assert( m1.insert("cute", 1) == true);
    assert( m1.insert("cool", 2) == true);
    assert( m1.insert("warm", 1) == true);
    assert( m1.insert("red", 2) == true);
    assert( m1.insert("cool", 1) == false);
    Map<string, int>::Iterator iter = m1.begin();
    cout << "here:" << iter->data << std::endl;
    m1["new"] = 999;
    m1["cool"] = 888;  // update entry indexed by "cool"
    cout << m1;
    m1.erase("red");
    cout << "\nafter erase\n";
    cout << m1;
    
    cout << "\nMap test 2\n";
    Map<string, Set<string> > m2;  // must have space between > > !!
    m2["Tonic"].insert("1.99");
    m2["grape"].insert("2.59");
    m2["cracker"].insert("2.99");
    m2["cracker"].insert("2.5");
    m2["grape"].insert("1.59");
    cout << m2;
    m2["grape"].insert("1.59");
    m2.erase("Tonic");
    cout << "\nafter erase\n";
    cout << m2;
    
    cout << "\nMap test 3\n";
    Map<string, Set<string> > m3[3];  // An array of Maps
    m3[0]["broccoli"].insert("3.29");
    m3[0]["cucumber"].insert("2.99");
    m3[1]["chocolate"].insert("4.99");
    m3[1]["brownie"].insert("2.99");
    m3[2]["pineapple"].insert("3.59");
    m3[2]["pineapple"].insert("2.59");
    m3[2]["starfruit"].insert("2.59");
    m3[2]["starfruit"].insert("4.59");
    
    for (int i=0; i<3; i++)
        cout << m3[i];
    
    Map<string, Set<string> >::Iterator it = m3[2].begin();
    while ( it != m3[2].end() ){
        cout << it->data << endl;
        it++;
    }

    
}
