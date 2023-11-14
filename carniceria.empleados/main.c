#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miotrabajo.h"
#define archivoTrabajadores "archivotrabajadores.bin"

int main()
{

cargarArchivo(archivoTrabajadores);
//mostrarArchivo(archivoTrabajadores);

nodoLista* lista=iniclista();

lista=pasarDelArchivoToLDA(archivoTrabajadores, lista);
mostrarLDA(lista);

lista=darDeBaja(lista);
printf("Despues de baja: \n");
mostrarLDA(lista);
mostrarBajas(lista);

/*/
lista=darDeAlta(lista);
printf("Despues de alta: \n");
mostrarLDA(lista);
/*/


//remove(archivoTrabajadores);
    return 0;
}
