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

private:
	string nombreArchivo;
	vector < pair<string, pair<double, char> > > lexico;
};

#endif /* RESOLVEDORCONSULTAS_H_ */
