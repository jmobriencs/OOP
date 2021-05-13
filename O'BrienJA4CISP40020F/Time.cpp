// CISP 400 Fall 2020 John-Michael O'Brien SID # w1890922
// A4 ....................................................
// Time.cpp
// Time class member-function definitions.
#include <iostream> // standard input/output stream library
#include <iomanip> // IO manipulators
#include <stdexcept> // standard exceptions
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

// Time constructor initializes each data member
Time::Time(int hour, int minute, int second)
{
    setTime(hour, minute, second); // validate and set time
    cout << "Time object constructor is called ";
    printStandard();
    cout << "\t";
    printUniversal();
    cout << "\n";
} // end Time constructor

// Time destructor displays message
Time::~Time()
{
    cout << "Time object destructor is called ";
    printStandard();
    cout << "\t";
    printUniversal();
    cout << "\n";
} // end Time destructor

// set new Time value using universal time
void Time::setTime(int h, int m, int s)
{
    setHour(h); // set private field hour
    setMinute(m); // set private field minute
    setSecond(s); // set private field second
} // end function setTime

// set hour value
void Time::setHour(int h)
{
    if (h >= 0 && h < 24) // if statement with logical operator and
        hour = h;
    else
        throw invalid_argument("hour must be 0-23"); // throw exception
} // end function setHour

// set minute value
void Time::setMinute(int m)
{
    if (m >= 0 && m < 60) // if statement with logical operator and
        minute = m;
    else
        throw invalid_argument("minute must be 0-59"); // throw exception
} // end function setMinute

// set second value
void Time::setSecond(int s)
{
    if (s >= 0 && s < 60) // if statement with logical operator and
        second = s;
    else
        throw invalid_argument("second must be 0-59"); // throw exception
} // end function setSecond

// return hour value
unsigned int Time::getHour() const
{
    return hour;
} // end function getHour

// return minute value
unsigned int Time::getMinute() const
{
    return minute;
} // end function getMinute

// return second value
unsigned int Time::getSecond() const
{
    return second;
} // end function getSecond

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() const
{
    cout << setfill('0') << setw(2) << getHour() << ":"
        << setw(2) << getMinute() << ":" << setw(2) << getSecond();
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard() const
{
    cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
        << ":" << setfill('0') << setw(2) << getMinute()
        << ":" << setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
} // end function printStandard