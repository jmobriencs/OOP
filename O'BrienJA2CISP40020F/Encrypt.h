// CISP 400 Fall 2020 John-Michael O'Brien SID # w18909822
// A2 ...................................................
// Encrypt.h
// Encrypt class definition. This file presents Encrypt's public
// interface without revealing the implementations of Encrypt's member
// functions, which are defined in Encrypt.cpp.
using namespace std;

// Encrypt class definition
class Encrypt 
{
private:
	int digits[8]; // 8 element array named digits
public:
	Encrypt(int); // constructor initializes data
	void displayOriginalData(); // sets the original data
	void storeData(int); // stores data
	void displayEncryptedData(); // displays encrypted data
}; // end class Encrypt