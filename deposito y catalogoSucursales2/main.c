#include <stdio.h>
#include <stdlib.h>
#include "listasProductos.h"
#define ARCHIVO_DEPOSITO "deposito.bin"
#define ARCHIVO_SUCUSALDep "depsucursal.bin"
#include <windows.h>
#include "depositoSucursal.h"


void imprimirBarraCarga(int porcentaje);
void barra();

int menuDeposito();
int menuOpcionDeposito();
int main()
{

    menuOpcionDeposito();



    return 0;
}



int menuOpcionDeposito()
{
    int selected;
    catalogo arreglo[40];
    catalogoDepos arregloSucur[40];
    int validos = 0, buscar = 0, pos = 0;
    int idDeProdu=0;
    nodoProductos *buscado;
    int idDesuc;
    int stock;
    do
    {
        selected = menuDeposito();

        switch (selected)
        {
        case 1:
            //barra();
            muestraArchivo(ARCHIVO_DEPOSITO);
            system("Pause");
            break;

        case 2:
            printf("\nARCHIVO:\n");

            cargaArchivo(ARCHIVO_DEPOSITO);
            muestraArchivo(ARCHIVO_DEPOSITO);
            system("pause");
            break;

        case 3:
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);
            system("pause");

            break;
        case 4:
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);

            printf("\ningrese el id del catalogo que desea desactivar\n");
            scanf("%d", &buscar);
            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);

            if (pos !=-1 )
            {
                desactivarCatalogo(ARCHIVO_DEPOSITO,arreglo, buscar, pos);
                validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
                muestraDeCatalogo(arreglo, validos);

            }
            else
            {
                printf("\nno se encontro catalogo\n");
            }

            system("pause");

            break;
        case 5 :



            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);

            printf("\ningrese el id del catalogo del producto a dersactivar\n");
            scanf("%d", &buscar);
            printf("\nINGRESE EL ID DEL PRODUCTO A DAR DE BAJA");
            scanf("%d",&idDeProdu);

            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
            buscado=buscaEnListaId(arreglo,pos,idDeProdu);


            if (pos !=-1 )
            {
                if(buscado!=NULL)
                {
                    desactivarProducto(ARCHIVO_DEPOSITO,arreglo, pos,buscado);
                }
                else
                {
                    printf("\nno se encontro producto\n");
                }


            }
            else
            {
                printf("\nno se encontro catalogo\n");
            }

            system("pause");

            break;
        case 6:
             validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogoNoActivo(arreglo, validos);

            printf("\ningrese el id del catalogo del producto a activar\n");
            scanf("%d", &buscar);
            printf("\nINGRESE EL ID DEL PRODUCTO A  activar");
            scanf("%d",&idDeProdu);

            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
            buscado=buscaEnListaId(arreglo,pos,idDeProdu);

            activarProducto(ARCHIVO_DEPOSITO,arreglo,pos,buscado);
            system("pause");
            break;

        case 7:
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);

            printf("\ningrese el id del catalogo del producto a modificar sotck\n");
            scanf("%d", &buscar);

            printf("\nINGRESE EL ID DEL PRODUCTO A a modificar");
            scanf("%d",&idDeProdu);
            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);

            system("pause");
            system("cls");

            if (pos !=-1 )
            {
                pasarDeArregloAArchivo(arreglo[pos],idDeProdu,ARCHIVO_VENTAS);

                muestraArchivoVentas(ARCHIVO_VENTAS);
            }
            else
            {
                printf("\nno se encontro catalogo\n");
            }

            system("pause");
            break;
        case 8:
            muestraArchivoVentas(ARCHIVO_VENTAS);
            system("pause");
            break;

        case 9:
            muestraArchivoVentas(ARCHIVO_VENTAS);
            printf("\nINGRESE EL ID DEL ARCHIVO A DESACTIVAR");
            scanf("%d",&idDeProdu);
            desactivarArchivoVentas(idDeProdu);
            system("pause");
            break;

        case 10:


            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);


            printf("\ningrese el id del catalogo del producto a modificar stock\n");
            scanf("%d", &buscar);
            printf("\nINGRESE EL ID DEL PRODUCTO a modificar stock");
            scanf("%d",&idDeProdu);

            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
            buscado=buscaEnListaId(arreglo,pos,idDeProdu);

            printf("\n\ncargue el id de la suc:  ");// esta la voy a pedir del menu de sucursales
            scanf("%d",&idDesuc);

            stock=cargarStockYmodificarlos(ARCHIVO_DEPOSITO,buscado);

            if(modificarStockEnArchivoDepSuc(ARCHIVO_SUCUSALDep,idDeProdu,idDesuc,stock)==1)//separa la funcion verifiar si en el archivo existe y si exite modificar su atock
            {
                // modificarStockEnArchivoDepSuc(ARCHIVO_SUCUSALDep,idDeProdu,idDesuc,stock);
            }
            else
            {
                recorrerDeposito(ARCHIVO_DEPOSITO,ARCHIVO_SUCUSALDep,idDesuc,idDeProdu,stock);
                // muestraArchivoSucursal(ARCHIVO_SUCUSALDep);
            }
            system("pause");
        case 11:

            muestraArchivoSucursal(ARCHIVO_SUCUSALDep);
            system("pause");

        case 12:

            printf("\n\ncargue el id de la suc:  ");// esta la voy a pedir del menu de sucursales
            scanf("%d",&idDesuc);

            printf("\nMUESTRA DEPOSITO DEL LOCAL:\n");
            validos=pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep,arregloSucur,40,idDesuc);
            printf("\nvalidos: %d",validos);
            muestraDecatalogoSucursal(arregloSucur,validos);
            system("pause");
            break;

            system("pause");
            break;

        case 13:



             printf("\n\ncargue el id de la suc:  ");// esta la voy a pedir del menu de sucursales
            scanf("%d",&idDesuc);

            validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
           muestraDecatalogoSucursal(arregloSucur, validos);

            printf("\ningrese el id del catalogo del producto a dersactivar\n");
            scanf("%d", &buscar);
            printf("\nINGRESE EL ID DEL PRODUCTO A DAR DE BAJA");
            scanf("%d",&idDeProdu);


            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
            buscado=buscaEnListaId(arreglo,pos,idDeProdu);


            if (pos !=-1 )
            {
                if(buscado!=NULL)
                {
                    desactivarProductoEnSucursal(ARCHIVO_SUCUSALDep,arregloSucur, pos,buscado,idDesuc);
                }
                else
                {
                    printf("\nno se encontro producto\n");
                }


            }
            else
            {
                printf("\nno se encontro catalogo\n");
            }

            system("pause");

        case 0:


            printf("\n\nTERMINATE THE PROGRAM\n");
            break;
        }

    }
    while (selected != 0);

    system("PAUSE");
    system("cls");
    return 0;
}
int menuDeposito()
{

    int input;
    system("cls");

    printf("\t\t\t\t\t\t\t\t\n----------");

    printf("                   \n MENU");
    printf("\n\t\t\t\t\t\t\t\t\t-----------");
    printf("\n\t\t\t\t\t\t\t\t\t1MUESTRA DEL ARCHIVO DEPOSTIO");
    printf("\n\t\t\t\t\t\t\t\t\t2-CARGA DEL ARCHIVO DEPOSITO");
    printf("\n\t\t\t\t\t\t\t\t\t3-MOSTRAR ARREGLO DE LISTAS DEPOSITO ");
    printf("\n\t\t\t\t\t\t\t\t\t4-DAR DE BAJA CATEGORIA del DEPOSITO");
    printf("\n\t\t\t\t\t\t\t\t\t5-DAR DE BAJA PRODUCTO DEL DEPOSITO" );
    printf("\n\t\t\t\t\t\t\t\t\t6-CARGA ARCHIVO VENTAS ");// PASAR A LIBRERIA CATALOGO DE CARNICERIAS
    printf("\n\t\t\t\t\t\t\t\t\t7-MUESTRA ARCHIVO VENTAS");
    printf("\n\t\t\t\t\t\t\t\t\t8-DESACTIVAR DATO DE VENTAS");
    printf("\n\t\t\t\t\t\t\t\t\t9-CARGAR ARCHIVO DE DEPOSITO SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t10-MOSTRAR ARCHIVO DE DEPOSITO SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t11-MOSTRAR DE DEPOSITO SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t-12- DAR DE BAJA PRODUCTO DE DEPOSITO SUCURSAL");

    printf("\n\n\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d",&input);
    system("cls");
    return input;
}






//BARRA DE CARGA INNCIO
void barra()
{
    printf("\n");
    printf("+------------------+\n");
    printf("|                  |\n");
    printf("|    CARGANDO...   |\n");
    printf("|                  |\n");
    printf("|------------------|");
    printf("\n");
    int porcentaje;
    for (porcentaje = 0; porcentaje <= 100; porcentaje++)
    {
        imprimirBarraCarga(porcentaje);
        Sleep(10000); // Esperar 100ms (0.1 segundos)
    }
    printf("\nCarga completa\n");
    // sleep(1);
    system("cls");
}

void imprimirBarraCarga(int porcentaje)
{
    int i;
    for (i = 0; i < 50; i++)
    {
        if (i < porcentaje / 2)
        {
            printf("#");
        }
        else
        {
            printf(" ");
        }
        fflush(stdout); // Limpiar y mostrar la salida inmediatamente
    }
    printf("] %d%%\r", porcentaje);
    fflush(stdout); // Limpiar y mostrar la salida inmediatamente
}










