/** CS515 Assignment 5
 * File: skiplist.h
 * Name: Joseph Bennett
 * Section: 3
 * Date: 10/10/14
 * Collaboration Declaration: none
 * Lab  Partner: none 
 * Collaboration:  none
 * */

//  the SkipList class manages insertion, erase and find; it has two sentinal nodes (head and tail).

#ifndef SKIP_LIST
#define SKIP_LIST
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>
using namespace std; 

typedef int ELEMENT_TYPE;  // key is int type

class SkipList{
	public:
		SkipList(int, float = 0.5);
		SkipList(const SkipList&);
		~SkipList();
		bool insert(ELEMENT_TYPE);
		bool erase(ELEMENT_TYPE);
		bool find(ELEMENT_TYPE);
		SkipList& operator=(const SkipList&);
		void output(); 
	private:
		struct SkipNode{
			SkipNode(ELEMENT_TYPE, int);
			~SkipNode();
			SkipNode** nextNodes;
			int height;
			ELEMENT_TYPE info;
		};
		friend ostream& operator<< (ostream&, const SkipList&);  
		SkipNode * _head, * _tail;
		float _probability;
		int _maxHeight, _curHeight;
		int randomLevel();
		void copyCode(const SkipList&);
		void destructCode();
		ostream& dumpOut(ostream&, const SkipList&) const;
};

#endif //SKIP_LIST

