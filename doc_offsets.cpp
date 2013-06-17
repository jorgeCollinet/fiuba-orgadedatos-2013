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

void Doc_offsets::add_cant_doc(size_t cant){
	unTraductor->write_delta(cant);
}

void Doc_offsets::add_num_doc(size_t doc){
	unTraductor->write_delta(doc);
}

void Doc_offsets::add_frec(size_t frec){
	unTraductor->write_delta(frec);
	// ant = 0;
}

void Doc_offsets::add_offset(size_t offset){
	// ant += offset;

	// cout << "\n pos " << ant;
	// cout << "\n dis " << (offset);
	//if((offset-ant)<0)throw ios::failure(" erooreererer");
	unTraductor->write_delta(offset);//offset-ant);
	// ant = offset;
}

