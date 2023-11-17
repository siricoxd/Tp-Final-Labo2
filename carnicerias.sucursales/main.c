#include <stdio.h>
#include <stdlib.h>
#include "listasSucusrsales.h"

int main()
{
    provincia ar[30];
    int id=1,pos=0;
    int validos;

    while(id!=0)
    {
        system("cls");
        validos=0;
        validos=descargarArchivo(ar,validos,30);
        int r=cantidadDeRegistros();
        printf("Cantidad de sucursales existentes: %d\n",r);
        printf("1. mostrar una sola provincia\n2. desactivar\n3. reactivar\n4. cargar\n5. mostrar todo\n6. mostrar id\n\n");

        scanf("%d",&pos);
        switch(pos)
        {
        case 1:
            printf("Ingrese el id del provincia que desee mostrar: ");
            scanf("%d",&id);
            pos=buscarPosProvincia(ar,id,validos);
            if(pos!=-1)
            {
                mostrarUnaProvincia(ar[pos]);
            }
            else
            {
                printf("La provincia no se encontro\n");
            }
            break;
        case 2:
            printf("Ingrese el id del provincia que desee desactivar: ");
            scanf("%d",&id);
            pos=buscarPosProvincia(ar,id,validos);
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
            break;
        case 3:
            printf("Ingrese el id del provincia que desee activar: ");
            scanf("%d",&id);
            pos=buscarPosProvincia(ar,id,validos);
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
            break;
        case 4:
            validos=cargarArchivo(30);
            break;
        case 5:
            mostrarTodo(ar,validos);
            break;
        case 6:
            provincias();
            break;


            break;
        }
        system("pause");

    }


    return 0;
}
