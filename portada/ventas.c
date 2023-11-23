#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "ventas.h"












//FUNCIONE VENTAS EN EL DIA(pasar de arreglo de listas a un archivo de ventas),cambiar el tipo de estructuras y veificar de que suc es el catalogo cuando cargamos el archivo de ventas,, lo podemos hacer wb el archivo asi es venta por dia y guardamos la info en ganancias

//void pasarDeArregloDeposAArchivoVenta(catalogoSuc arreglo[], int pos, int idDeProd, char archivo[], int idDeSuc)
//{
//    FILE *archi = fopen(archivo, "wb");
//
//    if (archi != NULL)
//    {
//        cargarArchivoVentas(arreglo[pos].lista, archi, idDeProd, archivo, idDeSuc);
//        fclose(archi);
//    }
//}
//








void pasarDeArregloDeposAArchivoVenta(catalogoSuc arreglo[], int validos, char archivo[], int idDeSuc)//recorrer el arreglo y pasar los produ
{
    FILE *archi = fopen(archivo, "wb");
    int i=0;
    if (archi != NULL)
    {
        while(i<validos)
        {
            printf("\nCARGUE LAS VENTAS DEL CATALOGO: %s",arreglo[i].nombreDeCategoria);
             cargarArchivoVentas(arreglo[i], archi, archivo, idDeSuc);
             i++;
        }

        fclose(archi);
    }
}






void cargarArchivoVentas(catalogoSuc dato, FILE *archi,  char arhcivo[], int idDeSuc)
{
    nodoproductosSucursal *seg = dato.lista;
    int flag = 0;
    StRegistroventas aux;

    if (archi != NULL)
    {
        while (seg != NULL )
        {
                printf("\nCARGUE LAS VENTAS DEL PRODUCTO: %s",seg->dato.nombreDeproductosDepos);
                aux = cambioDeEstrucCatalARegistro(seg->dato, arhcivo, idDeSuc);
                fwrite(&aux, sizeof(StRegistroventas), 1, archi);




            seg = seg->siguiente;
        }
    }
}




StRegistroventas cambioDeEstrucCatalARegistro(productosDepos dato,char archivo[],int idDeSuc)//transforma el tio de dato catlogo a uno de registroventa y cargo el la venta y el dia
{

    StRegistroventas  dest;

    strcpy(dest.nombreDeProductos,dato.nombreDeproductosDepos);
    dest.id=dato.id;
    dest.precioPorKilo=dato.precioPorKilo;
    dest.stock=dato.stock;

    printf("\nINGRESE EL DIA DE LA VENTA: ");
    fflush(stdin);
    gets(dest.fechaVenta);
    dest.venta=cargaVenta(dest.stock);
    dest.idDSuc=idDeSuc;
    modificarSatock(archivo,dest.id,dest.venta,idDeSuc);


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

void modificarSatock(char archi[],int idDelRegistro,int venta,int idDeSuc)
{
    FILE *archivo;


    archivo = fopen(archi, "rb+");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");

    }

    depositoSucursal registro;

    while (fread(&registro, sizeof(deposito), 1, archivo) == 1)
    {
        if (registro.id == idDelRegistro&& registro.idDeSuc==idDeSuc)
        {

            printf("stock antes de la modificación: %d\n", registro.stock);
            registro.stock=(registro.stock-venta); // Modifica el valor según tus necesidades
            fseek(archivo, -sizeof(depositoSucursal), SEEK_CUR); // Retrocede al inicio del registro
            fwrite(&registro, sizeof(depositoSucursal), 1, archivo); // Escribe el registro modificado
            printf("stock después de la modificación: %d\n", registro.stock);
            break;
        }
    }

    // Cierra el archivo
    fclose(archivo);


}










//
//
//
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




// MUESTRS DE ARCHIVO DE VENTAS

void muestraUnRegistroVentas(StRegistroventas dato)
{

        printf("\nNOMBRE DE PRODUCTO:  %s",dato.nombreDeProductos);
        printf("\nPRECIO POR KILO:%d ",dato.precioPorKilo);

        printf("\nid de productosDepos |%d|",dato.id);
        printf("\nFECHA DE VENTA: %s",dato.fechaVenta);
        printf("\nVenta: %d",dato.venta);
        printf("\n-----------------------------------------------");
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
