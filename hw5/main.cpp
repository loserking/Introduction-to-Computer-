
#include <iostream>
#include "myvector.h"
#include "myvector.h"	// test for duplicated inclusion

using namespace std;

int main()
{

	MyVector a;		// test for default constructor

	cout << a << endl;

	a.resize(3);
	a.set(0, 0.0).set(1, 0.1).set(2, 0.2);

	cout << a << endl;
	cout << a.get(1) << endl;
	cout << a.getLength() << endl;

	MyVector b(2), c(1);  // test if operator= deals with resizing
	c = b = a;            // test copier

	cout << b << endl;
	cout << c << endl;

	MyVector d(c);  // test copy constructor
	cout << d << endl;

	cout << c*d << endl;     // inner product
	cout << a+b+c << endl; 

	return 0;

}

