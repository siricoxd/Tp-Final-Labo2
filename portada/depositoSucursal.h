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

typedef struct nodoproductosSucursal//de la sucursal
{
    productosDepos dato;
    struct nodoproductosSucursal *siguiente;

} nodoproductosSucursal;//de la sucursal
typedef struct
{
    int idDeSuc;
    char nombreDeCategoria[40];
    int idCategoria;
    int activoCat;
    struct nodoproductosSucursal *lista;
} catalogoSuc;//de la sucursal




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
nodoproductosSucursal * inicListaProducSucursal();
nodoproductosSucursal *crearNuevonodoproductosSucursal(productosDepos dato );
nodoproductosSucursal* agregarNuevonodoproductosSucursalAlPLista(nodoproductosSucursal*lista,nodoproductosSucursal *nuevonodoproductosSucursal);

//manejo de arreglo de listas
int buscaEncatalogoSuc(catalogoSuc arreglo[],int validos,depositoSucursal dato);
int altacatalogoSuc(catalogoSuc arreglo[],int validos,depositoSucursal dato);
int agregarALcatalogoSuc(catalogoSuc arreglo[],int validos,depositoSucursal dato);
productosDepos pasarDeRegistroCatAProSucursal(depositoSucursal origen);

//cargaDecatalogoSuc
int pasardeArchivoAArregloSucursal(char archivo[],catalogoSuc arreglo[],int dim,int idDeSucu);


//carga de archivo DeposioSucursal
void recorrerDeposito(char archivoDepos[],char archivoDepoSuc[],int idDeSuc,int idDato,int stock);

void cargaArchivoDepositoSucursal(char archivoDepoSuc[],deposito dato,int idDeSuc,int stock);

depositoSucursal pasarDeDepositoASucursal(deposito dato,int idDeSuc,int stock);

int cargarStockYmodificarlos (char archivo[], nodoProductos *produc);
int cargarstock(int stock);

int modificarStockEnArchivoDepSuc(char archivo[], int idDePro,int idDeSuc, int stock);

int buscaPosDelArchivo (char archivo[], int idDePro,int idDeSuc);


//FUNCIONES DE MUESTRA
void muestraDecatalogoSucursal(catalogoSuc A[],int validos);
void muestraUncatalogoSucursal(catalogoSuc A);
void muestraLISTASucursal(nodoproductosSucursal *lista);
void mostrarUnProductoSucursal(productosDepos dato);
void muestraUnRegistroSucursal(depositoSucursal dato);
void muestraArchivoSucursal(char archivo[]);
void muestraLISTASucursalTodos(nodoproductosSucursal *lista);
void muestraUncatalogoSucursalTodos(catalogoSuc A);
void muestraDecatalogoSucursalTodos(catalogoSuc A[],int validos);
//ELIMINAR PRODUCTO EN DEPOSITO SUCURSAL
void desactivarProductoEnSucursal(char archivo[], catalogoSuc arreglo[], int pos, nodoproductosSucursal* id, int idDeSuc);
int buscaEnCatalogoPorIdSUCURSAL(catalogoSuc arreglo[],int validos,int id);
nodoproductosSucursal* buscaEnListaIdSucursal(catalogoSuc arreglo[],int pos,int idDePro);
int buscaEnCatalogoPorIdSUCURSAL(catalogoSuc arreglo[], int validos, int id);
void desactivarCatalogoSucursal(char archivo[],catalogoSuc ar[], int id, int pos,int idDeSuc);

void activarCatalogoSucursal(char archivo[],catalogoSuc ar[], int id, int pos,int idDeSuc);
void activarProductoEnSucursal(char archivo[], catalogoSuc arreglo[], int pos, nodoproductosSucursal* id, int idDeSuc);
#endif // depositoSucursalSUCURSAL_H_INCLUDED
