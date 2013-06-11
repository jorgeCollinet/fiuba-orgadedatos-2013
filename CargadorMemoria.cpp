/*
 * CargadorMemoria.cpp
 *
 *  Created on: 09/06/2013
 *      Author: juan
 */

#include "CargadorMemoria.h"
#define FINARCH (-1)

using namespace std;

CargadorMemoria::CargadorMemoria(const char* unNombreArchivo) {
	this -> nombreArchivo = string(unNombreArchivo);
}

CargadorMemoria::CargadorMemoria(string unNombreArchivo) {
	this -> nombreArchivo =  unNombreArchivo;
}

bool CargadorMemoria::cargar_lexico(void) {
	//Carga el léxico en memoria, sólo las palabras no sus ocurrencias.
	string finPalabras ("Error_Lectura");
	string nombreFC = nombreArchivo + "FC.dat";
	Front_codding* fCodding = new Front_codding(nombreFC.c_str());
	fCodding->modo_lectura();
	cout << "Se cargaran las palabras desde el archivo: " << nombreFC << endl;
	unsigned int j = 0;
	while (true) {
		string lectura;
		lectura = fCodding->leer_proxima_palabra();
		if (lectura == finPalabras) break;
		Ocurrencia auxiliar;
		auxiliar.first = lectura;
		lexico.push_back(auxiliar);
		j++;
	}
	if (j == 0) return false;
	return true;
}

bool CargadorMemoria::cargar_ocurrencias(void) {
	string nombreOC = nombreArchivo + "DOC.dat";
	Traductor traductor (READ, nombreOC.c_str());
	int numeroLeido, frecPalabra;
	unsigned int numeroPalabra=0;
	while (1 && (numeroPalabra < lexico.size())) {
		lexico[numeroPalabra].second.first = traductor.devolver_offset_de_byte(); //Leo el offset en bytes
		lexico[numeroPalabra].second.second = traductor.devolver_offset_de_bit(); //Leo el offset en bits
		numeroLeido = traductor.read_delta();
		cout << numeroLeido << " ";
		if (numeroLeido == FINARCH) break;
		//Lei la cantidad de documentos en los que aparece.
		for (int j = 0; j < numeroLeido; j++) {
			cout << traductor.read_delta(); // Leo el numero de documento
			//Estoy iterando sobre documentos
			frecPalabra = traductor.read_delta();
			cout << " " << frecPalabra << " ";
			for (int k=0; k < frecPalabra; k++) {
				//Estoy iterando sobre offsets de la misma palabra en el mismo documento.
				cout << traductor.read_delta() << " ";
			}
		}
		numeroPalabra++;
		cout << endl;
	}
	if (numeroPalabra != lexico.size())
		cout << "Hubo un problema en la carga del indice." << endl;
	//Una vez que estoy aquí todos los offset se han leido y la estructura quedó cargada en memoria.
	return true;
}

CargadorMemoria::~CargadorMemoria() {
	// TODO Auto-generated destructor stub
}

int CargadorMemoria::cantidad(void) {
	return lexico.size();
}

void CargadorMemoria::mostrar_ocurrencias(void) {
	for (int i=0; i<this->cantidad();i++) {
		cout << lexico[i].first << " " << lexico[i].second.first << "/" << (int)lexico[i].second.second << endl;
	}
	cout << endl;
}

