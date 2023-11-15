#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "portada.h"

int main()
{
    system("Title= Frigorifico");
    system("color 0a");
    int eleccion=0,menu=0,login=0,modo=0;
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
                            system("pause");
                            break;
                        case 2:
                            system("pause");
                            break;
                        case 0:
                            break;
                        }

                    }
                    while(menu!=0);
                    break;
                case 2:
                    registrarse();
                    system("pause");

                    break;
                case 3:
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


