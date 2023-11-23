#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include "../depositoGeneral/listasProductos.h"
#include "../depostitoPorSucursal/depositoSucursal.h"
#include "../provedores/provedores.h"
#include "../ventas/ventas.h"


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


void pasarDeArregloDeposAArchivoVenta(catalogoSuc arreglo[], int validos, char archivo[], int idDeSuc);//recorrer el arreglo y pasar los produ

void cargarArchivoVentas(catalogoSuc dato, FILE *archi,  char arhcivo[], int idDeSuc);
StRegistroventas cambioDeEstrucCatalARegistro(productosDepos dato,char archivo[],int idDeSuc);//transforma el tio de dato catlogo a uno de registroventa y cargo el la venta y el dia;
int cargaVenta(int stock);
void modificarSatock(char archi[],int idDelRegistro,int venta,int idDeSuc);
void desactivarArchivoVentas (int id);



// MUESTRS DE ARCHIVO DE VENTAS
void muestraArchivoVentas(char archivo[]);
void muestraUnRegistroVentas(StRegistroventas dato);
#endif // VENTAS_H_INCLUDED
