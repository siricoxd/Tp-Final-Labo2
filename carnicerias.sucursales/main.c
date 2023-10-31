#include <stdio.h>
#include <stdlib.h>
#include "listasSucusrsales.h"

int main()
{

    return 0;
}
provincia cargarProvincia()
{
    provincia aux;
    printf("Ingrese la provincia: ");
    fflush(stdin);
    gets(aux.NombreProvincia);
    printf("Ingrese el id de la provincia: ");
    scanf("%d",&aux.idProvincia);
    return aux;
}
locales cargarLocales()
{
    locales aux;
    printf("Ingrese el nombre de la ciudad: ");
    fflush(stdin);
    gets(aux.localidad);
    printf("Ingrese la direccion del local: ");
    fflush(stdin);
    gets(aux.direccion);

}
