/*
 * frontcodding.h
 *
 *  Created on: 25/05/2013
 *      Author: juan
 */

#include <iostream>
#include <fstream>
#include <string>
#ifndef FRONTCODDING_H_
#define FRONTCODDING_H_

#include "traductor.h"


using namespace std;

class Front_codding {

public:
	Front_codding(const char* unNombreArchivo);
	void modo_lectura(void);
	void modo_escritura(void);
	int agregar_palabra(const char* unaPalabra);
	string leer_proxima_palabra(void);
	~Front_codding();

private:
	Traductor* unTraductor;
	unsigned int cantidadPalabras;
	int modo;
	std::string ultimaPalabra;
	std::string nombreArchivo;
	
};

#endif /* FRONTCODDING_H_ */
