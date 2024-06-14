#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

typedef int DataType;

struct cell {
	DataType payload;
	cell* next;
};

typedef cell *BasicList;

cell* const emptyList = nullptr;

/*
 * It inserts a new cell containing the new_value at the beginning of the list
 */
void headInsert(BasicList& list, DataType new_value);

/*
 * It prints on output_stream all the elements in list
 */
void printList(std::ostream& output_stream, BasicList list);

/*
* It reads values from input_stream and store them into list
* list is initialized by this function, any previous value will be lost 
*/
void readList(std::istream& input_stream, BasicList& list);

