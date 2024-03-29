#include <iostream>
#include <string>
using namespace std;

void print_choice(int n, string ch1, string ch2, string ch3, string ch4) {
    cout << "\nScelta effettuata: ";

    switch(n) {
        case 1:
            cout << ch1;
            break;
        case 2:
            cout << ch2;
            break;
        case 3:
            cout << ch3;
            break;
        case 4:
            cout << ch4;
            break;
        default:
            cout << "Nessuna scelta effettuata";
    }
}

int main() {
    string s1 = "Prima scelta";
    string s2 = "Seconda scelta";
    string s3 = "Terza scelta";
    string s4 = "Quarta scelta";
    print_choice(1,s1,s2,s3,s4);
    print_choice(2,s1,s2,s3,s4);
    print_choice(3,s1,s2,s3,s4);
    print_choice(4,s1,s2,s3,s4);
    print_choice(5,s1,s2,s3,s4);

}