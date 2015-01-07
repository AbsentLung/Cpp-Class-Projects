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

stack::stack(int cap) { //Constructor declared with the capacity
	_capacity = cap; //The capacity is equal to the capacity
	_arr = new int[_capacity]; //The array is equal to a new integer array the size of the capacity
	_tos = 0;//Top of stack initially set to zero
};

stack::stack(const stack& stk) { //Copy constructor declared with the stack
	if ( stk._arr == 0 ) { //If empty
		_arr = 0; //Top of the array is zero
		_tos = 0; //Top of the stack is zero
	}
	else { //Otherwise
		_capacity = stk._capacity; //Capacity is the same
		_tos = stk._tos; //Top of stack is the same
		_arr = new int[_capacity]; //New array with the same size
		for ( int i=0; i<_tos; i++ ) //For each item
			_arr[i] = stk._arr[i]; //The values are copied
	}
};

stack::~stack() { //The destructor
	delete [] _arr; //Delete the pointer array
};

void stack::push(const int x) { //Pushes an element of value "x" into the stack
	_arr[_tos] = x; //Assign element to the top of the stack
	_tos++; //Increment the top of the stack
	if (_capacity == _tos) { //if the capacity is equal to the top of the stack
		_capacity = _capacity * 2; //The capacity doubles
		int temp [_capacity]; //An temp version of the array is created
		for (int i = 0; i < _tos; i++)
			temp[i] = _arr[i];
		delete [] _arr;
		_arr = new int [_capacity]; //The array is recreated with the new size
		for (int i = 0; i < _tos; i++) //Old values are re-inserted
			_arr[i] = temp[i];
	}
};

void stack::pop() { //Pop a value out of the stack
	if(_tos != 0) //If the top of the stack is not equal to zero
		_tos--; //Decrement the size of the top of the stack
};

int& stack::top() { //Returns the value at the top of the stack
	if(_tos == 0) //If the top value is zero then return 0
		return _arr[0];
	return _arr[_tos-1]; //Otherwise just return whatever value is at the top
};

bool stack::empty() { //Return a boolean indicating whether the stack is empty
	if (_tos == 0) //If top of stack is zero
		return true;
	else
		return false;
};

int  stack::size() { //Return the number of elements on stack
	return _tos;
};

int  stack::capacity(){ //Return the current capacity of the stack
	return _capacity;
};

stack& stack::operator=(const stack& stk) { //Make one stack equal to another stack
	if (this != &stk) { //If they aren't already equal
		if (stk._arr == 0) { //If array is empty
			delete [] _arr; //Delete array
			_arr = 0; 
			_tos = 0; //Top of stack is equal to zero
		}
		else { //Otherwise
			_capacity = stk._capacity; //Capacity is the same
			_tos = stk._tos; //Top of stack is the same
			delete [] _arr; //Delete array
			_arr = new int[_capacity]; //Array has new capacity
			for ( int i=0; i<_tos; i++ ) //Every value is copied
				_arr[i] = stk._arr[i];
		}
	}
	return *this; //Return new stack
}
