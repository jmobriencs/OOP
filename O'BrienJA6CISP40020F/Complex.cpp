// CISP 400 Fall 2020 John-Michael O'Brien SID # w1890922
// A6 ...................................................
// Complex.cpp
// Complex class member-function definitions.
#include <iostream> // standard input/output stream library
#include <math.h> // numerics library
#include "Complex.h" // include Complex class definition
using namespace std;

// constructor
Complex::Complex( double realPart, double imaginaryPart ) 
   : real( realPart ),
   imaginary( imaginaryPart )
{ 
	// empty body
} // end Complex constructor

// output operator
ostream &operator<<( ostream &out, const Complex &c )
{
	if( c.imaginary < 0 )
	{
		out << c.real << " - " << c.imaginary * (-1) << "i";
	}
	else
	{
		out << c.real << " + " << c.imaginary << "i";
	}

	return out;
} // end function &operator<<

bool Complex::operator==( const Complex &operand2 ) const
{
	return ( (real == operand2.real) && (imaginary == operand2.imaginary) ) ? true : false;
} // end function operator==