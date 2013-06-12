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
#include <stdint.h>
#include <algorithm>
using namespace std;

//Estructura para guardar los terminos
struct termino{

	std::string term;
	int posi;
	int doc;
};


class Parseador{

private:

	list<termino> milista; //Lista donde se guardaran los terminos
	std::string nombrearchivo; // GUardara el nombre del archivo a parsearse

	std::string  getnombre();

	std::string getnombrearchivofinal();

	static void pasarAminusculas(std::string& str);

	int cantidadpalabras();

	static bool ordenamiento(termino const& izq,termino const& der);

	void mostrarlista();

	void ordenarlistaposta();

	void acomodador(std::ofstream&);

	void posicionadistancia(std::list<int>&,std::ofstream&);


public:

	//Constructor. Inicializa el nombre del archivo a parsear
	Parseador();

	~Parseador();

	// Parsea el archivo extrayendo terminos importante y su ubicacion
	std::string parser(std::string& archivoaparsear,int doc);


};

#endif /* PARSERTEX_H_ */
