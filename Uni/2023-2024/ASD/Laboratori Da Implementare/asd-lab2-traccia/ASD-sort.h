#ifndef ASD_SORT_H
#define ASD_SORT_H

#include <vector> 

/**************************************************/
/*       prototipi di funzioni da implementare    */
/**************************************************/

/*quicksort con scelta banale del pivot*/
void quickSortTrivial(std::vector<int>& v);

/*quicksort randomizzato*/
void quickSortRandom(std::vector<int>& v);


/**************************************************/
/*       prototipi di funzioni implementate       */
/**************************************************/

/* selection sort in place*/
void selectionSort(std::vector<int>& v);

/* insertion sort in place*/
void insertionSort(std::vector<int>& v);

/* bubble sort in place*/
void bubbleSort(std::vector<int>& v);

/*merge sort in place*/
void mergeSort(std::vector<int>& v);

#endif