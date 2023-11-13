#ifndef PORTADA_H_INCLUDED
#define PORTADA_H_INCLUDED


typedef struct{
    char usuario[30];
    char contrasenia[30];
    int rango;
    unsigned long int dni;
}stUsuario;

///Menus
int menuPrincipal();
int menuSucursales();
int LogIn();
///complementos
void gotoxy(int x,int y);
///archivos
void cargarArchivoUsuarios();
int DescargarArchivoUsuarios(stUsuario ar[],int dim);
stUsuario cargarUsuarioNuevo();
int iniciarSesion();
void registrarse();


#endif // PORTADA_H_INCLUDED
