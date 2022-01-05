#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <math.h>
#include "Lib.h"
using namespace std;

//---------------------------------------------------------------------

// buile a sparse gcd table and query
vector<vector<int>> buildGCDSparseTable(vector<int> arr, int n)
{
    vector<vector<int>> lookUp(n);

    for (int i = 0; i < n; i++)
        lookUp[i].push_back(arr[i]);

    for (int j = 1; j <= log2(n); j++) {
        for (int i = 0; i <= n - (1 << j); i++) {
            lookUp[i].push_back(gcd(lookUp[i][j - 1], lookUp[i + (1 << (j - 1))][j - 1]));
        }
    }

    return lookUp;
}

int queryGCD(int L, int R, vector<vector<int>> table)
{
    checkException(L, R, table);

    int j = (int)log2(R - L + 1);

    return gcd(table[L][j], table[R - (1 << j) + 1][j]);
}

//---------------------------------------------------------

// buile a sparse min table and query
vector<vector<int>> buildMinSparseTable(vector<int> arr, int n)
{
    vector<vector<int>> lookUp(n);

    for (int i = 0; i < n; i++)
        lookUp[i].push_back(arr[i]);

    for (int j = 1; (1 << j) <= n; j++) {

        for (int i = 0; (i + (1 << j) - 1) < n; i++) {

            if (lookUp[i][j - 1] < lookUp[i + (1 << (j - 1))][j - 1])
                lookUp[i].push_back(lookUp[i][j - 1]);
            else
                lookUp[i].push_back(lookUp[i + (1 << (j - 1))][j - 1]);
        }
    }

    return lookUp;
}

int queryMin(int L, int R, vector<vector<int>>& table)
{
    checkException(L, R, table);

    int j = (int)log2(R - L + 1);

    if (table[L][j] <= table[R - (1 << j) + 1][j])
        return table[L][j];
    else
        return table[R - (1 << j) + 1][j];
}

//-----------------------------------------------------------------------

// buile a sparse max table and query
vector<vector<int>> buildMaxSparseTable(vector<int> arr, int n)
{
    vector<vector<int>> lookUp(n);

    for (int i = 0; i < n; i++)
        lookUp[i].push_back(arr[i]);

    for (int j = 1; (1 << j) <= n; j++) {

        for (int i = 0; (i + (1 << j) - 1) < n; i++) {

            if (lookUp[i][j - 1] > lookUp[i + (1 << (j - 1))][j - 1])
                lookUp[i].push_back(lookUp[i][j - 1]);
            else
                lookUp[i].push_back(lookUp[i + (1 << (j - 1))][j - 1]);
        }
    }

    return lookUp;
}

int queryMax(int L, int R, vector<vector<int>> table)
{
    checkException(L, R, table);

    int j = (int)log2(R - L + 1);

    if (table[L][j] > table[R - (1 << j) + 1][j])
        return table[L][j];

    else
        return table[R - (1 << j) + 1][j];
}

//-----------------------------------------------------------------------
// the function to make table and query all the type

void Make(List& l, int argc, char** argv)
{
	deleteSimilarNode(l, argv[2]);

	vector<int> a = ConvertFile(argc, argv);
	vector<vector<int>> arr;
	int n = a.size();

    if (strcmp(argv[3], "MIN") == 0) {
		arr = buildMinSparseTable(a, n);
	}
	else if (strcmp(argv[3], "MAX") == 0) {
		arr = buildMaxSparseTable(a, n);
	}
	else if (strcmp(argv[3], "GCD") == 0) {
		arr = buildGCDSparseTable(a, n);
	}
    
    // make new node, print and add to List
    Node* ptemp = createNode(argv[2], argv[3], arr);
    printTable(ptemp);
    addTail(l, ptemp);
    
    // save table
	writeFile(l);
}

int Query(List& l, char* name, int col, int row)
{
    // find the given node
    Node* foundNode = NULL;

    try {
        foundNode = findNode(l, name);
    }
    catch (const char* str) {
        throw str;
    }
    
    // find the type of node and do works
    if (strcmp(foundNode->type, "MIN") == 0) {
        return queryMin(col, row, foundNode->data);
    }
    else if (strcmp(foundNode->type, "MAX") == 0) {
        return queryMax(col, row, foundNode->data);
    }
    else if (strcmp(foundNode->type, "GCD") == 0) {
        return queryGCD(col, row, foundNode->data);
    }
}

//------------------------------------------------------------------------



int main(int argc, char** argv)
{
    List l;

    // load data
    readFile(l);

    // do works
    // make sparse table
    if (strcmp(argv[1], "make") == 0) {
        Make(l, argc, argv);
    }
    // query sparse table
    else if (strcmp(argv[1], "query") == 0) {
        try {
            cout << Query(l, argv[2], atoi(argv[3]), atoi(argv[4])) << endl;
        }
        catch (const char* str) {
            cout << str << endl;
        }
    }

    // delete all nodes
    deleteLinkedList(l);

    return 1;
}
