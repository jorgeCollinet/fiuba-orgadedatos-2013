#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**Variables de mi parseo */

FILE * fd;
int documento;
int tam=0;
int pos=0;
char * palabra;
char letra;
char palabra1[20];


void Parseo(){

fd= fopen("prueba","r");

if (fd == NULL){

                printf("\nError de apertura del archivo. \n\n");
        }
        else{ // Abri mi archivo, listo para ser leido



char* buffer;
int ocupacionbuffer;


        while(feof(fd)==0){ // MIentras no se encuentra fin de archivo

            buffer= (char *)(malloc(2000*sizeof(char))); // Asigno memoria para el buffer donde se va a pasar la info del texto

            //Otengo de a parrafos, hasta encontrar /n, y los guardo en buffer.
            buffer = fgets(buffer,2000,fd); // 2000 es la cantidad de caracteres que leo, debe ser grande para tener todos los de 1 parrafo asi no se corta el parrafo

            printf("%s \n",buffer);
            if(buffer == NULL) break;
            printf("%s","TERMINOBUFFER");
            printf("\n");
            ocupacionbuffer= strlen(buffer);
            printf("%d",ocupacionbuffer);
            printf("\n");

  int i,j;

            /**Debo Analizar cada parrafo*/
            for(i=0;i<ocupacionbuffer;i++){

                //Si no encuentro un espacio lo guardo en la palabra1
                if ((isspace(buffer[i]))==0) {
                palabra1[tam]=buffer[i];
                tam++;
                } else{

            palabra = (char *)(malloc(tam*sizeof(char)));

            strcpy(palabra,palabra1);

            printf("%d,%d,%d,%s \n",pos,documento,tam,palabra);
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




int main()
{
    Parseo();
    //printf("Hello world!\n");
    return 0;
}
