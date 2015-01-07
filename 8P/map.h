// A generic Map implemented with Red-Black Tree
// The tree is right-threaded

#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <string>
#include <limits>
using namespace std;

template <typename KEY, typename T>
class Map{
private:
    struct Elem {
        Elem(){};
        Elem(KEY newKey, T newData) : key(newKey), data(newData){}

        KEY key;
        T data;
        
        bool red; // false if node is black
        Elem *left;
        Elem *right;
        Elem *parent;
        bool rightThread;  //true if node is right-threaded
    };
    
    Elem * _nil; // a dummy nil sentinel node
    Elem * _root;  // a dummy root sentinel node
    int _size;
    
    // helper method for print tree
    // tree is printed lying down; the red nodes are printed with a pair of brackets
    // root and nil sentinels are not printed.
    void printTree(ostream& out, int level, Elem *p) const;
    
    // common code for deallocation
    void destructCode(Elem *& p);

    // RB tree rotation code
    void rightrotate(Elem * node);
    void leftrotate(Elem * node);
    
public:
    class Iterator{
    public:
        Iterator(){}
        explicit Iterator(Elem *cur):_cur(cur) {}
        Elem& operator*();
        Elem* operator->();
        Iterator operator++(int);
        bool operator==(Iterator it);
        bool operator!=(Iterator it);
    private:
        Elem* _cur;
    };
    Iterator begin() const;
    Iterator end() const;
    
    // constructs empty Map
    Map();
    
    // copy constructor; not required
    Map(const Map &rhs);
    
    // destructor
    ~Map();
    
    // assignment operator; not required
    Map& operator=(const Map &rhs);
    
    // insert an element into the Map; return true if successful
    bool insert(KEY, T);
    
    // remove an element from the Map; return true if successful; not required
    bool erase(KEY);
    
    // return size of the Map
    int size() const;
    
    // return an iterator pointing to the end if an element is not found,
    // otherwise, return an iterator to the element
    Iterator find(KEY) const;
    
    // overloaded subscript operator
    T& operator[](KEY);
    
    // output elements
    ostream& dump(ostream& out) const;
};

template<typename KEY, typename T>
ostream& operator<< (ostream&, const Map<KEY, T>&);

#include "map.cpp"  // must include source file for template compilation
#endif
