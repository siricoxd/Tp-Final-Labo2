#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proyectomio.h"
#define archivoTrabajadores "archivotrabajadores.bin"
#include <windows.h>


int menu();
int menuOpcion();
int main()
{

    menuOpcion();

//remove(archivoTrabajadores);

    return 0;
}



int menuOpcion()
{
    int selected;
    nodoLista* lista=iniclista();
    int dni, idSucursal, rango, idProvincia;
    nodoLista* sucursal;
    nodoLista* provincia;
    nodoArbol* encontrado;
    lista=pasarDelArchivoToLDA(archivoTrabajadores,lista);

    do
    {
        selected = menu();

        switch (selected)
        {
        case 1:

            mostrarArchivo(archivoTrabajadores);
            system("Pause");
            break;

        case 2:
            cargarArchivo(archivoTrabajadores);
            mostrarArchivo(archivoTrabajadores);
            lista = iniclista();
            lista=pasarDelArchivoToLDA(archivoTrabajadores, lista);

            system("pause");
            break;

        case 3:
            mostrarLDA(lista);
            system("pause");

            break;
        case 4:

            printf("Ingrese el ID de la sucursal del trabajador para dar de baja\n");
            fflush(stdin);
            scanf("%i", &idSucursal);

            sucursal=buscarSucursal(lista,idSucursal);

            if(sucursal==NULL)
            {
                printf("No se encontro la sucursal\n");
            }
            else
            {
                printf("Ingrese el rango del trabajador para dar de baja\n");
                fflush(stdin);
                scanf("%i", &rango);

                encontrado=buscarPorRango(sucursal->arbol, rango);
                if(encontrado==NULL)
                {
                    printf("No se encontro el rango\n");
                }
                else
                {
                    printf("Ingrese el dni del trabajador al que quiere dar de baja\n");
                    fflush(stdin);
                    scanf("%i", &dni);

                    darDeBaja(archivoTrabajadores,sucursal,dni,rango);

                }
            }


            system("pause");

            break;
        case 5 :

            printf("Ingrese el ID de la sucursal del trabajador para dar de alta\n");
            fflush(stdin);
            scanf("%i", &idSucursal);

            sucursal=buscarSucursal(lista,idSucursal);

            if(sucursal==NULL)
            {
                printf("No se encontro la sucursal\n");
            }
            else
            {
                printf("Ingrese el rango del trabajador para dar de alta\n");
                fflush(stdin);
                scanf("%i", &rango);

                encontrado=buscarPorRango(sucursal->arbol, rango);
                if(encontrado==NULL)
                {
                    printf("No se encontro el rango\n");
                }
                else
                {
                    printf("Ingrese el dni del trabajador al que quiere dar de alta\n");
                    fflush(stdin);
                    scanf("%i", &dni);

                    darDeAlta(archivoTrabajadores,sucursal,dni,rango);

                }
            }

            system("pause");

            break;
        case 6:
            mostrarBajas(lista);

            system("pause");
            break;
        case 7:
            agregarTrabajadores(archivoTrabajadores, lista);

            system("pause");
            break;

        case 8:


            printf("Ingrese el ID de la sucursal: \n");
            fflush(stdin);
            scanf("%i", &idSucursal);

            mostrarTrabajadoresDeUnaSucursal(lista,idSucursal);

            system("pause");
            break;

        case 9:

            printf("Ingrese el rango: \n");
            fflush(stdin);
            scanf("%i", &rango);

            mostrarTrabajadoresDeUnRango(lista,rango);

            system("pause");
            break;
        case 10:
            printf("Ingrese el ID de la sucursal del trabajador \n");
            fflush(stdin);
            scanf("%i", &idSucursal);

            sucursal=buscarSucursal(lista,idSucursal);

            if(sucursal==NULL)
            {
                printf("No se encontro la sucursal\n");
            }
            else
            {
                printf("Ingrese el rango del trabajador \n");
                fflush(stdin);
                scanf("%i", &rango);

                encontrado=buscarPorRango(sucursal->arbol, rango);
                if(encontrado==NULL)
                {
                    printf("No se encontro el rango\n");
                }
                else
                {
                    printf("Ingrese el dni del trabajador \n");
                    fflush(stdin);
                    scanf("%i", &dni);

                    cambiarSueldo(archivoTrabajadores,sucursal,dni,rango);

                }
            }

            system("pause");
            break;

        case 11:

            printf("Ingrese el id de la sucursal para dar de baja:\n");
            fflush(stdin);
            scanf("%i", &idSucursal);

            sucursal=buscarSucursal(lista,idSucursal);

            if(sucursal==NULL)
            {
                printf("No se encontro la sucursal\n");
            }
            else
            {
                darDeBajaUnaSucursal(archivoTrabajadores,sucursal);
            }




            system("pause");
            break;

        case 12:

            printf("Ingrese el id de la sucursal para dar de alta:\n");
            fflush(stdin);
            scanf("%i", &idSucursal);

            sucursal=buscarSucursal(lista,idSucursal);

            if(sucursal==NULL)
            {
                printf("No se encontro la sucursal\n");
            }
            else
            {
                darDeAltaUnaSucursal(archivoTrabajadores,sucursal);
            }




            system("pause");
            break;

             case 13:

            printf("Ingrese el id de la provincia para dar de baja:\n");
            fflush(stdin);
            scanf("%i", &idProvincia);

            provincia=buscarProvincia(lista,idProvincia);

            if(provincia==NULL)
            {
                printf("No se encontro la provincia\n");
            }
            else
            {
                darDeBajaUnaProvincia(archivoTrabajadores,provincia, idProvincia);
            }




            system("pause");
            break;

            case 14:

            printf("Ingrese el id de la provincia para dar de alta:\n");
            fflush(stdin);
            scanf("%i", &idProvincia);

            provincia=buscarProvincia(lista,idProvincia);

            if(provincia==NULL)
            {
                printf("No se encontro la provincia\n");
            }
            else
            {
                darDeAltaUnaProvincia(archivoTrabajadores,provincia, idProvincia);
            }




            system("pause");
            break;

        case 0:

            printf("\n\nTERMINATE THE PROGRAM\n");
            break;
        }

    }
    while (selected != 0);

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
    printf("\n\t\t\t\t\t\t\t\t\t3-MOSTRAR LA LISTA DE ARBOLES ");
    printf("\n\t\t\t\t\t\t\t\t\t4-DAR DE BAJA TRABAJADOR");
    printf("\n\t\t\t\t\t\t\t\t\t5-DAR DE ALTA TRABAJADOR");
    printf("\n\t\t\t\t\t\t\t\t\t6-MUESTRA TRABAJADORES DADOS DE BAJA");
    printf("\n\t\t\t\t\t\t\t\t\t7-AGREGAR UN TRABAJADOR");
    printf("\n\t\t\t\t\t\t\t\t\t8-MOSTRAR LOS TRABAJADORES DE UNA SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t9-MOSTRAR LOS TRABAJADORES DE UN RANGO");
    printf("\n\t\t\t\t\t\t\t\t\t10-CAMBIAR SUELDO");
    printf("\n\t\t\t\t\t\t\t\t\t11-DAR DE BAJA SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t12-DAR DE ALTA SUCURSAL");
    printf("\n\t\t\t\t\t\t\t\t\t13-DAR DE BAJA PROVINCIA");
    printf("\n\t\t\t\t\t\t\t\t\t14-DAR DE ALTA PROVINCIA");


    printf("\n\n\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d",&input);
    system("cls");
    return input;
}
