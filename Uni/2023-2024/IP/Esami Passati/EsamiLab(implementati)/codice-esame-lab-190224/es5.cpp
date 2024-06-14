#include <iostream>
#include "list.h"

bool allDiffInCircList(const List l){
  if (l == nullptr) {
    return true;
  }

  Cell* cur = l;

  while (cur -> next != l) {
    Cell* succ = cur -> next;
    while(succ != l) {
      if (cur -> elem == succ -> elem) {
        return false;
      }
      succ = succ -> next;
    }
    cur = cur -> next;
  }
  return true;
}
