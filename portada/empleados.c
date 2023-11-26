#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuEmpleados.h"
#include "empleados.h"


//Libreria archivo
trabajador cargarUnTrabajador(int idSucursal, nodoLista* lista)
{
    nodoArbol* repetido;

    trabajador a;


    a.idSucursal=idSucursal;

    printf("Ingresa el nombre y apellido: \n");
    fflush(stdin);
    gets(a.nombreApe);

    printf("Ingresa el dni: \n");
    fflush(stdin);
    scanf("%i", &a.dni);

    repetido=buscarPorDniPrincipal(lista,a.dni);

    while(repetido!=NULL)
    {
        printf("Este dni ya existe\n");
        printf("Ingresa el dni: \n");
        fflush(stdin);
        scanf("%i", &a.dni);

        repetido=buscarPorDniPrincipal(lista,a.dni);

    }


    printf("Ingresa el rango(1, 2 o 3): \n");
    fflush(stdin);
    scanf("%i", &a.rango);

    while(a.rango!= 1 && a.rango!=2 && a.rango!=3)
    {
        printf("Ingresa el rango(1, 2 o 3): \n");
        fflush(stdin);
        scanf("%i", &a.rango);

    }

    printf("Ingresa el sueldo: \n");
    fflush(stdin);
    scanf("%i", &a.sueldo);

    printf("Ingresa las horas extras: \n");
    fflush(stdin);
    scanf("%i", &a.horasExtra);

    a.baja=1;
    a.bajaSucursal=1;

    return a;

}

void cargarArchivoEmpleados(char archivoTrabajador[], int idSucursal,nodoLista* lista)
{

    FILE* archi=fopen(archivoTrabajador, "ab");

    trabajador a;
    char control='s';

    if(archi)
    {
        while(control=='s')
        {
            a=cargarUnTrabajador(idSucursal, lista);
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


    printf("\n-  -  -  -  -  -  -  - \n");
}

void mostrarUnTrabajador2(trabajador a)
{
    int bono;
    printf("\n-  -  -  -  -  -  -  -\n");

    printf("Nombre y apellido: ");
    puts(a.nombreApe);
    printf("DNI: %i\n", a.dni);
    printf("Rango :%i\n",a.rango);
    if(a.rango==1)
    {
        printf("Encargado\n");
    }
    else if(a.rango==2)
    {
        printf("Carnicero\n");
    }
    else if(a.rango==3)
    {
        printf("Personal Limpieza\n");
    }

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

nodoLista* crearNodoLista(int idSucursal, int bajaSucursal)
{

    nodoLista* aux=(nodoLista*)malloc(sizeof(nodoLista));

    aux->idSucursal=idSucursal;
    aux->bajaSucursal=bajaSucursal;
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
        if(arbol->dato.rango==rango && arbol->dato.baja==1)
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



nodoLista* altaEmpleados(nodoLista* lista, trabajador dato, int idSucursal,int bajaSucursal)
{

    nodoArbol* nuevo = crearNodoArbol(dato);
    nodoLista* encontrado=buscarSucursal(lista, idSucursal);

    if(encontrado==NULL)
    {
        nodoLista* aux = crearNodoLista(idSucursal,bajaSucursal);
        lista=agregarEnOrden(lista, aux); //o al ppio
        aux->arbol=insertar(aux->arbol, nuevo);

    }

    else
    {
        encontrado->arbol=insertar(encontrado->arbol, nuevo);

    }
    return lista;
}


nodoLista* pasarDelArchivoToLDA(char archivo[], nodoLista* lista, int idSucursal)
{

    FILE* archi=fopen(archivo, "rb");

    if(archi)
    {
        trabajador a;
        while(fread(&a, sizeof(trabajador), 1, archi)>0)
        {

            lista=altaEmpleados(lista, a, a.idSucursal,a.bajaSucursal);



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
        if(lista->bajaSucursal==1)
        {
            printf("\n\n\n\n\n\n");
            printf("\t\t\t\t\t | Id sucursal: %i    |\n", lista->idSucursal);
            printf("\t\t\t\n-----------------------------------------------------------------------------------------------------------------------\n");
            inorder(lista->arbol);
        }



        lista=lista->siguiente;

    }

}

nodoLista * buscarNodoEmpleado(nodoLista * lista,  int idSucursal)
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
    printf("\n\n\n\n");
    printf("\t\t\t\t\tTrabajadores rango %i: \n\n\n\n", rango);
    while(lista!=NULL)
    {
        printf("\t\t\t\t\tId sucursal: %i\n", lista->idSucursal);
        printf("\t\t\t\n-----------------------------------------------------------------------------------------------------------------------\n");
        inorderRango(lista->arbol, rango);
        lista=lista->siguiente;
    }



}


///

void cambiarSueldo(char archivo[], nodoArbol* aux, int dni)
{

    int flag=0;

    FILE* archi=fopen(archivo, "r+b");

    if(archi)
    {

        trabajador a;



        while(flag==0 && fread(&a, sizeof(trabajador),1,archi)>0)
        {


            if(a.dni==dni)
            {
                int sueldo;
                printf("Ingrese el sueldo: \n");
                fflush(stdin);
                scanf("%i", &sueldo);
                aux->dato.sueldo=sueldo;
                a.sueldo=sueldo;
                fseek(archi, (-1)*sizeof(trabajador), SEEK_CUR); // Retrocede al inicio del registro
                fwrite(&a, sizeof(trabajador), 1, archi); // Escribe el registro modificado


                flag=1;

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

//dar de baja solo con dni

nodoArbol *buscarPorDniBaja(nodoArbol *arbol, int dni)
{
    nodoArbol *aux=NULL;
    if(arbol!=NULL)
    {
        if(arbol->dato.dni==dni)
        {
            aux=arbol;

        }
        else
        {
            aux=buscarPorDniBaja(arbol->izq,dni);
            if(!aux)
            {
                aux=buscarPorDniBaja(arbol->der,dni);
            }
        }

    }
    return aux;
}

nodoArbol* buscarPorDniPrincipal(nodoLista* lista, int dni)
{
    int flag = 0;
    nodoArbol* aux = NULL;

    while (lista != NULL && flag == 0)
    {
        aux = buscarPorDniBaja(lista->arbol, dni);

        if (aux != NULL)
        {
            flag = 1;
        }
        else
        {
            lista = lista->siguiente;
        }
    }

    return aux;
}

void darDeBajaNuevo(char archivo[], nodoArbol* aux, int dni)
{

    int flag=0;

    FILE* archi=fopen(archivo, "r+b");

    if(archi)
    {

        trabajador a;


        while(flag==0 && fread(&a, sizeof(trabajador),1,archi)>0)
        {

            if(a.dni==dni)
            {
                aux->dato.baja=0;
                a.baja=0;
                fseek(archi, (-1)*sizeof(trabajador), SEEK_CUR); // Retrocede al inicio del registro
                fwrite(&a, sizeof(trabajador), 1, archi); // Escribe el registro modificado


                flag=1;

            }






        }

        fclose(archi);
    }



}

void darDeAltaNuevo(char archivo[], nodoArbol* aux, int dni)
{

    int flag=0;

    FILE* archi=fopen(archivo, "r+b");

    if(archi)
    {

        trabajador a;


        while(flag==0 && fread(&a, sizeof(trabajador),1,archi)>0)
        {

            if(a.dni==dni)
            {
                aux->dato.baja=1;
                a.baja=1;
                fseek(archi, (-1)*sizeof(trabajador), SEEK_CUR); // Retrocede al inicio del registro
                fwrite(&a, sizeof(trabajador), 1, archi); // Escribe el registro modificado


                flag=1;

            }






        }

        fclose(archi);
    }



}

//cambiar dni


void cambiarDni(char archivo[], nodoArbol* aux, int dni, nodoLista* lista)
{

    int flag=0;

    FILE* archi=fopen(archivo, "r+b");

    if(archi)
    {

        trabajador a;



        while(flag==0 && fread(&a, sizeof(trabajador),1,archi)>0)
        {


            nodoArbol* repetido;
            if(a.dni==dni)
            {
                int dniCambio;
                printf("Ingrese el dni nuevo: \n");
                fflush(stdin);
                scanf("%i", &dniCambio);

                repetido=buscarPorDniPrincipal(lista,dniCambio);

                if(repetido==NULL)
                {
                    aux->dato.dni=dniCambio;
                    a.dni=dniCambio;
                    fseek(archi, (-1)*sizeof(trabajador), SEEK_CUR); // Retrocede al inicio del registro
                    fwrite(&a, sizeof(trabajador), 1, archi); // Escribe el registro modificado


                    flag=1;
                }
                else
                {
                    printf("El dni ya existe\n");
                    break;
                }


            }


        }


        fclose(archi);
    }


}

//cambiar sucursal


void cambiarSucursalTrabajador(char archivo[], nodoArbol* aux, int dni, nodoLista* lista)
{

    int flag=0;

    FILE* archi=fopen(archivo, "r+b");

    if(archi)
    {

        trabajador a;


        while(flag==0 && fread(&a, sizeof(trabajador),1,archi)>0)
        {


            nodoLista* sucursalEncontrada;

            if(a.dni==dni)
            {
                int sucursalNueva;
                printf("Ingrese la nueva sucursal: \n");
                fflush(stdin);
                scanf("%i", &sucursalNueva);

                sucursalEncontrada=buscarSucursal(lista,sucursalNueva);

                if(sucursalEncontrada!=NULL && sucursalEncontrada->bajaSucursal==1)
                {

                    aux->dato.idSucursal=sucursalNueva;
                    a.idSucursal=sucursalNueva;
                    fseek(archi, (-1)*sizeof(trabajador), SEEK_CUR); // Retrocede al inicio del registro
                    fwrite(&a, sizeof(trabajador), 1, archi); // Escribe el registro modificado



                    sucursalEncontrada->arbol=insertar(sucursalEncontrada->arbol,aux);




                    flag=1;
                }
                else
                {
                    printf("La sucursal no existe o esta dada de baja\n");
                    break;
                }


            }


        }


        fclose(archi);
    }


}

void cambiarNombreTrabajador(char archivo[], nodoArbol* aux, int dni, nodoLista* lista)
{

    int flag=0;

    FILE* archi=fopen(archivo, "r+b");

    if(archi)
    {

        trabajador a;



        while(flag==0 && fread(&a, sizeof(trabajador),1,archi)>0)
        {


            if(a.dni==dni)
            {
                char nombreNuevo[30];
                printf("Ingrese el nombre y apellido nuevo: \n");
                fflush(stdin);
                gets(nombreNuevo);


                strcpy(aux->dato.nombreApe,nombreNuevo);
                strcpy(a.nombreApe,nombreNuevo);
                fseek(archi, (-1)*sizeof(trabajador), SEEK_CUR); // Retrocede al inicio del registro
                fwrite(&a, sizeof(trabajador), 1, archi); // Escribe el registro modificado


                flag=1;



            }


        }


        fclose(archi);
    }


}

void cambiarRango(char archivo[], nodoArbol* aux, int dni, nodoLista* lista)
{

    int flag=0;

    FILE* archi=fopen(archivo, "r+b");

    if(archi)
    {

        trabajador a;



        while(flag==0 && fread(&a, sizeof(trabajador),1,archi)>0)
        {


            if(a.dni==dni)
            {
                int rango;
                printf("Ingrese el rango nuevo: \n");
                fflush(stdin);
                scanf("%i", &rango);

                if(rango!=1 && rango!=2 && rango!=3)
                {

                    printf("Rango no valido\n");
                }
                else
                {
                    aux->dato.rango=rango;
                    a.rango=rango;
                    fseek(archi, (-1)*sizeof(trabajador), SEEK_CUR); // Retrocede al inicio del registro
                    fwrite(&a, sizeof(trabajador), 1, archi); // Escribe el registro modificado


                    flag=1;

                }



            }


        }


        fclose(archi);
    }


}
//mostrar por dni
void mostrarPorDniTrabajador(nodoArbol* aux){

mostrarUnTrabajador(aux->dato);


}


//mostrar por orden alfabetico

nodoArbol* insertarAlfabetico(nodoArbol* arbol, nodoArbol* nuevo)
{
    if (arbol == NULL)
    {
        arbol = nuevo;
    }
    else
    {

        int comparacion = strcmpi(arbol->dato.nombreApe, nuevo->dato.nombreApe);

        if (comparacion >= 0)
        {
            arbol->izq = insertarAlfabetico(arbol->izq, nuevo);
        }
        else
        {
            arbol->der = insertarAlfabetico(arbol->der, nuevo);
        }
    }

    return arbol;
}


nodoLista* altaEmpleadosAlfabetico(nodoLista* lista2, trabajador dato, int idSucursal,int bajaSucursal)
{

    nodoArbol* nuevo = crearNodoArbol(dato);
    nodoLista* encontrado=buscarSucursal(lista2, idSucursal);

    if(encontrado==NULL)
    {
        nodoLista* aux = crearNodoLista(idSucursal,bajaSucursal);
        lista2=agregarEnOrden(lista2, aux); //o al ppio
        aux->arbol=insertarAlfabetico(aux->arbol, nuevo);

    }

    else
    {
        encontrado->arbol=insertarAlfabetico(encontrado->arbol, nuevo);

    }
    return lista2;
}


nodoLista* pasarDelArchivoToLDAAlfabetico(char archivo[], nodoLista* lista2, int idSucursal)
{

    FILE* archi=fopen(archivo, "rb");

    if(archi)
    {
        trabajador a;
        while(fread(&a, sizeof(trabajador), 1, archi)>0)
        {

            lista2=altaEmpleadosAlfabetico(lista2, a, a.idSucursal,a.bajaSucursal);



        }

        fclose(archi);
    }

    return lista2;
}

void mostrarPorOrdenAlfabetico(nodoLista* lista2){

 printf("\n\n\n\n");
    printf("\t\t\t\t\tLISTA DE TRABAJADORES: \n\n\n\n");
    while(lista2 != NULL)
    {
        if(lista2->bajaSucursal==1)
        {
            printf("\n\n\n\n\n\n");
            printf("\t\t\t\t\t | Id sucursal: %i    |\n", lista2->idSucursal);
            printf("\t\t\t\n-----------------------------------------------------------------------------------------------------------------------\n");
            inorder(lista2->arbol);
        }



        lista2=lista2->siguiente;

    }



}


