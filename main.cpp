#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <list>

/**Variables de mi parseo */

FILE * fd;
int documento;
int tam=0;
int pos=0;
char * palabra;
char letra;
char palabra1[20];



std::list<std::string>* Parseo(void) {

	std::list<std::string>* listaDePalabras = new std::list<std::string>();
	fd= fopen("prueba","r");

	if (fd == NULL){

		printf("\nError de apertura del archivo. \n\n");
	} else { // Abri mi archivo, listo para ser leido

		char* buffer;
		unsigned int ocupacionbuffer;


		while(feof(fd)==0) { // MIentras no se encuentra fin de archivo

			buffer = (char *)(malloc(2000*sizeof(char))); // Asigno memoria para el buffer donde se va a pasar la info del texto

			//Otengo de a parrafos, hasta encontrar /n, y los guardo en buffer.
			buffer = fgets(buffer,2000,fd); // 2000 es la cantidad de caracteres que leo, debe ser grande para tener todos los de 1 parrafo asi no se corta el parrafo (linea???)

			printf("%s \n",buffer);
			if(buffer == NULL) break;
			printf("%s","TERMINOBUFFER");
			printf("\n");
			ocupacionbuffer = strlen(buffer);
			printf("%d",ocupacionbuffer);
			printf("\n");

			int i,j;

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
					printf("%d,%d,%d,%s \n",pos,documento,tam,palabra);
					listaDePalabras->push_back(std::string(palabra));
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
        return listaDePalabras;
}

void quitarCaracteresInvalidos(std::list<std::string>* lista) {
//Quita los caracteres invalidos al final o al comienzo de cada palabra.
}

int main()
{
    std::list<std::string>* listaDePalabras = Parseo();
    //printf("Hello world!\n");
    for(std::list<std::string>::iterator it = listaDePalabras-> begin(); it != listaDePalabras -> end(); it++ ) {
		printf("%s \n", it->c_str());
	}
    
    return 0;
}
