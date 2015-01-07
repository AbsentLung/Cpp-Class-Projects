/** CS515 Assignment 7
 * File: map.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 11/3/14
 * Collaboration Declaration: none
 * Lab  Partner: none 
 * Collaboration: none
 * */

#include<queue>
using namespace std;

template<typename KEY, typename T>
Map<KEY,T>::Map(){
	_size=0; //The initial size is 0
	_root = new Elem;
	_root->left = _root;  // empty tree
	_root->right = 0;
	_root->rightThread = false;
}

template<typename KEY, typename T>
Map<KEY,T>::Map(const Map &v){
	_root = new Elem;
	_root->left = _root;  // empty tree
	_root->right = 0;
	_root->rightThread = false;
	_size = 0; //The size is zero
	if (v._root->left!=v._root) { //Copy everything breadth-first
		queue<Elem*> q; //Create a queue
		q.push(v._root); //Insert the root
		Elem *e; //Create a node
		while (!q.empty()) { //While the queue isn't empty
			e = q.front(); //The element is at the front of the queue
			q.pop(); //Erase the value at the bottom of the queue
			if (e->left) { //If there is an element on the left
				q.push(e->left); //Push it onto the queue
				insert(e->left->key, e->left->data); //Insert the node
			}
			if (e->right&&!e->rightThread) { //If there is a right child
				q.push(e->right); //Push it onto the queue
				insert(e->right->key, e->right->data); //Insert the node
			}
		}
	}
}

template< typename KEY, typename T>
Map<KEY,T>::~Map(){
	destructCode(_root);
}

template<typename KEY, typename T>
Map<KEY,T>& Map<KEY,T>::operator=(const Map<KEY,T> &rhs){
	if (this != &rhs) { //If it isn't already the same
		destructCode(_root); //Destroy the previous information
		_root = new Elem;
		_root->left = _root;  // empty tree
		_root->right = 0;
		_root->rightThread = false;
		_size=0;
		if (rhs._root->left!=rhs._root) { //Copy everything breadth-first
			queue<Elem*> q; //Create a queue
			q.push(rhs._root); //Insert the root
			Elem *e; //Create a node
			while (!q.empty()) { //While the queue isn't empty
				e = q.front(); //The element is at the front of the queue
				q.pop(); //Erase the value at the bottom of the queue
				if (e->left) { //If there is an element on the left
					q.push(e->left); //Push it onto the queue
					insert(e->left->key, e->left->data); //Insert the node
				}
				if (e->right&&!e->rightThread) { //If there is a right child
					q.push(e->right); //Push it onto the queue
					insert(e->right->key, e->right->data); //Insert the node
				}
			}
		}
	}
	return *this;
}

template<typename KEY, typename T>
bool Map<KEY,T>::insert(KEY x,T value){
	if (insert(_root->left, x, value, _root)){ //If the data can be inserted
		_size++; //Increment the size
		return true; //Return true
	}
	return false; //If data cannot be inserted then return false
}

template<typename KEY, typename T>
bool Map<KEY,T>::insert(Elem *& root, const KEY &key, const T &data, Elem *lastLeft){
	if (root == _root || root == 0) { //If the current element is the root or null
		root = new Elem; //Create a new element with the appropriate values
		root->key = key;
		root->data = data;
		root->left = 0;
		root->right = lastLeft;
		root->rightThread = true;
		return true;
	}
	if (key == root->key) //If the value is equal to the current value
		return false;
	if (key < root->key) //Insert left
		return insert( root->left, key, data, root);
	if (!root->rightThread){ //Insert right
		return insert(root->right, key, data, lastLeft);
	} else {  // current's right is a thread; add a new node
		root->rightThread = false;
		root->right = new Elem;
		root->right->key = key;
		root->right->data = data;
		root->right->left = 0;
		root->right->right = lastLeft;
		root->right->rightThread = true;
		return true;
	}
}

template<typename KEY, typename T>
typename Map<KEY,T>::Iterator Map<KEY,T>::find(KEY value) const{
/*	queue<Elem*> q; //Create a queue
	q.push(_root); //Insert the root
	Elem *e; //Create a node
	while (!q.empty()) { //While the queue isn't empty
		e = q.front(); //The element is at the front of the queue
		if (e->key==value) //If value is found
			return Iterator(e); //Return the value
		q.pop(); //Erase the value at the bottom of the queue
		if (e->left&&e->left!=_root) //If there is an element on the left
			q.push(e->left); //Push it onto the queue
		if (e->right&&!e->rightThread) //If there is a right child
			q.push(e->right); //Push it onto the queue
	}
	return Iterator(end()); //If the element isn't found through breadth-first traverse.*/
	Elem *e=_root->left; //Create a node
	while (e->right!=_root) { //Search until the root is found
		if (e->key==value) //If the current element matches the key
			return Iterator(e); //Return the value
		else if (e->key>value&&e->left) //If the current element is greater than the key
			e = e->left;
		else if (!e->rightThread) //Current element is lesser, move right
			e=e->right;
		else //Value cannot be found
			return Iterator(end());
	}
}

template<typename KEY, typename T>
typename Map<KEY,T>::Elem& Map<KEY,T>::Iterator::operator*(){
	return *_cur;
}

template<typename KEY, typename T>
typename Map<KEY,T>::Elem* Map<KEY,T>::Iterator::operator->(){
	return _cur;
}

template<typename KEY, typename T>
typename Map<KEY,T>::Iterator Map<KEY,T>::Iterator::operator++(int){
	Iterator res = *this; _cur = _cur->right; return res;
};

template<typename KEY, typename T>
bool Map<KEY,T>::Iterator::operator==(Iterator it){
	return _cur == it._cur;
}

template<typename KEY, typename T>
bool Map<KEY,T>::Iterator::operator!=(Iterator it){
	return _cur != it._cur;
}

template<typename KEY, typename T>
typename Map<KEY,T>::Iterator Map<KEY,T>::begin() const {
	Elem* e = _root;
	while (e->left)
		e = e->left;
	return Iterator(e);
}

template<typename KEY, typename T>
typename Map<KEY,T>::Iterator Map<KEY,T>::end() const {
	Elem *e = _root;
	while (e->left)
		e = e->left;
	while (e!=_root)
		e = e->right;
	return Iterator(e);
}

template <typename KEY, typename T>
bool Map<KEY,T>::erase(KEY value){
	Elem *e=_root->left; //Create a node
	//if (e->key==value) { //If the current element matches the key
	//Elem *oldE=_root; //Create a node
	//Elem *goldE; //Create a node
	while (e->right!=_root) { //Search until the root is found
		//goldE = oldE;
		//oldE = e;
		if (e->key==value) { //If the current element matches the key
			//if (e->left&&!e->rightThread) { //If node has 2 children
				Map<KEY,T> m; //Create a map and insert all nodes aside from the current
				queue<Elem*> q; //Create a queue
				q.push(_root); //Insert the root
				Elem *e2; //Create a node
				while (!q.empty()) { //While the queue isn't empty
					e2 = q.front(); //The element is at the front of the queue
					q.pop(); //Erase the value at the bottom of the queue
					if (e2->left) { //If there is an element on the left
						q.push(e2->left); //Push it onto the queue
						if (e2->left!=e)
							m.insert(e2->left->key, e2->left->data); //Insert the node
					}
					if (e2->right&&!e2->rightThread) { //If there is a right child
						q.push(e2->right); //Push it onto the queue
						if (e2->right!=e)
							m.insert(e2->right->key, e2->right->data); //Insert the node
					}
				}
				destructCode(_root);
				_size=0; //The initial size is 0
				_root = new Elem;
				_root->left = _root;  // empty tree
				_root->right = 0;
				_root->rightThread = false;
				q.push(m._root);
				while (!q.empty()) { //While the queue isn't empty
					e2 = q.front(); //The element is at the front of the queue
					q.pop(); //Erase the value at the bottom of the queue
					if (e2->left) { //If there is an element on the left
						q.push(e2->left); //Push it onto the queue
						insert(e2->left->key, e2->left->data); //Insert the node
					}
					if (e2->right&&!e2->rightThread) { //If there is a right child
						q.push(e2->right); //Push it onto the queue
						insert(e2->right->key, e2->right->data); //Insert the node
					}
				}
				return true;
			//}
		}
		else if (e->key>value&&e->left) //If the current element is greater than the key
			e = e->left;
		else if (!e->rightThread) //Current element is lesser, move right
			e = e->right;
		else //Value cannot be found
			return false;
			/*else if (e->left) { //If node has only left child
				if (e==oldE->left) { //If its parent is right
					oldE->left = e->left;
					if (e->left->rightThread) //If rightThread
						e->left->right=oldE; //Right thread is now parent
				}
				else { //If its parent is left
					oldE->right=e->left;
					if (e->left->rightThread) //If rightThread
						e->left->right=goldE; //Right thread is grandparent
				}
				_size--;
				delete e;
			}
			else if (!e->rightThread) { //If node has only right child
				if (e==oldE->left) { //If its parent is right
					oldE->left = e->right;
					if (e->right->rightThread) //If rightThread
						e->right->right=oldE; //Right thread is now parent
				}
				else //If its parent is left
					oldE->right=e->right;
				_size--;
				delete e;
			}
			else { //If node has no children
				if (e==oldE->right) { //If parent came from the left
					oldE->rightThread=true;
					oldE->right=e->right;
				}
				else //If parent came from the right
					oldE->left=0;
				_size--;
				delete e;
			}*/
	}
}

template<typename KEY, typename T>
void Map<KEY,T>::destructCode(Elem *& p){ //Delete all of the nodes breadth-first
	if (p->left&&p->left!=_root) //If there's a left child
		destructCode(p->left);
	if (p->right&&!p->rightThread) //If there's a right child
		destructCode(p->right);
	_size=0;
	delete p; //Delete the node
}

template<typename KEY, typename T>
void Map<KEY, T>::printTree(ostream& out, int level, Elem *p) const{
	int i;
	if (p) {
		if (p->right && !p->rightThread)
			printTree(out, level+1,p->right);
		for(i=0;i<level;i++)
			out << "\t";
		out << p->key << " " << p->data << '\n';
		printTree(out, level+1,p->left);
	}
}

template<typename KEY, typename T>
ostream& Map<KEY,T>::dump(ostream& out) const{
	if (_root == _root->left) // tree empty
		return out;
	printTree(out, 0, _root->left);   // print tree structure
}

template<typename KEY, typename T>
ostream& operator<< (ostream& out, const Map<KEY,T> &v){
	v.dump(out);
	return out;
}

template<typename KEY,typename T>
T& Map<KEY,T>::operator[](KEY k){
	Elem *e; //Create a node
	if (_root->left==_root) { //If tree is empty
		e = new Elem;
		_root->left=e;
		e->key=k;
		e->right=_root;
		e->rightThread=true;
		return e->data;
	}
	e = _root->left;
	while (e->right!=_root) { //Search until the root is found
		if (e->key==k) //If the current element matches the key
			return e->data; //Return the value
		else if (e->key>k) { //If the current element is greater than the key
			if (e->left)
				e = e->left;
			else { //New element becomes left child
				Elem *newE = new Elem; //Create new element
				newE->key=k;
				newE->left=0;
				newE->right=e;
				newE->rightThread=true;
				e->left=newE;
				return newE->data;
			}
		}
		else if (e->rightThread) { //New element becomes current's right child
			Elem *newE = new Elem; //Create new element
			newE->key=k;
			newE->left=0;
			newE->right=e->right;
			newE->rightThread=true;
			e->rightThread=false;
			e->right=newE;
			return newE->data;
		}
		else //It's greater, move past
			e=e->right;
	}
	Elem *newE = new Elem; //Create new element
	newE->key=k;
	newE->left=0;
	e->rightThread=false; //If not found yet, element must be of greatest value
	e->right=newE;
	newE->rightThread=true;
	newE->right=_root;
	return newE->data;
}
