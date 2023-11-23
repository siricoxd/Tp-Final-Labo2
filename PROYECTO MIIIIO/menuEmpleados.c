#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proyecto.h"
#define archivoTrabajadores "archivotrabajadores.bin"
#include <windows.h>
#include "libreriaEmpleados.h"

int menu();
int menuOpcion();
int mainEmpleados()
{
system("color C0");


    menuOpcion();

system("color");

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
            mostrarBajas(lista);

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

            case 15:

            printf("\nIngrese id de la sucursal:");
            scanf("%i",&idSucursal);

            sucursal=buscarSucursal(lista,idSucursal);

            if(sucursal == NULL)
            {
                printf("\nNo se encontro la sucursal \n");
            }
            else
            {
                cargarHorasExtrasTrabajadores(sucursal,archivoTrabajadores);
            }

            system("pause");
            break;

            case 16:

            printf("\nIngrese id de la sucursal:");
            scanf("%i",&idSucursal);

            sucursal=buscarSucursal(lista,idSucursal);

            if(sucursal == NULL)
            {
                printf("\nNo se encontro la sucursal \n");
            }
            else
            {
                modificarHorasExtrasTrabajadores(sucursal,archivoTrabajadores);
            }

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
    system("cls");
    int seleccion=0;
    printf("\n\n\n");
    printf("\t\t\t ________________________________________________________________________\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|       ####   #   #  ###    #      ####     #    ###     ##     ##      |\n");
    printf("\t\t\t|       #      ## ##  #  #   #      #       # #   #  #   #  #   #  #     |\n");
    printf("\t\t\t|       ###    # # #  #  #   #      ###    #   #  #  #   #  #    #       |\n");
    printf("\t\t\t|       #      # # #  ###    #      #      #####  #  #   #  #     #      |\n");
    printf("\t\t\t|       #      #   #  #      #      #      #   #  #  #   #  #   #  #     |\n");
    printf("\t\t\t|       ####   #   #  #      ####   ####   #   #  ###     ##     ##      |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             1. MUESTRA DEL ARCHIVO                     |\n");
    printf("\t\t\t|                             2.CARGA DEL ARCHIVO                        |\n");
    printf("\t\t\t|                             3.MOSTRAR TRABAJADORES                     |\n");
    printf("\t\t\t|                             4. DAR DE BAJA TRABAJADOR                  |\n");
    printf("\t\t\t|                             5. DAR DE ALTA TRABAJADOR                  |\n");
    printf("\t\t\t|                             6. MUESTRA TRABAJADORES DADOS DE BAJA      |\n");
    printf("\t\t\t|                             7. AGREGAR UN TRABAJADOR                   |\n");
    printf("\t\t\t|                             8. MOSTRAR LOS TRABAJADORES DE UNA SUCURSAL|\n");
    printf("\t\t\t|                             9. MOSTRAR LOS TRABAJADORES DE UN RANGO    |\n");
    printf("\t\t\t|                             10. CAMBIAR SUELDO                         |\n");
    printf("\t\t\t|                             11. DAR DE BAJA SUCURSAL                   |\n");
    printf("\t\t\t|                             12. DAR DE ALTA SUCURSAL                   |\n");
    printf("\t\t\t|                             13. DAR DE BAJA PROVINCIA                  |\n");
    printf("\t\t\t|                             14. DAR DE ALTA PROVINCIA                  |\n");
    printf("\t\t\t|                             15. CARGAR HORAS EXTRA                     |\n");
    printf("\t\t\t|                             16. MODIFICAR HORAS EXTRA                  |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             0. VOLVER                                  |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|________________________________________________________________________|\n");
    printf("\n");
    scanf("%d",&seleccion);
    system("cls");
    return seleccion;

}
