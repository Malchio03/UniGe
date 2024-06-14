#include <iostream>
using namespace std;

void print_menu(string choice1, string choice2, string choice3, string choice4) {
    cout << "1\t" << choice1 << endl;
    cout << "2\t" << choice2 << endl;
    cout << "3\t" << choice3 << endl;
    cout << "4\t" << choice4 << endl;
}

int get_choice(int max) {
    int scelta;

    do {
        cout << "Inserisci una scelta fra 1 e " << max << endl;
        cin >> scelta;
    } while (scelta < 1 || scelta > max);

    return scelta;
}

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

int use_menu (string choice1, string choice2, string choice3, string choice4) {
    print_menu(choice1, choice2, choice3, choice4);
    int n = get_choice(4);
    print_choice(n, choice1, choice2, choice3, choice4);
    return n;
}

int main() {
    string s1 = "Prima scelta";
    string s2 = "Seconda scelta";
    string s3 = "Terza scelta";
    string s4 = "Basta!";
    
    int answer;
    do {
        answer = use_menu(s1, s2, s3, s4);
        cout << endl;
    } while (answer != 4);
}