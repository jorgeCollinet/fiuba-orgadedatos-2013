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
#include "front_codding.h"
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
	Doc_offsets docs(nombreoffsets);

	int cant_docs;
	int frec;
	int doc;
	int pos;

	while(!fuente.eof()){
		// leo una palabra
		string palabra;
		fuente >> palabra;
		// la mando a front codding
		fc_codder.agregar_palabra(palabra);

		// tomo la cantidad de documentos en donde aparece.
		fuente >> cant_docs;
		docs.add_cant_doc(cant_docs);

		// por cada documeto
		for(int i=0;i<cant_docs;i++){

			// leo el num de doc
			fuente >> doc;
			docs.add_num_doc(doc);

			// leo la frec.
			fuente >> frec;
			docs.add_frec(frec);

			vector<int> offsets;
			//tomo cada aparicion
			for (int j = 0; j < frec; j++) {
				fuente >> pos;
				offsets.push_back(pos);
			}
			docs.add_offsets(offsets);
		}
	}



	fuente.close();
}
