#include <iostream>
#include <string>
using namespace std;

bool arrayIncludedInArray(int *t1, int size1, int *t2, int size2) {
    for (int i = 0; i < size1; ++i) {
        bool found = false;
        for (int j = 0; j < size2; ++j) {
            if (*(t1 + i) == *(t2 + j)) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false; 
        }
    }
    return true; 
}

int main() {
    const int N1 = 4;
    int arr1[N1] = {1, 2, 3, 4};

    const int N2 = 6;
    int arr2[N2] = {5, 3, 1, 6, 2, 4};

    cout << boolalpha;
    cout << "Is array1 included in array2? " << arrayIncludedInArray(arr1, N1, arr2, N2) << endl;

}
