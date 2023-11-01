#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


int dibujo();
int main()
{

    system("Title= Carniceria");
    system("color 0a");
    dibujo();


    return 0;
}

int dibujo()
{
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
    printf("\t\t\t|                              3. ELIMINAR                               |\n");
    printf("\t\t\t|                              4. SALIR                                  |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|________________________________________________________________________|\n");


    printf("\n");
    seleccion=getch(seleccion);
    system("cls");
;    return seleccion;
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
