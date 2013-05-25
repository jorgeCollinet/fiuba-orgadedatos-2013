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

class Archivo {
private:
   std::fstream  miarchivo;  // mi archivo

public:

  ArchivoTexto();

  ~ArchivoTexto();

  void abrirLectura(const std::string& miruta);

  void abrirEscritura(const std::string& miruta);

};
#endif /* MANEJADORARCHIVOS_H_ */
