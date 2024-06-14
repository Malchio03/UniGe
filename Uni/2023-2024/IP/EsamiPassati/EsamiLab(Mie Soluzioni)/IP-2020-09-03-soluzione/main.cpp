#include <iostream>
#include <sstream>
#include <limits>
#include "names.h"

// legge un Name da file
bool readName(std::istream & f, Name &n)
{
  f >> n.name >> n.surname;
  return !f.fail();
}

// legge da file una intera lista nomi (std::vector di Name)
std::vector<Name> readNamesFromFile(const std::string nomefile)
{
  std::ifstream f;
  f.open(nomefile);
  if (!f.is_open()) throw "Error opening file\n";

  std::vector<Name> list;
  Name entry;
  while(readName(f, entry)) list.push_back(entry);
  f.close();
  return list;
}

int main()
{
  std::vector<Name> l;
  std::vector<std::string> u;
  
  std::string filename;
  std::cerr<<"-----Nome del file? ";
  std::cin>>filename;
  std::cout<<"-----Lettura di "<<filename<<"\n";
  try {
    l = readNamesFromFile(filename);
  }
  catch (std::string s) {
    std::cerr << "Exception reading file: "<< s<<"\n";
  }
  std::cout<<"\n-----Scrittura\n";
  printNameList(l);
  std::cout<<"\n-----Aggiungi un nome a mano\n";
  append(l,readNameFromKeyboard());
  std::cout<<"\n-----Scrittura dopo aggiunta\n";
  printNameList(l);

  std::cout<<"\n\n-----TEST DI isSorted, prima per nome e poi per cognome\n";
  std::cout<<"-----Non avendo fatto ordinamento deve restituire false\n";

  std::cout<<"\n-----isSorted per nome\n";
  if(isSorted(l,"name")) std::cout<< "Sorted by name (not ok)\n";
  else std::cout<< "Not sorted by name (OK)\n";
  std::cout<<"\n-----isSorted per cognome\n";
  if(isSorted(l,"surname")) std::cout<< "Sorted by surname (not ok)\n";
  else std::cout<< "Not sorted by surname (OK)\n";

  std::cout<<"\n\n-----TEST DI unique, prima per nome e poi per cognome\n";
  std::cout<<"-----Non avendo fatto ordinamento deve restituire vector vuoto\n";

  std::cout<<"\n-----Unique per nome\n";
  u = unique(l,"name");
  if(u.size()>0) std::cout<< "not empty (not ok)\n";
  else std::cout<< "Empty (OK)\n";

  std::cout<<"\n-----Unique per cognome\n";
  u = unique(l,"surname");
  if(u.size()>0) std::cout<< "not empty (not ok)\n";
  else std::cout<< "Empty (OK)\n";

  std::cout<<"\n\n-----TEST DI sortNameList, prima per nome e poi per cognome\n";
  std::cout<<"-----Deve stampare lista ordinata nei due modi\n";
  std::cout<<"-----Segue isSorted, nei due casi (questa volta deve restituire true) \n";

  std::cout<<"\n-----sort per nome\n";
  sortNameList(l,"name");
  printNameList(l);
  std::cout<<"\n-----isSorted per nome\n";
  if(isSorted(l,"name")) std::cout<< "Sorted by name (OK)\n";
  else std::cout<< "Not sorted by name (not ok)\n";

  std::cout<<"\n-----sort per cognome\n";
  sortNameList(l,"surname");
  printNameList(l);
  std::cout<<"\n-----isSorted per cognome\n";
  if(isSorted(l,"surname")) std::cout<< "Sorted by surname (OK)\n";
  else std::cout<< "Not sorted by surname (not ok)\n";

  std::cout<<"\n\n-----TEST DI unique, prima per cognome e poi per nome\n";
  std::cout<<"-----Deve stampare lista unica nei due modi\n";

  std::cout<<"\n-----unique per cognome\n";
  u = unique(l,"surname");
  for(int i=0;i<u.size(); i++) std::cout<<u[i]<<"\n";
  std::cout<<"\n-----unique per nome\n";
  sortNameList(l,"name");
  u = unique(l,"name");
  for(int i=0;i<u.size(); i++) std::cout<<u[i]<<"\n";
  std::cout<<"\n-----FINE TEST SUITE\n";

}
