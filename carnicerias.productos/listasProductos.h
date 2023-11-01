#ifndef LISTASPRODUCTOS_H_INCLUDED
#define LISTASPRODUCTOS_H_INCLUDED





typedef struct
{
    char nombreDeProductos[40];
    int precioPorKilo;
    int id;
}productos;

typedef struct nodoProductos
{
    productos dato;
    struct nodoProductos *siguiente;

}nodoProductos;
typedef struct
{
   char nombreDeCategoria[40];
    int idProductos;
    nodoProductos *lista;
}catalogo;
//manejo de listas
nodoProductos * inicListaProduc();
nodoProductos *crearNuevonodoProductos(productos dato );
nodoProductos* agregarNuevonodoProductosAlPLista(nodoProductos*lista,nodoProductos *nuevonodoProductos);
//manejo de arreglo de listas
int buscaEnCatalogo(catalogo arreglo[],int validos,catalogo dato1);
int altaCatalogo(catalogo arreglo[],int validos,catalogo dato1,productos dato2);
 int agregarALCatalogo(catalogo arreglo[],int validos,catalogo dato);

 //cargaDeCatalogo
 int  cargaCatalogo(catalogo arreglo[],int dim);
 productos cargaDeProductos();
 catalogo cargaDeUnaCateogoria();
 void guardarUltimoId(char archivo[],int ultimoId);
 int leerUltimoId(char archivo[]);
 //FUNCIONES DE MUESTRA
 void muestraDeCatalogo(catalogo A[],int validos);
 void muestraUnCatalogo(catalogo A);
  void muestraLISTA(nodoProductos *lista);
#endif // LISTASPRODUCTOS_H_INCLUDED
