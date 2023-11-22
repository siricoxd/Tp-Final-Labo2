#include <stdio.h>
#include <stdlib.h>
#include "depositoSucursal.h"
#include <string.h>



//TDA de listas
nodoproductosSucursal * inicListaProducSucursal()
{
    return NULL;
}

nodoproductosSucursal *crearNuevonodoproductosSucursal(productosDepos dato )
{

    nodoproductosSucursal *aux=(nodoproductosSucursal*)malloc(sizeof(nodoproductosSucursal));//creo el puntero que apunta al espacio de memoria del nodoproductosSucursal

    aux->dato=dato;//igualo el nodoproductosSucursal que cree al dato que me pasaron

    aux->siguiente=NULL;//apunto el campo que contiene la siguiente dirrecion de memoria a null

    return aux;//retorno el la nuva direccion de memoria para que sea asignada a un puntero

}

nodoproductosSucursal* agregarNuevonodoproductosSucursalAlPLista(nodoproductosSucursal*lista,nodoproductosSucursal *nuevonodoproductosSucursal)
{
    if(lista==NULL)//verifico si la lista esta vacia
    {
        lista=nuevonodoproductosSucursal;//si lo esta mi nuevo nodoproductosSucursal sera el primero en la lista
    }
    else
    {
        nuevonodoproductosSucursal->siguiente=lista;//si ya hay uno copio su direccion de memoria en siguiente
        lista=nuevonodoproductosSucursal;//EN EL LUGAR QUE ESTaba la lista sera el lugar de mi nuevo nodd porque estoy agregando al principio
    }

    return lista;
}
//__________________________________________________________________________________________________________________________________________________________________________________________________________________

//manejo de arreglo de listas
int buscaEncatalogoSuc(catalogoSuc arreglo[],int validos,depositoSucursal dato)
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


int agregarALcatalogoSuc(catalogoSuc arreglo[],int validos,depositoSucursal dato)//agrega al cateorias al arreglo
{
    arreglo[validos].idDeSuc=dato.idDeSuc;
    strcpy(arreglo[validos].nombreDeCategoria,dato.nombreDeCategoria);
    arreglo[validos].idCategoria=dato.idCategoria;
    arreglo[validos].activoCat=dato.activoCat;

    arreglo[validos].lista=inicListaProducSucursal();
    validos++;
    return validos;
}

int altacatalogoSuc(catalogoSuc arreglo[],int validos,depositoSucursal dato)//controla la carga de datos al arreglo de listas
{
    int pos=buscaEncatalogoSuc(arreglo,validos,dato);
    nodoproductosSucursal *aux;
    productosDepos aux2P=pasarDeRegistroCatAProSucursal(dato);

    if(pos==-1)
    {
        validos=agregarALcatalogoSuc(arreglo,validos,dato);
        pos=validos-1;

    }


    aux=crearNuevonodoproductosSucursal(aux2P);

    arreglo[pos].lista=agregarNuevonodoproductosSucursalAlPLista(arreglo[pos].lista,aux);

    return validos;
}

productosDepos pasarDeRegistroCatAProSucursal(depositoSucursal origen)
{
    productosDepos dest;
    strcpy(dest.nombreDeproductosDepos, origen.nombreDeproductosDepos);
    dest.id = origen.id;
    dest.precioPorKilo = origen.precioPorKilo;
    dest.stock = origen.stock;
    dest.activoPro = origen.activoPro;

    return dest;

}
//__________________________________________________________________________________________________________________________________________________________________________________________________________________

// carga de arreglo de listas


int pasardeArchivoAArregloSucursal(char archivo[],catalogoSuc arreglo[],int dim,int idDeSucu)
{
    FILE *archi=fopen(archivo,"rb");
    depositoSucursal aux;
    int i=0,validos=0;
    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(depositoSucursal),1,archi)>0&& i<dim)
        {
            if(idDeSucu==aux.idDeSuc)
            {

                 validos=altacatalogoSuc(arreglo,validos,aux);
            }

        }
    }
    return validos;
}


//FUNCIONES DE MUESTRA

void mostrarUnProductoSucursal(productosDepos dato)
{
    printf("\nACTIVO PRODUCTO: %d",dato.activoPro);
    printf("\nNOMBRE DE PRODUCTO:  %s", dato.nombreDeproductosDepos);
    printf("\nPRECIO POR KILO: %d ",dato.precioPorKilo);
    printf("\nSTOCK: %d", dato.stock);
    printf("\nID: %d", dato.id);
    printf("\n");
}
void muestraLISTASucursal(nodoproductosSucursal *lista)
{
    while (lista != NULL)
    {
        if (lista->dato.activoPro == 1)
        {
            mostrarUnProductoSucursal(lista->dato);
        }
        lista = lista->siguiente;
    }

}
void muestraUncatalogoSucursal(catalogoSuc A)
{
    if (A.activoCat == 1)
    {
        printf("\nACTIVO CAT: %d",A.activoCat);
        printf("\nID DE SUCURSAL: %d",A.idDeSuc);
        printf("\nNOMBRE DE CATEGORIA: %s", A.nombreDeCategoria);
        printf("\nID DE CATEGORIA|%d|", A.idCategoria);
        printf("\n");
        muestraLISTASucursal(A.lista);
        printf("\n----------------------------------------------");
    }


}
void muestraDecatalogoSucursal(catalogoSuc A[],int validos)
{
    int i=0;

    while (i<validos)
    {
        muestraUncatalogoSucursal(A[i]);
        i++;
    }
}

void muestraDecatalogoSucursalTodos(catalogoSuc A[],int validos)
{
    int i=0;

    while (i<validos)
    {
        muestraUncatalogoSucursalTodos(A[i]);
        i++;
    }
}
void muestraUncatalogoSucursalTodos(catalogoSuc A)
{

        printf("\nACTIVO CAT: %d",A.activoCat);
        printf("\nID DE SUCURSAL: %d",A.idDeSuc);
        printf("\nNOMBRE DE CATEGORIA: %s", A.nombreDeCategoria);
        printf("\nID DE CATEGORIA|%d|", A.idCategoria);
        printf("\n");
        muestraLISTASucursalTodos(A.lista);
        printf("\n----------------------------------------------");



}

void muestraLISTASucursalTodos(nodoproductosSucursal *lista)
{
    while (lista != NULL)
    {

            mostrarUnProductoSucursal(lista->dato);

        lista = lista->siguiente;
    }

}








//carga De ARCHIVO DEPOSITOSUCURSAL

void cargaArchivoDepositoSucursal(char archivoDepoSuc[], deposito dato, int idDeSuc, int stock) {
    FILE *archi = fopen(archivoDepoSuc, "ab");
    depositoSucursal aux;
    if (archi != NULL) {
        aux = pasarDeDepositoASucursal(dato, idDeSuc, stock);
        fwrite(&aux, sizeof(depositoSucursal), 1, archi);
        fclose(archi);
    } else {
        perror("Error opening archivoDepoSuc");
    }
}
depositoSucursal pasarDeDepositoASucursal(deposito dato,int idDeSuc,int stock)
{
    depositoSucursal aux;

    aux.idDeSuc=idDeSuc;
    aux.activoCat=dato.activoCat;
    aux.idCategoria=dato.idCategoria;
    strcpy(aux.nombreDeCategoria,dato.nombreDeCategoria);

    aux.id=dato.id;
    aux.activoPro=dato.activoPro;
    strcpy(aux.nombreDeproductosDepos,dato.nombreDeProductos);
    aux.stock=stock;
    aux.precioPorKilo=dato.precioPorKilo;


    return aux;
}
void recorrerDeposito(char archivoDepos[], char archivoDepoSuc[], int idDeSuc, int idDato, int stock) {
    FILE *archi = fopen(archivoDepos, "rb");
    deposito aux;
    int flag = 0;

    if (archi != NULL) {
        while (fread(&aux, sizeof(deposito), 1, archi) > 0 && flag == 0) {
            if (aux.id == idDato) {
                cargaArchivoDepositoSucursal(archivoDepoSuc, aux, idDeSuc, stock);
                flag = 1;
            }
        }
        fclose(archi);
    } else {
        perror("Error opening archivoDepos");
    }
}

int cargarStockYmodificarlos(char archivo[], nodoProductos *produc) {
    FILE *buffer = fopen(archivo, "r+b");

    int stockAgregar = 0;

    if (buffer != NULL) {
        deposito aux;
        int flag = 0;

        while (fread(&aux, sizeof(deposito), 1, buffer) > 0 && flag == 0) {
            if (produc->dato.id == aux.id) {
                stockAgregar = cargarstock(aux.stock);
                printf("stock antes de la modificación: %d\n", aux.stock);
                aux.stock -= stockAgregar;
                fseek(buffer, -sizeof(deposito), SEEK_CUR);
                fwrite(&aux, sizeof(deposito), 1, buffer);
                printf("stock después de la modificación: %d\n", aux.stock);
                flag = 1;
            }
        }

        fclose(buffer);
    } else {
        perror("Error opening archivo");
    }

    return stockAgregar;
}

int cargarstock(int stock) {
    int pasaje;
    printf("\ncargue el stock del producto: ");
    scanf("%d", &pasaje);

    while (pasaje > stock) {
        printf("\ncargue el stock del producto (que no supere el stock disponible): ");
        scanf("%d", &pasaje);
    }

    return pasaje;
}

int modificarStockEnArchivoDepSuc(char archivo[], int idDePro,int idDeSuc, int stock) {
    FILE *archivoDepSuc = fopen(archivo, "rb+");

    if (archivoDepSuc == NULL) {
        perror("Error opening archivo");
        return 0;  // Return an appropriate value or error code
    }

    int flag = 0;
    depositoSucursal aux;

    while (fread(&aux, sizeof(depositoSucursal), 1, archivoDepSuc) == 1 && flag == 0) {
        if (aux.id == idDePro && aux.idDeSuc==idDeSuc) {
                printf("\nnmm");
            printf("stock antes de la modificación: %d\n", aux.stock);
            aux.stock = stock+aux.stock;

            fseek(archivoDepSuc, -sizeof(depositoSucursal), SEEK_CUR);
            fwrite(&aux, sizeof(depositoSucursal), 1, archivoDepSuc);

            printf("stock después de la modificación: %d\n", aux.stock);
            flag = 1;
            break;
        }
    }

    fclose(archivoDepSuc);
    return flag;
}


int buscaPosDelArchivo (char archivo[], int idDePro,int idDeSuc)
{
     FILE *archivoDepSuc = fopen(archivo, "rb");

    if (archivoDepSuc == NULL) {
        perror("Error opening archivo");
        return 0;  // Return an appropriate value or error code
    }

    int flag = -1;
    depositoSucursal aux;

    while (fread(&aux, sizeof(depositoSucursal), 1, archivoDepSuc) == 1 && flag == -1) {
        if (aux.id == idDePro && aux.idDeSuc==idDeSuc) {


             flag = ftell(archivoDepSuc) / sizeof(depositoSucursal);

        }
    }

    fclose(archivoDepSuc);

    return flag;
}

//MUESTRA DE ARCHIVO_depositoSucursal

void muestraUnRegistroSucursal(depositoSucursal dato)
{
    if(dato.activoCat==1)
    {
        printf("\nACTIVO CATALOGO: %d",dato.activoCat);
        printf("\nID DE SUcursal: %d",dato.idDeSuc);
        printf("\nNOMBRE DE CATEGORIA: %s",dato.nombreDeCategoria);
        printf("\n|%d|",dato.idCategoria);
        printf("\nACTIVO: %d",dato.activoCat);
    }
    if(dato.activoPro==1)
    {

        printf("\nACTIVO PRODUCTO: %d",dato.activoPro);
        printf("\nNOMBRE DE PRODUCTO:  %s",dato.nombreDeproductosDepos);
        printf("\nPRECIO POR KILO:%d ",dato.precioPorKilo);
        printf("\nSTOCK: %d",dato.stock);
        printf("\nid de productosDepos |%d|",dato.id);

        printf("\n----------------------------------------------");
    }



}





void muestraArchivoSucursal(char archivo[])
{

    FILE *archi=fopen(archivo,"rb");
    depositoSucursal aux;

    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(depositoSucursal),1,archi)>0)
        {
            muestraUnRegistroSucursal(aux);
        }
        fclose(archi);
    }

}

//ELIMINAR PRODUCTO EN DEPOSITO SUCURSAL

void desactivarProductoEnSucursal(char archivo[], catalogoSuc arreglo[], int pos, nodoproductosSucursal* id, int idDeSuc)
{
    FILE* buffer = fopen(archivo, "r+b");

    if (buffer != NULL)
    {
        depositoSucursal aux;

        int flag = 0;

        while (fread(&aux, sizeof(depositoSucursal), 1, buffer)>0&& flag == 0) // no necesitas la condición flag == 0 aquí
        {
            if (id->dato.id == aux.id && aux.idDeSuc == idDeSuc)
            {
                id->dato.activoPro = 0;
                aux.activoPro = 0;

                fseek(buffer, -sizeof(depositoSucursal), SEEK_CUR);
                fwrite(&aux, sizeof(depositoSucursal), 1, buffer);
                flag = 1;

            }
        }
        fclose(buffer);
    }
}

int buscaEnCatalogoPorIdSUCURSAL(catalogoSuc arreglo[], int validos, int id)
{
    for (int i = 0; i < validos; ++i)
    {
        if (arreglo[i].idCategoria == id)
        {
            return i; // encontramos la posición, no necesitamos seguir buscando
        }
    }
    return -1; // no se encontró el ID
}

nodoproductosSucursal* buscaEnListaIdSucursal(catalogoSuc arreglo[],int pos,int idDePro)
{
    int flag=0;
    nodoproductosSucursal *id=NULL,*seg;
    seg=arreglo[pos].lista;

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
void desactivarCatalogoSucursal(char archivo[],catalogoSuc ar[], int id, int pos,int idDeSuc)
{
    FILE *buffer = fopen(archivo, "r+b");

    if (buffer != NULL)
    {
        depositoSucursal aux;
        int flag = 0;

        while (fread(&aux, sizeof(depositoSucursal), 1, buffer) > 0 && flag == 0)
        {
            if (ar[pos].idCategoria == aux.idCategoria && aux.idDeSuc == idDeSuc  )
            {
                ar[pos].activoCat = 0;
                aux.activoCat = 0;

                fseek(buffer, (-1) * sizeof(depositoSucursal), SEEK_CUR);
                fwrite(&aux, sizeof(depositoSucursal), 1, buffer);
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


void activarCatalogoSucursal(char archivo[],catalogoSuc ar[], int id, int pos,int idDeSuc)
{
    FILE *buffer = fopen(archivo, "r+b");

    if (buffer != NULL)
    {
        depositoSucursal aux;
        int flag = 0;

        while (fread(&aux, sizeof(depositoSucursal), 1, buffer) > 0 && flag == 0)
        {
            if (ar[pos].idCategoria == aux.idCategoria && aux.idDeSuc == idDeSuc  )
            {
                ar[pos].activoCat = 1;
                aux.activoCat = 1;

                fseek(buffer, (-1) * sizeof(depositoSucursal), SEEK_CUR);
                fwrite(&aux, sizeof(depositoSucursal), 1, buffer);
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





void activarProductoEnSucursal(char archivo[], catalogoSuc arreglo[], int pos, nodoproductosSucursal* id, int idDeSuc)
{
    FILE* buffer = fopen(archivo, "r+b");

    if (buffer != NULL)
    {
        depositoSucursal aux;

        int flag = 0;

        while (fread(&aux, sizeof(depositoSucursal), 1, buffer)>0&& flag == 0) // no necesitas la condición flag == 0 aquí
        {
            if (id->dato.id == aux.id && aux.idDeSuc == idDeSuc)
            {
                id->dato.activoPro = 1;
                aux.activoPro = 1;

                fseek(buffer, -sizeof(depositoSucursal), SEEK_CUR);
                fwrite(&aux, sizeof(depositoSucursal), 1, buffer);
                flag = 1;

            }
        }
        fclose(buffer);
    }
}












