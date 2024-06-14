#include <iostream>
#include <vector>
#include <algorithm> // per std::sort

using namespace std;

// Funzione per trovare il mediano di una sottosequenza
int findMedian(vector<int>& arr, int left, int right) {
    int n = right - left + 1;
    vector<int> temp(arr.begin() + left, arr.begin() + right + 1);
    sort(temp.begin(), temp.end());
    return temp[n / 2];
}

// Funzione di partizionamento
int partition(vector<int>& arr, int left, int right, int pivot) {
    while (left <= right) {
        while (arr[left] < pivot) left++;
        while (arr[right] > pivot) right--;
        if (left <= right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return left;
}

// Funzione ricorsiva di quicksort
void quicksort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    // Trova il mediano e usalo come pivot
    int median = findMedian(arr, left, right);
    cout << "Sottosequenza corrente: ";
    for (int i = left; i <= right; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\nMediano scelto: " << median << endl;

    int index = partition(arr, left, right, median);

    cout << "Partizionamento: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n----------------------\n";

    // Chiamate ricorsive su ciascuna partizione
    quicksort(arr, left, index - 1);
    quicksort(arr, index, right);
}

int main() {
    vector<int> arr = {5, 6, 8, 7, 9, 10, 3, 4, 2, 1};
    cout << "Sequenza iniziale: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n----------------------\n";

    quicksort(arr, 0, arr.size() - 1);

    cout << "Sequenza ordinata: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
