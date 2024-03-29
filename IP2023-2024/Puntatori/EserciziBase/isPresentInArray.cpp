#include <iostream>
using namespace std;

bool isPresentInArray(int *a, int size, int x) {
    for (int i = 0; i < size; ++i) {
        if (*(a + i) == x) {
            return true;
        }
    }
    return false;
}

int main() {
    const int N = 4;
    int a[N] = {1,2,3,4};
    cout << boolalpha;
    cout << isPresentInArray(a, N, 39);

}