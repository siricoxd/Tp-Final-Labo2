#ifndef LISTASDOBLES_H_INCLUDED
#define LISTASDOBLES_H_INCLUDED

typedef struct nodoLD{
    int dato;
    struct nodoLD*ante;
    struct nodoLD*siguiente;
}nodoLD;

/////////////////////////////////////////////////
nodoLD *crearNodoLD(int dato);
void inicListaLD(nodoLD**lista);
/////////////////////////////////////////////////
void mostrarNodoLD(nodoLD*lista);
void mostrarListaLD(nodoLD*lista);
/////////////////////////////////////////////////
nodoLD*buscarUltimoLD(nodoLD*lista);
int buscarNodoLD(nodoLD*lista,int objetivo);
/////////////////////////////////////////////////
void borrarNodoLD(nodoLD**lista,int objetivo);
/////////////////////////////////////////////////
void agregarAlPpioLLD(nodoLD**lista,nodoLD*nuevo);
void agregarAlFinalLD(nodoLD**lista,nodoLD*nuevo);
void agregarEnOrdenLD(nodoLD**lista,nodoLD*nuevoNodo);
/////////////////////////////////////////////////


#endif // LISTASDOBLES_H_INCLUDED
