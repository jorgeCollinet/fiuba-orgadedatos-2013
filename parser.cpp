#include "parser.h"
#include "ManejadorArchivos.h"
#include <iostream>
#include <fstream>
#include <cstring>

#ifndef CANTIDAD_TOTAL_NOPARSE
#define CANTIDAD_TOTAL_NOPARSE 48

using namespace std;

/*
 * Dado archivo lo parsea extrayendo las palabras. Lee linea por linea hasta eof
 * usa strtok para eliminar caracteres invalidos
 *
 *Falta guardaar en estructura...
 *Retorna true si salio  bien
 */
bool parser(std::string& archivoaParser){

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

                        cout<<palabra<<endl;

                        auxPalabra = strtok (NULL, *carac_invalidos);
                }
                delete []linea;
                delete auxPalabra;
        }


        return true;
 }


#endif

