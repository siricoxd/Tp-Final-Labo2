#ifndef LISTASPRODUCTOS_H_INCLUDED
#define LISTASPRODUCTOS_H_INCLUDED
#include <time.h>
#include <conio.h>
#include <string.h>
#define ARCHIVO_VENTAS "ventas.bin"

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
     char nombreDeProductos[40];
    int precioPorKilo;
    int stock;
    int id;
    int activoPro;
    char fechaVenta[11];   /// formato: AAAA-mm-DD
    int venta;


}StRegistroventas;

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


} REGISTROA;
//manejo de listas
nodoProductos * inicListaProduc();
nodoProductos *crearNuevonodoProductos(productos dato );
nodoProductos* agregarNuevonodoProductosAlPLista(nodoProductos*lista,nodoProductos *nuevonodoProductos);

//manejo de arreglo de listas
int buscaEnCatalogo(catalogo arreglo[],int validos,REGISTROA dato);
int altaCatalogo(catalogo arreglo[],int validos,REGISTROA dato);
int agregarALCatalogo(catalogo arreglo[],int validos,REGISTROA dato);
REGISTROA cargaRegistro();
productos pasarDeRegistroCatAPro(REGISTROA origen);

//cargaDeCatalogo
int pasardeArchivoAArreglo(char archivo[],catalogo arreglo[],int dim);
productos cargaDeProductos();
catalogo cargaDeUnaCateogoria();
void guardarUltimoId(char archivo[],int ultimoId);
int leerUltimoId(char archivo[]);

//FUNCIONES DE MUESTRA
void muestraDeCatalogo(catalogo A[],int validos);
void muestraUnCatalogo(catalogo A);
void muestraLISTA(nodoProductos *lista);
void mostrarUnProducto(productos dato);
//CARGA ARCHIVO DEPOSITO
REGISTROA cargaRegistro();
int cantidadDeRegistros();
void cargaArchivo(char archivo[]);
int generarIDUnico() ;




// MUESTRA DE ARCHIVOS
void muestraArchivo(char archivo[]);

//funciones de eliminar
void desactivarCatalogo(catalogo ar[], int id, int pos);
void descativarProducto(catalogo ar[],int id,int pos);
int buscaEnCatalogoPorId(catalogo arreglo[],int validos,int id);
void desactivarProducto(catalogo ar[], int id, int pos);

//funciones de menu
int menu();
int menuOpcion();

// crear archivo de ventas
StRegistroventas cambioDeEstrucCatalARegistro(productos dato);//transforma el tio de dato catlogo a uno de registroventa y cargo el la venta y el dia
int cargaVenta(int stock);
void cargarArchivoVentas(nodoProductos *lista, FILE *archi,int idDeProd );
void pasarDeArregloAArchivo(catalogo arreglo,int idDeProd,char archivo[]);
void modificarSatock(int idDelRegistro,int venta);
int cargaVenta(int stock);
void desactivarArchivoVentas (int id);
//MUESTRA ARCHIVO DE VENTAS
void muestraUnRegistroVentas(StRegistroventas dato);
void muestraArchivoVentas(char archivo[]);
#endif // LISTASPRODUCTOS_H_INCLUDED
