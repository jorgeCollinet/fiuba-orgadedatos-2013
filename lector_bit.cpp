/*
 * lector_bit.cpp
 *
 *  Created on: 21/05/2013
 *      Author: jorge
 */
#include "lector_bit.h"
using namespace std;

LectorBit::LectorBit(const char* nombre_archivo):
		arch(nombre_archivo, ifstream::binary) {
	contador = 8;
	buffer = 0;
}
bool LectorBit::eof() {
	return arch.eof();
}
unsigned int LectorBit::leer_bit() {
	if (!arch.is_open() || arch.eof()) {
		return 2;
	}

	if(contador == 8){
		char buf;
		arch.read(&buf,1);
		buffer=buf;
		contador = 0;
		//cout<<"lo que deberia aparecer: "<<hex<<int(buffer)<<endl;
	}
	unsigned char bit;

	bit = buffer >> (7 - contador);
	bit = bit & 1;
	++contador;

	if(bit == 0){
		return 0;
	}
	if(bit == 1){
		return 1;
	}
	return 2;
}
