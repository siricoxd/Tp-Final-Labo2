#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "listasProductos.h"

#define ARCHIVO_SUCUSALDep "depsucursal.bin"
#include <windows.h>
#include "depositoSucursal.h"
#include "ventas.h"
#include "provedores.h"
int mainMenuAdmin();


void imprimirBarraCarga(int porcentaje);
void barra();

int menuDepositoAdmin();
int menuOpcionDepositoAdmin();

int menuOpcionDepositoSucursalAdmin();
int menuDepositoSucursalesAdmin();



int menuOpcionVentasAdmin();
int menuVentasAdmin();



int menuOpcionProveedoresAdmin()  ;
int menuProveedoresAdmin() ;






//MUENU USUARIOS
int menuOpcionDepositoUsuario();
int menuDepositoUsuario();
#endif // MENUS_H_INCLUDED
