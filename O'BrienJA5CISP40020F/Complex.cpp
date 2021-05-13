// CISP 400 Fall 2020 John-Michael O'Brien SID # w1890922
// A5 ...................................................
// Complex.cpp
#include <iostream> // standard input/output stream library
#include <math.h> // numerics library
#include "Complex.h" // Complex class definition
using namespace std;

bool infinity = false;

// Constructor
Complex::Complex(double realPart, double imaginaryPart)
	: real(realPart),
	imaginary(imaginaryPart)
{
	// empty body
} // end Complex constructor

// addition operator
Complex Complex::operator+(const Complex& operand2) const
{
	return Complex(real + operand2.real,
		imaginary + operand2.imaginary);
} // end function operator+

// subtraction operator
Complex Complex::operator-(const Complex& operand2) const
{
	return Complex(real - operand2.real,
		imaginary - operand2.imaginary);
} // end function operator-

// multiplication operator
Complex Complex::operator*(const Complex& operand2) const
{
	return Complex((real * operand2.real) + (imaginary * operand2.imaginary * -1),
		(real * operand2.imaginary) + (imaginary * operand2.real));
} // end function operator*

// division operator
Complex Complex::operator/(const Complex& operand2) const
{
	if ((operand2.real == 0) && (operand2.imaginary == 0))
	{
		return Complex(7378707378738469, 7378707378738469); // 7378707378738469 is INFINITE in decimal
	}
	else
	{
		return Complex(((real * operand2.real) + (imaginary * operand2.imaginary)) / (pow(operand2.real, 2) + pow(operand2.imaginary, 2)),
			((imaginary * operand2.real) - (real * operand2.imaginary)) / (pow(operand2.real, 2) + pow(operand2.imaginary, 2)));
	}
} // end function operator/

// != comparison operator
bool Complex::operator!=(const Complex& operand2) const
{
	return ((real != operand2.real) && (imaginary != operand2.imaginary)) ? true : false;
} // end function operator!=

// == comparison operator
bool Complex::operator==(const Complex& operand2) const
{
	return ((real == operand2.real) && (imaginary == operand2.imaginary)) ? true : false;
} // end function operator==

// assignment operator
Complex Complex::operator=(const Complex& operand2)
{
	// check for self-assignment by comparing the address of the implicit object and the parameter
	if (this == &operand2)
		return *this;
	// do the copy
	real = operand2.real;
	imaginary = operand2.imaginary;

	// return the existing object
	return *this;
} // end function operator=

// input operator
istream& operator>>(istream& in, Complex& c)
{
	cout << "Enter a complex number in the form: (a, b) for Complex object k.\n";
	cout << "(Performing >> operator overloading.)\n";
	cout << "? ";

	in.ignore(1, '(');
	in >> c.real;
	in.ignore(1, ',');
	in >> c.imaginary;

	return in;
} // end function &operator>>

// output operator
ostream& operator<<(ostream& out, const Complex& c)
{
	if ((c.real == 7378707378738469) && (c.imaginary == 7378707378738469)) // 7378707378738469 is INFINITE in decimal
	{
		out << "infinite";
	}
	else
	{
		out << "(" << c.real << ", " << c.imaginary << ")";
	}

	return out;
} // end function &operator<<