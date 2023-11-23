#ifndef PROVEDORES_H_INCLUDED
#define PROVEDORES_H_INCLUDED
#include"depositoSucursal.h"


typedef struct {
     char nombre[20];
     int stock;
} provedor;


typedef struct nodoDobleProvedores
{
     provedor dato;
     struct nodoDobleProvedores * anterior;//aloja la pos del nodo anterior
     struct nodoDobleProvedores * siguiente; //aloja la posicion del nodo sig
} nodoDobleProvedores;


typedef struct fila
{

    nodoDobleProvedores *prim;//nodo que apunta al primero de la lista
    nodoDobleProvedores *ult;//nodo que apunt al ultimo de la lista
}fila;

//TDA LISTAS DOBLES
nodoDobleProvedores* inicializarListaD();
void crearNuevoNodo(nodoDobleProvedores **nuevo,provedor dato);
void agregarALP(nodoDobleProvedores **lista,nodoDobleProvedores *nuevo);
nodoDobleProvedores   *buscarUltimNodo(nodoDobleProvedores *lista);
nodoDobleProvedores * buscarNodoPorCampo(nodoDobleProvedores *lista,provedor dato);
void muestraUnNodD(provedor A);
void agregarALF(nodoDobleProvedores **lista, nodoDobleProvedores *nuevo);
void muestraLista(nodoDobleProvedores *seg);
provedor cargaUnaprovedor();


//FILAS


void  inicFila(fila *f);
void agregarAlaFila(fila *F,nodoDobleProvedores* nuevo);
int filaVacia(fila F);
void mostrarFila(fila F);
void cargaUnaFila(fila *F);
void verPrimer(fila F);
void extraerFila(fila *F);




//carga de provedores


void pasarDeDepositoAAFilas(catalogo arreglo[], int validos, fila *prov, char archivoDepos[]);
void cargaFilaDeProvedores(catalogo dato, fila *prov, char archivoDepos[]);
provedor cambioDeEstrucCatalAFila(productos dato, char archivoDepos[]);
int cargaCompra();
void modificarSatockDeposito(char archi[], int idDelRegistro, int compra);
#endif // PROVEDORES_H_INCLUDED
