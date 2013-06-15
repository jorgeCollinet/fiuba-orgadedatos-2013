//#define papa
#ifndef papa
#include <iostream>
#include <fstream>
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
vector<string> capturar_consultas(const char* consultas) {
	//Debe capturar las consultas y devolverlas al main.
	vector<string> aux ;
	return aux;
}


void crear_repositorio(string& dir_archivos, string& nombre_repositorio) {
	// ruta donde están los archivos a trabajar
	// se buscan los archivos con los cuales trabajaremos
	Lector_directorios lector;
	vector<string>& archivos = lector.leer_dir(dir_archivos.c_str());
	vector<string> archivos_a_mergear;
	cout << "Parser funcionando." << endl;
	// se parsean los archivos
	for (size_t i = 0; i < archivos.size(); i++) {
		string aux = dir_archivos;
		aux += "/";
		aux += archivos[i];
		Parseador pars;
		archivos_a_mergear.push_back(pars.parser(aux, i));
	}
	cout << "Archivos parseados a mergear:" << endl;
	for (size_t i = 0; i < archivos_a_mergear.size(); ++i) {
		cout << archivos_a_mergear[i] << endl;
	}
	// se mergean los archivos
	Merge merger;
	string aux_path_merge = nombre_repositorio + ".merge";
	merger.merge_n_archivos(archivos_a_mergear, aux_path_merge, PRIMERA_PASADA);
	cout << "Termino el merge." << endl;

	// se eliminan los archivos temporales del parser
	for (size_t i = 0; i < archivos_a_mergear.size(); ++i) {
		remove(archivos_a_mergear[i].c_str());
	}

	// se construyen los indices
	cout << "Se comienzan a construir los indices." << endl;
	indexer _idx;
	_idx.indexar(aux_path_merge.c_str(),nombre_repositorio);
	cout << "Se indexaron los archivos." << endl;

	// genero un archivo auxiliar para guardar la cantidad de documentos
	ofstream out (".metadatos");
	out<<archivos.size();
	out.close();

	delete &archivos;

}


vector<size_t> cargar_terminos_y_resolver_consulta(string& nombre_repositorio, const char* consulta) {
	CargadorMemoria unCargador(nombre_repositorio.c_str());
	try {
		unCargador.cargar_lexico();
		unCargador.cargar_ocurrencias();
	} catch (exception &e) {
		cout << "Hubo un problema al cargar el índice, el programa se cerrará."
				<< endl;
		exit(1);
	}
	//Tomar las consultas

	vector<string> consulta_parc = capturar_consultas(consulta);
	if (consulta_parc.size() == 0) {
		cout<<"consulta vacia";
		vector<size_t> vacio;
		return vacio;
	}
	//Aquí hacer algo con la consulta, por ejempo:
	vector<Termino> terminos;
	for (size_t i = 0; i < consulta_parc.size(); i++) {
		if(unCargador.buscar_termino(consulta_parc[i])==-1){
			cout<<"el termino "<<consulta_parc[i]<<" no aparece en ningun documento"<<endl;
			vector<size_t> vacio;
			return vacio;
		}
		terminos.push_back( unCargador.devolver_ocurrencias_termino(consulta_parc[i]) );
	}
	//Aca el resolvedor tendria que hacer la magia y escupir el resultado.

	// cargo cant total de docs
	ifstream in ;
	string path_metadatos = nombre_repositorio;
	path_metadatos += ".metadatos";
	in.open(path_metadatos.c_str());
	if(!in.is_open()){
		throw ios_base::failure("repositorio no esta indexado");
	}
	size_t cant_total_docs;
	in>>cant_total_docs;

	ResolvedorDeConsultas resolvedor;
	return resolvedor.resolver_consulta(terminos, cant_total_docs);
}

int main(int args, char* argv[]) {
	if (args < 3) {
		cout << "Indexar el Repositorio: "<< endl << "Por linea de comandos un programa indexador recibe un nombre para el repositorio y un directorio." << endl;
		cout << "Tpgrupo17 libros /home/TP/datos" << endl;;
		cout << "Realizar Consultas "<< endl;
		cout << "TpGrupo17q -r libros -q “apple” "<< endl << "TpGrupo17q -r libros -q ”New York”"<< endl<< "TpGrupo17q -r libros -q ”Call me Ishmael”"<<endl;;
		return 0;
	}
	if (args == 3) {
		cout<<"indexando repositorio"<<endl;
		cout<<"directorio a indexar: "<<argv[1]<<endl;
		cout<<"nombre repositorio: "<<argv[2]<<endl;
		string nombre_repositorio = argv[2];
		string dir_archivos = argv[1];
		crear_repositorio(dir_archivos, nombre_repositorio);
		cout<<"indexado terminado"<<endl;
		return 0;
	}
	if (args!=5 || string(argv[1]) != "-r" || string(argv[3]) != "-q") {
		throw ios_base::failure("formato de parametros incorrecto");
	}
	string nombre_repo = argv[2];
	const char* consulta = argv[4];
	vector<size_t> doc_encontrados = cargar_terminos_y_resolver_consulta(nombre_repo, consulta);

	// falta decir por nombre que documentos son, por ahora solo tenemos los numeros
	cout<<"los documentos que contienen la frase son: ";
	for(size_t i=0; i<doc_encontrados.size();++i){
		cout << doc_encontrados[i];
		cout<<" ";
	}
	cout<<endl;
}


#endif
