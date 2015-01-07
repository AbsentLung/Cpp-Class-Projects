/** CS515 Assignment 8
 * File: map.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 11/10/14
 * Collaboration Declaration: none
 * Lab  Partner: none 
 * Collaboration: none
 * */
// A generic Map implemented with right-threaded Red-Black Tree

template <typename KEY, typename T>
Map<KEY, T>::Map(){
    _nil = new Elem;
    _nil->left = _nil->right = _nil->parent = _nil;
    _nil->key = numeric_limits<int>::min(); // minimum int value
    _nil->red = false;
    
    _root = new Elem;
    _root->parent = _root->left = _root->right = _nil;
    _root->key = numeric_limits<int>::max(); // maximum int value
    _root->red = false;
    _size = 0;
}


template <typename KEY, typename T>
int Map<KEY, T>::size() const{
    return _size;
}


// private helper method to output the structure of tree.
// tree is printed lying down; the red nodes are printed with a pair of brackets
// root and nil sentinels are not printed.
template <typename KEY, typename T>
void Map<KEY, T>::printTree(ostream& out, int level, Elem *p) const{
    int i;
    if ( p != _nil && p != _root ) { // for empty tree
         if(!p->rightThread){  // for non right threaded node
            printTree(out, level+1, p->right);
         }
        for( i=0; i<level; i++ )
            out << "\t";
        if ( p->red )
            //out << "(" << p->key << ":" << p->data << ":" << p->parent->key << ")\n";
            out << "(" << p->key << ":" << p->data << ")\n";
        else
            //out << p->key << ":" << p->data << ":" << p->parent->key << '\n';
            out << p->key << ":" << p->data << '\n';
        printTree(out, level+1, p->left);
    }
}

// outputs elements
template <typename KEY, typename T>
ostream& Map<KEY, T>::dump(ostream& out) const{
    if ( _root == _root->left) {// tree empty
        return out;
    }
    printTree(out, 0, _root->left);   // print tree structure
    return out;
}


// outputs using overloaded << operator
template<typename KEY, typename T>
ostream& operator<< (ostream& out, const Map<KEY, T>& v){
    v.dump(out);
    return out;
}


//---------------------- Do not make edits above ------------------------

// copy constructor
template<typename KEY, typename T>
Map<KEY, T>::Map(const Map& rhs) {
	//Not required
}

// destructor
template<typename KEY, typename T>
Map<KEY, T>::~Map() {
	if (_root->left != _nil)  // not an empty tree
		destructCode(_root->left);
	delete _root;
	delete _nil;
}


// left rotation on node
template<typename KEY, typename T>
void Map<KEY, T>::leftrotate(Elem * node) {
	Elem* e = node->right; //Element assigned to the right child
	node->right = e->left; //Swap the right node with the right node's left node
	if(e->left != _nil) //If the right node has a left child
		e->left->parent = node; //The element's left child's parent is now the node
	e->parent = node->parent; //The element's parent is now the node's parent
	if(node->parent==_nil) //If the node doesn't have any parents
		_root = e; //The root is equal to the element
	else //Otherwise
		if(node == node->parent->left) //If the node is a left child
			node->parent->left = e; //Apply the correct properties
		else //Same if the node is a right child
			node->parent->right = e;
	e->left = node; //The node's old right child is now the parent
	node->parent = e;
}

// right rotation on node
template<typename KEY, typename T>
void Map<KEY, T>::rightrotate(Elem * node) {
	Elem* e = node->left; //Element assigned to the left child
	node->left=e->right; //Swap the left child with the left child's right child
	if(e->right != _nil) //If the left child's right child isn't null
		e->right->parent = node; //The left child's right child's parent is the node
	e->parent = node->parent; //The left child's parent is now the node's parent
	if(node->parent==_nil) //If the node's parent is null
		_root = e; //The root is equal to the left child
	else //Otherwise
		if(node == node->parent->right) //If the node is a right child
			node->parent->right = e; //The node's old left child is adopted by the node's old parent as right child
		else //Otherwise
			node->parent->left = e; //The node's old left child is adopted by the node's old parent as left child
	e->right = node; //The node's old left child is now the left parent of the node
	node->parent = e;
}

// inert a new key into the Red Black Tree
// if key already exist no operation is done
template<typename KEY, typename T>
bool Map<KEY, T>::insert(KEY k, T t){
	Elem* tmp = _root->left; //Temporary element starts left of the root
    Elem * par = _root; //Create a pointer to an element to keep track of the current position
    Elem * e = new Elem(k, t); //First element is left of the root
    e->key = k; //Inserted node is always red
    e->data = t; //Inserted node is always red
    e->left = _nil; //Null child to the left
    e->right = _nil; //Null child to the right
    e->red = true; //Inserted node is always red
	while (tmp!=_nil) { //While the key is not equal to zero
		par = tmp;
		if (k < tmp->key) //If the key inserted is of lesser value than the current key
			tmp = tmp->left; //Traverse left
		else if (k > tmp->key) //If the key inserted is of greater value than the current key
			tmp = tmp->right; //Traverse right
		else { //If it is of the same value then exit because a duplicate cannot be created
			delete e;
			return false;
		}
	}
	tmp = e;
	e->parent=par;
	if (k < par->key) //If the key inserted is less than the parent
		par->left = e; //Element is the left child of the parent
	else //Otherwise
		par->right = e; //Element is right child of the parent
	Elem* uncle;
	while(e!=_root->left&&e->parent->red) { //While there is a red parent and the element isn't equal to the root
		if(e->parent==e->parent->parent->left) { //If the parent is the left child of the grandparent
			uncle = e->parent->parent->right; //The uncle if the right child of the grandparent
			if (uncle->red) { //If the uncle is red
				e->parent->parent->red = true; //Change color
				e->parent->red = false;
				uncle->red = false;
				e = e->parent->parent; //Grandparent is the focus
			}
			else { //If uncle is black
				if (e == e->parent->right) { //If element is the right child
					e = e->parent; //The focus is on the parent
					leftrotate(e); //Left rotate
				}
				e->parent->red=false; //Parent is black
				e->parent->parent->red=true; //Grandparent is red
				rightrotate(e->parent->parent); //Right rotate the grandparent
			}
		}
		else { //If the parent is the right child of the grandparent
			uncle = e->parent->parent->left; //The uncle is the left child of the grandparent
			if (uncle->red) { //If uncle is red
				e->parent->parent->red = true; //Change color
				e->parent->red = false;
				uncle->red = false;
				e = e->parent->parent; //Grandparent is the focus
			}
			else { //If uncle is black
				if (e == e->parent->left) { //If element is a left child
					e = e->parent; //The focus is on the parent
					rightrotate(e); //Right rotate
				}
				e->parent->red=false; //Parent is black
				e->parent->parent->red=true; //Grandparent is red
				leftrotate(e->parent->parent); //Left rotate
			}
		}
    }
    _root->left->red=false; //The first element is always black
	_size++;
	return true; //Insertion complete, return true
}

// destructor code for deallocation
template<typename KEY, typename T>
void Map<KEY, T>::destructCode(Elem *& p){
	if (p->left != _nil)
		destructCode(p->left);
	if (p->right != _nil)
		destructCode(p->right);
	delete p;
}

template<typename KEY, typename T>
bool Map<KEY, T>::erase(KEY k) {
	//Not required
}

template<typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::find(KEY k) const{
	Elem * e = _root->left; //First element is left of the root
	while (e!=_nil) { //While the key is not equal to zero
		if (k < e->key) //If the key inserted is of lesser value than the current key
			e = e->left; //Traverse left
		else if (k > e->key) //If the key inserted is of greater value than the current key
			e = e->right; //Traverse right
		else //If it is of the same value then the key is found.  Return iterator at that element
			return Iterator(e);
	}
	return Iterator(_nil); //Element isn't found, return null
}

template<typename KEY, typename T>
T& Map<KEY, T>::operator[](KEY k) {
	T t;
	insert(k, t); //Insert the key
	Iterator it=find(k);
	return it->data; //Return the data at the element
}

template<typename KEY, typename T>
Map<KEY, T>& Map<KEY, T>::operator=(const Map& rhs) {
	//Not Required
}

template<typename KEY, typename T>
typename Map<KEY, T>::Elem& Map<KEY, T>::Iterator::operator*() {
	return *_cur;
}

template<typename KEY, typename T>
typename Map<KEY, T>::Elem* Map<KEY, T>::Iterator::operator->() {
	return _cur;
}

template<typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::Iterator::operator++(int) {
	if (_cur==_cur->right) {} //If _nil then return _nil
	else if (_cur->right!=_cur->right->left) { //If it has a right child
		_cur=_cur->right; //Move to the right
		while (_cur->left!=_cur->left->left) //Go to leftmost element
			_cur=_cur->left;
	}
	else { //If element is a left child with no right children
		while(_cur == _cur->parent->right) //While the current node is right child
			_cur=_cur->parent; //Become the parent
		if (_cur->parent->parent==_cur->parent->right) { //If the current element is the root
			_cur=_cur->parent->parent;
		}
		else
			_cur=_cur->parent; //Next parent will have a key of greater value
	}
	return Iterator(_cur); //Return the current element
}

template<typename KEY, typename T>
bool Map<KEY, T>::Iterator::operator==(Map<KEY, T>::Iterator it) {
	return _cur==it._cur;
}

template<typename KEY, typename T>
bool Map<KEY, T>::Iterator::operator!=(Map<KEY, T>::Iterator it) {
	return _cur!=it._cur;
}

template<typename KEY, typename T>
typename Map<KEY,T>::Iterator Map<KEY,T>::begin() const {
        if (_root->left==_root) //If tree is empty
                return Iterator(_nil); //newEdit
        Elem* e = _root;
        while (e->left!=_nil)
		e = e->left;
        return Iterator(e);
}

template<typename KEY, typename T>
typename Map<KEY,T>::Iterator Map<KEY,T>::end() const {
	return Iterator(_nil);
}
