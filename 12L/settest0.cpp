#include <cassert>
#include "set.h"
using namespace std;

int main(){
   Set t;
   
   // test find and insert
   assert(t.find("hello")==false);
   assert(t.insert("heLLo")==true);
   assert(t.find("hEllo")==true);
   assert(t.size()==1);
   
   assert(t.insert("hello")==false);
   assert(t.find("hello")==true);
   assert(t.size()==1);
   
   // test erase
   assert(t.erase("hello")==true);
   assert(t.find("hello")==false);
   assert(t.size()==0);
   
   assert(t.erase("hell")==false);
   assert(t.find("hell")==false);
   assert(t.size()==0);

	t.insert("derp");
	t.insert("Plderp");
	t.insert("Plerp");
	t.insert("Aye");
	t.insert("Hey");
	t.insert("ZZZZZzzzzzZzzZ");
	assert(t.size()==6);
	cerr<<"done"<<endl;
}
