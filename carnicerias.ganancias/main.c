#include <stdio.h>
#include <stdlib.h>
#include "ganancias.h"

int main(){

    nodoGananciasAnio* listaGanancias=inicLista();
    ganancias dato=cargarGananciasUnDia();
    listaGanancias=insertarGananciasNodo(listaGanancias, dato);
    mostrarGananciasAnio(listaGanancias->dato.ganancias);
    return 0;
}
