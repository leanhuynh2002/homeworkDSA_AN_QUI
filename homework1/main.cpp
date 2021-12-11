#include <iostream>
#include <string.h>
using namespace std;

int* ConvertFile(int argc, char** argv)
{
    int* Arr = new int[argc];
    for (int i = 2; i < argc; i++) {
        Arr[i - 2] = atoi(argv[i]);
    }

    return Arr;
}

void FindValue(int* Arr, int size, int x)
{
    int Ptemp;

    if (Arr[size - 1] == x) {
        cout << size - 1 << " - " << 0 << endl;
        return;
    }
    else  {
        Ptemp = Arr[size - 1];
        Arr[size - 1] = x;
    }
    
    for (int i = 0; ; i++) {
        if (Arr[i] == x) {
            if (i == size - 1) {
                Arr[size - 1] = Ptemp;
                cout << -1 << " - " << size - 1 << endl;
                return;
            }
            else {
                cout << i + 1 << " - " << i << endl;
                Arr[size - 1] = Ptemp;
                return;
            }
        }
    }
}

int main(int argc, char** argv)
{
    int* Arr = ConvertFile(argc, argv);
    FindValue(Arr, argc - 2, atoi(argv[1]));
    if (Arr != NULL)
        delete[] Arr;
    return 1;
}