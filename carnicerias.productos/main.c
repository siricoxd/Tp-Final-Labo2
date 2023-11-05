#include <stdio.h>
#include <stdlib.h>
#include "listasProductos.h"
#define ARCHIVO_CATALOGO "catalogo.bin"


int eliminarCategoria(catalogo arreglo[],int validos,int dato);
nodoProductos *borrarNodo(int buscado,nodoProductos *lista);
void eliminarProducto(catalogo arreglo[],int validos,int idCat,int idPro);
int main()
{
   catalogo arreglo[40];
   int validos=0,eliminarCatalogo,eliminarPro;
   char rta;

    printf("\nARCHIVO:\n");
     muestraArchivo(ARCHIVO_CATALOGO);
    validos=bajarArchivo(ARCHIVO_CATALOGO,arreglo,40);

        printf("\ndesea cargar el arreglo: ");
        fflush(stdin);
        scanf("%c",&rta);
        if(rta=='s')
        {
            printf("\nARREGLO:\n");
             muestraDeCatalogo(arreglo,validos);

              validos=cargaCatalogo(arreglo,40,validos);
              muestraDeCatalogo(arreglo,validos);
              guardaEnArchivo(arreglo,validos,ARCHIVO_CATALOGO);
        }
//           printf("\ningrese el id que desea eliminar\n");
//        scanf("%d",&eliminarCatalogo);
//        system("pause");
//        system("cls");
//         printf("\nnuevo arreglo:\n");
//        validos=eliminarCategoria(arreglo,validos,eliminarCatalogo);
//        muestraDeCatalogo(arreglo,validos);
//         guardaEnArchivo(arreglo,validos,ARCHIVO_CATALOGO);
//            system("pause");
//        system("cls");
//           printf("\ningrese el id del catalogo\n");
//        scanf("%d",&eliminarCatalogo);
//
//        eliminarProducto(arreglo,validos,eliminarCatalogo,1);
//        muestraDeCatalogo(arreglo,validos);
//         guardaEnArchivo(arreglo,validos,ARCHIVO_CATALOGO);



    return 0;
}

int eliminarCategoria(catalogo arreglo[],int validos,int dato)//elimina un posicion del arreglo de categoria
{
    int i=validos-1,flag=0;

    while(i>=0&& flag==0)
    {
        if(arreglo[i].idCategoria==dato)
        {
            arreglo[i]=arreglo[i+1];
            validos--;
            flag=1;
        }
        i--;

    }
    return validos;
}


nodoProductos *borrarNodo(int buscado,nodoProductos *lista)// elimina un nodo  de la lista de productos
{
    if(lista!=NULL)
    {
        if( lista->dato.id==buscado)//primera condicion , el buscado es el 1
        {
        nodoProductos*aBorrar=lista;
        lista=lista->siguiente;
        free(aBorrar);
        }


    else{//si lo buescado no esta en el 1 nodo seg condicion

            nodoProductos*ante=lista;
    nodoProductos*seg=lista->siguiente;
    while((seg!=NULL)&&(seg->dato.id!=buscado))
    {
        ante=seg;
        seg=seg->siguiente;
    }
    if(seg!=NULL)
        {

            ante->siguiente=seg->siguiente;//elimino
            free(seg);

        }

    }
    }
return lista;
}


void eliminarProducto(catalogo arreglo[],int validos,int idCat,int idPro)//recorre el arreglo para buscar el catalogo que contiene el producto a eliminar
{
     int i=validos-1,flag=0;

    while(i>=0&& flag==0)
    {
        if(arreglo[i].idCategoria==idCat)
        {
           arreglo[i].lista= borrarNodo(idPro,arreglo[i].lista);
            flag=1;
        }
        i--;

    }

}
