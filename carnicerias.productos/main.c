#include <stdio.h>
#include <stdlib.h>
#include "listasProductos.h"
#define ARCHIVO_CATALOGO "catalogo.bin"
#include <windows.h>


void imprimirBarraCarga(int porcentaje);
void barra();

int menu();
int menuOpcion();
int main()
{

              menuOpcion();



    return 0;
}



int menuOpcion()
{
    int selected;
    catalogo arreglo[40];
    int validos = 0, buscar = 0, pos = 0;
    int idDeProdu=0;
    do
    {
        selected = menu();

        switch (selected)
        {
        case 1:
            barra();
            muestraArchivo(ARCHIVO_CATALOGO);
            system("Pause");
            break;

        case 2:
           printf("\nARCHIVO:\n");

            cargaArchivo(ARCHIVO_CATALOGO);
            muestraArchivo(ARCHIVO_CATALOGO);
            system("pause");
            break;

        case 3:
            validos = pasardeArchivoAArreglo(ARCHIVO_CATALOGO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);
            system("pause");

            break;
        case 4:

            printf("\ningrese el id del catalogo que desea desactivar\n");
            scanf("%d", &buscar);
            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);

            if (pos !=-1 ) {
                desactivarCatalogo(arreglo, buscar, pos-1);
                validos = pasardeArchivoAArreglo(ARCHIVO_CATALOGO, arreglo, 40);
                muestraDeCatalogo(arreglo, validos);

            }
            else
            {
                printf("\nno se encontro catalogo\n");
            }

            system("pause");

            break;
        case 5 :





            printf("\ningrese el id del catalogo del producto a dersactivar\n");
            scanf("%d", &buscar);
              printf("\nINGRESE EL ID DEL PRODUCTO A DAR DE BAJA");
            scanf("%d",&idDeProdu);
            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
             if (pos !=-1 ) {
                desactivarProducto(arreglo, idDeProdu, pos-1);
                validos = pasardeArchivoAArreglo(ARCHIVO_CATALOGO, arreglo, 40);
                muestraDeCatalogo(arreglo,validos);

            }
            else
            {
                printf("\nno se encontro catalogo\n");
            }

            system("pause");

            break;
        case 6:
               validos = pasardeArchivoAArreglo(ARCHIVO_CATALOGO, arreglo, 40);
             muestraDeCatalogo(arreglo, validos);
              printf("\ningrese el id del catalogo del producto a modificar sotck\n");
            scanf("%d", &buscar);
              printf("\nINGRESE EL ID DEL PRODUCTO A a modificar");
            scanf("%d",&idDeProdu);
            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
              system("pause");
            system("cls");

             if (pos !=-1 ) {
                pasarDeArregloAArchivo(arreglo[pos],idDeProdu,ARCHIVO_VENTAS);

                  muestraArchivoVentas(ARCHIVO_VENTAS);
            }
            else
            {
                printf("\nno se encontro catalogo\n");
            }

              system("pause");
            break;
        case 7:
            muestraArchivoVentas(ARCHIVO_VENTAS);
              system("pause");
            break;

        case 8:
             muestraArchivoVentas(ARCHIVO_VENTAS);
            printf("\nINGRESE EL ID DEL ARCHIVO A DESACTIVAR");
            scanf("%d",&idDeProdu);
            desactivarArchivoVentas(idDeProdu);
             system("pause");
            break;


        case 0:

            printf("\n\nTERMINATE THE PROGRAM\n");
            break;
        }

    } while (selected != 0);

    system("PAUSE");
    return 0;
}
int menu()
{

    int input;
    system("cls");

    printf("\t\t\t\t\t\t\t\t\n----------");

    printf("                   \n MENU");
    printf("\n\t\t\t\t\t\t\t\t\t-----------");
    printf("\n\t\t\t\t\t\t\t\t\t1MUESTRA DEL ARCHIVO");
    printf("\n\t\t\t\t\t\t\t\t\t2-CARGA DEL ARCHIVO");
    printf("\n\t\t\t\t\t\t\t\t\t3-MOSTRAR ARREGLO DE LISTAS ");
    printf("\n\t\t\t\t\t\t\t\t\t4-DAR DE BAJA CATEGORIA");
    printf("\n\t\t\t\t\t\t\t\t\t5-DAR DE BAJA PRODUCTO");
    printf("\n\t\t\t\t\t\t\t\t\t6-CARGA ARCHIVO VENTAS");
    printf("\n\t\t\t\t\t\t\t\t\t7-MUESTRA ARCHIVO VENTAS");
    printf("\n\t\t\t\t\t\t\t\t\t8-DESACTIVAR DATO DE VENTAS");

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
        usleep(10000); // Esperar 100ms (0.1 segundos)
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










