#include <iostream>
#include <fstream>
#include <iomanip>

#include "db.h"

using namespace std;

int main()
{
  cout << "1) Lettura file\n";
  Db mydb = leggidb();
  cout << "2) Stampa db letto da file\n";
  scrividb(mydb);
  cout << "3) Stampa db ordinato per voto\n";
  scriviindex(indsort(mydb,3));
  cout << "4) seleziona e stampa cognomi >= C\n";
  scriviindex(selectwhere(mydb,1,"C",true));
  cout << "5) seleziona e stampa nomi < R\n";
  scriviindex(selectwhere(mydb,0,"R",false));
}

bool leggirecord(std::ifstream & f, Record & r)
{
  if (!f.good()) return false;
  f>>r.nome;
  if (!f.good()) return false;
  f>>r.cognome;
  if (!f.good()) return false;
  f>>r.matricola;
  if (!f.good()) return false;
  f>>r.media;
  return f.good();
}

void scrivirecord(Record r)
{
  cout << setw(20) << left << r.cognome<<" ";
  cout << setw(20) << left << r.nome<<" ";
  cout << setw(9) << left << r.matricola<<" ";
  cout << setw(5) << right << r.media<<"\n";
}
