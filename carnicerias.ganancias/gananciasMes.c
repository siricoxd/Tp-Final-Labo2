#include <ganancias.h>

nodoGananciasMes* inicGananciasMes*(){
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

nodoGananciaMes* insertarGananciasMes(nodoGananciasMes* listaMes, gananciasMes dato){
    if(listaMes==NULL) listaMes=crearGananciasMes(dato);
    else{
        if(dato.mes<listaMes->dato.mes){
            listaMes=agregarPpioGananciasMes(listaMes, crearGananciasMes(dato));
        }
        else{
            if(dato.mes==listaMes->dato.mes){
                sumarGananciasMes(listMes, dato);
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
        while(dato.listaDias!=NULL){
            sumarGananciasDia(listaMes->dato.listaDias, dato.listaDias->dato);
            dato.listaDias=dato.listaDias->sigDia;
        }
    }
    return listaMes;
}
