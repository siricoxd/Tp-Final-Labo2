#include <stdio.h>
#include <stdlib.h>
#include "provedores.h"
#include <string.h>
#define ESC 27
#include <conio.h>







//TDA LISTAS DOBLES

// Function to create a new node with the given provedor data
nodoDobleProvedores* crearNuevoNodoProvedor(provedor dato)
{
    nodoDobleProvedores* nuevoNodo = (nodoDobleProvedores*)malloc(sizeof(*nuevoNodo));

    if (nuevoNodo == NULL)
    {
        perror("Error creating new node");
        return NULL;
    }

    nuevoNodo->dato = dato;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}


nodoDobleProvedores* agregarNuevoNodoAlFinal(nodoDobleProvedores* lista, nodoDobleProvedores* nuevoNodo)
{
    if (lista == NULL)
    {
       lista= nuevoNodo;
    }

    nodoDobleProvedores* aux = lista;
    while (aux->siguiente != NULL)
    {
        aux = aux->siguiente;
    }

    aux->siguiente = nuevoNodo;
    nuevoNodo->anterior = aux;

    return lista;
}

// Function to display the doubly linked list
void mostrarListaProveedores(nodoDobleProvedores* lista)
{
    while (lista != NULL)
    {
        printf("Nombre: %s, Stock: %d\n", lista->dato.nombre, lista->dato.stock);
        lista = lista->siguiente;
    }
}

nodoDobleProvedores* agregarNuevoNodoAlPrincipio(nodoDobleProvedores* lista, nodoDobleProvedores* nuevoNodo)
{
    if (lista == NULL)
    {
        return nuevoNodo;
    }

    nuevoNodo->siguiente = lista;
    lista->anterior = nuevoNodo;

    return nuevoNodo;
}

//TDA FILAS
nodoDobleProvedores * inicializarListaDProductos()
{
    return NULL;
}

void inicFila(fila* f)
{
    f->prim =NULL;
    f->ult = NULL;
}

// Function to add a new node to the queue (fila)
void agregarAlaFila(fila* F, nodoDobleProvedores* nuevo)
{
    if (F->prim == NULL)
    {
        F->prim = nuevo;
        F->ult = nuevo;
    }
    else
    {
        F->ult = agregarNuevoNodoAlFinal(F->ult, nuevo);
        F->ult = nuevo;
    }
}

// Function to check if the queue (fila) is empty
int filaVacia(fila F)
{
    return F.prim == NULL;
}

// Function to display the queue (fila)
void mostrarFila(fila F)
{
    mostrarListaProveedores(F.prim);
}




// CARGA FILA PROVEDORES CON CATALOGO DEL DEPOSITO
void pasarDeDepositoAAFilas(catalogo arreglo[], int validos, fila *prov, char archivoDepos[])
{
    int i = 0;

    while (i < validos)
    {

        cargaFilaDeProvedores(arreglo[i], prov, archivoDepos);  // Pass catalog element by reference
        i++;

    }

}

provedor cambioDeEstrucCatalAFila(productos dato, char archivoDepos[])
{
    provedor dest;
    strcpy(dest.nombre, dato.nombreDeProductos);
    dest.stock = cargaCompra();
    modificarSatockDeposito(archivoDepos, dato.id, dest.stock);
    return dest;
}

void cargaFilaDeProvedores(catalogo dato, fila *prov, char archivoDepos[]) {
    nodoProductos *seg = dato.lista;




    while (seg != NULL) {
        cargaFila(prov,seg->dato,archivoDepos);
        seg=seg->siguiente;

    }
}

void cargaFila(fila *prov,productos dato,char archivoDeposGrl[])
{
    char opcion;
 provedor auxFila;
nodoDobleProvedores *nuevo;
    printf("\nSi desea comprar, presione Enter; de lo contrario, presione cualquier tecla: %s", dato.nombreDeProductos);
    fflush(stdin);
    opcion = getch();

    if (opcion == '\n' || opcion == '\r') {
        auxFila = cambioDeEstrucCatalAFila(dato, archivoDeposGrl);
        nuevo = crearNuevoNodoProvedor(auxFila);
        agregarAlaFila(prov, nuevo);
    }

        system("pause");
        system("cls");


}

int cargaCompra()
{
    int compra;
    printf("\ncargue la compra del producto: ");
    scanf("%d", &compra);
    return compra;
}

void modificarSatockDeposito(char archi[], int idDelRegistro, int compra)
{
    FILE *archivo;
    archivo = fopen(archi, "rb+");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
    }

    deposito registro;
    while (fread(&registro, sizeof(deposito), 1, archivo) == 1)
    {
        if (registro.id == idDelRegistro)
        {
            registro.stock = registro.stock + compra;
            fseek(archivo, -sizeof(deposito), SEEK_CUR);
            fwrite(&registro, sizeof(deposito), 1, archivo);
            break;
        }
    }

    fclose(archivo);
}
