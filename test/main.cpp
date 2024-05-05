#include "b+.cpp"

int main(){
	/*
	Bplus b1("index.dat","data.dat");
	b1.insert(Record(5));
	b1.insert(Record(10));
	b1.insert(Record(15));
	b1.insert(Record(4));
	b1.insert(Record(11));
	b1.insert(Record(9));
	b1.insert(Record(7));
	b1.insert(Record(8));
	b1.insert(Record(12));
	b1.insert(Record(13));




	cout << "\n\n\n-----------------------\n";
	b1.print_index();
	cout << "-----------------------\n";
	b1.print_data();
	cout << "\n\n\n-----------------------\n";
	b1.print_index_index(244);

*/

	//Bplus<string> b1("records.txt",RecordAux::Nombre);
	Bplus<char*> b1(RecordAux::Nombre);
	b1.add(Record(10,"Joel",1.1,true));
	cout <<"===========INDEX=================\n\n";
	b1.printIndex();
	cout <<"\n\n==========DATA===================\n\n";
	b1.printData();
	return 0;
}
