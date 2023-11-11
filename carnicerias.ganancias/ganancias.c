#include "ganancias.h"

nodoGananciasAnio* inicLista(){
    return NULL;
}

nodoGananciasAnio* crearNodo(int ganancias[DIAS][MESES]){
    nodoGananciasAnio* aux=(nodoGananciasAnio*) malloc(sizeof(nodoGananciasAnio));
    memcpy(aux->ganancias, ganancias, sizeof(aux->ganancias));
    aux->siguiente=NULL;
    return aux;
}

nodoGananciasAnio* agregarAnioGananciasPpio(nodoGananciasAnio* lista, nodoGananciasAnio* nuevo){
    if(lista==NULL){
        lista=nuevo;
    }
    else{
        nuevo->siguiente=lista;
        lista=nuevo;
    }
    return lista;
}

nodoGananciasAnio* buscarUltimoAnio(nodoGananciasAnio* lista){
    while(lista!=NULL){
        lista=lista->siguiente;
    }
    return lista;
}

nodoGananciasAnio* agregarAnioGananciasFinal(nodoGananciasAnio* lista, nodoGananciasAnio* nuevo){
    if(lista==NULL){
        lista=nuevo;
    }
    else{
        nodoGananciasAnio* aux=buscarUltimo(lista);
        aux->siguiente=nuevo;
    }
    return lista;
}
