/** CS515 Assignment 10
 * File: HuffTree.h
 * Name: Joseph Bennett
 * Section: 03
 * Date: 11/24/14
 * Collaboration Declaration: None
 * */

#ifndef HUFFTREE_H
#define HUFFTREE_H

#include <string>
using namespace std;

struct HuffNode{
    // default constructor
    HuffNode(HuffNode* l = 0, HuffNode* r = 0, int f = 0, char d = '\0')
        : left(l), right(r), freq(f), data(d){}
    HuffNode * left, * right;  // two child node
    unsigned int freq; // freqency of the node
    char data;  // char value for leaf nodes; '\0' for internal nodes
    string code;  // Huffman code for leaf nodes; not assigned for internal nodes
    
    // do not change above code
    // you may add below here

	HuffNode& operator=(HuffNode h) {
		this->data = h.data;
		this->freq = h.freq;
		this->left = h.left;
		this->right = h.right;
		this->code = h.code;
	}

	bool operator==(HuffNode h) {
		return this->freq == h.freq;
	}

	bool operator!=(HuffNode h) {
		return this->freq != h.freq;
	}

	bool operator<(HuffNode h) {
		return this->freq < h.freq;
	}

	bool operator>(HuffNode h) {
		return this->freq > h.freq;
	}

	bool operator<=(HuffNode h) {
		return this->freq <= h.freq;
	}

	bool operator>=(HuffNode h) {
		return this->freq >= h.freq;
	}

};

class HuffTree{
public:
    // get Huffman code and return it as a string
    string getCode(char);

    // build Huffman tree from an array of characters
    // and and an array of their corresponding freqencys;
    // the size of both arrays is given
    void buildTree(char * chs, int * freqs, int size);
    
private:
    HuffNode * _root; // root of the Huffman tree
   
    // do not change above code
    // you may add below here

	HuffNode* getCodeFull(char ch, HuffNode* h, string s);

};

#endif
