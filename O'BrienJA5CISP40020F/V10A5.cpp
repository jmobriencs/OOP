// CISP 400 Fall 2020 John-Michael O'Brien SID # w1890922
// A5 ...................................................
// V10A5.cpp
// Complex class test program.
#include <iostream> // standard input/output stream library
#include <cstdlib> // standard general utilities library
#include "Complex.h" // Complex class definition
using namespace std;

int main()
{
    // Instantiate 6 Complex objects
    Complex x, k, l;
    Complex y(4.3, 8.2);
    Complex z(3.3, 1.1);
    Complex m(0, 0.1);

    cin >> k; // provide k object data

    // display all object data
    cout << "\nThe existing Complex objects are:";
    cout << "\n(Performing << operator overloading.)";
    cout << "\nx: " << x << "\ny: " << y << "\nz: " << z << "\nk: " << k << "\nl: " << l << "\nm: " << m << '\n';

    // demonstrate overloading +, = and << operators
    cout << "\nPerforming +, = and << operators overloading.";
    x = y + z;
    cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n'; // display the result

    // demonstrate overloading -, = and << operators
    cout << "\nPerforming -, = and << operators overloading.";
    x = y - z;
    cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n'; // display the result

    // demonstrate overloading *, = and << operators
    cout << "\nPerforming *, = and << operators overloading.";
    x = y * z;
    cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << '\n'; // display the result

    // demonstrate overloading /, = and << operators
    cout << "\nPerforming /, = and << operators overloading.";
    x = y / z;
    cout << "\nx = y / z:\n" << x << " = " << y << " / " << z << '\n'; // display the result

    // demonstrate overloading /, = and << operators and handles division by zero situation
    cout << "\nPerforming /, = and << operators overloading with divisor is (0, 0).";
    x = y / l;
    cout << "\nx = y / l:\n" << x << " = " << y << " / " << l << '\n'; // display the result

    // demonstrate overloading /, = and << operators and handles a close division by zero situation
    cout << "\nPerforming /, = and << operators overloading with divisor is (0, 0.1).";
    x = y / m;
    cout << "\nx = y / m:\n" << x << " = " << y << " / " << m << '\n'; // display the result

    // demonstrate overloading != and << operators
    cout << "\nPerforming != and << operators overloading.\ncheck x != k\n";
    if (x != k)
        cout << x << " != " << k << '\n'; // display the result

    // demonstrate overloading =, == and << operators
    cout << "\nPerforming =, == and << operators overloading.\nassign k to x by using x=k statement.\ncheck x == k\n";
    x = k;
    if (x == k)
        cout << x << " == " << k << '\n'; // display the result

    system("pause"); // display "Press any key to continue . . . "
    return 0;
} // end main