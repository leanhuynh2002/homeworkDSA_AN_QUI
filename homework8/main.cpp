#include <iostream>
#include <string.h>
#include <map>
#include <fstream>
#include <vector>
#include "LZW.h"
using namespace std;

int main(int argc, char** argv)
{
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