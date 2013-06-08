/*
 * ManejadorNombreArchivo.cpp
 *
 *  Created on: 05/06/2013
 *      Author: juan
 */

#include "ManejadorNombreArchivo.h"
//#define CLASEENPRUEBA
#ifndef CLASEENPRUEBA
ManejadorNombreArchivo::ManejadorNombreArchivo() {
	nombres = new std::vector<std::string>();
}

ManejadorNombreArchivo::ManejadorNombreArchivo(char* unNombreArchivo) {
	nombres = new std::vector<std::string>();
	nombreArchivo = std::string (unNombreArchivo);
}

ManejadorNombreArchivo::~ManejadorNombreArchivo() {
	// TODO Auto-generated destructor stub
	delete (nombres);
}

int ManejadorNombreArchivo::agregarNombre(std::string unNombre) {
	// Agrega un nombre y devuelve el entero que lo representa.
	nombres->push_back(unNombre);
	return nombres->size() - 1;
}

std::string ManejadorNombreArchivo::obtenerNombre(int unEntero) {
	//Devuelve el nombre que corresponde a la posiciòn 'unEntero'
	return (*nombres)[unEntero];
}

bool ManejadorNombreArchivo::guardarNombres(void) {
	std::ofstream salida;
	salida.open(nombreArchivo.c_str(),std::ios::out);
	if (! salida.is_open()) return false;
	for (unsigned int i= 0 ; i< nombres->size(); i++) {
		salida << (*nombres)[i] << " ";
	}
	return true;
}
#endif
