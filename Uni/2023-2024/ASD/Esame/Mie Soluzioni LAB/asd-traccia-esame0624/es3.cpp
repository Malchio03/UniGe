#include "trinary-tree.h"

using namespace std;

std::string leavesToString(const triTree& tr){
  if (tr == emptyTriTree) return "";

  string result = "";

  // caso foglia
  if (tr->child1 == emptyTriTree && tr->child2 == emptyTriTree && tr->child3 == emptyTriTree) {
    result += to_string(tr->el) + " ";
  }

  // visita ricorsiva in ordine sinistra → centro → destra
  result += leavesToString(tr->child1);
  result += leavesToString(tr->child2);
  result += leavesToString(tr->child3);

  return result;
}
