// CISP 400 Fall 2020 John-Michael O'Brien SID # w1890922
// A1 ...................................................
// GradeBook.h
// GradeBook class definition. This file presents GradeBook's public 
// interface without revealing the implementations of GradeBook's member
// functions, which are defined in GradeBook.cpp.
#include <string> // class GradeBook uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
   GradeBook( std::string, std::string); // constructor initializes courseName and instructorName
   void setCourseName( std::string ); // sets the course name
   std::string getCourseName() const; // gets the course name
   void setInstructorName(std::string); // sets the instructor name
   std::string getInstructorName() const; // gets the instructor name
   void displayMessage() const; // displays a welcome message
private:
   std::string courseName; // course name for this GradeBook
   std::string instructorName; // instructor name for this GradeBook
}; // end class GradeBook