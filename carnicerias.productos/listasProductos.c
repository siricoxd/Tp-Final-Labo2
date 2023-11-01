#include <stdio.h>
#include <stdlib.h>
#include "listasProductos.h"
#include <string.h>
#define ARCHIVO_CATALOGO "catalogo.bin"
#define ARCHIVO_PRODUCTOS "productos.bin"
#define ESC 27
#include <conio.h>

//manejo de listas
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
int buscaEnCatalogo(catalogo arreglo[],int validos,catalogo dato1)
{
    int i=validos-1,flag=-1;
    while(i>=0 && flag==-1)
    {
        if(arreglo[i].idProductos==dato1.idProductos)
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


 int agregarALCatalogo(catalogo arreglo[],int validos,catalogo dato)//agrega al cateorias al arreglo
 {
     strcpy(arreglo[validos].nombreDeCategoria,dato.nombreDeCategoria);
     arreglo[validos].idProductos=dato.idProductos;
     validos++;
     return validos;
 }

int altaCatalogo(catalogo arreglo[],int validos,catalogo dato1,productos dato2)//controla la carga de datos al arreglo de listas
{
    int pos=buscaEnCatalogo(arreglo,validos,dato1);
    nodoProductos *aux;

    if(pos==-1)
    {
        validos=agregarALCatalogo(arreglo,validos,dato1);
        pos=validos-1;
    }
    aux=crearNuevonodoProductos(dato2);
    arreglo[pos].lista=agregarNuevonodoProductosAlPLista(arreglo[pos].lista,aux);

return validos;
}
//__________________________________________________________________________________________________________________________________________________________________________________________________________________
// carga de arreglo de listas
int leerUltimoId(char archivo[])// POSICIONAMOS EN EL ULTIMO ID de cada estruc
{
    FILE* archi = fopen(archivo, "rb");
    int ultimoId = 0;

    if (archi != NULL)
    {
        fscanf(archi, "%d", &ultimoId);
        fclose(archi);
    }

    return ultimoId;
}





void guardarUltimoId(char archivo[],int ultimoId)//GUARDAMOS POS DEL ULTIMO ID de cada estr
{
    FILE* archi = fopen(archivo, "wb");

    if (archivo != NULL)
    {
        fprintf(archi, "%d", ultimoId);//copia el ultimo id en el archivo
        fclose(archi);
    }
}


catalogo cargaDeUnaCateogoria()//funcion de carga para el catalogo
{
    //carga el ultimo id +1
    printf("\nARREGLO:\n");
    catalogo A;
    printf("\nNOMBRE DE CATEGORIA: ");
    fflush(stdin);
    gets(A.nombreDeCategoria);
    int ultimoId=leerUltimoId(ARCHIVO_CATALOGO);//cargo el archivo de catalo
    A.idProductos=ultimoId+1;
    guardarUltimoId(ARCHIVO_CATALOGO,A.idProductos);


    return A;
}

productos cargaDeProductos()//funcion de carga para productos
{
    productos dato;

      printf("\nLISTA: \n");
    printf("\nNOMBRE DE PRODUCTO:  ");
    fflush(stdin);
    gets(dato.nombreDeProductos);

    printf("\nPRECIO POR KILO: ");
    scanf("%d",&dato.precioPorKilo);

    int ultimosId=leerUltimoId(ARCHIVO_PRODUCTOS);
    dato.id=ultimosId;
    guardarUltimoId(ARCHIVO_PRODUCTOS,ultimosId);

    return dato;
}

int  cargaCatalogo(catalogo arreglo[],int dim)
{
    productos auxProd;
    catalogo auxCata;
    int validos=0;
    char opcion;
    do
    {
        auxCata=cargaDeUnaCateogoria();
       // system("pause");
        system("cls");
        auxProd=cargaDeProductos();
        //system("pause");
        system("cls");
       validos= altaCatalogo(arreglo,0,auxCata,auxProd);
       printf("\nPRESIONE ESC PARA SALIR");
       fflush(stdin);
       opcion=getch();
       system("pause");
        system("cls");

    }while(opcion!=ESC);

return validos;
}


 //FUNCIONES DE MUESTRA
//hay que revisar la funcion de alta porque esta pisando los datos en alguna parte
 void muestraLISTA(nodoProductos *lista)
 {
     while(lista!=NULL)
     {
        printf("\nNOMBRE DE PRODUCTO:  %s",lista->dato.nombreDeProductos);
         printf("\nPRECIO POR KILO:%d ",lista->dato.precioPorKilo);
         printf("\n");
         lista=lista->siguiente;

     }
 }
void muestraUnCatalogo(catalogo A)
{
     printf("\nNOMBRE DE CATEGORIA: %s",A.nombreDeCategoria);
     printf("\n|%d|",A.idProductos);
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
