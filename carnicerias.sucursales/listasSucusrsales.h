#ifndef LISTASSUCUSRSALES_H_INCLUDED
#define LISTASSUCUSRSALES_H_INCLUDED

typedef struct
{
    char NombreProvincia[30];
    int idProvincia;

}provincia;

typedef struct
{
    char localidad[30];
    char direccion[30];
    int idDeLocal;
}locales;

typedef struct nodoLocales
{
    locales dato;
   struct  nodoLocales *siguiente;
}nodoLocales;



///prototipado





#endif // LISTASSUCUSRSALES_H_INCLUDED
