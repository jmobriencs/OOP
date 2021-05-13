// CISP 400 Fall 2020 John-Michael O'Brien SID # w1890922
// AD1 ..................................................
// Employee.h
// Employee class definition. This file presents Employee's public 
// interface without revealing the implementations of Employee's member
// functions, which are defined in Employee.cpp.
#include <string> // class Employee uses C++ standard string class
using namespace std;

// Employee class definition
class Employee
{
public:
	Employee(string, string, int); // constructor initializes firstName, lastName, monthlySalary
	void setFirstName(string); // sets the first name
	string getFirstName(); // gets the first name
	void setLastName(string); // sets the last name
	string getLastName(); // gets the last name
	void setMonthlySalary(int); // sets the monthly salary
	int getMonthlySalary(); // gets the monthly salary
	void increaseMonthlySalary(int); // increase monthly salary
private:
	string firstName; // firstName for employee
	string lastName; // lastName for employee
	int monthlySalary; // monthlySalary for employee
}; // end class Employee