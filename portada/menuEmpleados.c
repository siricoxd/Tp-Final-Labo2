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
    menuOpcion2();

    system("color");

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
    printf("\t\t\t|                           1.FUNCIONES DE MUESTRA Y CONSULTA            |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                           2.FUNCIONES DE CARGA Y MODIFICACION          |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                           3.FUNCIONES DE BAJA Y ALTA                   |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                           0. VOLVER                                    |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|________________________________________________________________________|\n");
    printf("\n");
    scanf("%d",&seleccion);
    system("cls");
    return seleccion;
}

void menuOpcion2()
{
    nodoLista* lista=iniclista();
    nodoLista* lista2=iniclista();
    int dni, idSucursal, rango;
    nodoLista* sucursal;
    nodoArbol* encontrado;

    provincia arEmpleados[30];

    int validosProv=0;
    validosProv=descargarArchivo(arEmpleados,validosProv,30);
    int pos;
    lista=pasarDelArchivoToLDA(archivoTrabajadores,lista,idSucursal);
    int opcion;
    int subopcion1;
    int subopcion2;
    int subopcion3;
    int selected;

    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 1: // Sección 1: Funciones de Muestra y Consulta

            do
            {
                system("cls");
                printf("\t\t\t|                             1. MUESTRA DEL ARCHIVO                     |\n");
                printf("\t\t\t|                             2. MOSTRAR LISTA DE TRABAJADORES           |\n");
                printf("\t\t\t|                             3. MOSTRAR TRABAJADORES POR RANGO          |\n");
                printf("\t\t\t|                             4. MOSTRAR TRABAJADORES DE UNA SUCURSAL    |\n");
                printf("\t\t\t|                             5. MOSTRAR DADOS DE BAJA                   |\n");
                printf("\t\t\t|                             6. MOSTRAR EMPLEADO POR DNI                |\n");
                printf("\t\t\t|                             7.MOSTRAR TRABAJADOES ALFABETICAMENTE      |\n");
                printf("\t\t\t|                             0.VOLVER                                   |\n");


                scanf("%d", &subopcion1);
                system("cls");

                switch (subopcion1)
                {
                case 1:
                    mostrarArchivo(archivoTrabajadores);
                    system("Pause");

                    break;
                case 2:

                    mostrarLDA(lista);
                    system("pause");

                    break;
                case 3:

                    printf("Ingrese el rango (1, 2 o 3): \n");
                    fflush(stdin);
                    scanf("%i", &rango);

                    if(rango!=1 && rango!=2 && rango!=3)
                    {
                        printf("Rango no valido\n");
                    }
                    else
                    {
                        mostrarTrabajadoresDeUnRango(lista,rango);
                    }

                    system("pause");

                    break;
                case 4:
                    printf("Ingrese el ID de la sucursal: \n");
                    fflush(stdin);
                    scanf("%i", &idSucursal);

                    sucursal=buscarSucursal(lista,idSucursal);
                    if(sucursal==NULL)
                    {
                        printf("No existe la sucursal\n");
                    }
                    else
                    {
                        mostrarTrabajadoresDeUnaSucursal(lista,idSucursal);
                    }

                    system("pause");
                    break;
                case 5:
                    mostrarBajas(lista);
                    system("pause");
                    break;
                case 6:
                    printf("Ingrese el DNI del trabajador \n");
                    fflush(stdin);
                    scanf("%i", &dni);

                    encontrado=buscarPorDniPrincipal(lista,dni);

                    if(encontrado==NULL)
                    {
                        printf("El dni no existe\n");
                    }
                    else
                    {
                        mostrarPorDniTrabajador(encontrado);
                    }

                    system("pause");


                    break;
                case 7:
                    lista2=pasarDelArchivoToLDAAlfabetico(archivoTrabajadores,lista2,idSucursal);
                    mostrarPorOrdenAlfabetico(lista2);


                     system("pause");
                    break;

                }
            }
            while (subopcion1 != 0);
            break;

        case 2: // Sección 2: Funciones de Carga y Modificación

            do
            {
                system("cls");
                printf("\t\t\t|                             1. CARGA TRABAJADORES POR SUCURSAL        |\n");
                printf("\t\t\t|                             2. CAMBIAR SUELDO                         |\n");
                printf("\t\t\t|                             3. CAMBIAR SUCURSAL                       |\n");
                printf("\t\t\t|                             4. CARGAR HORAS EXTRA                     |\n");
                printf("\t\t\t|                             5. MODIFICAR HORAS EXTRA                  |\n");
                printf("\t\t\t|                             6. MODIFICAR DNI                          |\n");
                printf("\t\t\t|                             7. MODIFICAR NOMBRE                       |\n");
                printf("\t\t\t|                             8. MODIFICAR RANGO                        |\n");
                printf("\t\t\t|                             0. VOLVER                                 |\n");

                scanf("%d", &subopcion2);
                system("cls");

                switch (subopcion2)
                {
                case 1:
                    mostrarTodo(arEmpleados,validosProv);
                    printf("\n\nCargue el id de la sucursal:  ");// esta la voy a pedir del menu de sucursales
                    scanf("%d",&idSucursal);
                    pos=VerificarSucursal(idSucursal);
                    if(pos==1)
                    {
                        cargarArchivoEmpleados(archivoTrabajadores, idSucursal,lista);
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
                case 2:

                    mostrarLDA(lista);

                    printf("Ingrese el DNI del trabajador \n");
                    fflush(stdin);
                    scanf("%i", &dni);

                    encontrado=buscarPorDniPrincipal(lista,dni);

                    if(encontrado==NULL)
                    {
                        printf("El dni no existe\n");
                    }
                    else
                    {
                        cambiarSueldo(archivoTrabajadores,encontrado,dni);
                    }

                    system("pause");

                    break;
                case 3:

                    mostrarLDA(lista);

                    printf("Ingrese el DNI del trabajador \n");
                    fflush(stdin);
                    scanf("%i", &dni);

                    encontrado=buscarPorDniPrincipal(lista,dni);

                    if(encontrado==NULL)
                    {
                        printf("El dni no existe\n");
                    }
                    else
                    {

                        cambiarSucursalTrabajador(archivoTrabajadores,encontrado,dni,lista);
                        selected=0;

                    }

                    system("pause");
                    break;

                case 4:

                    mostrarLDA(lista);

                    printf("Ingrese el DNI del trabajador \n");
                    fflush(stdin);
                    scanf("%i", &dni);

                    encontrado=buscarPorDniPrincipal(lista,dni);

                    if(encontrado==NULL)
                    {
                        printf("El dni no existe\n");
                    }
                    else
                    {
                        cargarHorasExtrasTrabajadores(encontrado,archivoTrabajadores,dni);
                    }

                    system("pause");

                    break;
                case 5:

                    mostrarLDA(lista);

                    printf("Ingrese el DNI del trabajador \n");
                    fflush(stdin);
                    scanf("%i", &dni);

                    encontrado=buscarPorDniPrincipal(lista,dni);

                    if(encontrado==NULL)
                    {
                        printf("El dni no existe\n");
                    }
                    else
                    {
                        cambiarHorasExtras(archivoTrabajadores,encontrado,dni);
                    }

                    system("pause");

                    break;
                case 6:
                    mostrarLDA(lista);

                    printf("Ingrese el DNI del trabajador \n");
                    fflush(stdin);
                    scanf("%i", &dni);

                    encontrado=buscarPorDniPrincipal(lista,dni);

                    if(encontrado==NULL)
                    {
                        printf("El dni no existe\n");
                    }
                    else
                    {
                        cambiarDni(archivoTrabajadores,encontrado,dni,lista);
                    }

                    system("pause");

                    break;
                case 7:
                    mostrarLDA(lista);

                    printf("Ingrese el DNI del trabajador \n");
                    fflush(stdin);
                    scanf("%i", &dni);

                    encontrado=buscarPorDniPrincipal(lista,dni);

                    if(encontrado==NULL)
                    {
                        printf("El dni no existe\n");
                    }
                    else
                    {

                        cambiarNombreTrabajador(archivoTrabajadores,encontrado,dni,lista);

                    }

                    system("pause");

                    break;
                case 8:
                    mostrarLDA(lista);

                    printf("Ingrese el DNI del trabajador \n");
                    fflush(stdin);
                    scanf("%i", &dni);

                    encontrado=buscarPorDniPrincipal(lista,dni);

                    if(encontrado==NULL)
                    {
                        printf("El dni no existe\n");
                    }
                    else
                    {

                        cambiarRango(archivoTrabajadores,encontrado,dni,lista);

                    }

                    system("pause");

                    break;
                }
            }
            while (subopcion2 != 0);
            break;

        case 3: // Sección 3: Funciones de Baja y Alta

            do
            {
                system("cls");
                printf("\t\t\t|                             1. DAR DE BAJA EMPLEADO                    |\n");
                printf("\t\t\t|                             2.DAR DE ALTA EMPLEADO                     |\n");
                printf("\t\t\t|                             0. VOLVER                                  |\n");

                scanf("%d", &subopcion3);
                system("cls");

                switch (subopcion3)
                {
                case 2:
                    mostrarBajas(lista);
                    printf("Ingrese el DNI del trabajador para dar de alta: ");
                    fflush(stdin);
                    scanf("%i", &dni);


                    encontrado = buscarPorDniPrincipal(lista, dni);

                    if (encontrado != NULL)
                    {
                        if(encontrado->dato.baja==1)
                        {
                            printf("Este empleado ya se encuentra dado de alta\n");
                        }
                        else if(encontrado->dato.bajaSucursal==0)
                        {
                            printf("La sucursal de este empleado se encuentra dada de baja\n");
                        }
                        else
                        {
                            darDeAltaNuevo(archivoTrabajadores, encontrado, dni);
                            mostrarLDA(lista);
                        }
                    }
                    else
                    {
                        printf("No se encontro un trabajador con el DNI proporcionado.\n");
                    }

                    system("pause");

                    break;
                case 1:
                    mostrarLDA(lista);
                    printf("Ingrese el DNI del trabajador para dar de baja: ");
                    fflush(stdin);
                    scanf("%i", &dni);


                    encontrado = buscarPorDniPrincipal(lista, dni);

                    if (encontrado != NULL)
                    {
                        if(encontrado->dato.baja==0)
                        {
                            printf("Este empleado ya se encuentra dado de baja\n");
                        }
                        else
                        {
                            darDeBajaNuevo(archivoTrabajadores, encontrado, dni);
                            mostrarLDA(lista);
                        }


                    }
                    else
                    {
                        printf("No se encontro un trabajador con el DNI proporcionado.\n");
                    }

                    system("pause");

                    break;

                }
            }
            while (subopcion3 != 0);
            break;

        case 0:
            // Opción para salir o volver
            break;
        default:
            printf("Opción no válida. Intente de nuevo.\n");
        }
    }
    while (opcion != 0);
}
