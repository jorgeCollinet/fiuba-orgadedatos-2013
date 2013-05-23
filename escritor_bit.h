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
public:
	Escritor_bit(const char* nombre_archivo);
	/* escribe el bit en el archivo
	 * OJO: se ecribe de menor a mayor, es decir que el primer escribir_bit que se haga va a ser del lugar 0
	 * ej: primero : _ _ _ _ _ _ _ _
	 * escribir_bit(1) -> queda: _ _ _ _ _ _ _ 1
	 * escribir_bit(0) -> queda: _ _ _ _ _ _ 0 1
	 * escribir_bit(0) -> queda: _ _ _ _ _ 0 0 1
	 * ect */
	bool escribir_bit_desde_abajo(unsigned int bit);
	/*escribe el bit en el archivo EN GENERAL SE USARA ESTA
	 * OJO: escribe de mayor a menor, lo contrario del anterior metodo
	 */
	bool escribir_bit_desde_arriba(unsigned int bit);
	/* cierra el archivo en donde se está escribiendo
	 * OJO: si no completaron los bits para llegar a los 8 se llena con ceros el resto */
	bool cerrar_escritor();
};



#endif /* ESCRITOR_BIT_H_ */
