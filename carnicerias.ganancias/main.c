#include <stdio.h>
#include <stdlib.h>
#include "ganancias.h"

int main(){
    int seleccion=99;
    nodoGananciasAnio* lista=inicLista();
    while(seleccion!=0){
        system("cls");
        printf("\t--SISTEMA GANANCIAS--\n\n");
        printf("1)Ver archivo\n");
        printf("2)Sumar ventas a archivo\n");
        printf("3)Ver ganancias por sucursal\n");

        seleccion=getch()-'0';
        system("cls");
        switch(seleccion){
        case 1:
            lista=archivoToLista();
            mostrarTodasGanancias(lista);
            free(lista);
            break;
        case 2: ;
            StRegistroventas ventas=cargarVentas();
            sumarGananciasArchivo(ventas.venta, ventas.precioPorKilo, ventas.idSuc, ventas.fechaVenta);
            break;
        case 3:
            lista=archivoToLista();
            int sucursal;
            printf("Ingrese num de sucursal: ");
            scanf("%d", &sucursal);
            verGananciasSucursal(lista, sucursal);
            break;
        case 0:
            break;
            default:
                printf("Seleccion incorrecta.\n");
                break;
        }
        system("pause");
    }
    return 0;
}


