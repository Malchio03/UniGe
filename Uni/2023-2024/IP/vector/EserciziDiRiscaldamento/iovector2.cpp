#include <iostream>
#include <vector>
#include <string>
using namespace std;

void readVectorAlt(vector<int> &v) {
    string s;
    do {
        cin >> s;
        if (s != "y") {
            try {
                int n = stoi(s);
                v.push_back(n);
            } catch (const invalid_argument& e) {
                cout << "Input invalido" << endl;
            }
        }
    }while(s != "y");
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
    readVectorAlt(v);
    printVector(v);
}