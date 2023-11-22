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

//Libreria Archivo:

trabajador cargarUnTrabajador();
void cargarArchivo(char archivoTrabajador[]);
void mostrarUnTrabajador(trabajador a);
void mostrarArchivo(char archivo[]);
void agregarTrabajadores(char archivo[], nodoLista* lista);

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
void mostrarTrabajadoresDeUnaSucursal(nodoLista* lista,int idSucursal);
void mostrarTrabajadoresDeUnRango(nodoLista* lista, int rango);

//Dar de baja y alta
void darDeBaja(char archivo[], nodoLista* aux, int dni, int rango);
void darDeAlta(char archivo[], nodoLista* aux, int dni, int rango);

//cambiar sueldo
void cambiarSueldo(char archivo[], nodoLista* aux, int dni, int rango);

//Libreria arbol:
nodoArbol* inicarbol();
nodoArbol* crearNodoArbol(trabajador a);
nodoArbol* insertar(nodoArbol* arbol, nodoArbol* nuevo);
void inorder(nodoArbol* arbol);
void inorderBajas(nodoArbol * arbol);
void inorderRango(nodoArbol * arbol, int rango);
nodoArbol * buscarPorDni(nodoArbol * arbol, int dni, int rango);
nodoArbol * buscarPorRango(nodoArbol * arbol, int rango);

//Funciones del main

void darDeBajaCase(char archivo[],nodoLista* lista,nodoLista* sucursal, nodoArbol* encontrado, int* idSucursal, int* dni, int* rango);
void darDeAltaCase(char archivo[],nodoLista* lista,nodoLista* sucursal, nodoArbol* encontrado, int* idSucursal, int* dni, int* rango);
void mostrarTrabajadoresDeUnaSucursalCase(int* idSucursal, nodoLista* lista);
 void mostrarTrabajadoresDeUnRangoCase(int* rango, nodoLista* lista);
void cambiarSueldoCase(char archivo[],nodoLista* lista,nodoLista* sucursal, nodoArbol* encontrado, int* idSucursal, int* dni, int* rango);

#endif // PROYECTOMIO_H_INCLUDED
