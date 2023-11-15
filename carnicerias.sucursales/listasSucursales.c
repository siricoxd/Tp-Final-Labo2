#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listasSucusrsales.h"

const char archivoProvincia[]= {"archivoProvincia.dat"};




///listas
nodoLocales*crearNodoLocales(locales dato)
{
    nodoLocales* nuevo=(nodoLocales*)malloc(sizeof(nodoLocales));
    nuevo->dato=dato;
    nuevo->siguiente=NULL;
    return nuevo;
}
nodoLocales* inicLista()
{
    return NULL;
}
void mostrarNodo(nodoLocales*lista)
{
    mostrarLocal(lista->dato);
}
void mostrarLista(nodoLocales*lista)
{
    int i=1;
    if(lista==NULL)
    {
        printf("\tLa lista esta vacia.\n");
    }
    else
    {
        nodoLocales* seguidora=lista;
        while(seguidora!=NULL)
        {
            printf("\nNodo %d: ",i);
            mostrarNodo(seguidora);
            seguidora=seguidora->siguiente;
            i++;
        }
    }
}
nodoLocales*buscarUltimo(nodoLocales*lista)
{
    nodoLocales*seg=lista;
    if(seg != NULL)
    {
        while(seg->siguiente!=NULL)
        {
            seg=seg->siguiente;
        }
    }
    return seg;
}
nodoLocales*buscarNodo(nodoLocales*lista,int id)
{
    int flag=0;
    nodoLocales*seguidora=lista;
    if(seguidora==NULL)
    {
        printf("La lista esta vacia.\n");
    }
    else
    {
        while(seguidora!=NULL&&flag==0)
        {
            if(seguidora->dato.idDeLocal==id)
            {
                flag=1;
            }
            seguidora=seguidora->siguiente;
        }
    }

    return seguidora;
}
nodoLocales* agregarAlPpioLocales(nodoLocales*lista,nodoLocales*nuevo)
{
    if(lista==NULL) //si la lista esta vacia
    {
        lista=nuevo;
    }
    else// si la lista tiene algo
    {
        nuevo->siguiente=lista;
        lista=nuevo;
    }
    return lista;
}
nodoLocales*agregarAlFinalLocales(nodoLocales*lista,nodoLocales*nuevo)
{

    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nodoLocales*ultimo;
        ultimo=buscarUltimo(lista);
        ultimo->siguiente=nuevo;
    }
    return lista;
}
nodoLocales*agregarEnOrdenLocales(nodoLocales*lista,nodoLocales*nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        if(nuevoNodo->dato.idDeLocal<lista->dato.idDeLocal)
        {
            agregarAlPpioLocales(lista,nuevoNodo);
        }
        else
        {
            nodoLocales*ante=lista;
            nodoLocales*seg=lista->siguiente;
            while(seg!=NULL&&nuevoNodo->dato.idDeLocal>=seg->dato.idDeLocal)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            nuevoNodo->siguiente=seg;
            ante->siguiente=nuevoNodo;
        }
    }
    return lista;
}
nodoLocales*EliminarLocal(nodoLocales*lista,int objetivo)
{
    if(lista!=NULL)
    {
        if(objetivo==lista->dato.idDeLocal)
        {
            lista->dato.activo=0;
        }
        else
        {
            int flag=0;

            while(lista!=NULL&&flag==0)
            {
                if(lista->dato.idDeLocal==buscarNodo(lista,objetivo)->dato.idDeLocal)
                    lista->dato.activo=0;
            }
        }
    }
    return lista;
}
///mostrar y cargar
provincia cargarProvincia()
{
    provincia aux;
    printf("Ingrese la provincia: ");
    fflush(stdin);
    gets(aux.NombreProvincia);
    printf("Ingrese el id de la provincia: ");
    scanf("%d",&aux.idProvincia);
    aux.activo=1;


    return aux;
}
int cargarArreglosProvincia(provincia ar[],registroArchivoLocales dato,int dim,int validos)
{
    if(validos<dim)
    {
        strcpy(ar[validos].NombreProvincia,dato.provincia);
        ar[validos].idProvincia=dato.idProvincia;
        ar[validos].activo=dato.activoProv;
        ar[validos].listaDelocales=inicLista();
        validos++;
    }

    return validos;
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
    printf("Ingrese el id del local: ");
    scanf("%d",&aux.idDeLocal);
    aux.activo=1;

    return aux;
}
void mostrarProvincia(provincia aux)
{
    printf("Privincia: %s\n",aux.NombreProvincia);
    printf("Id provincia: %d\n",aux.idProvincia);
}
void mostrarLocal(locales aux)
{
    printf("Ciudad del local: %s\n",aux.localidad);
    printf("Direccion del local: %s\n",aux.direccion);
    printf("Id del local: %d\n",aux.idDeLocal);
}
void mostrarAr(provincia ar[],int validos)
{
    int i=0;
    printf("Provincias en las cuales tenemos una sucursal:\n");
    while(i<validos)
    {
        if(ar[i].activo==1)
        {
            mostrarProvincia(ar[i]);
        }
        i++;
    }
}
void desactivarProvincia(provincia ar[],int pos)
{

    FILE*buffer=fopen(archivoProvincia,"r+b");
    if(buffer)
    {
        registroArchivoLocales aux;
        int flag=0;
        while(fread(&aux,sizeof(registroArchivoLocales),1,buffer)&&flag==0)
        {
            if(ar[pos].idProvincia==aux.idProvincia)
            {
                ar[pos].activo=0;
                aux.activoProv=0;
                fseek(buffer,(-1)*sizeof(registroArchivoLocales),SEEK_CUR);
                fwrite(&aux,sizeof(registroArchivoLocales),1,buffer);

                flag=1;
            }
        }

        fclose(buffer);
    }

}
void activarProvincia(provincia ar[],int pos)
{

    FILE*buffer=fopen(archivoProvincia,"r+b");
    if(buffer)
    {
        registroArchivoLocales aux;
        int flag=0;
        while(fread(&aux,sizeof(registroArchivoLocales),1,buffer)&&flag==0)
        {
            if(ar[pos].idProvincia==aux.idProvincia)
            {
                ar[pos].activo=1;
                aux.activoProv=1;
                fseek(buffer,(-1)*sizeof(registroArchivoLocales),SEEK_CUR);
                fwrite(&aux, sizeof(registroArchivoLocales),1, buffer);
                flag=1;
            }
        }

        fclose(buffer);
    }

}
int buscarPosProvincia(provincia ar[],int id,int validos)
{
    int rta=-1;
    int i=0;
    while((i<validos)&&(rta==-1))
    {
        if(id==ar[i].idProvincia)
        {
            rta=i;
        }
        i++;
    }
    return rta;
}
int alta(provincia ar[],registroArchivoLocales dato,int validos)
{
    nodoLocales* aux;
    locales auxlocal=pasarRegistrosToLocal(dato);
    aux=crearNodoLocales(auxlocal);

    int pos=buscarPosProvincia(ar,dato.idProvincia,validos);
    if (pos==-1)
    {
        validos=cargarArreglosProvincia(ar,dato,30,validos);
        pos=validos-1;
    }
    //if(ar[pos].listaDelocales->dato.idDeLocal==dato.idLocal)
    ar[pos].listaDelocales=agregarAlFinalLocales(ar[pos].listaDelocales,aux);

    return validos;
}
locales pasarRegistrosToLocal(registroArchivoLocales dato)
{
    locales auxlocal;
    auxlocal.activo=dato.activoLocal;
    strcpy(auxlocal.direccion,dato.direccion);
    strcpy(auxlocal.localidad,dato.localidad);
    auxlocal.idDeLocal=dato.idLocal;
    return auxlocal;

}
registroArchivoLocales cargarRegistroLocales()
{

    registroArchivoLocales aux;
    printf("Ingrese la provincia: ");
    fflush(stdin);
    gets(aux.provincia);
    printf("Ingrese la id de la provincia:");
    scanf("%d",&aux.idProvincia);
    aux.activoProv=1;
    printf("Ingrese la ciudad: ");
    fflush(stdin);
    gets(aux.localidad);
    printf("Ingrese la direccion del local: ");
    fflush(stdin);
    gets(aux.direccion);
    FILE* buffer2 = fopen(archivoProvincia,"rb");
    if(buffer2)
    {
        aux.idLocal=cantidadDeRegistros()+1;

        fclose(buffer2);
    }
    aux.activoLocal=1;
    return aux;
}
int cantidadDeRegistros()
{
    int cantidad;
    FILE* buffer = fopen(archivoProvincia,"rb");
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cantidad =(int)ftell(buffer)/sizeof(registroArchivoLocales);
        fclose(buffer);
    }
    return cantidad;
}
int cargarArchivo(int dim)
{
    registroArchivoLocales aux;
    int i=0;
    char salir='s';
    FILE* buffer= fopen(archivoProvincia,"ab");
    if(buffer)
    {
        while(salir=='s' && i<dim)
        {
            aux=cargarRegistroLocales();
            fwrite(&aux,sizeof(registroArchivoLocales),1,buffer);
            printf("\nDesea seguir?: ");
            fflush(stdin);
            scanf("%c",&salir);
            printf("\n");
            i++;
        }

        fclose(buffer);
    }
    return i;
}
int descargarArchivo(provincia ar[],int validos,int dim)
{
    registroArchivoLocales aux;
    FILE* buffer= fopen(archivoProvincia,"rb");
    if(buffer)
    {
        while(fread(&aux,sizeof(registroArchivoLocales),1,buffer)&&(validos<dim))
        {
            validos=alta(ar,aux,validos);
        }
        fclose(buffer);
    }
    return validos;
}
void recorrerYMostrar(provincia ar[],int validos,int pos)
{
    if(ar[pos].activo!=0)
    {
        nodoLocales*seg=ar[pos].listaDelocales;
        printf("\nProvincia: %s:\n",ar[pos].NombreProvincia);
        printf("Id de la provincia: %d\n",ar[pos].idProvincia);
        printf("Locales existentes: \n\n");
        while(seg!=NULL)
        {
            if(seg->dato.activo!=0)
            {
                printf("Ciudad del local: %s\n",seg->dato.localidad);
                printf("ID del local: %d\n",seg->dato.idDeLocal);
                printf("Direccion del local: %s\n",seg->dato.direccion);
                printf("Estado de actividad: %d\n",seg->dato.activo);
                printf("\n");
                seg=seg->siguiente;
            }
        }

    }
}
void recorrerYMostrarTodos(provincia ar[],int validos,int pos)
{
    nodoLocales*seg=ar[pos].listaDelocales;
    printf("\nProvincia: %s:\n",ar[pos].NombreProvincia);
    printf("Id de la provincia: %d\n",ar[pos].idProvincia);
    printf("Estado de actividad %d\n",ar[pos].activo);
    printf("Locales existentes: \n\n");
    while(ar[pos].listaDelocales!=NULL)
    {



        printf("Ciudad del local: %s\n",seg->dato.localidad);
        printf("ID del local: %d\n",seg->dato.idDeLocal);
        printf("Direccion del local: %s\n",seg->dato.direccion);
        printf("Estado de actividad: %d\n",seg->dato.activo);
        printf("\n");
        seg=seg->siguiente;



    }
}
void recorrerYMostrarDesactivados(provincia ar[],int validos,int pos)
{
    nodoLocales*seg=ar[pos].listaDelocales;
    if(ar[pos].activo==0)
    {

        printf("\nProvincia: %s:\n",ar[pos].NombreProvincia);
        printf("Id de la provincia: %d\n",ar[pos].idProvincia);
        printf("Locales existentes: \n\n");
        while(seg!=NULL)
        {


            printf("Ciudad del local: %s\n",seg->dato.localidad);
            printf("ID del local: %d\n",seg->dato.idDeLocal);
            printf("Direccion del local: %s\n",seg->dato.direccion);
            printf("Estado de actividad: %d\n",seg->dato.activo);
            printf("\n");
            seg=seg->siguiente;

        }

    }
}
void activarLocal(provincia ar[],int id,int pos)
{
    FILE*buffer=fopen(archivoProvincia,"r+b");
    if(buffer)
    {
        registroArchivoLocales aux;
        nodoLocales*seg=ar[pos].listaDelocales;
        int flag=0;
        while(fread(&aux,sizeof(registroArchivoLocales),1,buffer)&&flag==0)
        {
            if(ar[pos].idProvincia==aux.idProvincia&&aux.idLocal==seg->dato.idDeLocal)
            {
                while(seg!=NULL)
                {
                    seg->dato.activo=1;
                    aux.activoLocal=1;

                    fseek(buffer,(-1)*sizeof(registroArchivoLocales),SEEK_CUR);
                    fwrite(&aux, sizeof(registroArchivoLocales),1, buffer);
                    flag=1;
                    seg=seg->siguiente;
                }
            }
        }
        fclose(buffer);
    }

}
void descativarLocal(provincia ar[],int id,int pos)
{
    FILE*buffer=fopen(archivoProvincia,"r+b");
    if(buffer)
    {
        registroArchivoLocales aux;
        nodoLocales*seg=ar[pos].listaDelocales;
        int flag=0;
        while(fread(&aux,sizeof(registroArchivoLocales),1,buffer)&&flag==0)
        {
            if(ar[pos].idProvincia==aux.idProvincia&&aux.idLocal==seg->dato.idDeLocal)
            {
                while(seg!=NULL)
                {
                    seg->dato.activo=0;
                    aux.activoLocal=0;
                    fseek(buffer,(-1)*sizeof(registroArchivoLocales),SEEK_CUR);
                    fwrite(&aux, sizeof(registroArchivoLocales),1, buffer);
                    flag=1;
                    seg=seg->siguiente;
                }
            }
        }
        fclose(buffer);
    }

}
void mostrarTodo(provincia ar[],int validos)
{
    int i=0;

    printf("--------------------------------------------------------------------------------\n");
    while(i<validos)
    {
        if(ar[i].activo!=0)
        {
            nodoLocales*seg=ar[i].listaDelocales;
            printf("\nProvincia..............: %s\n",ar[i].NombreProvincia);
            printf("ID de la provincia.....: %d\n",ar[i].idProvincia);
            printf("Activo.................: %d\n",ar[i].activo);
            printf("Locales existentes \n\n");
            while(seg!=NULL)
            {

                if(seg->dato.activo!=0)
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
void Provincias()
{
    printf("   |Provincias---------ID|  \n\n");
    printf(" |Buenos Aires------------1|\n");
    printf(" |Catamarca---------------2|\n");
    printf(" |Chaco-------------------3|\n");
    printf(" |Chubut------------------4|\n");
    printf(" |Cordoba-----------------5|\n");
    printf(" |Corrientes--------------6|\n");
    printf(" |Entre Rios--------------7|\n");
    printf(" |Formosa-----------------8|\n");
    printf(" |Jujuy-------------------9|\n");
    printf(" |La Pampa---------------10|\n");
    printf(" |La Rioja---------------11|\n");
    printf(" |Mendoza----------------12|\n");
    printf(" |Misiones---------------13|\n");
    printf(" |Neuquen----------------14|\n");
    printf(" |Rio Negro--------------15|\n");
    printf(" |Salta------------------16|\n");
    printf(" |San Juan---------------17|\n");
    printf(" |San Luis---------------18|\n");
    printf(" |Santa Cruz-------------19|\n");
    printf(" |Santa Fe---------------20|\n");
    printf(" |Santiago del Estero----21|\n");
    printf(" |Tierra del Fuego-------22|\n");
    printf(" |Tucuman----------------23|\n\n");
}
