#include "Traductor.h"
#include <iostream>
#include <cmath>
#include "lector_bit.h"
#include "escritor_bit.h"

using namespace std;

traductor::traductor(const int modo,const char* arch_destino){

	this->modo= modo;

	if(modo == READ){
		reader = new LectorBit(arch_destino);
	}
	if(modo == WRITE){
		writer = new Escritor_bit(arch_destino);
	}
	if((modo !=1)&&(modo !=2)){
		cout << "Modo invalido" << endl;
		delete this;
	}

}


traductor::~traductor(){
	if(modo == READ){
		delete reader;
	}
	if(modo == WRITE){
		delete writer;
	}
}


int traductor::read_gamma(){

	if(modo == WRITE) return -2;

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
			binary=binary+(int)pow((float)2, (float)(i-1));
		}
		if(reader.eof()) return -1;
	}
	return((int)pow((double)2,(double)unary)+binary);
};


bool traductor::write_gamma(int num){

	if(modo == READ) return false;

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
	return true;
};


int traductor::read_delta(){

	if(modo == WRITE) return -2;

	int gamma = 0;
	int binary = 0;

	// decodifico la parte gamma
	gamma = (read_gamma() - 1);

	for(int i=gamma;i>0;i--){
		// decodifico la parte binaria
		if(reader.leer_bit()){
			binary=binary+(int)pow((float)2, (float)i);
		}
		if(reader.eof()) return -1;
	}
	return((int)pow((float)2,(float)gamma)+binary);
}


bool traductor::write_delta(int num,){

	if(modo == READ) return false;

	int gamma;
	int binary;
	int aux,aux2;

	// calculo los componentes
	aux = floor(log2(num));
	gamma = 1 + aux;
	binary = num - (int)pow((float)2,(float)aux);

	// escribo la parte gamma
	write_gamma(gamma);

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

	return true;
};


char traductor::read_char(){

	if(modo == WRITE) return NULL;

	char letra;
	int bin = 0;

	//leo el resto
	for(int i=7;i>=0;i--){
		// decodifico la parte binaria
		if(reader.leer_bit() == 1){
			bin=bin+(int)pow((float)2, (float)i);
		}
		if(reader.eof()) return NULL;
	}

	letra =  static_cast<char>(bin);
	return letra;
}


bool traductor::write_char(char letra){

	if(modo == READ) return false;

	int bin = static_cast<int>(letra);
	int aux;

	// escribo la parte binaria
	for(int i=7;i>=0;i--){
		aux = (int)pow((float)2, (float)(i));
		if(aux <= bin){
			writer.escribir_bit_desde_abajo(1)
			bin = bin - aux;
		}else{
			writer.escribir_bit_desde_abajo(0);
		}
	}
	return true;
}


const int traductor::mode(){
	return modo;
}
