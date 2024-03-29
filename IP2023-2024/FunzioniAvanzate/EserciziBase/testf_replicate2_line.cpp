#include <iostream>
using namespace std;

void replicate2_line(int f, char f_c, int s, char s_c) {
    if (f > 0) {
        for (int i = 0; i < f; ++i) {
            cout << f_c;
        }
    }
    if (s > 0) {
        for (int i = 0; i < s; ++i) {
            cout << s_c;
        }
    }
    cout << endl;
}

int main() {
    replicate2_line(3, 's', 7, 'q');
}
