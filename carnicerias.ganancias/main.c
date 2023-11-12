#include <stdio.h>
#include <stdlib.h>
#include "ganancias.h"

int main(){

    nodoGananciasAnio* listaGanancias=inicLista();
    listaGanancias=asignarMemoriaNodo();

    /*int asd[MESES][DIAS];
    asd[4][7]=1234;
    ganancias fffff;
    fffff.anio=2018;
    sumarGanancias(fffff.ganancias, asd);
    listaGanancias=crearNodo(fffff);*/

    inicArregloGanancias(listaGanancias->dato.ganancias);
    mostrarGananciasAnio(listaGanancias->dato.ganancias);
    return 0;
}
