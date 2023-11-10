#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "portada.h"

int main()
{
    stUsuario arUsuarios[80];
    system("Title= Carniceria");
    system("color 0a");
    int eleccion=0,menu=0,login=0,ok=0;
    do
    {
        login=LogIn();

        switch(login)
        {
        case 1:
            do
            {
                ok=iniciarSesion();
                if(ok==1)
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
                        printf("hola\n");
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

            }while(eleccion!=0);
        }
        break;
    }

}while(login!=0);

return 0;

}
