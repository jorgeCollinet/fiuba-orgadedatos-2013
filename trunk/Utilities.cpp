/*
 * Utilities.cpp
 *
 *  Created on: 25/05/2013
 *      Author: pablo
 */


#include <string.h>
#include <stdio.h>
#include <ctype.h>


/* Function de Hashing. Devuelve numero entre 0 y EspacioDIrecciones-1*/

int FoldAdd(char* palabra,int espaciodirecc){

	int tam = strlen(palabra);
	int letra1,letra2,i,sumaparcial=0,sumatotal=0;

	for(i=0;i<tam;i++){

		letra1=palabra[i];
		letra2=palabra[i+1];

		sumaparcial= ((letra1+letra2)%espaciodirecc);
		sumatotal +=sumaparcial;

		if (i+1 == tam) i=tam;
	}


		return (sumatotal%espaciodirecc);



}



