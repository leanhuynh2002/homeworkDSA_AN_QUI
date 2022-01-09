#include <iostream>
#include <string.h>
#include <map>
#include <fstream>
#include <vector>
#include "LZW.h"
using namespace std;

int main(int argc, char** argv)
{
	// take the number of bits is 9
	// notice that example string: ABCDEFGHIJKLMNOPQRSTUVWXYZ has 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90
	// we see no newUNICODE has over than 255 were used and the bit before 26 * 8 and after 26 * 9 (beacause newUNICODE has number of bits is 9)
	// so that the compression ratio can be a negative number
	// and the compression ratio is the decimal round to 2
	try {
		if (argc < 2) {
			throw "Error form input data !\n";
		}

		if (strcmp(argv[1], "-c") == 0) {
			compression(argv[2]);
		}
		else if (strcmp(argv[1], "-e") == 0) {
			decompression(argc - 2, argv + 2);
		}
		else {
			throw "Error form input data !\n";
		}
	}
	catch (const char* str) {
		cout << str << endl;
	}
	return 1;
}