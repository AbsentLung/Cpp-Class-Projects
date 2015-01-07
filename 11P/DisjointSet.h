/**	CS515 Assignment 11
	File: DisjointSet.h
	Name: Joseph Bennett
	Section: 3
	Date: 12/03/14
	Collaboration Declaration: None
*/

/* Sets are disjoint if the sets are all pairwise disjoint.                  *
 * For example, the sets {1,2}, {3,6}, {1,0,41} are  disjoint,               *
 * whereas the sets {3,2}, {2,8} are not, due to the common element 2.       *
 * A disjoint set is a set containing disjoint sets. Another name   		 *
 * for this data structure is the union-find.                                *
 * 
 * This particular implementation uses an uptree that is built with an       *
 * underlying std::map. All elements are int type                            *
 *                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



#include <map>
using namespace std;

template<class T>

class DisjointSet{
private:
	std::map<T, T> parents; // access to set representitives
	std::map<T, int> depths; // used for path compression
public:
	DisjointSet(){};

	/**
		  * Creates a singleton set from the parameter.
		  */
	void createSet(T);

	/**
		  * Finds and returns the representative of the set which contains the
		  * parameter. Implements path compression.
		  */
	T findSet(T p);

	/**
		 * Combines the sets which contain the parameters. Return false if two 
	 * parameters are already in the same set; otherwise, union the two sets
	 * by rank and return true. Implements union by rank
	 *          */
	bool unionSets(T p, T q);

};

#include "DisjointSet.cpp"
