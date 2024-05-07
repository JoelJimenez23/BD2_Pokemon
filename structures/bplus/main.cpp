#include "bplustxt.cpp"
#include "bplusT.cpp"

int main(){


	// los indices ints y floats se pueden probar usando el enum de la clase RecordAux, como en el ejemplo 2
	// si usas cadenas de texto como indice usa la clase BplusTxt y el enum de RecordAux correspondiente al 
	// indice de tipo texto


	BplusTxt b1(RecordAux::Nombre);

	array<char, 20> nombre0 = {"a"};
	array<char, 20> nombre1 = {"b"};
	array<char, 20> nombre2 = {"c"};
	array<char, 20> nombre3 = {"d"};
	array<char, 20> nombre4 = {"e"};
	array<char, 20> nombre5 = {"f"};
	array<char, 20> nombre6 = {"g"};
	array<char, 20> nombre7 = {"h"};
	array<char, 20> nombre8 = {"i"};
	array<char, 20> nombre9 = {"j"};
	array<char, 20> nombre10 = {"k"};
	array<char, 20> nombre11 = {"l"};
	array<char, 20> nombre12 = {"m"};
	array<char, 20> nombre13 = {"n"};
	array<char, 20> nombre14 = {"o"};
	array<char, 20> nombre15 = {"p"};


    b1.add(Record(15, nombre0, 15.15, true));
    b1.add(Record(14, nombre1, 1.1, true));
    b1.add(Record(13, nombre2, 2.2, true));
    b1.add(Record(12, nombre3, 3.3, true));
    b1.add(Record(11, nombre4, 4.4, true));
    b1.add(Record(10, nombre5, 5.5, true));
    b1.add(Record(9, nombre6, 6.6, true));
    b1.add(Record(8, nombre7, 7.7, true));
    b1.add(Record(7, nombre8, 8.8, true));
	b1.add(Record(6, nombre9, 9.9, true));
    b1.add(Record(5, nombre10, 10.10, true));
    b1.add(Record(4, nombre11, 11.11, true));
    b1.add(Record(3, nombre12, 12.12, true));
    b1.add(Record(2, nombre13, 13.13, true));
    b1.add(Record(1, nombre14, 14.14, true));
    b1.add(Record(0, nombre15, 10.10, true));

	cout <<"===========INDEX=================\n\n";
	b1.printIndex();
	cout <<"\n\n==========DATA===================\n\n";
	b1.printData();
	

	cout << "\n\n\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n\n\n\n";

	Bplus<int> b2(RecordAux::Code); // float tambien valido <float>
    b2.add(Record(15, nombre0, 15.15, true));
    b2.add(Record(14, nombre1, 1.1, true));
    b2.add(Record(13, nombre2, 2.2, true));
    b2.add(Record(12, nombre3, 3.3, true));
    b2.add(Record(11, nombre4, 4.4, true));
    b2.add(Record(10, nombre5, 5.5, true));
    b2.add(Record(9, nombre6, 6.6, true));
    b2.add(Record(8, nombre7, 7.7, true));
    b2.add(Record(7, nombre8, 8.8, true));
	b2.add(Record(6, nombre9, 9.9, true));
    b2.add(Record(5, nombre10, 10.10, true));
    b2.add(Record(4, nombre11, 11.11, true));
    b2.add(Record(3, nombre12, 12.12, true));
    b2.add(Record(2, nombre13, 13.13, true));
    b2.add(Record(1, nombre14, 14.14, true));
    b2.add(Record(0, nombre15, 10.10, true));

	cout <<"===========INDEX=================\n\n";
	b2.printIndex();
	cout <<"\n\n==========DATA===================\n\n";
	b2.printData();
	
	cout << "\n\n\n\n\n\n\n\n\n";
	vector<Record> v1 = b2.rangeSearch(3,10 );
	for (auto i : v1){cout <<i;}cout << endl;
	cout << endl;
	vector<Record> v2 = b2.search(11);
	for (auto i : v2){cout <<i;}cout << endl;

	return 0;
}