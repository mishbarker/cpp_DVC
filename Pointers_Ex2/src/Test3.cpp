//============================================================================
// Name : 8-16.cpp
// Author :
// Version :
// Copyright : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
int thefunc (int s []) // by default arrays are PBR
{
s[6] = 99;
return 5;
}
int easyFunc (int & y)
{
y++;
cout << "in easyFunc y=" << y << endl;
return 0;
}
void func3 (int * p)
{
cout << "in func3 &p=" << &p << endl;
p++; // adds 4 to whatever the address is in p
*p=55;
return;
}
void func4 (int * g)
{
*g=*g+1;
g++; // adds 4 - ints are 4 bytes long
// g now points to element [1]
*g=*g+1;
g--; // and now back at element [0]
*g=*g-2;
g[4] = 44; //can also access the array thusly
return;
}
void func5(int & a1, int & a2, int * & p1, int * & p2, int * & p3)
{
	if (a1 > a2)
	{
		p3 = &a1; // notice p3 is pbr, so we're really000
		// changing main's p3 here
	}
	else
	{
		p3 = &a2;
	}
}
int main() {
// example of a segmentation exception
// (trying to access memory that isn't mine)
// int * pp = nullptr;
// cout << "starting *pp = " << *pp << endl;
// causes error C0000005 (windows) aka -1,073,741,819
// *pp=*pp+1;
int i[10]; // i by itself refers to the address of the array
// i[n] refers to an element of the array
// can't code &i, as i is already an address
// but &i[n] is ok
int j,k;
j = 2;
cout << "in main, j as defined initially is: " << j << endl;
// pass by value / pass by reference
// pass by value == make a copy
k = easyFunc (j); // let's pass j into easyFunc where j is incremented from 2 to 3
cout << "in main, k = " << k << endl;
cout << "in main, j = " << j << " because easyFunc changed j which is PBR (real value) in the parameter of easyFunc"<< endl;

// need to see easyfunc to determine
// if it's pbv or pbr
// if pbv, then main's j doesn't change
// if pbr, then there is only one j
cout << "in main j = " << j << endl;
i[6]=88;
j = thefunc (i); // an array is pbr automatically
// so thefunc changes the only copy
// of the array
cout << i[6] << endl;
int t;
int * p;
p = &t;
t = 66;
cout << "&p=" << &p << endl; // address of the pointer var p
func3(p); // pass that pointer var to func3
// func3 uses pbv
// func3 changes it, but only its local copy
// a pointer isn't automatically passed by reference!
// but don't forget, an array is a special case
cout << "after call to func3, t = " << t << endl;
i[0]=10;
i[1]=20;
i[2]=30;
func4(i); // i is automatically pbr  *g in func4 is pointing to the address of i (I think so.)
cout << "after call to func4 i[0] = " << i[0] << endl;
cout << "after call to func4 i[1] = " << i[1] << endl;
cout << "after call to func4 i[2] = " << i[2] << endl;
// a bit more complex. func5 examines a1 and a2, and points p3
// at whichever is larger
// p3 will need to pbr, else whatever change func5 makes
// will be only local to func5

/*void func5(int & a1, int & a2, int * & p1, int * & p2, int * & p3)
{
	if (a1 > a2)
	{
		p3 = &a1; // notice p3 is pbr, so we're really000
		// changing main's p3 here
	}
	else
	{
		p3 = &a2;
	}
}*/

int a1, a2;
int * p1, *p2, *p3;
a1=1;
a2=2;
p1 = &a1;
p2 = &a2;
// we can make it easy on ourselves and just pass everything pbr
func5(a1, a2, p1, p2, p3);
cout << "after call to func5 *p3 = " << *p3 << endl;
return 0;
}
