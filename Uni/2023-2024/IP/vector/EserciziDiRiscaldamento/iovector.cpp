#include <iostream>
#include <vector>
using namespace std;

void readVector(vector<int> &v) {
    cout << "Inserisci la dimensione della sequenza: ";
    int N;
    cin >> N;
    while(N < 0) {
        cout << "La dimensione deve essere positiva";
        cin >> N;
    }
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        v.push_back(val);
    }
}

void printVector(const vector<int> &v) {
    for(int i = 0; i < v.size(); ++i) {
        cout << v.at(i);
        if (i < v.size() - 1) {
            cout << ", ";
        }
    }
}
int main() {
    vector <int> v;
    readVector(v);
    printVector(v);
}