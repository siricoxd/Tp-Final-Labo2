#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int ganancias;
    int dia;
}gananciasDia;

typedef struct{
    ganancias dato;
    struct nodoGananciasDia * sigDia;
}nodoGananciasDia;

typedef struct{
    int mes;
    int idSucursal;
}gananciasMes;

typedef struct{
    int anio;
    struct nodoGananciasDia* listaDeMes;
    struct nodoGananciasMes * sigAnio;
}nodoGananciasMes;



/*typedef struct{
    int ganancias;
    int dia;
    int mes;
    int anio;
}gananciasDia;

typedef struct{

}nodoGananciasDia*/
