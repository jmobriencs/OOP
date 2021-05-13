// CISP 400 Fall 2020 John-Michael O'Brien SID # w1890922
// A4 ....................................................
// Project Description (from WordDoc CISP400V10A4)
/*
This program modifies the Time class to be able to work with Date class.
This program modifies the Date class to include a Time class object as a composition,
a tick member function that increments the time stored in a Date object by one second,
and increaseADay function to increase day, month and year when it is proper.
This program tests the following cases:
-Incrementing into the next minute.
-Incrementing into the next hour.
-Incrementing into the next day (i.e., 11:59:59 PM to 12:00:00 AM).
-Incrementing into the next month and next year.
*/
// Date.h 
// Date class definition; Member functions defined in Date.cpp
// header guards
#ifndef DATE_H
#define DATE_H
#include "Time.h" // include Time class definition
class Date
{
public:
	static const unsigned int monthsPerYear = 12; // months in a year
	explicit Date(int = 1, int = 1, int = 1900, Time = Time()); // default constructor
	void print() const; // print date in month/day/year format
	void increaseADay(); // increase the day by one if data is valid
	void tick(); // increase time by one second if data is valid
	~Date(); // provided to confirm destruction order
	
private:
	unsigned int month; // 1-12 (January-December)
	unsigned int day; // 1-31 based on month
	unsigned int year; // any year

	// utility function to check if day is proper for month and year
	unsigned int checkDay(int) const;

	// Time object
	Time time;

}; // end class Date

#endif