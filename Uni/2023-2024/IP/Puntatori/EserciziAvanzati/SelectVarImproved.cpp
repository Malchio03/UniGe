#include <iostream>
#include <string>

using namespace std;

char* proposeVar(string messaggio, char& a) {
    cout << messaggio;
    char answer;
    cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        return &a;
    } else {
        return nullptr;
    }
}

void printChoice(char* choice, char variable, const char* varName) {
    if (choice == &variable) {
        cout << "Hai scelto: " << varName << endl;
    }
}


char* selectVar(char& a, char& b, char& c) {
    char* p = nullptr;

    char* choicePtr;

    choicePtr = proposeVar("Scegli fra queste variabili, potrai cambiare idea in seguito e sceglierne una diversa che preferisci", a);
    if (choicePtr != nullptr) {
        p = choicePtr;
    }

    choicePtr = proposeVar("preferisci la seconda?", b);
    if (choicePtr != nullptr) {
        p = choicePtr;
    }

    choicePtr = proposeVar("preferisci la terza?", c);
    if (choicePtr != nullptr) {
        p = choicePtr;
    }

    return p;
}