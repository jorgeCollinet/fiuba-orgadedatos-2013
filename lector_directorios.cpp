#include "lector_directorios.h"
using namespace std;
vector<string>& Lector_directorios::leer_dir(char* ruta){

	// variables
	DIR *dir = NULL;
	struct dirent *drnt = NULL;
	//char** archivos = malloc(sizeof(char**));
	vector<string>*archivos = new vector<string>;
	//if(!archivos) return NULL;

	dir=opendir(ruta);

	if(dir){

		int i=0;

		while((drnt = readdir(dir))){

			if((drnt->d_name[0] == '.')||(drnt->d_name[1] == '.')){
				continue;
			}
			//archivos[i] = drnt->d_name);
			stringstream ss;
			ss<<drnt->d_name;
			string * aux = new string(ss.str());
			archivos->push_back(*aux);
			i++;
	    }

	    closedir(dir);

	}else{
		//free(archivos);
		delete archivos;
		// devuelve uno vacio
		vector<string>*archivos = new vector<string>;
		return *archivos;
	}

	return *archivos;
}

