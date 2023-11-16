#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
nodoGananciasAnio* crearNodo(ganancias dato);
nodoGananciasAnio* agregarAnioGananciasPpio(nodoGananciasAnio* lista, nodoGananciasAnio* nuevo);
nodoGananciasAnio* buscarUltimoAnio(nodoGananciasAnio* lista);
nodoGananciasAnio* agregarAnioGananciasFinal(nodoGananciasAnio* lista, nodoGananciasAnio* nuevo);
nodoGananciasAnio* insertarGananciasNodo(nodoGananciasAnio* lista, ganancias nuevo);
nodoGananciasAnio* sumarGananciasNodo(nodoGananciasAnio* lista, nodoGananciasAnio* nuevo);
nodoGananciasAnio* buscarPosAnio(nodoGananciasAnio* lista, int anio);

//func arreglo
void inicArregloGanancias(int ganancias[MESES][DIAS]);
void sumarGananciaADia(int ganancias[MESES][DIAS], int mes, int dia, int sumaGanancia);
void sumarGanancias(int ganancias[MESES][DIAS], int nuevasGanancias[MESES][DIAS]);


//func usuario
ganancias cargarGananciasUnDia();
int cargarAnio();

int precioPorVenta(int precio, int ventas);

void listaToArchivo(nodoGananciasAnio* lista);
nodoGananciasAnio* archivoToLista();
void obtenerFecha(char fechaVenta[11], int *anio, int *mes, int *dia);
nodoGananciasAnio* ventasToLista(nodoGananciasAnio* lista, int ventas, int precio, char fechaVenta[11]);
ganancias ventasToGanancias(int ventas, int precio, char fechaVenta[11]);
void gananciasABarchivo(int ventas, int precio, char fechaVenta[11]);

void numeroAString(char* nombreMes, int mes);
