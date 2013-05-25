#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

int main()
{
        char dirn[50];
        DIR *dir = NULL;
        struct dirent *drnt = NULL;

        printf("nombre del directorio: ");
        gets(dirn);

        dir=opendir(dirn);
        if(dir)
        {
                printf("Archivos:\n");
                while(drnt = readdir(dir))
                {
                        printf("%-20s\t\n", drnt->d_name);

                }
                closedir(dir);
        }
        else
        {
                printf("No se pudo abrir el directorio '%s'\n", dirn);
        }

        return 0;
}
