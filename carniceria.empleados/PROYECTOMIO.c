#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proyectomio.h"

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
    printf("\n--------------------------\n");

    printf("Nombre y apellido: ");
    puts(a.nombreApe);
    printf("DNI: %i\n", a.dni);
    printf("Id provincia: %i\n", a.idProvincia);
    printf("Id sucursal: %i\n", a.idSucursal);
    printf("Rango :%i\n",a.rango);
    printf("Sueldo: $ %i\n", a.sueldo);
    printf("Horas Extra: %i\n", a.horasExtra);
    if(a.baja==0)
    {
        printf("Se encuentra dado de baja\n");
    }
    else if(a.baja==1)
    {
        printf("Se encuentra activo\n");
    }

    printf("\n--------------------------\n");
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

nodoLista* crearNodoLista(int idSucursal)
{

    nodoLista* aux=(nodoLista*)malloc(sizeof(nodoLista));

    aux->idSucursal=idSucursal;
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
            mostrarUnTrabajador(arbol->dato);
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
            mostrarUnTrabajador(arbol->dato);
        }
        inorderBajas(arbol->der);
    }
}

void inorderRango(nodoArbol * arbol, int rango)
{
    if(arbol != NULL)
    {
        inorderRango(arbol->izq, rango);
        if(arbol->dato.rango==rango) // si esta de baja
        {
            mostrarUnTrabajador(arbol->dato);
        }
        inorderRango(arbol->der, rango);
    }
}


nodoArbol * buscarPorDni(nodoArbol * arbol, int dni, int rango)
{
    nodoArbol * rta=NULL;
    if(arbol!=NULL)
    {
        printf("%i\t", arbol->dato.dni);
        if( (dni == arbol->dato.dni) && (rango==arbol->dato.rango) )
        {
            rta=arbol;
            printf("Dato dado de baja: %i", rta->dato.dni);
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

nodoLista* alta(nodoLista* lista, trabajador dato, int idSucursal)
{

    nodoArbol* nuevo = crearNodoArbol(dato);
    nodoLista* encontrado=buscarSucursal(lista, idSucursal);

    if(encontrado==NULL)
    {
        nodoLista* aux = crearNodoLista(idSucursal);
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
            lista=alta(lista, a, a.idSucursal);

        }

        fclose(archi);
    }

    return lista;
}



void mostrarLDA(nodoLista* lista)
{

    while(lista != NULL)
    {
        printf("Id sucursal: %i\n", lista->idSucursal);
        printf("\n--------------------------------\n");
        inorder(lista->arbol);
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
    printf("Trabajadores dados de baja: \n");

    while(lista != NULL)
    {
        printf("Id sucursal: %i\n", lista->idSucursal);
        printf("\n--------------------------------\n");
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
        lista=alta(lista,a,a.idSucursal);
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



