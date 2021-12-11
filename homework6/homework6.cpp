#include <iostream>
#include <string>
#include "Tries.h"
using namespace std;

int main()
{
    TrieNode* Dic = NULL;

    try {
        createTrie(Dic, "D:\\HW6-dic.txt");
        
        string word = "das";

        while (word != "") {
            cout << "Nhap prefix can tra: ";
            getline(cin, word);
            vector<string> data = lookUpPrefix(Dic, word);
            for (auto u : data) {
                cout << u << " ";
            }
            cout << "\n---------------------------------------------------\n\n";
        }
       
        deleteTrieNode(Dic);
    }
    catch (const char* message) {
        cout << message << endl;
    }
    
    return 1;
}