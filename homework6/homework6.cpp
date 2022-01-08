#include <iostream>
#include <string>
#include "Tries.h"
using namespace std;

int main()
{

    try {
        TrieNode* Dic = NULL;

        // demo function createTries
        createTrie(Dic, "HW6-dic.txt");
        
        // demo function lookUp
        string word = "friend";
        cout << "Gia tri cua tu friend : " << lookUp(Dic, word) << endl;
        // demo function remove
        Remove(Dic, word);
        cout << "Gia tri cua tu friend : " << lookUp(Dic, word) << endl;
        // demo function Insert
        Insert(Dic, "vtpt", 2000);
        cout << "Gia tri cua tu vtpt moi them vao: " << lookUp(Dic, "vtpt") << endl;

        // demo function lookUpPrefix
        do {
            cout << "Nhap prefix can tra: ";
            getline(cin, word);
            vector<string> data = lookUpPrefix(Dic, word);
            for (auto u : data) {
                cout << u << " ";
            }
            cout << "\n---------------------------------------------------\n\n";
        } while (word != "stop");

        // delete all node
        deleteTrieNode(Dic);
    }
    catch (const char* message) {
        cout << message << endl;
    }
    
    return 1;
}