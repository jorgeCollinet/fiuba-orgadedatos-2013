/*
 * merge.h
 *
 *  Created on: 25/05/2013
 *      Author: jorge
 */

#ifndef MERGE_H_
#define MERGE_H_
#include <vector>
class Merge {
	char** arch_a_merg;
public:
	Merge(std::vector<char*> archivos_a_mergear){
		arch_a_merg = archivos_a_mergear;
	}
};

#endif /* MERGE_H_ */
