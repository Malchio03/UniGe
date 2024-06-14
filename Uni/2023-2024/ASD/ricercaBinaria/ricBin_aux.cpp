#include "ricBin.h"

extern int opcounter;

int ricercaBinariaAux(int inizio, int fine, int array[], int elem)
{
opcounter++; // conteggio il confronto inizio==fine
if (inizio>=fine)
   {
   opcounter++; // conteggio il confronto array[inizio]==elem
   if (array[inizio]==elem) return inizio;
   else return -1;
   }
  
opcounter++; // conteggio l'assegnazione mezzo = (inizio+fine)/2
int mezzo = (inizio+fine)/2;

cout << "Confronto " << elem << " con " << array[mezzo] << " in posizione " << mezzo << endl;

opcounter++; // conteggio il confronto array[mezzo]==elem 
if (array[mezzo]==elem) return mezzo;

opcounter++; // conteggio il confronto array[mezzo] > elem 
if (elem > array[mezzo]) return ricercaBinariaAux(mezzo+1,fine,array,elem); 
else return ricercaBinariaAux(inizio,mezzo-1,array,elem);
}


int ricercaBinaria(int dim, int array[], int elem)
{
opcounter=0;
return ricercaBinariaAux(0, dim-1, array, elem);
}


// La funzione letturaDaStdin aggiorna l'array
void letturaDaStdin(int dim, int a[])
{
for (int i=0; i<dim; ++i)
    {
     cout << "Inserisci elemento in posizione " << i << ": ";
     cin >> a[i];
     if (!cin) throw runtime_error("Errore nella lettura di un elemento dell'array\n");
    }
}


// La funzione letturaDaFile aggiorna l'array
void letturaDaStream(ifstream &ifs, int dim, int a[])
{
for (int i=0; i <dim; ++i) 
    {	  
     ifs >> a[i];
     if (!ifs) throw runtime_error("Errore durante la lettura di un numero da file\n");
     // cout << "[DEBUG] Il " << i << "° numero letto da file e' " << x << endl;
    };
}


void stampa(int dim, int a[])
{
for (int i=0; i <dim; ++i) 
    cout << a[i] << " ";

cout << endl;
}
