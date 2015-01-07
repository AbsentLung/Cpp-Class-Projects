/** CS515 Assignment 10
 * File: PQueue.cpp
 * Name: Joseph Bennett
 * Section: 03
 * Date: 11/24/14
 * Collaboration Declaration: None
 * */
using namespace std;

template<class T, int MAX_SIZE>
PQueue<T, MAX_SIZE>::PQueue() {
	buildHeap(); //Simply just build the heap
}

template<class T, int MAX_SIZE>
PQueue<T, MAX_SIZE>::PQueue(T* items, int size){ //Alternative constructor
	buildHeap(); //Build the heap
	for (int i = 0; i < size; i++) //Insert a list of nodes
		insert(items[i]);
}

template<class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::insert(T t) {
	_size++; //Increase the size
	_array[_size]=t; //New node starts at the highest value
	moveUp(); //Move up the tree until placed properly
}

template<class T, int MAX_SIZE>
T PQueue<T, MAX_SIZE>::findMin() {
	return _array[1]; //Grab the minimum value
}

template<class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::deleteMin() {
	_array[1] = _array[_size]; //Greatest value is now the smallest
	_size--; //Decrease the size
	moveDown(1); //Percolate down the greatest value
}

template<class T, int MAX_SIZE>
bool PQueue<T, MAX_SIZE>::isEmpty() {
	if (_size==0) //If the size is zero
		return true; //The PQueue is empty
	return false; //Otherwise it is not
}

template<class T, int MAX_SIZE>
int PQueue<T, MAX_SIZE>::size() {
	return _size; //Return the size of the PQueue
}

template<class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::buildHeap() {
	_array[0] = 0; //Root node is null
	_size = 0; //The size starts at zero
}

template<class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::moveDown(int t) {
	int down = t; //The node percolating down
	int leftChild = t*2; //The left child
	int rightChild = t*2 + 1; //The right child
	while(leftChild <= _size && (*_array[down] >= *_array[rightChild] || *_array[down] >= *_array[leftChild])) { 
		T temp = _array[down]; //Temporarilty assign the node going down
		if(*_array[leftChild] <= *_array[rightChild]) { //If the left child is less than or of equal value to the right child
			_array[down] = _array[leftChild];
			_array[leftChild] = temp;
			down = leftChild; //The node going down has changed value
		}
		else { //Otherwise the left child is swapped
			_array[down] = _array[rightChild]; //Swap the right child with the current
			_array[rightChild] = temp;
			down = rightChild; //The node going down has changed value
		}
		leftChild = down * 2; //Left child is reassigned
		rightChild = down * 2 + 1; //Right child is reassigned
	}
}

template<class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::moveUp() {
	int height = _size; //Assign the height
	T temp; //Create a temporary value for the node
	while (height > 1 && *_array[height/2] > *_array[height]) { //If the new node has not yet been placed properly
		temp = _array[height/2]; //Swap the node with its parent
		_array[height/2] = _array[height];
		_array[height] = temp;
		height = height/2; //Height of the node has changed
	}
}
