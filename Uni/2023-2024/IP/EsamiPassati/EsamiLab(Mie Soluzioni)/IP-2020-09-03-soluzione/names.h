#ifndef _NAMES_H_
#define _NAMES_H_


#include <fstream>
#include <string>
#include <vector>

struct Name {
  std::string name;
  std::string surname;
};

std::vector<Name> readNamesFromFile(const std::string);

Name readNameFromKeyboard();
std::string toString(const Name);
void printNameList(const std::vector<Name> &);
void sortNameList(std::vector<Name> &, const std::string);
void append(std::vector<Name> &, const Name);
bool isSorted(const std::vector<Name> &, const std::string);
std::vector<std::string> unique(const std::vector<Name> &, const std::string);

#endif
