#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "listasProductos.h"
#include "provedores.h"

#include <windows.h>

#include "ventas.h"
#include "menuGanancias.h"
#include "listasSucusrsales.h"
int mainMenuAdmin();


void imprimirBarraCarga(int porcentaje);
void barra();


int menuDepositoAdmin();
void menuAltaBaja(provincia ar[], int validosProv);
int menuOpcionDepositoAdmin();
void modificaciones();
void modificacionProducPrecio(int idDesuc);
void modificacionCatalogo(int idDeSuc);
void modificacionProduc(int idDeSuc);
void muestraCatalgoMenu();
int menuModificaionesDeposGRL();
void cargararchivoSucursal();
void realizarCargaStockProducto(provincia ar[], int validosProv);
//
//int menuOpcionDepositoSucursalAdmin();
//
//void mostrarDepositoSucursal();
//void menuDesactivarProductoSucursal();
//void menuDesactivarCatalogoSucursal();
//void menuActivarCatalogoSucursal();
//void menuActivarProductoSucursal();
//int menuDepositoSucursalesAdmin();
//int menuModificacionesDeposSuc() ;
//void modificacionCatalogoSucursal();
//void modificacionProductoSucursal();
//void modificacionProductoPrecioSucursal() ;


int menuOpcionVentasAdmin();
void cargarArchivoVentasMenu();
int menuVentasAdmin();
void menuAltaBaja();


int menuOpcionProveedoresAdmin()  ;
int menuProveedoresAdmin() ;
void realizarCompraStock(provincia ar[], int validosProv, int idDesuc, catalogo arregloDepos[], fila* prov);



int mainMenuUsuario ();
int menuOpcionDepositoUusuario();
int menuDepositoUusario();
int menuOpcionDepositoSucursalUsuario();
int menuDepositoSucursalesUusario();

//MUENU USUARIOS
//int menuOpcionDepositoUsuario();
//int menuDepositoUsuario();
#endif // MENUS_H_INCLUDED
