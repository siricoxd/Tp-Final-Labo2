#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int dibujo();
int main()
{

    system("Title= Carniceria");
    system("color 0a");
    int eleccion=0;
    do
    {
        eleccion=dibujo();
        switch(eleccion)
        {
        case 1:
            printf("hola\n");

            break;
        case 2:
            printf("hola\n");

            break;
        case 3:
            printf("hola\n");

            break;
        case 0:
            printf("Adios\n");

        }
        system("pause");

    }
    while(eleccion!=0);



    return 0;
}
int dibujo()
{
    system("cls");
    int seleccion=0;
    printf("\n\n\n");
    printf("\t\t\t ________________________________________________________________________\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|    __  __ ___ _  _ _   _    ___ ___ ___ _  _  ___ ___ ___  _   _       |\n");
    printf("\t\t\t|   |  \\/  | __| \\| || | |   | _ \\ _ \\_ _| \\| |/ __|_ _| _ \\/_\\ | |      |\n");
    printf("\t\t\t|   | |\\/| | __|    || | |   |  _/   /| || .` | (__ | ||  _/ _ \\| |__    |\n");
    printf("\t\t\t|   |_|  |_|___|_|\\_|\\___/   |_| |_|_\\___|_|\\_|\\___|___|_|/_/ \\_\\____|   |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                              1. AGREGAR                                |\n");
    printf("\t\t\t|                              2. MODIFICAR                              |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                              0. SALIR                                  |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|________________________________________________________________________|\n");


    printf("\n");
    scanf("%d",&seleccion);
    system("cls");
    return seleccion;
}
void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
