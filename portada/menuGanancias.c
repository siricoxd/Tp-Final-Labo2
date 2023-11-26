#include "menuGanancias.h"

void menuGanancias(){
    int seleccion=99;
    nodoGananciasAnio* lista=inicLista();
    while(seleccion!=0){
        system("cls");
        printf("\n\n\n");
        printf("\t\t ______________________________________________________________________________________\n");
        printf("\t\t|                                                                                      |\n");
        printf("\t\t|                                                                                      |\n");
        printf("\t\t|    ## ##     ##     ###  ##    ##     ###  ##   ## ##     ####     ##      ## ##     |\n");
        printf("\t\t|   ##   ##     ##      ## ##     ##      ## ##  ##   ##     ##       ##    ##   ##    |\n");
        printf("\t\t|   ##        ## ##    # ## #   ## ##    # ## #  ##          ##     ## ##   ####       |\n");
        printf("\t\t|   ##  ###   ##  ##   ## ##    ##  ##   ## ##   ##          ##     ##  ##   #####     |\n");
        printf("\t\t|   ##   ##   ## ###   ##  ##   ## ###   ##  ##  ##          ##     ## ###      ###    |\n");
        printf("\t\t|   ##   ##   ##  ##   ##  ##   ##  ##   ##  ##  ##   ##     ##     ##  ##  ##   ##    |\n");
        printf("\t\t|    ## ##   ###  ##  ###  ##  ###  ##  ###  ##   ## ##     ####   ###  ##   ## ##     |\n");
        printf("\t\t|                                                                                      |\n");
        printf("\t\t|                             1.MENU DE MUESTRA                                        |\n");
        printf("\t\t|                             2.MENU ALTA/BAJA                                         |\n");
        printf("\t\t|                             3.MODIFICACION                                           |\n");
        printf("\t\t|                             0.Volver                                                 |\n");
        printf("\t\t|                                                                                      |\n");
        printf("\t\t|_____________________________________________________________________________________ |\n");
        printf("\n");
        seleccion=getch()-'0';
        system("cls");
        switch(seleccion){
        case 1:
            menuMostrarGanancias();
            break;
        case 2:
            menuAltaBajaGanancias();
            break;
        case 3:
            menuModificacionGanancias();
            break;
        case 0:
            break;
        }
    }
}
int menuConfirmacion(){
    int seleccion;
    printf("\t\t\t\tEsta seguro que desea continuar?\n");
    printf("\t\t\t\t1.SI\n");
    printf("\t\t\t\t2.NO\n\t\t\t\t");
    scanf("%d", &seleccion);
    return seleccion;
}

///MUESTRA
void menuMostrarGanancias(){
    int seleccion=99;
    nodoGananciasAnio* lista;
    while(seleccion!=0){
        system("cls");
        printf("\t\t\t\t---MUESTRA DE GANANCIAS---\n\n");
        printf("\t\t\t\t1.VER TODAS LAS GANANCIASs\n\t\t\t\t2.VER TODAS LAS GANANCIAS DE UNA SUCURSAL\n\t\t\t\t3.VER TODAS LAS GANANCIAS DE UN ANIO\n\t\t\t\t4.VER GANANCIAS DADAS DE BAJA\n\t\t\t\t0.VOLVER");
        seleccion=getch()- '0';
        system("cls");
        switch(seleccion){
        case 1:
            lista=archivoToLista();
            mostrarTodasGanancias(lista);
            free(lista);
            system("pause");
            break;
        case 2:
            menuMostrarGananciasSucursal();
            break;
        case 3:
            menuMostrarGananciasAnio();
            break;
        case 4:
            lista=archivoToLista();
            mostrarTodasGananciasBajas(lista);
            free(lista);
            system("pause");
            break;
        }
    }
}

void menuMostrarGananciasSucursal(){
    int sucursal;
    nodoGananciasAnio* lista;
    system("cls");
    printf("--MUESTRA GANANCIAS DE SUCURSAL--\n");
    printf("Seleccione numero de sucursal: ");
    scanf("%d", &sucursal);
    system("cls");
    lista=archivoToLista();
    mostrarGananciasSucursal(lista, sucursal);
    system("pause");
}

void menuMostrarGananciasAnio(){
    int anio;
    nodoGananciasAnio* lista;
    system("cls");
    printf("--MUESTRA GANANCIAS DE ANIO--\n");
    printf("Ingrese anio: ");
    scanf("%d", &anio);
    system("cls");
    lista=archivoToLista();
    mostrarGananciasAnio(lista, anio);
    system("pause");
}

///ALTA/BAJA
void menuAltaBajaGanancias(){
    int seleccion=99;
    while(seleccion!=0){
        system("cls");
        printf("\t\t\t\t---ALTA Y BAJA DE GANANCIAS---\n");
        printf("\t\t\t\t1.DAR DE BAJA GANANCIAS\n");
        printf("\t\t\t\t1.DAR DE ALTA GANANCIAS\n");
        printf("\t\t\t\t0.VOLVER");
        seleccion=getch()-'0';
        switch(seleccion){
        case 1:
            menuBajaGanancias();
            break;
        case 2:
            menuAltaGanancias();
            break;
        }
    }
}

//MENU BAJA
void menuBajaGanancias(){
    int seleccion=99;
    while(seleccion!=0){
        system("cls");
        printf("\t\t\t\t---DAR DE BAJA GANANCIAS---\n");
        printf("\t\t\t\t1.DAR DE BAJA TODAS LAS GANANCIAS DE UNA SUCURSAL\n");
        printf("\t\t\t\t2.DAR DE BAJA TODAS LAS GANANCIAS DE UN ANIO\n");
        printf("\t\t\t\t3.DAR DE BAJA GANANCIAS DE UNA SUCURSAL Y ANIO\n");
        printf("\t\t\t\t0.VOLVER");
        seleccion=getch()-'0';
        switch(seleccion){
        case 1:
            menuBajaGananciasSucursal();
            break;
        case 2:
            menuBajaGananciasAnio();
            break;
        case 3:
            menuBajaGananciasAnioSucursal();
            break;
        }
    }
}

void menuBajaGananciasSucursal(){
    int sucursal;
    system("cls");
    printf("\t\t\t\t---BAJA GANANCIAS SUCURSAL---\n");
    printf("\t\t\t\tIngrese numero de sucursal: ");
    scanf("%d", &sucursal);
    if(menuConfirmacion()){
        altaBajaGananciasSucursal(sucursal, 0);
        printf("\n\t\t\t\tLAS GANANCIAS DE LA SUCURSAL %d HAN SIDO DADAS DE BAJA CON EXITO.\n", sucursal);
    }
    system("pause");
}

void menuBajaGananciasAnio(){
    int anio;
    system("cls");
    printf("\t\t\t\t---BAJA GANANCIAS ANIO---\n");
    printf("\t\t\t\tIngrese anio: ");
    scanf("%d", &anio);
    if(menuConfirmacion()){
        altaBajaGananciasAnio(anio, 0);
        printf("\n\t\t\t\tLAS GANANCIAS DEL ANIO %d HAN SIDO DADAS DE BAJA CON EXITO.\n", anio);
    }
    system("pause");
}

void menuBajaGananciasAnioSucursal(){
    int sucursal, anio;
    system("cls");
    printf("\t\t\t\t---BAJA GANANCIAS---\n");
    printf("\t\t\t\tIngrese sucursal: ");
    scanf("%d", &sucursal);
    printf("\t\t\t\tIngrese anio: ");
    scanf("%d", &anio);
    if(menuConfirmacion()){
        if(altaBajaGanancias(sucursal, anio, 0)){
            printf("\n\t\t\t\tLAS GANANCIAS DE %d DE LA SUCURSAL %d HAN SIDO DADAS DE BAJA CON EXITO.\n", anio, sucursal);
        }
    }
    system("pause");
}


//MENU ALTA
void menuAltaGanancias(){
    int seleccion=99;
    while(seleccion!=0){
        system("cls");
        printf("\t\t\t\t---DAR DE ALTA GANANCIAS---\n");
        printf("\t\t\t\t1.DAR DE ALTA TODAS LAS GANANCIAS DE UNA SUCURSAL\n");
        printf("\t\t\t\t2.DAR DE ALTA TODAS LAS GANANCIAS DE UN ANIO\n");
        printf("\t\t\t\t3.DAR DE ALTA GANANCIAS DE UNA SUCURSAL Y ANIO\n");
        printf("\t\t\t\t0.VOLVER");
        seleccion=getch()-'0';
        switch(seleccion){
        case 1:
            menuAltaGananciasSucursal();
            break;
        case 2:
            menuAltaGananciasAnio();
            break;
        case 3:
            menuAltaGananciasAnioSucursal();
            break;
        }
    }
}

void menuAltaGananciasSucursal(){
    int sucursal;
    system("cls");
    printf("\t\t\t\t---ALTA GANANCIAS SUCURSAL---\n");
    printf("\t\t\t\tIngrese numero de sucursal: ");
    scanf("%d", &sucursal);
    if(menuConfirmacion()){
        altaBajaGananciasSucursal(sucursal, 1);
        printf("\n\t\t\t\tLAS GANANCIAS DE LA SUCURSAL %d HAN SIDO DADAS DE ALTA CON EXITO.\n", sucursal);
    }
    system("pause");
}

void menuAltaGananciasAnio(){
    int anio;
    system("cls");
    printf("\t\t\t\t---ALTA GANANCIAS ANIO---\n");
    printf("\t\t\t\tIngrese anio: ");
    scanf("%d", &anio);
    if(menuConfirmacion()){
        altaBajaGananciasAnio(anio, 1);\
        printf("\n\t\t\t\tLAS GANANCIAS DEL ANIO %d HAN SIDO DADAS DE ALTA CON EXITO.\n", anio);
    }
    system("pause");
}

void menuAltaGananciasAnioSucursal(){
    int sucursal, anio;
    system("cls");
    printf("\t\t\t\t---ALTA GANANCIAS---\n");
    printf("\t\t\t\tIngrese sucursal: ");
    scanf("%d", &sucursal);
    printf("\t\t\t\tIngrese anio: ");
    scanf("%d", &anio);
    if(menuConfirmacion()){
        if(altaBajaGanancias(sucursal, anio, 1)){
            printf("\n\t\t\t\tLAS GANANCIAS DE %d DE LA SUCURSAL %d HAN SIDO DADAS DE ALTA CON EXITO.\n", anio, sucursal);
        }
    }
    system("pause");
}

///MODIFICACION
void menuModificacionGanancias(){
    int nuevasGanancias, sucursal;
    char fecha[10];
    system("cls");
    printf("\t\t\t\t---MODIFICACION---\n");
    printf("\t\t\t\tIngrese sucursal: ");
    scanf("%d", &sucursal);
    fflush(stdin);
    printf("Ingrese fecha (DIA/MES/ANIO): ");
    fgets(fecha, sizeof(fecha), stdin);
    printf("\t\t\t\tIngrese ganancias: ");
    scanf("%d", &nuevasGanancias);
    if(menuConfirmacion()){
        reemplazarDiaGanancias(sucursal, fecha, nuevasGanancias);
    }
    system("pause");
}
