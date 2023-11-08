#include <gananciasD.h>

nodoGananciasDia* inicGananciasDia(){
    return NULL;
}

nodoGananciasDia* crearGananciasDia(gananciasDia dato){
    nodoGananciasDia* aux=(nodoGananciasDia*) malloc(sizeof(nodoGananciasDia));
    aux->dato=dato;
    aux->sigMes=NULL;
    return aux;
}

nodoGananciasDia* agregarPpioGananciasDia(nodoGanancias* listaDias, nodoGananciasDia* nuevo){
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

nodoGananciasMeses* agregarFinalGananciasDia(nodoGananciasDia* listaDias, nodoGananciasDia* nuevo){
    if(listaDias==NULL){
        listaDias=nuevo;
    }
    else{
        nodoGananciasDia* aux=listaDias;
        aux=buscarUltimo(aux);
        aux->sigMes=nuevo;
    }
    return listaDias;
}

nodoGananciasDia* sumarGananciasDia(nodoGananciasDia* listaDias, gananciasDia dato){
    if(listaDias==NULL){
        listaDias=crearGananciasDia(listaDias, dato);
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
            listaDias=agregarPpioGananciasDia(listaDias, crearGananciasDia(nuevo));
        }
        else{
            if(dato.dia==listaDias->dato.dia){
                listaDias=sumarGananciasDia(listaDias, dato);
            }
            else{
                listaDias=agregarFinalGananciasDia(listaDias, crearGananciasDia(nuevo));
            }
        }
    }
    return listaDias;
}
