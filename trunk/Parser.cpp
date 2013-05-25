#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

using namespace std;

/**Variables de mi parseo */

FILE* fd;
int documento;
unsigned int tam=0;
unsigned int pos=0;
char * palabra;
char letra;
char palabra1[20];


/* FUncion que agarra un archivo de texto, extrae los terminos, los guarda en
 * alguna estructura en memoria y.. ( tendria que ordenarla en memoria y grabar
 * a otro txt... ? ).
 */
void Parser(char* archivo) {

	fd= fopen(archivo,"r");

	if (fd == NULL){

		cout<<("\nError de apertura del archivo. \n\n");
	} else { // Abri mi archivo, listo para ser leido

		char* buffer;
		unsigned int ocupacionbuffer;


		while(feof(fd)==0) { // MIentras no se encuentra fin de archivo

			buffer = (char *)(malloc(2000*sizeof(char))); // Asigno memoria para el buffer donde se va a pasar la info del texto

			//Otengo de a parrafos, hasta encontrar /n, y los guardo en buffer.
			buffer = fgets(buffer,2000,fd); // 2000 es la cantidad de caracteres que leo, debe ser grande para tener todos los de 1 parrafo asi no se corta el parrafo (linea???)

			cout<<buffer;
			if(buffer == NULL) break;
			cout<<("TERMINOBUFFER");
			cout<<("\n");
			ocupacionbuffer = strlen(buffer);
			cout<<ocupacionbuffer;
			cout<<"\n";

			 unsigned int i,j;

			/**Debo Analizar cada parrafo*/
			for(i=0;i<ocupacionbuffer;i++){

				//Si no encuentro un espacio lo guardo en la palabra1
				if ((isspace(buffer[i])) == 0) {
					//Si no es espacio
					palabra1[tam] = buffer[i];
					tam++;
				} else {
					palabra = (char *)(malloc(tam*sizeof(char)));
					strcpy(palabra,palabra1);
					cout<<pos<<documento<<tam<<palabra;
					free(palabra);
					pos++;
					for(j=0;j<tam;j++){
					palabra1[j]=' ';
					}
					tam=0;

				}
				}
				free(buffer);
			}
        }
        fclose(fd);

}


