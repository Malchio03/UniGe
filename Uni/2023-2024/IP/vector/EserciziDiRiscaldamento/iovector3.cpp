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

void selectionSort(vector<int> &v, bool ascending) {
    int index;
    for (int i = 0; i < v.size() - 1; ++i) {
        index = i;
        for (int j = i + 1; j < v.size(); ++j) {
            if ((v.at(j) < v.at(index) && ascending == true) || (v.at(j) > v.at(index) && ascending == false)) {
                index = j;
            }
        }
        if(index != i) {
            int temp = v.at(i);
            v.at(i) = v.at(index);
            v.at(index) = temp;
        }
    }
}
int main() {
    vector <int> v;
    readVectorAlt(v);
    printVector(v);
    cout << endl;
    selectionSort(v, true);
    printVector(v);
    selectionSort(v, false);
    printVector(v);
}