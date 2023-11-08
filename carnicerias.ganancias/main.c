#include <stdio.h>
#include <stdlib.h>
#include "ganancias.h"

int main(){

    nodoGananciasMes* listaMes=inicListaMes();
    gananciasDia asd;
    asd.dia=23;
    asd.ganancias=3000;
    nodoGananciasDia* listaDias=inicListaDias();
    listaDias=insertarGananciasDia(listaDias, asd);
    mostrarGananciasUnDia(listaDias->dato);
    return 0;
}
