#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proyecto.h"
#include "libreriaEmpleados.h"


//Libreria archivo
trabajador cargarUnTrabajador()
{

    trabajador a;

    printf("Ingresa el id de la provincia: \n");
    fflush(stdin);
    scanf("%i", &a.idProvincia);

    printf("Ingresa el id de la sucursal: \n");
    fflush(stdin);
    scanf("%i", &a.idSucursal);

    printf("Ingresa el nombre y apellido: \n");
    fflush(stdin);
    gets(a.nombreApe);

    printf("Ingresa el dni: \n");
    fflush(stdin);
    scanf("%i", &a.dni);


    printf("Ingresa el rango: \n");
    fflush(stdin);
    scanf("%i", &a.rango);

    printf("Ingresa el sueldo: \n");
    fflush(stdin);
    scanf("%i", &a.sueldo);

    printf("Ingresa las horas extras: \n");
    fflush(stdin);
    scanf("%i", &a.horasExtra);

    a.baja=1;
    a.bajaSucursal=1;
    a.bajaProvincia=1;

    return a;

}

void cargarArchivo(char archivoTrabajador[])
{

    FILE* archi=fopen(archivoTrabajador, "ab");

    trabajador a;
    char control='s';

    if(archi)
    {
        while(control=='s')
        {
            a=cargarUnTrabajador();
            fwrite(&a, sizeof(trabajador), 1, archi);

            printf("Seguir?");
            fflush(stdin);
            scanf("%c", &control);
        }

        fclose(archi);
    }

}

void mostrarUnTrabajador(trabajador a)
{
    int bono;
    printf("\n-  -  -  -  -  -  -  -\n");

    printf("Nombre y apellido: ");
    puts(a.nombreApe);
    printf("DNI: %i\n", a.dni);
    printf("Id provincia: %i\n", a.idProvincia);
    printf("Id sucursal: %i\n", a.idSucursal);
    printf("Rango :%i\n",a.rango);

    if(a.horasExtra > 0)
    {
        bono=bonoXtrabajadorArbol(a);
        printf("Sueldo + bono : $ %i\n", a.sueldo + bono);
    }
    else
    {
        printf("Sueldo: $ %i\n", a.sueldo);
    }

    printf("Horas Extra: %i\n", a.horasExtra);
    if(a.baja==0)
    {
        printf("Se encuentra dado de baja\n");
    }
    else if(a.baja==1)
    {
        printf("Se encuentra activo\n");
    }

    if(a.bajaSucursal==0)
    {
        printf("Sucursal dada de baja\n");
    }
    else if(a.bajaSucursal==1)
    {
        printf("SUCURSAL activa\n");
    }
    if(a.bajaProvincia==0)
    {
        printf("Provincia dada de baja\n");
    }
    else if(a.bajaProvincia==1)
    {
        printf("Provincia activa\n");
    }


    printf("\n-  -  -  -  -  -  -  - \n");
}

void mostrarUnTrabajador2(trabajador a)
{
    int bono;
    printf("\n-  -  -  -  -  -  -  -\n");

    printf("Nombre y apellido: ");
    puts(a.nombreApe);
    printf("DNI: %i\n", a.dni);
    //printf("Id provincia: %i\n", a.idProvincia);
    //printf("Id sucursal: %i\n", a.idSucursal);
    printf("Rango :%i\n",a.rango);

    if(a.horasExtra > 0)
    {
        bono=bonoXtrabajadorArbol(a);
        printf("Sueldo + bono : $ %i\n", a.sueldo + bono);
    }
    else
    {
        printf("Sueldo: $ %i\n", a.sueldo);
    }

    printf("Horas Extra: %i\n", a.horasExtra);


    printf("\n-  -  -  -  -  -  -  - \n");
}


void mostrarArchivo(char archivo[])
{

    printf("ARCHIVO: \n");
    FILE* archi=fopen(archivo, "rb");
    trabajador a;
    if(archi)
    {
        while(fread(&a, sizeof(trabajador), 1, archi)>0)
        {
            mostrarUnTrabajador(a);

        }
        fclose(archi);
    }

}
///Libreria listas

nodoLista* iniclista()
{
    return NULL;
}

nodoLista* crearNodoLista(int idSucursal, int bajaSucursal,int idProvincia, int bajaProvincia)
{

    nodoLista* aux=(nodoLista*)malloc(sizeof(nodoLista));

    aux->idSucursal=idSucursal;
    aux->idProvincia=idProvincia;
    aux->bajaSucursal=bajaSucursal;
    aux->bajaProvincia=bajaProvincia;
    aux->arbol=inicarbol();
    aux->siguiente=NULL;

    return aux;
}

nodoLista* agregarAlPpio(nodoLista* lista, nodoLista* nuevo)
{

    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nuevo->siguiente=lista;
        lista=nuevo;

    }
    return lista;
}

nodoLista* agregarEnOrden(nodoLista* lista, nodoLista * nuevoNodo)
{

    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {


        if(nuevoNodo->idSucursal < lista->idSucursal)
        {
            lista = agregarAlPpio(lista, nuevoNodo);
        }
        else
        {

            nodoLista * ante = lista;
            nodoLista * seg = lista->siguiente;
            while((seg != NULL) && (nuevoNodo->idSucursal > seg->idSucursal))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            nuevoNodo->siguiente = seg;
            ante->siguiente = nuevoNodo;
        }
    }
    return lista;
}

///Libreria arboles
nodoArbol* inicarbol()
{
    return NULL;
}
nodoArbol* crearNodoArbol(trabajador a)
{

    nodoArbol* aux=malloc(sizeof(nodoArbol));

    aux->dato=a;
    aux->izq=NULL;
    aux->der=NULL;

    return aux;
}

nodoArbol* insertar(nodoArbol* arbol, nodoArbol* nuevo)
{

    if(arbol==NULL)
    {
        arbol=nuevo;
    }
    else
    {
        if(arbol->dato.rango > nuevo->dato.rango)
        {
            arbol->izq=insertar(arbol->izq, nuevo);
        }
        else
        {
            arbol->der=insertar(arbol->der, nuevo);
        }
    }
    return arbol;
}

void inorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        inorder(arbol->izq);
        if(arbol->dato.baja==1) // si esta activo lo muestra sino no:
        {
            mostrarUnTrabajador2(arbol->dato);
        }
        inorder(arbol->der);
    }
}

void inorderBajas(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        inorderBajas(arbol->izq);
        if(arbol->dato.baja==0) // si esta de baja
        {
            mostrarUnTrabajador2(arbol->dato);
        }
        inorderBajas(arbol->der);
    }
}

void inorderRango(nodoArbol * arbol, int rango)
{
    if(arbol != NULL)
    {
        inorderRango(arbol->izq, rango);
        if(arbol->dato.rango==rango)
        {
            mostrarUnTrabajador2(arbol->dato);
        }
        inorderRango(arbol->der, rango);
    }
}


nodoArbol * buscarPorDni(nodoArbol * arbol, int dni, int rango)
{
    nodoArbol * rta=NULL;
    if(arbol!=NULL)
    {

        if( (dni == arbol->dato.dni) && (rango==arbol->dato.rango) )
        {
            rta=arbol;

        }

        else if(rango>=arbol->dato.rango)
            rta = buscarPorDni(arbol->der, dni, rango);
        else
            rta = buscarPorDni(arbol->izq, dni,rango);
    }
    return rta;
}


nodoArbol * buscarPorRango(nodoArbol * arbol, int rango)
{
    nodoArbol * rta=NULL;
    if(arbol!=NULL)
    {
        if(rango == arbol->dato.rango)
            rta = arbol;
        else if(rango>=arbol->dato.rango)
            rta = buscarPorRango(arbol->der, rango);
        else
            rta = buscarPorRango(arbol->izq,rango);
    }
    return rta;
}
/// Libreria LDA

nodoLista* buscarSucursal(nodoLista* lista, int sucursal)
{

    nodoLista *seg = lista;

    while ((seg != NULL) && (seg->idSucursal != sucursal))
    {
        seg=seg->siguiente;
    }

    return seg;
}

nodoLista* buscarProvincia(nodoLista* lista, int provincia)
{

    nodoLista *seg = lista;

    while ((seg != NULL) && (seg->idProvincia != provincia))
    {
        seg=seg->siguiente;
    }

    return seg;
}

nodoLista* alta(nodoLista* lista, trabajador dato, int idSucursal,int bajaSucursal,int idProvincia, int bajaProvincia)
{

    nodoArbol* nuevo = crearNodoArbol(dato);
    nodoLista* encontrado=buscarSucursal(lista, idSucursal);

    if(encontrado==NULL)
    {
        nodoLista* aux = crearNodoLista(idSucursal,bajaSucursal,idProvincia, bajaProvincia);
        lista=agregarEnOrden(lista, aux); //o al ppio
        aux->arbol=insertar(aux->arbol, nuevo);

    }

    else
    {
        encontrado->arbol=insertar(encontrado->arbol, nuevo);

    }
    return lista;
}


nodoLista* pasarDelArchivoToLDA(char archivo[], nodoLista* lista)
{

    FILE* archi=fopen(archivo, "rb");

    if(archi)
    {
        trabajador a;
        while(fread(&a, sizeof(trabajador), 1, archi)>0)
        {
            lista=alta(lista, a, a.idSucursal,a.bajaSucursal,a.idProvincia,a.bajaProvincia);

        }

        fclose(archi);
    }

    return lista;
}



void mostrarLDA(nodoLista* lista)
{
printf("\n\n\n\n");
    printf("\t\t\t\t\tLISTA DE TRABAJADORES: \n\n\n\n");
    while(lista != NULL)
    {
        if(lista->bajaSucursal==1 && lista->bajaProvincia==1){
             printf("\n\n\n\n\n\n");
      printf("\t\t\t\t\t | Id sucursal: %i    |\n", lista->idSucursal);
     // printf("\t\t\t\t\t |  baja sucursal: %i |\n", lista->bajaSucursal);
      printf("\t\t\t\t\t |  Id provincia: %i  |\n", lista->idProvincia);
      //printf("\t\t\t\t\t |  baja provincia: %i|\n", lista->bajaProvincia);
      printf("\t\t\t\n-----------------------------------------------------------------------------------------------------------------------\n");
        inorder(lista->arbol);
        }



        lista=lista->siguiente;

    }

}

nodoLista * buscarNodo(nodoLista * lista,  int idSucursal)
{

    nodoLista * seg;
    seg = lista;
    while ((seg != NULL) && ( seg->idSucursal!=idSucursal))
    {
        seg=seg->siguiente;
    }

    return seg;
}

///Dar de baja y de alta.

void mostrarBajas(nodoLista* lista)
{
    printf("\n\n\n\n");
    printf("\t\t\t\t\tTrabajadores dados de baja: \n\n\n\n");

    while(lista != NULL)
    {
        printf("\t\t\t\t\tId sucursal: %i\n", lista->idSucursal);
        printf("\t\t\t\n-----------------------------------------------------------------------------------------------------------------------\n");
        inorderBajas(lista->arbol);
        lista=lista->siguiente;

    }

}

void darDeBaja(char archivo[], nodoLista* aux, int dni, int rango)
{

    int flag=0;

    FILE* archi=fopen(archivo, "r+b");

    if(archi)
    {

        trabajador a;


        nodoArbol* arbol;
        while(flag==0 && fread(&a, sizeof(trabajador),1,archi)>0)
        {
            if(aux->idSucursal==a.idSucursal)
            {
                arbol=buscarPorDni(aux->arbol, dni, rango);
                if(arbol!=NULL)
                {



                    if(a.dni==dni)
                    {
                        arbol->dato.baja=0;
                        a.baja=0;
                        fseek(archi, (-1)*sizeof(trabajador), SEEK_CUR); // Retrocede al inicio del registro
                        fwrite(&a, sizeof(trabajador), 1, archi); // Escribe el registro modificado


                        flag=1;

                    }


                }
            }


        }

        fclose(archi);
    }



}


void darDeAlta(char archivo[], nodoLista* aux, int dni, int rango)
{

    int flag=0;

    FILE* archi=fopen(archivo, "r+b");

    if(archi)
    {

        trabajador a;


        nodoArbol* arbol;
        while(flag==0 && fread(&a, sizeof(trabajador),1,archi)>0)
        {
            if(aux->idSucursal==a.idSucursal)
            {
                arbol=buscarPorDni(aux->arbol, dni, rango);
                if(arbol!=NULL)
                {



                    if(a.dni==dni)
                    {
                        arbol->dato.baja=1;
                        a.baja=1;
                        fseek(archi, (-1)*sizeof(trabajador), SEEK_CUR); // Retrocede al inicio del registro
                        fwrite(&a, sizeof(trabajador), 1, archi); // Escribe el registro modificado


                        flag=1;

                    }


                }
            }


        }

        fclose(archi);
    }



}

///


void agregarTrabajadores(char archivo[], nodoLista* lista)
{

    FILE* archi=fopen(archivo, "ab");

    trabajador a;

    if(archi)
    {
        a=cargarUnTrabajador();
        lista=alta(lista,a,a.idSucursal,a.bajaSucursal,a.idProvincia,a.bajaProvincia);
        fwrite(&a,sizeof(trabajador),1,archi);

        fclose(archi);
    }


}

///

void mostrarTrabajadoresDeUnaSucursal(nodoLista* lista,int idSucursal)
{

    nodoLista* aux=buscarSucursal(lista,idSucursal);

    if(aux==NULL)
    {
        printf("No se encontro la sucursal\n");
    }
    else
    {
        printf("Id sucursal: %i\n", aux->idSucursal);
        printf("\n--------------------------------\n");
        inorder(aux->arbol);
    }



}

void mostrarTrabajadoresDeUnRango(nodoLista* lista, int rango)
{
    printf("Trabajadores rango %i\n", rango);
    while(lista!=NULL)
    {
        printf("Id sucursal: %i\n", lista->idSucursal);
        printf("\n--------------------------------\n");
        inorderRango(lista->arbol, rango);
        lista=lista->siguiente;
    }



}

///

void cambiarSueldo(char archivo[], nodoLista* aux, int dni, int rango)
{

    int flag=0;

    FILE* archi=fopen(archivo, "r+b");

    if(archi)
    {

        trabajador a;


        nodoArbol* arbol;
        while(flag==0 && fread(&a, sizeof(trabajador),1,archi)>0)
        {
            if(aux->idSucursal==a.idSucursal)
            {
                arbol=buscarPorDni(aux->arbol, dni, rango);
                if(arbol!=NULL)
                {



                    if(a.dni==dni)
                    {
                        int sueldo;
                        printf("Ingrese el sueldo: \n");
                        fflush(stdin);
                        scanf("%i", &sueldo);
                        arbol->dato.sueldo=sueldo;
                        a.sueldo=sueldo;
                        fseek(archi, (-1)*sizeof(trabajador), SEEK_CUR); // Retrocede al inicio del registro
                        fwrite(&a, sizeof(trabajador), 1, archi); // Escribe el registro modificado


                        flag=1;

                    }


                }
            }


        }

        fclose(archi);
    }



}
//dar de baja una sucursal

void inorderBajaSucursal(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        inorderBajaSucursal(arbol->izq);

        arbol->dato.bajaSucursal=0;
        arbol->dato.baja=0;

        inorderBajaSucursal(arbol->der);
    }
}

void darDeBajaUnaSucursal(char archivo[], nodoLista* aux)
{

    FILE* archi=fopen(archivo, "r+b");



    if(archi)
    {

        trabajador a;


        while(fread(&a, sizeof(trabajador),1,archi)>0)
        {
            if(aux->idSucursal==a.idSucursal)
            {

                a.bajaSucursal=0;
                a.baja=0;
                fseek(archi, (-1)*sizeof(trabajador), SEEK_CUR); // Retrocede al inicio del registro
                fwrite(&a, sizeof(trabajador), 1, archi); // Escribe el registro modificado
                fseek(archi, 0, SEEK_CUR);



            }


        }
        aux->bajaSucursal=0;
        inorderBajaSucursal(aux->arbol);
        fclose(archi);

    }



}

//dar de alta una sucursal


void inorderAltaSucursal(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        inorderAltaSucursal(arbol->izq);

        arbol->dato.bajaSucursal=1;
        //arbol->dato.baja=1;

        inorderAltaSucursal(arbol->der);
    }
}

void darDeAltaUnaSucursal(char archivo[], nodoLista* aux)
{

    FILE* archi=fopen(archivo, "r+b");



    if(archi)
    {

        trabajador a;


        while(fread(&a, sizeof(trabajador),1,archi)>0)
        {
            if(aux->idSucursal==a.idSucursal)
            {

                a.bajaSucursal=1;
                //a.baja=1;
                fseek(archi, (-1)*sizeof(trabajador), SEEK_CUR); // Retrocede al inicio del registro
                fwrite(&a, sizeof(trabajador), 1, archi); // Escribe el registro modificado
                fseek(archi, 0, SEEK_CUR);



            }


        }
        aux->bajaSucursal=1;
        inorderAltaSucursal(aux->arbol);
        fclose(archi);

    }



}

//dar de baja una provincia

void inorderBajaProvincia(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        inorderBajaProvincia(arbol->izq);

        arbol->dato.bajaProvincia=0;
        arbol->dato.bajaSucursal=0;
        arbol->dato.baja=0;

        inorderBajaProvincia(arbol->der);
    }
}

void darDeBajaUnaProvincia(char archivo[], nodoLista* aux, int idProvincia)
{

    FILE* archi=fopen(archivo, "r+b");



    if(archi)
    {

        trabajador a;


        while(fread(&a, sizeof(trabajador),1,archi)>0)
        {
            if(aux->idProvincia==a.idProvincia)
            {
                a.bajaProvincia=0;
                a.bajaSucursal=0;
                a.baja=0;
                fseek(archi, (-1)*sizeof(trabajador), SEEK_CUR); // Retrocede al inicio del registro
                fwrite(&a, sizeof(trabajador), 1, archi); // Escribe el registro modificado
                fseek(archi, 0, SEEK_CUR);



            }


        }

        while(aux!=NULL)
        {
            if(aux->idProvincia==idProvincia)
            {
                aux->bajaProvincia=0;
                aux->bajaSucursal=0;
                inorderBajaProvincia(aux->arbol);
            }


            aux=aux->siguiente;
        }

        fclose(archi);

    }



}

//dar de alta una provincia

void inorderAltaProvincia(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        inorderAltaProvincia(arbol->izq);

        arbol->dato.bajaProvincia=1;
        //arbol->dato.bajaSucursal=1;
        //arbol->dato.baja=1;

        inorderAltaProvincia(arbol->der);
    }
}

void darDeAltaUnaProvincia(char archivo[], nodoLista* aux, int idProvincia)
{

    FILE* archi=fopen(archivo, "r+b");



    if(archi)
    {

        trabajador a;


        while(fread(&a, sizeof(trabajador),1,archi)>0)
        {
            if(aux->idProvincia==a.idProvincia)
            {
                a.bajaProvincia=1;
                //a.bajaSucursal=1;
                //a.baja=1;
                fseek(archi, (-1)*sizeof(trabajador), SEEK_CUR); // Retrocede al inicio del registro
                fwrite(&a, sizeof(trabajador), 1, archi); // Escribe el registro modificado
                fseek(archi, 0, SEEK_CUR);



            }


        }

        while(aux!=NULL)
        {
            if(aux->idProvincia==idProvincia)
            {
                aux->bajaProvincia=1;
                //aux->bajaSucursal=1;
                inorderAltaProvincia(aux->arbol);
            }


            aux=aux->siguiente;
        }

        fclose(archi);

    }



}

///funciones case 15 y 16

nodoArbol * buscarPorDni2(nodoArbol * arbol, int dni, int rango)
{
    nodoArbol * rta=NULL;
    if(arbol!=NULL)
    {
        // printf("%i\t", arbol->dato.dni);
        if( (dni == arbol->dato.dni) && (rango==arbol->dato.rango) )
        {
            rta=arbol;
            //printf("Dato dado de baja: %i", rta->dato.dni);
        }

        else if(rango>=arbol->dato.rango)
            rta = buscarPorDni2(arbol->der, dni, rango);
        else
            rta = buscarPorDni2(arbol->izq, dni,rango);
    }
    return rta;
}

void modificarHrsExtrasEnArchivo(char archivo[], nodoLista* aux, int dni, int rango)
{
    int flag=0;
    int horasNuevas;

    FILE* archi=fopen(archivo, "r+b");

    if(archi)
    {
        trabajador a;
        nodoArbol* arbol;

        while(flag==0 && fread(&a, sizeof(trabajador),1,archi)>0)
        {
            if(aux->idSucursal==a.idSucursal)
            {
                arbol=buscarPorDni2(aux->arbol, dni, rango);
                if(arbol!=NULL)
                {
                    if(a.dni==dni)
                    {
                        printf("\nIngrese las horas extras que desea modificar: ");
                        scanf("%i",&horasNuevas);

                        arbol->dato.horasExtra =horasNuevas;
                        a.horasExtra=horasNuevas;

                        fseek(archi, (-1)*sizeof(trabajador), SEEK_CUR); // Retrocede al inicio del registro
                        fwrite(&a, sizeof(trabajador), 1, archi); // Escribe el registro modificado

                        printf(" \nLas horas extras fueron cargadas y guardadas exitosamente :)\n");
                        flag=1;
                    }

                }
            }
        }
        fclose(archi);
    }
}
void modificarHorasExtrasTrabajadores(nodoLista*lista,char nombreArchivo[])
{
    char seguir='s';
    int dni;
    int horasExtras;
    int rango;
    nodoArbol*encontrado;

    if(lista != NULL)
    {
        while(seguir == 's')
        {
            printf("\nIngrese dni: ");
            scanf("%i", &dni);

            printf("\nIngrese rango: ");
            scanf("%i",&rango);

            encontrado=buscarPorDni2(lista->arbol,dni,rango);

            if(encontrado== NULL)
            {
                printf("\nDNI INVALIDO \n");
            }
            else
            {
                modificarHrsExtrasEnArchivo(nombreArchivo,lista,dni,rango);
            }

            printf("\nDesea continuar? s/n \n");
            fflush(stdin);
            scanf("%c", &seguir);

        }
    }
    else
    {
        printf("no hay empleados cargados \n");
    }
}
void guardarHrsExtrasEnArchivo(char archivo[], nodoLista* aux, int dni, int rango, int hrsExtras)
{
    int flag=0;

    FILE* archi=fopen(archivo, "r+b");

    if(archi)
    {
        trabajador a;
        nodoArbol* arbol;

        while(flag==0 && fread(&a, sizeof(trabajador),1,archi)>0)
        {
            if(aux->idSucursal==a.idSucursal)
            {
                arbol=buscarPorDni2(aux->arbol, dni, rango);
                if(arbol!=NULL)
                {
                    if(a.dni==dni)
                    {
                        arbol->dato.horasExtra +=hrsExtras;
                        a.horasExtra+=hrsExtras;

                        fseek(archi, (-1)*sizeof(trabajador), SEEK_CUR); // Retrocede al inicio del registro
                        fwrite(&a, sizeof(trabajador), 1, archi); // Escribe el registro modificado

                        printf(" \nLas horas extras fueron cargadas y guardadas exitosamente :)\n");
                        flag=1;
                    }

                }
            }
        }
        fclose(archi);
    }
}

void cargarHorasExtrasTrabajadores(nodoLista*lista,char nombreArchivo[])
{
    char seguir='s';
    int dni;
    int horasExtras;
    int rango;
    nodoArbol*encontrado;

    if(lista != NULL)
    {
        while(seguir == 's')
        {
            printf("\nIngrese dni: ");
            scanf("%i", &dni);

            printf("\nIngrese rango: ");
            scanf("%i",&rango);

            encontrado=buscarPorDni2(lista->arbol,dni,rango);

            if(encontrado== NULL)
            {
                printf("\nDNI INVALIDO \n");
            }
            else
            {
                printf("\nIngrese horas extras: ");
                scanf("%i", &horasExtras);
                guardarHrsExtrasEnArchivo(nombreArchivo,lista,dni,rango,horasExtras);
            }

            printf("\nDesea continuar? s/n \n");
            fflush(stdin);
            scanf("%c", &seguir);

        }
    }
    else
    {
        printf("no hay empleados cargados \n");
    }
}
//////////////////FUNCIONES BONO/////////////
int bonoXtrabajadorArbol(trabajador a)
{
    int bonoPorHoraExtra = 500;
    int bono = -1;

    bono =a.horasExtra * bonoPorHoraExtra;

    return bono;
}



