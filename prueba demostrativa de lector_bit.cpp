/*
 * main.cpp
 *
 *  Created on: 21/05/2013
 *      Author: jorge
 */


#include "lector_bit.h"
#include "escritor_bit.h"
using namespace std;
// caso de muestra de como usar lector_bit.h
/*
int main(){

	Escritor_bit escritor ("mi prueba.txt");
	/*
	 * si se quiere probar este , comentar el otro metodo
	 * NUNCA USAR LOS DOS AL MISMO TIEMPO
	escritor.escribir_bit_desde_abajo(1);
	escritor.escribir_bit_desde_abajo(1);
	escritor.escribir_bit_desde_abajo(1);
	escritor.escribir_bit_desde_abajo(1);
	escritor.escribir_bit_desde_abajo(1);
	escritor.escribir_bit_desde_abajo(1);
	escritor.escribir_bit_desde_abajo(1);
	escritor.escribir_bit_desde_abajo(0);

	escritor.escribir_bit_desde_abajo(0);
	escritor.escribir_bit_desde_abajo(1);
	escritor.escribir_bit_desde_abajo(1);
	escritor.escribir_bit_desde_abajo(1);
	escritor.escribir_bit_desde_abajo(1);
	escritor.escribir_bit_desde_abajo(1);
	escritor.escribir_bit_desde_abajo(1);
	escritor.escribir_bit_desde_abajo(1);
	*/
	escritor.escribir_bit_desde_arriba(1);
	escritor.escribir_bit_desde_arriba(1);
	escritor.escribir_bit_desde_arriba(1);
	escritor.escribir_bit_desde_arriba(1);
	escritor.escribir_bit_desde_arriba(1);
	escritor.escribir_bit_desde_arriba(1);
	escritor.escribir_bit_desde_arriba(1);
	escritor.escribir_bit_desde_arriba(0);

	escritor.escribir_bit_desde_arriba(0);
	escritor.escribir_bit_desde_arriba(1);
	escritor.escribir_bit_desde_arriba(1);
	escritor.escribir_bit_desde_arriba(1);
	escritor.escribir_bit_desde_arriba(1);
	escritor.escribir_bit_desde_arriba(1);
	escritor.escribir_bit_desde_arriba(1);
	escritor.escribir_bit_desde_arriba(1);

	// aca pruebo q a pesar de no completar los bits el resto se llena de ceros
	escritor.escribir_bit_desde_arriba(1);

	escritor.cerrar_escritor();

//------------------------------------------------------------

	// leo lo que anter escribí
	LectorBit lector("mi prueba.txt");
	cout<<"prueba: "<<endl;
	int cont=1;
	int num=0;
	int aux=0;

	while(true) {
		// simplemente se pide un bit
		num=lector.leer_bit();
		// aca se verifica que no llegué a fin de archivo
		if(lector.eof()){
			break;
		}
		cout<<num;
		if(cont==8){
			cont=0;
			cout<<endl;
		}
		cont++;
		aux++;
	}

}
*/
