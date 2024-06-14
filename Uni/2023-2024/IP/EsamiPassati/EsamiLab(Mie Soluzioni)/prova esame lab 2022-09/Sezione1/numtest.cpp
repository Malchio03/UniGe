#include <iostream>

#include "num.h"

void print(num * n)
{
  if(n) {
    std::cout << n->digit;
    print(n->next);
  }
}

void test(int n1, int n2)
{
  std::cout << "Test: "<<n1 << " + " <<n2 <<" ---> " << n1 + n2 << "\n";
  std::cout << "Conversione di "<< n1 << ": "; print (int2list(n1)); std::cout << "\n";
  std::cout << "Conversione di "<< n2 << ": "; print (int2list(n2)); std::cout << "\n";
  std::cout << "Risultato "<< n2 << ": ";
  print (sum(int2list(n1),int2list(n2)));
  std::cout << "\n\n";
}

int main()
{
  test(1, 2); // entrambi 1 cifra
  test(100, 221); // entrambi 3 cifre
  test(223, 12);  // n cifre diversi
  test(289, 87);  // n cifre diversi, riporto
}
