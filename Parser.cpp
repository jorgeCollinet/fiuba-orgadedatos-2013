#include "Parser.h"
#include "ManejadorArchivos.h"
#include <iostream>
#include <fstream>
#include <cstring>

#ifndef CANTIDAD_TOTAL_NOPARSE
#define CANTIDAD_TOTAL_NOPARSE 48

using namespace std;

/*
 * Dado un documento de texto, lo parsea (extrae los terminos relevantes)
 * y los almacena en la estructura dada.
 *
 * @param archivoAparsear: es el puntero al archivo a parsear.
 * @param arbol: es la estructura para guardar las palabras.
 *
 * @return true si termino bien, false caso contrario
 */
bool parser(std::string& archivoAparsear){

        std::string palabra;
        const char* invalidos[CANTIDAD_TOTAL_NOPARSE] = {"¡!#$%&'( )*+,-.0123456789:;<=>¿?@[]^_`{|}~/\\\"\n"};
        ArchivoTexto archivo;

        archivo.abrirParaLectura(archivoAparsear);
        std::string auxLinea;

        while ( archivo.leerLinea(auxLinea)){
                char *linea = new char[CANT_MAX];
                strcpy(linea,auxLinea.c_str());
                char* auxPalabra = strtok(linea,*invalidos);

                while ( auxPalabra != NULL ){
                        palabra = auxPalabra;
                        //Utilidades::pasarAminusculas(palabra);
                        //trie.insertarPalabra(palabra,direccion);
                        cout<<palabra<<endl;

                        auxPalabra = strtok (NULL, *invalidos);
                }
                delete []linea;
                delete auxPalabra;
        }


        return true;
 }


#endif

