/*
 * ResolvedorConsultas.cpp
 *
 *  Created on: 09/06/2013
 *      Author: juan
 */

#include "ResolvedorConsultas.h"

using namespace std;

ResolvedorConsultas::ResolvedorConsultas(const char* unNombreArchivo) {
	this -> nombreArchivo = string(unNombreArchivo);
}

ResolvedorConsultas::ResolvedorConsultas(string unNombreArchivo) {
	this -> nombreArchivo =  unNombreArchivo;
}

bool ResolvedorConsultas::cargar_lexico(void) {
	//Carga el léxico en memoria, sólo las palabras no sus ocurrencias.
	string finPalabras ("Error_Lectura");
	Front_codding* fCodding = new Front_codding(nombreArchivo.c_str());
	fCodding->modo_lectura();
	cout << "Se cargaran las palabras desde el archivo: " << nombreArchivo << endl;
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

ResolvedorConsultas::~ResolvedorConsultas() {
	// TODO Auto-generated destructor stub
}

int ResolvedorConsultas::cantidad(void) {
	return lexico.size();
}

void ResolvedorConsultas::mostrar_ocurrencias(void) {
	for (int i=0; i<this->cantidad();i++) {
		cout << lexico[i].first << ", ";
	}
	cout << endl;
}

