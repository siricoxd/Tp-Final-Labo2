#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ventas.h"
#define MESES 12
#define DIAS 31
#define DIAS_EN_MES {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}

static const char nombreArchivoGanancias[]="ganancias.bin";
static const char nombreArchivoVentas[]="ventas.bin";

typedef struct{
    int anio;
    int idSucursal;
    int arrayGanancias[MESES][DIAS];
}ganancias;

typedef struct nodoGananciasAnio{
    ganancias dato;
    struct nodoGananciasAnio * siguiente;
    struct nodoGananciasAnio * anterior;
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
void sumarGanancias(int ganancias[MESES][DIAS], const int nuevasGanancias[MESES][DIAS]);
//mostrado
void mostrarTodasGanancias(nodoGananciasAnio* lista);
void mostrarGananciasSucursal(nodoGananciasAnio* lista, int id);
void mostrarGananciasAnio(nodoGananciasAnio* lista, int anio);
void mostrarGanancias(int ganancias[MESES][DIAS]);

//func usuario
ganancias cargarGananciasUnDia();
int cargarAnio();

int precioPorVenta(int precio, int ventas);

//archivo
void crearArchivoGanancias(nodoGananciasAnio* lista);
nodoGananciasAnio* archivoToLista();
void obtenerFecha(char fechaVenta[11], int *anio, int *mes, int *dia);
nodoGananciasAnio* ventasToLista(nodoGananciasAnio* lista, StRegistroventas ventas);
ganancias ventasToGanancias(StRegistroventas ventas);
void gananciasABarchivo(StRegistroventas ventas);
void sumarGananciasArchivo(StRegistroventas ventas);
int buscarEnArchivoGanancias(FILE* archivo, ganancias dato);

void numeroAString(char* nombreMes, int mes);

void crearArchivoGananciasConVentas();
StRegistroventas cargarVentas();
