#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct
{
    char  nombre[];
    int rango;

}jerarquias;

typedef struct nodoArbol
{
    jerarquias dato;
   struct nodoArbol *izq;
    struct nodoArbol *der;


}nodoArbol;

#endif // ARBOL_H_INCLUDED
