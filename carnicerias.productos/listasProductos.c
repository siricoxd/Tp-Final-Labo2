#include <stdio.h>
#include <stdlib.h>
#include "listasProductos.h"



#define ESC 27

#define ARCHIVO_CATALOGO "catalogo.bin"

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
int altaCatalogo(catalogo arreglo[],int validos,REGISTROA dato)//controla la carga de datos al arreglo de listas
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

productos pasarDeRegistroCatAPro(REGISTROA origen)
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
    REGISTROA aux;
    int i=0,validos=0;
    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(REGISTROA),1,archi)>0&& i<dim)
        {
            validos=altaCatalogo(arreglo,validos,aux);
        }
    }
    return validos;
}


//FUNCIONES DE MUESTRA

void mostrarUnProducto(productos dato)
{
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
        printf("\n|%d|", A.idCategoria);
        printf("\n%d",A.activoCat);
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







//Pasar DE DEPOSTIO A ARCHIVO CATALOGO


void depoditoAAcarnicria(char catalogo[],)

//MUESTRA DE ARCHIVO_CATALOGO

void muestraUnRegistro(REGISTROA dato)
{
    if(dato.activoCat==1)
    {
        printf("\nNOMBRE DE CATEGORIA: %s",dato.nombreDeCategoria);
        printf("\n|%d|",dato.idCategoria);
        printf("\nACTIVO: %d",dato.activoCat);
    }
    if(dato.activoPro==1)
    {

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




//funcion de desactivar
int buscaEnCatalogoPorId(catalogo arreglo[],int validos,int id)
{
    int flag=-1,i=0;

    while(i<validos && flag==-1)
    {
        if(arreglo[i].idCategoria==id)
        {
            flag=1;
        }
        i++;
    }
    muestraUnCatalogo(arreglo[i-1]);
    return flag;
}

void desactivarCatalogo(catalogo ar[], int id, int pos)
{
    FILE *buffer = fopen(ARCHIVO_CATALOGO, "r+b");

    if (buffer != NULL)
    {
        REGISTROA aux;
        int flag = 0;

        while (fread(&aux, sizeof(REGISTROA), 1, buffer) > 0 && flag == 0)
        {
            if (ar[pos].idCategoria == aux.idCategoria)
            {
                ar[pos].activoCat = 0;
                aux.activoCat = 0;

                long currentPos = ftell(buffer);
                fseek(buffer, currentPos - sizeof(REGISTROA), SEEK_SET);
                fwrite(&aux, sizeof(REGISTROA), 1, buffer);
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

void desactivarProducto(catalogo ar[], int id, int pos)
{
    FILE *buffer = fopen(ARCHIVO_CATALOGO, "r+b");

    if (buffer != NULL)
    {
        REGISTROA aux;
        nodoProductos *seg = ar[pos].lista;
        int flag = 0;

        while (fread(&aux, sizeof(REGISTROA), 1, buffer) && flag == 0)//abre
        {
            if (ar[pos].idCategoria == aux.idCategoria )
            {

                while (seg != NULL && flag==0)
                {
                    if(aux.id==seg->dato.id)
                    {
                        seg->dato.activoPro = 0;
                        aux.activoPro = 0;

                        fseek(buffer, (-1) * sizeof(REGISTROA), SEEK_CUR);
                        fwrite(&aux, sizeof(REGISTROA), 1, buffer);
                        flag = 1;
                        seg = seg->siguiente;
                    }
                }
            }
        }

        fclose(buffer);
    }
}


//FUNCIONE VENTAS EN EL DIA(pasar de arreglo de listas a un archivo de ventas)

void pasarDeArregloAArchivo(catalogo arreglo,int idDeProd,char archivo[])
{
    FILE *archi=fopen(archivo,"ab");
    //StRegistroventas ventas;


    if(archi!=NULL)
    {

        cargarArchivoVentas(arreglo.lista,archi,idDeProd);

        fclose(archi);
    }
}


void cargarArchivoVentas(nodoProductos *lista, FILE *archi,int idDeProd )
{
    nodoProductos *seg = lista;
    int flag=0;
    StRegistroventas aux;
    if(archi!=NULL)
    {
        while (seg != NULL && flag==0)
        {
            if(seg->dato.id==idDeProd)
            {
                aux = cambioDeEstrucCatalARegistro(seg->dato);
                fwrite(&aux, sizeof(StRegistroventas), 1, archi);
                flag=1;
            }
            seg = seg->siguiente;

        }
    }

}




StRegistroventas cambioDeEstrucCatalARegistro(productos dato)//transforma el tio de dato catlogo a uno de registroventa y cargo el la venta y el dia
{

    StRegistroventas  dest;

    strcpy(dest.nombreDeProductos,dato.nombreDeProductos);
    dest.id=dato.id;
    dest.precioPorKilo=dato.precioPorKilo;
    dest.stock=dato.stock;
    dest.activoPro=dato.activoPro;
    printf("\nINGRESE EL DIA DE LA VENTA: ");
    fflush(stdin);
    gets(dest.fechaVenta);
    dest.venta=cargaVenta(dest.stock);

    modificarSatock(dest.id,dest.venta);


    return dest;
}

int cargaVenta(int stock)
{
    int venta;
    printf("\ncargue la venta del producto: ");
    scanf("%d",&venta);
    while(venta>stock)
    {
        printf("\ncargue la venta del producto(que no supere el stock disponible): ");
        scanf("%d",&venta);
    }


    return venta;

}

void modificarSatock(int idDelRegistro,int venta)
{
    FILE *archivo;


    archivo = fopen(ARCHIVO_CATALOGO, "rb+");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");

    }

    REGISTROA registro;

    while (fread(&registro, sizeof(REGISTROA), 1, archivo) == 1)
    {
        if (registro.id == idDelRegistro)
        {

            printf("stock antes de la modificación: %d\n", registro.stock);
            registro.stock=(registro.stock-venta); // Modifica el valor según tus necesidades
            fseek(archivo, -sizeof(REGISTROA), SEEK_CUR); // Retrocede al inicio del registro
            fwrite(&registro, sizeof(REGISTROA), 1, archivo); // Escribe el registro modificado
            printf("stock después de la modificación: %d\n", registro.stock);
            break;
        }
    }

    // Cierra el archivo
    fclose(archivo);


}

void desactivarArchivoVentas (int id)
{
    FILE *buffer = fopen(ARCHIVO_VENTAS, "r+b");

    if (buffer != NULL)
    {
        StRegistroventas aux;

        int flag = 0;

        while (fread(&aux, sizeof(StRegistroventas), 1, buffer) && flag == 0)
        {



            if(aux.id==id)
            {
                aux.activoPro = 0;

                // Move the file position indicator to the beginning of the current record
                fseek(buffer, -sizeof(StRegistroventas), SEEK_CUR);

                // Write the modified record back to the file
                fwrite(&aux, sizeof(StRegistroventas), 1, buffer);

                printf("\nactivo: %d", aux.activoPro);
                flag = 1;

            }

        }
        fclose(buffer);
    }



}

// MUESTRS DE ARCHIVO DE VENTAS

void muestraUnRegistroVentas(StRegistroventas dato)
{
    if(dato.activoPro==1)
    {
        printf("\nNOMBRE DE PRODUCTO:  %s",dato.nombreDeProductos);
        printf("\nPRECIO POR KILO:%d ",dato.precioPorKilo);
        printf("\nACTIVO: %d",dato.activoPro);
        printf("\nid de productos |%d|",dato.id);
        printf("\nFECHA DE VENTA: %s",dato.fechaVenta);
        printf("\nVenta: %d",dato.venta);
        printf("\n-----------------------------------------------");
    }

}
void muestraArchivoVentas(char archivo[])
{
    FILE *archi=fopen(archivo,"rb");
    StRegistroventas dato;
    if(archi!=NULL)
    {
        while(fread(&dato,sizeof(StRegistroventas),1,archi)>0)
        {
            muestraUnRegistroVentas(dato);
        }
        fclose(archi);
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

int cantidadDeRegistros()
{
    int cantidad;
    FILE* buffer = fopen(ARCHIVO_CATALOGO,"rb");
    if(buffer)
    {
        fseek(buffer, 0, SEEK_END);
        cantidad =(int)ftell(buffer)/sizeof(ARCHIVO_CATALOGO);
        fclose(buffer);
    }
    return cantidad;
}

REGISTROA cargaRegistro()
{
    REGISTROA dato;


    printf("\nNOMBRE DE CATEGORIA: ");
    fflush(stdin);
    gets(dato.nombreDeCategoria);
    dato.idCategoria=generarIDUnico();


    dato.activoCat = 1;




    dato.id=generarIDUnico();
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

void cargaArchivo(char archivo[])
{
    REGISTROA aux;

    char opcion;

    FILE* buffer= fopen(archivo,"ab");
    if(buffer)
    {
        do
        {


            printf("\nCARGUE EL REGISTRRO\n");
            aux=cargaRegistro();
            fwrite(&aux,sizeof(REGISTROA),1,buffer);

            printf("\nPARA SALIR PRESIONE ESC\n");
            fflush(stdin);
            opcion=getch();
            system("pause");
            system("cls");

        }
        while(opcion!=ESC);

        fclose(buffer);
    }

}

