/** CS515 Assignment 6
 * File: map.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 10/27/14
 * Collaboration Declaration: none
 * Lab  Partner: none 
 * Collaboration: none
 * */

using namespace std;

template<typename KEY, typename T>
Map<KEY,T>::Map(){
        _size=0; //The initial size is 0
        _head= new Elem; //The head is equal to a new element
        _head->prev = 0; //There is nothing before the head
        _tail= new Elem; //The tail is equal to a new element
        _tail->next = 0; //There is nothing after the tail
        _head->next = _tail; //The head is immediately after the tail
        _tail->prev = _head; //The tail is immediately before the head
}

template<typename KEY, typename T>
Map<KEY,T>::Map(const Map &v){
    copyCode(v);
}

template< typename KEY, typename T>
Map<KEY,T>::~Map(){
    destructCode();
}

template<typename KEY, typename T>
Map<KEY,T>& Map<KEY,T>::operator=(const Map<KEY,T> &rhs){
    if (this != &rhs) { //If it isn't already the same
        destructCode(); //Destroy the previous information
        copyCode(rhs); //Copy information over
    }
    return *this;
}

template<typename KEY, typename T>
bool Map<KEY,T>::insert(KEY x,T value){
	if(find(x) == end()) { //If the value found is the last value
		Elem *p = new Elem; //New element created
		p->data = value; //Data is equal to data inserted
		p->key = x; //Data is equal to data inserted
		Elem *cur = _head->next; //The current element is equal to the node after the head
		while(cur != _tail){ //While the current node isn't equal to the tail
			if (cur->key > x) //If the current key is greater than the first value inserted
				break; //Break
			cur = cur->next; //Go to the next node
		} //Then a new node is inserted
		p->next = cur; //Next value is the current
		p->prev = cur->prev; //The previous of the current is the previous of the if the new node
		cur->prev->next = p; //Previous is the new node
		cur->prev = p;
		_size++; //Increment size
		return true; //Insertion worked, return true
	}
	return false; //Insertion failed, return false
}

template<typename KEY, typename T>
typename Map<KEY,T>::Iterator Map<KEY,T>::find(KEY value) const{
	Elem *e = _head -> next; //Pointer starts at Elem after _head
	while(e != _tail) { //Search through all Elems until _tail is reached
		if (e -> key == value) //If Elem is found
			return Iterator(e);
		e = e->next; //Next element
	}
	return Iterator(_tail); //Return an iterator starting at the current element
}

template <typename KEY, typename T>
bool Map<KEY,T>::erase(KEY value){
	Elem *e = _head -> next; //Start pointing at the first element after the head
	while(e != _tail) { //Loop until the tail is reached
		if (e -> key == value) { //If element is the one to be erased
			e->prev->next = e->next; //Rearrange previous node's next node
			e->next->prev = e->prev; //and the next node's previous node to remove current node from list
			_size--; //Decrement the size
			delete e; //Delete the node
			return true;
		}
		e = e->next; //Check the next node
	}
	return false;
}

template<typename KEY, typename T>
void Map<KEY,T>::clear(){
    Elem *e;
    while (_head->next != _tail) { //Loop until head reaches the tail
        e = _head->next; //Current element is the one after the head
        _head->next = e->next; //Head is pushed to the next element
        e->next->prev = _head;
        delete e; //Delete the current element
    }
}

template<typename KEY, typename T>
void Map<KEY,T>::copyCode(const Map<KEY,T> &v) {
    _head = new Elem; //Create Head
    _tail = new Elem; //Create Tail
    _tail->next = 0; //Null after the tail
    _head->prev = 0; //Null before the head
    _head->next = _tail; //Tail after the head
    _tail->prev = _head; //Head before the tail
    Elem *e = v._tail->prev; //Current node immediately before tail
    _size = v._size; //The size is copied
    while (e != v._head) { //While the current element isn't at the head
        insert(e->data); //Insert each piece of data
        e = e->prev; //Go to the previous element
    }
}

template<typename KEY, typename T>
void Map<KEY,T>::destructCode(){
	Elem *e;
	while (_head != _tail) { //Loop until the head equals the tail
		e = _head;
		_head = _head->next;
		delete e; //Delete each element
	}
	delete _head; //Then delete the head
    _size = 0; //Size of the map is set back to zero
}

template<typename KEY, typename T>
ostream& Map<KEY,T>::dump(ostream& out, const Map<KEY,T> &v) const{
	Elem *e = v._head->next; //Start with pointer pointing to the first element after the head
	while (e != v._tail) { //Go through every element until the tail is reached
		out << e->key << " " << e->data << endl; //Output the number of the current element
		e = e->next; //Go to the next element
	}
	return out; //Return the output
}

template<typename KEY, typename T>
ostream& operator<< (ostream& out, const Map<KEY,T> &v){
	return v.dump(out, v); //Generate from dump method and return
}

template<typename KEY,typename T>
T& Map<KEY,T>::operator[](KEY k){
	Elem* e1 = _head->next; //Temporary element assigned to node after the head
	while (e1!=_tail) { //While the element is not equal to the tail
		if (e1->key == k) //If the key is found
			return e1->data; //Return the data at that key
		e1 = e1->next; //Go to the next element
	}
	e1 = _head->next; //e1 is set back to the element after the head
	Elem* e2 = new Elem; //The key hasn't been found, new element is created
	e2->key = k; //Key of new element is the element sought
	while (e1!=_tail) {
		if (k<e1->key) //When the key is found that is of lesser value than the value sought
			break;
		e1 = e1->next; //Go to the next element
	}
	e2->prev = e1->prev; //The element with the new key is placed properly
	e2->next = e1;
	e1->prev->next = e2;
	e1->prev = e2;
	_size++; //Increase the size of the map
	return e2->data; //Return the element of the new data
}
