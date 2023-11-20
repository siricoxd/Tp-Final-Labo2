#include <stdio.h>
#include <stdlib.h>
#include "depositoSucursal.h"
#include <string.h>



//TDA de listas
nodoproductosDepos * inicListaProducSucursal()
{
    return NULL;
}

nodoproductosDepos *crearNuevonodoproductosDepos(productosDepos dato )
{

    nodoproductosDepos *aux=(nodoproductosDepos*)malloc(sizeof(nodoproductosDepos));//creo el puntero que apunta al espacio de memoria del nodoproductosDepos

    aux->dato=dato;//igualo el nodoproductosDepos que cree al dato que me pasaron

    aux->siguiente=NULL;//apunto el campo que contiene la siguiente dirrecion de memoria a null

    return aux;//retorno el la nuva direccion de memoria para que sea asignada a un puntero

}

nodoproductosDepos* agregarNuevonodoproductosDeposAlPLista(nodoproductosDepos*lista,nodoproductosDepos *nuevonodoproductosDepos)
{
    if(lista==NULL)//verifico si la lista esta vacia
    {
        lista=nuevonodoproductosDepos;//si lo esta mi nuevo nodoproductosDepos sera el primero en la lista
    }
    else
    {
        nuevonodoproductosDepos->siguiente=lista;//si ya hay uno copio su direccion de memoria en siguiente
        lista=nuevonodoproductosDepos;//EN EL LUGAR QUE ESTaba la lista sera el lugar de mi nuevo nodd porque estoy agregando al principio
    }

    return lista;
}
//__________________________________________________________________________________________________________________________________________________________________________________________________________________

//manejo de arreglo de listas
int buscaEncatalogoDepos(catalogoDepos arreglo[],int validos,depositoSucursal dato)
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


int agregarALcatalogoDepos(catalogoDepos arreglo[],int validos,depositoSucursal dato)//agrega al cateorias al arreglo
{
    arreglo[validos].idDeSuc=dato.idDeSuc;
    strcpy(arreglo[validos].nombreDeCategoria,dato.nombreDeCategoria);
    arreglo[validos].idCategoria=dato.idCategoria;
    arreglo[validos].activoCat=dato.activoCat;

    arreglo[validos].lista=inicListaProducSucursal();
    validos++;
    return validos;
}

int altacatalogoDepos(catalogoDepos arreglo[],int validos,depositoSucursal dato)//controla la carga de datos al arreglo de listas
{
    int pos=buscaEncatalogoDepos(arreglo,validos,dato);
    nodoproductosDepos *aux;
    productosDepos aux2P=pasarDeRegistroCatAProSucursal(dato);

    if(pos==-1)
    {
        validos=agregarALcatalogoDepos(arreglo,validos,dato);
        pos=validos-1;

    }


    aux=crearNuevonodoproductosDepos(aux2P);

    arreglo[pos].lista=agregarNuevonodoproductosDeposAlPLista(arreglo[pos].lista,aux);

    return validos;
}

productosDepos pasarDeRegistroCatAProSucursal(depositoSucursal origen)
{
    productosDepos dest;
    strcpy(dest.nombreDeproductosDepos,origen.nombreDeproductosDepos);
    dest.id=origen.id;
    dest.precioPorKilo=origen.precioPorKilo;
    dest.stock=origen.stock;
    dest.activoPro=origen.activoPro;

    return dest;
}
//__________________________________________________________________________________________________________________________________________________________________________________________________________________

// carga de arreglo de listas


int pasardeArchivoAArregloSucursal(char archivo[],catalogoDepos arreglo[],int dim,int idDeSucu)
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
                printf("\nentro");
                 validos=altacatalogoDepos(arreglo,validos,aux);
            }

        }
    }
    return validos;
}


//FUNCIONES DE MUESTRA

void mostrarUnProductoSucursal(productosDepos dato)
{
    printf("\nNOMBRE DE PRODUCTO:  %s", dato.nombreDeproductosDepos);
    printf("\nPRECIO POR KILO: %d ",dato.precioPorKilo);
    printf("\nSTOCK: %d", dato.stock);
    printf("\nID: %d", dato.id);
    printf("\n");
}
void muestraLISTASucursal(nodoproductosDepos *lista)
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
void muestraUncatalogoSucursal(catalogoDepos A)
{
    if (A.activoCat == 1)
    {
        printf("\nID DE SUCURSAL: %d",A.idDeSuc);
        printf("\nNOMBRE DE CATEGORIA: %s", A.nombreDeCategoria);
        printf("\n|%d|", A.idCategoria);
        printf("\n%d",A.activoCat);
        muestraLISTASucursal(A.lista);
        printf("\n----------------------------------------------");
    }


}
void muestraDecatalogoSucursal(catalogoDepos A[],int validos)
{
    int i=0;

    while (i<validos)
    {
        muestraUncatalogoSucursal(A[i]);
        i++;
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
        printf("\nID DE SUcursal: %d",dato.idDeSuc);
        printf("\nNOMBRE DE CATEGORIA: %s",dato.nombreDeCategoria);
        printf("\n|%d|",dato.idCategoria);
        printf("\nACTIVO: %d",dato.activoCat);
    }
    if(dato.activoPro==1)
    {

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

void desactivarProductoEnSucursal(char archivo[], catalogoDepos arreglo[],int pos,nodoProductos* id,int idDeSuc)
{
    FILE *buffer = fopen(archivo, "r+b");

    if (buffer != NULL)
    {

        depositoSucursal aux;

        int flag = 0;

        while (fread(&aux, sizeof(depositoSucursal), 1, buffer) && flag == 0)//abre
        {

            if (id->dato.id == aux.id && aux.idDeSuc==idDeSuc)
            {
                id->dato.activoPro = 0;
                aux.activoPro = 0;

                fseek(buffer, (-1) * sizeof(depositoSucursal), SEEK_CUR);
                fwrite(&aux, sizeof(depositoSucursal), 1, buffer);
                flag = 1;

            }
        }
        fclose(buffer);
    }


}


//FUNCIONE VENTAS EN EL DIA(pasar de arreglo de listas a un archivo de ventas),cambiar el tipo de estructuras y veificar de que suc es el catalogo cuando cargamos el archivo de ventas,, lo podemos hacer wb el archivo asi es venta por dia y guardamos la info en ganancias

//void pasarDeArregloAArchivo(catalogoDepos arreglo,int idDeProd,char archivo[])
//{
//    FILE *archi=fopen(archivo,"ab");
//    //StRegistroventas ventas;
//if(arreglo.i)
//
//    if(archi!=NULL)
//    {
//
//        cargarArchivoVentas(arreglo.lista,archi,idDeProd,archivo);
//
//        fclose(archi);
//    }
//}
//
//
//void cargarArchivoVentas(nodoProductos *lista, FILE *archi,int idDeProd,char arhcivo[] )
//{
//    nodoProductos *seg = lista;
//    int flag=0;
//    StRegistroventas aux;
//    if(archi!=NULL)
//    {
//        while (seg != NULL && flag==0)
//        {
//            if(seg->dato.id==idDeProd)
//            {
//                aux = cambioDeEstrucCatalARegistro(seg->dato,arhcivo);
//                fwrite(&aux, sizeof(StRegistroventas), 1, archi);
//                flag=1;
//            }
//            seg = seg->siguiente;
//
//        }
//    }
//
//}
//
//
//
//
//StRegistroventas cambioDeEstrucCatalARegistro(productos dato,char archivo[])//transforma el tio de dato catlogo a uno de registroventa y cargo el la venta y el dia
//{
//
//    StRegistroventas  dest;
//
//    strcpy(dest.nombreDeProductos,dato.nombreDeProductos);
//    dest.id=dato.id;
//    dest.precioPorKilo=dato.precioPorKilo;
//    dest.stock=dato.stock;
//    dest.activoPro=dato.activoPro;
//    printf("\nINGRESE EL DIA DE LA VENTA: ");
//    fflush(stdin);
//    gets(dest.fechaVenta);
//    dest.venta=cargaVenta(dest.stock);
//
//    modificarSatock(archivo,dest.id,dest.venta);
//
//
//    return dest;
//}
//
//int cargaVenta(int stock)
//{
//    int venta;
//    printf("\ncargue la venta del producto: ");
//    scanf("%d",&venta);
//    while(venta>stock)
//    {
//        printf("\ncargue la venta del producto(que no supere el stock disponible): ");
//        scanf("%d",&venta);
//    }
//
//
//    return venta;
//
//}
//
//void modificarSatock(char archi[],int idDelRegistro,int venta)
//{
//    FILE *archivo;
//
//
//    archivo = fopen(archi, "rb+");
//    if (archivo == NULL)
//    {
//        perror("Error al abrir el archivo");
//
//    }
//
//    deposito registro;
//
//    while (fread(&registro, sizeof(deposito), 1, archivo) == 1)
//    {
//        if (registro.id == idDelRegistro)
//        {
//
//            printf("stock antes de la modificación: %d\n", registro.stock);
//            registro.stock=(registro.stock-venta); // Modifica el valor según tus necesidades
//            fseek(archivo, -sizeof(deposito), SEEK_CUR); // Retrocede al inicio del registro
//            fwrite(&registro, sizeof(deposito), 1, archivo); // Escribe el registro modificado
//            printf("stock después de la modificación: %d\n", registro.stock);
//            break;
//        }
//    }
//
//    // Cierra el archivo
//    fclose(archivo);
//
//
//}
//
//void desactivarArchivoVentas (int id)
//{
//    FILE *buffer = fopen(ARCHIVO_VENTAS, "r+b");
//
//    if (buffer != NULL)
//    {
//        StRegistroventas aux;
//
//        int flag = 0;
//
//        while (fread(&aux, sizeof(StRegistroventas), 1, buffer) && flag == 0)
//        {
//
//
//
//            if(aux.id==id)
//            {
//                aux.activoPro = 0;
//
//                // Move the file position indicator to the beginning of the current record
//                fseek(buffer, -sizeof(StRegistroventas), SEEK_CUR);
//
//                // Write the modified record back to the file
//                fwrite(&aux, sizeof(StRegistroventas), 1, buffer);
//
//                printf("\nactivo: %d", aux.activoPro);
//                flag = 1;
//
//            }
//
//        }
//        fclose(buffer);
//    }
//
//
//
//}
//
//
//
