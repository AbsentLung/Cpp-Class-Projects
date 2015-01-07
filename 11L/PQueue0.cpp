/** CS515 Lab 11
 * File: PQueue0.cpp
 * Name: Joseph Bennett
 * Section: 03
 * Date: 11/22/14
 * Collaboration Declaration: None
 * Lab Partner: None
 * Collaboration: None
 * */
#include "PQueue0.h"
using namespace std;

PQueue::PQueue(){
	buildHeap();
}

PQueue::PQueue(int* items, int size){
	_size=0;
	for (int i = 0; i < size; i++)
		insert(items[i]);
}

void PQueue::insert(T t){
	_size++;
	_array[_size]=t;
	moveUp();
}

T PQueue::findMin(){
	return _array[1];
}

void PQueue::deleteMin(){
	_array[1] = _array[_size];
	_size--;
	moveDown(1);
}

bool PQueue::isEmpty(){
	if (_size==0)
		return true;
	return false;
}

int PQueue::size(){
	return _size;
}

void PQueue::buildHeap(){
	_size=0;
}

void PQueue::moveDown(int t){
	int tmp=_array[t]; //Equal to the number percolating down
	if (t*2<=_size && _array[t*2] <= _array[t*2+1] && _array[t] >= _array[t*2]) { //If left child is lesser
		_array[t] = _array[t*2]; //Swap current with left child
		_array[t*2] = tmp;
		moveDown(t*2); //Move down
	}
	else if (t*2+1 <= _size && _array[t] >= _array[t*2+1]){ //If right child is lesser
		_array[t] = _array[t*2+1]; //Swap current with right child
		_array[t*2+1] = tmp;
		moveDown(t*2+1); //Move down
	}
}

void PQueue::moveUp() {
	int n = _size;
	int p = _size/2;
	int tmp;
	while (p != 0 && _array[n] < _array[p]) {
		tmp = _array[p];
		_array[p] = _array[n];
		_array[n] = tmp;
		n = p;
		p = n/2;
	}
}
