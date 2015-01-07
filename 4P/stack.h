/** CS515 Assignment 4
 * File: stack.h
 * Name: Joseph Bennett
 * Section: 3
 * Date: 10/09/14
 * Collaboration Declaration: none
 * Lab  Partner: none 
 * Collaboration:  none
 * */
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
using namespace std;

#define INITCAP 8
#define TYPE string

class FullStackException{};
class EmptyStackException{};

class stack{
public:
    TYPE * _arr;     // pointer to dynamic integer array
    int _tos;       // index to top of stack

    // constructor with default capacity value
    stack(int=INITCAP);
    
    // copy constructor
    stack(const stack&);
    
    // assignment operator
    stack& operator=(const stack&);
    
    // destructor
    ~stack();
    
    // push an element;
    // if fixed sized stack, throw FullStackException when stack is full
    void push(const TYPE x);
    
    // remove and element; throw EmptyStackException when stack is empty
    void pop();
    
    // return a reference to the top element without popping; throw EmptyStackException when stack is empty
    TYPE& top();
    
    // return true if the stack is empty, false otherwise
    bool empty();
    
    // return the number of elements currently on the stack
    int  size();
    
    // return the current capacity of the stack
    int  capacity();

    // print stack content to ostream
    void print(std::ostream& os);
    
private:
    int _capacity;  // current capacity 
};
 
