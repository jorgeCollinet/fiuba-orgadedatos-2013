/*
 * indexer.h
 *
 *  Created on: 08/06/2013
 *      Author: federico
 */

#ifndef INDEXER_H_
#define INDEXER_H_
#include <vector>
#include <string>

class indexer {
public:
	indexer();
	virtual ~indexer();
	// con la salida del merge separa offsets de terminos y los guarda comprimidos
	void indexar(const char* archivo_fuente);
	/** comprimir con LZW (falta)**/
	void guardar_rutas(std::vector<std::string> rutas);
};

#endif /* INDEXER_H_ */
