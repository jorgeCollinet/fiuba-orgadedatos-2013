/*
 * CargadorMemoria.h
 *
 *  Created on: 09/06/2013
 *      Author: juan
 */

#ifndef RESOLVEDORCONSULTAS_H_
#define RESOLVEDORCONSULTAS_H_
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include "front_codding.h"
#include "traductor.h"
using namespace std;
#define Ocurrencia pair<string, pair<double, short> >
#define OFFSET pair <size_t,vector<size_t> >


class CargadorMemoria {
public:
	CargadorMemoria(const char* unNombreArchivo);
	CargadorMemoria(std::string unNombreArchivo);
	virtual ~CargadorMemoria();
	bool cargar_lexico(void);
	bool cargar_ocurrencias(void);
	int cantidad(void);
	// Uso para debug
	void mostrar_ocurrencias(void);
	//Devuelve las ocurrencias de un termino
	vector<OFFSET>* devolver_ocurrencias_termino(string unTermino);

private:
	string nombreArchivo;
	vector < pair<string, pair<double, char> > > lexico;
	int buscar_termino(string unTermino);

};

#endif /* RESOLVEDORCONSULTAS_H_ */
