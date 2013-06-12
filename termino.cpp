/*
 * termino.cpp
 *
 *  Created on: 12/06/2013
 *      Author: jorge
 */
#include "termino.h"
using namespace std;


Termino::Termino(std::string& termino, std::vector<std::pair <size_t,std::vector<size_t> > > docs_y_offts) {

	this->termino = termino;
	this->vector_docs = docs_y_offts;

}
std::string& Termino::get_termino(){
	return termino;
}

bool Termino::tiene_doc(size_t nro_doc){
	for(size_t i =0;i<vector_docs.size();++i){
		if(vector_docs[i].first == nro_doc){
			return true;
		}
	}
	return false;
}

size_t Termino::get_max_offset(size_t nro_doc){
	for(size_t i=0; i<vector_docs.size();++i){
		if(vector_docs[i].first == nro_doc) {
			return vector_docs[i].second[vector_docs[i].second.size()-1];
		}
	}
	throw ios_base::failure ("Termino::get_max_offset: nro de doc no encontrado para termino");
	return -1;
}

size_t Termino::get_next_offset(size_t nro_doc, size_t lugar_ant_offst) {
	for(size_t i=0; i<vector_docs.size();++i){
		if(vector_docs[i].first == nro_doc) {
			if(lugar_ant_offst+1 == vector_docs[i].second.size()){
				throw ios_base::failure ("Termino::get_next_offset: nro de offset requerido excede la cantidad de offsets");
			}
			return vector_docs[i].second[lugar_ant_offst+1];
		}
	}
	throw ios_base::failure ("Termino::get_max_offset: nro de doc no encontrado para termino");
	return -1;

}
ostream& operator<<(ostream& os, Termino& ter) {

	os << "termino: " << ter.get_termino() << endl;

	for (size_t i = 0; i < ter.vector_docs.size(); ++i) {
		os << "nro_doc: "<<ter.vector_docs[i].first <<endl;
		os << "offsets: ";
		for (size_t j = 0; j < ter.vector_docs[i].second.size(); ++j) {
			os << ter.vector_docs[i].second[j] << " ";
		}
		os << endl;
	}
	return os;
}
