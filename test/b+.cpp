#include "b+.hpp"

template<typename T>
Bplus<T>::Bplus(string _csv,Index _pk){
	csv = _csv;
	pk = _pk;
	if(pk == RecordAux::Code){ 
		index = "code_index.dat";
		data = "code_data.dat";
	}else if(pk == RecordAux::Nombre){
		index = "nombre_index.dat";
		data = "nombre_data.dat";
	}else if(pk == RecordAux::Promedio){
		index = "promedio_index.dat";
		data = "promedio_data.dat";
	}else if(pk == RecordAux::Alto){
		index = "alto_index.dat";
		data = "alto_data.dat";
	}
	
	ifstream datafile(data,ios::binary);
	ifstream indexfile(index,ios::binary);
	if (!datafile.is_open()){
		indexfile.close();
		ofstream index_file(index,ios::binary);
		ofstream data_file(data,ios::binary);
		
		Nodo<T> _root;
		_root.leaf = true;
		_root.size = 0;
		_root.pointers[0] = 0; // representa al primer bucket
		Bucket tmp_bucket;
		tmp_bucket.next = -1; tmp_bucket.size = 0;
		root_pos = 4;

		index_file.write(reinterpret_cast<char*>(&root_pos),sizeof(int));
		index_file.write(reinterpret_cast<char*>(&_root),sizeof(Nodo<T>));
		data_file.write(reinterpret_cast<char*>(&tmp_bucket),sizeof(Bucket));

		index_file.close();
		data_file.close();
	} 
	datafile.close(); indexfile.close();
	insert_csv(csv);

}


template<typename T>
Bplus<T>::Bplus(Index _pk){
	pk = _pk;
	if(pk == RecordAux::Code){ 
		index = "code_index.dat";
		data = "code_data.dat";
	}else if(pk == RecordAux::Nombre){
		index = "nombre_index.dat";
		data = "nombre_data.dat";
	}else if(pk == RecordAux::Promedio){
		index = "promedio_index.dat";
		data = "promedio_data.dat";
	}else if(pk == RecordAux::Alto){
		index = "alto_index.dat";
		data = "alto_data.dat";
	}
	
	ifstream datafile(data,ios::binary);
	ifstream indexfile(index,ios::binary);
	if (!datafile.is_open()){
		indexfile.close();
		ofstream index_file(index,ios::binary);
		ofstream data_file(data,ios::binary);
		
		Nodo<T> _root;
		_root.leaf = true;
		_root.size = 0;
		_root.pointers[0] = 0; // representa al primer bucket
		Bucket tmp_bucket;
		tmp_bucket.next = -1; tmp_bucket.size = 0;
		root_pos = 4;

		index_file.write(reinterpret_cast<char*>(&root_pos),sizeof(int));
		index_file.write(reinterpret_cast<char*>(&_root),sizeof(Nodo<T>));
		data_file.write(reinterpret_cast<char*>(&tmp_bucket),sizeof(Bucket));

		index_file.close();
		data_file.close();
	} 
	datafile.close(); indexfile.close();

}


template<typename T>
void Bplus<T>::printIndex(){
	Nodo<T> nodo;
	ifstream indexfile(index,ios::binary|ios::in);
	indexfile.seekg(sizeof(int));
	while(indexfile.read(reinterpret_cast<char*>(&nodo),sizeof(Nodo<T>))){
		cout << nodo << endl;
	}
	indexfile.close();
}

template<typename T>
void Bplus<T>::printData(){
	Bucket bucket;
	ifstream datafile(data,ios::binary|ios::in);
	while(datafile.read(reinterpret_cast<char*>(&bucket),sizeof(Bucket))){
		cout << bucket << endl;
	}
	datafile.close();
}

template<typename T>
T Bplus<T>::stoT(string value){
	if(is_integral_v<T>){return stoi(value);}
	else if(is_floating_point_v<T>){return stof(value);}
	else if(value == "True" || value == "TRUE" || value == "true"){
		return true;
	}
	else if(value == "False" || value == "FALSE" || value == "false"){
		return false;
	}
	return T();
}

template<>
string Bplus<string>::stoT(string value){
	return value;
}

template<>
char* Bplus<char*>::stoT(string value){
	char* tmp = value.data();
	return tmp;
}


template<typename T>
Record Bplus<T>::Bin2Record(ifstream &file){
	char a='a';
	string _code;
	string _nombre;
	string _promedio;
	string _alto;
	

	while (a != ',') {
		file.read(reinterpret_cast<char*>(&a),sizeof(a));
		if(a != ','){ _code.push_back(a); }
	}
	a = 'a';
			
	while (a != ',') {
		file.read(reinterpret_cast<char*>(&a),sizeof(a));
		if(a != ','){ _nombre.push_back(a); }
	}
	a = 'a';

			
	while (a != ',') {
		file.read(reinterpret_cast<char*>(&a),sizeof(a));
		if(a != ','){ _promedio.push_back(a); }
	}
	a = 'a';


			
	while (a != '\n') {
		if (file.eof()){ cout << 'n' ;break; }
		file.read(reinterpret_cast<char*>(&a),sizeof(a));
		_alto.push_back(a);
	}
	
	int code = stoi(_code);
	float promedio = stof(_promedio);
	const char* nombre = _nombre.data();
	bool alto;
	if (_alto == "True" || _alto == "true" || _alto == "TRUE"){alto = true;}
	else {alto = false;}
	


	return Record(code,nombre,promedio,alto);

}


template<typename T>
bool Bplus<T>::add(Record record){
	fstream indexfile(index,ios::binary|ios::in|ios::out);
	fstream datafile(data,ios::binary|ios::in|ios::out);
	RecordAux recordaux(record,pk);
	
	insert_root(recordaux,indexfile,datafile,root_pos);
	
	indexfile.close(); datafile.close();
	return true;
}

template<typename T>
void Bplus<T>::insert_root(RecordAux recordaux,fstream &index,fstream &data,int pos){
	Nodo<T> nodo;
	pair<pair<bool,bool>,pair<T,int>> request;request.first.first = false;
	index.seekg(pos);
	index.read(reinterpret_cast<char*>(&nodo),sizeof(Nodo<T>));
	
	cout << nodo << endl;
	
	if(nodo.size == 0){
		root_0(recordaux,index,data,pos);
	} else if(nodo.size != 0){
		request = insert_nodo(recordaux,index,data,pos);
	}
	index.seekg(pos);
	index.read(reinterpret_cast<char*>(&nodo), sizeof(Nodo<T>));

	cout << "RETURNING FROM ROOT_0\n";
	cout << nodo << endl;
	/*
 	 if(request.first.first == true) {
		if(request.first.second == false){
			for(int i=nodo.size-1;i>-1;i--){
				if(nodo.index[i] < request.second.first){
					nodo.index[i+1] = request.second.first;
					nodo.pointers[i+2] = request.second.second;
				} else {
					nodo.index[i+1] = nodo.index[i];
					nodo.pointers[i+2] = nodo.pointers[i+1];
				}
	 	 	}
	 	 	nodo.size += 1;
		} else if (request.first.second == true){
			Nodo<T> new_root;
			new_root.index[0] = request.second.first;
			new_root.pointers[1] = request.second.second;
			new_root.pointers[0] = pos;
			new_root.leaf = false;
			new_root.size += 1;
			index.seekg(0,ios::end);
			root_pos = index.tellg();
			index.write(reinterpret_cast<char*>(&new_root),sizeof(Nodo<T>));
		}

	}
	 if (nodo.size == M) {
	 	split_root(index,pos);	
	 }
*/


}

template<typename T>
void Bplus<T>::root_0(RecordAux recordaux,fstream &index,fstream &data,int pos){
	Nodo<T> nodo;
	Bucket bucket,bucket_prev;
	T key = stoT(recordaux());
	cout << key << endl;
	index.seekg(pos);
	data.seekg(ios::beg);
	index.read(reinterpret_cast<char*>(&nodo),sizeof(Nodo<T>));
	data.read(reinterpret_cast<char*>(&bucket),sizeof(Bucket));

	
	nodo.index[0] = key;

	nodo.size = 1;
	nodo.pointers[0] = 0;
	nodo.leaf = true;
	
	bucket.records[0] = recordaux.record;
	bucket.size = 1;
	bucket_prev.next = int(sizeof(Bucket));
	bucket.next = -1;
	cout << "BEFORE \n";
	cout << nodo << endl;

	data.seekp(0);
	data.write(reinterpret_cast<char*>(&bucket_prev),sizeof(Bucket));
	nodo.pointers[1] = data.tellp();
	data.write(reinterpret_cast<char*>(&bucket),sizeof(Bucket));
	index.seekp(pos);
	index.write(reinterpret_cast<char*>(&nodo),sizeof(Nodo<T>));
	index.flush();

	index.seekg(pos);
	index.read(reinterpret_cast<char*>(&nodo),sizeof(Nodo<T>));
	
	cout << "AFTER \n";
	cout << nodo << endl;

}

//alvaro arch linux compa

template <typename T>
pair<pair<bool,bool>,pair<T,int>> Bplus<T>::insert_nodo(
		RecordAux recordaux,fstream &index,fstream &data,int pos){
	Nodo<T> nodo;
	T key = stoT(recordaux());
	index.seekg(pos);
	index.read(reinterpret_cast<char*>(&nodo),sizeof(Nodo<T>));
	pair<pair<bool,bool>,pair<T,int>> response,request;

	int next_pos;
	for(int i=nodo.size-1;i>-1;i--){
		if(key < nodo.index[i]){
			next_pos = nodo.pointers[i];
		}else if(key > nodo.index[i]){
			next_pos = nodo.pointers[i+1];
			break;
		}
	}


	if (!nodo.leaf){
		request = insert_nodo(recordaux,index,data,next_pos);
	} else {
		request = insert_bucket(recordaux,data,next_pos);
	}


	if(request.first.first == true){
		pair<T,int> index_pointer;
		index_pointer.first = request.second.first;index_pointer.second = request.second.second;

		for(int i=nodo.size-1;i>-1;i--){
			if(nodo.index[i] < index_pointer.first){
				nodo.index[i+1] = index_pointer.first;
				nodo.pointers[i+2] = index_pointer.second;
				nodo.size +=1;
				break;
			} else{
				nodo.index[i+1] = nodo.index[i];
				nodo.pointers[i+2] = nodo.pointers[i+1];
			}
			if(nodo.index[i] > index_pointer.first && i==0){
				nodo.index[i] = index_pointer.first;
				nodo.pointers[i+1] = index_pointer.second;
				nodo.size +=1;
			}
		}
		index.seekg(pos);
		index.write(reinterpret_cast<char*>(&nodo), sizeof(Nodo<T>));
	}

	response.first.second = false;
	if(nodo.size == M){
		pair<T,int> index_pointer = split_nodo(index,pos);
		response.first.first = true; response.second = index_pointer;
		if (pos == root_pos){ 
			response.first.second = true; 
		}
	} else { 
		response.first.first = false;
	}

	return  response;
}


template<typename T>
pair<pair<bool,bool>,pair<T,int>> Bplus<T>::insert_bucket(RecordAux recordaux,fstream &data,int pos_bucket){
	Bucket bucket;
	pair<pair<bool,bool>,pair<T,int>> response; 
	response.first.first = false;
	data.seekg(pos_bucket);
	data.read(reinterpret_cast<char*>(&bucket),sizeof(Bucket));

	RecordAux tmp; tmp.attr = pk;

	if(bucket.size == 0){
		bucket.records[0] = recordaux.record;
	} else {
		for(int i=bucket.size-1;i>-1;i--){
			tmp.record = bucket.records[i];
			if(stoT(recordaux()) > stoT(tmp())){
				bucket.records[i+1] = recordaux.record;
				break;
			}
			else {
				bucket.records[i+1] = bucket.records[i]; 
			}
		}
	}
	bucket.size += 1; 

	data.seekp(pos_bucket);
	data.write(reinterpret_cast<char*>(&bucket),sizeof(Bucket));
	if (bucket.size == M){
		response.first.first = true;
		response.second = split_bucket(data,pos_bucket);
	}
	return response;
}


template<typename T>
pair<T,int> Bplus<T>::split_bucket(fstream &data,int pos_bucket){
	Bucket bucket;
	Bucket sibling;
	pair<T,int> response;
	data.seekg(pos_bucket);
	data.read(reinterpret_cast<char*>(&bucket),sizeof(Bucket));
	int midindex = bucket.size/2; //sube y se va con la mitad derecha nueva
	for(int i=midindex,j=0;i<M;i++,j++){
		sibling.records[j] = bucket.records[i];
		sibling.size += 1;
	}
	bucket.size = midindex; //reducir el size nuevo;
	data.seekp(0,ios::end);
	int bucket_next = bucket.next;
	int siblingpointer = data.tellp();
	sibling.next = bucket_next;
	bucket.next = siblingpointer;
	data.write(reinterpret_cast<char*>(&sibling),sizeof(Bucket));

	data.seekp(pos_bucket);
	data.write(reinterpret_cast<char*>(&bucket),sizeof(Bucket));
	
	RecordAux recordaux(bucket.records[midindex],pk);
	T index2insert = stoT(recordaux());
	
	response.first = index2insert;
	response.second = siblingpointer;
	return response;
}


template<typename T>
pair<T,int> Bplus<T>::split_nodo(fstream &index,int pos){
	pair<T,int> response;
	Nodo<T> nodo;
	
	index.seekg(pos);
	index.read(reinterpret_cast<char*>(&nodo), sizeof(Nodo<T>));
	
	int middle_index = nodo.size / 2;
	T middle_value = nodo.index[middle_index];
	Nodo<T> sibling;

	for(int i = middle_index + 1,j=0;i < nodo.size;i++,j++){
		sibling.index[j] = nodo.index[i];
		sibling.pointers[j] = nodo.pointers[i];
		sibling.size += 1;
		if(i == nodo.size-1){
			sibling.pointers[j+1] = nodo.pointers[i+1];
		}

	}
	nodo.size = nodo.size /2;

	index.seekg(pos);
	index.write(reinterpret_cast<char*>(&nodo),sizeof(Nodo<T>));

	index.seekp(0,ios::end);
	int ptr_index = index.tellp();
	index.write(reinterpret_cast<char*>(&sibling),sizeof(sibling));
	
	response.first = middle_value;
	response.second = ptr_index;

	return response;
}

template <typename T>
void Bplus<T>::split_root(fstream &index,int pos){
	Nodo<T> nodo;
	index.seekg(pos);
	index.read(reinterpret_cast<char*>(&nodo),sizeof(Nodo<T>));

	int middle_index = nodo.size / 2;
	T middle_value = nodo.index[middle_index];
		
	Nodo<T> sibling, new_root;
	for(int i = middle_index + 1,j=0;i < nodo.size;i++,j++){
		sibling.index[j] = nodo.index[i];
		sibling.pointers[j] = nodo.pointers[i];
		if(i == nodo.size){
			sibling.pointers[j+1] = nodo.pointers[i+1];
		}
	}
	nodo.leaf = sibling.leaf = true;
	new_root.leaf = false;

	index.seekp(ios::end);
	int ptr_index = index.tellp();
	index.write(reinterpret_cast<char*>(&sibling),sizeof(sibling));
	
	nodo.size = nodo.size/2;
	new_root.index[0] = middle_value;
	new_root.size += 1;
	new_root.pointers[0] = root_pos;
	new_root.pointers[1] = ptr_index;

	index.seekg(pos);
	index.write(reinterpret_cast<char*>(&nodo),sizeof(Nodo<T>));

	index.seekp(ios::end);
	int new_root_pos = index.tellp(); //indice del nuevo root
	index.write(reinterpret_cast<char*>(&new_root),sizeof(Nodo<T>));
		
	root_pos = new_root_pos;
	index.seekp(0); //insertar nuevo root
	index.write(reinterpret_cast<char*>(&new_root_pos),sizeof(int));		
}


template <typename T>
void Bplus<T>::insert_csv(string csv){
	ifstream file(csv,ios::binary);
	Record record;
	file.seekg(0,ios::end);
	int end = file.tellg();
	file.seekg(0);

	while(true){
		record = Bin2Record(file);
		cout << record << endl;
		add(record);
		if (file.tellg() == end){break;}

	}

	file.close();
}
