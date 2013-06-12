/*
 * termino.cpp
 *
 *  Created on: 12/06/2013
 *      Author: jorge
 */
#include "termino.h"
using namespace std;

Termino::Termino(std::string& termino, std::vector<size_t>& nro_docs,
		std::vector<size_t>& off_bytes, std::vector<size_t>& off_bits) {

	this->termino = termino;
	this->nro_docs = nro_docs;
	this->off_bytes = off_bytes;
	this->off_bits = off_bits;

}
std::string& Termino::get_termino(){
	return termino;
}
std::vector<size_t>& Termino::get_docs() {
	return nro_docs;
}

std::vector<size_t>& Termino::get_off_bytes(){
	return off_bytes;
}
std::vector<size_t>& Termino::get_off_bits(){
	return off_bits;
}






ostream& operator<<(ostream& os, Termino& ter) {

	os<<"termino: "<<ter.get_termino()<<endl;
	os<<"nro de docs: ";
	for(size_t i=0;i<ter.get_docs().size();++i){
		os<<ter.get_docs()[i]<<" ";
	}
	os<<endl;
	os<<"offts bytes: ";
	for(size_t i=0;i<ter.get_off_bytes().size();++i){
		os<<ter.get_off_bytes()[i]<<" ";
	}
	os<<endl;

	os<<"offts bits: ";
	for (size_t i = 0; i < ter.get_off_bits().size(); ++i) {
		os << ter.get_off_bits()[i] << " ";
	}
	os << endl;
	return os;
}
