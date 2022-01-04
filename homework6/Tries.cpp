#include "Tries.h"
#include <string>
#include <fstream>
using namespace std;

// convert character into the index of array
int ctoi(char symbol)
{
    int ptemp = ((int)symbol - 97);

    if (ptemp > 25 || ptemp < 0) {
        throw "Out of index !\n";
    }
}

// convert index of array into character
char itoc(int i)
{
    return (i + 97);
}

//---------------------------------

// load data
void readFile(fstream& file, string& word, int& ID)
{
    file >> ID;
    getline(file, word);
    word = word.substr(2, word.length());
}

// make a Trie from input data
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

// find the node contain the given word
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

// insert a word into trie
void Insert(TrieNode*& Dic, const string word, const int ID)
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

//-------------------------------------------------------------------
// delete all node
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
        // add a character into the current string
        prefix = prefix + itoc(i);
        findWordSamePrefix(Dic->next[i], prefix, data);
        // delete the character added in the current string
        prefix = prefix.substr(0, prefix.length() - 1);
    }
}

vector<string> lookUpPrefix(TrieNode* Dic, string prefix)
{
    // array save the found words
    vector<string> data;
    // find the node that contain the prefix word
    TrieNode* foundTrieNode = findTheEndOfWord(Dic, prefix);
    // find all words
    findWordSamePrefix(foundTrieNode, prefix, data);
    // return the array has found
    return data;
}

//----------------------------------------------------------------------
// find the value of word
int lookUp(TrieNode* Dic, string word)
{
    TrieNode* foundNode = findTheEndOfWord(Dic, word);
    if (foundNode == NULL) {
        return -1;
    }
    else {
        return foundNode->ID;
    }
}

//----------------------------------------------------------
// change the value of word into -1
void Remove(TrieNode* Dic, string word, int depth)
{
    TrieNode* foundNode = findTheEndOfWord(Dic, word);
    if (foundNode != NULL) {
        foundNode->ID = -1;
    }
}