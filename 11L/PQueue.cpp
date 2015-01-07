/** CS515 Lab 11
 * File: PQueue.cpp
 * Name: Joseph Bennett
 * Section: 03
 * Date: 11/22/14
 * Collaboration Declaration: None
 * Lab Partner: None
 * Collaboration: None
 * */
using namespace std;

template<class T, int MAX_SIZE>
PQueue<T, MAX_SIZE>::PQueue() {
	buildHeap();
}

template<class T, int MAX_SIZE>
PQueue<T, MAX_SIZE>::PQueue(T* items, int size){
	_size = 0;
	for (int i = 0; i < size; i++)
		insert(items[i]);
}

template<class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::insert(T t) {
	_size++;
	_array[_size]=t;
	moveUp();
}

template<class T, int MAX_SIZE>
T PQueue<T, MAX_SIZE>::findMin() {
	return _array[1];
}

template<class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::deleteMin() {
	_array[1] = _array[_size];
	_size--;
	moveDown(1);
}

template<class T, int MAX_SIZE>
bool PQueue<T, MAX_SIZE>::isEmpty() {
	if (_size==0)
		return true;
	return false;
}

template<class T, int MAX_SIZE>
int PQueue<T, MAX_SIZE>::size() {
	return _size;
}

template<class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::buildHeap() {
	_size = 0;
}

template<class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::moveDown(int t) {
	T tmp=_array[t]; //Equal to the number percolating down
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

template<class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::moveUp() {
	int parent = _size/2;
	int node = _size;
	T temp;
	while (parent != 0 && _array[node] < _array[parent]) {
		temp = _array[parent];
		_array[parent] = _array[node];
		_array[node] = temp;
		node = parent;
		parent = node/2;
	}
}
