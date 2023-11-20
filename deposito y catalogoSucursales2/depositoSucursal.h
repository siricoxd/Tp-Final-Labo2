#ifndef depositoSucursalSUCURSAL_H_INCLUDED
#define depositoSucursalSUCURSAL_H_INCLUDED
#include "listasProductos.h"
typedef struct
{
    char nombreDeproductosDepos[40];
    int precioPorKilo;
    int stock;
    int id;
    int activoPro;
} productosDepos;//de la sucursal

typedef struct nodoproductosDepos//de la sucursal
{
    productosDepos dato;
    struct nodoproductosDepos *siguiente;

} nodoproductosDepos;//de la sucursal
typedef struct
{
    int idDeSuc;
    char nombreDeCategoria[40];
    int idCategoria;
    int activoCat;
    struct nodoproductosDepos *lista;
} catalogoDepos;//de la sucursal


//typedef struct
//{
//    int idDeSuc;
//    char nombreDeproductosDepos[40];
//    int precioPorKilo;
//    int stock;
//    int id;
//    int activoPro;
//    char fechaVenta[11];   /// formato: AAAA-mm-DD
//    int venta;
//
//
//} StRegistroventas;



typedef struct
{

    int idDeSuc;
    char nombreDeCategoria[40];
    int idCategoria;
    int activoCat;

    char nombreDeproductosDepos[40];
    int precioPorKilo;
    int stock;
    int id;
    int activoPro;



}depositoSucursal;



//manejo de listas
nodoproductosDepos * inicListaProducSucursal();
nodoproductosDepos *crearNuevonodoproductosDepos(productosDepos dato );
nodoproductosDepos* agregarNuevonodoproductosDeposAlPLista(nodoproductosDepos*lista,nodoproductosDepos *nuevonodoproductosDepos);

//manejo de arreglo de listas
int buscaEncatalogoDepos(catalogoDepos arreglo[],int validos,depositoSucursal dato);
int altacatalogoDepos(catalogoDepos arreglo[],int validos,depositoSucursal dato);
int agregarALcatalogoDepos(catalogoDepos arreglo[],int validos,depositoSucursal dato);
productosDepos pasarDeRegistroCatAProSucursal(depositoSucursal origen);

//cargaDecatalogoDepos
int pasardeArchivoAArregloSucursal(char archivo[],catalogoDepos arreglo[],int dim,int idDeSucu);


//carga de archivo DeposioSucursal
void recorrerDeposito(char archivoDepos[],char archivoDepoSuc[],int idDeSuc,int idDato,int stock);

void cargaArchivoDepositoSucursal(char archivoDepoSuc[],deposito dato,int idDeSuc,int stock);

depositoSucursal pasarDeDepositoASucursal(deposito dato,int idDeSuc,int stock);

int cargarStockYmodificarlos (char archivo[], nodoProductos *produc);
int cargarstock(int stock);

int modificarStockEnArchivoDepSuc(char archivo[], int idDePro,int idDeSuc, int stock);

int buscaPosDelArchivo (char archivo[], int idDePro,int idDeSuc);


//FUNCIONES DE MUESTRA
void muestraDecatalogoSucursal(catalogoDepos A[],int validos);
void muestraUncatalogoSucursal(catalogoDepos A);
void muestraLISTASucursal(nodoproductosDepos *lista);
void mostrarUnProductoSucursal(productosDepos dato);
void muestraUnRegistroSucursal(depositoSucursal dato);
void muestraArchivoSucursal(char archivo[]);

//ELIMINAR PRODUCTO EN DEPOSITO SUCURSAL

void desactivarProductoEnSucursal(char archivo[], catalogoDepos arreglo[],int pos,nodoProductos* id,int idDeSuc);


#endif // depositoSucursalSUCURSAL_H_INCLUDED
