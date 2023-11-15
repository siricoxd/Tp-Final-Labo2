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



    return 0;
}



int menuOpcion()
{
    int selected;
    nodoLista* lista=iniclista();
    int dni, idSucursal;
    nodoLista* sucursal;
    nodoArbol* trabajador;


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

            system("pause");
            break;

        case 3:
            lista=pasarDelArchivoToLDA(archivoTrabajadores, lista);
            mostrarLDA(lista);
            system("pause");

            break;
        case 4:

            printf("Ingrese el de la sucursal del trabajador para dar de baja\n");
                fflush(stdin);
                scanf("%i", &idSucursal);

            sucursal=buscarSucursal(lista,idSucursal);

            if(sucursal==NULL){
                printf("No se encontro la sucursal\n");
            }else{
            printf("Ingrese el dni del trabajador al que quiere dar de baja\n");
                fflush(stdin);
                scanf("%i", &dni);

                trabajador=buscarPorDni(sucursal->arbol, dni);

                if(trabajador==NULL){
                    printf("No se encontro el dni\n");
                }else{
                lista=darD
                }
            }




            system("pause");

            break;
        case 5 :


            system("pause");

            break;
        case 6:

            system("pause");
            break;
        case 7:

            system("pause");
            break;

        case 8:

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
    printf("\n\t\t\t\t\t\t\t\t\t6-CARGA ARCHIVO VENTAS");
    printf("\n\t\t\t\t\t\t\t\t\t7-MUESTRA ARCHIVO VENTAS");
    printf("\n\t\t\t\t\t\t\t\t\t8-DESACTIVAR DATO DE VENTAS");

    printf("\n\n\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d",&input);
    system("cls");
    return input;
}

