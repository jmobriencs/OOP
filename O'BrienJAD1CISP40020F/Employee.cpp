// Employee.cpp
// Employee member-function definitions. This file contains
// implementations of the member functions prototyped in Employee.h.
#include <iostream>
#include "Employee.h" // include definition of class Employee
using namespace std;

// constructor initializes firstName, lastName, and monthlySalary
Employee::Employee(string first, string last, int salary)
{
    setFirstName(first); // call set function to initialize firstName
    setLastName(last); // call set function to initialize lastName
    setMonthlySalary(salary); // call set function to initialize monthlySalary
} // end Employee constructor

// function to set the first name
void Employee::setFirstName(string first)
{
    firstName = first; // store the first name in the object
} // end function setFirstName

// function to get the first name
string Employee::getFirstName()
{
    return firstName; // return object's first name
} // end function getFirstName

// function to set the last name
void Employee::setLastName(string last)
{
    lastName = last; // store the last name in the object
} // end function setLastName

// function to get the last name
string Employee::getLastName()
{
    return lastName; // return object's last name
} // end function getLastName

// function to set the monthly salary
void Employee::setMonthlySalary(int salary)
{
    if (salary <= 0)
    {
        monthlySalary = 1000; // assigns a value to monthly salary
        cout << "\nXX Employee: " << firstName << " " << lastName << "'s inputted monthly salary is " << salary << endl; // display inputted monthly salary
        cout << "** The salary is set to $1000. **\n"; // display updated salary
    }
    else
    {
        monthlySalary = salary; // store monthlySalary in the object
    }
} // end function setMonthlySalary

// function to get monthly salary
int Employee::getMonthlySalary()
{
    return monthlySalary; // return object's monthly salary
} // end function getMonthlySalary

// function to increase monthly salary
void Employee::increaseMonthlySalary(int percent)
{
    int change = monthlySalary * percent / 100; // determine change in monthly salary
    if (percent < 0)
    {
        cout << "--- Employee: " << firstName << " " << lastName << " has a salary adjustment of " << percent << " %\n"; // display employee name and percent decrease in adjusted salary
    }
    else 
    {
        cout << "+++  Employee: " << firstName << " " << lastName << " has a salary adjustment of " << percent << " %\n"; // display employee name and percent increase in adjusted salary
    }
    cout << " The original monthly salary is $" << monthlySalary << ".\n"; // display original monthly salary
    monthlySalary += change; // update monthly salary
    cout << " The new monthly salary is $" << monthlySalary << endl << endl; //display new monthly salary
} // end function increaseMonthlySalary