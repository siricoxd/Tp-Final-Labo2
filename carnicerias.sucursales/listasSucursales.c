#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listasSucusrsales.h"




///listas
nodoLocales*crearNodoLocales(locales dato)
{
    nodoLocales* nuevo=(nodoLocales*)malloc(sizeof(nodoLocales));
    nuevo->dato=dato;
    nuevo->siguiente=NULL;
    return nuevo;
}
nodoLocales* inicLista(nodoLocales*lista)
{
    return NULL;
}
void mostrarNodo(nodoLocales*lista)
{
    mostrarLocal(lista->dato);
}
void mostrarLista(nodoLocales*lista)
{
    int i=1;
    if(lista==NULL)
    {
        printf("\tLa lista esta vacia.\n");
    }
    else
    {
        nodoLocales* seguidora=lista;
        while(seguidora!=NULL)
        {
            printf("\nNodo %d: ",i);
            mostrarNodo(seguidora);
            seguidora=seguidora->siguiente;
            i++;
        }
    }
}
nodoLocales*buscarUltimo(nodoLocales*lista)
{
    nodoLocales*seg=lista;
    if(seg != NULL)
    {
        while(seg->siguiente!=NULL)
        {
            seg=seg->siguiente;
        }
    }
    return seg;
}
nodoLocales*buscarNodo(nodoLocales*lista,int id)
{
    int flag=0;
    nodoLocales*seguidora=lista;
    if(seguidora==NULL)
    {
        printf("La lista esta vacia.\n");
    }
    else
    {
        while(seguidora!=NULL&&flag==0)
        {
            if(seguidora->dato.idDeLocal==id)
            {
                flag=1;
            }
            seguidora=seguidora->siguiente;
        }
    }

    return seguidora;
}
nodoLocales* agregarAlPpioLocales(nodoLocales*lista,nodoLocales*nuevo)
{
    if(lista==NULL) //si la lista esta vacia
    {
        lista=nuevo;
    }
    else// si la lista tiene algo
    {
        nuevo->siguiente=lista;
        lista=nuevo;
    }
    return lista;
}
nodoLocales*agregarAlFinalLocales(nodoLocales*lista,nodoLocales*nuevo)
{

    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nodoLocales*ultimo;
        ultimo=buscarUltimo(lista);
        ultimo->siguiente=nuevo;
    }
    return lista;
}
nodoLocales*agregarEnOrdenLocales(nodoLocales*lista,nodoLocales*nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        if(nuevoNodo->dato.idDeLocal<lista->dato.idDeLocal)
        {
            agregarAlPpioLocales(lista,nuevoNodo);
        }
        else
        {
            nodoLocales*ante=lista;
            nodoLocales*seg=lista->siguiente;
            while(seg!=NULL&&nuevoNodo->dato.idDeLocal>=seg->dato.idDeLocal)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            nuevoNodo->siguiente=seg;
            ante->siguiente=nuevoNodo;
        }
    }
    return lista;
}
nodoLocales*EliminarLocal(nodoLocales*lista,int objetivo)
{
    if(lista!=NULL)
    {
        if(objetivo==lista->dato.idDeLocal)
        {
            lista->dato.activo=0;
        }
        else
        {
            int flag=0;

            while(lista!=NULL&&flag==0)
            {
                if(lista->dato.idDeLocal==buscarNodo(lista,objetivo)->dato.idDeLocal)
                    lista->dato.activo=0;
            }
        }
    }
    return lista;
}
///mostrar y cargar
provincia cargarProvincia()
{
    provincia aux;
    printf("Ingrese la provincia: ");
    fflush(stdin);
    gets(aux.NombreProvincia);
    printf("Ingrese el id de la provincia: ");
    scanf("%d",&aux.idProvincia);
    aux.activo=1;


    return aux;
}
int cargarArreglosProvincia(provincia ar[],int dim,int validos)
{
    if(validos<dim)
    {
        ar[validos]=cargarProvincia();
        validos++;
    }
    return validos;
}

locales cargarLocales()
{
    locales aux;
    printf("Ingrese el nombre de la ciudad: ");
    fflush(stdin);
    gets(aux.localidad);
    printf("Ingrese la direccion del local: ");
    fflush(stdin);
    gets(aux.direccion);
    printf("Ingrese el id del local: ");
    scanf("%d",&aux.idDeLocal);
    aux.activo=1;

    return aux;
}
void mostrarProvincia(provincia aux)
{
    printf("Privincia: %s\n",aux.NombreProvincia);
    printf("Id provincia: %d\n",aux.idProvincia);
}
void mostrarLocal(locales aux)
{
    printf("Ciudad del local: %s\n",aux.localidad);
    printf("Direccion del local: %s\n",aux.direccion);
    printf("Id del local: %d\n",aux.idDeLocal);
}
void mostrarAr(provincia ar[],int validos)
{
    int i=0;
    printf("Provincias en las cuales tenemos una sucursal:\n");
    while(i<validos)
    {
        if(ar[i].activo==1)
        {
            mostrarProvincia(ar[i]);
        }
        i++;
    }
}
void desctivarProvincia(provincia ar[],int validos,int id)
{
    int i=0,flag=0;
    while(i<validos&&flag==0)
    {
        if(id==ar[i].idProvincia)
        {
            ar[i].activo=0;
            flag=1;
        }
        i++;
    }
}
int buscarPosProvincia(provincia ar[],int id,int validos)
{
    int rta=-1;
    int i=0;
    while((i<validos)&&(rta==-1))
    {
        if(id==ar[i].idProvincia)
        {
            rta=i;
        }
        i++;
    }
    return rta;
}
int alta(provincia ar[],registroArchivoLocales dato,int validos)
{
    nodoLocales* aux;
    locales auxlocal=pasarRegistrosToLocal(dato);
    aux=crearNodoLocales(auxlocal);

    int pos=buscarPosProvincia(ar,dato.idProvincia,validos);
    if (pos==-1)
    {
        validos=cargarArreglosProvincia(ar,30,validos);
        pos=validos-1;
    }
    ar[pos].listaDelocales=agregarAlPpioLocales(ar[pos].listaDelocales,aux);

    return validos;
}
locales pasarRegistrosToLocal(registroArchivoLocales dato)
{
    locales auxlocal;
    auxlocal.activo=dato.idLocal;
    strcpy(auxlocal.direccion,dato.direccion);
    strcpy(auxlocal.localidad,dato.localidad);
    auxlocal.idDeLocal=dato.idLocal;
    return auxlocal;

}
registroArchivoLocales cargarRegistroLocales()
{
    registroArchivoLocales aux;
    printf("Ingrese la provincia: ");
    fflush(stdin);
    gets(aux.provincia);
    printf("Ingrese el id de la provincia: ");
    scanf("%d",&aux.idProvincia);
    aux.activoProv=1;
    printf("Ingrese la ciudad: ");
    fflush(stdin);
    gets(aux.localidad);
    printf("Ingrese la direccion del local: ");
    fflush(stdin);
    gets(aux.direccion);
    printf("Ingrese el id de la empresa: ");
    scanf("%d",&aux.idLocal);
    aux.activoLocal=1;
    return aux;
}
