#include <stdio.h>
#include <stdlib.h>
#include "listasProductos.h"
#include <string.h>


#define ESC 27
#include <conio.h>

//TDA de listas
nodoProductos * inicListaProduc()
{
    return NULL;
}

nodoProductos *crearNuevonodoProductos(productos dato )
{

    nodoProductos *aux=(nodoProductos*)malloc(sizeof(nodoProductos));//creo el puntero que apunta al espacio de memoria del nodoProductos

    aux->dato=dato;//igualo el nodoProductos que cree al dato que me pasaron

    aux->siguiente=NULL;//apunto el campo que contiene la siguiente dirrecion de memoria a null

    return aux;//retorno el la nuva direccion de memoria para que sea asignada a un puntero

}

nodoProductos* agregarNuevonodoProductosAlPLista(nodoProductos*lista,nodoProductos *nuevonodoProductos)
{
    if(lista==NULL)//verifico si la lista esta vacia
    {
        lista=nuevonodoProductos;//si lo esta mi nuevo nodoProductos sera el primero en la lista
    }
    else
    {
        nuevonodoProductos->siguiente=lista;//si ya hay uno copio su direccion de memoria en siguiente
        lista=nuevonodoProductos;//EN EL LUGAR QUE ESTaba la lista sera el lugar de mi nuevo nodd porque estoy agregando al principio
    }

    return lista;
}
//__________________________________________________________________________________________________________________________________________________________________________________________________________________

//manejo de arreglo de listas
int buscaEnCatalogo(catalogo arreglo[],int validos,REGISTROA dato)
{
    int i=validos-1,flag=-1;
    while(i>=0 && flag==-1)
    {
        if(strcasecmp(arreglo[i].nombreDeCategoria,dato.nombreDeCategoria)==0)
        {
            flag=i;
        }
        else
        {
            i--;
        }

    }
    return flag;
}


int agregarALCatalogo(catalogo arreglo[],int validos,REGISTROA dato)//agrega al cateorias al arreglo
{
    strcpy(arreglo[validos].nombreDeCategoria,dato.nombreDeCategoria);
    arreglo[validos].idCategoria=validos*100;
    arreglo[validos].lista=inicListaProduc();
    validos++;
    return validos;
}
int buscarUltimoIdDelista(nodoProductos *lista)
{
    nodoProductos *seg=lista;
    while(seg->siguiente!=NULL)
    {
        seg=seg->siguiente;
    }
    return seg->dato.id;
}
int altaCatalogo(catalogo arreglo[],int validos,REGISTROA dato)//controla la carga de datos al arreglo de listas
{
    int pos=buscaEnCatalogo(arreglo,validos,dato);
    nodoProductos *aux;
   productos aux2P=pasarDeRegistroCatAPro(dato);
   int id;
    if(pos==-1)
    {
        validos=agregarALCatalogo(arreglo,validos,dato);
        pos=validos-1;
        aux2P.id=arreglo[pos].idCategoria;
    }
    else
    {
          id=buscarUltimoIdDelista(arreglo[pos].lista);// aca va la funcion de buscar ultimo id
    }

    aux2P.id=id+1;
    aux=crearNuevonodoProductos(aux2P);

    arreglo[pos].lista=agregarNuevonodoProductosAlPLista(arreglo[pos].lista,aux);

    return validos;
}

productos pasarDeRegistroCatAPro(REGISTROA origen)
{
    productos dest;
      strcpy(dest.nombreDeProductos,origen.nombreDeProductos);
    dest.id=origen.id;
    dest.precioPorKilo=origen.precioPorKilo;
    dest.stock=origen.stock;

    return dest;
}
//__________________________________________________________________________________________________________________________________________________________________________________________________________________

// carga de arreglo de listas









REGISTROA cargaRegistro()
{
    REGISTROA dato;

    printf("\nNOMBRE DE CATEGORIA: ");
    fflush(stdin);
    gets(dato.nombreDeCategoria);


     printf("\nNOMBRE DE PRODUCTO:  ");
    fflush(stdin);
    gets(dato.nombreDeProductos);
    printf("\nSTOCK: ");
    scanf("%d",&dato.stock);
    printf("\nPRECIO POR KILO: ");
    scanf("%d",&dato.precioPorKilo);
    dato.activoCat=1;
    dato.activoProd=1;



    return dato;
}

int  cargaCatalogo(catalogo arreglo[],int dim,int validos)//tengo que mpdificar para que tome los validos asi si el arreglo ya tiene empieza de ahi
{
    REGISTROA aux;
    char opcion;

    do
    {
        aux=cargaRegistro();
        validos= altaCatalogo(arreglo,validos,aux);
        printf("\nPRESIONE ESC PARA SALIR");
        fflush(stdin);
        opcion=getch();
        system("pause");
        system("cls");

    }
    while(opcion!=ESC);

    return validos;
}


//FUNCIONES DE MUESTRA

void muestraLISTA(nodoProductos *lista)
{
    while(lista!=NULL)
    {
        printf("\nNOMBRE DE PRODUCTO:  %s",lista->dato.nombreDeProductos);
        printf("\nPRECIO POR KILO:%d ",lista->dato.precioPorKilo);
        printf("\nSTOCK: %d",lista->dato.stock);
        printf("\nACTIVO: %d",lista->dato.activoProd);
        printf("\n");
        lista=lista->siguiente;

    }
}
void muestraUnCatalogo(catalogo A)
{
    printf("\nNOMBRE DE CATEGORIA: %s",A.nombreDeCategoria);
    printf("\n|%d|",A.idCategoria);
    printf("\nACTIVO; %d",A.activoCata);
    muestraLISTA(A.lista);
    printf("\n----------------------------------------------");


}
void muestraDeCatalogo(catalogo A[],int validos)
{
    int i=0;
    while (i<validos)
    {
        muestraUnCatalogo(A[i]);
        i++;
    }
}


//GUARDAR EN EL ARCHIVO
void guardaEnArchivo(catalogo arreglo[],int validos,char archivoCata[])//ESTA FUNCION RECORRE EL ARREGLO
{
    FILE *archiC=fopen(archivoCata,"wb");

    for(int i=0; i<validos; i++)
    {
        pasarDeArregloDeLisAArchivo(arreglo[i],archiC);

    }
}

void pasarDeArregloDeLisAArchivo(catalogo arreglo,FILE* archiC)//pasa los datos de una posicion del arreglo y la lista entera al arreglo
{
    nodoProductos* seg=arreglo.lista;

    while(seg!=NULL)
    {
        if(archiC!=NULL)
        {
            REGISTROA aux=cambioDeEstrucCatalARegistro(arreglo);
            fwrite(&aux,sizeof(REGISTROA),1,archiC);

        }
        seg=seg->siguiente;
    }
    fclose(archiC);
}

REGISTROA cambioDeEstrucCatalARegistro(catalogo origen)//transforma el tio de dato catlogo a uno de REGISTROA
{
    REGISTROA dest;
    strcpy(dest.nombreDeCategoria,origen.nombreDeCategoria);
    dest.idCategoria= origen.idCategoria;

    strcpy(dest.nombreDeProductos,origen.lista->dato.nombreDeProductos);
    dest.id=origen.lista->dato.id;
    dest.precioPorKilo=origen.lista->dato.precioPorKilo;
    dest.stock=origen.lista->dato.stock;
    dest.activoCat=origen.activoCata;
    dest.activoProd=origen.lista->dato.activoProd;

    return dest;
}

int  bajarArchivo(char archivo[],catalogo arreglo[],int dim)
{
    FILE *archi=fopen(archivo,"rb");
    int i=0;

    REGISTROA aux;
    int validos=0;
    if(archi!=NULL)
    {
        while(i<dim && fread(&aux,sizeof(REGISTROA),1,archi)>0)
        {
            validos=altaCatalogo(arreglo,validos,aux);
            printf("n");

        }
        fclose(archi);
    }
    return validos;

}





//MUESTRA DE ARCHIVO_CATALOGO

void muestraUnRegistro(REGISTROA dato)
{
    printf("\nNOMBRE DE CATEGORIA: %s",dato.nombreDeCategoria);
    printf("\n|%d|",dato.idCategoria);

    printf("\nNOMBRE DE PRODUCTO:  %s",dato.nombreDeProductos);
    printf("\nPRECIO POR KILO:%d ",dato.precioPorKilo);
    printf("\nSTOCK: %d",dato.stock);
    printf("\n----------------------------------------------");


}
void muestraArchivo(char archivo[])
{
    FILE *archi=fopen(archivo,"rb");
    REGISTROA aux;
    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(REGISTROA),1,archi)>0)
        {

            muestraUnRegistro(aux);
        }
        fclose(archi);
    }

}





