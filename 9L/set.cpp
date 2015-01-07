/** CS515 Lab 9
 * File: set.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 11/5/14
 * Collaboration Declaration: None
 * Lab Partner: None
 * Collaboration: None
 * */
// Copyright 2013 KJ
// a set ADT implemented with an AVL tree
#include "set.h"

// default constructor
Set::Set():_root(0), _size(0){}

// common copy code for copying a tree recursively
Set::Elem* Set::copyCode(Elem *node){
    if (node)
        return new Elem(node->info, copyCode(node->left), copyCode(node->right), node->height);
    else
        return 0;
}

Set::Set(const Set& rhs){
    _root = copyCode(rhs._root);
}

// overloaded assignment opertor
Set& Set::operator=(const Set &rhs){
    if(this != &rhs){
        destructCode(_root);
        _root = copyCode(rhs._root);
    }
    return *this;
}

// common destruct code for deallocation and make an empty tree
void Set::destructCode(Elem *& node){
    if (node){
        destructCode(node->left);
        destructCode(node->right);
        delete node;
    }
    node = 0;
}

// destructor
Set::~Set(){
    destructCode(_root);
}

// return size of the set elements
int Set::size() const{
    return _size;
}

// insert an element
void Set::insert(ELEMENT_TYPE x) {
    insert(x, _root);
}

// helper method for recusively insertion
void Set::insert(ELEMENT_TYPE x, Elem *& node) {
    if (node == 0){ // insert here
        node = new Elem(x, 0, 0);
        _size++;
    }
    // move to left
    else if (x < node->info) {
        insert(x, node->left);
    }
    // move to right
    else if (x > node->info) {
        insert(x, node->right);
    }
    
    if (height(node->left) - height(node->right) == 2) { // calculate load factor
        if(x < node->left->info) // outside case
            rotateRight(node);
        else  // inside case
            doubleRotateRight(node);
    }
    
    if (height(node->left) - height(node->right) == -2) { // calculate load factor
        if (x > node->right->info) // outside case
            rotateLeft(node);
        else  // inside case
            doubleRotateLeft(node);
    }
    node->height = max(height(node->left), height(node->right)) + 1; // update height
}

// remove an element
void Set::erase(ELEMENT_TYPE x){
//    erase(x, _root);
}

// helper method for recusively removal
void Set::erase(ELEMENT_TYPE x, Elem *& node){
/*	if (!node) // If there isn't a node, do nothing
		return;
	if (x < node->info) //If the value is less than the node
		erase(x, node->left); //Recursively check the left node
	else if (x > node->info) //If the value is greater than the node
		erase(x, node->right); //Recursively check the right node
	else { //Otherwise, the value is correct so erase it
		Elem* temp = node; //Create a temporary element equal to the node
		if (node->right && !node->left) //If there is only a right child, node equals node to the right
			node = node->right;
		else if (!node->right && node->left) //If there is only a left child, assign node to that child
			node = node->left;
		else if (node->right && node->left) { //If there are two children
			Elem* temp2 = node->right; //Assign a temporary node to each element
			Elem* temp1 = node->left;
			while (temp1->right)
				temp1 = temp1->right;
			node = temp1;
			node->right = temp2;
		}
		delete temp;
		_size--;
	} */
}

// single right rotation
void Set::rotateRight(Elem *& node) {
	Elem* tmp = node; //Temporary element assigned to node
	int lvl = 0;
	while(tmp->right) { //Go to the rightmost node
		tmp = tmp->right;
		lvl++;
	}
	if (lvl != node->height) //If the level of the rightmost node isn't equal to the height
		node->height--; //Decrease the height
	tmp = node->left;
	node->left = tmp->right;
	tmp->right = node;
	node = tmp;
}

// single left rotation
void Set::rotateLeft(Elem *& node){
	Elem* tmp = node;
	int lvl = 0;
	while(tmp->left) {
		tmp = tmp->left;
		lvl++;
	}
	if (lvl != node->height)
		node->height--;
	tmp = node->right;
	node->right = tmp->left;
	tmp->left = node;
	node = tmp;
}

// double right rotation
void Set::doubleRotateRight(Elem *& node) {
	rotateLeft(node->left); //Left rotate the left node
	rotateRight(node); //Right rotate the current node
}

// double left rotation
void Set::doubleRotateLeft(Elem *& node) {
	rotateRight(node->right); //Right rotate the right node
	rotateLeft(node); //Left rotate the current node
}

// return the height of a node
int Set::height(Elem *node) {
    return node == 0 ? -1 : node->height;
}

// return the address of the minimum node in the tree
Set::Elem* Set::findMin(Elem *node) {
    if (node == 0)
        return node;
    while (node->left)  // move to the leftmost node
        node = node->left;
    return node;
}

// print tree "laying down"
void Set::printTree() {
    printTree(0, _root);
}

// output the structure of tree. The tree is output as "lying down"
// in which root is the LEFT most node.
void Set::printTree(int level, Elem *node) {
    int i;
    if (node) {
        printTree(level+1, node->right);
        for (i=0; i<level; i++)
            cout << "\t";
        cout << node->info << "(" << node->height << ")" << endl;
        printTree(level+1, node->left);
    }
}
