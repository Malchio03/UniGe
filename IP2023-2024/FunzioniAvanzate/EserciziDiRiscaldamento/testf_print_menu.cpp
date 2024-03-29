#include <iostream>
#include <string>
using namespace std;

void print_menu(string choice1, string choice2, string choice3, string choice4) {
    cout << "1" << "\t" << choice1 << endl;
    cout << "2" << "\t" << choice2 << endl;
    cout << "3" << "\t" << choice3 << endl;
    cout << "4" << "\t" << choice4 << endl;
}

int main() {
    string s1 = "Prima scelta";
    string s2 = "Seconda scelta";
    string s3 = "Terza scelta";
    string s4 = "Quarta scelta";
    print_menu(s1,s2,s3,s4);

}