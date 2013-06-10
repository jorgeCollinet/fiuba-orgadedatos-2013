/*
 * doc_offsets.h
 *
 *  Created on: 09/06/2013
 *      Author: federico
 */

#ifndef DOC_OFFSETS_H_
#define DOC_OFFSETS_H_
#include <vector>

using namespace std;


class Doc_offsets {
public:
	Doc_offsets(const char* nombre);
	virtual ~Doc_offsets();
	void add_cant_doc(int cant);
	void add_num_doc(int doc);
	void add_frec(int frec);
	void add_offsets(vector<int> offsets);
private:
	Traductor* unTraductor;
};

#endif /* DOC_OFFSETS_H_ */
