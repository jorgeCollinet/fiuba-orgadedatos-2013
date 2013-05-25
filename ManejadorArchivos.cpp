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
// Lo que lee lo guardo en micadena
//Retorna true si pudo leer una linea, o false en caso contrario
bool ManejadorArchivos::leerunalinea(std::string& micadena){

	char linea[256];

	  // lee del archivo a la linea, hasta haber leido:
	  // MAX_LENGTH caracteres, o un fin de linea
	  miarchivo.getline( (char*)&linea , 256 , '\n');
	  micadena = linea;

	  if (miarchivo.fail() ) {
	    //chequea si se ha producido un error, se devuelve false
	    miarchivo.clear();
	    return false;
	  }
	  return true;



}





