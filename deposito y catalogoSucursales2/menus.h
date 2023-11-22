#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "listasProductos.h"

#define ARCHIVO_SUCUSALDep "depsucursal.bin"
#include <windows.h>
#include "depositoSucursal.h"
#include "ventas.h"

int mainMenu();


void imprimirBarraCarga(int porcentaje);
void barra();

int menuDeposito();
int menuOpcionDeposito();

int menuOpcionDepositoSucursal();
int menuDepositoSucursales();


int menuOpcionVentas();
int menuVentas();
int mainMenu();
#endif // MENUS_H_INCLUDED
