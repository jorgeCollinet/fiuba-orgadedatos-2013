/*
 * test_CargadorMemoria.cpp
 *
 *  Created on: 09/06/2013
 *      Author: juan
 */
#define TESTCONSULTAS
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


	for (int i=0; i < 49; i++) {
			unTraductor -> write_delta(numero[i]);
	}
	delete unTraductor;

	//Ya están escritos
	unTraductor = new Traductor(READ, "archivoOC.dat");
	rs->cargar_ocurrencias();
	rs->mostrar_ocurrencias();
	int resEsperado[] = {1,4,2,4,3,4,1},k=0,resultado=0;

	vector<OFFSET>* vector1 = rs->devolver_ocurrencias_termino("perritos");
	for (unsigned int i=0; i<vector1->size(); i++) {
		if((size_t)resEsperado[k++] != (*vector1)[i].first) resultado=(-1);
		for (unsigned int j=0; j<(*vector1)[i].second.size(); j++ ) {
			if((unsigned) resEsperado[k++] != (*vector1)[i].second[j]) resultado =(-1);
		}
	}
	cout << "Levantar offset de disco: ";
	if (resultado==0) {
		cout << "correcto." << endl;
	} else {
		cout << "incorrecto." << endl;
	}
	cout << endl << "Fin pruebas." << endl;

	delete vector1;
	delete rs;
	return 0;
}
#endif



