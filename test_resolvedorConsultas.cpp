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
#include "traductor.h"
#include <iostream>
using namespace std;

int main(void) {
	ResolvedorConsultas* rs = new ResolvedorConsultas("archivo");
	cout << "Inicio pruebas " << endl;
	if(rs->cargar_lexico())
		cout << "Carga de lexico correcta" << endl;
	else cout << "Carga de lexico incorrecta"<< endl;
	rs->mostrar_ocurrencias();
	//general el indice
	Traductor* unTraductor = new Traductor(WRITE, "archivoDOC.dat");
	int numero[]= {1,1,1,5,1,1,1,6,3,1,1,4,2,1,4,3,2,4,1,1,2,1,1,1,1,1,1,3,1,1,3,2,1,3,3,1,6,3,1,1,2,2,1,2,3,3,1,1,1};
	for (unsigned int i=0; i <49; i++ ) {
		unTraductor->write_delta(numero[i]);
	}
	delete (unTraductor);
	Traductor otroTraductor(READ, "archivoDOC.dat");
	while (1) {
		int numero = otroTraductor.read_delta();
		if (numero == (-1)) break;
		cout << numero << ",";
	}
	rs->cargar_ocurrencias();
	rs->mostrar_ocurrencias();
	cout << "Fin pruebas." << endl;
	delete rs;
	return 0;
}
#endif



