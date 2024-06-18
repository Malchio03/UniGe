#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono> 

#include "ASD-sort.h"

using namespace std;

using namespace std::chrono;

/**************************************************/
/*         prototipi di funzioni ausiliare        */
/**************************************************/

/*legge un vector da un file con uno intero per riga*/
vector<int> readVectorFromFile(string);

/**************************************************/
/*               programma principale             */
/**************************************************/
int main(){
	std::cout << std::boolalpha;
	srand(time(NULL));
	string name_file;
	high_resolution_clock::time_point t1, t2;
	double duration;
	cout<<"----------------TESTING-----------------"<<endl;
	cout<<"-> Su quale file vuoi effetuare i test?"<<endl;
	cin>>name_file;
	vector<int> v_init=readVectorFromFile(name_file);
	cout<<endl;


	cout<<"------------SELECTION SORT--------------"<<endl;
	vector<int> v_sel = v_init;

	t1 = high_resolution_clock::now();
	selectionSort(v_sel);
	t2 = high_resolution_clock::now();

	duration = duration_cast<microseconds>( t2 - t1 ).count();
	cout<<endl<<"----> Durata del ordinamento: "<<duration<<endl<<endl;

	cout<<"------------INSERTION SORT--------------"<<endl;
	vector<int> v_ins = v_init;

	t1 = high_resolution_clock::now();
	insertionSort(v_ins);
	t2 = high_resolution_clock::now();

	duration = duration_cast<microseconds>( t2 - t1 ).count();
	cout<<endl<<"----> Durata del ordinamento: "<<duration<<endl<<endl;

	cout<<"-------------BUBBLE SORT----------------"<<endl;
	vector<int> v_bub = v_init;

	t1 = high_resolution_clock::now();
	bubbleSort(v_bub);
	t2 = high_resolution_clock::now();

	duration = duration_cast<microseconds>( t2 - t1 ).count();
	cout<<endl<<"----> Durata del ordinamento: "<<duration<<endl<<endl;

	cout<<"--------------MERGE SORT----------------"<<endl;
	vector<int> v_mer = v_init;

	t1 = high_resolution_clock::now();
	mergeSort(v_mer);
	t2 = high_resolution_clock::now();

	duration = duration_cast<microseconds>( t2 - t1 ).count();
	cout<<endl<<"----> Durata del ordinamento: "<<duration<<endl<<endl;

	cout<<"---------QUICK SORT TRIVIAL------------"<<endl;
	vector<int> v_qut = v_init;

	t1 = high_resolution_clock::now();
	quickSortTrivial(v_qut);
	t2 = high_resolution_clock::now();

	duration = duration_cast<microseconds>( t2 - t1 ).count();
	cout<<endl<<"----> Durata del ordinamento: "<<duration<<endl<<endl;

	cout<<"---------QUICK SORT RANDOM-------------"<<endl;
	vector<int> v_qur = v_init;

	t1 = high_resolution_clock::now();
	quickSortRandom(v_qur);
	t2 = high_resolution_clock::now();

	duration = duration_cast<microseconds>( t2 - t1 ).count();
	cout<<endl<<"----> Durata del ordinamento: "<<duration<<endl<<endl;

	cout<<"---------------------------------------"<<endl;
	cout<<"   Verifica del QUICK SORT TRIVIAL:"<<endl;
	if(v_qut!=v_ins){
		cout<<"   -> ATTENZIONE! Problema nell'implementazione!!!"<<endl;
	}else{
		cout<<"   -> Implementazione corretta!!!"<<endl;
	}
	cout<<endl;
	cout<<"   Verifica del QUICK SORT RANDOM:"<<endl;
	if(v_qur!=v_ins){
		cout<<"   -> ATTENZIONE! Problema nell'implementazione!!!"<<endl;
	}else{
		cout<<"   -> Implementazione corretta!!!"<<endl;
	}
}

/**************************************************/
/*                funzioni ausiliare              */
/**************************************************/

/*legge un vector da un file con un inter per riga*/
vector<int> readVectorFromFile(string name_file){
	ifstream infile;
	string read_data;
	vector<int> vret;

	infile.open(name_file);
	while (getline (infile,read_data)){
		if(read_data.length()>0){
			vret.push_back(stoi(read_data));
		}
	}
	return vret;
}

/*scrive un vector in un file con un intero per riga*/
void writeVectorToFile(const vector<int>& v,string name_file){
	ofstream outfile;
	outfile.open(name_file);
	for(unsigned int i=0;i<v.size();++i) outfile << v.at(i)<<endl;
	outfile.close();
}

/*stampa un	vettore di interi*/
void printVector(const vector<int>& v){
	cout<<"[";
	if(v.size()==0){
		cout<<"]"<<endl;
		return;
	}
	for(unsigned int i=0;i<v.size()-1;++i){
		cout<<v.at(i)<<",";
	}
	cout<<v.at(v.size()-1)<<"]"<<endl;
	return;
}