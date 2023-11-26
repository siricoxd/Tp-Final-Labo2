#include "ganancias.h"

//nodos
nodoGananciasAnio* inicListaGanancias()
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

void mostrarTodasGananciasBajas(nodoGananciasAnio* lista){
    while(lista!=NULL){
        if(lista->dato.alta==0){
            printf("\t---ANIO %d---\n\n", lista->dato.anio);
            printf("--SUCURSAL %d--\n\n", lista->dato.idSucursal);
            mostrarGanancias(lista->dato.arrayGanancias);
        }
        lista=lista->siguiente;
    }
}
void mostrarTodasGanancias(nodoGananciasAnio* lista){
    while(lista!=NULL){
        if(lista->dato.alta==1){
            if(lista->anterior==NULL || lista->anterior->dato.anio!=lista->dato.anio){
                printf("\t---ANIO %d---\n\n", lista->dato.anio);
            }
            printf("--SUCURSAL %d--\n\n", lista->dato.idSucursal);
            mostrarGanancias(lista->dato.arrayGanancias);
        }
        lista=lista->siguiente;
    }
}
void mostrarGananciasSucursal(nodoGananciasAnio* lista, int id){
    int flag=0;
    printf("\t---SUCURSAL %d---\n\n", id);
    while(lista!=NULL){
        if(lista->dato.idSucursal==id){
            if(lista->dato.alta==1){
                flag=1;
                printf("--ANIO %d--\n", lista->dato.anio);
                mostrarGanancias(lista->dato.arrayGanancias);
            }
        }
        lista=lista->siguiente;
    }
    if(flag==0){
        printf("LA SUCURSAL %d NO EXISTE O HA SIDO DADA DE BAJA.\n", id);
    }
}


void mostrarGananciasAnio(nodoGananciasAnio* lista, int anio){
    printf("\t---ANIO %d---\n\n", anio);
    while(lista!=NULL){
        if(lista->dato.anio==anio){
            if(lista->dato.alta==1){
                printf("--SUCURSAL %d--\n\n", lista->dato.idSucursal);
                mostrarGanancias(lista->dato.arrayGanancias);
            }
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
    nodoGananciasAnio* lista=inicListaGanancias();
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
    sscanf(fechaVenta, "%d/%d/%d", dia, mes, anio);
}


nodoGananciasAnio* ventasToLista(nodoGananciasAnio* lista, StRegistroventas ventas)
{
    ganancias aux=ventasToGanancias(ventas);
    lista=insertarGananciasNodo(lista, aux);
    return lista;

}
int precioPorVenta(int precio, int ventas)
{
    return (precio*ventas);
}

ganancias ventasToGanancias(StRegistroventas ventas){
    int profit=precioPorVenta(ventas.precioPorKilo, ventas.venta);
    int anio, mes, dia;
    ganancias aux;
    inicArregloGanancias(aux.arrayGanancias);
    obtenerFecha(ventas.fechaVenta, &anio, &mes, &dia);
    aux.anio=anio;
    aux.arrayGanancias[mes-1][dia-1]=profit;
    aux.idSucursal=ventas.idDSuc;
    aux.alta=1;
    return aux;
}


void sumarGananciasArchivo(StRegistroventas ventas){
    FILE* archivo=fopen(nombreArchivoGanancias, "rb+");
    if(archivo==NULL){
        printf("Error archivo ganancias.\n");
    }
    else{
        ganancias registro;
        ganancias aux=ventasToGanancias(ventas);
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

void gananciasABarchivo(StRegistroventas ventas) {
    FILE* archivo=fopen(nombreArchivoGanancias, "ab");
    if(archivo){
        ganancias profit = ventasToGanancias(ventas);
        if(fwrite(&profit, sizeof(ganancias), 1, archivo)!= 1){
            printf("Error al escribir en el archivo de ganancias.\n");
        }
        fclose(archivo);
    }
}

void crearArchivoGananciasConVentas(){
    FILE* archivoVentas=fopen(nombreArchivoVentas, "rb");
    if(archivoVentas){
        StRegistroventas ventas;
        while(fread(&ventas, sizeof(StRegistroventas), 1, archivoVentas)==1){
            if(buscaEnArchivoGanancias(nombreArchivoGanancias, ventas.fechaVenta)==-1){
                gananciasABarchivo(ventas);
            }
            else{
                sumarGananciasArchivo(ventas);
            }
        }
        fclose(archivoVentas);
    }
}


int buscaEnArchivoGanancias(char archivoGanancia[],char fecha[])
{
    FILE *archi=fopen(archivoGanancia,"rb");
    ganancias flag;
    flag.anio=-1;
    int anio,mes,dia;
    ganancias aux;
    int existe=0;

    obtenerFecha(fecha,&anio,&mes,&dia);
    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(ganancias),1,archi)>0 && flag.anio==-1)
        {
            if(aux.anio==anio)
            {
                flag=aux;
            }
        }
        fclose(archi);
    }
    else
    {
        return -1;
    }

    if(flag.anio!=-1){
            if(flag.arrayGanancias[mes-1][dia-1]>0)
            {
                existe=1;
            }
    }


    return existe;
}

void altaBajaGananciasSucursal(int sucursal, int estado){
    FILE* archivo=fopen(nombreArchivoGanancias, "rb+");
    if(archivo){
        ganancias aux;
        long int pos=0;
        while(fread(&aux, sizeof(ganancias), 1, archivo)==1){
            if(aux.idSucursal==sucursal && aux.alta!=estado){
                aux.alta=estado;
                fseek(archivo, pos * sizeof(ganancias), SEEK_SET);
                fwrite(&aux, sizeof(ganancias), 1, archivo);

            }
            pos=ftell(archivo);
        }
        fclose(archivo);
    }
    else{
    printf("error archivo ganancias.\n");
    }
}

void altaBajaGananciasAnio(int anio, int estado){
    FILE *archivo=fopen(nombreArchivoGanancias, "rb+");
    if(archivo){
        ganancias aux;
        long int pos=0;
        while(fread(&aux, sizeof(ganancias), 1, archivo)==1){
            if(aux.anio==anio && aux.alta!=estado){
                aux.alta=estado;
                fseek(archivo, pos * sizeof(ganancias), SEEK_SET);
                fwrite(&aux, sizeof(ganancias), 1, archivo);
            }
            pos=ftell(archivo);
        }
        fclose(archivo);
    }else{
    printf("error archivo ganancias.\n");
    }
}

int altaBajaGanancias(int sucursal, int anio, int estado){
    FILE* archivo=fopen(nombreArchivoGanancias, "rb+");
    int exito=0;
    if(archivo){
        ganancias aux;
        aux.anio=anio;
        aux.idSucursal=sucursal;
        int flag=buscarEnArchivoGanancias(archivo, aux);
        if(flag){
            exito=1;
            rewind(archivo);
            while(fread(&aux, sizeof(ganancias), 1, archivo)==1){
                if (aux.anio == anio && aux.idSucursal == sucursal) {
                        aux.alta=estado;
                        fseek(archivo, (-1) * sizeof(ganancias), SEEK_CUR);
                        fwrite(&aux, sizeof(ganancias), 1, archivo);
                        break;
                    }
            }
        }
        else{
            printf("No se encontro ganancias de %d en la sucursal %d\n", anio, sucursal);
        }
        fclose(archivo);
    }
    else{
        printf("error archivo ganancias.\n");
    }
    return exito;
}


void reemplazarDiaGanancias(int sucursal, char fecha[], int suma){
    FILE* archivo=fopen(nombreArchivoGanancias, "rb+");
    if(archivo){
        int anio, mes, dia, flag=0;
        obtenerFecha(fecha, &anio, &mes, &dia);
        ganancias aux;
        long int pos=0;
        while(fread(&aux, sizeof(ganancias), 1, archivo)==1){
            if(sucursal==aux.idSucursal && anio==aux.anio){
                flag=1;
                if (mes >= 1 && mes <= MESES && dia >= 1 && dia <= DIAS){
                    aux.arrayGanancias[mes-1][dia-1]=suma;
                    fseek(archivo, pos * sizeof(ganancias), SEEK_SET);
                    fwrite(&aux, sizeof(ganancias), 1, archivo);
                    break;
                }
                else{
                    printf("Dia y mes no validos\n\n");
                }
            }
            pos=ftell(archivo);
        }
        if(flag==0){
            printf("No se encontro sucursal o fecha ingresada.\n");
        }
        fclose(archivo);
    }
    else{
        printf("error archivo ganancias\n");
    }
}
