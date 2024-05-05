#include "usefull_structs.hpp"

ostream& operator<<(ostream& os,Record r1){
	//os << r1.code << " " << r1.nombre << " " << r1.promedio << " "
		//<< r1.alto; 
	os << r1.nombre ;
	return os;
}


template <typename T>
ostream& operator<<(ostream &os,Nodo<T> n1){
	os << "{";
	os << n1.size;
	os << " [ ";
	for (int i=0;i<M;i++){
		os << n1.index[i] << "|";
	}
	os << " ] [";
	for (int i=0;i<M+1;i++){
		os << n1.pointers[i] << "|";
	}
	os<<" ]}";
	return os;
}


ostream& operator<<(ostream &os,Bucket b1){
 
	os << "[ ";
	for(int i=0;i<M;i++){
		os << b1.records[i] << "|"; 
	}

	os << "sz: "<<b1.size << " nxt: " << b1.next << "* ]";
	return os;
}
