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
	if(!arch.is_open()){
		throw ios_base::failure("ERROR en lectorBit: el archivo donde se tiene que leer el bit no está abierto");
	}
	if (arch.eof()) {
		return 2;
	}
	if(contador == 8){
		char buf = 2;
		arch.read(&buf,1);
		buffer=buf;
		contador = 0;
		//cout<<"lo que deberia aparecer: "<<hex<<int(buffer)<<endl;
		if(arch.eof()){
			return 2;
		}
	}
	unsigned char bit = -1;

	bit = buffer >> (7 - contador);
	bit = bit & 1;
	++contador;

	if(bit == 0){
		return 0;
	}
	if(bit == 1){
		return 1;
	}
	throw ios_base::failure("ERROR en lectorBit: Se leyó mal un bit");

	return 2;
}

double LectorBit::devolver_offset_de_byte(void) {
	int aux = arch.tellg();
	if (contador == 8) {
		//esta por cambiar de byte, devuelvo la el actual +1
		// Salvo que sea la primer lectura, el cursor aquí esta en el comienzo del archivo.
		return (aux);
	}
	return (--aux);
}

short LectorBit::devolver_offset_de_bit(void) {
	if (contador == 8) {
		//esta por cambiar de byte devuelvo 0
		return 0;
	}
	return contador;
}

bool LectorBit::avanzar_cursor(int unByte, char unBit) {
	cout << "Mirar BYte: "<<unByte<<" Mirar Bit: " << (short)unBit << endl;
	arch.seekg(0, ios::end); // Colocar el cursor al final del fichero
	if (unByte > arch.tellg()) {

		cout << "NO pude avanzar, largo total: " << arch.tellg()<<endl;
		return false;
		//Si no se puede devuelvo falso.
	}
	//Me debo posicionar en el byte, contado desde el principio.
	arch.seekg(unByte, ios::beg );
	contador=8;
	if (unBit != 0) {
		this->leer_bit();
		contador += (unBit-1); //Descarto los que no necesito
	} //Si el bit es 0 no debo descartar nada.
	//Descarto los bits que no me interesan
	return true;
}

LectorBit::~LectorBit() {
	arch.close();
}

