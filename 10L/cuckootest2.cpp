#include "cuckoo.h"
#include <cassert>
using namespace std;


int main(int argc, char** argv){

    HashTable s1;
   
    assert(s1.insert("oa")==true);
    assert(s1.insert("fa")==true);
    assert(s1.insert("pa")==true);
    assert(s1.insert("it")==true);
    assert(s1.remove("ca")==false);
    assert(s1.remove("ca")==false);
    
    assert(s1.insert("ca")==true);
    assert(s1.insert("ff")==true);
    assert(s1.insert("ca")==false); // dup
    assert(s1.insert("ff")==false); // dup
    assert(s1.insert("ea")==true); 
    assert(s1.insert("it")==false); // dup
    assert(s1.insert("aba")==true);
    assert(s1.insert("ffd")==true);
    assert(s1.insert("eafdf")==true);
    assert(s1.insert("cad")==true);
    assert(s1.insert("fif")==true);
    assert(s1.insert("ear")==true);    
    assert(s1.size()==13);
   
  
    assert(s1.find("ear") == true);
    assert(s1.find("ff") == true);
    assert(s1.find("ca") == true);
    assert(s1.find("sand") == false);
    assert(s1.find("thing") == false);
    assert(s1.find("about") == false);
    
    assert(s1.remove("ear")==true);
    assert(s1.remove("ear")==false);
    assert(s1.find("ear") == false);
    
    return 0;
}
