/*Esto es una prueba para la estructura de front codding, se espera que no pinche(por ahora)*/
#include "front_codding.h"

int main(void){
	Front_codding* fc = new Front_codding("archivo.dat");
	fc->agregar_palabra("perra");
	fc->agregar_palabra("perros");
	fc->agregar_palabra("perritos");
	fc->agregar_palabra("puchache");
	fc->agregar_palabra("yAhora");
	delete (fc);
};
