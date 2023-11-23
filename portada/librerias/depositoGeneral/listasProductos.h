#ifndef LISTASPRODUCTOS_H_INCLUDED
#define LISTASPRODUCTOS_H_INCLUDED
#include <time.h>
#include <conio.h>
#include <string.h>
#define ARCHIVO_VENTAS "ventas.bin"
#define ARCHIVO_DEPOSITO "deposito.bin"
#include"../depostitoPorSucursal/depositoSucursal.h"
typedef struct
{
    char nombreDeProductos[40];
    int precioPorKilo;
    int stock;
    int id;
    int activoPro;
} productos;

typedef struct nodoProductos
{
    productos dato;
    struct nodoProductos *siguiente;

} nodoProductos;
typedef struct
{
    char nombreDeCategoria[40];
    int idCategoria;
    int activoCat;
    struct nodoProductos *lista;
} catalogo;




typedef struct
{

    char nombreDeCategoria[40];
    int idCategoria;
    int activoCat;

    char nombreDeProductos[40];
    int precioPorKilo;
    int stock;
    int id;
    int activoPro;


} deposito;
//manejo de listas
nodoProductos * inicListaProduc();
nodoProductos *crearNuevonodoProductos(productos dato );
nodoProductos* agregarNuevonodoProductosAlPLista(nodoProductos*lista,nodoProductos *nuevonodoProductos);

//manejo de arreglo de listas
int buscaEnCatalogo(catalogo arreglo[],int validos,deposito dato);
int altaCatalogo(catalogo arreglo[],int validos,deposito dato);
int agregarALCatalogo(catalogo arreglo[],int validos,deposito dato);
deposito cargaRegistro();
productos pasarDeRegistroCatAPro(deposito origen);

//cargaDeCatalogo
int pasardeArchivoAArreglo(char archivo[],catalogo arreglo[],int dim);



//FUNCIONES DE MUESTRA
void muestraDeCatalogo(catalogo A[],int validos);
void muestraUnCatalogo(catalogo A);
void muestraLISTA(nodoProductos *lista);
void mostrarUnProducto(productos dato);
void muestraUnRegistro(deposito dato);

//muestra todos
void muestraDeCatalogoTodos(catalogo A[],int validos);
void muestraUnCatalogoTodos(catalogo A);
void muestraLISTATODOs(nodoProductos *lista);

//CARGA ARCHIVO DEPOSITO
deposito cargaRegistro();
int cantidadDeRegistros();
void cargaArchivo(char archivo[]);
int generarIDUnico() ;


int cantidadDeRegistros();


// MUESTRA DE ARCHIVOS
void muestraArchivo(char archivo[]);

//funciones de eliminar
void desactivarCatalogo(char archivo[],catalogo ar[], int id, int pos);
void desactivarProducto(char archivo[],catalogo ar[], int pos,nodoProductos* id);
int buscaEnCatalogoPorId(catalogo arreglo[],int validos,int id);
nodoProductos *buscaEnListaId(catalogo arreglo[],int pos,int idDePro);
void activarProducto(char archivo[], catalogo arreglo[],int pos,nodoProductos* id);
void activarCatalogo(char archivo[],catalogo ar[], int id, int pos);
//funciones de menu
int menu();
int menuOpcion();


//MUESTRA ARCHIVO DE VENTAS
//void muestraUnRegistroVentas(StRegistroventas dato);
//void muestraArchivoVentas(char archivo[]);
#endif // LISTASPRODUCTOS_H_INCLUDED
