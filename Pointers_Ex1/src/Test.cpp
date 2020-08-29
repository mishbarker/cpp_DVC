
//============================================================================
// Name : 8-26.cpp
// Author : Paul Hrycewicz
// Version :
// Copyright : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
int main() {
// addressing essentials
int i;
float f;
int * p;
// remember:
// all vars have some address in memory
// all vars have some value - ints, floats, whatever
// when a var is a pointer, then we can use that pointer
// to get at what it points to - this is dereferencing
i = 3;
cout << "i=" << i << endl; // i has some value
cout << "&i=" << &i << endl; // all these vars have some address in memory
cout << "&f=" << &f << endl;
cout << "&p=" << &p << endl;
// what is value of f?
cout << "f=" << f << endl; // who knows what?? garbage
cout << "p=" << p << endl; // also garbage - points somewhere, who knows where
p = nullptr; // but now it points to zero
cout << "p=" << p << endl;
p = &i; // and now it points to var i
cout << "p=" << p << endl; // i can display the address contained in p
// which is the address of i
cout << "*p=" << *p << endl; // but this is different than the contents of i
// which i get if i dereference p
return 0;
}
