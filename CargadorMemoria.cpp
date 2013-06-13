/*
 * CargadorMemoria.cpp
 *
 *  Created on: 09/06/2013
 *      Author: juan
 */

#include "CargadorMemoria.h"
#define FINARCH (-1)
#define FINOCURRENCIAS "OC.dat"
#define FINFRONTCODDING "FC.dat"


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
	string nombreFC = nombreArchivo + FINFRONTCODDING;
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
	string nombreOC = nombreArchivo + FINOCURRENCIAS;
	cout << "Se cargan las ocurrencias desde el archivo: " << nombreOC << endl;
	Traductor traductor (READ, nombreOC.c_str());
	int numeroLeido=0, frecPalabra=0,cantDocumentos=0;
	unsigned int numeroPalabra = 0;
	while (1 && (numeroPalabra < lexico.size())) {
		lexico[numeroPalabra].second.first = traductor.devolver_offset_de_byte(); //Leo el offset en bytes
		lexico[numeroPalabra].second.second = traductor.devolver_offset_de_bit(); //Leo el offset en bits
		cantDocumentos = numeroLeido = traductor.read_delta();
		//cout << numeroLeido << " ";
		if (numeroLeido == FINARCH) break;
		//Lei la cantidad de documentos en los que aparece.
		for (int j = 0; j < cantDocumentos; j++) {
			numeroLeido = traductor.read_delta(); // Leo el numero de documento, no me importa ahora.
			if (numeroLeido==FINARCH) cout << "El archivo de ocurrencias está mal formado." << endl;
			//Estoy iterando sobre documentos
			frecPalabra = traductor.read_delta();
			//cout << " " << frecPalabra << " ";
			if (frecPalabra==FINARCH) cout << "El archivo de ocurrencias está mal formado." << endl;
			for (int k=0; k < frecPalabra; k++) {
				//Estoy iterando sobre offsets de la misma palabra en el mismo documento.
				numeroLeido=traductor.read_delta();
				if (numeroLeido==FINARCH) cout << "El archivo de ocurrencias está mal formado." << endl;
			}
		}
		numeroPalabra++;
		//cout << endl;
	}
	if (numeroPalabra != lexico.size())
		cout << "Hubo un problema en la carga del indice." << endl;
		return false;
	//Una vez que estoy aquí todos los offset se han leido y la estructura quedó cargada en memoria.
	return true;
}

CargadorMemoria::~CargadorMemoria(void) {
	lexico.clear();
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

Termino* CargadorMemoria::devolver_ocurrencias_termino(string unTermino) {
	cout << "Estoy por buscar, resultado: ";
	int resultado = this->buscar_termino(unTermino);
	if (resultado == -1) {
		return NULL;
	}
	string nombreOC = nombreArchivo + FINOCURRENCIAS;
	Traductor traductor (READ, nombreOC.c_str());
	int numeroLeido=0, frecPalabra=0,cantDocumentos=0;
	if (!traductor.avanzar_cursor((int)lexico[resultado].second.first, lexico[resultado].second.second)) {
		cout << "El archivo de ocurrencias está mal formado. 1 " << endl;
		return NULL;
	}
	cout << "Byte: " << traductor.devolver_offset_de_byte() << "Bit: " << traductor.devolver_offset_de_bit() << endl;
	//std::vector<std::pair <size_t ,std::vector<size_t> > > auxiliar;
	cantDocumentos = traductor.read_delta();
	std::vector<std::pair <size_t ,std::vector<size_t> > > valor;
	for (int k=0; k < cantDocumentos; k++) {
		pair<size_t ,std::vector<size_t> > offsets;
		numeroLeido = traductor.read_delta(); //Leo el numero del documento
		offsets.first = numeroLeido;
		frecPalabra = traductor.read_delta();
		for (int j = 0; j < frecPalabra; j++) {
			numeroLeido = traductor.read_delta(); //Leo offsets
			if (numeroLeido==FINARCH) {
				cout << "El archivo de ocurrencias está mal formado." << endl;
				return NULL;
			}
			offsets.second.push_back(numeroLeido); //Guardo el offset
		}
		valor.push_back(offsets);
	}
	return new Termino(unTermino, valor);
}

int CargadorMemoria::buscar_termino(string unTermino) {
	int Iarriba = lexico.size()-1;
	int Iabajo = 0;
	int Icentro;
	while (Iabajo <= Iarriba)
	{
		Icentro = (Iarriba + Iabajo)/2;
		if (lexico[Icentro].first == unTermino){
			cout << Icentro << endl;
			return Icentro;
		}else{
			if (unTermino < lexico[Icentro].first)
				Iarriba=(Icentro-1);
			else
				Iabajo=(Icentro+1);
		}
	}
	cout << "No lo encontre";
	return -1;
}
