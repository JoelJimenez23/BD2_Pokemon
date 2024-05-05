#include <iostream>
#include <cstring>
#include <fstream>
using namespace std; 

const int M = 3;
//sz nodo 48


struct Record {
	int code;
    char nombre[20];
    float promedio;
    bool alto;
	Record(){}
  Record(int _code,const char* _nombre,float _promedio,bool _alto){
      code = _code;
      strcpy(nombre, _nombre);
      promedio = _promedio;
       alto = _alto;
  }
};


struct RecordAux {
    Record record;
    enum Attribute { Code, Promedio, Nombre, Alto };
    RecordAux::Attribute attr;

	RecordAux(){}
	RecordAux(Record _record,RecordAux::Attribute _attr){
		record = _record;attr = _attr;
	}
	string operator()(){
    	switch (attr) {
      	case Code:
        		return to_string(record.code);
        case Promedio:
           	return to_string(record.promedio);
        case Nombre:
					 	return record.nombre;
        case Alto:
           	return to_string(record.alto);
        default:
						cerr << "Atributo no válido" << endl;
          	exit(EXIT_FAILURE);
        }
	}
};


template<typename T>
struct Nodo {
	T index[M];
	int pointers[M+1];
	size_t size = 0;
	bool leaf = true;   
};


struct Bucket {
	Record records[M];
	int next;
	int size;
	Bucket():next(-1),size(0){}
};

