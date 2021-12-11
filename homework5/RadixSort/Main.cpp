#include <iostream>
#include "RadixSort.h"
using namespace std;


int times = 1;

int main() {
	
	FILE* fileIn = fopen("input.txt", "r");

	int k, n;
	Nref head = NULL;
	Nref tail = NULL;
	Bref buckDump = NULL;

	readInput(fileIn, k, n, head, tail);
	radixSort(k, head, tail, buckDump);
	printOutput(n, head);

	fclose(fileIn);
}