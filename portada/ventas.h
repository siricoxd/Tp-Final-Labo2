#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include "listasProductos.h"

typedef struct
{
    int idDSuc;
     char nombreDeProductos[40];
    int precioPorKilo;
    int stock;
    int id;

    char fechaVenta[11];   /// formato: AAAA-mm-DD
    int venta;


}StRegistroventas;

// crear archivo de ventas



void pasarDeArregloDeposAArchivoVenta(catalogo arreglo[], int validos, char archivoVentas[], int idDeSuc, char fechaVenta[11]);//recorrer el arreglo y pasar los produ

void cargarArchivoVentas(catalogo dato, FILE *archi,  int idDeSuc, char fechaVenta[11]);
StRegistroventas cambioDeEstrucCatalARegistro(productos dato,int idDeSuc, char fechaVenta[11]);//transforma el tio de dato catlogo a uno de registroventa y cargo el la venta y el dia;
int cargaVenta(int stock);
void modificarSatock(int idDelRegistro,int venta,int idDeSuc);
void desactivarArchivoVentas (int id);



// MUESTRS DE ARCHIVO DE VENTAS
void muestraArchivoVentas(char archivo[]);
void muestraUnRegistroVentas(StRegistroventas dato);
#endif // VENTAS_H_INCLUDED
