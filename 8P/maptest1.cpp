#include "map.h"
#include <cassert>
using namespace std;

int main(){
    Map<int, int> m;
    int i;
    
    i = 1;
    m.insert(i, 1);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    i = 5;
    m.insert(i, 5);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    i = 7;
    m.insert(i, 7);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    i = 11;
    m.insert(i, 11);
    cout << "****insert " << i << "************************************" << endl;
    cout << m;
    
    assert(m.size() == 4);
    
    Map<int, int>::Iterator iter;
    iter = m.find(1);
    assert(iter != m.end());
    assert(iter->key == 1);
    assert(iter->data == 1);
    
    iter = m.find(5);
    assert(iter != m.end());
    assert(iter->key == 5);
    assert(iter->data == 5);
    
    iter = m.find(7);
    assert(iter != m.end());
    assert(iter->key == 7);
    assert(iter->data == 7);
    
    iter = m.find(11);
    assert(iter != m.end());
    assert(iter->key == 11);
    assert(iter->data == 11);
}