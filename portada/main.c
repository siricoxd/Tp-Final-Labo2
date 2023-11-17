#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "portada.h"
#include "listasSucusrsales.h"
int main()
{
    system("Title= Carniceria");
    system("color 0a");
    int eleccion=0,menu=0,login=0,modo=0;
    ///----------------
    ///sucursales
    provincia ar[30];
    int id=1,pos=0;
    int validosSucursal=0;
    validosSucursal=descargarArchivo(ar,validosSucursal,30);
    ///----------------
    do
    {
        login=LogIn();
        if(login==1)
        {
            modo=iniciarSesion();

        }
        else if(login==2)
        {
            registrarse();
            system("cls");
            modo=iniciarSesion();
        }
        if(modo==1)
        {
            do
            {
                eleccion=menuPrincipal();
                switch(eleccion)
                {
                case 1:
                    do
                    {
                        menu=menuSucursales();
                        switch(menu)
                        {
                        case 1:
                            validosSucursal=cargarArchivo(30);
                            validosSucursal=0;
                            validosSucursal=descargarArchivo(ar,validosSucursal,30);//para que se agrege los cargados
                            system("pause");
                            break;
                        case 2:
                            id= menuSucursalesModificar();
                            if(id==1)
                            {
                                printf("Ingrese el id del provincia que desee desactivar: ");
                                scanf("%d",&id);
                                pos=buscarPosProvincia(ar,id,validosSucursal);
                                if(pos!=-1)
                                {
                                    mostrarUnaProvincia(ar[pos]);
                                    printf("Ingrese el id del local que desee desactivar: ");
                                    scanf("%d",&id);
                                    descativarLocal(ar,id,pos);
                                    system("cls");
                                    mostrarUnaProvincia(ar[pos]);
                                }
                                else
                                {
                                    printf("La provincia no se encontro\n");
                                }

                            }
                            if(id==2)
                            {
                                printf("Ingrese el id del provincia que desee activar: ");
                                scanf("%d",&id);
                                pos=buscarPosProvincia(ar,id,validosSucursal);
                                if(pos!=-1)
                                {
                                    mostrarUnaProvincia(ar[pos]);
                                    printf("Ingrese el id del local que desee activar: ");
                                    scanf("%d",&id);
                                    activarLocal(ar,id,pos);
                                    mostrarUnaProvincia(ar[pos]);
                                }
                                else
                                {
                                    printf("La provincia no se encontro\n");
                                }
                            }
                            system("pause");
                            break;
                        case 3:
                            id=menuSucursalesInfo();
                            if(id==1)
                            {
                                int r=cantidadDeRegistros();
                                printf("Cantidad de sucursales existentes: %d\n",r);
                            }
                            if(id==2)
                            {
                                provincias();
                            }
                            system("pause");
                            break;
                        case 4:
                            id= menuSucursalesMostrar();
                            if(id==1)
                            {
                                printf("Ingrese el id del provincia que desee mostrar: ");
                                scanf("%d",&id);
                                pos=buscarPosProvincia(ar,id,validosSucursal);
                                if(pos!=-1)
                                {
                                    mostrarUnaProvincia(ar[pos]);
                                }
                                else
                                {
                                    printf("La provincia no se encontro\n");
                                }
                                system("pause");
                            }
                            if(id==2)
                            {
                                mostrarTodo(ar,validosSucursal);
                                system("pause");
                            }
                            break;
                        case 0:
                            break;

                        }
                    }
                    while(menu!=0);
                    break;
                case 2:
                    system("pause");

                    break;
                case 3:
                    printf("hola\n");
                    system("pause");

                    break;
                case 4:
                    printf("hola\n");
                    system("pause");

                    break;
                case 0:
                    printf("Adios\n");
                    system("pause");
                }

            }
            while(eleccion!=0);
        }
        else if(modo==2)
        {

            printf("hola\n");
            system("pause");
        }
    }
    while(login!=0);
    return 0;
}
