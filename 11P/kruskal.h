/**	CS515 Assignment 11
	File: kruskal.h
	Name: Joseph Bennett
	Section: 3
	Date: 12/03/14
	Collaboration Declaration: None
*/

#include "DisjointSet.h"
#include <list>
#include <string>
#include <sstream>
#include <iostream>

struct forestNode{
	bool visited; //Whether or not the forest node has been visited
	bool operator==(const forestNode& rhs) const { //== operator
		return this->value == rhs.value;
	}
	string value; //The value of the forest node
};

struct edge{
	forestNode n1; //Node 1
	forestNode n2; //Node 2
	int weight; //Weight of the edge
	bool operator<(const edge& rhs) const { //Assignment operators
		return this->weight < rhs.weight;
	}
	bool operator<=(const edge& rhs) const {
		return this->weight <= rhs.weight;
	}
	bool operator>(const edge& rhs) const {
		return this->weight > rhs.weight;
	}
	bool operator>=(const edge& rhs) const {
		return this->weight >= rhs.weight;
	}
	bool operator==(const edge& rhs) const {
		return this->weight == rhs.weight;
	}
	bool operator!=(const edge& rhs) const {
		return this->weight != rhs.weight;
	}
};

class forest{
private:
	bool started; //Whether or not the printing has started
	list<forestNode> forestNodes; //List that contains every forest node
	list<edge> edges; //List that contains all of the edges
	list<edge> safeEdges; //List that contains all of the safe edges
	DisjointSet<string> disjS; //The disjoint set used for connections
	void print(string); //Print out the string
public:
	list<forestNode> connectionPoints; //List containing all of the forest nodes that have been previously selected
	forestNode cur; //The current selected forest node
	void sort(); //sort the nodes
	void insert(string, string, int); //Insert a forest node
	void connectTo(string,bool); //Connect to a forest node
	void findPath(string, string, forestNode); //find the path
	bool ifExists(string); //Boolean that returns whether or not the forest node exists
	void travelNext(string); //Travel to the node proceeding the node of the value
	void reset(); //Reset the search through the path
	void exit(); //Exit currently selected node and return to the previous one
};

#include "kruskal.cpp"
