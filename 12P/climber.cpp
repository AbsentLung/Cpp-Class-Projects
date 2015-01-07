/*
 * CS515 Assignment 12
 * File: climber.cpp
 * Name: Joseph Bennett
 * Section: 03
 * Date: 12/13/14
 * Collaboration Declaration: None
 */

#include <map>
#include <list>
#include <limits>
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;

int main() {
	int x; //Declare Variables
	int y;
	int shortestDistance;
	int currentDistance;
	int endX;
	int endY;
	int totalRopes;
	pair<int, int> pIt1;
	pair<int, int> pairIt1;
	pair<int, int> newPairInner;
	pair<bool, pair<int, int> > pIt2;
	pair<bool, pair<int, int> > pairIt2;
	pair<bool, pair<int, int> > newPairMiddle;
	pair<int, pair<bool, pair<int, int> > > pIt3;
	pair<int, pair<bool, pair<int, int> > > pairIt3;
	pair<int, pair<bool, pair<int, int> > > newPairOuter;
	list<pair<int, pair<bool, pair<int, int> > > >::iterator lIt1;
	list<pair<int, pair<bool, pair<int, int> > > >::iterator lIt2;
	list<pair<int, pair<bool, pair<int, int> > > >::iterator listIt;
	list<pair<int, pair<bool, pair<int, int> > > >::iterator newListIt;
	map<int, list<pair<int, pair<bool, pair<int, int> > > > > m;
	map<int, list<pair<int, pair<bool, pair<int, int> > > > >::iterator mIt;
	map<int, list<pair<int, pair<bool, pair<int, int> > > > >::iterator mapIt;
	map<int, list<pair<int, pair<bool, pair<int, int> > > > >::iterator newMapIt;
	string line;
	getline(cin, line);
	stringstream s(line);
	s >> totalRopes; //Grab the total number of ropes
	s >> x; //First rope's X
	s >> y; //First rope's Y
	m[x].push_back(make_pair(y, make_pair(true, make_pair(0, 0)))); //Insert the first rope into the map
	mapIt = m.begin(); //Make all of the values for the first rope as the current position for the iterators
	listIt=mapIt->second.begin();
	pairIt3 = *listIt;
	pairIt2 = pairIt3.second;
	pairIt1 = pairIt2.second;
	pairIt2.second = pairIt1;
	pairIt3.second = pairIt2;
	mIt=m.begin();
	lIt1=mIt->second.begin();
	*lIt1=pairIt3;
	s >> x; //Last rope's X
	s >> y; //Last rope's Y
	m[x].push_back(make_pair(y, make_pair(false, make_pair(std::numeric_limits<int>::max(), 0))));
	endX = x;
	endY = y;
	for (int count = 2; s >> x && s >> y && count < totalRopes; count++) //For every remaining rope
		m[x].push_back(make_pair(y, make_pair(false, make_pair(std::numeric_limits<int>::max(), 0))));
	while (! (mapIt->first == endX && pairIt3.first == endY) ) { //Until the last rope is reached
		for(mIt=m.begin(); mIt != m.end() ; mIt++) //Throughout the whole map
			for(lIt1 = mIt->second.begin(); lIt1 != mIt->second.end() ; lIt1++) { //For every list within the map
				pIt3 = *lIt1; //Reassign values
				pIt2 = pIt3.second;
				pIt1 = pIt2.second;
				if (!pIt2.first) { //If it has not yet been visited
					currentDistance = (mIt->first - mapIt->first) * (mIt->first - mapIt->first) + (pIt3.first - pairIt3.first) * (pIt3.first - pairIt3.first);
					if (currentDistance + pairIt1.first < pIt1.first) { //If the distance to be added still does not equal pIt1.first's distance
						pIt1.first = currentDistance + pairIt1.first; //Add the distance
						pIt1.second = pairIt1.second; //Reassign value
						if (currentDistance > pIt1.second) //If a greater distance
							pIt1.second = currentDistance; //assign it
					}
				}
				pIt2.second = pIt1; //Reassign values
				pIt3.second = pIt2;
				*lIt1=pIt3;
			}
		shortestDistance = std::numeric_limits<int>::max(); //Shortest distance starts at the maximum value
		for(mIt=m.begin(); mIt != m.end() ; mIt++) //For all of the values in the map
			for(lIt1 = mIt->second.begin(); lIt1 != mIt->second.end(); lIt1++) { //For all of the lists in the map
				pIt3=*lIt1; //Reassign values
				pIt2 = pIt3.second;
				pIt1 = pIt2.second;
				if (!pIt2.first && pIt1.first < shortestDistance) { //If not yet visited and a shorter distance
					shortestDistance=pIt1.first; //Assign to be new shortest distance
					newMapIt = mIt;
					newListIt= lIt1;
					newPairOuter = pIt3;
					newPairMiddle = pIt2;
					newPairInner = pIt1;
					lIt2 = lIt1;
				}
			}
		pairIt1 = newPairInner; //Reassign values
		pairIt2 = newPairMiddle;
		pairIt2.first = true;
		pairIt3 = newPairOuter;
		listIt= newListIt;
		mapIt = newMapIt;
		pairIt2.second = pairIt1;
		pairIt3.second = pairIt2;
		*lIt2=pairIt3;
	}
	cerr << pairIt1.second <<endl; //The shortest distance is found
	return 0;
}
