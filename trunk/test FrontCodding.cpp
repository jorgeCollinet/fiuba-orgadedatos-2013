#define prueba_para_la_estructura_de_front_codding
#ifndef prueba_para_la_estructura_de_front_codding
/*Esto es una prueba para la estructura de front codding, se espera que no pinche(por ahora)*/
#include "front_codding.h"

int main(void){
	Front_codding* fc = new Front_codding("archivo.dat");
	fc->modo_escritura();
	fc->agregar_palabra("perra");
	fc->agregar_palabra("perros");
	fc->agregar_palabra("perritos");
	fc->agregar_palabra("puchache");
	fc->agregar_palabra("yAhora");
	delete (fc);
	Front_codding* fc2 = new Front_codding("archivo.dat");
	fc2->modo_lectura();
	char* palabra;
	// Ojo que la función devuelve un char*, hay que hacer un delete!
	palabra = fc2 -> leer_proxima_palabra();
	cout << palabra << std::endl;
	delete(palabra);
	palabra = fc2 -> leer_proxima_palabra();
	cout << palabra << std::endl;
	delete(palabra);
	palabra = fc2 -> leer_proxima_palabra();
	cout << palabra << std::endl;
	delete(palabra);
	palabra = fc2 -> leer_proxima_palabra();
	cout << palabra << std::endl;
	delete(palabra);
	delete (fc2);
};
#endif
