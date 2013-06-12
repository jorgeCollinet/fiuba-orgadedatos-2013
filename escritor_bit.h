/*
 * escritor_bit.h
 *
 *  Created on: 23/05/2013
 *      Author: jorge
 */

#ifndef ESCRITOR_BIT_H_
#define ESCRITOR_BIT_H_
#include <fstream>
class Escritor_bit {
	std::ofstream arch;
	size_t contador;
	unsigned char buffer;
	unsigned char num [8];
public:
	Escritor_bit(const char* nombre_archivo);

	/*escribe el bit en el archivo
	 */
	bool escribir_bit_desde_arriba(unsigned int bit);
	/* cierra el archivo en donde se está escribiendo
	 * OJO: si no completaron los bits para llegar a los 8 se llena con ceros el resto */
	bool cerrar_escritor();
};



#endif /* ESCRITOR_BIT_H_ */
