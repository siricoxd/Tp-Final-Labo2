#include "ganancias.h"

nodoGananciasMes* inicListaMes(){
    return NULL;
}

nodoGananciasMes* crearGananciasMes(gananciasMes dato){
    nodoGananciasMes* aux=(nodoGananciasMes*) malloc(sizeof(nodoGananciasMes));
    aux->dato=dato;
    aux->sigMes=NULL;
}

nodoGananciasMes* agregarPpioGananciasMes(nodoGananciasMes* listaMes, nodoGananciasMes* nuevo){
    if(listaMes==NULL) listaMes=nuevo;
    else{
        nuevo->sigMes=listaMes;
        listaMes=nuevo;
    }
    return listaMes;
}

nodoGananciasMes* agregarFinalGananciasMes(nodoGananciasMes* listaMes, nodoGananciasMes* nuevo){
    if(listaMes==NULL) listaMes=nuevo;
    else{
        nodoGananciasMes* aux=listaMes;
        aux=buscarUltimoMes(aux);
        aux->sigMes=nuevo;
    }
    return listaMes;
}

nodoGananciasMes* buscarUltimoMes(nodoGananciasMes* listaMes){
    while(listaMes!=NULL){
        listaMes=listaMes->sigMes;
    }
    return listaMes;
}

nodoGananciasMes* insertarGananciasMes(nodoGananciasMes* listaMes, gananciasMes dato){
    if(listaMes==NULL) listaMes=crearGananciasMes(dato);
    else{
        if(dato.mes<listaMes->dato.mes){
            listaMes=agregarPpioGananciasMes(listaMes, crearGananciasMes(dato));
        }
        else{
            if(dato.mes==listaMes->dato.mes){
                sumarGananciasMes(listaMes, dato);
            }
            else{
                listaMes=agregarFinalGananciasMes(listaMes, crearGananciasMes(dato));
            }
        }
    }
    return listaMes;
}

nodoGananciasMes* sumarGananciasMes(nodoGananciasMes* listaMes, gananciasMes dato){
    if(listaMes==NULL) listaMes=crearGananciasMes(dato);
    else{
        nodoGananciasDia* diaActual=dato.listaDias;
        while(diaActual!=NULL){
            listaMes->dato.listaDias=sumarGananciasDia(listaMes->dato.listaDias,diaActual->dato);
            diaActual=diaActual->sigDia;
        }
    }
    return listaMes;
}

void mostrarGananciasMes(gananciasMes dato){
    printf("MES %d:\n", dato.mes);
    mostrarGananciasDias(dato.listaDias);
}

void mostrarGanancias(nodoGananciasMes* listaMes){
    while(listaMes!=NULL){
        mostrarGananciasMes(listaMes->dato);
        listaMes=listaMes->sigMes;
    }
}
