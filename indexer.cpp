/*
 * indexer.cpp
 *
 *  Created on: 08/06/2013
 *      Author: federico
 */

#include "indexer.h"
#include <iostream>
#include <fstream>
#include <string>
#define NOMBRE_FC = "index_fc.txt";

using namespace std;

indexer::indexer() {
	// TODO Auto-generated constructor stub

}

indexer::~indexer() {
	// TODO Auto-generated destructor stub
}


void indexer::indexar(const char* archivo_fuente) {

	ifstream fuente;
	fuente.open(archivo_fuente, std::ifstream::in);

	const char* nombrefc = "index_fc.txt";
	Front_codding fc_codder(nombrefc);
	fc_codder.modo_escritura();

	const char* nombreoffsets = "index_offsets.txt";
	Doc_offsets docs(nombrefc);

	char aux;

	while(fuente.good()){
		// leo una palabra
		string palabra;
		aux = fuente.get();
		while(aux != ' '){
			aux = fuente.get();
			palabra.append(&aux);
		}
		// la mando a front codding
		/** modificar para que se le puedan poner strings**/
		fc_codder.agregar_palabra(palabra.c_str());

		//leer hasta el eol
		string offsets = fuente.getline();
		// mando sus offsets a documentos
		docs.agregar_offsets(offsets);


	}



	fuente.close();
}
