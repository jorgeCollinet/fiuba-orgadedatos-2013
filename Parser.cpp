#include "Parser.h"
#include "ManejadorArchivos.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <list>

#ifndef CANTIDAD_TOTAL_NOPARSE
#define CANTIDAD_TOTAL_NOPARSE 48

using namespace std;

/*
 * Dado archivo lo parsea extrayendo las palabras. Lee linea por linea hasta eof
 * usa strtok para eliminar caracteres invalidos
 * EL 2DO Parametro es donde es la lista donde se va a ir guardando el nombre que parsea para
 * luego darsela al merge
 *Falta guardaar en estructura...
 *Retorna true si salio  bien
 */
bool parser(std::string& archivoaParser,list<std::string> mylist){

		int pos=0; // Posicion de la palabra en el documento actual
        std::string palabra;
        const char* carac_invalidos[CANTIDAD_TOTAL_NOPARSE] = {"¡!#$%&'( )*+,-.:;<=>¿?@[]^_`{|}~/\\\"\n"};
        ManejadorArchivos archivo;

        archivo.abrirLectura(archivoaParser);
        std::string aux;

        while ( archivo.leerunalinea(aux)){
                char *linea = new char[256];
                strcpy(linea,aux.c_str());
                char* auxPalabra = strtok(linea,*carac_invalidos);

                while ( auxPalabra != NULL ){
                        palabra = auxPalabra;

                        cout<<palabra<<" "<<pos<<endl;
                        pos++;
                        auxPalabra = strtok (NULL, *carac_invalidos);
                }
                delete []linea;
                delete auxPalabra;
        }


        return true;
 }


#endif

