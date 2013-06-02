/*
 * test_traductor.cpp
 *
 *  Created on: 21/05/2013
 *      Author: jorge
 */

//#define sacar_esto_para_correr_la_prueba_traductor
#ifndef sacar_esto_para_correr_la_prueba_traductor
#include "traductor.h"

using namespace std;
// caso de muestra de como usar un traductor

int main(void) {

	Traductor* unTraductor = new Traductor(WRITE, "pTraductor.dat");
	//Prueba escribir números;
	int num[] = {1,2,3,4,10};
	for (int i=0; i < 5; i++) {
		cout << num[i] << ",";
		unTraductor->write_gamma(num[i]);
	}
	cout << endl;
	delete unTraductor;
	
	//Ya están escritos
	Traductor* otroTraductor = new Traductor(READ, "pTraductor.dat");
	int res = 0;
	for (int i=0; i < 5; i++) {
		int aux = unTraductor->read_gamma();
		if( num[i] != aux ) {
			//cout << aux << endl;
			res = 1;
		}	
	}
	delete otroTraductor;

	cout << "Escritura y lectura de gamma: ";
	if (res == 0) {
		cout << "corretos." << endl;
	} else {
		cout << "incorrectos." << endl;
	}

	//Pruebas delta
	unTraductor = new Traductor(WRITE, "pTraductor2.dat");
	for (int i=0; i < 5; i++) {
			unTraductor -> write_delta(num[i]);
	}
	delete unTraductor;

	//Ya están escritos
	otroTraductor = new Traductor(READ, "pTraductor2.dat");

	res = 0;
	for (int i=0; i < 5; i++) {
		int aux = unTraductor->read_delta();
		if( num[i] != aux ) {
			cout << aux << endl;
			res = 1;
		}
	}
	delete otroTraductor;
	cout << "Escritura y lectura de delta: ";
	if (res == 0) {
		cout << "corretos." << endl;
	} else {
		cout << "incorrectos." << endl;
	}

	return 0;
}
#endif
