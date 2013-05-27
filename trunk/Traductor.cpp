#include "Traductor.h"
#include <iostream>
#include <cmath>
#include "lector_bit.h"
#include "escritor_bit.h"

int traductor::read_gamma(LectorBit reader){

	int unary = 0;
	int binary = 0;

	// leo la parte unaria-1, corto en el primer 0
	while (reader.leer_bit()==1){
		unary++;
		if(reader.eof()) return -1;
	}

	//leo el resto
	for(int i=unary;i>0;i--){
		// decodifico la parte binaria
		if(reader.leer_bit() == 1){
			binary=binary+(int)pow((float)2, (float)i);
		}
		if(reader.eof()) return -1;
	}
	return((int)pow((float)2,(float)unary)+binary);
};


void traductor::write_gamma(int num,Escritor_bit writer){

	int unary;
	int binary;
	int aux,aux2;

	// calculo los componentes
	aux = floor(log2(num));
	unary = 1 + aux;
	binary = num - (int)pow((float)2,(float)aux);

	// escribo la parte unaria
	for(int i=1;i<unary;i++){
		writer.escribir_bit_desde_abajo(1);
	};
	writer.escribir_bit_desde_abajo(0);

	// escribo la parte binaria
	for(int i=aux;i>0;i--){
		aux2 = (int)pow ((float)2, (float)(i-1));
		if(aux2 <= binary){
			writer.escribir_bit_desde_abajo(1);
			binary = binary - aux2;
		}else{
			writer.escribir_bit_desde_abajo(0);
		}
	}
};


int traductor::read_delta(LectorBit reader){

	int gamma = 0;
	int binary = 0;

	// decodifico la parte gamma
	gamma = (this->read_gamma(reader) - 1);

	for(int i=gamma;i>0;i--){
		// decodifico la parte binaria
		if(reader.leer_bit()){
			binary=binary+(int)pow((float)2, (float)i);
		}
		if(reader.eof()) return -1;
	}
	return((int)pow((float)2,(float)gamma)+binary);
}


void traductor::write_delta(int num,Escritor_bit writer){

	int gamma;
	int binary;
	int aux,aux2;

	// calculo los componentes
	aux = floor(log2(num));
	gamma = 1 + aux;
	binary = num - (int)pow((float)2,(float)aux);

	// escribo la parte gamma
	this->write_gamma(gamma,writer);

	// escribo la parte binaria
	for(int i=aux;i>0;i--){
		aux2 = (int)pow ((float)2, (float)(i-1));
		if(aux2 <= binary){
			writer.escribir_bit_desde_abajo(1);
			binary = binary - aux2;
		}else{
			writer.escribir_bit_desde_abajo(0);
		}
	}
};
