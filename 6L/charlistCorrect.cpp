/** CS515 Lab 6
 * File: charlist.cpp
 * Name: Joseph Bennett
 * Section: 03
 * Date: 10/04/13
 * Collaboration Declaration:
 * 	Lab Partner: none
 * 	Collaboration: help from TA
 */

#include "charlist.h"//changed "charlist.h" to "charlist.cpp"


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
    if (!head){   // empty list
        p = new Elem;
        p->info = value;
        p->next = head;
        head = p;
    } else {
       while ( cur -> next )//took out the "!" next to the cur
           cur = cur->next;
       p = new Elem;
       p->info = value;
       p->next = 0;
       cur->next = p;
    }
}

// convert to string
string CharList::toStr(){
    Elem * p = head;
    string s; 
    while (p) {
        s += p->info;
        p = p->next;
    }
    return s; 
}

// common copy code
void CharList::copyCode(const CharList & v){
    Elem *p1;
    Elem *p2;

    if ( !v.head ){
        head = 0;
    } else {  
        head = new Elem;
        head->info = v.head->info;
        p1 = head;
        p2 = v.head->next;

        while (p2) {
            p1->next = new Elem;
            p1 = p1->next;
            p1->info = p2->info;
            p2 = p2->next;
        }
        p1->next = 0;
    }
}

// common code for deallocation 
void CharList::destructCode(){
    delete [] head;
}

// overloaded output operator
ostream& operator<<(ostream& out, CharList c){
     out << c.toStr(); 
     return out;
}
