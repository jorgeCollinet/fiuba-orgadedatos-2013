/*
 * indexer.h
 *
 *  Created on: 08/06/2013
 *      Author: federico
 */
#define INDEXER_H_
#ifndef INDEXER_H_


class indexer {
public:
	indexer();
	virtual ~indexer();
	void indexar(const char* archivo_fuente);
};

#endif /* INDEXER_H_ */
