#include "menuGanancias.h"

void menuGanancias(){
    int seleccion=99;
    nodoGananciasAnio* lista=inicLista();
    while(seleccion!=0){
        int flag=0;
        system("cls");
        printf("\n\n\n");
        printf("\t\t ______________________________________________________________________________________\n");
        printf("\t\t|                                                                                      |\n");
        printf("\t\t|                                                                                      |\n");
        printf("\t\t|    ## ##     ##     ###  ##    ##     ###  ##   ## ##     ####     ##      ## ##     |\n");
        printf("\t\t|   ##   ##     ##      ## ##     ##      ## ##  ##   ##     ##       ##    ##   ##    |\n");
        printf("\t\t|   ##        ## ##    # ## #   ## ##    # ## #  ##          ##     ## ##   ####       |\n");
        printf("\t\t|   ##  ###   ##  ##   ## ##    ##  ##   ## ##   ##          ##     ##  ##   #####     |\n");
        printf("\t\t|   ##   ##   ## ###   ##  ##   ## ###   ##  ##  ##          ##     ## ###      ###    |\n");
        printf("\t\t|   ##   ##   ##  ##   ##  ##   ##  ##   ##  ##  ##   ##     ##     ##  ##  ##   ##    |\n");
        printf("\t\t|    ## ##   ###  ##  ###  ##  ###  ##  ###  ##   ## ##     ####   ###  ##   ## ##     |\n");
        printf("\t\t|                                                                                      |\n");
        printf("\t\t|                             1.Ver todas las ganacias                                 |\n");
        printf("\t\t|                             2.Ver ganancias de una sucursal                          |\n");
        printf("\t\t|                             2.Ver ganancias de un año                                |\n");
        printf("\t\t|                             0.Volver                                                 |\n");
        printf("\t\t|                                                                                      |\n");
        printf("\t\t|_____________________________________________________________________________________ |\n");
        printf("\n");
        seleccion=getch()-'0';
        system("cls");
        switch(seleccion){
        case 1:
            lista=archivoToLista();
            mostrarTodasGanancias(lista);
            free(lista);
            break;
        case 2:
            lista=archivoToLista();
            int sucursal;
            printf("Ingrese numero de sucursal: ");
            scanf("%d", &sucursal);
            mostrarGananciasSucursal(lista, sucursal);
            break;
        case 3:
            lista=archivoToLista();
            int anio;
            printf("Ingrese anio: ");
            scanf("%d", &anio);
            mostrarGananciasAnio(lista, anio);
            break;
        case 0:
            break;
            default:
                printf("Seleccion incorrecta.\n");
                break;
        }
        system("pause");
    }
}



