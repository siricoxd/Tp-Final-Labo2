#include <stdio.h>
#include <stdlib.h>
#include "listasProductos.h"



#define ESC 27



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
int buscaEnCatalogo(catalogo arreglo[],int validos,deposito dato)
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


int agregarALCatalogo(catalogo arreglo[],int validos,deposito dato)//agrega al cateorias al arreglo
{
    strcpy(arreglo[validos].nombreDeCategoria,dato.nombreDeCategoria);
    arreglo[validos].idCategoria=dato.idCategoria;
    arreglo[validos].activoCat=dato.activoCat;

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
int altaCatalogo(catalogo arreglo[],int validos,deposito dato)//controla la carga de datos al arreglo de listas
{
    int pos=buscaEnCatalogo(arreglo,validos,dato);
    nodoProductos *aux;
    productos aux2P=pasarDeRegistroCatAPro(dato);

    if(pos==-1)
    {
        validos=agregarALCatalogo(arreglo,validos,dato);
        pos=validos-1;

    }


    aux=crearNuevonodoProductos(aux2P);

    arreglo[pos].lista=agregarNuevonodoProductosAlPLista(arreglo[pos].lista,aux);

    return validos;
}

productos pasarDeRegistroCatAPro(deposito origen)
{
    productos dest;
    strcpy(dest.nombreDeProductos,origen.nombreDeProductos);
    dest.id=origen.id;
    dest.precioPorKilo=origen.precioPorKilo;
    dest.stock=origen.stock;
    dest.activoPro=origen.activoPro;

    return dest;
}
//__________________________________________________________________________________________________________________________________________________________________________________________________________________

// carga de arreglo de listas


int pasardeArchivoAArreglo(char archivo[],catalogo arreglo[],int dim)
{
    FILE *archi=fopen(archivo,"rb");
    deposito aux;
    int i=0,validos=0;
    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(deposito),1,archi)>0&& i<dim)
        {
            validos=altaCatalogo(arreglo,validos,aux);
        }
    }
    return validos;
}


//FUNCIONES DE MUESTRA

void mostrarUnProducto(productos dato)
{
    printf("\nACTIVO: %d",dato.activoPro);
    printf("\nNOMBRE DE PRODUCTO:  %s", dato.nombreDeProductos);
    printf("\nPRECIO POR KILO: %d ",dato.precioPorKilo);
    printf("\nSTOCK: %d", dato.stock);
    printf("\nID: %d", dato.id);
    printf("\n");
}
void muestraLISTA(nodoProductos *lista)
{
    while (lista != NULL)
    {
        if (lista->dato.activoPro == 1)
        {
            mostrarUnProducto(lista->dato);
        }
        lista = lista->siguiente;
    }

}
void muestraUnCatalogo(catalogo A)
{
    if (A.activoCat == 1)
    {
        printf("\nNOMBRE DE CATEGORIA: %s", A.nombreDeCategoria);
        printf("\nID DE CATEGORIA: |%d|", A.idCategoria);
        printf("\nACTIVOcatalog: %d",A.activoCat);
        muestraLISTA(A.lista);
        printf("\n----------------------------------------------");
    }


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

//MUESTRA ACTIVO Y NO ACTIVOS


void muestraLISTATODOs(nodoProductos *lista)
{
    while (lista != NULL)
    {

            mostrarUnProducto(lista->dato);

        lista = lista->siguiente;
    }

}
void muestraUnCatalogoTodos(catalogo A)
{
      printf("\nNOMBRE DE CATEGORIA: %s", A.nombreDeCategoria);
        printf("\nID DE CATEGORIA|%d|", A.idCategoria);
        printf("\nACTIVO(catalogo):%d",A.activoCat);
        muestraLISTATODOs(A.lista);
        printf("\n----------------------------------------------");



}


void muestraDeCatalogoTodos(catalogo A[],int validos)
{
    int i=0;

    while (i<validos)
    {
        muestraUnCatalogoTodos(A[i]);
        i++;
    }
}





//MUESTRA DE ARCHIVO_deposito

void muestraUnRegistro(deposito dato)
{
    printf("nn");
    if(dato.activoCat==1)
    {
        printf("\nNOMBRE DE CATEGORIA: %s",dato.nombreDeCategoria);
        printf("\nid DE CATEGORIA|%d|",dato.idCategoria);
        printf("\nACTIVO: %d",dato.activoCat);
    }
    if(dato.activoPro==1)
    {
         printf("\nACTIVO: %d",dato.activoPro);
        printf("\nNOMBRE DE PRODUCTO:  %s",dato.nombreDeProductos);
        printf("\nPRECIO POR KILO:%d ",dato.precioPorKilo);
        printf("\nSTOCK: %d",dato.stock);
        printf("\nid de productos |%d|",dato.id);

        printf("\n----------------------------------------------");
    }



}
void muestraArchivo(char archivo[])
{
    FILE *archi=fopen(archivo,"rb");
    deposito aux;
    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(deposito),1,archi)>0)
        {

            muestraUnRegistro(aux);
        }
        fclose(archi);
    }

}




//funcion de desactivar
int buscaEnCatalogoPorId(catalogo arreglo[],int validos,int id)
{
    int flag=-1,i=0;

    while(i<validos && flag==-1)
    {
        if(arreglo[i].idCategoria==id)
        {
            flag=i;

        }
        i++;
    }
    //muestraUnCatalogo(arreglo[i-1]);
    return flag;
}

void desactivarCatalogo(char archivo[],catalogo ar[], int id, int pos)
{
    FILE *buffer = fopen(archivo, "r+b");

    if (buffer != NULL)
    {
        deposito aux;
        int flag = 0;

        while (fread(&aux, sizeof(deposito), 1, buffer) > 0 && flag == 0)
        {
            if (ar[pos].idCategoria == aux.idCategoria )
            {
                ar[pos].activoCat = 0;
                aux.activoCat = 0;

                fseek(buffer, (-1) * sizeof(deposito), SEEK_CUR);
                fwrite(&aux, sizeof(deposito), 1, buffer);
                fflush(buffer);
                flag = 1;
            }
        }

        fclose(buffer);
    }
    else
    {
        printf("\nnnn");
    }
}


nodoProductos* buscaEnListaId(catalogo arreglo[],int pos,int idDePro)
{
    int flag=0;
    nodoProductos *id=NULL,*seg;
    seg=arreglo[pos].lista;

    muestraUnCatalogo(arreglo[pos]);
    mostrarUnProducto(seg->dato);
    while(seg!=NULL&& flag==0)
    {
        if(seg->dato.id==idDePro)
        {

            flag=1;
            id=seg;
        }

        seg= seg->siguiente;
    }
    return id;

}

void desactivarProducto(char archivo[], catalogo arreglo[],int pos,nodoProductos* id)
{
    FILE *buffer = fopen(archivo, "r+b");

    if (buffer != NULL)
    {

        deposito aux;

        int flag = 0;

        while (fread(&aux, sizeof(deposito), 1, buffer)>0 && flag == 0)//abre
        {

            if (id->dato.id == aux.id )
            {
                id->dato.activoPro = 0;
                aux.activoPro = 0;

                fseek(buffer, (-1) * sizeof(deposito), SEEK_CUR);
                fwrite(&aux, sizeof(deposito), 1, buffer);
                flag = 1;

            }
        }
        fclose(buffer);
    }


}

void activarProducto(char archivo[], catalogo arreglo[],int pos,nodoProductos* id)
{
    FILE *buffer = fopen(archivo, "r+b");

    if (buffer != NULL)
    {

        deposito aux;

        int flag = 0;

        while (fread(&aux, sizeof(deposito), 1, buffer) && flag == 0)//abre
        {

            if (id->dato.id == aux.id )
            {
                id->dato.activoPro = 1;
                aux.activoPro = 1;

                fseek(buffer, (-1) * sizeof(deposito), SEEK_CUR);
                fwrite(&aux, sizeof(deposito), 1, buffer);
                flag = 1;

            }
        }
        fclose(buffer);
    }


}

void activarCatalogo(char archivo[],catalogo ar[], int id, int pos)
{
    FILE *buffer = fopen(archivo, "r+b");

    if (buffer != NULL)
    {
        deposito aux;
        int flag = 0;

        while (fread(&aux, sizeof(deposito), 1, buffer) > 0 && flag == 0)
        {
            if (ar[pos].idCategoria == aux.idCategoria )
            {
                ar[pos].activoCat = 1;
                aux.activoCat = 1;

                fseek(buffer, (-1) * sizeof(deposito), SEEK_CUR);
                fwrite(&aux, sizeof(deposito), 1, buffer);
                fflush(buffer);
                flag = 1;
            }
        }

        fclose(buffer);
    }
    else
    {
        printf("\nnnn");
    }
}




// Función para generar un ID único
int generarIDUnico()
{
    // Inicializar la semilla del generador de números aleatorios con el tiempo actual
    srand((unsigned int)time(NULL));

    // Generar un número aleatorio y devolverlo como el ID único
    return rand();
}


deposito cargaRegistro()
{



    deposito dato;


    printf("\nNOMBRE DE CATEGORIA: ");
    fflush(stdin);
    gets(dato.nombreDeCategoria);
    //dato.idCategoria=generarIDUnico();
    FILE* buffer1 = fopen(ARCHIVO_DEPOSITO,"rb");
    if(buffer1)
    {
        dato.idCategoria=cantidadDeRegistros()*1;

        fclose(buffer1);
    }

    dato.activoCat = 1;




    FILE* buffer2 = fopen(ARCHIVO_DEPOSITO,"rb");
    if(buffer2)
    {
        dato.id=cantidadDeRegistros()+1;

        fclose(buffer2);
    }
   // dato.id=generarIDUnico();
    printf("\nNOMBRE DE PRODUCTO:  ");
    fflush(stdin);
    gets(dato.nombreDeProductos);
    printf("\nSTOCK: ");
    scanf("%d",&dato.stock);
    printf("\nPRECIO POR KILO: ");
    scanf("%d",&dato.precioPorKilo);
    dato.activoPro=1;




    return dato;
}




int cantidadDeRegistros()
{
    int cantidad;
    FILE* buffer = fopen(ARCHIVO_DEPOSITO,"rb");
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cantidad =(int)ftell(buffer)/sizeof(deposito);
        fclose(buffer);
    }
    return cantidad;
}
void cargaArchivo(char archivo[])
{
    deposito aux;

    char opcion;


     do
        {
        FILE* buffer= fopen(archivo,"ab");
         if(buffer)
            {

            printf("\nCARGUE EL REGISTRRO\n");
            aux=cargaRegistro();
            fwrite(&aux,sizeof(deposito),1,buffer);

            printf("\nPARA SALIR PRESIONE ESC\n");
            fflush(stdin);
            opcion=getch();
            system("pause");
            system("cls");

          }
           fclose(buffer);

        }while(opcion!=ESC);




}

