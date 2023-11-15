#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <../carnicerias.sucursales/listasSucusrsales.h>
#define MESES 12
#define DIAS 31

static const char nombreArchivoGanancias[]="archivoGanancias.dat";

typedef struct{
    int anio;
    int ganancias[MESES][DIAS];
}ganancias;

typedef struct nodoGananciasAnio{
    ganancias dato;
    struct nodoGananciasAnio * siguiente;
}nodoGananciasAnio;


//func nodo
nodoGananciasAnio* inicLista();
nodoGananciasAnio* asignarMemoriaNodo();
nodoGananciasAnio* crearNodo(ganancias dato);
nodoGananciasAnio* agregarAnioGananciasPpio(nodoGananciasAnio* lista, nodoGananciasAnio* nuevo);
nodoGananciasAnio* buscarUltimoAnio(nodoGananciasAnio* lista);
nodoGananciasAnio* agregarAnioGananciasFinal(nodoGananciasAnio* lista, nodoGananciasAnio* nuevo);
nodoGananciasAnio* insertarNodo(nodoGananciasAnio* lista, nodoGananciasAnio* nuevo);
nodoGananciasAnio* sumarGananciasNodo(nodoGananciasAnio* lista, nodoGananciasAnio* nuevo);
nodoGananciasAnio* buscarPosAnio(nodoGananciasAnio* lista, int anio);

//func arreglo
void inicArregloGanancias(int ganancias[MESES][DIAS]);
void sumarGananciaADia(int ganancias[MESES][DIAS], int fecha[2], int sumaGanancia);
void sumarGanancias(int ganancias[MESES][DIAS], int nuevasGanancias[MESES][DIAS]);
