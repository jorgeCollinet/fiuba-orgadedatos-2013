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
	ant = 0;
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
	ant = 0;
}

void Doc_offsets::add_offset(size_t offset){
	unTraductor->write_delta(offset-ant);
	ant = offset;
}

