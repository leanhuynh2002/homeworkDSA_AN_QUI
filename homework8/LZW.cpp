// source code: https://www.geeksforgeeks.org/lzw-lempel-ziv-welch-compression-technique/
#include "LZW.h"
using namespace std;

//-----------------------------------------------------------------

// overloading <<
ostream& operator << (ostream& os, const newUNICODE& uni)
{
	os << uni.character;
	return os;
}

// overloading >>
istream& operator >> (istream& is, newUNICODE& uni)
{
	short ptemp;
	is >> ptemp;
	uni.character = ptemp;
	return is;
}

// overloading ++
newUNICODE& operator ++(newUNICODE& uni)
{
	++uni.character;
	return uni;
}

// print newUNICODE to binary form
void convertForm(newUNICODE value)
{
	binaryForm* ptemp = (binaryForm*)&value;
	cout << int(ptemp->x9) << int(ptemp->x8) << int(ptemp->x7) << int(ptemp->x6)
		<< int(ptemp->x5) << int(ptemp->x4) << int(ptemp->x3) << int(ptemp->x2) << int(ptemp->x1);
}

//---------------------------------------------------------

// convert the input data into array of newUNICODE
vector<newUNICODE> convertArraytToVector(int n, char** str)
{
	vector<newUNICODE> arr;
	newUNICODE ptemp;
	for (int i = 0; i < n; i++) {
		ptemp = (short)atoi(str[i]);
		arr.push_back(ptemp);
	}
	return arr;
}

// print the compression ratio
// take the number of bits is 9
void printTheCompressionRatio(const int before, const int after)
{
	double ptemp = 1 - double((double(after * 9) / double(before * 8)));
	cout << setprecision(2) << fixed << ptemp * 100;
}

//--------------------------------------------------------------------

// compression
void compression(char* str)
{
	// save the UNICODE into map table
	unordered_map<string, newUNICODE> table;
	string ch;
	for (int i = 0; i <= 255; i++) {
		ch = "";
		ch += char(i);
		table[ch] = i;
	}

	string token = string(str);
	string p = "", c = "";
	// start with the first character
	p += token[0];
	int code = 256;

	vector<newUNICODE> output;
	for (int i = 0; i < token.length(); i++) {
		if (i != token.length() - 1)
			c += token[i + 1];
		// check the string
		if (table.find(p + c) != table.end()) {
			p = p + c;
		}
		else {
			// find a newUNICODE, push it into table
			output.push_back(table[p]);
			table[p + c] = code++;
			p = c;
		}
		c = "";
	}

	output.push_back(table[p]);
	//print to console the compress token to newUNICODE
	for (auto u : output) {
		cout << u << " ";
	}
	cout << endl;

	// print the binary form of newUNICODE
	for (auto u : output) {
		convertForm(u);
		cout << " ";
	}
	cout << endl;

	printTheCompressionRatio(token.length(), output.size());
}

//---------------------------------------------------------

// decompression
void decompression(int size, char** str)
{
	vector<newUNICODE> arr = convertArraytToVector(size, str);
	unordered_map<newUNICODE, string, MyHashFunction> table;

	// save the unicode into map table
	string ch;
	newUNICODE ptemp;
	for (int i = 0; i <= 255; i++) {
		ch = "";
		ch += char(i);
		ptemp = i;
		table[ptemp] = ch;
	}

	newUNICODE old = arr[0], n;
	string output;
	string s = table[old];
	string c = "";
	c += s[0];
	output += s;
	newUNICODE count;
	count = 256;

	for (int i = 0; i < arr.size() - 1; i++) {
		n = arr[i + 1];
		if (table.find(n) == table.end()) {
			s = table[old];
			s = s + c;
		}
		else {
			s = table[n];
		}
		output += s;
		c = "";
		c += s[0];
		table[count] = table[old] + c;
		++count;
		old = n;
	}
	cout << output << endl;
	printTheCompressionRatio(output.length(), arr.size());
}