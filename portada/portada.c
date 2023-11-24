#include "portada.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

const char archivoUsuarios[]= {"archivoUsuarios.bin"};

///menus

void GARDEL(){

    printf("############################################&&&#Y7!P&###&&&&&#######################################\n");
    printf("##########################################&&#5?7?YJJ55Y7~75GB#&&####################################\n");
    printf("########################################&#G7^75GGGGPPP5~~5GP555B&###################################\n");
    printf("######################################&#P!~?PGGGGGGGPP5!GBBBBBGY5#&#################################\n");
    printf("######################################G7!5BBGGGGGGGGGGY?BBBBBBBBPJB&################################\n");
    printf("#####################################&#&@@@&&&&#BBGGPP5JBBBBBBBBBG?#################################\n");
    printf("###################################&@@@@@@@@@@@@@&&&##BPY5GBBBBBBBYG&###############################\n");
    printf("######################&&&&&&####&#&@@@@@@@@@@@@@@@@@@&&&#G55PGBBB#5P&###############################\n");
    printf("######################BGPGGBB###&&@@@@@@@@@@@@@@&&&@@&&&&@@&#G5PGP?B&###############################\n");
    printf("####################&&#B57^.....:~?YPB&@@@@@&&&&&@@@@@@@@@@@@@&GJ~?&################################\n");
    printf("######################&&&@@&GJ~:       :YB###&&&&&&@@@@@@@@@&&&&B!P&################################\n");
    printf("#########################&@@@@@@&P^.... .5BBBBBBB###&&&&&&&&&&&&&###################################\n");
    printf("###########################&&&&@@P???7!~~7PPGBBBBBBBBB#BBB#&&&&&&###################################\n");
    printf("##################################&&&&&#5!!YB#&#BBGBBBBBBBBGGGBB###&&###############################\n");
    printf("################################BG#&&#&&5!?#@&@&&&##&&###BBBBGGP55PGB&&#############################\n");
    printf("###############################&G5BBGGBG5!~Y#&&####&&&@&&&&&&###BBG5??5G############################\n");
    printf("###############################&PJJY5YYJJ~::~7777!!7??J?J5G#&&&&&&&&###BBB##########################\n");
    printf("###############################&5?7??JYY?^^~!!~^^^^::..::^!?PB&##&&&&&&&&###########################\n");
    printf("################################57!?5PPJ^^^!7?Y?^:.....::~~!??P?5###################################\n");
    printf("################################5?YBGYYYY5PP5?J5?^....::^:...~!Y####################################\n");
    printf("################################PYGGP5YJ???7!!~~7J!^:^~~~:.:!!P&&###################################\n");
    printf("################################B555P#BJ?7?7777J5JJ~^~!77~:Y##&#####################################\n");
    printf("################################&G5YYG#57!!7?JJY??!^!77??!^G&&######################################\n");
    printf("##################################G5J?JJJJJ?7!~~~!!7?JJ?~:^#&&######################################\n");
    printf("###################################B5?7777!~^^~~!!?JJJ!^^:.JB&&&&###################################\n");
    printf("################################&&@#?YJ7~^^^^^~7JY55Y7~!7^.~PYGBB###################################\n");
    printf("#############################&&@@@@&^^7Y5YJJYPGGGPP5J77!~: !&PPG5PGGBBB#######&#####################\n");
    printf("##########################&&&@@@@@@@P...:!J5555YYJ?7!~^:. .#@##&&&&&&&BGPGGGBB######################\n");
    printf("####################&##&&@@@@@@@@@@@@7.    .:^^^^^^:..    ^#@&&&@@@@@@@@&&&&&#######################\n");
    printf("################&&@@@&@@@@@@@@@@@@@@@G.        ^?J~.      .Y@&&&@@@@@@@@@@&@@@@@&&&&################\n");
    printf("#############&&@@@@@@@@@@@@@@@@@@@@@@&:.      ~B#&##J.     .#@&&&&@@@@@@@@@@@@@@@@@@&###############\n");
    printf("############&&@@@@@@@@@@@@@@@@@@@@@@@&:     .P&&&&&J5B7     !&&&&@@@@@@@@@@@@@@&&&&&&###############\n");
    printf("##############&&@@@@@@@@@@@@@@@@@@@@@&:   .!P&B#&#J  ~5~:.   P@&@@@@@@@@@@@&&&&#####################\n");
    printf("#################&&&&&@@@@@@@@@@@@@@@&: .7&&^G&B&@B7 .~ 7&5: .&@@@@@@@&&&&&#########################\n");
    printf("#######################&&&&&@@@@@@@@@@^7#@@&7B&@#B@@YJ~ P@@&B5#&&&&&&&##############################\n");
    printf("##############################&&&&@@@@&@@@@@&###&&B#@&Y~&&&#&&######################################\n");
    printf("###################################&&&&&&&&&#&&B&##&##&#############################################\n");
    system("pause");

}
int menuPrincipal()
{
    system("cls");
    int seleccion=0;
    printf("\n\n\n");
    printf("\t\t\t ________________________________________________________________________\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|    __  __ ___ _  _ _   _    ___ ___ ___ _  _  ___ ___ ___  _   _       |\n");
    printf("\t\t\t|   |  \\/  | __| \\| || | |   | _ \\ _ \\_ _| \\| |/ __|_ _| _ \\/_\\ | |      |\n");
    printf("\t\t\t|   | |\\/| | __|    || | |   |  _/   /| || .` | (__ | ||  _/ _ \\| |__    |\n");
    printf("\t\t\t|   |_|  |_|___|_|\\_|\\___/   |_| |_|_\\___|_|\\_|\\___|___|_|/_/ \\_\\____|   |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             1. SUCURSALES                              |\n");
    printf("\t\t\t|                             2. EMPLEADOS                               |\n");
    printf("\t\t\t|                             3. PRODUCTOS                               |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             0. SALIR                                   |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|________________________________________________________________________|\n");
    printf("\n");
    seleccion= getch()-'0';
    system("cls");
    return seleccion;
}
int menuSucursales()
{
    system("cls");
    int seleccion=0;
    printf("\n\n\n");
    printf("\t\t\t ________________________________________________________________________\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                     ##                 |\n");
    printf("\t\t\t|                                                     #                  |\n");
    printf("\t\t\t|  ####   #  #    ###   #  #   # ##   ####    ###     #     ##    ####   |\n");
    printf("\t\t\t|  ##     #  #   #      #  #   ##     ##         #    #    # ##   ##     |\n");
    printf("\t\t\t|    ##   #  #   #      #  #   #        ##    ####    #    ##       ##   |\n");
    printf("\t\t\t|      #  #  #   #   #  #  #   #          #  #   #    #    #          #  |\n");
    printf("\t\t\t|  ####    ##     ###    ##    #      ####    ####   ###    ###   ####   |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             1. AGREGAR                                 |\n");
    printf("\t\t\t|                             2. MODIFICAR                               |\n");
    printf("\t\t\t|                             3. INFO                                    |\n");
    printf("\t\t\t|                             4. MOSTRAR                                 |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             0. VOLVER                                  |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|________________________________________________________________________|\n");
    printf("\n");
    seleccion= getch()-'0';
    system("cls");
    return seleccion;

}
int menuSucursalesModificar()
{
    system("cls");
    int seleccion=0;
    printf("\n\n\n");
    printf("\t\t\t ________________________________________________________________________\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                     ##                 |\n");
    printf("\t\t\t|                                                     #                  |\n");
    printf("\t\t\t|  ####   #  #    ###   #  #   # ##   ####    ###     #     ##    ####   |\n");
    printf("\t\t\t|  ##     #  #   #      #  #   ##     ##         #    #    # ##   ##     |\n");
    printf("\t\t\t|    ##   #  #   #      #  #   #        ##    ####    #    ##       ##   |\n");
    printf("\t\t\t|      #  #  #   #   #  #  #   #          #  #   #    #    #          #  |\n");
    printf("\t\t\t|  ####    ##     ###    ##    #      ####    ####   ###    ###   ####   |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             1. DESACTIVAR                              |\n");
    printf("\t\t\t|                             2. ACTIVAR                                 |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             0. VOLVER                                  |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|________________________________________________________________________|\n");
    printf("\n");
    seleccion= getch()-'0';
    system("cls");
    return seleccion;

}
int menuSucursalesInfo()
{
    system("cls");
    int seleccion=0;
    printf("\n\n\n");
    printf("\t\t\t ________________________________________________________________________\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                     ##                 |\n");
    printf("\t\t\t|                                                     #                  |\n");
    printf("\t\t\t|  ####   #  #    ###   #  #   # ##   ####    ###     #     ##    ####   |\n");
    printf("\t\t\t|  ##     #  #   #      #  #   ##     ##         #    #    # ##   ##     |\n");
    printf("\t\t\t|    ##   #  #   #      #  #   #        ##    ####    #    ##       ##   |\n");
    printf("\t\t\t|      #  #  #   #   #  #  #   #          #  #   #    #    #          #  |\n");
    printf("\t\t\t|  ####    ##     ###    ##    #      ####    ####   ###    ###   ####   |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             1. NUMERO DE SUCURSALES                    |\n");
    printf("\t\t\t|                             2. ID PROVINCIAS                           |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             0. VOLVER                                  |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|________________________________________________________________________|\n");
    printf("\n");
    seleccion= getch()-'0';
    system("cls");
    return seleccion;

}
int menuSucursalesMostrar()
{
    system("cls");
    int seleccion=0;
    printf("\n\n\n");
    printf("\t\t\t ________________________________________________________________________\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                     ##                 |\n");
    printf("\t\t\t|                                                     #                  |\n");
    printf("\t\t\t|  ####   #  #    ###   #  #   # ##   ####    ###     #     ##    ####   |\n");
    printf("\t\t\t|  ##     #  #   #      #  #   ##     ##         #    #    # ##   ##     |\n");
    printf("\t\t\t|    ##   #  #   #      #  #   #        ##    ####    #    ##       ##   |\n");
    printf("\t\t\t|      #  #  #   #   #  #  #   #          #  #   #    #    #          #  |\n");
    printf("\t\t\t|  ####    ##     ###    ##    #      ####    ####   ###    ###   ####   |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             1. MOSTRAR UNA PROVINCIA                   |\n");
    printf("\t\t\t|                             2. MOSTARAR TODO                           |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             0. VOLVER                                  |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|________________________________________________________________________|\n");
    printf("\n");
    seleccion= getch()-'0';
    system("cls");
    return seleccion;

}
int menuEmpleados(){
    system("cls");
    int seleccion=0;
    printf("\n\n\n");
    printf("\t\t\t ________________________________________________________________________\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|       ####   #   #  ###    #      ####     #    ###     ##     ##      |\n");
    printf("\t\t\t|       #      ## ##  #  #   #      #       # #   #  #   #  #   #  #     |\n");
    printf("\t\t\t|       ###    # # #  #  #   #      ###    #   #  #  #   #  #    #       |\n");
    printf("\t\t\t|       #      # # #  ###    #      #      #####  #  #   #  #     #      |\n");
    printf("\t\t\t|       #      #   #  #      #      #      #   #  #  #   #  #   #  #     |\n");
    printf("\t\t\t|       ####   #   #  #      ####   ####   #   #  ###     ##     ##      |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             1.                                         |\n");
    printf("\t\t\t|                             2.                                         |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             0. VOLVER                                  |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|________________________________________________________________________|\n");
    printf("\n");
    seleccion= getch()-'0';
    system("cls");
    return seleccion;

}
int menuProuctos()
{
    system("cls");
    int seleccion=0;
    printf("\n\n\n");
    printf("\t\t\t ________________________________________________________________________\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|      ###    ###     ##    ###    #  #    ##    #####   ##     ##       |\n");
    printf("\t\t\t|      #  #   #  #   #  #   #  #   #  #   #  #     #    #  #   #  #      |\n");
    printf("\t\t\t|      #  #   #  #   #  #   #  #   #  #   #        #    #  #    #        |\n");
    printf("\t\t\t|      ###    ###    #  #   #  #   #  #   #        #    #  #     #       |\n");
    printf("\t\t\t|      #      #  #   #  #   #  #   #  #   #  #     #    #  #   #  #      |\n");
    printf("\t\t\t|      #      #  #    ##    ###     ##     ##      #     ##     ##       |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             1.                                         |\n");
    printf("\t\t\t|                             2.                                         |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|                             0. VOLVER                                  |\n");
    printf("\t\t\t|                                                                        |\n");
    printf("\t\t\t|________________________________________________________________________|\n");
    printf("\n");
    seleccion= getch()-'0';
    system("cls");
    return seleccion;

}




int LogIn()
{
    system("cls");
    int seleccion=0;
    printf("\n\n\n");

    printf("\t     ####      ##     #####    ##  ##    ####     ####    ######   #####     ####      ## \n");
    printf("\t    ##  ##    ####    ##  ##   ### ##     ##     ##  ##   ##       ##  ##     ##      ####\n");
    printf("\t    ##       ##  ##   ##  ##   ######     ##     ##       ##       ##  ##     ##     ##  ##\n");
    printf("\t    ##       ######   #####    ######     ##     ##       ####     #####      ##     ######\n");
    printf("\t    ##       ##  ##   ####     ## ###     ##     ##       ##       ####       ##     ##  ##\n");
    printf("\t    ##  ##   ##  ##   ## ##    ##  ##     ##     ##  ##   ##       ## ##      ##     ##  ##\n");
    printf("\t     ####    ##  ##   ##  ##   ##  ##    ####     ####    ######   ##  ##    ####    ##  ##\n");
    printf("\n\n\n");
    printf("\t\t\t\t\t\t 1. INICIAR SESION\n\n\t\t\t\t\t\t 2. REGISTRARSE\n\n\t\t\t\t\t\t 0. SALIR\n\n\n\n");

    seleccion= getch()-'0';
    system("cls");
    return seleccion;
}
void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
///archivos
void cargarArchivoUsuarios()
{
    stUsuario aux;
    FILE*buffer=fopen(archivoUsuarios,"ab");
    if(buffer)
    {
        aux=cargarUsuarioNuevo(0);
        fwrite(&aux,sizeof(stUsuario),1,buffer);
        fclose(buffer);
    }
}
int DescargarArchivoUsuarios(stUsuario ar[],int dim)
{
    stUsuario aux;
    int i=0;
    FILE*buffer=fopen(archivoUsuarios,"ab");
    if(buffer)
    {

        while(fread(&aux,sizeof(stUsuario),1,buffer))
        {
            if(i<dim)
            {
                ar[i]=aux;
            }
            i++;
        }
        fclose(buffer);
    }
    return i;
}
stUsuario cargarUsuarioNuevo(int *usuarioExiste)
{
    stUsuario aux,archi;
    printf("Ingrese el nombre de usuario: ");
    fflush(stdin);
    gets(aux.usuario);
    FILE* buffer = fopen("archivoUsuarios.bin", "r+b");
    if (buffer)
    {
        while (fread(&archi, sizeof(stUsuario), 1, buffer))
        {
            if (strcmpi(aux.usuario, archi.usuario) == 0)
            {
                *usuarioExiste = 1;
            }
        }
        if(*usuarioExiste==1)
        {
            printf("Este empleado ya existe\n");
            system("pause");
        }
        fclose(buffer);
    }

    if(*usuarioExiste==0)
    {
        printf("Ingrese la contrasenia: ");
        fflush(stdin);
        gets(aux.contrasenia);
        printf("Ingrese su nombre: ");
        fflush(stdin);
        gets(aux.nombre);

        printf("Ingrese el DNI del empleado: ");
        scanf("%ld",&aux.dni);
        FILE* buffer2 = fopen("archivoUsuarios.bin", "r+b");
        if (buffer2)
        {
            int usuarioExiste = 0;
            while (fread(&archi, sizeof(stUsuario), 1, buffer2))
            {
                if (aux.dni==archi.dni)
                {
                    usuarioExiste = 1;
                }
            }
            if(usuarioExiste==1)
            {
                printf("Este DNI ya existe\n");
                system("pause");

            }
            fclose(buffer2);
        }
    }



    return aux;
}
int iniciarSesion()
{
    stUsuario aux,archi;
    int ok=0,user = 0,contra = 0;
    FILE* buffer = fopen(archivoUsuarios,"rb");
    if (buffer)
    {
        printf("\t\t\t---------------\n");
        printf("\n\t\t\tINICIO DE SESION\n");
        printf("\t\t\t---------------\n");

        printf("\n\tUsuario: ");
        fflush(stdin);
        gets(aux.usuario);

        printf("\tContrasenia: ");
        fflush(stdin);
        gets(aux.contrasenia);

        system("cls");
        if(strcmpi(aux.usuario,"admin")==0)
        {
            if(strcmpi(aux.contrasenia,"admin")==0)
            {
                user=1;
                contra=1;
                ok=1;
            }
        }


        while(fread(&archi,sizeof(stUsuario),1,buffer)&&contra==0)
        {
            if(strcmpi(aux.usuario, archi.usuario) == 0)
            {
                user = 1;

                if(strcmpi(aux.contrasenia, archi.contrasenia) == 0)
                {
                    contra = 1;
                    ok=2;
                }
            }
        }
        if(user == 0) //verificacion de usuario
        {
            printf("Usuario incorrecto\n");
            system("pause");
        }
        if(contra == 0) //verificacion de contraseña
        {
            printf("Contrasenia incorrecta\n");
            system("pause");
        }
        fclose(buffer);
    }

    return ok;
}
void registrarse()
{
    stUsuario aux;
    int usuarioExiste=0;
    system("cls");
    printf("\t\t\t---------------\n");
    printf("\n\t\t\t   REGISTRAR\n");
    printf("\t\t\t---------------\n");
    FILE* buffer = fopen("archivoUsuarios.bin", "ab");
    if (buffer)
    {

        aux = cargarUsuarioNuevo(&usuarioExiste);
        if(usuarioExiste==0)
        {
            fwrite(&aux, sizeof(stUsuario), 1, buffer);
        }
        fclose(buffer);
    }

}
