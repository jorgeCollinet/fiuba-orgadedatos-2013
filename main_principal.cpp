//#define papa
#ifndef papa
#include <iostream>
#include "lector_directorios.h"
#include "parser.h"
#include "merge.h"
#include <vector>
using namespace std;
/* la llamada al programa se hace pasandole el directorio donde están los archivos */
int main (int args, char* argv[]){
	cout<<"esto es el main del programa"<<endl;
	// se buscan los archivos con los cuales trabajaremos
	Lector_directorios lector;
	vector<string>archivos = lector.leer_dir(argv[1]);
	//debug que muestra que lector devolvió bien los archivos
	for(size_t i=0;i<archivos.size();++i){
		cout<<"DEBUG archivos: "<<archivos[i]<<endl;
	}

	// se parsean los archivos
	while(!archivos.empty()){
		bool exito = true;
		string path(argv[1]);
		path+="/";
		path+=archivos.back();
		cout<<path<<endl;
		exito = parser(path);
		if(!exito){
			cout<<"ERROR EN PARSER !!!"<<endl;
			return 1;
		}
		archivos.pop_back();
	}

	// se mergean los archivos
		//auxiliar a la espera de que parcer se finalize de implementar
		vector<string>archivos_a_mergear;
		string path1 ("/home/jorge/Escritorio/ej tps/ej1/parser-doc1.txt");
		archivos_a_mergear.push_back(path1);
		string path2 ("/home/jorge/Escritorio/ej tps/ej1/parser-doc2.txt");
		archivos_a_mergear.push_back(path2);

	//Merge merger(archivos_a_mergear);
	//merger.merge_2_etapas("merge-doc.txt");

	// se construyen los indices
		//falta hacer

	// se reciben consultas
		//falta hacer


}


#endif
