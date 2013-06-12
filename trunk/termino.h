/*
 * termino.h
 *
 *  Created on: 12/06/2013
 *      Author: jorge
 */

#ifndef TERMINO_H_
#define TERMINO_H_
#include <string>
#include <vector>
#include <ostream>
class Termino {
	std::string termino;
	std::vector<size_t> nro_docs;
	std::vector<size_t> off_bytes;
	std::vector<size_t> off_bits;
public:
	Termino (std::string& termino, std::vector<size_t>& nro_docs, std::vector<size_t>& off_bytes, std::vector<size_t>& off_bits );

	std::string& get_termino();
	std::vector<size_t>& get_docs();
	std::vector<size_t>& get_off_bytes();
	std::vector<size_t>& get_off_bits();

};

std::ostream& operator<<(std::ostream& os, Termino& mod);


#endif /* TERMINO_H_ */
