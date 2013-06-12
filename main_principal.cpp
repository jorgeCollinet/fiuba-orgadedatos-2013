//#define papa
#ifndef papa
#include <iostream>
#include "lector_directorios.h"
#include "parser.h"
#include "merge2.h"
#include "indexer.h"
#include <vector>
#include <stdio.h>
using namespace std;
/* la llamada al programa se hace pasandole el directorio donde están los archivos */
int main (int args, char* argv[]) {
	if(args<2){
		throw ios_base::failure("faltan parametros de llamada al programa");
	}
	// ruta donde están los archivos a trabajar
	string path = argv[1];
	// se buscan los archivos con los cuales trabajaremos
	Lector_directorios lector;
	vector<string>& archivos = lector.leer_dir(argv[1]);
	vector<string> archivos_a_mergear;
	// se parsean los archivos
	for(size_t i=0; i<archivos.size();i++){
		string path(argv[1]);
		path+="/";
		path+=archivos[i];
		Parseador pars;
		archivos_a_mergear.push_back(pars.parser(path,i));
	}
	cout<<"Archivos parseados a mergear:"<<endl;
	for(size_t i =0;i<archivos_a_mergear.size();++i){
		cout<<archivos_a_mergear[i]<<endl;
	}
	// se mergean los archivos
		Merge merger;
		string aux_path = path;
		aux_path +="/merge-doc.txt";
		merger.merge_n_archivos(archivos_a_mergear,aux_path,PRIMERA_PASADA);
		cout<<"termino el merge"<<endl;

		for(size_t i=0; i<archivos_a_mergear.size();++i){
			remove(archivos_a_mergear[i].c_str());
		}
	// se construyen los indices
		//indexer _idx;
		//_idx.indexar(path.c_str());/* supongo que es esta la ruta; */
		//cout << "se indexaron los archivos\n";

	// se reciben consultas
		//falta hacer
	delete &archivos;
}


#endif
