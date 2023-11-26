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

        case 3:
            mostrarLDA(lista);
            system("pause");

            break;
        case 4:
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
                }


            }
            else
            {
                printf("No se encontro un trabajador con el DNI proporcionado.\n");
            }

            system("pause");
            break;
        case 5 :
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
                else
                {
                    darDeAltaNuevo(archivoTrabajadores, encontrado, dni);
                }


            }
            else
            {
                printf("No se encontro un trabajador con el DNI proporcionado.\n");
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

        case 8:

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
        case 9:
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
                if(sucursal->bajaSucursal==0)
                {
                    printf("La sucursal ya se encuentra dada de baja\n");
                }
                else
                {
                    darDeBajaUnaSucursal(archivoTrabajadores,sucursal);
                }

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
                if(sucursal->bajaSucursal==1)
                {
                    printf("La sucursal ya se encuentra dada de alta\n");
                }
                else
                {
                    darDeAltaUnaSucursal(archivoTrabajadores,sucursal);
                }

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

        case 14:
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
        case 15:
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

            }

            system("pause");
            break;

            case 16:
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

            case 17:
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
    printf("\t\t\t|                            FUNCIONES DE MUESTRA Y CONSULTA:            |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             1. MUESTRA DEL ARCHIVO                     |\n");
    printf("\t\t\t|                             2. MOSTRAR LISTA DE TRABAJADORES           |\n");
    printf("\t\t\t|                             3. MOSTRAR TRABAJADORES POR RANGO          |\n");
    printf("\t\t\t|                             4. MOSTRAR TRABAJADORES DE UNA SUCURSAL    |\n");
    printf("\t\t\t|                             5. MOSTRAR DADOS DE BAJA                   |\n");
    printf("\t\t\t|                             6. MOSTRAR EMPLEADO POR DNI****            |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                              FUNCIONES DE CARGA Y MODIFICACION:        |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             7. CARGA TRABAJADORES POR SUCURSAL         |\n");
    printf("\t\t\t|                             8. CAMBIAR SUELDO                          |\n");
    printf("\t\t\t|                             9. CAMBIAR SUCURSAL                        |\n");
    printf("\t\t\t|                             10. CARGAR HORAS EXTRA                     |\n");
    printf("\t\t\t|                             11. MODIFICAR HORAS EXTRA                  |\n");
    printf("\t\t\t|                             12. MODIFICAR DNI                          |\n");
    printf("\t\t\t|                             13. MODIFICAR NOMBRE                       |\n");
    printf("\t\t\t|                             14. MODIFICAR RANGO                        |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             FUNCIONES DE BAJA Y ALTA                   |\n");
    printf("\t\t\t|                             15. DAR DE BAJA EMPLEADO                   |\n");
    printf("\t\t\t|                             16. DAR DE ALTA EMPLEADO                   |\n");
    printf("\t\t\t|                             17. DAR DE BAJA SUCURSAL                   |\n");
    printf("\t\t\t|                             18. DAR DE ALTA SUCURSAL                   |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             0. VOLVER                                  |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|________________________________________________________________________|\n");
    printf("\n");
    scanf("%d",&seleccion);
    system("cls");
    return seleccion;

}
