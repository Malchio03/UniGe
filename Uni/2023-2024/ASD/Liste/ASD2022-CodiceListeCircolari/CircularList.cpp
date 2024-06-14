#include "CircularList.h"


void headInsert(CircularList& list, DataType new_value) {
	cell* aux = new cell;
	aux->payload = new_value;
	if (list == emptyList) 
		aux->next = aux;
	else 
		{cell* tmp = list;
		 while (tmp->next != list)
			tmp = tmp->next;
		tmp->next = aux;
		aux->next = list;
		}
    
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


void printList(std::ostream& output_stream, CircularList list) {
	if (list != emptyList)
	{	
		cell* aux = list;
		while (aux->next != list) {
			writeData(output_stream, aux->payload);
			aux = aux->next;
			output_stream << std::endl;
		}
		writeData(output_stream, aux->payload);
	}
	output_stream << std::endl;
}

void readList(std::istream& input_stream, CircularList& list) {
	list = emptyList;
	DataType d;
	while (readData(input_stream, d)) {
		headInsert(list, d);
	}
}



