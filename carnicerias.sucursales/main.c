#include <stdio.h>
#include <stdlib.h>
#include "listasSucusrsales.h"

const char archivoProvincia[]= {"archivoProvincia.dat"};
int cargarArchivo(int dim);
void recorrerYMostrar(provincia ar[],int validos,int pos);

int guardarArchivo(provincia ar[],int validos,int dim);
int main()
{
    provincia ar[30];
    int id=0,pos=0;
    int validos=0;
    validos=cargarArchivo(30);
    printf("listo\n");
    validos=guardarArchivo(ar,validos,30);
    printf("listo\n");


    printf("Ingrese el id del local que desee mostrar: ");
    scanf("%d",&id);
    pos=buscarPosProvincia(ar,id,validos);
    if(pos!=-1)
    {
        recorrerYMostrar(ar,validos,pos);
    }
    else
    {
        printf("La materia no se encontro\n");
    }

    return 0;
}
int cargarArchivo(int dim)
{
    provincia aux;
    int i=0;
    char salir='s';
    FILE* buffer= fopen(archivoProvincia,"ab");
    if(buffer)
    {
        while(salir=='s' && i<dim)
        {
            aux=cargarProvincia();
            fwrite(&aux,sizeof(provincia),1,buffer);
            printf("\nDesea seguir?: ");
            salir=getch(salir);
            printf("\n");
            i++;
        }

        fclose(buffer);
    }
    return i;
}
int guardarArchivo(provincia ar[],int validos,int dim)
{
    provincia aux;
    FILE* buffer= fopen(archivoProvincia,"rb");
    if(buffer)
    {
        while(fread(&aux,sizeof(provincia),1,buffer)&&(validos<dim))
        {
            validos=alta(ar,aux.idProvincia,validos);
        }
        fclose(buffer);
    }
    return validos;
}
void recorrerYMostrar(provincia ar[],int validos,int pos)
{
    printf("\nProvincia: %s:\n",ar[pos].NombreProvincia);
    printf("Id de la provincia: %d\n",ar[pos].idProvincia);
    printf("Locales existentes: \n\n\n");
    while(ar[pos].listaDelocales!=NULL)
    {
        printf("Ciudad del local: %s\n",ar[pos].listaDelocales->dato.localidad);
        printf("ID del local: %d\n",ar[pos].listaDelocales->dato.idDeLocal);
        printf("Direccion del local:%s\n",ar[pos].listaDelocales->dato.direccion);
        printf("\n");
        ar[pos].listaDelocales=ar[pos].listaDelocales->siguiente;
    }
}
