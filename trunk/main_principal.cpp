//#define papa
#ifndef papa
#include <iostream>
#include "lector_directorios.h"
#include "parser.h"
#include "merge2.h"
#include "CargadorMemoria.h"
#include "indexer.h"
#include <vector>
#include <stdio.h>

#define INDEXAR 1
#define CONSULTAR 2
#define ERROR_MODO 3

#define CERRAR "xCerrar"
using namespace std;
/* la llamada al programa se hace pasandole el directorio donde están los archivos */
vector<string>* capturar_consultas(void) {
	//Debe capturar las consultas y devolverlas al main.
	vector<string>* aux = new vector<string>;
	return aux;
}

int capturar(char modo){
	if(modo == 'r') return INDEXAR;
	if(modo == 'q') return CONSULTAR;
	return ERROR_MODO;
}

int main (int args, char* argv[]) {
	if(args<2){
		cout << "Faltan parametros de llamada al programa." << endl << "./programa -m 'directorio'" << endl
				<< "El directorio es el lugar donde se encuentran los archivos." << endl
				<< "-m es el modo: -q consultas, -r indexar" << endl;
		return 0;
	}
	if(argv[1][0] != '-') return 0;
	int modo = capturar(argv[1][1]);

	switch (modo){
	case (INDEXAR):
		cout << "indexar\n";
		cout << argv[2];
		break;
	case (CONSULTAR):
		cout << "consultar \n";
		break;
	default:
		cout << "No es un modo valido.";
		return 0;
	}


	// ruta donde están los archivos a trabajar
	string path(argv[2]);
	// se buscan los archivos con los cuales trabajaremos
	Lector_directorios lector;
	vector<string>& archivos = lector.leer_dir(argv[2]);
	vector<string> archivos_a_mergear;
	cout << "Parser funcionando." << endl;
	// se parsean los archivos
	for(size_t i=0; i<archivos.size();i++){
		string path(argv[2]);
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
	string aux_path(argv[2]);
	aux_path +="/merge-doc.txt";
	try {
		Merge merger;
		merger.merge_n_archivos(archivos_a_mergear,aux_path,PRIMERA_PASADA);
		cout<<"Termino el merge."<<endl;

		for(size_t i=0; i<archivos_a_mergear.size();++i){
			remove(archivos_a_mergear[i].c_str());
		}
	}catch (exception &e) {
		cout << "El directorio ingresado es invalido, por favor intente con otro."<< endl;
		return 0;
	}
	// se construyen los indices
	cout << "Se comienzan a construir los indices." << endl;
	indexer _idx;
	_idx.indexar(aux_path.c_str()); /* supongo que es esta la ruta; */
	cout << "Se indexaron los archivos." << endl;


	CargadorMemoria unCargador("NOMBREDELINDICE");
	try {
		unCargador.cargar_lexico();
		unCargador.cargar_ocurrencias();
	} catch (exception &e) {
		cout << "Hubo un problema al cargar el índice, el programa se cerrará."  << endl;
		delete &archivos;
		exit(1);
	}

	//Tomar las consultas
	while (true) {
		vector<string>* consulta = capturar_consultas();
		if ((*consulta)[0] == CERRAR) {
			break;
		}
		//Aquí hacer algo con la consulta, por ejempo:
		vector<Termino*> terminos;
		for (unsigned short i=0; i<consulta->size(); i++) {
			terminos.push_back(unCargador.devolver_ocurrencias_termino((*consulta)[i]));
		}
		//Aca el resolvedor tendria que hacer la magia y escupir el resultado.

		// Limpio la memoria
		for (unsigned short i=0; i<consulta->size(); i++) {
			delete terminos[i];
		}
		consulta->clear();
	}

	delete &archivos;
}
#endif
