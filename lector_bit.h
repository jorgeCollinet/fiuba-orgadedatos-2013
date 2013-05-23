/*
 * lector_bit.h
 *
 *  Created on: 21/05/2013
 *      Author: jorge
 */

#ifndef LECTOR_BIT_H_
#define LECTOR_BIT_H_
#include <iostream>
#include <fstream>
/* clase que se encarga de la lectura de a 1 bit de un determinado archivo */
class LectorBit {
	std::ifstream arch;
	size_t contador;
	unsigned char buffer;
public:
	LectorBit(const char* nombre_archivo);
	/* Devuelve el siguiente bit leido del archivo, es decir un 0 o un 1
	 * En caso de algún error devuelve 2
	 * OJO: despues de leer un bit se tiene que comprobar que no se llegó
	 *  a fin de archivo con el metodo eof(),  ver ejemplo */
	unsigned int leer_bit();
	/* si se llegó al final del archivo devuelve true caso contrario devuelve false */
	bool eof();
};



#endif /* LECTOR_BIT_H_ */
