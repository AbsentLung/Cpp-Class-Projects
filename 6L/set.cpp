/** CS515 Lab 6
 * File: set.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 10/14/14
 * Collaboration Declaration: none
 * Lab  Partner: none 
 * Collaboration: none
 * */
#include <iostream>
#include "set.h"

using namespace std;

Set::Set() {
	_size=0; //The initial size is 0
	_head= new Elem; //The head is equal to a new element
	_head->prev = 0; //There is nothing before the head
	_tail= new Elem; //The tail is equal to a new element
	_tail->next = 0; //There is nothing after the tail
	_head->next = _tail; //The head is immediately after the tail
	_tail->prev = _head; //The tail is immediately before the head
}

Set::Set(const Set& rhs) { //Copy constructor declared with the Set
	if(this != &rhs) { //If they're already equal then do nothing
		_size=0; //The initial size is 0
		_head= new Elem; //The head is equal to a new element
		_head->prev = 0; //There is nothing before the head
		_tail= new Elem; //The tail is equal to a new element
		_tail->next = 0; //There is nothing after the tail
		_head->next = _tail; //The head is immediately after the tail
		_tail->prev = _head; //The tail is immediately before the head
		Elem* el = rhs._head->next; //Set an element equal to the element after the head
		while(el != rhs._tail) { //Go through every element until the tail is reached
			insert(el->info); //Insert each element in copied set
			el = el->next;
		}
	}
}

Set::~Set() { //The destructor
	Elem *e;
	e = _head -> next; //Pointer points to the element after the head
	while(e != _tail) { //All elements up to the tail
		Elem* ele = e->next; //Assign to the next element
		delete e; //Delete the current element
		e = ele; //Assign the next element
	}
	delete _tail; //Delete the tail
	delete _head; //Delete the head
}

Set& Set::operator=(const Set& rhs) { //Make one Set equal to another Set
	Elem *e; //First all of the previous information is deleted
	e = _head -> next; //Pointer points to the element after the head
	while(e != _tail) { //All elements up to the tail
		Elem* ele = e->next; //Assign to the next element
		delete e; //Delete the current element
		e = ele; //Assign the next element
	}
	if(this != &rhs) { //If they're already equal then do nothing
		_size=0; //The initial size is 0
		_head->next = _tail; //The head is immediately after the tail
		_tail->prev = _head; //The tail is immediately before the head
		Elem* el = rhs._head->next; //Set an element equal to the element after the head
		while(el != rhs._tail) { //Go through every element until the tail is reached
			insert(el->info); //Insert each element in copied set
			el = el->next;
		}
	}
}

void Set::insert(ELEMENT_TYPE newInt){ //Insert a node
	Elem *nElem = new Elem; //New element
	Elem *e; //Element pointer
	nElem -> info = newInt; //Value of new element
	e = _head -> next; //Element begins to point to element after the head
	for( ; ;) { //Infinite loop
		if (e->info > newInt||e==_tail) { //If the current element is greater less than the value or the tail is reached
			e = e -> prev; //Element is equal to the previous element
			nElem->next = e -> next; //The element after the new element is the one after the current element
			nElem->next->prev = nElem; //The element before the element after the current element is the new element
			e -> next = nElem; //The element after the current element is the new element
			nElem -> prev = e; //The element before the new element is the previous element.
			_size++; //Increment the size
			break;
		}
		else if (e->info == newInt) { //If there is already an element of that value then nothing is inserted
			delete nElem;
			break;
		}
		e = e -> next; //Check the next node
	}
}

void Set::erase(ELEMENT_TYPE erased){ //Erase a node from the set
	Elem *e;
	e = _head -> next; //Start pointing at the first element after the head
	while(e != _tail) { //Loop until the tail is reached
		if (e -> info == erased) { //If element is the one to be erased
			e->prev->next = e->next; //Rearrange previous node's next node
			e->next->prev = e->prev; //and the next node's previous node to remove current node from list
			_size--; //Decrement the size
			delete e; //Delete the node
			break;
		}
		e = e->next; //Check the next node
	}
}

void Set::clear(){ //Clear all elements in the set
	Elem *e;
	e = _head -> next; //Start at the element after the head
	while(e != _tail) { //Loop until you reach the tail
		Elem* tmp = e->next; //Assign pointer to next element
		delete e; //Delete current element
		e = tmp; //Current element is the next element
	}
	_head->next = _tail; //The tail is after the head
	_tail->prev = _head; //The head is before the tail
	_size = 0; //The size is set to 0 because the set is empty
}

int Set::size() const { //Returns the size of a set
	return _size;
}

bool Set::find(ELEMENT_TYPE findThis) const { //Returns "True" if element is found, "False" otherwise
	Elem *e;
	e = _head -> next; //Pointer starts at element after head
	while(e != _tail) { //Search through all elements until the tail is reached
		if (e -> info == findThis) { //If element is found
			return true;
			break;
		}
		e = e->next; //Next element
	}
	return false;
}

ostream& Set::dumpOut(ostream& out, const Set &v) const{
	Elem *e;
	e = _head -> next; //Start with pointer pointing to the first element after the head
	while(e != _tail) { //Go through every element until the tail is reached
		out << e->info << " "; //Output the number of the current element
		e = e -> next; //Go to the next element
	}
	return out; //Return the output
}

ostream& operator<< (ostream& out, const Set& s){ //Operator for reading in the elements
	s.dumpOut(out, s);
}

bool Set::equals(const Set& s1, const Set& s2) const{
	if (s1._size!=s2._size)
		return false;
	Elem *e1; //One element pointer for each set
	Elem *e2;
	e1 = s1._head->next; //Start with each pointer pointing to the first element after the head
	e2 = s2._head->next;
	while(e1 != s1._tail) { //Go through every element until the tail is reached
		if (e1->info!=e2->info)
			return false;
		e1 = e1 -> next; //Go to the next element
		e2 = e2 -> next; //for each pointer
	}
	return true;
}

bool operator==(const Set& s1, const Set& s2){
	s1.equals(s1, s2);
}
