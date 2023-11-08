#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int ganancias;
    int dia;
}gananciasDia;

typedef struct{
    gananciasDia dato;
    struct nodoGananciasDia * sigDia;
}nodoGananciasDia;

typedef struct{
    int mes;
    struct nodoGananciasDia * listaDias;
}gananciasMes;

typedef struct{
    gananciasMes dato;
    struct nodoGananciasMes * sigMes;
}nodoGananciasMes;
// no hay idSucursal, para q nodoGananciasMes sea un parametro de la estructura de una sucursal


///FUNC DIAS
//funciones inicializacion/creacion
nodoGananciasDia* inicGananciasDia();
nodoGananciasDia* crearGananciasDia(gananciasDia dato);
//f de busqueda
nodoGananciasDia* buscarUltimo(nodoGananciasDia* listaDias);
nodoGananciasDia* buscarPorDia(nodoGananciasDia* listaDias, int diaBuscado);
//f de agregado
nodoGananciasDia* agregarPpioGananciasDia(nodoGanancias* listaDias, nodoGananciasDia* nuevo);
nodoGananciasMeses* agregarFinalGananciasDia(nodoGananciasDia* listaDias, nodoGananciasDia* nuevo);
nodoGananciasDia* sumarGananciasDia(nodoGananciasDia* listaDias, gananciasDia dato);
nodoGananciasDia* insertarGananciasDia(nodoGananciasDia* listaDias, gananciasDia dato);
//


///FUNC MES
nodoGananciasMes* inicGananciasMes*();
nodoGananciasMes* crearGananciasMes(gananciasMes dato);
nodoGananciasMes* agregarPpioGananciasMes(nodoGananciasMes* listaMes, nodoGananciasMes* nuevo);
nodoGananciasMes* agregarFinalGananciasMes(nodoGananciasMes* listaMes, nodoGananciasMes* nuevo);
nodoGananciasMes* buscarUltimoMes(nodoGananciasMes* listaMes);
nodoGananciaMes* insertarGananciasMes(nodoGananciasMes* listaMes, gananciasMes dato);
nodoGananciasMes* sumarGananciasMes(nodoGananciasMes* listaMes, gananciasMes dato);
