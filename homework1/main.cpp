#include <iostream>
#include <string.h>
#include <utility>
using namespace std;

// convert data from character into array
int* ConvertFile(int argc, char** argv)
{
    int* Arr = new int[argc];
    for (int i = 2; i < argc; i++) {
        Arr[i - 2] = atoi(argv[i]);
    }

    return Arr;
}

// use interpolation search
pair<int, int> FindValue(int* Arr, int size, int x)
{
    int left = 0, right = size - 1;
    int currentPos = -1;
    int count = 0;
    double val;

    while (left <= right && Arr[left] <= x && x <= Arr[right]) {
        ++count;
        // find the nearest pos
        val = (double) (x - Arr[left]) / (Arr[right] - Arr[left]);
        currentPos = left + (right - left) * val;

        if (Arr[currentPos] == x) {
            return pair<int, int>(currentPos + 1, count);
            break;
        }
        else if (Arr[currentPos] > x) {
            --right;
        }
        else {
            ++left;
        }
    }

    return pair<int, int>(-1, count);
}

int main(int argc, char** argv)
{
    int* Arr = ConvertFile(argc, argv);
    pair<int, int> result = FindValue(Arr, argc - 2, atoi(argv[1]));
    cout << result.first << " - " << result.second << endl;
    if (Arr != NULL)
        delete[] Arr;
    return 1;
}