
#include <iostream>
#include "lector_directorios.h"
#include "Parser.h"
#include <vector>
using namespace std;
/* la llamada al programa se hace pasandole el directorio donde están los archivos */
int main (int args, char* argv[]){
	cout<<"esto es el main del programa"<<endl;
	// se buscan los archivos con los cuales trabajaremos
	Lector_directorios lector;
	vector<string>archivos = lector.leer_dir(argv[1]);

	// se parsean los archivos
	while(!archivos.empty()){
		string aux = archivos.back();
		cout<<aux<<endl;
		archivos.pop_back();
		//Parser((char*)aux.c_str());
	}

	// se mergean los archivos
		//falta hacer

	// se construyen los indices
		//falta hacer

	// se reciben consultas
		//falta hacer


}


