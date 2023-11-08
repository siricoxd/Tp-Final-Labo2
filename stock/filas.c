#include "filas.h"
#include <stdio.h>
#include <stdlib.h>


void inicFila(Fila * f)
{
    inicListaLD(&f->inicio);
    inicListaLD(&f->fin);
}
void agregar(Fila*f,int dato)
{
    nodoLD*nuevo=crearNodoLD(dato);
    if(&f->inicio==NULL)
    {
        f->inicio=nuevo;
        f->fin=nuevo;
    }
    else{
       agregarAlFinalLD(&f->inicio,nuevo);
        f->fin=nuevo;
    }
}
int extraer(Fila * f)
{
    int rta=-1;
    if(f->inicio!=NULL)
    {
        rta=verPrimero(f->inicio);
        f->fin=borarrPrimero(f->inicio);
        if(f->inicio==NULL)
        {
            inicListaLD(&f->fin);
        }
    }
    return rta;
}
int verPrimero(nodoLD * lista)
{
    int rta=0;
    if(lista)
        rta=lista->dato;
    return rta;
}

nodoLD* borarrPrimero(nodoLD* lista)
{
    nodoLD*aborrar=lista;
    if(lista!=NULL)
    {
        lista=lista->siguiente;
        if(lista!=NULL)
        {
            lista->ante=NULL;
        }
        free(aborrar);
    }
    return lista;
}
void mostrar(Fila * f)
{

    if(f->inicio!=NULL)
    {
        while(f->inicio!=NULL)
        {
        printf("\nPrincipio----------------------Fin\n");
        mostrarListaLD(f->inicio);
        printf("\nPrincipio----------------------Fin\n");
        }

    }
    else{
        printf("La Fila esta vacia.\n");
    }
}
int primero(Fila*f)
{
    int rta=-9999;
    if(f->inicio!=NULL)
    {
        rta=verPrimero(f->inicio);
    }
    else{
        printf("La Fila esta vacia, se retornara -9999\n");
    }
    return rta;
}
void leer(Fila *f)
{
    int x=0;
    printf("Ingrese el dato: ");
    scanf("%d",&x);
    agregar(f,x);
}
int filavacia(Fila*f)
{
    int flag=0;
    if(f->inicio!=NULL){
        flag=1;

    }
    return flag;
}
