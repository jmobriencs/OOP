// CISP 400 Fall 2020 John-Michael O'Brien SID # w18909822
// A3 ....................................................
// GradeBook.h
// GradeBook class definition. This file presents GradeBook's public
// interface without revealing the implementations of GradeBook's member
// functions, which are defined in GradeBook.cpp.
#include <string>
using namespace std;

// GradeBook class definition
class GradeBook
{
public:
	explicit GradeBook(string); // initialize course name
	void initializeData(); // sets variables and arrays to 0
	void setCourseName(string); // set the course name
	string getCourseName() const; // retrieve the course name
	void displayMessage() const; // display a welcome message
	void inputGrades(); // input arbitrary number of grades from user
	void displayGradeReport() const; // display report based on user input
	void displayInputs(); // displays all the input data 4 per row
	double calculateGrade() const; // calculates gpa
	~GradeBook(); // destructor
private:
	string courseName; // course name for this GradeBook
	char letterGrades[100]; // stores all the input information
	int countGrades[6]; // stores the number of each letter grade and number of the errors input
}; // end class GradeBook