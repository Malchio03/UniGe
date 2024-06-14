#include <iostream>

#include "boomerang.h"

void print(std::vector<punto> v)
{
  for(int i=0; i<v.size(); i++) std::cout << "( "<<v[i].x<<", "<<v[i].y<<" )\n";
  std::cout << "\n";
}

int main()
{
  std::vector<punto> punti1 = { { 0, 0 }, {1, 1}, {2, 0}}; int cnt1 = 1;
  std::cout << "Test 1:\n";
  print(punti1);
  std::cout<< "Risultato: "<<contaBoomerang(punti1)<< ",  atteso: "<<cnt1<<"\n\n";
  
  std::vector<punto> punti2 = { { 1, 1 }, {2, 2}, {3, 3}}; int cnt2 = 1;
  std::cout << "Test 1:\n";
  print(punti2);
  std::cout<< "Risultato: "<<contaBoomerang(punti2)<< ",  atteso: "<<cnt2<<"\n\n";
  
  std::vector<punto> punti3 = { { 1, 1 }, {2, 2}, {1, 3}, {0, 2}}; int cnt3 = 2;
  std::cout << "Test 1:\n";
  print(punti3);
  std::cout<< "Risultato: "<<contaBoomerang(punti3)<< ",  atteso: "<<cnt3<<"\n\n";
  
  std::vector<punto> punti4 = { { 1, 1 }, {1, 2}, {2, 0}, {0, 2}}; int cnt4 = 0;
  std::cout << "Test 4:\n";
  print(punti4);
  std::cout<< "Risultato: "<<contaBoomerang(punti4)<< ",  atteso: "<<cnt4<<"\n\n";
  
}
