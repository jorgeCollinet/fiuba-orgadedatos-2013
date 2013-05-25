/*
 * ManejadorArchivos.cpp
 *
 *  Created on: 25/05/2013
 *      Author: pablo
 */

#include "ManejadorArchivos.h"
#include <iostream>

using namespace std;

ManejadorArchivos::ManejadorArchivos(){};


/**
  * Cierra el archivo
  */
ManejadorArchivos::~ManejadorArchivos() {
  miarchivo.close();
}

void ManejadorArchivos::abrirLectura(const std::string& miruta){


	//intenta abrir el archivo en modo lectura
	  miarchivo.open(miruta.c_str(), std::fstream::in);

	  if (!miarchivo.is_open())
	          // si no se puede abrir
	          throw std::ios_base::failure("El archivo no se abre");

	}

void ManejadorArchivos::abrirEscritura(const std::string& miruta){

	miarchivo.open(miruta.c_str(), std::fstream::in);


}



