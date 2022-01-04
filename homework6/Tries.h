#pragma once
#ifndef TRIES_H
#define TRIES_H
#include <iostream>
#include <vector>
using namespace std;

struct TrieNode
{
	int ID = -1;
	TrieNode* next[26];
};

TrieNode* findTheEndOfWord(TrieNode* Dic, string word);

int ctoi(char symbol);

//--------------------------------------------------

void readFile(fstream& file, string& word, int& ID);

void createTrie(TrieNode*& Dic, string DicFile);

void Insert(TrieNode*& Dic, const string word, const int ID);

//-------------------------------------------------------------

void deleteTrieNode(TrieNode* Dic);

//-----------------------------------------------------------------

void findWordSamePrefix(TrieNode* Dic, string prefix, vector<string>& data);

vector<string> lookUpPrefix(TrieNode* Dic, string prefix);

//-----------------------------------------------------------------

//TrieNode* findID(TrieNode* Dic, string word, int depth = 0);

int lookUp(TrieNode* Dic, string word);

void Remove(TrieNode* Dic, string word, int depth = 0);

#endif