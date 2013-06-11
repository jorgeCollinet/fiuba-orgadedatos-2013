/*
 * doc_offsets.cpp
 *
 *  Created on: 09/06/2013
 *      Author: federico
 */

#include "doc_offsets.h"
#include "traductor.h"
#include <vector>

using namespace std;

Doc_offsets::Doc_offsets(const char* nombre) {
	unTraductor = new Traductor(WRITE,nombre);
}

Doc_offsets::~Doc_offsets() {
	delete(unTraductor);
}

void Doc_offsets::add_cant_doc(int cant){
	unTraductor->write_delta(cant);
}

void Doc_offsets::add_num_doc(int doc){
	unTraductor->write_delta(doc);
}

void Doc_offsets::add_frec(int frec){
	unTraductor->write_delta(frec);
}

void Doc_offsets::add_offsets(vector<int> offsets){

	// iterador
	int i = 0;
	int tam = offsets.size();

	int doc;

	//guardo el 1°
	int ant = offsets.at(i); i++;
	unTraductor->write_delta(ant);

	while(i<tam){
		// guardo la dist con el anterior
		doc = offsets.at(i); i++;
		unTraductor->write_delta(doc-ant);
		ant = doc;
	}
}
