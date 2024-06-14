#include "CircularList.h"

int main(int argc, char* argv[])
{
// ifstream my_input("SimpleInput.txt");
// ifstream my_input("empty.txt");
// ifstream my_input("onlyOne.txt");
ifstream my_input("in-1000-ordinati.txt");

CircularList my_list = emptyList;
readList(my_input, my_list);
printList(cout, my_list);
}
