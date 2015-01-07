#include <iostream>

using namespace std;
/*
class Vector{
	// an int vector class
	public:
		Vector(int);
		Vector(const Vector&);
		Vector& operator=(const Vector&);
		~Vector();
		int getAt(int i);
	private:
		int size, *ptr;
};
Vector::Vector(int n) : size(n){
	ptr = new int[size];
	for(int i=0; i<size; i++)
		ptr[i]=0; // initialize
}
Vector::Vector(const Vector& V) {
	size = V.size;
	ptr = new int[size];
}
Vector::~Vector(){
	delete [] ptr;
}
int Vector::getAt(int index){
	return ptr[index];
}
void f(Vector v){
	cout << v.getAt(0);
}
int main(){
	Vector v1(10);
	f(v1);
}*/

//There is a compile time error if iostream and namespace std aren't included.
//But if that doesn't count then there's a runtime error when using function "f"
//Because there is no copy constructer for class "Vector".






//2
//The c++ Othodox Canonical Class Form includes a default constructor, a copy constructor,
//an assignment operator, and a destructor in every class object.  It is important so that
//an implemented object may be created, copied, operated on, and destroyed efficiently without
//taking up extra memory space or altering a program in an unwanted way.


//3
class B{
public:
	B() { cout << "B default constructor" << endl; }
	B( B& ) { cout << "B copy constructor" << endl; }
	~B() { cout << "B destructor" << endl; }
};

class C{
public:
	C() { cout << "C default constructor" << endl; }
	C( C& ) { cout << "C copy constructor" << endl; }
	~C() { cout << "C destructor" << endl; }
};

C* f( B bb, C& c1 ){
	C * cptr = new C();
	*cptr = c1;
	return cptr;
}

int main(){
	C c, *cptr;
	B b;
	cout << "before function call" << endl;
	cptr = f( b, c );
	cout << "after function call" << endl;
	delete cptr;
}

/*
C default
B default
before
B copy
C default
B destruct
after
C destruct
B destruct
C destruct
*/


//4
/*
	Constant methods are called within a class and have a "this" variable which calls variables within the object.
*/
