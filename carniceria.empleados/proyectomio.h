#ifndef PROYECTOMIO_H_INCLUDED
#define PROYECTOMIO_H_INCLUDED

typedef struct {

int rango;
char nombreApe[25];
int idSucursal;
int idProvincia;
int sueldo;
int baja; //si es 0, esta dado de baja, si es uno esta activo;
int bajaSucursal;
int horasExtra;
int dni;

}trabajador; //Registro archivo

typedef struct nodoArbol{

trabajador dato;

struct nodoArbol* izq;
struct nodoArbol* der;

}nodoArbol;

typedef struct nodoLista{

int idSucursal;
nodoArbol* arbol;
struct nodoLista* siguiente;

}nodoLista;

//Librería Archivo:

trabajador cargarUnTrabajador();
void cargarArchivo(char archivoTrabajador[]);
void mostrarUnTrabajador(trabajador a);
void mostrarArchivo(char archivo[]);

//Libreria listas:
nodoLista* iniclista();
nodoLista* crearNodoLista(int idSucursal);
nodoLista* agregarAlPpio(nodoLista* lista, nodoLista* nuevo);
nodoLista* agregarEnOrden(nodoLista* lista, nodoLista* nuevoNodo);
nodoLista * buscarNodo(nodoLista * lista,  int idSucursal);
//Libreria LDA
nodoLista* buscarSucursal(nodoLista* lista, int sucursal);
nodoLista* alta(nodoLista* lista, trabajador dato, int idSucursal);
nodoLista* pasarDelArchivoToLDA(char archivo[], nodoLista* lista);
void mostrarLDA(nodoLista* lista);
void mostrarBajas(nodoLista* lista);

//Dar de baja y alta
void darDeBaja(char archivo[], nodoLista* aux, int dni);
nodoLista* darDeAlta(char archivo[], nodoLista* lista, int idSucursal, int dni);

//Libreria arbol:
nodoArbol* inicarbol();
nodoArbol* crearNodoArbol(trabajador a);
nodoArbol* insertar(nodoArbol* arbol, nodoArbol* nuevo);
void inorder(nodoArbol* arbol);
void inorderBajas(nodoArbol * arbol);
nodoArbol * buscarPorDni(nodoArbol * arbol, int dni);

#endif // PROYECTOMIO_H_INCLUDED
