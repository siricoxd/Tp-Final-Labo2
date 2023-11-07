#include <ganancias.h>

nodoGananciasDia* inicGananciasMes(){
    return NULL;
}

nodoGananciasDia* crearGananciasMes(ganancias dato){
    nodoGananciasDia* aux=(nodoGananciasDia*) malloc(sizeof(nodoGananciasDia));
    aux->dato=dato;
    aux->sigMes=NULL;
    return aux;
}

nodoGananciasDia* agregarPpioGananciasMes(nodoGanancias* listaDias, nodoGananciasDia* nuevo){
    if(listaDias==NULL){
        listaDias=nuevo;
    }
    else{
        nuevo->siguiente=listaDias;
        listaDias=nuevo;
    }
    return listaDias;
}
nodoGananciasDia* buscarUltimo(nodoGananciasDia* listaDias){
    while(listaDias!=NULL){
        listaDias=listaDias->siguiente;
    }
    return listaDias;
}
nodoGananciasMeses* agregarFinalGananciasMes(nodoGananciasDia* listaDias, nodoGananciasDia* nuevo){
    if(listaDias==NULL){
        listaDias=nuevo;
    }
    else{
        listaDias=buscarUltimo(listaDias);
        listaDias->sigMes=nuevo;
    }
    return listaDias;
}

nodoGananciasDia* insertarGananciasMes(nodoGananciasDia* listaDias, ganancias dato){
    if(listaDias==NULL){
        listaDias=crearGananciasMes(dato);
    }
    else{
        if(dato.dia<listaDias->dato.dia){
            listaDias=agregarPpioGananciasMes(listaDias, crearGananciasMes(nuevo));
        }
        else{
            if(dato.dia==listaDias->dato.dia){
                //sumar ganancias
            }
            else{
                agregarFinalGananciasMes(listaDias, crearGananciasMes(nuevo));
            }
        }
    }
}


