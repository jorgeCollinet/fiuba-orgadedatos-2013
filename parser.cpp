/*
 * ParserTex.h
 *
 *  Created on: 06/06/2013
 *      Author: pablo
 */

#include "parser.h"
#include "ManejadorArchivos.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <list>

//#ifndef CANTIDAD_DE_SEPARADORES
#define CANTIDAD_DE_SEPARADORES 38



Parseador::Parseador(std::string& archivo){

	this->nombrearchivo=archivo;
}


Parseador::~Parseador(){

}


//Parsea el documento de texto extrayendo los terminos(filtrados) y su ubicacion en el mismo
bool Parseador::parser(){

			int pos=0; // Posicion de la palabra en el documento actual

	        std::string palabra;
	        const char* invalidos[CANTIDAD_DE_SEPARADORES] = {"¡!#$%&'( )*+,-.:;<=>¿?@[]^_`{|}~/\\\"\n"};
	        ManejadorArchivos archivo;

	        archivo.abrirLectura(this->nombrearchivo);
	        std::string auxLinea;

	        while ( archivo.leerunalinea(auxLinea)){
	                char *linea = new char[256];
	                strcpy(linea,auxLinea.c_str());
	                char* auxPalabra = strtok(linea,*invalidos);

	                while ( auxPalabra != NULL ){
	                        palabra = auxPalabra;
	                        pasarAminusculas(palabra);

	                        termino term;

	                        term.term=palabra;
	                        term.posi=pos;


	                        //trie.insertarPalabra(palabra,direccion);
	                        cout<<term.term<<" "<<term.posi<<endl;
	                        //cout<<palabra<<" "<<pos<<endl;
	                        pos++;
	                        auxPalabra = strtok (NULL, *invalidos);
	                }
	                delete []linea;
	                delete auxPalabra;
	        }




	        //mylist.push_back(os.str());

	        //delete archivo; // cierra el archivo, no lo borra
	        //delete direccion;

	        return true;
	 }


//Devuelve el nombre de mi archivo parseado
std::string Parseador::getnombre(){

	return this->nombrearchivo;


}

//Devuelve el nombre del archivo final dps de parsear y ordenar(va a hacer el nombre del archivo
//donde se va a grabar al final)
std::string Parseador::getnombrearchivofinal(){


	ostringstream os;

	os << this->nombrearchivo << "final";

	return os.str();


}




