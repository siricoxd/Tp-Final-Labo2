#include "ganancias.h"

//nodos
nodoGananciasAnio* inicLista(){
    return NULL;
}

nodoGananciasAnio* asignarMemoriaNodo(){ //para poder inicializar el arreglo dentro del nodo, pq si es NULL no se puede
    nodoGananciasAnio* aux=(nodoGananciasAnio*) malloc(sizeof(nodoGananciasAnio));
    return aux;
}


nodoGananciasAnio* crearNodo(ganancias dato){
    nodoGananciasAnio* aux=asignarMemoriaNodo();
    aux->dato=dato;
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
        nodoGananciasAnio* aux=buscarUltimoAnio(lista);
        aux->siguiente=nuevo;
    }
    return lista;
}

nodoGananciasAnio* insertarNodo(nodoGananciasAnio* lista, nodoGananciasAnio* nuevo){
    if(lista==NULL){
        lista=nuevo;
    }
    else{
        if(nuevo->dato.anio > (buscarUltimoAnio(lista))->dato.anio){
            lista=agregarAnioGananciasFinal(lista, nuevo);
        }
        else{
            if(nuevo->dato.anio < lista->dato.anio){
                lista=agregarAnioGananciasPpio(lista, nuevo);
            }
            else{
                nodoGananciasAnio* aux=lista;
                while((aux->siguiente)->dato.anio < nuevo->dato.anio){
                    aux=aux->siguiente;
                }
                if(aux->siguiente->dato.anio==nuevo->dato.anio){
                    aux->siguiente=sumarGananciasNodo(aux->siguiente, nuevo);
                    free(nuevo);
                }
                else{
                    nodoGananciasAnio* sig=aux->siguiente;
                    aux->siguiente=nuevo;
                    nuevo->siguiente=sig;
                }
            }
        }
    }
    return lista;
}

nodoGananciasAnio* sumarGananciasNodo(nodoGananciasAnio* lista, nodoGananciasAnio* nuevo){
    if(lista==NULL){
        lista=nuevo;
    }
    else{
        sumarGanancias(lista->dato.ganancias, nuevo->dato.ganancias);
    }
    return lista;
}

nodoGananciasAnio* buscarPosAnio(nodoGananciasAnio* lista, int anio){
    while(lista->dato.anio!=anio && lista!=NULL){
        lista=lista->siguiente;
    }

    if(lista==NULL){
        lista=NULL;
    }
    return lista;
}

//arreglo
void inicArregloGanancias(int ganancias[MESES][DIAS]){
    for(int i=0;i<MESES;i++){
        for(int j=0;j<DIAS;j++){
            ganancias[i][j]=0;
        }
    }
}

//lo hago asi nomas, pero queda feo xd
void mostrarGananciasAnio(int ganancias[MESES][DIAS]){
    char nombreMes[20];
    for(int i=0;i<MESES;i++){
        numeroAString(nombreMes, i+1);
        printf("GANANCIAS %s:\n\n", nombreMes);
        for(int j=0;j<DIAS;j++){
            printf("%d\n", ganancias[i][j]);
        }
    }
}

void numeroAString(char* nombreMes, int mes){
    switch(mes){
    case 1:
        strcpy(nombreMes, "ENERO");
        break;
    case 2:
        strcpy(nombreMes, "FEBRERO");
        break;
    case 3:
        strcpy(nombreMes, "MARZO");
        break;
    case 4:
        strcpy(nombreMes, "ABRIL");
        break;
    case 5:
        strcpy(nombreMes, "MAYO");
        break;
    case 6:
        strcpy(nombreMes, "JUNIO");
        break;
    case 7:
        strcpy(nombreMes, "JULIO");
        break;
    case 8:
        strcpy(nombreMes, "AGOSTO");
        break;
    case 9:
        strcpy(nombreMes, "SEPTIEMBRE");
        break;
    case 10:
        strcpy(nombreMes, "OCTUBRE");
        break;
    case 11:
        strcpy(nombreMes, "NOVIEMBRE");
        break;
    case 12:
        strcpy(nombreMes, "DICIEMBRE");
        break;
    default:
        strcpy(nombreMes, "MES NO VALIDO");
        break;
    }
}

//manera 1
void sumarGananciaADia(int ganancias[MESES][DIAS], int mes, int dia, int sumaGanancia){
    if(mes<=12 && mes>=1 && dia>=1 && dia<=31){
        ganancias[mes][dia]+=sumaGanancia;
    }
    else{
        printf("xd");
    }
}

//manera 2
void sumarGanancias(int ganancias[MESES][DIAS], int nuevasGanancias[MESES][DIAS]){
    for(int i=0;i<MESES;i++){
        for(int j=0;j<DIAS;j++){
            ganancias[i][j]+=nuevasGanancias[i][j];
        }
    }
}


///func datos




/*ganancias intToGanancias(int ganancias[MESES][DIAS], int anio){
    ganancias aux;
    memccpy(aux.ganancias, ganancias, sizeof(aux.ganancias));
    aux.anio=anio;
    return aux;
}*/


///func usuario
/*ganancias cargarGananciasADia(ganancias dato){
    int fecha[2], plata;
    printf("Ingrese num de mes: ");
    scanf("%d", fecha[0]);
    printf("Ingrese dia: ");
    scanf("%d", fecha[1]);
    printf("Ingrese dinero a sumar: ");
    scanf("%d", &plata);
    sumarGananciaADia(dato.ganancias, fecha, plata);
    return dato;
}

ganancias cargarAnio(){
    ganancias aux;
    int anio;
    printf("Ingrese anio: ");
    scanf("&d", &anio);
    aux.anio=anio;
    return aux;
}*/


///
int precioPorVenta(int precio, int ventas){
    return precio*ventas;
}



//func archivo
void listaToArchivo(nodoGananciasAnio* lista){
    FILE* archivo=fopen(nombreArchivoGanancias, "ab");
    if(archivo==NULL){
        printf("asd");
    }
    else{
        ganancias aux;
        while(lista!=NULL){
            aux=lista->dato;
            fwrite(&aux, sizeof(ganancias), 1, archivo);
        }
        fclose(archivo);
    }
}


nodoGananciasAnio* archivoToLista(){
    FILE* archivo=fopen(nombreArchivoGanancias, "rb");
    if(archivo==NULL){
        printf("Error archivo\n\n");
    }
    else{
        ganancias aux;
        nodoGananciasAnio* lista=inicLista();
        nodoGananciasAnio* aux2=inicLista();
        while(fread(&aux, sizeof(ganancias), 1, archivo)){
            aux2=crearNodo(aux);
            insertarNodo(lista, aux2);
        }
        fclose(archivo);
    }
}

void obtenerFecha(char fechaVenta[11], int *anio, int *mes, int *dia) {
    sscanf(fechaVenta, "%d-%d-%d", anio, mes, dia);
}


nodoGananciasAnio* ventasToLista(nodoGananciasAnio* lista, int ventas, int precio, char fechaVenta[11]){
    ganancias aux=ventasToGanancias(ventas, precio, fechaVenta);
    nodoGananciasAnio* nodoNuevo=crearNodo(aux);
    lista=insertarNodo(lista, nodoNuevo);
    return lista;

}

ganancias ventasToGanancias(int ventas, int precio, char fechaVenta[11]){
    int profit=precioPorVenta(precio, ventas);
    int anio, mes, dia;
    ganancias aux;
    obtenerFecha(fechaVenta, &anio, &mes, &dia);
    ganancias.anio=anio;
    gananaias[mes-1][dia-1]=profit;
    return ganancias;
}

void gananciasABarchivo(int ventas, int precio, char fechaVenta[11]){
    FILE * archivo=fopen(nombreArchivoGanancias, "ab");
    if(archivo){
        ganancias aux=ventasToGanancias(ventas, precio, fechaVenta);
        fwrite(&aux, sizeof(ganancias), 1, archivo);
        fclose(archivo);
    }
}
