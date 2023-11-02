#ifndef LISTASSUCUSRSALES_H_INCLUDED
#define LISTASSUCUSRSALES_H_INCLUDED


typedef struct
{
    char localidad[30];
    char direccion[30];
    int idDeLocal;
    int activo;//1 alta,0 baja
} locales;

typedef struct nodoLocales
{
    locales dato;
    struct  nodoLocales *siguiente;
} nodoLocales;

typedef struct
{
    char NombreProvincia[30];
    int idProvincia;
    int activo;//1 alta,0 baja
    nodoLocales* listaDelocales;

} provincia;

typedef struct
{
    char provincia[30];
    int idProvincia;
    int activoProv;
    char localidad[30];
    char direccion[30];
    int idLocal;
    int activoLocal;

}registroArchivoLocales;


///prototipado

///listas
//crear
nodoLocales*crearNodoLocales(locales dato);
nodoLocales* inicLista(nodoLocales*lista);
//mostrar
void mostrarNodo(nodoLocales*lista);
void mostrarLista(nodoLocales*lista);
//buscar
nodoLocales*buscarUltimo(nodoLocales*lista);
nodoLocales*buscarNodo(nodoLocales*lista,int id);
//agregar
nodoLocales*agregarAlPpioLocales(nodoLocales*lista,nodoLocales*nuevo);
nodoLocales*agregarAlFinalLocales(nodoLocales*lista,nodoLocales*nuevo);
nodoLocales*agregarEnOrdenLocales(nodoLocales*lista,nodoLocales*nuevoNodo);
//elimnar
nodoLocales* EliminarLocal(nodoLocales*lista,int objetivo);


///mostrar y cargar
//cargar
provincia cargarProvincia();
int cargarArreglosProvincia(provincia ar[],int dim,int validos);
registroArchivoLocales cargarRegistroLocales();
locales pasarRegistrosToLocal(registroArchivoLocales dato);
locales cargarLocales();
//mostrar
void mostrarProvincia(provincia aux);
void mostrarAr(provincia ar[],int validos);
void mostrarLocal(locales aux);

//sacar provincia
void desctivarProvincia(provincia ar[],int validos,int id);
//buscar prov
int buscarPosProvincia(provincia ar[],int id,int validos);
//alta
int alta(provincia ar[],registroArchivoLocales dato,int validos);

#endif // LISTASSUCUSRSALES_H_INCLUDED
