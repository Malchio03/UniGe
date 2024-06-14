#include "array.h"

bool ascendingSequence(const int* arr,unsigned int dim){
    for (unsigned int i = 0; i < dim; ++i) {
      for (unsigned int j = i + 1; j < dim; ++j) {
        if (arr[i] > arr[j]) {
          return false;
        }
      }
    }
    return true;
}
