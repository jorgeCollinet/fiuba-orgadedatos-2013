/*
 * frontcodding.cpp
 *
 *  Created on: 25/05/2013
 *      Author: juan
 */

#include "front_codding.h"
#include <cstring>
#define LECTURA 1
#define ESCRITURA 2
#define ERRORMODO (-1)
#define ERROR (-2)
#define CERO (100) //se define por la imposibilidad de guardar el 0 en gamma


//using namespace std;

Front_codding::Front_codding(const char* unNombreArchivo) {
	//Crea la clase y guarda el nombre del archivo a usar.
	nombreArchivo = std::string(unNombreArchivo);
	this -> cantidadPalabras = 0;
	this -> modo = ESCRITURA;
	unTraductor = NULL;
}

void Front_codding::modo_lectura(void) {
	this -> modo = LECTURA;
	this -> unTraductor = new Traductor(LECTURA, nombreArchivo.c_str());
}

void Front_codding::modo_escritura(void) {
	this -> modo = ESCRITURA;
	this -> unTraductor = new Traductor(ESCRITURA, nombreArchivo.c_str());
}

int Front_codding::agregar_palabra(const char* unaPalabra) {
	if ( modo == LECTURA) return ERRORMODO;
	std::string palabra (unaPalabra);
	unsigned int i = 0;
	if (cantidadPalabras == 0) {
		// Como es la primera guardamos toda la plabra;
		if (!unTraductor -> write_gamma(CERO)) return ERROR;
		if (!unTraductor -> write_gamma(palabra.length())) return ERROR;
		if (!unTraductor -> write_string(palabra)) return ERROR;
	} else {
		/* En este momento debemos revisar la última palabra escrita y ver cuantos de las caracteres se pueden omitir.
		 * Busco la repetición contigua máxima
		*/
		for (i=0; i < palabra.length(); i++ ) {
			if ( palabra[i] != ultimaPalabra[i] ) {
				//cout << i;
				break;
			}
		}
		// Tengo la longitud de la repetición;
		if (i == 0) unTraductor -> write_gamma(CERO);
		else unTraductor -> write_gamma(i);
		unTraductor -> write_gamma(palabra.length() - i);
		unTraductor -> write_string(palabra.substr(i, palabra.length()));
	}
	this -> cantidadPalabras++;
	this -> ultimaPalabra = std::string(unaPalabra);
	return 0;
}

std::string Front_codding::leer_proxima_palabra(void) {
	if (modo == ESCRITURA) return NULL;
	std::string palabra, palabraDist;
	// Leo la cantidad de iguales y distintos y en base a la ultima palabra leida armo la nueva.
	int distintos, iguales;
	iguales = unTraductor -> read_gamma();
	if (iguales == CERO) iguales = 0;
	distintos = unTraductor -> read_gamma();
	for (int j = 0; j < distintos; j++) {
		char aux = unTraductor->read_char();
		if (aux == '~') return std::string("ErrorLectura");
		palabraDist += aux;
	}
	if ( cantidadPalabras == 0 ) {
		ultimaPalabra = palabraDist;
	} else {
		if (iguales == 1) {
			palabra = ultimaPalabra[0];
		} else if (iguales == 0) {
			palabra.clear();
		} else {
			palabra = ultimaPalabra.substr(0, iguales);
		}
		ultimaPalabra = palabra + palabraDist;
	}
	cantidadPalabras++;
	return ultimaPalabra;
}

Front_codding::~Front_codding() {
	delete(unTraductor);
}

