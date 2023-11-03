#include <stdio.h>
#include <stdlib.h>
#include "listasProductos.h"
#define ARCHIVO_CATALOGO "catalogo.bin"



int main()
{
   catalogo arreglo[40];
   int validos=0;
   char rta;

    printf("\nARCHIVO:\n");
     muestraArchivo(ARCHIVO_CATALOGO);
    validos=bajarArchivo(ARCHIVO_CATALOGO,arreglo,40);



        printf("\ndesea cargar el arreglo: ");
        fflush(stdin);
        scanf("%c",&rta);
        if(rta=='s')
        {
            printf("\nARREGLO:\n");
             muestraDeCatalogo(arreglo,validos);

              validos=cargaCatalogo(arreglo,40,validos);
              muestraDeCatalogo(arreglo,validos);
              guardaEnArchivo(arreglo,validos,ARCHIVO_CATALOGO);


        }



    printf("\nARCHIVO:\n");


    return 0;
}
