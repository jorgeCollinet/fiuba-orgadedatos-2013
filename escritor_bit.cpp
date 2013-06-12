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
	buffer = 255;
	//num = {254,253,251,247,239,223,191,127};
	num[0]=254;
	num[1]=253 ;
	num[2]=251 ;
	num[3]=247 ;
	num[4]=239 ;
	num[5]=223 ;
	num[6]=191 ;
	num[7]=127 ;
}


bool Escritor_bit::escribir_bit_desde_arriba(unsigned int bit) {
	if(bit != 0 && bit !=1){
			throw ios_base::failure("Escritor_bit: no se ingresó ni un 1 ni un 0");
		}

		if(contador == 8){
			arch.write((char*)&buffer,1);
			contador = 0;
			buffer = 255;
		}
		if(bit == 0){
			buffer = buffer & num[7-contador];
		}
		contador++;

	return true;
}
bool Escritor_bit::cerrar_escritor(){
	if(contador>0){
		arch.write((char*)&buffer,1);
	}
	arch.close();
	return true;
}
