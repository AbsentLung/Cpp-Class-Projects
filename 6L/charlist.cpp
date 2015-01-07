/** CS515 Lab 6
 * File: charlist.cpp
 * Name: Joseph Bennett
 * Section: 03
 * Date: 10/14/14
 * Collaboration Declaration: none
 * Lab Partner: none
 * Collaboration: none
 */

#include "charlist.h" //changed from "CharList.h"

// insert char at the begining of the list
void CharList::insertFront(char value){
        Elem *p = new Elem;
        p->info = value;
        p->next = head;
        head = p;
}

// insert char at the end of the list
void CharList::insertRear(char value){
    Elem *p, *cur = head;
    if ( 0 == head){   // empty list
        Elem *p = new Elem;
        p->info = value;
        p->next = head;
        head = p;
    } else {
       while ( cur -> next ) //While there is a next node, not while there isn't
           cur = cur->next;
       p = new Elem;
       p->info = value;
       p->next = 0;
       cur->next = p;
    } 
}

// convert to string
string CharList::toStr(){
    Elem * cur = head;
    string s; 
    while (cur) {
        s += cur->info;
        cur = cur->next;
    }
    return s; 
}

// common copy code
void CharList::copyCode(const CharList & v){
    Elem *cur1, *cur2;
    if ( 0 == v.head ){  // if empty list
        head = 0;
    } else {  
        head = new Elem;
        head->info = v.head->info;
        cur1 = head;
        cur2 = v.head->next;
        while (cur2) {
            cur1->next = new Elem;
            cur1 = cur1->next; //First Elem must be equal to the next node before changing info of the next node
            cur1->info = cur2->info;
            cur2 = cur2->next;
        }
        cur1->next = 0;
    }
}

// common code for deallocation 
void CharList::destructCode(){
	Elem *cur, *tmp;
	cur = head->next;
	while (cur) {
		tmp = cur;
		cur = cur->next;
		delete tmp;
	}
	delete [] head;
}

ostream& operator<<(ostream& out, CharList c) { //Operator for the output
     out << c.toStr(); //output the c string
     return out; //Return the output
}
