/** CS515 Lab 8
 * File: set.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 11/1/14
 * Collaboration Declaration: None
 * Lab Partner: None
 * Collaboration: None
 * */
#include "set.h"

Set::Set():_size(0){
    // create a dummy root node
    _root = new Elem;
    _root->info = numeric_limits<int>::max();
    _root->left = _root;  // empty tree
    _root->right = 0;
    _root->rightThread = false;
}

Set::~Set(){
    if (_root->left != _root)  // not an empty tree
        destructCode(_root->left);
    delete _root;
}

void Set::destructCode(Elem *& p){
	if (p->left) //If there's a left child
		destructCode(p->left);
	if (p->right&&!p->rightThread) //If there's a right child
		destructCode(p->right);
	delete p; //Delete the node
}


// returns true if the new node is inserted, otherwise false
bool Set::insert(ELEMENT_TYPE v){
    if (insert(_root->left, v, _root)){
        _size++;
        return true;
    }
    return false;
}

// insert helper method
// returns true if the new node is inserted, otherwise false
bool Set::insert(Elem *&cur, const ELEMENT_TYPE &value, Elem *lastLeft){
    if (cur == _root || cur == 0) {
        cur = new Elem;
        cur->info = value;
        cur->left = 0;
        cur->right = lastLeft;
        cur->rightThread = true;
        return true;
    }
    
    if (value == cur->info){
        return false;
    }
    // insert at left
    if (value < cur->info)
        return insert( cur->left, value, cur);
    
    // insert at right
    if (!cur->rightThread){
        return insert(cur->right, value, lastLeft);
    } else {  // current's right is a thread; add a new node
        cur->rightThread = false;
        cur->right = new Elem;
        cur->right->info = value;
        cur->right->left = 0;
        cur->right->right = lastLeft;
        cur->right->rightThread = true;
        return true;
    }
}

// print out tree elements in depth first in order
void Set::depthFirstInOrder(){
	Elem* cur = _root->left; //Start with the first node
	while (cur->left) //Go to the leftmost node
		cur=cur->left;
	cout << cur->info << ' '; //Print it
	while (cur->right!=_root) { //While it isn't the last node
		if (cur->rightThread) { //If the node has a right parent
			cur=cur->right; //Select the right parent
			cout << cur->info << ' '; //Print it out
		}
		else {
			cur=cur->right; //Otherwise go to the right child
			while (cur->left) //Go to the leftmost node
				cur=cur->left;
			cout << cur->info << ' '; //Print it out
		}
	}
}

void Set::breadthFirst(){
	queue<Elem*> q; //Create a queue
	q.push(_root); //Insert the root
	Elem *e; //Create a node
	while (!q.empty()) { //While the queue isn't empty
		e = q.front(); //The element is at the front of the queue
		q.pop(); //Erase the value at the bottom of the queue
		if (e->left) { //If there is an element on the left
			q.push(e->left); //Push it onto the queue
			cout << e->left->info << " "; //Read it out
		}
		if (e->right&&!e->rightThread) { //If there is a right child
			q.push(e->right); //Push it onto the queue
			cout << e->right->info << " "; //Read it out
		}
	}
}

int Set::size() const{
    return _size;
}

// output the structure of tree. The tree is output as "lying down"
// in which _root is the LEFT most Elem.
void Set::printTree(ostream& out, int level, Elem *p){
    int i;
    if (p) {
        if (p->right && !p->rightThread)
            printTree(out, level+1,p->right);
        for(i=0;i<level;i++)
            out << "\t";
        out << p->info << '\n';
        printTree(out, level+1,p->left);
    }
}

// outputs information in tree in inorder traversal order
ostream& Set::dump(ostream &out){
    if ( _root == _root->left) // tree empty
        return out;
    printTree(out, 0, _root->left);   // print tree structure
}


// outputs using overloaded << operator
ostream& operator << (ostream &s, Set &v){
    v.dump(s);
    return s;
}

