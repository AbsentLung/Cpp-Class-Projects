/**
 * CS515 Lab 8
 * File: set.cpp
 * Name: Joseph Bennett
 * Section: 03
 * Date: 10/18/13
 * Collaboration Declaration:
 * Lab Partner:	none
 * Collaboration: Hardly any help.  The "specialist" from the PAC told me to use wikipedia and had no clue.
 * 	I also didn't even have a lab because there are no classes friday. (I am unhappy with this)
 */

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
	delete p;
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

void Set::depthFirstInOrder(){
	Elem* p = _root;
	while (p != 0)
	{
		while (p->left != 0)
			p = p->left;
		cout << p->info << " ";
		if (!p->rightThread)
			p = p->right;
		else
		{
			do
			{
				p = p->right;
				if (p->right != 0)
					cout << p->info << " ";
			}
			while (p != 0 && p->rightThread);
			if (p != 0)
				p = p->right;
		}
	}
}

void Set::breadthFirst()
{
    queue<Elem*> q;
    q.push(_root);
    while (!q.empty()) {
	const Elem * const p = q.front();
	if (p->left == _root || p->right == _root)
		break;
	if (p->left) {
		q.push(p->left);
		cout << p->left->info << " ";
		q.pop();
	}
	if (p->right) {
		q.push(p->right);
		cout << p->right->info << " ";
		q.pop();
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

