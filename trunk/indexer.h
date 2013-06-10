/*
 * indexer.h
 *
 *  Created on: 08/06/2013
 *      Author: federico
 */

#ifndef INDEXER_H_
#define INDEXER_H_

class indexer {
public:
	indexer();
	virtual ~indexer();
	void indexar(const char* archivo_fuente);
};

#endif /* INDEXER_H_ */
