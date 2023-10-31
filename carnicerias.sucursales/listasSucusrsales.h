#ifndef LISTASSUCUSRSALES_H_INCLUDED
#define LISTASSUCUSRSALES_H_INCLUDED

typedef struct
{
    char provincia[];
    int idProvincia;

}provincia;

typedef struct
{
    char localidad[];
    char direccion[];
    int idDeLocal;
}locales;

typedef struct nodoLocales
{
    locales dato;
   struct  nodoLocales *siguiente;
}nodoLocales;

#endif // LISTASSUCUSRSALES_H_INCLUDED
