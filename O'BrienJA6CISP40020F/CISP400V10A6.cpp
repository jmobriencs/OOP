// CISP 400 Fall 2020 John-Michael O'Brien SID # w1890922
// A6 ...................................................
// Project Description (from WordDoc CISP400V10A6)
/*
Write a simple function template for predicate function isEqualTo that compares its two
arguments of the same type with the equality operator (==) and returns true if they are equal and
false if they are not equal. Use this function template in a program that calls isEqualTo on a
variety of built-in types and user define types, Complex and Date (need to overload the equality
operator (operator==) and extraction operator (operator<<)).  Write a program with variety of
inputs to test the functionalities of the program.
*/
// CISP400V10A6.cpp
#include <iostream> // standard input/output stream library
#include "Complex.h" // include Complex class definition
#include "Date.h" // include Date class definition
using namespace std;

// isEqualTo template function
template< typename T >
bool isEqualTo( T  a, T  b )
{
	return (a == b) ? true : false;
}

int main()
{
	Complex a( 10, 5 ); // operant a
	Complex b( 10, 54 ); // operant b
	Complex c( 10, -5 ); // operant c
	Complex d( -10, -5 ); // operant d
	Date e( 2, 31, 2017 ); // operant e
	Date f( 2, 13, 2017 ); // operant f
	Date g( 2, 14, 2017 ); // operant g
	Date h( -2, 13, 2017 ); // operant h

	// integer tests
	cout << "***  Integers Tests  ***\n";
	cout << "Integers: 1 and 1 are ";
	( isEqualTo( 1, 1 ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // 1 and 1 are equal
	cout << "Integers: 2 and 4 are ";
	( isEqualTo( 2, 4 ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // 2 and 4 are "NOT" equal
	cout << "Integers: -1 and 1 are ";
	( isEqualTo( -1, 1 ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // -1 and 1 are "NOT" equal
	cout << "Integers: -1 and -1 are ";
	( isEqualTo( -1, -1 ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // -1 and -1 are equal

	// character tests
	cout << "\n\n***  Chars Tests  ***\n";
	cout << "Characters: a and a are ";
	( isEqualTo( 'a', 'a' ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // a and a are equal
	cout << "Characters: a and c are ";
	( isEqualTo( 'a', 'c' ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // a and c are "NOT" equal
	cout << "Characters: c and a are ";
	( isEqualTo( 'c', 'a' ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // c and a are "NOT" equal
	cout << "Characters: c and c are ";
	( isEqualTo( 'c', 'c' ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // c and c are equal

	// doubles tests
	cout << "\n\n***  Doubles Tests  ***\n"; 
	cout << "Double numbers: 2.2 and 2.2 are ";
	( isEqualTo( 2.2, 2.2 ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // 2.2 and 2.2 are equal
	cout << "Double numbers: 2.2 and 2.3 are ";
	( isEqualTo( 2.2, 2.3 ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // 2.2 and 2.3 are "NOT" equal
	cout << "Double numbers: -2.2 and 2.2 are ";
	( isEqualTo( -2.2, 2.2 ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // -2.2 and 2.2 are "NOT" equal
	cout << "Double numbers: -2.2 and -2.2 are ";
	( isEqualTo( -2.2, -2.2 ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // -2.2 and -2.2 are equal

	// complex tests
	cout << "\n\n***  Complex Tests  ***\n";
	cout << "Complex Objects: " << a << " and " << a << " are ";
	( isEqualTo( a, a ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // 10 + 5i and 10 + 5i are equal
	cout << "Complex Objects: " << a << " and " << b << " are ";
	( isEqualTo( a, b ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // 10 + 5i and 10 + 54i are "NOT" equal
	cout << "Complex Objects: " << c << " and " << a << " are ";
	( isEqualTo( c, a ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // 10 - 5i and 10 + 5i are "NOT" equal
	cout << "Complex Objects: " << d << " and " << d << " are ";
	( isEqualTo( d, d ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // -10 - 5i and -10 - 5i are equal
	
	// string tests
	cout << "\n\n***  String Tests  ***\n"; 
	cout << "String objects: abcdefg and abcdefg are ";
	( isEqualTo( "abcdefg", "abcdefg" ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // abcdefg and abcdefg are equal
	cout << "String objects: abcdefg and abcdefh are ";
	( isEqualTo( "abcdefg", "abcdefh" ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // abcdefg and abcdefh are "NOT" equal
	cout << "String objects: -abcdefg and abcdefg are ";
	( isEqualTo( "-abcdefg", "abcdefg" ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // -abcdefg and abcdefg are "NOT" equal
	cout << "String objects: -abcdefg and -abcdefg are ";
	( isEqualTo( "-abcdefg", "-abcdefg" ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // -abcdefg and -abcdefg are equal

	// date tests
	cout << "\n\n***  Date Tests  ***\n";
	cout << "Date objects: " << e << " and " << e << " are ";
	( isEqualTo( e, e ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // February 1, 2017 and February 1, 2017 are equal
	cout << "Date objects: " << f << " and " << g << " are ";
	( isEqualTo( f, g ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // February 13, 2017 and February 14, 2017 are "NOT" equal
	cout << "Date objects: " << h << " and " << f << " are ";
	( isEqualTo( h, f ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // January 13, 2017 and February 13, 2017 are "NOT" equal
	cout << "Date objects: " << h << " and " << h << " are ";
	( isEqualTo( h, h ) ) ? cout << "equal\n" : cout << "\"NOT\" equal\n"; // January 13, 2017 and January 13, 2017 are equal

	cout << endl;
	system( "pause" ); 
	return 0;
} // end main