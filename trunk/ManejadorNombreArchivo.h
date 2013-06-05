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

class ManejadorNombreArchivo {
public:
	ManejadorNombreArchivo();
	virtual ~ManejadorNombreArchivo();
	int agregarNombre(std::string unNombre);
	std::string obtenerNombre(int unEntero);

private:
	std::vector<std::string>* nombres;
};

#endif /* MANEJADORNOMBREARCHIVO_H_ */
