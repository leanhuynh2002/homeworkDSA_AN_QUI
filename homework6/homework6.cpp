#include <iostream>
#include <string>
#include "Tries.h"
using namespace std;

int main()
{

    try {
        TrieNode* Dic = NULL;

        createTrie(Dic, "HW6-dic.txt");
        
        string word = "friend";
        cout << "Gia tri cua tu friend : " << lookUp(Dic, word) << endl;
        Remove(Dic, word);
        cout << "Gia tri cua tu friend : " << lookUp(Dic, word) << endl;
        Insert(Dic, "vtpt", 2000);
        cout << "Gia tri cua tu vtpt moi them vao: " << lookUp(Dic, "vtpt") << endl;

        do {
            cout << "Nhap prefix can tra: ";
            getline(cin, word);
            vector<string> data = lookUpPrefix(Dic, word);
            for (auto u : data) {
                cout << u << " ";
            }
            cout << "\n---------------------------------------------------\n\n";
        } while (word != "stop");

        deleteTrieNode(Dic);
    }
    catch (const char* message) {
        cout << message << endl;
    }
    
    return 1;
}