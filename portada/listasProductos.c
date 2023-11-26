#include <stdio.h>
#include <stdlib.h>
#include "listasProductos.h"



#define ESC 27



//TDA de listas
nodoProductos * inicListaProduc()
{
    return NULL;
}

nodoProductos *crearNuevonodoProductos(productos dato )
{

    nodoProductos *aux=(nodoProductos*)malloc(sizeof(nodoProductos));//creo el puntero que apunta al espacio de memoria del nodoProductos

    aux->dato=dato;//igualo el nodoProductos que cree al dato que me pasaron

    aux->siguiente=NULL;//apunto el campo que contiene la siguiente dirrecion de memoria a null

    return aux;//retorno el la nuva direccion de memoria para que sea asignada a un puntero

}
nodoProductos* agregarNuevonodoProductosAlPLista(nodoProductos* lista, nodoProductos* nuevonodoProductos)
{
    if (lista == NULL || strcasecmp(nuevonodoProductos->dato.nombreDeProductos, lista->dato.nombreDeProductos) < 0)
    {
        // Case: the list is empty or the new node should go at the beginning
        nuevonodoProductos->siguiente = lista;
        lista = nuevonodoProductos;
    }
    else
    {
        // Find the correct position for insertion based on alphabetical order
        nodoProductos* actual = lista;
        while (actual->siguiente != NULL &&
                strcasecmp(nuevonodoProductos->dato.nombreDeProductos, actual->siguiente->dato.nombreDeProductos) > 0)
        {
            actual = actual->siguiente;
        }

        // Insert the new nodoProductos at the correct position
        nuevonodoProductos->siguiente = actual->siguiente;
        actual->siguiente = nuevonodoProductos;
    }

    return lista;
}
//__________________________________________________________________________________________________________________________________________________________________________________________________________________

//manejo de arreglo de listas
int buscaEnCatalogo(catalogo arreglo[],int validos,deposito dato)
{
    int i=validos-1,flag=-1;
    while(i>=0 && flag==-1)
    {
        if(strcmp(arreglo[i].nombreDeCategoria,dato.nombreDeCategoria)==0)
        {
            flag=i;
        }
        else
        {
            i--;
        }

    }
    return flag;
}


int agregarALCatalogo(catalogo arreglo[],int validos,deposito dato)//agrega al cateorias al arreglo
{
    strcpy(arreglo[validos].nombreDeCategoria,dato.nombreDeCategoria);
    arreglo[validos].idCategoria=dato.idCategoria;
    arreglo[validos].activoCat=dato.activoCat;

    arreglo[validos].lista=inicListaProduc();
    validos++;
    return validos;
}
int buscarUltimoIdDelista(nodoProductos *lista)
{
    nodoProductos *seg=lista;
    while(seg->siguiente!=NULL)
    {
        seg=seg->siguiente;
    }
    return seg->dato.id;
}
int altaCatalogo(catalogo arreglo[],int validos,deposito dato)//controla la carga de datos al arreglo de listas
{
    int pos=buscaEnCatalogo(arreglo,validos,dato);
    nodoProductos *aux;
    productos aux2P=pasarDeRegistroCatAPro(dato);

    if(pos==-1)
    {
        validos=agregarALCatalogo(arreglo,validos,dato);
        pos=validos-1;

    }


    aux=crearNuevonodoProductos(aux2P);

    arreglo[pos].lista=agregarNuevonodoProductosAlPLista(arreglo[pos].lista,aux);

    return validos;
}

productos pasarDeRegistroCatAPro(deposito origen)
{
    productos dest;
    strcpy(dest.nombreDeProductos,origen.nombreDeProductos);
    dest.id=origen.id;
    dest.precioPorKilo=origen.precioPorKilo;
    dest.stock=origen.stock;
    dest.activoPro=origen.activoPro;

    return dest;
}
void ordenarCatalogoAlfabeticamente(catalogo arreglo[], int validos)
{
    int i, j;
    catalogo temp;

    for (i = 0; i < validos - 1; i++)
    {
        for (j = 0; j < validos - i - 1; j++)
        {
            if (strcasecmp(arreglo[j].nombreDeCategoria, arreglo[j + 1].nombreDeCategoria) > 0)
            {
                // Swap elements if they are in the wrong order
                temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}
//__________________________________________________________________________________________________________________________________________________________________________________________________________________

// carga de arreglo de listas


int pasardeArchivoAArreglo(char archivo[],int idDeSuc,catalogo arreglo[],int dim)
{
    FILE *archi=fopen(archivo,"rb");
      deposito aux;
    int i = 0, validos = 0;

    if (archi != NULL) {
        while (fread(&aux, sizeof(deposito), 1, archi) == 1 && i < dim) {
            if (aux.idDeSucursal == idDeSuc) {
                validos = altaCatalogo(arreglo, validos, aux);
                i++;
            }
        }
    }

    return validos;
}


//FUNCIONES DE MUESTRA

void mostrarUnProducto(productos dato)
{
    printf("\nACTIVO PRODUCTO: %d",dato.activoPro);
    printf("\nNOMBRE DE PRODUCTO:  %s", dato.nombreDeProductos);
    printf("\nPRECIO POR KILO: %d ",dato.precioPorKilo);
    printf("\nSTOCK: %d", dato.stock);
    printf("\nID PRODUCTO: %d", dato.id);
    printf("\n");
}
void muestraLISTA(nodoProductos *lista)
{
    while (lista != NULL)
    {
        if (lista->dato.activoPro == 1)
        {
            mostrarUnProducto(lista->dato);
        }
        lista = lista->siguiente;
    }

}
void muestraUnCatalogo(catalogo A)
{
    if (A.activoCat == 1)
    {
        printf("\nNOMBRE DE CATEGORIA: %s", A.nombreDeCategoria);
        printf("\nID DE CATEGORIA: |%d|", A.idCategoria);
        printf("\nACTIVO CATEGORIA: %d",A.activoCat);
        muestraLISTA(A.lista);
        printf("\n----------------------------------------------");
    }


}


void muestraDeCatalogo(catalogo A[],int validos)
{
    int i=0;

    while (i<validos)
    {
        muestraUnCatalogo(A[i]);
        i++;
    }

}

//MUESTRA ACTIVO Y NO ACTIVOS


void muestraLISTATODOs(nodoProductos *lista)
{
    while (lista != NULL)
    {

        mostrarUnProducto(lista->dato);

        lista = lista->siguiente;
    }

}
void muestraUnCatalogoTodos(catalogo A)
{
    printf("\nNOMBRE DE CATEGORIA: %s", A.nombreDeCategoria);
    printf("\nID DE CATEGORIA|%d|", A.idCategoria);
    printf("\nACTIVO(catalogo):%d",A.activoCat);
    muestraLISTATODOs(A.lista);
    printf("\n----------------------------------------------");



}


void muestraDeCatalogoTodos(catalogo A[],int validos)
{
    int i=0;

    while (i<validos)
    {
        muestraUnCatalogoTodos(A[i]);
        i++;
    }
}





//MUESTRA DE ARCHIVO_deposito

void muestraUnRegistro(deposito dato)
{
    if(dato.activoCat==1)
    {
        printf("\nid de suc %d",dato.idDeSucursal);
        printf("\nNOMBRE DE CATEGORIA: %s",dato.nombreDeCategoria);
        printf("\nid DE CATEGORIA|%d|",dato.idCategoria);
        printf("\nACTIVO CATEGORIA: %d",dato.activoCat);
    }
    if(dato.activoPro==1)
    {
        printf("\nACTIVO PRODUCTO: %d",dato.activoPro);
        printf("\nNOMBRE DE PRODUCTO:  %s",dato.nombreDeProductos);
        printf("\nPRECIO POR KILO:%d ",dato.precioPorKilo);
        printf("\nSTOCK: %d",dato.stock);
        printf("\nId de productos |%d|",dato.id);
        printf("\n----------------------------------------------\n");
    }



}
void muestraArchivo(char archivo[])
{
    FILE *archi=fopen(archivo,"rb");
    deposito aux;
    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(deposito),1,archi)>0)
        {

            muestraUnRegistro(aux);
        }
        fclose(archi);
    }
    else
    {
        printf("Error archivo deposito.\n");
    }

}




//funcion de desactivar
int buscaEnCatalogoPorId(catalogo arreglo[], int validos, int id)
{
    int flag = -1, i = 0;

    while (i < validos && flag == -1)
    {
        if (arreglo[i].idCategoria == id)
        {
            flag = i;
            break;
        }
        i++;
    }


    if (flag == -1)
    {
        printf("No se encontró una categoría con el ID %d.\n", id);
         return flag;
    }

    return flag;
}


void desactivarCatalogo(char archivo[],catalogo ar[], int pos,int idDeSuc)
{
    FILE *buffer = fopen(archivo, "r+b");

    if (buffer != NULL)
    {
        deposito aux;
        int flag = 0;


        while (fread(&aux, sizeof(deposito), 1, buffer) > 0 && flag == 0)


    if (ar[pos].idCategoria == aux.idCategoria && aux.idDeSucursal == idDeSuc)
    {
      ar[pos].activoCat = 0;
                aux.activoCat = 0;

                fseek(buffer, (-1) * sizeof(deposito), SEEK_CUR);
                fwrite(&aux, sizeof(deposito), 1, buffer);
                fflush(buffer);
                flag = 1;
    }
}

        fclose(buffer);
    }
    else
    {
        printf("\nnnn");
    }
}


nodoProductos* buscaEnListaId(catalogo arreglo[],int pos,int idDePro)
{
    int flag=0;
    nodoProductos *id=NULL,*seg;
    seg=arreglo[pos].lista;

    //muestraUnCatalogo(arreglo[pos]);
    //mostrarUnProducto(seg->dato);
    while(seg!=NULL&& flag==0)
    {
        if(seg->dato.id==idDePro)
        {

            flag=1;
            id=seg;
        }

        seg= seg->siguiente;
    }
    return id;

}

void desactivarProducto(char archivo[], catalogo arreglo[],int pos,nodoProductos* id,int idDeSuc)
{
    FILE *buffer = fopen(archivo, "r+b");

    if (buffer != NULL)
    {

        deposito aux;

        int flag = 0;

        while (fread(&aux, sizeof(deposito), 1, buffer)>0 && flag == 0)//abre
        {

            if (id->dato.id == aux.id&& aux.idDeSucursal==idDeSuc )
            {
                id->dato.activoPro = 0;
                aux.activoPro = 0;

                fseek(buffer, (-1) * sizeof(deposito), SEEK_CUR);
                fwrite(&aux, sizeof(deposito), 1, buffer);
                flag = 1;

            }
        }
        fclose(buffer);
    }


}

void activarProducto(char archivo[], catalogo arreglo[],int pos,nodoProductos* id,int idDeSuc)
{
    FILE *buffer = fopen(archivo, "r+b");

    if (buffer != NULL)
    {

        deposito aux;

        int flag = 0;

        while (fread(&aux, sizeof(deposito), 1, buffer) == 1 && flag == 0)
        {
            if (id->dato.id == aux.id && aux.idDeSucursal == idDeSuc)
            {
                id->dato.activoPro = 1;
                aux.activoPro = 1;

                fseek(buffer, (-1) * sizeof(deposito), SEEK_CUR);
                fwrite(&aux, sizeof(deposito), 1, buffer);
                flag = 1;
            }
        }
        if(flag==0)
        {
            printf("\nNo se pudo activar el producto.\n");
        }
        fclose(buffer);
    }


}

void activarCatalogo(char archivo[],catalogo ar[], int id, int pos,int idDeSuc)
{
    FILE *buffer = fopen(archivo, "r+b");

    if (buffer != NULL)
    {
        deposito aux;
        int flag = 0;

        while (fread(&aux, sizeof(deposito), 1, buffer) > 0 && flag == 0)
        {
            if (ar[pos].idCategoria == aux.idCategoria && aux.activoCat!=1 && aux.idDeSucursal==idDeSuc)
            {
                ar[pos].activoCat = 1;
                aux.activoCat = 1;

                fseek(buffer, (-1) * sizeof(deposito), SEEK_CUR);
                fwrite(&aux, sizeof(deposito), 1, buffer);
                fflush(buffer);
                flag = 1;
            }
        }
        if(flag==0)
        {
            printf("\nNo se pudo activar la categoria.\n");
        }


        fclose(buffer);
    }
    else
    {
        printf("\nnnn");
    }
}




// Función para generar un ID único
int generarIDUnico()
{
    // Inicializar la semilla del generador de números aleatorios con el tiempo actual
    srand((unsigned int)time(NULL));

    // Generar un número aleatorio y devolverlo como el ID único
    return rand();
}

deposito cargaRegistro(int idDeSuc)
{
    deposito dato;

    dato.idDeSucursal = idDeSuc;

    printf("\nNOMBRE DE CATEGORIA: ");
    fflush(stdin);
    gets(dato.nombreDeCategoria);

    // Use a consistent method for generating idCategoria
    dato.idCategoria = generarIDUnico();

    dato.activoCat = 1;

    // Use a consistent method for generating id
    dato.id = generarIDUnico();

    printf("\nNOMBRE DE PRODUCTO:  ");
    fflush(stdin);
    gets(dato.nombreDeProductos);

    dato.stock = 0; // Initialize to 0, and the supplier will update the stock
    printf("\nPRECIO POR KILO: ");
    scanf("%d", &dato.precioPorKilo);

    dato.activoPro = 1;

    return dato;
}



int cantidadDeRegistros()
{
    int cantidad;
    FILE* buffer = fopen(ARCHIVO_DEPOSITO,"rb");
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cantidad =(int)ftell(buffer)/sizeof(deposito);
        fclose(buffer);
    }
    return cantidad;
}

int buscarIdCategoriaPorNombre( char nombreArchivo[],  char nombreCategoria[])
{
    FILE* archivo = fopen(nombreArchivo, "rb");

    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return -1; // Return -1 to indicate an error
    }

    catalogo registro;

    while (fread(&registro, sizeof(catalogo), 1, archivo) == 1)
    {
        if (strcmp(registro.nombreDeCategoria, nombreCategoria) == 0 && registro.activoCat == 1)
        {
            fclose(archivo);
            return registro.idCategoria; // Return the ID if category is found
        }
    }

    fclose(archivo);
    return -1; // Return -1 if category is not found
}
void cargaArchivo(char archivo[], int idDeSuc)
{
    deposito aux;
    char opcion;

    FILE* buffer = fopen(archivo, "ab");
    if (buffer)
    {
        do
        {

            aux = cargaRegistro(idDeSuc);
            fwrite(&aux, sizeof(deposito), 1, buffer);

            printf("\nSi desea salir presione ESC. De lo contrario, presione cualquier tecla.\n");
            fflush(stdin);
            opcion = getch();
            system("cls");
        }
        while (opcion != ESC);

        fclose(buffer);
    }
    else
    {
        perror("Error al abrir archivo");
    }
}



//MODIFICACIONE EN EL ARCHIVO


void modificarCatalogoArchivo(catalogo ar[], int pos,  char nuevoNombreCatalogo[])//MODIFICA EL NOMBRE DEL CATALOGO
{
    FILE *buffer = fopen(ARCHIVO_DEPOSITO, "r+b");

    if (buffer)
    {
        deposito aux;
        long posicion = 0;  // Almacena la posición actual en el archivo

        while (fread(&aux, sizeof(deposito), 1, buffer) > 0)
        {
            if (strcmp(aux.nombreDeCategoria, ar[pos].nombreDeCategoria) == 0)
            {
                // Modificar el nombre de la categoría en la estructura auxiliar
                strcpy(aux.nombreDeCategoria, nuevoNombreCatalogo);

                // Guardar la posición actual en el archivo
                fseek(buffer, posicion, SEEK_SET);

                // Escribir la estructura modificada de vuelta en el archivo
                fwrite(&aux, sizeof(deposito), 1, buffer);

                // Romper el bucle después de la modificación
                break;
            }

            // Actualizar la posición actual en el archivo
            posicion = ftell(buffer);
        }

        fclose(buffer);
    }
}


void modificarProductoArchivo(catalogo ar[], int pos,  int idDePro,char nuevoNombreProducto[])//MODIFICA EL NOMBRE DEL PRODUCTO
{
    FILE *buffer = fopen(ARCHIVO_DEPOSITO, "r+b");

    if (buffer)
    {
        deposito aux;
        long posicion = 0;  // Almacena la posición actual en el archivo

        while (fread(&aux, sizeof(deposito), 1, buffer) > 0)
        {
            if (strcmp(aux.nombreDeCategoria, ar[pos].nombreDeCategoria) == 0 && aux.id==idDePro)
            {
                // Modificar el nombre de la categoría en la estructura auxiliar

                strcpy(aux.nombreDeProductos,nuevoNombreProducto);
                // Guardar la posición actual en el archivo
                fseek(buffer, posicion, SEEK_SET);

                // Escribir la estructura modificada de vuelta en el archivo
                fwrite(&aux, sizeof(deposito), 1, buffer);

                // Romper el bucle después de la modificación
                break;
            }

            // Actualizar la posición actual en el archivo
            posicion = ftell(buffer);
        }

        fclose(buffer);
    }
}

void modificarProductoPrecioArchivo(catalogo ar[], int pos,  int idDePro,int nuevoPrecio)//MODIFICA EL PRECIO PRODUCTO
{
    FILE *buffer = fopen(ARCHIVO_DEPOSITO, "r+b");

    if (buffer)
    {
        deposito aux;
        long posicion = 0;  // Almacena la posición actual en el archivo

        while (fread(&aux, sizeof(deposito), 1, buffer) > 0)
        {
            if (strcmp(aux.nombreDeCategoria, ar[pos].nombreDeCategoria) == 0 && aux.id==idDePro)
            {
                // Modificar el nombre de la categoría en la estructura auxiliar

                aux.precioPorKilo=nuevoPrecio;
                // Guardar la posición actual en el archivo
                fseek(buffer, posicion, SEEK_SET);

                // Escribir la estructura modificada de vuelta en el archivo
                fwrite(&aux, sizeof(deposito), 1, buffer);

                // Romper el bucle después de la modificación
                break;
            }

            // Actualizar la posición actual en el archivo
            posicion = ftell(buffer);
        }

        fclose(buffer);
    }
}


