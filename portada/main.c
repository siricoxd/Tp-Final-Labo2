#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"listasSucusrsales.h"
#include "portada.h"
#include "menus.h"

int main()
{
///---------------------------------------------------------------///
    system("Title= Carniceria");
    system("color 0a");
    ///----------------
    ///Variables del menu
    int eleccion=0,menu=0,login=0,modo=0,elecMenu=0;
    ///----------------
    ///sucursales
    provincia ar[30];
    int id=1,pos=0;
    int validosSucursal=0;
    validosSucursal=descargarArchivo(ar,validosSucursal,30);
    ///----------------
///---------------------------------------------------------------///
    do
    {
        modo=0;
        login=LogIn();
        if(login==1)
        {
            modo=iniciarSesion();
        }
        else if(login==2)
        {
            registrarse();
            system("cls");
            modo=iniciarSesion();//si te registras despues inicias sesion
        }
        if(modo==1)
        {
            do
            {
                elecMenu=menuPrincipal();
                switch(elecMenu)
                {
                case 1://Funciones de Sucursales
                    do
                    {
                        menu=menuSucursales();
                        switch(menu)
                        {
                        case 1://Agregar sucursal
                            validosSucursal=cargarArchivo(30);
                            validosSucursal=0;
                            validosSucursal=descargarArchivo(ar,validosSucursal,30);//para que se agrege los cargados
                            system("pause");
                            break;
                        case 2://baja logica
                            id= menuSucursalesModificar();
                            if(id==1)//Desactivar
                            {
                                printf("Ingrese el id del provincia que desee desactivar: ");
                                scanf("%d",&id);
                                pos=buscarPosProvincia(ar,id,validosSucursal);
                                if(pos!=-1)
                                {
                                    mostrarUnaProvincia(ar[pos]);//Muestra la provincia y sus sucursales
                                    printf("Ingrese el id del local que desee desactivar: ");
                                    scanf("%d",&id);
                                    descativarLocal(ar,id,pos);
                                    system("cls");
                                    mostrarUnaProvincia(ar[pos]);//Muestra la provincia y sus sucursales despues del cambio
                                }
                                else
                                {
                                    printf("La provincia no se encontro\n");
                                }

                            }
                            if(id==2)//Activar
                            {
                                printf("Ingrese el id del provincia que desee activar: ");
                                scanf("%d",&id);
                                pos=buscarPosProvincia(ar,id,validosSucursal);
                                if(pos!=-1)
                                {
                                    mostrarUnaProvincia(ar[pos]);//Muestra la provincia y sus sucursales
                                    printf("Ingrese el id del local que desee activar: ");
                                    scanf("%d",&id);
                                    activarLocal(ar,id,pos);
                                    mostrarUnaProvincia(ar[pos]);//Muestra la provincia y sus sucursales despues del cambio
                                }
                                else
                                {
                                    printf("La provincia no se encontro\n");
                                }
                            }
                            system("pause");
                            break;
                        case 3://Info
                            id=menuSucursalesInfo();
                            if(id==1)
                            {
                                int r=cantidadDeRegistros();
                                printf("Cantidad de sucursales existentes: %d\n",r);
                            }
                            if(id==2)
                            {
                                provincias();//id de las provincias
                            }
                            system("pause");
                            break;
                        case 4://Funciones para mostrar
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
                        mainEmpleados();
                    break;
                case 3:
                        mainMenuAdmin();
                    break;
                }

            }
            while(elecMenu!=0);
        }
        else if(modo==2)
        {
            mainMenuUsuario();

            system("pause");
        }
    }
    while(login!=0);
    return 0;
}
