// CISP 400 Fall 2020 John-Michael O'Brien SID # w1890922
// A4 ....................................................
// Time.h
// Time class definition; Member functions defined in Time.cpp
// header guards
#ifndef TIME_H
#define TIME_H

class Time
{
public:
	explicit Time(int = 0, int = 0, int = 0); // default constructor
	~Time(); // destructor

	// set functions
	void setTime(int, int, int); // set hour, minute, second
	void setHour(int); // set hour (after validation)
	void setMinute(int); // set minute (after validation)
	void setSecond(int); // set second (after validation)

	// get functions
	unsigned int getHour() const; // return hour
	unsigned int getMinute() const; // return minute
	unsigned int getSecond() const; // return second
	void printUniversal() const; // output time in universal-time format
	void printStandard() const; // output time in standard-time format
private:
	unsigned int hour; // 0 - 23 (24-hour clock format)
	unsigned int minute; // 0 - 59
	unsigned int second; // 0 - 59
}; // end class Time

#endif