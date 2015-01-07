/** CS515 Assignment 9
 * File: map.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 11/17/14
 * Collaboration Declaration: None
 * Lab Partner: None
 * Collaboration: None
 * */
#include <cstdlib>

// Construct the hash table.
template <typename KEY, typename T>
Map<KEY, T>::Map(){
    srand(time(0));
    tablesize = nextPrime(101); // initial table size
    entrysize = 0;
    numOfTables = 100;
    array = new Elem*[numOfTables];
    for (int i =0; i<numOfTables; i++)
        array[i] = new Elem[tablesize];
}

template <typename KEY, typename T>
Map<KEY, T>::~Map(){
    for (int i=0; i<numOfTables; i++)
        delete [] array[i];
    delete [] array;
}


// Insert item newkey into the hash table.
// return false if item is already in the table
// otherwise, insert element and return true
// rehash if eviction loop is detected
// YOU DON'T NEED TO IMPLEMENT REHASH FOR LAB SUBMISSION
template <typename KEY, typename T>
bool Map<KEY, T>::insert(KEY &newkey, T &t){
	//if(find(newkey)==Iterator()) //If the string inserted cannot be found
	//	return 0; //Exit function, return false
	allKeys.insert(newkey);
	KEY sub = newkey; //A substitute string for the key entered
	T sub2 = t; //A substitute string for the key entered
	KEY prev;
	T prev2;
	int hashNum;
	for (int j = 0; j < 20; j++) { //Repeat method spot for all 20 rows or until an inactive element is found
		for (int i = 0; i < numOfTables; i++) { //Search through each table
			hashNum = hash(sub, i) % tablesize; //Generate the correct row
			prev = array[i][hashNum].key; //Grab the element
			prev2 = array[i][hashNum].data; //Grab the data
			array[i][hashNum].key = sub; //The element is now equal to the key
			array[i][hashNum].data = sub2;
			if (array[i][hashNum].isActive) { //If it is active with the key
				sub = prev; //Grab the previous element so that it may be pushed forward
				sub2 = prev2;
			}
			else { //If inactive
				entrysize++; //Increase the entry size
				array[i][hashNum].isActive=true; //The element is now active
				return true; //Element is returned, return true
			}
		}
	}
	return true;
}

// increase the size of each table and rehash all elements
template <typename KEY, typename T>
void Map<KEY, T>::rehash( ){
    // not implemented
}

// find position of an element in a table
// if found, set n to the table index and return x's position in this table
// if not found (in any table), set n to -1 and return -1;
template <typename KEY, typename T>
int Map<KEY, T>::findPos(KEY & x) const{
	for (int i = 0; i < numOfTables; i++) //Search through each table
		for (int j = 0; j < tablesize; j++) //Search through each row
			if (array[i][j].isActive && x == array[i][j].key) //If the element is found and it is active
				return j; //Return the row position
	return -1; //For row position as well
}

// Remove item x from the hash table. Return true if successufl, else false
template <typename KEY, typename T>
bool Map<KEY, T>::remove(KEY & x){
	for (int i = 0; i < numOfTables; i++) //Search through each table
		for (int j = 0; j < tablesize; j++) //Search through each row
			if (x == array[i][j].key) { //If the element is found
				array[i][j].isActive=false; //The element is no longer active
				entrysize--; //Decrease in entry size
				return true; //Element is found, return true
			}
	return false; //Element was not found, return false
}

// Find item x in the hash table. Return true if found, else false
template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::find(KEY & x ) const{
	for (int i = 0; i < numOfTables; i++) //Search through each table
		for (int j = 0; j < tablesize; j++) //Search through each row
			if (array[i][j].isActive && x == array[i][j].key) //If element is found and it is active
				return Iterator(&array[i][j]); //Element is found, return true
	return Iterator(); //Element was not found, return false
}

// return the total number of element in the hashtable.
template <typename KEY, typename T>
int Map<KEY, T>::size() const{
    return entrysize;
}

// hash a string based on one of the three simple hash functions
// each hash function differ by three prime constant
// precondition: which value is between [0-2]
template <typename KEY, typename T>
unsigned int Map<KEY, T>::hash(KEY & key, int which){
    unsigned int hashVal = 0;
    static int multiplier[] = {233, 113, 307}; // randomly selected 3 prime numbers
    // use multiplier[which] to apply one of the three prime numbers 
    for(int i = 0; i < key.length(); i++) //For each key
        hashVal =  multiplier[which] * hashVal + key[i]; //Hash value increases by the key value added to the hash value multiplied by the prime number selected
    return hashVal; //Return the final hash value
}

// Internal method to test if a positive number is prime (not efficient)
bool isPrime( int n ){
    if( n == 2 || n == 3 )
        return true;
    if( n == 1 || n % 2 == 0 )
        return false;
    for( int i = 3; i * i <= n; i += 2 )
        if( n % i == 0 )
            return false;
    return true;
}

// Internal method to return a prime number at least as large as n.
// Assumes n > 0.
int nextPrime( int n ){
    if( n % 2 == 0 )
        n++;
    for( ; !isPrime( n ); n += 2 )
        ;
    return n;
}

template<typename KEY, typename T>
T& Map<KEY, T>::operator[](KEY &k) {
	T t;
	if (findPos(k) == -1)
		insert(k, t); //Insert the key
	Iterator it = find(k);
	return it->data; //Return the data at the element
}

template<typename KEY, typename T>
typename Map<KEY, T>::Elem& Map<KEY, T>::Iterator::operator*() {
	return *_cur;
}

template<typename KEY, typename T>
typename Map<KEY, T>::Elem* Map<KEY, T>::Iterator::operator->() {
	return _cur;
}

template<typename KEY, typename T>
bool Map<KEY, T>::Iterator::operator==(Map<KEY, T>::Iterator it) {
	return _cur==it._cur;
}

template<typename KEY, typename T>
bool Map<KEY, T>::Iterator::operator!=(Map<KEY, T>::Iterator it) {
	return _cur!=it._cur;
}

template<typename KEY, typename T>
typename Map<KEY,T>::Iterator Map<KEY,T>::end() const {
	return Iterator();
}
