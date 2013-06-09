/*
 * ResolvedorConsultas.h
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
using namespace std;
#define Ocurrencia pair<string, pair<double, char> >

class ResolvedorConsultas {
public:
	ResolvedorConsultas(const char* unNombreArchivo);
	ResolvedorConsultas(std::string unNombreArchivo);
	virtual ~ResolvedorConsultas();
	bool cargar_lexico(void);
	int cantidad(void);
	void mostrar_ocurrencias(void);


private:
	string nombreArchivo;
	vector < pair<string, pair<double, char> > > lexico;
};

#endif /* RESOLVEDORCONSULTAS_H_ */
