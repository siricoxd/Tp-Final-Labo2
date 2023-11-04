#ifndef LISTASPRODUCTOS_H_INCLUDED
#define LISTASPRODUCTOS_H_INCLUDED





typedef struct
{
    char nombreDeProductos[40];
    int precioPorKilo;
    int stock;
    int id;
    int activoProd;
} productos;

typedef struct nodoProductos
{
    productos dato;
    struct nodoProductos *siguiente;

} nodoProductos;
typedef struct
{
    char nombreDeCategoria[40];
    int idCategoria;
     int activoCata;
    nodoProductos *lista;
} catalogo;

typedef struct
{

    char nombreDeCategoria[40];
    int idCategoria;

    char nombreDeProductos[40];
    int precioPorKilo;
    int stock;
    int id;
    int activoCat;
    int activoProd;


} REGISTROA;
//manejo de listas
nodoProductos * inicListaProduc();
nodoProductos *crearNuevonodoProductos(productos dato );
nodoProductos* agregarNuevonodoProductosAlPLista(nodoProductos*lista,nodoProductos *nuevonodoProductos);

//manejo de arreglo de listas
int buscaEnCatalogo(catalogo arreglo[],int validos,REGISTROA dato);
int altaCatalogo(catalogo arreglo[],int validos,REGISTROA dato);
int agregarALCatalogo(catalogo arreglo[],int validos,REGISTROA dato);
REGISTROA cargaRegistro();
productos pasarDeRegistroCatAPro(REGISTROA origen);

//cargaDeCatalogo
int  cargaCatalogo(catalogo arreglo[],int dim,int validos);
productos cargaDeProductos();
catalogo cargaDeUnaCateogoria();
void guardarUltimoId(char archivo[],int ultimoId);
int leerUltimoId(char archivo[]);

//FUNCIONES DE MUESTRA
void muestraDeCatalogo(catalogo A[],int validos);
void muestraUnCatalogo(catalogo A);
void muestraLISTA(nodoProductos *lista);

//CARGA DE ARCHIVOS
void pasarDeArregloDeLisAArchivo(catalogo arreglo,FILE* archiC);
REGISTROA cambioDeEstrucCatalARegistro(catalogo origen);
void guardaEnArchivo(catalogo arreglo[],int validos,char archivoCata[]);
int  bajarArchivo(char archivo[],catalogo arreglo[],int dim);

// MUESTRA DE ARCHIVOS
void muestraArchivo(char archivo[]);
#endif // LISTASPRODUCTOS_H_INCLUDED
