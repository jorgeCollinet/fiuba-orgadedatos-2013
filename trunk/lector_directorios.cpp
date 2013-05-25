#include "lector_directorios.h"

char** lector_directorios::leer_dir(char* ruta){

	// variables
	DIR *dir = NULL;
	struct dirent *drnt = NULL;
	char** archivos = malloc(sizeof(char**));
	if(!archivos) return NULL;

	dir=opendir(ruta);

	if(dir){

		int i=0;

		while(drnt = readdir(dir)){

			if((drnt->d_name == '.')||(drnt->d_name == '..')){
				continue;
			}
			archivos[i] = drnt->d_name);
			i++;
	    }

	    closedir(dir);

	}else{
		free(archivos);
		return NULL;
	}

	return archivos;
}

