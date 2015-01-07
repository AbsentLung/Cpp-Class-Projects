// A generic Map implemented with Red-Black Tree
// The tree is right-threaded

#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <string>
#include <limits>
#include "set.h"
using namespace std;

template <typename KEY, typename T>
class Map{
private:
    struct Elem {
	Elem(){}
        Elem(KEY newKey, T newData, bool a = false) : key(newKey), data(newData), isActive(a){}

        KEY key;
        T data;
	bool isActive;
        
    };
    
    Elem ** array;  // pointers to table arrays
    int numOfTables;  // number of tables
    int tablesize;  // size of each table
    int entrysize;  // total number of elements in the hash table
    int findPos(KEY & x) const; // find the position of an element
    void rehash();  // increase the size of each table and rehash all element

public:
    class Iterator{
    public:
        Iterator(){}
        explicit Iterator(Elem *cur):_cur(cur) {}
        Elem& operator*();
        Elem* operator->();
        bool operator==(Iterator it);
        bool operator!=(Iterator it);
    private:
        Elem* _cur;
    };
    Iterator end() const;
    Set<KEY> allKeys;
    
    // constructs empty Map
    Map();
    
    // destructor
    ~Map();
    
    // insert an element into the Map; return true if successful
    bool insert(KEY&, T&);
    
    // return size of the Map
    int size() const;
    
    // return an iterator pointing to the end if an element is not found,
    // otherwise, return an iterator to the element
    Iterator find(KEY&) const;
    
    // overloaded subscript operator
    T& operator[](KEY&);
    
    // output elements
    //ostream& dump(ostream& out) const;

    bool remove(KEY&); // Remove an element

    unsigned int hash(KEY & key, int which);

};

//template<typename KEY, typename T>
//ostream& operator<< (ostream&, const Map<KEY, T>&);

bool isPrime(int n);

int nextPrime(int n);

#include "map.cpp"  // must include source file for template compilation
#endif
