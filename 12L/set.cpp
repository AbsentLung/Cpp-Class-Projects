/** Lab 12
 * File: set.cpp
 * Name: Joseph Bennett
 * Section: 03
 * Date: 11/29/14
 * Collaboration Declaration: None
 * Lab Partner: None
 * Collaboration: None
 * */

#include "set.h"

Set::Set() {
	_root = new TrieNode;
	_size = 0;
}

bool Set::insert(string str) {
	TrieNode* cur = _root;
	for (int i = 0; str[i]; i++) {
		if (str[i]>='A' && str[i]<='Z')
			str[i] += 'a' - 'A';
		if (!cur->child[str[i]-'a'])
			cur->child[str[i] - 'a'] = new TrieNode;
		cur = cur->child[str[i] - 'a'];
	}
	if (!cur->isWord) {
		cur->isWord = true;
		_size++; //Increase the size
		return true;
	}
	return false;
}

bool Set::erase(string str) {
	TrieNode* cur = _root;
	for (int i = 0; str[i]; i++) {
		if (str[i]>='A' && str[i]<='Z')
			str[i] += 'a' - 'A';
		if (!cur->child[str[i]-'a'])
			cur->child[str[i] - 'a'] = new TrieNode;
		cur = cur->child[str[i] - 'a'];
	}
	if (cur->isWord) {
		cur->isWord = false;
		_size--; //Decrease the size
		return true;
	}
	return false;
}

bool Set::find(string str) {
	TrieNode* cur = _root;
	for (int i = 0; str[i]; i++) {
		if (str[i]>='A' && str[i]<='Z')
			str[i] += 'a' - 'A';
		if (!cur->child[str[i]-'a'])
			cur->child[str[i] - 'a'] = new TrieNode;
		cur = cur->child[str[i] - 'a'];
	}
	if (cur->isWord) {
		return true;
	}
	return false;
}

int Set::size() {
	return _size; //Return the size of the PQueue
}
