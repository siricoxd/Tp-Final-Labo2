#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#define archivoTrabajadores "archivotrabajadores.bin"
#include <windows.h>
#include "menuEmpleados.h"
#include "listasSucusrsales.h"

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
    int dni, idSucursal, rango;
    nodoLista* sucursal;
    nodoArbol* encontrado;

    provincia arEmpleados[30];

    int validosProv=0;
    validosProv=descargarArchivo(arEmpleados,validosProv,30);
    int pos;
    lista=pasarDelArchivoToLDA(archivoTrabajadores,lista,idSucursal);



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
            mostrarTodo(arEmpleados,validosProv);
            printf("\n\nCargue el id de la sucursal:  ");// esta la voy a pedir del menu de sucursales
            scanf("%d",&idSucursal);
            pos=VerificarSucursal(idSucursal);
            if(pos==1)
            {
                cargarArchivoEmpleados(archivoTrabajadores, idSucursal);
                mostrarArchivo(archivoTrabajadores);
                lista = iniclista();
                lista=pasarDelArchivoToLDA(archivoTrabajadores, lista, idSucursal);

            }
            else
            {
                printf("No Existe la sucursal\n");
                system("pause");
                break;
            }


            system("pause");
            break;

        case 3:
            mostrarLDA(lista);
            system("pause");

            break;
        case 4:
            mostrarLDA(lista);
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

                    encontrado=buscarPorDni(sucursal->arbol,dni,rango);
                    if(encontrado==NULL)
                    {
                        printf("No se encontro el dni\n");
                    }
                    else
                    {
                        darDeBaja(archivoTrabajadores,sucursal,dni,rango);
                    }



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

                    encontrado=buscarPorDni(sucursal->arbol,dni,rango);
                    if(encontrado==NULL)
                    {
                        printf("No se encontro el dni\n");
                    }
                    else
                    {
                        darDeAlta(archivoTrabajadores,sucursal,dni,rango);
                    }



                }
            }

            system("pause");

            break;
        case 6:
            mostrarBajas(lista);

            system("pause");
            break;

        case 7:


            printf("Ingrese el ID de la sucursal: \n");
            fflush(stdin);
            scanf("%i", &idSucursal);

            mostrarTrabajadoresDeUnaSucursal(lista,idSucursal);

            system("pause");
            break;

        case 8:

            printf("Ingrese el rango (1, 2 o 3): \n");
            fflush(stdin);
            scanf("%i", &rango);

            mostrarTrabajadoresDeUnRango(lista,rango);

            system("pause");
            break;
        case 9:
            mostrarLDA(lista);

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

                    encontrado=buscarPorDni(sucursal->arbol,dni,rango);
                    if(encontrado==NULL)
                    {
                        printf("No se encontro el dni\n");
                    }
                    else
                    {
                        cambiarSueldo(archivoTrabajadores,sucursal,dni,rango);
                    }



                }
            }

            system("pause");
            break;

        case 10:

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

        case 11:

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




        case 12:
            mostrarLDA(lista);

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

        case 13:
            mostrarLDA(lista);

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
    printf("\t\t\t|                             2.CARGA TRABAJADORES POR SUCURSAL          |\n");
    printf("\t\t\t|                             3.MOSTRAR TRABAJADORES                     |\n");
    printf("\t\t\t|                             4. DAR DE BAJA TRABAJADOR                  |\n");
    printf("\t\t\t|                             5. DAR DE ALTA TRABAJADOR                  |\n");
    printf("\t\t\t|                             6. MUESTRA TRABAJADORES DADOS DE BAJA      |\n");
    printf("\t\t\t|                             7. MOSTRAR LOS TRABAJADORES DE UNA SUCURSAL|\n");
    printf("\t\t\t|                             8. MOSTRAR LOS TRABAJADORES DE UN RANGO    |\n");
    printf("\t\t\t|                             9. CAMBIAR SUELDO                          |\n");
    printf("\t\t\t|                             10. DAR DE BAJA SUCURSAL                   |\n");
    printf("\t\t\t|                             11. DAR DE ALTA SUCURSAL                   |\n");
    printf("\t\t\t|                             12. CARGAR HORAS EXTRA                     |\n");
    printf("\t\t\t|                             13. MODIFICAR HORAS EXTRA                  |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             0. VOLVER                                  |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|________________________________________________________________________|\n");
    printf("\n");
    scanf("%d",&seleccion);
    system("cls");
    return seleccion;

}
