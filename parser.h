/*
 * Parser.h
 *
 *  Created on: 06/06/2013
 *      Author: pablo
 */
#ifndef PARSERTEX_H_
#define PARSERTEX_H_

#include <string.h>
#include <iostream>
#include <fstream>
#include "ManejadorArchivos.h"
#include "Utilities.h"
#include <list>
using namespace std;

//Estructura para guardar los terminos
struct termino{

	std::string term;
	int posi;
};


class Parseador{

private:

	list<termino> milista; //Lista donde se guardaran los terminos
	std::string nombrearchivo; // GUardara el nombre del archivo a parsearse


public:

	//Constructor. Inicializa el nombre del archivo a parsear
	Parseador(std::string& archivoaparsear);

	~Parseador();
	// Parsea el archivo extrayendo terminos importante y su ubicacion
	bool parser();

	std::string  getnombre();

	std::string getnombrearchivofinal();

	int cantidadpalabras();

	bool ordenamiento(termino const& izq,termino const& der);

	void mostrarlista();

};

#endif /* PARSERTEX_H_ */
