/**	CS515 Assignment 11
	File: kruskal.cpp
	Name: Joseph Bennett
	Section: 3
	Date: 12/03/14
	Collaboration Declaration: None
*/

void forest::print(string str) {
	stringstream s(str); //Make a string stream of the string
	string output;
	s>>output; //First variable is always the node currently connected
	cout<<" From: "<<output<<endl; //Print to the user
	while(s>>output) //Print out every node the has been gone through along the way
		cout<<"   To: "<<output<<endl;
	started = true; //The forest has began to be sifted through
}

void forest::sort() {
	edges.sort(); //Sort the edges
	list<edge>::iterator it; //Create an iterator
	for (it = edges.begin(); it != edges.end(); it++) { //Go through every edge
		if (disjS.findSet(((*it).n1).value)[0] == 0) //Create a set for node 1 of the edge if it hasn't been created already
			disjS.createSet(((*it).n1).value);
		if (disjS.findSet(((*it).n2).value)[0] == 0) //Create a set for node 2 of the edge if it hasn't been created already
			disjS.createSet(((*it).n2).value);
		if (disjS.findSet(((*it).n1).value) != disjS.findSet(((*it).n2).value)) { //If the sets aren't unioned
			disjS.unionSets(((*it).n1).value, ((*it).n2).value); //Union each set
			safeEdges.push_back(*it); //The edge is now a safe edge
		}
	}
}

void forest::insert(string s1, string s2, int weight) {
	bool addn1 = true; //Declare variables
	bool addn2 = true;
	edge e; //Create an edge and set the variables
	e.n1.visited = false;
	e.n2.visited = false;
	e.n1.value = s1;
	e.n2.value = s2;
	e.weight = weight;
	edges.push_back(e); //Push the edge back onto the list of edges
	list<forestNode>::iterator it;
	for (it=forestNodes.begin(); it!=forestNodes.end(); it++) { //Iterate through every forest node
		if ((*it).value == s1) //If the first value is found then don't insert it
			addn1=false;
		if ((*it).value == s2) //Same for the second value
			addn2=false;
	}
	if (addn1) //If the first value was never found then it is inserted
		forestNodes.push_back(e.n1);
	if (addn2) //Same for the second value
		forestNodes.push_back(e.n2);
}

void forest::connectTo(string str, bool newConnection) {
	list<edge>::iterator it;
	for (it = edges.begin(); it != edges.end(); it++) { //Iterate through every edge
		if (((*it).n2).value == str) { //If it is the second value then set it
			cur=(*it).n2;
			break;
		}
		if (((*it).n1).value == str) { //If it is the first value then set it as the current
			cur=(*it).n1;
			break;
		}
	}
	if (newConnection) //If it's a new connection
		connectionPoints.push_back(cur); //Push it onto the list
}

void forest::findPath(string fullStr, string soughtValue, forestNode n) {
	if (n.value==soughtValue) //If the value matches the sought value
		print(fullStr+" "+n.value); 
	else if (!started) { //If the print hasn't started
		list<edge>::iterator it;
		list<edge>::iterator it2;
		for (it = safeEdges.begin(); it != safeEdges.end(); it++) { //Iterator through every safe edge
			if (((*it).n1).value == n.value && ((*it).n2).visited == false) { //If the value matches the first node and the second node is unvisited
				travelNext(((*it).n2).value); //Travel to the second value
				findPath(fullStr+" "+n.value, soughtValue, (*it).n2); //Add the value to the path
			}
			if (((*it).n2).value == n.value && ((*it).n1).visited == false) { //If the value matches the second node and the first node is unvisited
				travelNext(((*it).n1).value); //Travel to the first value
				findPath(fullStr+" "+n.value, soughtValue, (*it).n1); //Add the value to the path
			}
		}
	}
}

bool forest::ifExists(string str) {
	list<forestNode>::iterator it;
	for (it = forestNodes.begin(); it != forestNodes.end(); it++) //Iterate through every node in the forest
		if ((*it).value == str) //If the string is found
			return true; //Return true
	cout<<"Cannot find node. Available nodes are:"<<endl; //Alert user if node wasn't found
	for (it = forestNodes.begin(); it != forestNodes.end(); it++) //Show connectionPoints of the available nodes to the user
		cout<<" "<<(*it).value<<endl;
	return 0;
}

void forest::travelNext(string str) {
	list<edge>::iterator it;
	for (it=safeEdges.begin();it!=safeEdges.end();it++) { //Iterate through every safe edge
		if (((*it).n1).value == str) //If it matches the first node
			((*it).n1).visited = true; //The first node has now been visited
		else if (((*it).n2).value == str) //If it matches the second node
			((*it).n2).visited = true; //The second node has now been visited
	}
}

void forest::reset() {
	list<edge>::iterator it;
	for (it=safeEdges.begin(); it!=safeEdges.end(); it++) { //Iterate through every safe edge
		((*it).n1).visited = false; //The node of each edge has not yet been visited
		((*it).n2).visited = false;
	}
	started=false; //Set back to normal as if printing hasn't been started
}

void forest::exit() {
	connectionPoints.pop_back(); //Pop the current forest node out of the stack
	list<forestNode>::iterator end = connectionPoints.end(); //The end node is now one less
	end--;
	if(!connectionPoints.empty()) //If the list is empty
		connectTo((*end).value,false); //Create a false connectivity
}
