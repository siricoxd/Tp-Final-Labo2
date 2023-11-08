#include <stdio.h>
#include <malloc.h>
#include "listasDobles.h"

/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
nodoLD *crearNodoLD(int dato)
{
    nodoLD* nuevo=(nodoLD*)malloc(sizeof(nodoLD));
    nuevo->dato=dato;
    nuevo->ante=NULL;
    nuevo->siguiente=NULL;
    return nuevo;
}


void inicListaLD(nodoLD**lista)//inicializar lista en null
{
    *lista=NULL;
}
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
void mostrarNodoLD(nodoLD*lista)
{
    printf(" %d \n",lista->dato);
}
void mostrarListaLD(nodoLD*lista)
{
    int i=1;
    if(lista==NULL)
    {
        printf("\tLa lista esta vacia.\n");
    }
    else
    {
        nodoLD* seguidora=lista;
        while(seguidora!=NULL)
        {
            printf("\nNodo %d: ",i);
            mostrarNodoLD(seguidora);
            seguidora=seguidora->siguiente;
            i++;
        }
    }
}
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
nodoLD*buscarUltimoLD(nodoLD*lista)
{
    nodoLD*seg=lista;
    if(seg != NULL)
    {
        while(seg->siguiente!=NULL)
        {
            seg=seg->siguiente;
        }
    }

    return seg;
}
int buscarNodoLD(nodoLD*lista,int objetivo)
{
    int flag=0;

    if(lista==NULL)
    {
        printf("La lista esta vacia.\n");
    }
    else
    {
        nodoLD* seguidora=lista;
        while(seguidora!=NULL&&flag==0)
        {
            if(seguidora->dato==objetivo)
            {
                flag=1;
            }
            seguidora=seguidora->siguiente;
        }
    }

    return flag;
}
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
void borrarNodoLD(nodoLD**lista,int objetivo)
{
    if((*lista)!=NULL)
    {
        if(objetivo==(*lista)->dato)
        {
            nodoLD* aBorrar=*lista;
            *lista=(*lista)->siguiente;
            if(*lista!=NULL)
            {
                (*lista)->ante=NULL;
            }
            free(aBorrar);// solo sirve para borrar memoria dinamica (creado con malloc)

        }
        else
        {
            nodoLD*ante=*lista;
            nodoLD*seg=(*lista)->siguiente;
            while(seg!=NULL&& objetivo!=seg->dato)
            {
                ante=seg;
                ante=seg->siguiente;
            }
            if(seg!=NULL)
            {
                ante->siguiente=seg->siguiente;//bypas
                nodoLD*aux=seg->siguiente;
                if(aux!=NULL)
                {
                    aux->ante=ante;
                }
                free(seg);
            }
        }
    }
}
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
void agregarAlPpioLLD(nodoLD**lista,nodoLD*nuevo)
{
    if((*lista)==NULL) //si la lista esta vacia
    {
        *lista=nuevo;
    }
    else// si la lista tiene algo
    {
        (*lista)->ante=nuevo;
        nuevo->siguiente=*lista;
        nuevo->ante=NULL;
        *lista=nuevo;
    }
}
void agregarAlFinalLD(nodoLD**lista,nodoLD*nuevo)
{

    if(*lista==NULL)
    {
        *lista=nuevo;
    }
    else
    {
        nodoLD*ultimo;
        ultimo=buscarUltimoLD(*lista);
        ultimo->siguiente=nuevo;
        nuevo->ante=ultimo;

    }
}
void agregarEnOrdenLD(nodoLD**lista,nodoLD*nuevoNodo)
{
    if(*lista==NULL)
    {
        *lista=nuevoNodo;
    }
    else
    {
        if(nuevoNodo->dato<(*lista)->dato)
        {
            agregarAlPpioLLD(lista,nuevoNodo);
        }
        else
        {
            nodoLD*ante=*lista;
            nodoLD*seg=(*lista)->siguiente;
            while(seg!=NULL&&nuevoNodo->dato>=seg->dato)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            nuevoNodo->siguiente=seg;
            nuevoNodo->ante=ante;
            ante->siguiente=nuevoNodo;
            if(seg!=NULL)
            {
                seg->ante=nuevoNodo;
            }
        }
    }
}
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
