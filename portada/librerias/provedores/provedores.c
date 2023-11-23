#include <stdio.h>
#include <stdlib.h>
#include "provedores.h"
#include <string.h>
#define ESC 27
#include <conio.h>







//TDA LISTAS DOBLES

// Function to create a new node with the given provedor data
nodoDobleProvedores* crearNuevoNodoProvedor(provedor dato) {
    nodoDobleProvedores* nuevoNodo = (nodoDobleProvedores*)malloc(sizeof(*nuevoNodo));

    if (nuevoNodo == NULL) {
        perror("Error creating new node");
        return NULL;
    }

    nuevoNodo->dato = dato;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

// Function to add a new node to the doubly linked list
nodoDobleProvedores* agregarNuevoNodoAlFinal(nodoDobleProvedores* lista, nodoDobleProvedores* nuevoNodo) {
    if (lista == NULL) {
        return nuevoNodo;
    }

    nodoDobleProvedores* aux = lista;
    while (aux->siguiente != NULL) {
        aux = aux->siguiente;
    }

    aux->siguiente = nuevoNodo;
    nuevoNodo->anterior = aux;

    return lista;
}

// Function to display the doubly linked list
void mostrarListaProveedores(nodoDobleProvedores* lista) {
    while (lista != NULL) {
        printf("Nombre: %s, Stock: %d\n", lista->dato.nombre, lista->dato.stock);
        lista = lista->siguiente;
    }
}

nodoDobleProvedores* agregarNuevoNodoAlPrincipio(nodoDobleProvedores* lista, nodoDobleProvedores* nuevoNodo) {
    if (lista == NULL) {
        return nuevoNodo;
    }

    nuevoNodo->siguiente = lista;
    lista->anterior = nuevoNodo;

    return nuevoNodo;
}

//TDA FILAS

void inicFila(fila* f) {
    f->prim = NULL;
    f->ult = NULL;
}

// Function to add a new node to the queue (fila)
void agregarAlaFila(fila* F, nodoDobleProvedores* nuevo) {
    if (F->prim == NULL) {
        F->prim = nuevo;
        F->ult = nuevo;
    } else {
        F->ult = agregarNuevoNodoAlFinal(F->ult, nuevo);
        F->ult = nuevo;
    }
}

// Function to check if the queue (fila) is empty
int filaVacia(fila F) {
    return F.prim == NULL;
}

// Function to display the queue (fila)
void mostrarFila(fila F) {
    mostrarListaProveedores(F.prim);
}




// CARGA FILA PROVEDORES CON CATALOGO DEL DEPOSITO
void pasarDeDepositoAAFilas(catalogo arreglo[], int validos, fila *prov, char archivoDepos[]) {
    int i = 0;

    while (i < validos) {
        printf("\n EL STOCK DE LOS PRODUCTOS: %s", arreglo[i].nombreDeCategoria);
        cargaFilaDeProvedores(arreglo[i], prov, archivoDepos);  // Pass catalog element by reference
        i++;
    }

}

void cargaFilaDeProvedores(catalogo dato, fila *prov, char archivoDepos[]) {
    nodoProductos *seg = dato.lista;
    char opcion;
    provedor auxFila;
    nodoDobleProvedores *nuevo;

    while (seg != NULL) {
        printf("\nDESEA COMPRAR (s o n): %s", seg->dato.nombreDeProductos);
        fflush(stdin);
        opcion = getch();
        if (opcion == 's' || opcion == 'S') {
            auxFila = cambioDeEstrucCatalAFila(seg->dato, archivoDepos);
            nuevo = crearNuevoNodoProvedor(auxFila);
            agregarAlaFila(prov, nuevo);
        } else {
            seg = seg->siguiente;
        }
    }
}

provedor cambioDeEstrucCatalAFila(productos dato, char archivoDepos[]) {
    provedor dest;
    strcpy(dest.nombre, dato.nombreDeProductos);
    dest.stock = cargaCompra();
    modificarSatockDeposito(archivoDepos, dato.id, dest.stock);
    return dest;
}

int cargaCompra() {
    int compra;
    printf("\ncargue la compra del producto: ");
    scanf("%d", &compra);
    return compra;
}

void modificarSatockDeposito(char archi[], int idDelRegistro, int compra) {
    FILE *archivo;
    archivo = fopen(archi, "rb+");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
    }

    deposito registro;
    while (fread(&registro, sizeof(deposito), 1, archivo) == 1) {
        if (registro.id == idDelRegistro) {
            printf("stock antes de la modificación: %d\n", registro.stock);
            registro.stock = registro.stock + compra;
            fseek(archivo, -sizeof(deposito), SEEK_CUR);
            fwrite(&registro, sizeof(deposito), 1, archivo);
            printf("stock después de la modificación: %d\n", registro.stock);
            break;
        }
    }

    fclose(archivo);
}
