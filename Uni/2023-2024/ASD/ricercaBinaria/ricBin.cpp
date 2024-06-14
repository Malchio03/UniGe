#include "ricBin.h"

int opcounter = 0;

int main()
{
try {

int dim;
char input;
ifstream ifs;

cout << "Lettura da standard input (s) o da file (f)? ";
cin >> input;
if (!cin) throw runtime_error("Errore nell'inserimento della scelta dell'input\n");

if (input=='s' || input=='S')
{
   cout << "Inserisci la dimensione dell'array: ";
   cin >> dim;
   if (!cin) throw runtime_error("Errore nell'inserimento della dimensione\n");
}
else if (input=='f' || input=='F')
{
   string nome_file;
   cout << "\nInserire il nome del file > ";
   cin >> nome_file;
   if (!cin) throw runtime_error("Errore nella lettura del nome file\n");
   ifs.open(nome_file.c_str()); // associa lo stream ifs al file il cui nome e' appena stato letto
   ifs >> dim; // per leggere da file uso ifs invece di cin; la sintassi e' la stessa della lettura da standard input, devo solo ricordare di usare ifs invece di cin
   if (!ifs) throw runtime_error("Errore nell'apertura del file\n");
   if (dim==0) throw runtime_error("Letto da file il numero 0 come dimensione dell'array: errore\n");
}
else 
{
   cout << "Carattere errato: esecuzione abortita"; 
   return 1;
}

int a[dim];

if (input=='s' || input=='S')
   letturaDaStdin(dim, a);
else
   letturaDaStream(ifs, dim, a);

stampa(dim, a);

int elem, res;
cout << "\nInserire il numero da cercare (-1 per terminare) > ";
cin >> elem;
if (!cin) throw runtime_error("Errore nella lettura del numero da cercare\n");
while (elem!=-1)
{  
   res=ricercaBinaria(dim, a, elem);
   if (res==-1) 
      cout << "\nIl numero " << elem << " non e' presente nell'array\n";
   else 
      cout << "\nIl numero " << elem << " e' presente nell'array in posizione " << res << endl;
   cout << "Le operazioni di confronto e assegnazione eseguite sono " << opcounter << endl;
   cout << "\nInserire il numero da cercare (-1 per terminare) > ";
   cin >> elem;
   if (!cin) throw runtime_error("Errore nella lettura del numero da cercare\n");
}

return 0;
     } 
catch (runtime_error &msg) 
   {cerr << "Errore a runtime: " << msg.what() << endl;} 
catch (...) 
   {cerr << "Eccezione non riconosciuta\n";}
}
