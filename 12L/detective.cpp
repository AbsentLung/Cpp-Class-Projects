/* 
 * This is a sample driver that tests the performace of mysterySort1
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sys/time.h>
#include "mysterysorts.h"
using namespace std;

int main(){
    vector<int> a;
    srand(time(0));
    
    cout << "original:" << endl;
    /*for( int i = 0; i < 50; i++ ){
        a.push_back(rand()%1000);
        cout << a[i] << " ";
    }
    cout << endl;
    */
	a.push_back(6);
	a.push_back(5);
	a.push_back(3);
	a.push_back(1);
	a.push_back(8);
	a.push_back(7);
	a.push_back(2);
	a.push_back(4);
	for( int i = 0; i < 8; i++ ){
		cout << a[i] << " ";
	}
	cout << endl;
for (int i = 0; i < 500; i++) {
//    timeval start, finish;
//    double elapse;
//    gettimeofday(&start, 0);
    
    //run sort without interruption
    //mysterySort1(a);
    mysterySort4(a, 1);
//    gettimeofday(&finish, 0);
//   	elapse = (double) finish.tv_usec  - (double) start.tv_usec;
//    cout << "Total elapsed time: " << elapse << " microseconds." << endl;
    
    //interrupt sort after time elapse 150 microseconds
    //mysterySort1(a, 15);
    
    // check current vector content
//    cout << "current:" << endl;
    for( int i = 0; i < a.size(); i++ ){
        cout << a[i] << " ";
    }
    cout << endl;
    
    }
	    
}
