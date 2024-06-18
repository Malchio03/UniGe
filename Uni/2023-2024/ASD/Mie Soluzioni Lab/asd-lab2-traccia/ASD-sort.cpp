#include <cstdlib>
#include <ctime>
#include <iostream>

#include "ASD-sort.h"

using namespace std;

/**************************************************/
/*       funzioni ausiliare                      */
/**************************************************/

/*scambia le posizione i e j in v assumendo che siano posizione correte*/
void swap_ind(vector<int>& v, int i, int j)
{ 
  int tmp = v.at(j);
  v.at(j) = v.at(i);
  v.at(i) = tmp;
}

int partition(vector<int>& v, int inizio, int fine) {
   int pivot = v.at(inizio);     // Il mio pivot è il primo elemento
   int i = inizio + 1;           // Faccio partire i dal secondo elemento
   for (int j = inizio + 1; j <= fine; ++j) {
      if (v.at(j) < pivot) {
         swap_ind(v, i, j);
         ++i;
      }
   }
   swap_ind(v, inizio, i - 1);      
   return i - 1;                 // Restituisco il penultimo elemento
}

void quickSort(vector<int>& v, int inizio, int fine) {
    if (inizio < fine) {
        int pivot = partition(v, inizio, fine);   

        // array diviso a sinistra del mediano
        quickSort(v, inizio, pivot - 1);

        // array diviso a destra del mediano
        quickSort(v, pivot + 1, fine);
    }
}

void quickSortRandom(vector<int>& v, int inizio, int fine) {
   if (inizio < fine) {

      // Scelgo un indice a caso tra inizio e fine
      int randomIndex = inizio + rand() % (fine - inizio + 1);

      // Metto il mio pivot generato all'inizio
      swap_ind(v, randomIndex, inizio);

      int pivot = partition(v, inizio, fine);

      // array diviso a sinistra del mediano
      quickSortRandom(v, inizio, pivot - 1);

      // array diviso a destra del mediano
      quickSortRandom(v, pivot + 1, fine);
   }
}

/**************************************************/
/*       funzioni da implementare                 */
/**************************************************/



/*quicksort con scelta banale del pivot*/
void quickSortTrivial(vector<int>& v){
   quickSort(v, 0, v.size() - 1);
}

/*quicksort randomizzato*/
void quickSortRandom(vector<int>& v){
   /* Implementare quickSort randomizzato con partizione in place */
   quickSortRandom(v, 0, v.size() - 1);
}


/**************************************************/
/*      funzioni implementate                     */
/**************************************************/

/* selection sort in place*/
void selectionSort(vector<int>& v){
   unsigned int current_min_index;
   unsigned int size = v.size();
   for (unsigned int i=0; i<size; ++i)
   { 
     current_min_index = i;
     for (unsigned int j=i+1;j<size; ++j){
        if (v.at(current_min_index) > v.at(j)){
            current_min_index = j;
         }
     }
     swap_ind(v, i, current_min_index);
   }
}

/* insertion sort in place*/
void insertionSort(vector<int>& v){
   unsigned int current, prev;
   unsigned int size = v.size();
   for (unsigned int i=1; i<size; ++i){ 
      current=i; 
      prev=i-1;
      while(v.at(current)<v.at(prev)){
         swap_ind(v, current, prev);
         --current;
         if(prev>0){
            --prev;
         }else{
            break;
         }
      }
   }
}

/* bubble sort in place*/
void bubbleSort(vector<int>& v){
   unsigned int size = v.size();
   bool swapped=false;
   do{
      swapped=false;
      for (unsigned int i=1; i<size; ++i){
         if(v.at(i-1)>v.at(i)){ 
            swap_ind(v,i-1,i);
            swapped = true;
         }
      }
   }while(swapped);
}

/*merge sort in place*/
void merge(vector<int>& v, unsigned int beg, unsigned int cent, unsigned int end){
   unsigned int p1=beg;
   unsigned int p2=cent;
   vector<int> mv;
   while(p1<cent && p2<end){
      if(v.at(p1)<=v.at(p2)){
         mv.push_back(v.at(p1));
         ++p1;
      }else{
         mv.push_back(v.at(p2));
         ++p2;
      }
   }
   while(p1<cent){
      mv.push_back(v.at(p1));
      ++p1; 
   }
   while(p2<end){
      mv.push_back(v.at(p2));
      ++p2; 
   }
   for(unsigned int i=0;i<mv.size();++i){
      v.at(beg+i)=mv.at(i);
   }
}

void mergeSort(vector<int>& v){
   unsigned int s=v.size();
   for(unsigned int width=1;width<s;width=2*width){
      for(unsigned int i=0;i<s;i=i+2*width){
         if(i+width<s){
            unsigned int end=(i+2*width<=s)?(i+2*width):s;
            merge(v,i,i+width,end);
         }
      }
   }
}