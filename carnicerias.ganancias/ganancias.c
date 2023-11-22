#include "ganancias.h"

//nodos
nodoGananciasAnio* inicLista()
{
    return NULL;
}


nodoGananciasAnio* crearNodo(ganancias dato)
{
    nodoGananciasAnio* aux=(nodoGananciasAnio*) malloc(sizeof(nodoGananciasAnio));
    aux->dato=dato;
    aux->siguiente=NULL;
    aux->anterior=NULL;
    return aux;
}

nodoGananciasAnio* agregarAnioGananciasPpio(nodoGananciasAnio* lista, nodoGananciasAnio* nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nuevo->siguiente=lista;
        nuevo->anterior=NULL;
        lista->anterior=nuevo;
        lista=nuevo;
    }
    return lista;
}

nodoGananciasAnio* buscarUltimoAnio(nodoGananciasAnio* lista)
{
    while(lista->siguiente!=NULL)
    {
        lista=lista->siguiente;
    }
    return lista;
}

nodoGananciasAnio* agregarAnioGananciasFinal(nodoGananciasAnio* lista, nodoGananciasAnio* nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nodoGananciasAnio* aux=buscarUltimoAnio(lista);
        nuevo->anterior=aux;
        aux->siguiente=nuevo;
    }
    return lista;
}

nodoGananciasAnio* insertarGananciasNodo(nodoGananciasAnio* lista, ganancias nuevo)
{
    if(lista==NULL)
    {
        lista=crearNodo(nuevo);
    }
    else
    {
        nodoGananciasAnio* aux=lista;
        nodoGananciasAnio* nuevoNodo=crearNodo(nuevo);
        while(aux->siguiente!=NULL && (aux->dato.anio<nuevo.anio || (aux->dato.idSucursal<=nuevo.idSucursal && aux->dato.anio==nuevo.anio))){
            aux=aux->siguiente;
        }
        if(aux->dato.anio==nuevo.anio && aux->dato.idSucursal==nuevo.idSucursal){
            sumarGanancias(aux->dato.arrayGanancias, nuevo.arrayGanancias);
            free(nuevoNodo);
        }
        else{
            if(aux->dato.anio>nuevo.anio || (aux->dato.anio==nuevo.anio && (aux->dato.idSucursal>nuevo.idSucursal))){
                if(aux->anterior!=NULL){
                    aux->anterior->siguiente=nuevoNodo;
                    nuevoNodo->anterior=aux->anterior;
                }
                else{
                    nuevoNodo->anterior=NULL;
                    lista=nuevoNodo;
                }
                nuevoNodo->siguiente=aux;
                aux->anterior=nuevoNodo;
            }
            else{
                aux->siguiente=nuevoNodo;
                nuevoNodo->anterior=aux;
                nuevoNodo->siguiente=NULL;
            }
        }
    }
    return lista;
}

nodoGananciasAnio* sumarGananciasNodo(nodoGananciasAnio* lista, nodoGananciasAnio* nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        sumarGanancias(lista->dato.arrayGanancias, nuevo->dato.arrayGanancias);
    }
    return lista;
}

nodoGananciasAnio* buscarPosAnio(nodoGananciasAnio* lista, int anio)
{
    while(lista->dato.anio!=anio && lista!=NULL)
    {
        lista=lista->siguiente;
    }

    if(lista==NULL)
    {
        lista=NULL;
    }
    return lista;
}

//arreglo
void inicArregloGanancias(int ganancias[MESES][DIAS])
{
    int diasEnMes[MESES]=DIAS_EN_MES;
    for(int i=0; i<MESES; i++)
    {
        for(int j=0; j<diasEnMes[i]; j++)
        {
            ganancias[i][j]=0;
        }
    }
}

//printeo
void mostrarTodasGanancias(nodoGananciasAnio* lista){
    while(lista!=NULL){
        printf("\t---ANIO %d---\n\n", lista->dato.anio);
         printf("--SUCURSAL %d--\n\n", lista->dato.idSucursal);
        mostrarGanancias(lista->dato.arrayGanancias);
        lista=lista->siguiente;
    }
}
void mostrarGananciasSucursal(nodoGananciasAnio* lista, int id){
    int flag=0;
    printf("\t---SUCURSAL %d---\n\n", id);
    while(lista!=NULL){
        if(lista->dato.idSucursal==id){
            flag=1;
            printf("--ANIO %d--\n", lista->dato.anio);
            mostrarGanancias(lista->dato.arrayGanancias);
        }
        lista=lista->siguiente;
    }
    if(flag==0){
        printf("LA SUCURSAL %d NO EXISTE.\n", id);
    }
}


void mostrarGananciasAnio(nodoGananciasAnio* lista, int anio){
    printf("\t---ANIO %d---\n\n", anio);
    while(lista!=NULL){
        if(lista->dato.anio==anio){
            printf("--SUCURSAL %d--\n\n", lista->dato.idSucursal);
            mostrarGanancias(lista->dato.arrayGanancias);
        }
        lista=lista->siguiente;
    }
}
void mostrarGanancias(int ganancias[MESES][DIAS])
{
    char nombreMes[20];
    int diasEnMes[MESES]=DIAS_EN_MES;
    int hayGanancias;
    for(int i=0; i<MESES; i++){
        hayGanancias=0;
        for(int j=0;j<diasEnMes[i];j++){
            if(ganancias[i][j]!=0){
                hayGanancias=1;
                break;
            }
        }

        if(hayGanancias==1){
            numeroAString(nombreMes, i+1);
            printf("GANANCIAS %s:\n", nombreMes);
            for(int j=0; j<diasEnMes[i]; j++){
                if(ganancias[i][j]!=0){
                printf("DIA %d: %d\n", j+1, ganancias[i][j]);
                }
            }
            printf("\n");
        }
    }
}

void numeroAString(char* nombreMes, int mes)
{
    switch(mes)
    {
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




//
void sumarGanancias(int ganancias[MESES][DIAS], const int nuevasGanancias[MESES][DIAS])
{
    int diasEnMes[MESES]=DIAS_EN_MES;
    for(int i=0; i<MESES; i++)
    {
        for(int j=0; j<diasEnMes[i]; j++)
        {
            ganancias[i][j]+=nuevasGanancias[i][j];
        }
    }
}


///
int precioPorVenta(int precio, int ventas)
{

    return (precio*ventas);
}



//func archivo
void crearArchivoGanancias(nodoGananciasAnio* lista)
{
    FILE* archivo=fopen(nombreArchivoGanancias, "ab");
    if(archivo==NULL)
    {
        printf("asd");
    }
    else
    {
        ganancias aux;
        while(lista!=NULL)
        {
            aux=lista->dato;
            fwrite(&aux, sizeof(ganancias), 1, archivo);
        }
        fclose(archivo);
    }
}


nodoGananciasAnio* archivoToLista()
{
    nodoGananciasAnio* lista=inicLista();
    FILE* archivo=fopen(nombreArchivoGanancias, "rb");
    if(archivo==NULL)
    {
        printf("Error archivo\n\n");
    }
    else
    {
        ganancias aux;
        while(fread(&aux, sizeof(ganancias), 1, archivo)==1)
        {
            lista=insertarGananciasNodo(lista, aux);
        }
        fclose(archivo);
    }
    return lista;
}

void obtenerFecha(char fechaVenta[11], int *anio, int *mes, int *dia)
{
    sscanf(fechaVenta, "%d-%d-%d", anio, mes, dia);
}


nodoGananciasAnio* ventasToLista(nodoGananciasAnio* lista, int ventas, int precio, int idSucursal, char fechaVenta[11])
{
    ganancias aux=ventasToGanancias(ventas, precio, idSucursal, fechaVenta);
    lista=insertarGananciasNodo(lista, aux);
    return lista;

}

ganancias ventasToGanancias(int ventas, int precio, int idSucursal, char fechaVenta[11])
{
    int profit=precioPorVenta(precio, ventas);
    int anio, mes, dia;
    ganancias aux;
    inicArregloGanancias(aux.arrayGanancias);
    obtenerFecha(fechaVenta, &anio, &mes, &dia);
    aux.anio=anio;
    aux.arrayGanancias[mes-1][dia-1]=profit;
    aux.idSucursal=idSucursal;
    return aux;
}

void gananciasABarchivo(int ventas, int precio, int idSucursal, char fechaVenta[11])
{
    FILE * archivo=fopen(nombreArchivoGanancias, "ab");
    if(archivo)
    {
        ganancias aux=ventasToGanancias(ventas, precio, idSucursal, fechaVenta);
        fwrite(&aux, sizeof(ganancias), 1, archivo);
        fclose(archivo);
    }
}

void sumarGananciasArchivo(int ventas, int precio, int idSucursal, char fechaVenta[11]){
    FILE* archivo=fopen(nombreArchivoGanancias, "rb+");
    if(archivo==NULL){
        printf("Error archivo ganancias.\n");
    }
    else{
        ganancias registro;
        ganancias aux=ventasToGanancias(ventas, precio, idSucursal, fechaVenta);
        int flag=buscarEnArchivoGanancias(archivo, aux);
        if(flag){
        rewind(archivo);
            while (fread(&registro, sizeof(ganancias), 1, archivo) == 1) {
                if (registro.anio == aux.anio && registro.idSucursal == aux.idSucursal) {
                    sumarGanancias(registro.arrayGanancias, aux.arrayGanancias);
                    fseek(archivo, -sizeof(ganancias), SEEK_CUR);
                    fwrite(&registro, sizeof(ganancias), 1, archivo);
                    break;
                }
            }
        }
        else{
            fseek(archivo, 0, SEEK_END);
            fwrite(&aux, sizeof(ganancias), 1, archivo);
        }

        fclose(archivo);

}
}

int buscarEnArchivoGanancias(FILE* archivo, ganancias dato){
    ganancias regActual;
    while(fread(&regActual, sizeof(ganancias), 1, archivo)==1){
        if(regActual.anio==dato.anio && regActual.idSucursal==dato.idSucursal){
            return 1;
        }
    }
    return 0;
}

void crearArchivoGananciasConVentas(){
    FILE* archivoVentas=fopen(nombreArchivoVentas, "rb");
    if(archivoVentas){
        StRegistroventas ventas;
        ganancias profit;
        while(fread(&ventas, sizeof(StRegistroventas), 1, archivoVentas)==1){
            gananciasABarchivo(ventas.venta, ventas.precioPorKilo, ventas.idDSuc, ventas.fechaVenta);
        }
        fclose(archivoVentas);
    }
}

//func aux ventas
StRegistroventas cargarVentas(){
    StRegistroventas aux;
    printf("Ingrese id sucursal: ");
    scanf("%d", &aux.idDSuc);
    fflush(stdin);
    printf("Ingrese fecha de la venta (AAAA-mm-DD): ");
    gets(aux.fechaVenta);
    printf("Precio: ");
    scanf("%d", &aux.precioPorKilo);
    printf("Ventas: ");
    scanf("%d", &aux.venta);
    return aux;
}

void menuGanancias(){
    int seleccion=99;
    nodoGananciasAnio* lista=inicLista();
    while(seleccion!=0){
        system("cls");
        printf("\t--SISTEMA GANANCIAS--\n\n");
        printf("1)Ver archivo\n");
        printf("2)Sumar ventas a archivo\n");
        printf("3)Ver ganancias de una sucursal\n");
        printf("4)Ver ganancias de un año\n");
        printf("5)Crear archivo ganancias.\n");

        seleccion=getch()-'0';
        system("cls");
        switch(seleccion){
        case 1:
            lista=archivoToLista();
            mostrarTodasGanancias(lista);
            free(lista);
            break;
        case 2: ;
            StRegistroventas ventas=cargarVentas();
            sumarGananciasArchivo(ventas.venta, ventas.precioPorKilo, ventas.idDSuc, ventas.fechaVenta);
            break;
        case 3:
            lista=archivoToLista();
            int sucursal;
            printf("Ingrese num de sucursal: ");
            scanf("%d", &sucursal);
            mostrarGananciasSucursal(lista, sucursal);
            break;
        case 4:
            lista=archivoToLista();
            int anio;
            printf("Ingrese anio: ");
            scanf("%d", &anio);
            mostrarGananciasAnio(lista, anio);
            break;
        case 5:
            crearArchivoGananciasConVentas();
            break;
        case 0:
            break;
            default:
                printf("Seleccion incorrecta.\n");
                break;
        }
        system("pause");
    }
}
