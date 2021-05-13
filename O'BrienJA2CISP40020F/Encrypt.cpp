// CISP 400 Fall 2020 John-Michael O'Brien SID # w18909822
// A2 ...................................................
// Encrypt.cpp
// Encrypt member-function definitions. This file contains
// implementations of the member functions prototyped in Encrypt.h.
#include <iostream>
#include "Encrypt.h" // include definition of class Encrypt
using namespace std;

// constructor initializes data
Encrypt::Encrypt(int data) 
{
	cout << "\n\n** The default constructor is called " << endl; // display info
	cout << "   and the passed in number is " << data << ".**" << endl; // display info with passed number

	if (data <= 0) // if statement for when data is less than or equal to zero
	{
		cout << "\n XXX The inputed number is less than or equal to 0." << endl; // display info
		cout << "     The number is reset to 9436. XXX" << endl; // display info
		data = 9436; // set data to 9436
	}
	storeData(data); // call storeData
	displayOriginalData(); // call displayOriginalData
	displayEncryptedData(); // call EncryptedData
}

// display original data function
void Encrypt::displayOriginalData() 
{
	cout << "\n     The original data is  "; // display info
	for (int i = 0; i < 4; i++) // post-increment for loop conditions
	{
		cout << digits[i] << " "; // display first four elements of private data member
	}
	cout << "\b." << endl; // display backspace and period
}

// storeData function
void Encrypt::storeData(int data) 
{
	for (int i = 3; i >= 0; i--) // post-deincrement for loop conditions
	{
		digits[i] = data % 10;   // body of loop
		data = data / 10;
	}
	for (int i = 0; i < 4; i++) // post-increment for loop conditions
	{
		int digit = digits[i];
		digits[i + 4] = (digit + 7) % 10; // read a four-digit integer and replace each digit by sum of digit plus 7 modulus 10
	}
	// Swap 1st and 3rd and 2nd and 4th encrypted digits
	int temp = digits[4];
	digits[4] = digits[6];
	digits[6] = temp;
	temp = digits[5];
	digits[5] = digits[7];
	digits[7] = temp;
}

// display encrypted data function
void Encrypt::displayEncryptedData()
{
	cout << "     The encrypted data is  "; // display info
	for (int i = 4; i < 8; i++) // post-increment for loop conditions
	{
		cout << digits[i] << " "; // display last four elements of private data member
	}
	cout << "\b." << endl; // display a backspace and period
}