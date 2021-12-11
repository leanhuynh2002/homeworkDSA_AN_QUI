#include "Tries.h"
#include <string>
#include <fstream>
using namespace std;

int ctoi(char symbol)
{
    int ptemp = ((int)symbol - 97);

    if (ptemp > 25 || ptemp < 0) {
        throw "Out of index !\n";
    }
}

char itoc(int i)
{
    return (i + 97);
}

//---------------------------------

void readFile(fstream& file, string& word, int& ID)
{
    file >> ID;
    getline(file, word);
    word = word.substr(2, word.length());
    cout << word << endl;
}

void createTrie(TrieNode*& Dic, string DicFile)
{
    fstream fileIn(DicFile, ios::in);
    string word;
    int ID;

    if (fileIn.fail()) {
        throw "Can't open FILE !\n";
    }

    while (!fileIn.eof()) {
        readFile(fileIn, word, ID);
        Insert(Dic, word, ID);
    }

    fileIn.close();
}

TrieNode* findTheEndOfWord(TrieNode* Dic, string word)
{
    // check the root
    if (Dic == NULL) {
        throw "Can't find the Word !\n";
    }

    TrieNode* currentNode = Dic;
    int ptemp, i;

    // find the node of the charactor 
    for (i = 0; i < word.length(); i++) {
        ptemp = ctoi(word[i]);
        if (currentNode->next[ptemp] == NULL) {
            throw "Can't find the Word !\n";
        }
        else {
            currentNode = currentNode->next[ptemp];
        }
    }

    return currentNode;
}

//---------------------------------------------------------

void Insert(TrieNode*& Dic, const string& word, const int& ID)
{
    // check the Root
    if (Dic == NULL) {
        Dic = new TrieNode();
    }

    TrieNode* currentNode = Dic;
    int i, currentIndex;

    // find the path
    for (i = 0; i < word.length() - 1; i++) {
        currentIndex = ctoi(word[i]);
        if (currentNode->next[currentIndex] == NULL) {
            currentNode->next[currentIndex] = new TrieNode();
        }
        currentNode = currentNode->next[currentIndex];
    }

    // do the last character
    currentIndex = ctoi(word[i]);
    if (currentNode->next[currentIndex] == NULL) {
        currentNode->next[currentIndex] = new TrieNode();
        currentNode = currentNode->next[currentIndex];
        currentNode->ID = ID;
    }
}

void deleteWordTrie(TrieNode*& Dic, string word)
{
    TrieNode* currentNode = findTheEndOfWord(Dic, word);
    currentNode->ID = -1;
}

void deleteTrieNode(TrieNode* Dic)
{
    if (Dic == NULL)
        return;

    // delete all children TrieNodes
    for (int i = 0; i < 26; i++) {
        deleteTrieNode(Dic->next[i]);
    }

    delete Dic;
}

//---------------------------------------------------------

void findWordSamePrefix(TrieNode* Dic, string prefix, vector<string>& data)
{
    if (Dic == NULL)
        return;

    if (Dic->ID != -1) {
        data.push_back(prefix);
    }

    for (int i = 0; i < 26; i++) {
        prefix = prefix + itoc(i);
        findWordSamePrefix(Dic->next[i], prefix, data);
        prefix = prefix.substr(0, prefix.length() - 1);
    }
}

vector<string> lookUpPrefix(TrieNode* Dic, string prefix)
{
    vector<string> data;
    TrieNode* foundTrieNode = findTheEndOfWord(Dic, prefix);
    findWordSamePrefix(foundTrieNode, prefix, data);
    return data;
}

int lookUp(TrieNode* Dic, string word, int index)
{
    if (index == word.length()) {
        return Dic->ID;
    }

    if (Dic == NULL) {
        return -1;
    }
    else {
        return lookUp(Dic->next[ctoi(word[index])], word, index + 1);
    }
}