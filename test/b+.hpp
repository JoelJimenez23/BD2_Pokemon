#include "usefull_structs.cpp"
#include <vector>
#include <fstream>
#include <type_traits>
#include <cstring>
#pragma once


template<typename T>
class Bplus{
public:
	typedef RecordAux::Attribute Index;
private:
	void insert_csv(string csv);
	T stoT(string value);
	Record Bin2Record(ifstream &file);
private:
	/////////INSERT///////////////////////
	void insert_root(RecordAux record,fstream &index,fstream &data,int pos);
	void root_0(RecordAux recordaux,fstream &index,fstream &data,int pos);
	void split_root(fstream& index,int pos);
	
	pair<pair<bool,bool>,pair<T,int>> insert_nodo(
			RecordAux recordaux,fstream &index,fstream &data,int pos);
	
	pair<T,int> split_nodo(fstream &index,int pos);

	pair<pair<bool,bool>,pair<T,int>> insert_bucket(
			RecordAux record,fstream &data,int pos_bucket);
	
	pair<T,int> split_bucket(fstream &data,int pos_bucket);
	/////////REMOVE////////////////////////
	///////////////////////////////////////
	/////////SEARCH////////////////////////
	/////////////////////////////////////
	/////////RANGE SEARCH////////////////
	/////////////////////////////////////
public:
	Bplus<T>(string _csv,Index _pk);
	Bplus<T>(Index _pk);
	bool add(Record record);
	bool remove(T key);
	vector<Record> search(T key);
	vector<Record> rangeSearch(T bkey,T ekey);

	void printIndex();
	void printData();

private:
	string data;
	string index;
	int root_pos;
	Index pk;
	string csv;
};



