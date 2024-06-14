#ifndef _DB_H_
#define _DB_H_

#include <vector>
#include <string>

struct Record {
  std::string nome;
  std::string cognome;
  int matricola;
  float media;
};

typedef std::vector<Record> Db;

#include "dbdef"

bool leggirecord(std::ifstream & , Record &);
void scrivirecord(Record);
Db leggidb();
void scrividb(Db &);
Index indsort(Db &, int);
void scriviindex(Index);
Index selectwhere(Db &, int, std::string, bool);

#endif
