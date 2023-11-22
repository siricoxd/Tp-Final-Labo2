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
    int dni, idSucursal, rango;
    nodoLista* sucursal;
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

            darDeBajaCase(archivoTrabajadores,lista,sucursal,encontrado,&idSucursal,&dni,&rango);

            system("pause");

            break;
        case 5 :

            darDeAltaCase(archivoTrabajadores,lista,sucursal,encontrado,&idSucursal,&dni,&rango);

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


            mostrarTrabajadoresDeUnaSucursalCase(&idSucursal,lista);

            system("pause");
            break;

        case 9:

            mostrarTrabajadoresDeUnRangoCase(&rango,lista);

            system("pause");
            break;
        case 10:
            cambiarSueldoCase(archivoTrabajadores,lista,sucursal,encontrado,&idSucursal,&dni,&rango);
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

    printf("\n\n\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d",&input);
    system("cls");
    return input;
}
