#ifndef PROYECTO_H_INCLUDED
#define PROYECTO_H_INCLUDED

typedef struct {

int rango;
char nombreApe[25];
int idSucursal;
int sueldo;
int baja; //si es 0, esta dado de baja, si es uno esta activo;
int horasExtra;
int dni;
int bajaSucursal;


}trabajador; //Registro archivo

typedef struct nodoArbol{

trabajador dato;

struct nodoArbol* izq;
struct nodoArbol* der;

}nodoArbol;

typedef struct nodoLista{

int idSucursal;
int bajaSucursal;

nodoArbol* arbol;
struct nodoLista* siguiente;

}nodoLista;

//Libreria Archivo:

trabajador cargarUnTrabajador(int idSucursal);
void cargarArchivoEmpleados(char archivoTrabajador[], int idSucursal);
void mostrarUnTrabajador(trabajador a);
void mostrarArchivo(char archivo[]);
void agregarTrabajadores(char archivo[], nodoLista* lista, int idSucursal);


//Libreria listas:
nodoLista* iniclista();
nodoLista* crearNodoLista(int idSucursal, int bajaSucursal);
nodoLista* agregarAlPpio(nodoLista* lista, nodoLista* nuevo);
nodoLista* agregarEnOrden(nodoLista* lista, nodoLista* nuevoNodo);
nodoLista * buscarNodoEmpleado(nodoLista * lista,  int idSucursal);
void mostrarUnTrabajador2(trabajador a);

//Libreria LDA
nodoLista* buscarSucursal(nodoLista* lista, int sucursal);
nodoLista* altaEmpleados(nodoLista* lista, trabajador dato, int idSucursal, int bajaSucursal);
nodoLista* pasarDelArchivoToLDA(char archivo[], nodoLista* lista, int idSucursal);
void mostrarLDA(nodoLista* lista);
void mostrarBajas(nodoLista* lista);
void mostrarTrabajadoresDeUnaSucursal(nodoLista* lista,int idSucursal);
void mostrarTrabajadoresDeUnRango(nodoLista* lista, int rango);

//Dar de baja y alta
void darDeBaja(char archivo[], nodoLista* aux, int dni, int rango);
void darDeAlta(char archivo[], nodoLista* aux, int dni, int rango);

//cambiar sueldo
void cambiarSueldo(char archivo[], nodoLista* aux, int dni, int rango);

//dar de baja una sucursal
void inorderBajaSucursal(nodoArbol * arbol);
void darDeBajaUnaSucursal(char archivo[], nodoLista* aux);

//dar de alta una sucursal
void inorderAltaSucursal(nodoArbol* arbol);
void darDeAltaUnaSucursal(char archivo[], nodoLista* aux);


//funciones del case 15 y 16
void cargarHorasExtrasTrabajadores(nodoLista*lista,char nombreArchivo[]);
void guardarHrsExtrasEnArchivo(char archivo[], nodoLista* aux, int dni, int rango, int hrsExtras);
nodoArbol * buscarPorDni2(nodoArbol * arbol, int dni, int rango);
void modificarHorasExtrasTrabajadores(nodoLista*lista,char nombreArchivo[]);
void modificarHrsExtrasEnArchivo(char archivo[], nodoLista* aux, int dni, int rango);
int bonoXtrabajadorArbol(trabajador a);
//Libreria arbol:
nodoArbol* inicarbol();
nodoArbol* crearNodoArbol(trabajador a);
nodoArbol* insertar(nodoArbol* arbol, nodoArbol* nuevo);
void inorder(nodoArbol* arbol);
void inorderBajas(nodoArbol * arbol);
void inorderRango(nodoArbol * arbol, int rango);
nodoArbol * buscarPorDni(nodoArbol * arbol, int dni, int rango);
nodoArbol * buscarPorRango(nodoArbol * arbol, int rango);

//

#endif // PROYECTO_H_INCLUDED
