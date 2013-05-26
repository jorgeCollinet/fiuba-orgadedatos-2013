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

using namespace std;

class Front_codding {

public:
	Front_codding(char* unNombreArchivo);
	int agregar_palabra(char* unaPalabra);
	std::string leer_proxima_palabra(void);
	~Front_codding();

private:
	fstream archivo;
	unsigned int cantidadPalabras;
	std::string ultimaPalabra;
	
};

#endif /* FRONTCODDING_H_ */
