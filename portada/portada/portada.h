#ifndef PORTADA_H_INCLUDED
#define PORTADA_H_INCLUDED
#include"../listaSucursales/listasSucusrsales.h"
typedef struct{
    char usuario[30];
    char contrasenia[30];
    char nombre[30];
    unsigned long int dni;
}stUsuario;

///Menus
int menuPrincipal();
int menuSucursales();
int menuSucursalesModificar();
int menuSucursalesInfo();
int menuSucursalesMostrar();
int menuEmpleados();


int menuProuctos();


int LogIn();
///complementos
void gotoxy(int x,int y);
///archivos
void cargarArchivoUsuarios();
int DescargarArchivoUsuarios(stUsuario ar[],int dim);
stUsuario cargarUsuarioNuevo(int*usuarioExiste);
int iniciarSesion();
void registrarse();


#endif // PORTADA_H_INCLUDED
