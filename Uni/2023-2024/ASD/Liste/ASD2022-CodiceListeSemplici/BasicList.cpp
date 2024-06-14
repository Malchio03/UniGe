#include "BasicList.h"


void headInsert(BasicList& list, DataType new_value) {
	cell* aux = new cell;
	aux->next = list;
	aux->payload = new_value;
	list = aux;
}

/* L'implementazione delle funzioni di lettura e scrittura è pensata per leggere da/scrivere su file qualunque; questo rende le funzioni molto potenti ma anche complesse da comprendere: la comprensione di queste funzioni non è l'obiettivo dell'esercizio! Ignoratele, assumendo che funzionino, e concentratevi solo sulla struttura dati e sull'inserimento. */
 
bool readData(std::istream& input_stream, DataType& value)
{
	string line;
	getline(input_stream, line);
	istringstream s(line);
	if (s >> value)	return true;
	return false;
}


void writeData(std::ostream& output_stream, DataType value)
{
	output_stream << value;
}


void printList(std::ostream& output_stream, BasicList list) {
	cell* aux = list;
	while (aux != emptyList) {
		writeData(output_stream, aux->payload);
		aux = aux->next;
		output_stream << std::endl;
	}
        output_stream << std::endl;
}

void readList(std::istream& input_stream, BasicList& list) {
	list = emptyList;
	DataType d;
	while (readData(input_stream, d)) {
		headInsert(list, d);
	}
}



