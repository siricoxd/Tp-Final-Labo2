#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


#define ARCHIVO_SUCUSALDep "depsucursal.bin"
#include <windows.h>
#include "../depositoGeneral/listasProductos.h"
#include "../depostitoPorSucursal/depositoSucursal.h"
#include "../provedores/provedores.h"
#include "../ventas/ventas.h"

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
