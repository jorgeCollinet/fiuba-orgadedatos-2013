/*
 * doc_offsets.h
 *
 *  Created on: 09/06/2013
 *      Author: federico
 */

#ifndef DOC_OFFSETS_H_
#define DOC_OFFSETS_H_
#include <vector>
#include "traductor.h"

using namespace std;


class Doc_offsets {
public:
	Doc_offsets(const char* nombre);
	virtual ~Doc_offsets();
	void add_cant_doc(size_t cant);
	void add_num_doc(size_t doc);
	void add_frec(size_t frec);
	void add_offset(size_t offset);
private:
	Traductor* unTraductor;
	size_t ant;
};

#endif /* DOC_OFFSETS_H_ */
