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
	char nombreArchivo[] = "nombresDeArchivos.dat";
	ManejadorNombreArchivo* manejador = new ManejadorNombreArchivo(nombreArchivo);
	bool res = true;
	for( unsigned int i = 0; i< 5; i++) {
		if (i != (unsigned int)manejador->agregar_nombre(palabras[i]))
			res = false;
	}
	for( unsigned int i = 0; i< 5; i++) {
			if (palabras[i] != manejador->obtener_nombre(i))
				res = false;
	}
	std::cout << "Prueba escritura y lectura de nombre en el manejador de nombres: ";
	if (res) std::cout << "correcto."<< std::endl;
	else std::cout << "incorrecto" << std::endl;
	res = true;
	if(manejador->guardar_nombres()) {
		delete (manejador);
		manejador = new ManejadorNombreArchivo(nombreArchivo);
		manejador -> cargar_nombres();
		for( unsigned int i = 0; i< 5; i++) {
				if (palabras[i] != manejador->obtener_nombre(i))
					res = false;
		}
	}
	std::cout << "Prueba persistencia de nombres en el manejador de nombres: ";
		if (res) std::cout << "correcto.";
		else std::cout << "incorrecto";
	delete (manejador);
}
#endif

