#include <stdio.h>
#include <stdlib.h>
#include "listasProductos.h"




int main()
{
   catalogo arreglo[40];
   int validos;
   arreglo->lista=inicListaProduc();

   validos=cargaCatalogo(arreglo,40);
   muestraDeCatalogo(arreglo,validos);

    return 0;
}
