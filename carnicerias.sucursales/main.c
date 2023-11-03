#include <stdio.h>
#include <stdlib.h>
#include "listasSucusrsales.h"

void mostrarTodo(provincia ar[],int validos);
int main()
{
    provincia ar[30];
    int id=1,pos=0;
    int validos=0;

    validos=descargarArchivo(ar,validos,30);
    while(id!=0)
    {
        system("cls");


        printf("1. mostrar una sola provincia\n2. desactivar\n3. reactivar\n4. cargar\n5. mostrar todo\n");
        scanf("%d",&pos);
        switch(pos)
        {
        case 1:
            printf("Ingrese el id del provincia que desee mostrar: ");
            scanf("%d",&id);
            pos=buscarPosProvincia(ar,id,validos);
            if(pos!=-1)
            {
                recorrerYMostrar(ar,validos,pos);
            }
            else
            {
                printf("La provincia no se encontro\n");
            }
            break;
        case 2:
            printf("Ingrese el id del provincia que desee descativar: ");
            scanf("%d",&id);
            pos=buscarPosProvincia(ar,id,validos);
            if(pos!=-1)
            {
                printf("Ingrese el id del local que desee activar: ");
                scanf("%d",&id);
                descativarLocal(ar,id,pos);
                mostrarTodo(ar,validos);
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
                printf("Ingrese el id del local que desee activar: ");
                scanf("%d",&id);
                activarLocal(ar,id,pos);
                mostrarTodo(ar,validos);
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
        }
        system("pause");

    }


    return 0;
}

void mostrarTodo(provincia ar[],int validos)
{
    int i=0;

    printf("--------------------------------------------------------------------------------\n");
    while(i<validos)
    {
        if(ar[i].activo!=324)
        {
            nodoLocales*seg=ar[i].listaDelocales;
            printf("\nProvincia..............: %s\n",ar[i].NombreProvincia);
            printf("ID de la provincia.....: %d\n",ar[i].idProvincia);
            printf("Activo.................: %d\n",ar[i].activo);
            printf("Locales existentes \n\n");
            while(seg!=NULL)
            {

                if(seg->dato.activo!=10)
                {
                    printf("\t----------------------------------------------------\n");
                    printf("\t|Ciudad del local................: %s\n",seg->dato.localidad);
                    printf("\t|ID del local....................: %d\n",seg->dato.idDeLocal);
                    printf("\t|Direccion del local.............: %s\n",seg->dato.direccion);
                    printf("\t|Activo..........................: %d\n",seg->dato.activo);
                    printf("\t----------------------------------------------------\n");

                }
                printf("\n");
                seg=seg->siguiente;

            }
            printf("--------------------------------------------------------------------------------\n");
        }

        i++;
    }
}
