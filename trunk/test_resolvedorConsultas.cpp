/*
 * test_resolvedorConsultas.cpp
 *
 *  Created on: 09/06/2013
 *      Author: juan
 */
//#define TESTCONSULTAS
#ifndef TESTCONSULTAS
#include "front_codding.h"
#include "ResolvedorConsultas.h"
#include <iostream>
using namespace std;

int main(void) {
	ResolvedorConsultas rs("archivoFC.dat");
	cout << "Inicio pruebas " << endl;
	if(rs.cargar_lexico())
		cout << "Carga de lexico correcta" << endl;
	else cout << "Carga de lexico incorrecta"<< endl;
	rs.mostrar_ocurrencias();
	cout << "Fin pruebas " << endl;
	return 0;
}
#endif



