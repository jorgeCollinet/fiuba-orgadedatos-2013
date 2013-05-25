/*
 * ManejadorArchivos.cpp
 *
 *  Created on: 25/05/2013
 *      Author: pablo
 */

#include "ManejadorArchivos.h"
#include <iostream>

using namespace std;

ManejadorArchivos::ManejadorArchivos(){};


/**
  * Cierra el archivo
  */
ManejadorArchivos::~ManejadorArchivos() {
  miarchivo.close();
}

