/** CS515 Assignment 10
 * File: HuffTree.cpp
 * Name: Joseph Bennett
 * Section: 03
 * Date: 11/24/14
 * Collaboration Declaration: None
 * */

#include "HuffTree.h"
#include "PQueue.h"
#include <string>

void HuffTree::buildTree(char * chs, int * freqs, int size) {
	HuffNode* leftHuff; //Assign Variables
	HuffNode* rightHuff;
	HuffNode* h;
	PQueue<HuffNode*, 10000> q; //Size is made very large just in case
	for(int i = 0; i < size; i++) { //Insert every node in no particular order
		h = new HuffNode(0, 0, freqs[i], chs[i]);
		q.insert(h);
	}
	for (; q.size()>1; size++) { //Sort every node as a tree
		rightHuff = q.findMin();
		q.deleteMin();
		leftHuff = q.findMin();
		q.deleteMin();
		h = new HuffNode(rightHuff, leftHuff, rightHuff->freq+leftHuff->freq, '\0');
		q.insert(h);
	}
	HuffNode root = q.findMin(); //Assign the root node
	_root = &root;
}

string HuffTree::getCode(char ch) {
	HuffNode* n = getCodeFull(ch, _root->left, ""); //More properties are needed to call recursively so I made another function
	return n->code;
}

HuffNode* HuffTree::getCodeFull(char ch, HuffNode* h, string str) {
	if (!h) //If the node doesn't exist then return null
		return 0;
	if (ch==h->data) { //If the character matches
		h->code = str; //Assign the code
		return h; //Return the node
	}
	HuffNode* tmp = getCodeFull(ch, h->left, str + "0"); //Add a 0 to the code
	if (tmp == 0) //If the code is already assigned
		return getCodeFull(ch, h->right, str + "1"); //Add a 1 to the code instead
	return tmp;
}
