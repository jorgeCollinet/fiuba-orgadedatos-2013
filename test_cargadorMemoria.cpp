/*
 * test_CargadorMemoria.cpp
 *
 *  Created on: 09/06/2013
 *      Author: juan
 */
//#define TESTCONSULTAS
#ifndef TESTCONSULTAS
#include "front_codding.h"
#include "CargadorMemoria.h"
#include "traductor.h"
#include <iostream>
using namespace std;

int main(void) {
	string nombreArchivo("archivo");
	CargadorMemoria* rs = new CargadorMemoria(nombreArchivo);
	cout << "Inicio pruebas " << endl;
	if(rs->cargar_lexico())
		cout << "Carga de lexico correcta" << endl;
	else cout << "Carga de lexico incorrecta"<< endl;
	//rs->mostrar_ocurrencias();
	//general el indice
	Traductor* unTraductor = new Traductor(WRITE, "archivoOC.dat");
	int numero[]= {1,1,1,5,1,1,1,6,3,1,1,4,2,1,4,3,2,4,1,1,2,1,1,1,1,1,1,3,1,1,3,2,1,3,3,1,6,3,1,1,2,2,1,2,3,3,1,1,1};


	for (int i=0; i < 8; i++) {
			unTraductor -> write_delta(numero[i]);
	}
	delete unTraductor;

	//Ya están escritos
	unTraductor = new Traductor(READ, "archivoOC.dat");
	rs->cargar_ocurrencias();
	rs->mostrar_ocurrencias();
	cout << "Fin pruebas." << endl;
	delete rs;
	return 0;
}
#endif



