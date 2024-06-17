#include "dictionary.h"

using namespace dict;

//STRUCT TO BE COMPLETED
// *** NON AGGIUNGETE IL PUNTATORE AL PADRE ALLA STRUCT!!!! *** 
struct dict::bstNode {
  //TO COMPLETE
};

//Funzione da implementare
bool dict::isEmpty(const Dictionary& d){
  //TODO
}
   
//Funzione da implementare
Dictionary dict::createEmptyDict(){
  //TODO
}

//Funzione da implementare
Error dict::insertElem(const Key k, const Value v, Dictionary& d){
  //TODO
  return FAIL;
}

//Funzione da implementare
Value dict::search(const Key k, const Dictionary& d){
  //TODO
  return emptyValue;
}

//Funzione da implementare
Error dict::deleteElem(const Key k, Dictionary& d){
  //TODO
  return FAIL;
}

//Funzione da implementare
void print(const Dictionary& d) {
  //TODO
}

/****************************************************************/
/*              FUNZIONE IMPLEMENTATE                           */
/****************************************************************/
Dictionary readFromFile(string nome_file){
  ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
  if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return emptyDictionary;}  
  return readFromStream(ifs);
}

Dictionary readFromStdin(){
  cout << "\nInserire una sequenza di linee che rispettano la sintassi key: value.<enter>\nDigitare CTRL^ D per terminare l'inserimento\n";
  Dictionary d = readFromStream((std::cin));
  // Questa serve per aggirare un bug di alcune versioni attuali di glibc.
  clearerr(stdin);
  return d;
}

Dictionary readFromStream(istream& str){
  Dictionary d = emptyDictionary; 
  string key, kcopy;
  string value;
  getline (str, key, ':'); 
  getline (str, value); 
  while (!str.eof())  
    {        
      kcopy = key;
      removeBlanksAndLower(kcopy); 
      insertElem(kcopy, value, d);
      getline (str, key, ':'); 
      getline (str, value); 
    }
  str.clear();
  return d;
}
