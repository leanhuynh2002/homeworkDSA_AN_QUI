#pragma once
#pragma pack(1)

#ifndef LZW_H
#define LZW_H
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct newUNICODE
{
	unsigned short character : 9;
	
	newUNICODE& operator = (const short value) {
		this->character = value;
		return *this;
	}

	// overloading ==
	bool operator == (const newUNICODE& other) const
	{
		if (character == other.character) {
			return true;
		}
		else {
			return false;
		}
	}
};

class MyHashFunction {
public:

	// Use sum of lengths of first and last names
	// as hash function.
	size_t operator()(const newUNICODE& p) const
	{
		return p.character;
	}
};

typedef union
{
	newUNICODE chars;
	struct
	{
		unsigned char x1 : 1;
		unsigned char x2 : 1;
		unsigned char x3 : 1;
		unsigned char x4 : 1;
		unsigned char x5 : 1;
		unsigned char x6 : 1;
		unsigned char x7 : 1;
		unsigned char x8 : 1;
		unsigned char x9 : 1;
	};
} binaryForm;

//-----------------------------------------------------------------

// overloading <<
ostream& operator << (ostream& os, const newUNICODE& uni);

// overloading >>
istream& operator >> (istream& is, newUNICODE& uni);

newUNICODE& operator ++(newUNICODE& uni);

// convert to binary form
void convertForm(newUNICODE value);

//------------------------------------------------------------------

// convert the input data into array of newUNICODE
vector<newUNICODE> convertArraytToVector(int n, char** str);

// print the compression ratio
void printTheCompressionRatio(const int before, int const after);

//-------------------------------------------------------------------

// compression
void compression(char* str);

//---------------------------------------------------------

// decompression
void decompression(int size, char** str);

#endif