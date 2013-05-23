/*
 * escritor_bit.cpp
 *
 *  Created on: 23/05/2013
 *      Author: jorge
 */
#include "escritor_bit.h"
using namespace std;
Escritor_bit::Escritor_bit(const char* nombre_archivo):
		arch(nombre_archivo, ofstream::binary) {
	contador = 0;
	buffer = 0;
}

bool Escritor_bit::escribir_bit_desde_abajo(unsigned int bit){
	if(bit != 0 && bit !=1){
		return false;
	}

	if(contador == 8){
		arch.write((char*)&buffer,1);
		contador = 0;
		buffer = 0;
	}
	if(bit == 1){
		unsigned char aux = 1;
		aux = aux << (contador);
		buffer = buffer | aux;
	}
	contador++;
	//arch.write((char*)&buffer,1);

	return true;
}
bool Escritor_bit::escribir_bit_desde_arriba(unsigned int bit) {
	if(bit != 0 && bit !=1){
			return false;
		}

		if(contador == 8){
			arch.write((char*)&buffer,1);
			contador = 0;
			buffer = 0;
		}
		if(bit == 1){
			unsigned char aux = 1;
			aux = aux << (7 - contador);
			buffer = buffer | aux;
		}
		contador++;
		//arch.write((char*)&buffer,1);

	return true;
}
bool Escritor_bit::cerrar_escritor(){
	if(contador>0){
		arch.write((char*)&buffer,1);
	}
	arch.close();
	return true;
}
