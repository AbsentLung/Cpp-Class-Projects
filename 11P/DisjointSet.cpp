/**	CS515 Assignment 11
	File: DisjointSet.cpp
	Name: Joseph Bennett
	Section: 3
	Date: 12/03/14
	Collaboration Declaration: None
*/

template<class T>
void DisjointSet<T>::createSet(T t) {
	parents[t] = t; //The parent's value is itself
	depths[t] = 0; //Depth at this value starts at zero
}

template<class T>
T DisjointSet<T>::findSet(T p) {
	if (p!=parents[p]) //If the value is not equal to its parent's value then it is not the root value
		parents[p] = findSet(parents[p]); //Call recursively until the root is found value
	return parents[p]; //Return the root value
}

template<class T>
bool DisjointSet<T>::unionSets(T p, T q) {
	if (findSet(p)==findSet(q)) //If the sets are equal
		return false; //Return False
	T pid1 = findSet(p); //Create pids
	T pid2 = findSet(q);
	if (depths[pid1] > depths[pid2]) //If the first pid's depth is greater than the second
		parents[pid2] = pid1; //Assign pid1's value to pid2's parent
	else { //Otherwise
		parents[pid1] = pid2; //Assign pid2's value to pid1's parent
		if (depths[pid1] == depths[pid2]) { //If the depths are equal
			depths[pid2]++; //Increment the value of pid2's depth
			return false; //Return False
		}
	}
	return true; //Return true depths weren't equal
}
