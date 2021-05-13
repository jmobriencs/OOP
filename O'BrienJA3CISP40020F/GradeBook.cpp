// CISP 400 Fall 2020 John-Michael O'Brien SID # w18909822
// A3 ....................................................
// GradeBook.cpp
// Member-function definitions for class GradeBook that
// uses a switch statement to count A, B, C, D and F grades.
#include <iostream>
#include <iomanip>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument;
// initializes counter data members to 0
GradeBook::GradeBook(string name) 
{
    cout << "The Grade Book Constructor is called" << endl; // display that constructor is called
    initializeData(); // sets everything to 0
    setCourseName(name); // sets course name
    displayGradeReport(); // display all data
    cout << "\n*****The end of Grade Book Constructor.*****\n\n" << endl; // display that the constructor is over
} // end GradeBook constructor

void GradeBook::initializeData() // sets all variables to 0
{
    for (int x = 0; x <= 5; x++) { // loops through entire array
        countGrades[x] = 0; // sets each array element to 0
    } // end for

    for (int x = 0; x <= 99; x++) { // loops through entire array
        letterGrades[x] = '\0'; // sets each element to null
    } // end for

    courseName = 'null'; // sets variable to null
}

// function to set the course name; limits name to 30 or fewer characters
void GradeBook::setCourseName(string name) // takes string name
{
    if (name.size() <= 30) // if name has 30 or fewer characters
        courseName = name; // store the course name in the object
    else // if name is longer than 30 characters
    { // set courseName to first 30 characters of parameter name
        courseName = name.substr(0, 30); // select first 30 characters
        cerr << "\tName: \"" << name << "\"" << endl << "\texceeds maximum length (30).\n\n"; // displays that the name is too long
        cout << "\tLimiting courseName to first 30 characters.\n" << endl // displays that name is being shortened
            << "\tWelcome to the grade book for" << endl
            << "\t" << courseName << "!\n\n" // displays the shortened name
            << "The Grade Book, " << courseName << ", contains\n\n";
    } // end if...else
} // end function setCourseName

// function to retrieve the course name
string GradeBook::getCourseName() const
{
    return courseName; // returns courseName
} // end function getCourseName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
    // this statement calls getCourseName to get the
    // name of the course this GradeBook represents
    cout << "\tWelcome to the grade book for\n\t" << getCourseName() << "!\n" // calls getCourseName
        << endl;
} // end function displayMessage

// input arbitrary number of grades from user; update grade counter
void GradeBook::inputGrades()
{
    int grade; // grade entered by user
    int i = 0; // counter to move along letterGrades array

    // display formatted prompt
    cout << "\tEnter letter grades." << endl
        << "\tOr Enter the EOF character to end input." << endl
        << "\t(Use Ctrl + D, or Ctrl + Z)" << endl;

    // loop until user types end-of-file key sequence
    while ((grade = cin.get()) != EOF)
    {
        // determine which grade was entered
        switch (grade) // switch statement nested in while
        {
        case 'A': // grade was uppercase A
        case 'a': // or lowercase a
            // display user prompt
            cout << "\n\tEnter letter grades." << endl
                << "\t-->     Or Enter the EOF character to end input." << endl
                << "\t(Use Ctrl + D, or Ctrl + Z)" << endl;
            if (grade == 'a') // if lowercase a
            {
                grade = 'A'; // change to uppercase A
            } // endif
            letterGrades[i] = grade; // set character to element in array
            i++; // increment letterGrade counter
            countGrades[0] += 1; // increment grade count of A
            break; // necessary to exit switch

        case 'B': // grade was uppercase B
        case 'b': // or lowercase b
            // display user prompt
            cout << "\n\tEnter letter grades." << endl
                << "\t-->     Or Enter the EOF character to end input." << endl
                << "\t(Use Ctrl + D, or Ctrl + Z)" << endl;
            if (grade == 'b') // if lowercase b
            {
                grade = 'B'; // change to uppercase B
            } // endif
            letterGrades[i] = grade; // set character to element in array
            i++; // increment letterGrade counter
            countGrades[1] += 1; // increment grade count of B
            break; // exit switch

        case 'C': // grade was uppercase C
        case 'c': // or lowercase c
            // display user prompt
            cout << "\n\tEnter letter grades." << endl
                << "\t-->     Or Enter the EOF character to end input." << endl
                << "\t(Use Ctrl + D, or Ctrl + Z)" << endl;
            if (grade == 'c') // if lowercase c
            {
                grade = 'C'; // change to uppercase C
            } // endif
            letterGrades[i] = grade; // set character to element in array
            i++; // increment letterGrades counter
            countGrades[2] += 1; // increment grade count of C
            break; // exit switch

        case 'D': // grade was uppercase D
        case 'd': // or lowercase d
            // display user prompt
            cout << "\n\tEnter letter grades." << endl
                << "\t-->     Or Enter the EOF character to end input." << endl
                << "\t(Use Ctrl + D, or Ctrl + Z)" << endl;
            if (grade == 'd') // if lowercase d
            {
                grade = 'D'; // change to uppercase D
            } // endif
            letterGrades[i] = grade; // set character to element in array
            i++; // increment letterGrades counter
            countGrades[3] += 1; // increment grade count of D
            break; // exit switch

        case 'F': // grade was uppercase F
        case 'f': // or lowercase f
            // display user prompt
            cout << "\n\tEnter letter grades." << endl
                << "\t-->     Or Enter the EOF character to end input." << endl
                << "\t(Use Ctrl + D, or Ctrl + Z)" << endl;
            if (grade == 'f') // if lowercase f
            {
                grade = 'F'; // change to uppercase F
            } // endif
            letterGrades[i] = grade; // set character to element in array
            i++; // increment letterGrades counter
            countGrades[4] += 1; // increment grade count of F
            break; // exit switch

        case '\n': // ignore newlines,  
        case '\t': // tabs, 
        case ' ': // and spaces in input
            break; // exit switch

        default: // catch all other characters
            cout << "\tXXXX An incorrect letter grade entered.  XXXX" << endl // display error message and reprompt user
                << "\t\"" << (char)grade << "\"" << " is not a proper letter grade.\n" << endl
                << "\tEnter letter grades." << endl
                << "\t-->     Or Enter the EOF character to end input." << endl
                << "\t(Use Ctrl + D, or Ctrl + Z)" << endl;
            letterGrades[i] = grade; // set character to elements in array
            i++; // increment letterGrades counter
            countGrades[5] += 1; // increment error count
            break; // optional; will exit switch anyway
        } // end switch
    } // end while
} // end function inputGrades

// calculates and returns the GPA
double GradeBook::calculateGrade() const
{
    double data = 0; // double to include decimal
    for (int x = 0; x <= 4; x++) // counts valid grades
    {
        data += countGrades[x]; // adds up all valid grades
    } // end for
    double x = 0;
    if (data == 0) // in case user entered no valid grades, protects against dividing by 0
    {
        data = 1; // will divide by 1
    } // end if


    x = ((countGrades[0] * 4) + (countGrades[1] * 3) + (countGrades[2] * 2) + (countGrades[3] * 1)) / data; // gives grades their value and calculates GPA

    return x; // returns GPA
} // end function GradeBook

// function to display the input data from user
void GradeBook::displayInputs()
{
    int tabCount = 0; // variable to hold tabCount

    cout << "\n\nThe data entered is listed as the following: " << endl; // display the header message

    // for looping through the total number of entered data
    for (int x = 0; x < (countGrades[0] + countGrades[1] + countGrades[2] + countGrades[3] + countGrades[4] + countGrades[5]); x++)
    {
        cout << "[" << x << "]" << " -> " << letterGrades[x] << "\t"; // display the entered data
        tabCount++; // increment tabCount
        // if tabCount is 4, create newline to format the data as a 4 in a row
        if (tabCount == 4)
        {
            tabCount = 0;
            cout << endl;
        } //end if
    } // end for
} // end function displayInputs

// display a report based on the grades entered by user
void GradeBook::displayGradeReport() const
{
    // output summary of results
    int grades = 0; // counter for # of grades entered
    int data = 0; // grades + errors
    for (int x = 0; x <= 4; x++) // loop to count grades
    {
        grades += countGrades[x]; // counts each grade
    }
    data = (grades + countGrades[5]); // total number of user entries
    cout << "\nThe total number of data entered is " << data; // tells user how many characters they input
    cout << "\nThe total number of students receive grades is " << grades; // tells user how many valid grades they entered
    cout << "\nNumber of students who received each letter grade:" // title for following list of grades
        << "\nA:" << setw(8) << countGrades[0] // display number of A grades
        << "\nB:" << setw(8) << countGrades[1] // display number of B grades
        << "\nC:" << setw(8) << countGrades[2] // display number of C grades
        << "\nD:" << setw(8) << countGrades[3] // display number of D grades
        << "\nF:" << setw(8) << countGrades[4] // display number of F grades
        << "\nError:" << setw(4) << countGrades[5] // display number of errors
        << endl << endl; // spacing

    cout << "The class average is: " << fixed << setprecision(1) << calculateGrade() << endl; // calls calculateGrade function and limits it to one decimal
} // end function displayGradeReport

// deconstructor
GradeBook::~GradeBook()
{
    cout << "\n\nDestructor is called\n" << endl; // tells user deconstructor was called
} // end deconstructor