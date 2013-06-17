/*
 * indexer.cpp
 *
 *  Created on: 08/06/2013
 *      Author: federico
 */

#include "indexer.h"
#include "doc_offsets.h"
#include <iostream>
#include <fstream>
#include <string>
#include "front_codding.h"

#define NOMBRE_FC = ".fc";
#define NOMBRE_OF = ".offsets";

using namespace std;

indexer::indexer() {
	// TODO Auto-generated constructor stub

}

indexer::~indexer() {
	// TODO Auto-generated destructor stub
}


void indexer::indexar(const char* archivo_fuente,string& nombre_repositorio) {

	ifstream fuente;
	fuente.open(archivo_fuente, std::ifstream::in);

	string nombrefc(nombre_repositorio);
	nombrefc += ".fc";
	Front_codding fc_codder(nombrefc.c_str());
	fc_codder.modo_escritura();


	string nombreoffsets(nombre_repositorio);
	nombreoffsets += ".offsets";
	Doc_offsets docs(nombreoffsets.c_str());

	size_t cant_docs;
	size_t frec;
	size_t doc;
	size_t pos;

	while(!fuente.eof()){

		// leo una palabra
		string palabra;
		fuente >> palabra;
		// cout<<endl<< palabra << "\n";
		// la mando a front codding
		fc_codder.agregar_palabra(palabra);

		// tomo la cantidad de documentos en donde aparece.
		fuente >> cant_docs;
		// cout<< "cant_docs" << " ";
		docs.add_cant_doc(cant_docs);

		// por cada documeto
		for(size_t i=0;i<cant_docs;i++){

			// leo el num de doc
			fuente >> doc;
			docs.add_num_doc(doc);
			// cout<< "doc" << " ";

			// leo la frec.
			fuente >> frec;
			docs.add_frec(frec);
			// cout<< "frec" << " ";

			//tomo cada aparicion
			for (size_t j = 0; j < frec; j++) {
				fuente >> pos;
				docs.add_offset(pos);
			}
			// cout << endl;
		}
	}



	fuente.close();
}
