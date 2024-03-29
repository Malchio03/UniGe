#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition (int a[], int p, int r) {        // p = elemento iniziale  r = elemento finale
    int pivot = a[p];   
    int i = p - 1;  // Imposto i in posizione 0, ovvero una posizioone prima del pivot (scorro da sinistra)
    int j = r + 1;  // imposto r nella posizione successiva dell'ultimo elemento r (size del mio array, scorro da destra)
    do {
        do {
            j = j - 1;
        } while (a[j] > pivot);     // avanzo l'indice j verso sinistra finche si incontra un elemento piu piccolo o uguale al pivot
        do {
            i = i + 1;
        } while(a[i] < pivot);      // avanzo l'indice verso destra finche si incontra un elemento piu grande o uguale al pivot

       // cout << "i vale: " << i << " a[i] vale: " << a[i] << endl;
       // cout << "j vale: " << j << " a[j] vale: " << a[j] << endl;


        if (i < j) {
            swap(a[i], a[j]);           
        }
    } while(i < j);                 // si termina quando i e j si "scavalcano"

    return j;                       // si ritorna j come mediano di spaccatura del mio array (divido semplicemente in due parti e il mio j sarebbe appunto il mediano, elemento medio)
}

void quickSort(int a[], int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);     // q corrisponde al mediano j

        // array diviso a sinistra del mediano
        quickSort(a, p, q);

        // array diviso a destra del mediano
        quickSort(a, q + 1, r);
    }
}






int main() {
    int array[] = {10, 8, 3, 15, 7, 9, 13, 4, 11, 6};
    int length = 10;

    quickSort(array, 0, length - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;


}
