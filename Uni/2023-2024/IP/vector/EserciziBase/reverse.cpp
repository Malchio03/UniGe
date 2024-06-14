#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(const vector<int> &v) {
    vector<int> dest;
    for(int i = v.size() - 1; i >= 0; --i) {
        dest.push_back(v.at(i));
    }
    return dest;
}

void readVector(vector<int> &v) {
    cout << "Inserire la dimensione: ";
    int N;
    do {
        cin >> N;
        if (N < 0) {
            cout << "La dimensione deve essere positiva";
        }
    } while (N < 0);

    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v.at(i);
    }
}

void printVector(vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v.at(i) << " ";
    }
}

int main() {
    vector<int> source;
    readVector(source);
    cout << "Source: ";
    printVector(source);
    vector<int> dest = reverse(source);
    cout << endl;
    cout << "Dest: ";
    printVector(dest);
}