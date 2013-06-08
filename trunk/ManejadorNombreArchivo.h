/*
 * ManejadorNombreArchivo.h
 *
 *  Created on: 05/06/2013
 *      Author: juan
 */

#ifndef MANEJADORNOMBREARCHIVO_H_
#define MANEJADORNOMBREARCHIVO_H_

#include <vector>
#include <string>
#include <fstream>

class ManejadorNombreArchivo {
public:
	ManejadorNombreArchivo();
	ManejadorNombreArchivo(char* unNombreArchivo);
	virtual ~ManejadorNombreArchivo();
	int agregarNombre(std::string unNombre);
	std::string obtenerNombre(int unEntero);
	bool guardarNombres();

private:
	std::vector<std::string>* nombres;
	std::string nombreArchivo;
};

#endif /* MANEJADORNOMBREARCHIVO_H_ */
