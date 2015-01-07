/** CS515 Lab 4
 * File: queue.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 10/04/14
 * Collaboration Declaration: none
 * Lab  Partner: none 
 * Collaboration:  none
 * */
#include <iostream>
#include "stack.h"

using namespace std;

// assignment operator
// parameter:
//    rhs: the stack object to be assigned from 
// returns: a deep copy of the rhs stack object

stack::stack(int size)               // constructor with default value
{
	_tos = 0;
	_arr = new int[size];
	_capacity = size;
};
stack::stack(const stack& rhs){              // copy constructor
        if ( rhs._arr != 0 ){
            _capacity = rhs._capacity;
            _tos = rhs._tos;
            _arr = new int[_capacity];
            for ( int i=0; i<_tos; i++ )
                _arr[i] = rhs._arr[i];
        }
        else{
            _arr = 0;
            _tos = 0;
        }
};
stack::~stack(){};                        // destructor
void stack::print(std::ostream& os){ // print stack content to ostream
	for(int i = 0; i < _tos; i++)
		os << _arr[i] << ",";
	os << endl;
}
void stack::push(const int x){   // push an element
	_arr[_tos] = x;
	_tos++;
	if (_capacity == _tos)
	{
		_capacity = _capacity * 2;
		int _arrOld [_capacity];
		for (int i = 0; i < _tos; i++)
		{
			_arrOld[i] = _arr[i];
		}
		_arr = new int [_capacity];
		for (int i = 0; i < _tos; i++)
                {
                        _arr[i] = _arrOld[i];
                }
	}
};
void stack::pop(){         // remove and element,
	_tos--;
	if(_tos < 0)
		_tos = 0;
};
int& stack::top(){        // access next element without popping
	if(_tos == 0)
		return _arr[0];

	return _arr[_tos-1];
};
bool stack::empty(){       // test whether stack is empty
	if (_tos == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
};int  stack::size(){return _tos;};        // return the number of elements on stack
int  stack::capacity(){return _capacity;};    // return the current capacity of the stack

stack& stack::operator=(const stack& rhs) {
    if (this != &rhs){
        if ( rhs._arr != 0 ){
            _capacity = rhs._capacity;
            _tos = rhs._tos;
            delete [] _arr;
            _arr = new int[_capacity];
            for ( int i=0; i<_tos; i++ )
                _arr[i] = rhs._arr[i];
        }
        else{
            delete [] _arr;
            _arr = 0;
            _tos = 0;
        }
    }
    return *this;
}
