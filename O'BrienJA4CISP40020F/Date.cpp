// CISP 400 Fall 2020 John-Michael O'Brien SID # w1890922
// A4 ....................................................
// Date.cpp
// Date class member-function definitions.
#include <array> // header defines fixed size array container class
#include <iostream> // standard input/output stream library
#include <stdexcept> // standard exceptions
#include "Date.h" // include Date class definition
#include "Time.h" // include Time class definition
using namespace std;

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date(int mn, int dy, int yr, Time time)
    : time(time)
{
    if (mn > 0 && mn <= monthsPerYear) // validate the month
        month = mn;
    else
    {
        month = 1; // invalid month set to 1
        cout << "Invalid month (" << mn << ") set to 1.\n";
    } // end else

    year = yr; // could validate yr
    day = checkDay(dy); // validate the day

    // output Date object to show when its constructor is called
    cout << "Date object constructor for date ";
    print();
    cout << endl;
} // end Date constructor

// output Date object to show when its destructor is called
Date::~Date()
{
    cout << "Date object destructor is called" << endl; // display line
    print();
    cout << endl;
} // end ~Date destructor

// print Date object in form month/day/year
void Date::print() const
{
    cout << month << '/' << day << '/' << year;
    cout << "\t";
    time.printStandard();
    cout << "\t";
    time.printUniversal();
} // end function print

// increase day by 1 and will adjust data if day is not proper
void Date::increaseADay()
{
    day = checkDay(day + 1); // check if day is accurate
    if (day == 1) // if day wasn't accurate, its value is one
    {
        month = month + 1; // increase month by 1 because day went over boundary
        if (month > 0 && month >= monthsPerYear) // if month is more than 12
        {
            month = 1;
            if (month == 1) // if month was over boundary, its value is one
            {
                year = year + 1; // increment year by 1 because month went over boundary
            } // end if
        } // end if
    } // end if
} // end function increaseADay

// increases one second to the Time object of the Date class private data member
void Date::tick() // if second increased is improper, the function will adjust
{
    int tempSecond = time.getSecond(); // get current value of seconds
    if (tempSecond < 59) // if tempSecond is less than 59
    {
        tempSecond++; // increment tempSecond by 1
        time.setSecond(tempSecond); // update value
    }
    else if (tempSecond >= 59) // else if tempSecond is greater than or equal to 59
    {
        time.setSecond(0); // second to 0
        int tempMin = time.getMinute(); // get current values of minutes
        if (tempMin < 59) // if tempMin is less than 59
        {
            tempMin++; // increment tempMin by 1
            time.setMinute(tempMin); // update value
        } // end if
        else if (tempMin >= 59) // else if tempMin is greater than or equal to 59
        {
            time.setMinute(0); // minute to 0
            int tempHour = time.getHour(); // get current value of hours
            if (tempHour < 23) // if tempHour is less than 23
            {
                tempHour++; // increment tempHour by 1
                time.setHour(tempHour); // update value
            } // end if
            else if (tempHour >= 23) // else if tempHour is greater than or equal to 23
            {
                time.setHour(0); // hour to 0
                increaseADay(); // increase a day
            } // end else if
        } // end else if
    } // end if
} // end function tick

// utility function to confirm proper day value based on
// month and year; handles leap years, too
unsigned int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[monthsPerYear + 1] =
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // determine whether testDay is valid for specified month
    if (testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;
    // end if

    // February 29 check for leap year
    if (month == 2 && testDay == 29 && (year % 400 == 0 ||
        (year % 4 == 0 && year % 100 != 0)))
        return testDay;
    // end if

    cout << "day (" << testDay << ") set to 1.\n";
    return 1; // leave object in consistent state if bad value
} // end function checkDay