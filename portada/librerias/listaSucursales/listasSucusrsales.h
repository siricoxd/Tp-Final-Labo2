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
nodoLocales* inicLista();
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


///manejo provincias y locales
//cargar
provincia cargarProvincia();
int cargarArreglosProvincia(provincia ar[],registroArchivoLocales dato,int dim,int validos);
registroArchivoLocales cargarRegistroLocales();
locales pasarRegistrosToLocal(registroArchivoLocales dato);
locales cargarLocales();
//mostrar
void mostrarProvincia(provincia aux);
void mostrarAr(provincia ar[],int validos);
void mostrarLocal(locales aux);
void recorrerYMostrar(provincia ar[],int validos,int pos);
void recorrerYMostrarDesactivados(provincia ar[],int validos,int pos);
void recorrerYMostrarTodos(provincia ar[],int validos,int pos);
void mostrarTodo(provincia ar[],int validos);
void mostrarUnaProvincia(provincia ar);

//activar y desactivar provincia
void desactivarProvincia(provincia ar[],int pos);
void activarProvincia(provincia ar[],int pos);
void activarLocal(provincia ar[],int id,int pos);
void descativarLocal(provincia ar[],int id,int pos);
//buscar prov
int buscarPosProvincia(provincia ar[],int id,int validos);
void provincias();
//alta
int alta(provincia ar[],registroArchivoLocales dato,int validos);
//archivos
int descargarArchivo(provincia ar[],int validos,int dim);
int cargarArchivo(int dim);
int cantidadDeRegistros();
#endif // LISTASSUCUSRSALES_H_INCLUDED
