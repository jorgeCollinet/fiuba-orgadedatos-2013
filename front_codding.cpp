/*
 * frontcodding.cpp
 *
 *  Created on: 25/05/2013
 *      Author: juan
 */

#include "front_codding.h"
#include <cstring>
#define LECTURA 0
#define ESCRITURA 1
#define ERRORMODO (-1)


//using namespace std;

Front_codding::Front_codding(char* unNombreArchivo) {
	//Crea la clase y guarda el nombre del archivo a usar.
	nombreArchivo = std::string(unNombreArchivo);
	this -> cantidadPalabras = 0;
	this -> modo = ESCRITURA;
}

void Front_codding::modo_lectura(void) {
	this -> modo = LECTURA;
	this -> archivo.open(nombreArchivo.c_str(), std::fstream::in);
	if (!this->archivo.is_open()) {
		/*El archivo no se pudo crear
		Todo mal, en realidad*/
		//this -> archivo = NULL;
		return;
	}
}

void Front_codding::modo_escritura(void) {
	this -> modo = ESCRITURA;
	this -> archivo.open(nombreArchivo.c_str(), std::fstream::out);
	if (!this->archivo.is_open()) {
		/*El archivo no se pudo crear
		Todo mal, en realidad*/
		//this -> archivo = NULL;
		return;
	}
}

int Front_codding::agregar_palabra(char* unaPalabra) {
	if ( modo == LECTURA) return ERRORMODO; //no pongo el define porque por alguna razon no compila
	std::string palabra (unaPalabra);
	unsigned int i = 0;
	if (cantidadPalabras == 0) {
		// Como es la primera guardamos toda la plabra;
		archivo << unaPalabra << " ";
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
		archivo << i << " "; // Caracteres iguales
		archivo << (palabra.length() - i) << " "; // Distintos
		archivo << (unaPalabra + i) << " "; // Resto de la plabra
	}
	this -> cantidadPalabras++;
	this -> ultimaPalabra = std::string(unaPalabra);
	return 0;
}

char* Front_codding::leer_proxima_palabra(void) {
	if (modo == ESCRITURA) return NULL;
	char* palabraLeida = new char[255];
	if (cantidadPalabras == 0) {
		// Solo debo leer la palabra completa.
		archivo >> palabraLeida;
		ultimaPalabra = std::string (palabraLeida);
	} else {
		// Leo la cantidad de iguales y distintos y en base a la ultima palabra leida armo la nueva.
		int distintos, iguales;
		archivo >> iguales;
		archivo >> distintos;
		archivo >> palabraLeida;
		ultimaPalabra = ultimaPalabra.substr(0, (size_t) iguales);
		ultimaPalabra += std::string(palabraLeida);
		delete (palabraLeida);
		char* palabraLeida = new char [ultimaPalabra.length()+1];
		std::strcpy (palabraLeida, ultimaPalabra.c_str());
	}
	cantidadPalabras++;
	return palabraLeida;
	
}

Front_codding::~Front_codding() {
	archivo.close();
}

