/*
 * frontcodding.cpp
 *
 *  Created on: 25/05/2013
 *      Author: juan
 */

#include "front_codding.h"

using namespace std;

Front_codding::Front_codding(char* unNombreArchivo) {
	//Crea la clase y abre el archivo en el que se van a guardar las palabras.
	this -> archivo.open(unNombreArchivo, std::ofstream::out);
	this -> cantidadPalabras = 0;
	if (!this->archivo.is_open()) {
		/*El archivo no se pudo crear
		Todo mal, en realidad*/
		//this -> archivo = NULL;
		return;
	}
}

int Front_codding::agregar_palabra(char* unaPalabra) {
	std:string palabra (unaPalabra);
	unsigned int i = 0;
	if (cantidadPalabras == 0) {
		// Como es la primera guardamos toda la plabra;
		archivo << unaPalabra;
	} else {
		/* En este momento debemos revisar la última palabra escrita y ver cuantos de las caracteres se pueden omitir.
		 * Busco la repetición contigua máxima
		*/
		for (i=0; i < palabra.length(); i++ ) {
			if ( palabra[i] != ultimaPalabra[i] ) {
				cout << i;
				break;
			}
		}
		// Tengo la longitud de la repetición;
		archivo << i; // Caracteres iguales
		archivo << (palabra.length() - i); // Distintos
		archivo << (unaPalabra + i); // Resto de la plabra
	}
	this -> cantidadPalabras++;
	this -> ultimaPalabra = std::string(unaPalabra);
	return 0;
}

Front_codding::~Front_codding() {
	archivo.close();
}

