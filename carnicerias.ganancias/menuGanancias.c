#include "menuGanancias.h"

void menuGanancias(){
    int seleccion=99;
    nodoGananciasAnio* lista=inicLista();
    while(seleccion!=0){
        system("cls");
        printf("\t--SISTEMA GANANCIAS--\n\n");
        printf("1)Ver todas las gannacias\n");
        printf("2)Sumar ventas a archivo\n");
        printf("3)Ver ganancias de una sucursal\n");
        printf("4)Ver ganancias de un año\n");
        printf("5)Crear archivo ganancias\n");

        seleccion=getch()-'0';
        system("cls");
        switch(seleccion){
        case 1:
            lista=archivoToLista();
            mostrarTodasGanancias(lista);
            free(lista);
            break;
        case 2: ;
            cargarVariasVentas();
            break;
        case 3:
            lista=archivoToLista();
            int sucursal;
            printf("Ingrese num de sucursal: ");
            scanf("%d", &sucursal);
            mostrarGananciasSucursal(lista, sucursal);
            break;
        case 4:
            lista=archivoToLista();
            int anio;
            printf("Ingrese anio: ");
            scanf("%d", &anio);
            mostrarGananciasAnio(lista, anio);
            break;
        case 5:
            crearArchivoGananciasConVentas();
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



