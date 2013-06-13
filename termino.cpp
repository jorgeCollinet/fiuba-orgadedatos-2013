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
bool Termino::antecede(Termino& termino, size_t nro_doc, size_t lugar_offset) {
	cout << "entro a anetecedeeeeeeeeeeeeeeeeeeeeeeeeee" << endl;
	size_t off_mio = this->get_offset(nro_doc, lugar_offset);
	for (size_t i = 0; i < termino.get_cant_offsets(nro_doc); ++i) {
		size_t off_otro = termino.get_offset(nro_doc, i);
		if (off_mio + 1 == off_otro) {
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

size_t Termino::get_offset(size_t nro_doc, size_t lugar_offst) {
	bool encontro=false;
	for(size_t i=0; i<vector_docs.size();++i){
		//cout<<"doc_actual: "<<vector_docs[i].first<<endl;
		//cout<<"doc_buscado: "<<nro_doc<<endl;
		if(vector_docs[i].first == nro_doc) {
			//cout<<"Entro!!"<<endl;
			//cout<<"lugar_offset: "<<lugar_offst<<endl;
			//cout<<"max_tam: "<<vector_docs[i].second.size()<<endl;
			if(lugar_offst >= (vector_docs[i].second.size())) {
				string falla("Termino::get_offset: nro de OFFSET requerido excede la cantidad de offsets");
				falla+= "lugar_offst: ";
				falla+= lugar_offst;
				falla+= "max_tam: ";
				falla+= vector_docs[i].second.size();
				throw ios_base::failure (falla.c_str());
			}
			encontro = true;
			size_t offset = vector_docs[i].second[lugar_offst];
			cout <<"get_offset devuelve "<<offset<<endl;
			return offset;
		}
	}
	cout<<"pero aparece aca"<<endl;
	if(!encontro){
		throw ios_base::failure ("Termino::get_offset: NRO DE DOCUMENTO no encontrado para termino");
	}
	return -1;

}
size_t Termino::get_cant_offsets(size_t nro_doc) {
	for(size_t i=0; i<vector_docs.size();++i){
		if(vector_docs[i].first == nro_doc) {
			return vector_docs[i].second.size();
		}
	}
	throw ios_base::failure ("Termino::get_cant_offsets: nro de doc no encontrado para termino");
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
