#ifndef LECTOR_DIRECTORIOS_H_
#define LECTOR_DIRECTORIOS_H_

#include <fstream>
#include <iostream>
#include <string>

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

class lector_directorios{

	public:
	// se le entrega una ruta y devuelve una lista de archivos en ese directorio
	// devuelve NULL ante algun problema
	char** leer_dir(char* ruta);

};
