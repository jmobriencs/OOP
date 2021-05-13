// CISP 400 Fall 2020 John-Michael O'Brien SID # w1890922
// A6 ...................................................
// Date.cpp
// Date class member-function definitions.
#include <array> // defines fixed size array container class
#include <string> // string types, character traits and a set of converting functions
#include <iostream> // standard input/output stream library
#include <stdexcept> // standard exceptions
#include "Date.h" // include Date class definition
using namespace std;

const string Date::allMonths[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date( int mn, int dy, int yr )
{
   month =  ( mn > 0 && mn <= monthsPerYear ) ? mn : 1; // validate the month
   year = yr; // may validate yr
   day = checkDay( dy ); // validate the day
} // end Date constructor

bool Date::operator==( const Date &operand2 ) const
{
   return ( (month == operand2.month) && (day == operand2.day) && (year == operand2.year) ) ? true : false;
}

ostream &operator<<(ostream &out, const Date &d)
{

   out << d.allMonths[d.month - 1] << " " << d.day << ", " << d.year;

   return out;
}

// utility function to confirm proper day value based on 
// month and year; handles leap years, too
unsigned int Date::checkDay( int testDay ) const
{
   static const array< int, monthsPerYear + 1 > daysPerMonth = 
      { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   // determine whether testDay is valid for specified month
   if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
   {
      return testDay;
   } // end if
   
   // February 29 check for leap year 
   if ( month == 2 && testDay == 29 && ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ) )
   {
      return testDay;
   } // end if
   
   return 1; // leave object in consistent state if bad value
} // end function checkDay