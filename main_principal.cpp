#define papa
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

	// se parsean los archivos
	while(!archivos.empty()){
		string path(argv[1]);
		path+="/";
		path+=archivos.back();
		cout<<"Archivo: "<<path<<endl;
		// aca el parser tendria que devolver
		parser(path);
		archivos.pop_back();
	}
	//PARSER
	/*//Archivo a parsear
	string archivo = "texto.txt";
	//Esta lista es la que va a ir llenando el parser con los nombres de los archivos parseados +
	//sufijo para darse cuenta que lo parseo.
	std::list<std::string> listadirect;

	parser(archivo,listadirect);
	 *
	 *
	 *
	 *
	 *
	// se mergean los archivos
		//auxiliar a la espera de que parcer se finalize de implementar
		vector<string>archivos_a_mergear;
		string path1 ("/home/jorge/workspace2/tp DATOS/prototipo a seguir ej1/parser-doc1.txt");
		archivos_a_mergear.push_back(path1);
		string path2 ("/home/jorge/workspace2/tp DATOS/prototipo a seguir ej1/parser-doc2.txt");
		archivos_a_mergear.push_back(path2);
		string path3 ("/home/jorge/workspace2/tp DATOS/prototipo a seguir ej1/parser-doc3.txt");
		archivos_a_mergear.push_back(path3);

		Merge merger(archivos_a_mergear);
		merger.merge_2_etapas("merge-doc.txt");

	// se construyen los indices
		//falta hacer

	// se reciben consultas
		//falta hacer

*/
}


#endif
