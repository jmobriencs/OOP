// CISP 400 Fall 2020 John-Michael O'Brien SID # w1890922
// A6 ...................................................
// Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream> // standard input/output stream library
using namespace std;

class Complex
{
public:
	friend ostream& operator<<( ostream&, const Complex& ); // output
	explicit Complex( double = 0.0, double = 0.0 ); // constructor
	bool operator==( const Complex& ) const; // comparison
private:
	double real; // real part
	double imaginary; // imaginary part
}; // end class Complex
#endif