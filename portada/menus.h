#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "listasProductos.h"
#include "provedores.h"

#define ARCHIVO_SUCUSALDep "depsucursal.bin"
#include <windows.h>
#include "depositoSucursal.h"
#include "ventas.h"
#include "menuGanancias.h"
#include "listasSucusrsales.h"
int mainMenuAdmin();


void imprimirBarraCarga(int porcentaje);
void barra();

int menuDepositoAdmin();
void menuAltaBaja();
int menuOpcionDepositoAdmin();

int menuOpcionDepositoSucursalAdmin();
void cargarStockSucursal();
void mostrarDepositoSucursal();
void menuDesactivarProductoSucursal();
void menuDesactivarCatalogoSucursal();
void menuActivarCatalogoSucursal();
void menuActivarProductoSucursal();
int menuDepositoSucursalesAdmin();



int menuOpcionVentasAdmin();
void cargarArchivoVentasMenu();
int menuVentasAdmin();
void menuAltaBaja();


int menuOpcionProveedoresAdmin()  ;
int menuProveedoresAdmin() ;






//MUENU USUARIOS
//int menuOpcionDepositoUsuario();
//int menuDepositoUsuario();
#endif // MENUS_H_INCLUDED
