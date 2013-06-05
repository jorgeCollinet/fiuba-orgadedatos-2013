/*
 * test_manejadorNombreArchivo.cpp
 *
 *  Created on: 05/06/2013
 *      Author: juan
 */
#include "ManejadorNombreArchivo.h"
#include <vector>
#include <iostream>

#define TESTMANEJADORNOMBREARCHIVO
#ifndef TESTMANEJADORNOMBREARCHIVO
int main(void) {
	std::string str1("hola"),str2("esto"),str3("es"),str4("una"),str5("prueba.");
	std::string palabras[]={str1,str2,str3,str4,str5};
	ManejadorNombreArchivo* manejador = new ManejadorNombreArchivo();
	for( unsigned int i = 0; i< 5; i++) {
		manejador->agregarNombre(palabras[i]);
	}
	bool res = true;
	for( unsigned int i = 0; i< 5; i++) {
			if (palabras[i] != manejador->obtenerNombre(i))
				res = false;
	}
	std::cout << "Prueba escritura y lectura de nombre en el manejador de nombres: ";
	if (res) std::cout << "correcto.";
	else std::cout << "incorrecto";
}
#endif

