// GradeBook.cpp
// GradeBook member-function definitions. This file contains
// implementations of the member functions prototyped in GradeBook.h.
#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// constructor initializes courseName and instructorName with string supplied as arguments
GradeBook::GradeBook(string name, string insName)
{  
   cout << "\n\n *Create a GradeBook Object*\n\n"; // display program objective message
   setCourseName(name); // call set function to initialize courseName
   setInstructorName(insName); // call set function to initialize instructorName
} // end GradeBook constructor

// function to set the course name
void GradeBook::setCourseName(string name)
{
   courseName = name; // store the course name in the object
} // end function setCourseName

// function to get the course name
string GradeBook::getCourseName() const
{
   return courseName; // return object's courseName
} // end function getCourseName

// function to set the instructor name
void GradeBook::setInstructorName(string insName)
{
    instructorName = insName; // store the instructor name in the object
} // end function setInstructorName

// function to get the instructor name
string GradeBook::getInstructorName() const
{
    return instructorName; // return object's instructorName
} // end function getInstructorName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
   // call getCourseName to get the courseName
   cout << "  Welcome to the grade book for\n   " << getCourseName() << "!" << endl;
   // call getInstructorName to get the instructorName
   cout << "  This course is presented by: " << getInstructorName() << endl << endl;
} // end function displayMessage