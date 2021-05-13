// CISP 400 Fall 2020 John-Michael O'Brien SID # w1890922
// A6 ...................................................
// Date.h
#ifndef DATE_H
#define DATE_H
#include <string> // string types, character traits and a set of converting functions
using namespace std;

class Date 
{
public:
   static const unsigned int monthsPerYear = 12; // months in a year
   static const string allMonths[12]; // 12 months
   Date( int, int, int ); // default constructor
   friend ostream &operator<<( ostream &, const Date & ); // output
   bool operator==( const Date & ) const; // comparison
private:
   unsigned int month; // 1-12 (January-December)
   unsigned int day; // 1-31 based on month
   unsigned int year; // any year

   // utility function to check if day is proper for month and year
   unsigned int checkDay( int ) const; 
   
}; // end class Date
#endif