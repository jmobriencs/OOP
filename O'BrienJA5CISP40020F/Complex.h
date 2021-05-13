// CISP 400 Fall 2020 John-Michael O'Brien SID # w1890922
// A5 ...................................................
// Project Description (from WordDoc CISP400V10A5)
/*
The following are requirements for this assignment.
a) Modify the class to enable input and output of complex numbers through the overloaded >> and << operators, respectively.  
   The “<<” operator provides print ability.  So the print function in the original Complex class can be removed.  
   The “>>” operator provides the ability to change the private data members of the Complex class object.
b) Overload the multiplication operator to enable multiplication of two complex numbers as in algebra.
c) Overload the division operator to enable division of two complex numbers as in algebra.  In here we need handle “divide by zero” situation.
d) Overload the == and != operators to allow comparisons of complex numbers.
e) Overload the = operator to allow assign a Complex object to the other Complex object.
f) Create V10A5.cpp to test all the functions designed in the assignment.
*/
// Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream> // standard input/output stream library

class Complex
{
public:
	explicit Complex(double = 0.0, double = 0.0); // constructor
	Complex operator+(const Complex&) const; // addition operator
	Complex operator-(const Complex&) const; // subtraction operator
	Complex operator*(const Complex&) const; // multiplication operator
	Complex operator/(const Complex&) const; // division operator
	Complex operator=(const Complex&); // assignment operator
	bool operator!=(const Complex&) const; // not equal to comparison 
	bool operator==(const Complex&) const; // equal to comparison
	friend std::istream& operator>>(std::istream&, Complex&); // input
	friend std::ostream& operator<<(std::ostream&, const Complex&); // output
private:
	double real; // real part
	double imaginary; // imaginary part
}; // end class Complex
#endif