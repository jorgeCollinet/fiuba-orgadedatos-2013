/*
 * ManejadorNombreArchivo.cpp
 *
 *  Created on: 05/06/2013
 *      Author: juan
 */

#include "ManejadorNombreArchivo.h"
#define CLASEENPRUEBA
#ifndef CLASEENPRUEBA
ManejadorNombreArchivo::ManejadorNombreArchivo() {
	nombres = new std::vector<std::string>();
}

ManejadorNombreArchivo::~ManejadorNombreArchivo() {
	// TODO Auto-generated destructor stub
	delete (nombres);
}

int ManejadorNombreArchivo::agregarNombre(std::string unNombre) {
	// Agrega un nombre y devuelve el entero que lo representa.
	if ( nombres->push_back(unNombre) )
		return nombres->size() - 1;
	else
		return -1;
}

std::string ManejadorNombreArchivo::obtenerNombre(int unEntero) {
	//Devuelve el nombre que corresponde a la posiciòn 'unEntero'
	return (*nombres)[unEntero];
}
#endif
