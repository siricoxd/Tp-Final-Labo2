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
    int idSucursal;
    struct nodoGananciasDia * listaDias;
}gananciasMes;

typedef struct{
    int anio;
    gananciasMes dato;
    struct nodoGananciasMes * sigMes;
}nodoGananciasMes;


//funciones inicializacion/creacion
nodoGananciasDia* inicGananciasMes();
nodoGananciasDia* crearGananciasDia(gananciasDia dato);
//f de busqueda
nodoGananciasDia* buscarUltimo(nodoGananciasDia* listaDias);
nodoGananciasDia* buscarPorDia(nodoGananciasDia* listaDias, int diaBuscado);
//f de agregado
nodoGananciasDia* agregarPpioGananciasDia(nodoGanancias* listaDias, nodoGananciasDia* nuevo);
nodoGananciasMeses* agregarFinalGananciasDia(nodoGananciasDia* listaDias, nodoGananciasDia* nuevo);
nodoGananciasDia* sumarGananciasDia(nodoGananciasDia* listaDias, gananciasDia dato);
nodoGananciasDia* insertarGananciasMes(nodoGananciasDia* listaDias, gananciasDia dato);
