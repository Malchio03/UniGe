#include <iostream>
#include <fstream>
#include "AlbumLibrary.h"

using namespace std;

// Implementazioni funzioni per il tipo MyArray

void readAlbumLibrary(const std::string& filename, AlbumLibrary& AL) {
    ifstream albumfile(filename);
    if (!albumfile) {
        string msg = "File non trovato: " + filename;
        throw(msg);
    }
    
    string line;
    while(getline(albumfile, line)) {
        
        if(!(line.compare("")==0)) {
            Album A;
            A.performer = line;
        
            getline(albumfile, A.title);
        
            getline(albumfile, line);
            A.year = stoi(line);
        
            AL.push_back(A);
        }
    }
    
    albumfile.close();

}
void printAlbumLibrary(const AlbumLibrary& AL) {
    if(AL.size()==0) {
        cout << endl << "album_library vuota." << endl;
        return;
    }
    cout << endl;
    for(unsigned int i = 0; i < AL.size(); ++i)
        cout << "[" << i << "] " << AL[i].title << ", performed by " << AL[i].performer << " (" << AL[i].year << ")" << endl;

}

void copyAlbum(const Album& source, Album& dest) {
    dest.performer = source.performer;
    dest.title = source.title;
    dest.year = source.year;
}

bool isSorted(const AlbumLibrary& AL) {
    
    if(AL.size() == 0) return true;
    unsigned int i = 0;
    while((i < AL.size()-1 ) && ((AL[i].year < AL[i+1].year) || (AL[i].year == AL[i+1].year && AL[i].title < AL[i+1].title)))
        ++i;
    
    return(i==AL.size()-1);
}

void showMenu(string msg, const vector<string>& menu){
    cout<<endl<<msg<<endl;
    for (int i = 1; i <= menu.size(); ++i) {
        cout<<i<<'\t'<<menu.at(i-1)<<endl;
    }
}

// Gets a choice in [1,maxChoice]
int getChoice(int maxChoice){
    int choice=0;
    cin>>choice;
    while(choice<=0||choice>maxChoice){
        cout<<endl<<"Scelta non riconosciuta, riprovare: ";
        cin.clear();
        cin.ignore();
        cin>>choice;
    }
    return choice;
}

// Makes the call under test and prints its result
void printTestResult(bool res, AlbumLibrary& AL){
    
    if(res) {
        sortAlbumLibrary(AL);
        printAlbumLibrary(AL);
    } else {
        Album A;
        string aux;
        cout << endl << "Inserire titolo, interprete e anno separati da ; : ";
        cin.ignore();
        getline(cin, A.title, ';');
        getline(cin, A.performer, ';');
        cin >> A.year;
            
        insertAlbum(A, AL);
        printAlbumLibrary(AL);
        
    }
    
}

int main() {
    
    cout << endl << "Scegli il nome del file che contiene i dati da leggere: ";
    string filename;
    cin >> filename;
    
    try {
        // Per prima cosa, leggo il file per popolare il vector...
        AlbumLibrary AL;
        readAlbumLibrary(filename, AL);
        //... e ne stampo il contenuto
        printAlbumLibrary(AL);
        
        char continuing='y';
        do {
            
            vector<string> testFunChoices;
            testFunChoices.push_back("sortAlbumLibrary");
            testFunChoices.push_back("insertAlbum");
            
            cout << endl;
            showMenu("Scegli la funzione su cui vuoi eseguire il test ",testFunChoices);
            int funChoice=getChoice(testFunChoices.size());
            
            //cout<<endl<<"Il risultato di "<<((1==funChoice)?"sortAlbumLibrary e': ":"insertAlbum e': ")<<endl;
            printTestResult(1==funChoice, AL);
            
            cout<<endl<<"Vuoi continuare con altri test? ('y'/'n' default 'n')"<<endl;
            cin>>continuing;
            continuing = tolower(continuing);
            
        } while('n'!=continuing);
    } catch(string msg) {
        cout << msg << endl;
        return -1;
    }
    return 0;
    
}
