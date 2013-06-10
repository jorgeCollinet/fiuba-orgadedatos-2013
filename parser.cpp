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
	                        //Utilities.pasarAminusculas(palabra);

	                        termino term;

	                        term.term=palabra;
	                        term.posi=pos;

	                        //Meto en mi lista el conjunto palabra-posicion
	                        this->milista.push_back(term);
	                        //cout<<term.term<<" "<<term.posi<<endl;

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

int Parseador::cantidadpalabras(){

	return this->milista.size();

}

//Defino un ordenamiento de estructuras para mi lista
bool Parseador::ordenamiento(termino const& izq,termino const& der){

	if (izq.term != der.term)

	     return (izq.term < der.term);

	if (izq.posi != der.posi)

	     return (izq.posi < der.posi);

	else return true;
}

void Parseador::mostrarlista(){

	std::list<termino>::iterator it;
	//itero mi lista
	for(it=this->milista.begin();it != this->milista.end(); ++it){

		cout<<(*it).term<<(*it).posi<<endl;


	}


}

//Ordeno mi lista con mi metodo de ordenamiento prefijado
void Parseador::ordenarlistaposta(){

	this->milista.sort(&ordenamiento);

}

