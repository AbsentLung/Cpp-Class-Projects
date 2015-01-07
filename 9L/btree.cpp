/** CS515 Lab 9
 * File: btree.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 11/5/14
 * Collaboration Declaration: None
 * Lab Partner: None
 * Collaboration: None
 * */
#include "btree.h"

// helper method for tree display
void BTreeNode::indent(int depth){
    for(int i=0; i<depth; i++)
        cout << "\t";
}

BLeaf * BLeaf::insert(int &newKey, string item){
    // find position for insert into current node
    int pos=size-1;
    while (pos>=0 && newKey<keys[pos]) {
        keys[pos+1] = keys[pos];
        data[pos+1] = data[pos];
        pos--;
    }
    keys[pos+1] = newKey;
    data[pos+1] = item;
    size++;

    if(size <= MAX) // if curent leaf node does not overflow
        return 0;

    else { // need split
        // create new leaf
        BLeaf *sibling = new BLeaf();

        // copy upper half of the current node's elements over
        for(int i=0; i<(MAX+1)/2; i++){
            sibling->data[i] = data[i + (MAX+2)/2];
            sibling->keys[i] = keys[i + (MAX+2)/2];
        }

        // update size for both nodes
        sibling->size = (MAX+1)/2;
        size -= (MAX+1)/2;

        // send back new key by reference
        newKey = sibling->keys[0]; // sibling->keys[0] same as keys[(MAX+2)/2]

        // and return pointer to new node
        return sibling;
    }
}

void BLeaf::dump(int depth){
    indent(depth);
    int i;
    for(i = 0; i<size-1; i++)
        cout << keys[i] << ":" << data[i] << " ";
    cout << keys[i] << ":" << data[i] << endl;
}

BInternal * BInternal::insert(int &newKey, string item){
	int i = 0;
	while (i<size-1&&newKey>=keys[i+1]) //Search until the end is reached or the correct key is found
		i++;
	BTreeNode* split = child[i]->insert(newKey, item); //Call "insert" recursively on child nodes
	if (split){ //If there is a split, reassign all values that are shifted
		for (int j = size-1; j > i; j--) {
			child[j+1] = child[j];
			keys[j+1] = keys[j];
		}
		size++; //Increase size
		child[i+1] = split; //Inser Split
		keys[i+1] = newKey;
		if (size>MAX){ //If the size is greater than the maximum
			BInternal* newEle = new BInternal; //Create a new internal element
			newEle->keys[1] = keys[MAX+1/2]; //split between this and new
			for(int j = 0; j < MAX+1/2; j++) //For all elements up to the new element
				newEle->child[j] = child[MAX+1/2-1+j]; //Each element assigned as a child of the new element
			newEle->size = newEle->size+2; //The size of the new element is increased by two
			size -= 2; //The btree's size is decreased by two
			newKey = keys[MAX+1/2-1]; //The new key is equal to the new key
			return newEle;
		}
	}
	return 0;
}

void BInternal::dump(int depth){
    indent(depth);
    cout << "[";
    int i;
    for(i=1; i<size-1; i++) // keys[0] not displayed
        cout << keys[i] << ",";
    cout << keys[i] << "]" << endl;

    // call dump on all children
    for(int i=0; i<size; i++)
        child[i]->dump(depth+1);
}

void BTree::insert(int newKey, string item){
    BTreeNode *split = root->insert(newKey, item);
    if(split) {
        // splitting root; new root now has two children
        BInternal *newRoot = new BInternal();
        newRoot->child[0] = root;
        newRoot->child[1] = split;
        newRoot->keys[1] = newKey;
        newRoot->size = 2;
        root = newRoot;
    }
}
