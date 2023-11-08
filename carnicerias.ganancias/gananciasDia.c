#include "ganancias.h"

nodoGananciasDia* inicListaDias(){
    return NULL;
}

nodoGananciasDia* crearGananciasDia(gananciasDia dato){
    nodoGananciasDia* aux=(nodoGananciasDia*) malloc(sizeof(nodoGananciasDia));
    aux->dato=dato;
    aux->sigDia=NULL;
    return aux;
}

nodoGananciasDia* agregarPpioGananciasDia(nodoGananciasDia* listaDias, nodoGananciasDia* nuevo){
    if(listaDias==NULL){
        listaDias=nuevo;
    }
    else{
        nuevo->sigDia=listaDias;
        listaDias=nuevo;
    }
    return listaDias;
}
nodoGananciasDia* buscarUltimo(nodoGananciasDia* listaDias){
    while(listaDias!=NULL){
        listaDias=listaDias->sigDia;
    }
    return listaDias;
}

nodoGananciasDia* buscarPorDia(nodoGananciasDia* listaDias, int diaBuscado){
    if(listaDias==NULL){
        return NULL;
    }
    if(listaDias->dato.dia==diaBuscado){
        return listaDias;
    }
    else{
        listaDias=buscarPorDia(listaDias->sigDia, diaBuscado);
    }
    return listaDias;
}

nodoGananciasDia* agregarFinalGananciasDia(nodoGananciasDia* listaDias, nodoGananciasDia* nuevo){
    if(listaDias==NULL){
        listaDias=nuevo;
    }
    else{
        nodoGananciasDia* aux=listaDias;
        aux=buscarUltimo(aux);
        aux->sigDia=nuevo;
    }
    return listaDias;
}

nodoGananciasDia* sumarGananciasDia(nodoGananciasDia* listaDias, gananciasDia dato){
    if(listaDias==NULL){
        listaDias=crearGananciasDia(dato);
    }
    else{
        listaDias=buscarPorDia(listaDias, dato.dia);
        listaDias->dato.ganancias+=dato.ganancias;
    }
    return listaDias;
}

nodoGananciasDia* insertarGananciasDia(nodoGananciasDia* listaDias, gananciasDia dato){
    if(listaDias==NULL){
        listaDias=crearGananciasDia(dato);
    }
    else{
        if(dato.dia<listaDias->dato.dia){
            listaDias=agregarPpioGananciasDia(listaDias, crearGananciasDia(dato));
        }
        else{
            if(dato.dia==listaDias->dato.dia){
                listaDias=sumarGananciasDia(listaDias, dato);
            }
            else{
                listaDias=agregarFinalGananciasDia(listaDias, crearGananciasDia(dato));
            }
        }
    }
    return listaDias;
}


void mostrarGananciasUnDia(gananciasDia dato){
    printf("DIA %d: $%d\n", dato.dia, dato.ganancias);
}

void mostrarGananciasDias(nodoGananciasDia* listaDias){
    while(listaDias!=NULL){
        mostrarGananciasUnDia(listaDias->dato);
        listaDias=listaDias->sigDia;
    }
}
