/*
 * ManejadorArchivos.h
 *
 *  Created on: 25/05/2013
 *      Author: pablo
 */

#ifndef MANEJADORARCHIVOS_H_
#define MANEJADORARCHIVOS_H_

#include <fstream>
#include <iostream>

class ManejadorArchivos {
private:

   std::fstream  miarchivo;  // mi archivo

public:


  ManejadorArchivos();

  ~ManejadorArchivos();

  void abrirLectura(const std::string& miruta);

  void abrirEscritura(const std::string& miruta);

  bool leerunalinea(std::string& micadena);

  void terminarlinea();

};
#endif /* MANEJADORARCHIVOS_H_ */
