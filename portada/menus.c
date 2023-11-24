#include "menus.h"



//MENUS ADMIN

int mainMenuAdmin()
{



    int opcion=99;

    do
    {
        // Menú principal
        system("cls");
        printf("\n\n\n");
        printf("\t\t _______________________________________________________________________________________________\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|   ##   ##  ### ###  ### ##    ## ##     ##     ### ##   ### ###  ### ##     ####     ##       |\n");
        printf("\t\t|    ## ##    ##  ##   ##  ##  ##   ##     ##     ##  ##   ##  ##   ##  ##     ##       ##      |\n");
        printf("\t\t|   # ### #   ##       ##  ##  ##        ## ##    ##  ##   ##       ##  ##     ##     ## ##     |\n");
        printf("\t\t|   ## # ##   ## ##    ## ##   ##        ##  ##   ##  ##   ## ##    ## ##      ##     ##  ##    |\n");
        printf("\t\t|   ##   ##   ##       ## ##   ##        ## ###   ##  ##   ##       ## ##      ##     ## ###    |\n");
        printf("\t\t|   ##   ##   ##  ##   ##  ##  ##   ##   ##  ##   ##  ##   ##  ##   ##  ##     ##     ##  ##    |\n");
        printf("\t\t|   ##   ##  ### ###  #### ##   ## ##   ###  ##  ### ##   ### ###  #### ##    ####   ###  ##    |\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|                             1. DEPOSITO GENERAL                                               |\n");
        printf("\t\t|                             2. DEPOSITO POR SUCURSAL                                          |\n");
        printf("\t\t|                             3. VENTAS                                                         |\n");
        printf("\t\t|                             4. COMPRA DE PROVEEDORES                                          |\n");
        printf("\t\t|                             0. VOLVER                                                         |\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|_______________________________________________________________________________________________|\n");
        printf("\n");

        opcion=getch() - '0';
        system("cls");
        switch (opcion)
        {
        case 1:
            menuOpcionDepositoAdmin();
            break;
        case 2:
            menuOpcionDepositoSucursalAdmin();

            break;
        case 3:
            menuOpcionVentasAdmin();
            break;
        case 4:
            menuOpcionProveedoresAdmin();
            break;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");
        }

    }
    while (opcion != 0);

    return 0;
}




int menuOpcionDepositoAdmin()
{
    int selected;
    catalogo arreglo[40];
    int validos = 0;
    do{
        selected = menuDepositoAdmin();
        switch (selected)
        {
        case 1:
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);
            system("pause");
            break;
        case 2:
            printf("\n---CARGA DE DEPOSITO--\n");
            cargaArchivo(ARCHIVO_DEPOSITO);
            break;
        case 3:
            menuAltaBaja();
            break;

        }

    }
    while (selected != 0);

    //system("pause");
    // system("cls");
    return 0;
}

void menuAltaBaja()
{
    int opcion;
    int validos = 0, buscar = 0, pos = 0;
    int idDeProdu=0;
    catalogo arreglo[40];
    nodoProductos *buscado;
    do
    {
        system("cls");
        printf("\t\t\t1)Dar de baja a una categoria\n");
        printf("\t\t\t2)Dar de baja a un producto\n");
        printf("\t\t\t3)Dar de alta a una producto\n");
        printf("\t\t\t4)Dar de alta a una categoria\n");
        printf("\t\t\t0)Volver\n");
        opcion=getch() -'0';

        switch(opcion)
        {
        case 1://muestra archivo depos general
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);
            printf("\nIngrese el id de la categoria que desea desactivar: \n");
            scanf("%d", &buscar);
            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
            if (pos !=-1)
            {
                desactivarCatalogo(ARCHIVO_DEPOSITO,arreglo, buscar, pos);
            }
            else
            {
                printf("\nNo se encontro catalogo.\n");
            }
            break;
        case 2 ://carga deposito general solo los productos y catalogos
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);
            printf("\nIngrese el id del catalogo del producto a desactivar: \n");
            scanf("%d", &buscar);
            printf("\nIngrese el id del producto a dar de baja: ");
            scanf("%d",&idDeProdu);

            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
            buscado=buscaEnListaId(arreglo,pos,idDeProdu);


            if (pos !=-1 )
            {
                if(buscado!=NULL)
                {
                    desactivarProducto(ARCHIVO_DEPOSITO,arreglo, pos,buscado);
                }
                else
                {
                    printf("\nNo se encontro producto.\n");
                }


            }
            else
            {
                printf("\nNo se encontro catalogo.\n");
            }


            break;
        case 3://muestra  depos general
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogoTodos(arreglo, validos);

            printf("\nIngrese el id del catalogo del cual el producto producto a activar forma parte: \n");
            scanf("%d", &buscar);
            printf("\nIngrese el id del producto a activar: ");
            scanf("%d",&idDeProdu);

            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
            buscado=buscaEnListaId(arreglo,pos,idDeProdu);

            activarProducto(ARCHIVO_DEPOSITO,arreglo,pos,buscado);
            break;

        case 4://activar catalogo depos
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogoTodos(arreglo, validos);

            printf("\nIngrese el id del catalogo que desea activar: \n");
            scanf("%d", &buscar);
            pos = buscaEnCatalogoPorId(arreglo, validos, buscar);

            if (pos !=-1 )
            {
                activarCatalogo(ARCHIVO_DEPOSITO,arreglo, buscar, pos);



            }
            else
            {
                printf("\nNo se encontro catalogo.\n");
            }

            break;
        }
    }
    while(opcion!=0);

}
int menuDepositoAdmin()
{

    int input;
    system("cls");


    printf("\n\n\n");
    printf("\t\t __________________________________________________________________________________________________________________________________________________\n");
    printf("\t\t|                                                                                                                                                  |\n");
    printf("\t\t|                                                                                                                                                  |\n");
    printf("\t\t|  #####    #######  ######    #####    #####    ####    ######    #####              ####   #######  ##   ##  #######  ######     ##     ####     |\n");
    printf("\t\t|  ## ##    ##   #   ##  ##  ##   ##  ##   ##    ##     # ## #   ##   ##            ##  ##   ##   #  ###  ##   ##   #   ##  ##   ####     ##       |\n");
    printf("\t\t|  ##  ##   ## #     ##  ##  ##   ##  #          ##       ##     ##   ##           ##        ## #    #### ##   ## #     ##  ##  ##  ##    ##       |\n");
    printf("\t\t|  ##  ##   ####     #####   ##   ##   #####     ##       ##     ##   ##           ##        ####    ## ####   ####     #####   ##  ##    ##       |\n");
    printf("\t\t|  ##  ##   ## #     ##      ##   ##       ##    ##       ##     ##   ##           ##  ###   ## #    ##  ###   ## #     ## ##   ######    ##   #   |\n");
    printf("\t\t|  ## ##    ##   #   ##      ##   ##  ##   ##    ##       ##     ##   ##            ##  ##   ##   #  ##   ##   ##   #   ##  ##  ##  ##    ##  ##   |\n");
    printf("\t\t| #####    #######  ####      #####    #####    ####     ####     #####              #####  #######  ##   ##  #######  #### ##  ##  ##   #######   |\n");
    printf("\t\t|                                                                                                                                                  |\n");
    printf("\t\t|                                                                                                                                                  |\n");
    printf("\t\t|                                                                  1. MUESTRA DEL DEPOSITO                                                         |\n");
    printf("\t\t|                                                                  2. CARGA DEL DEPOSITO                                                           |\n");
    printf("\t\t|                                                                  3. MENU ALTA/BAJA                                                               |\n");
    printf("\t\t|                                                                  0. VOLER                                                                        |\n");
    printf("\t\t|                                                                                                                                                  |\n");
    printf("\t\t|__________________________________________________________________________________________________________________________________________________|\n");

    input=getch()-'0';
    system("cls");
    return input;
}




//BARRA DE CARGA INNCIO
void barra()
{
    printf("\n");
    printf("+------------------+\n");
    printf("|                  |\n");
    printf("|    CARGANDO...   |\n");
    printf("|                  |\n");
    printf("|------------------|");
    printf("\n");
    int porcentaje;
    for (porcentaje = 0; porcentaje <= 100; porcentaje++)
    {
        imprimirBarraCarga(porcentaje);
        Sleep(10000); // Esperar 100ms (0.1 segundos)
    }
    printf("\nCarga completa\n");
    // sleep(1);
    system("cls");
}

void imprimirBarraCarga(int porcentaje)
{
    int i;
    for (i = 0; i < 50; i++)
    {
        if (i < porcentaje / 2)
        {
            printf("#");
        }
        else
        {
            printf(" ");
        }
        fflush(stdout); // Limpiar y mostrar la salida inmediatamente
    }
    printf("] %d%%\r", porcentaje);
    fflush(stdout); // Limpiar y mostrar la salida inmediatamente
}


//MENU DEPOSITO SUCURSALES

int menuOpcionDepositoSucursalAdmin()
{
    int opcion;
    do{
        opcion = menuDepositoSucursalesAdmin();
        switch (opcion)
        {
        case 1:
            cargarStockSucursal();
            break;
        case 2:
            mostrarDepositoSucursal();
            break;
        case 3 :
            menuDesactivarProductoSucursal();
            break;
        case 4:
            menuDesactivarCatalogoSucursal();
            break;

        case 5:
            menuActivarCatalogoSucursal();
            break;

        case 6:
            menuActivarProductoSucursal();
            break;
        }

    }
    while (opcion != 0);

    return 0;
}

void cargarStockSucursal(){
    int validosProv=0, validos=0, buscar=0, pos=0, stock, idDesuc, idDeProdu;
    provincia ar[30];
    catalogo arreglo[40];
    nodoProductos* buscadoDepos;
    validosProv=descargarArchivo(ar,validosProv,30);
    validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
    printf("--CARGA DE STOCK PRODUCTO--\n\n");
    muestraDeCatalogo(arreglo, validos);
    printf("\nIngrese el id de la categoria: ");
    scanf("%d", &buscar);
    pos = buscaEnCatalogoPorId(arreglo, validos, buscar);
    if (pos == -1){
    printf("\nEl catalogo con ID %d no existe.\n", buscar);
    system("pause");
    }
    else{
        printf("\nIngrese id del producto al cual desea modificar stock: ");
        scanf("%d", &idDeProdu);
        buscadoDepos = buscaEnListaId(arreglo, pos, idDeProdu);
        if (buscadoDepos == NULL)
        {
        printf("\nEl producto con ID %d no existe en el catalogo %d.\n", idDeProdu, buscar);
        system("pause");
        }
        else{
            //system("pause");
            system("cls");
            mostrarTodo(ar,validosProv);
            printf("\n\nCargue el id de la sucursal:  ");// esta la voy a pedir del menu de sucursales
            scanf("%d",&idDesuc);
            pos=VerificarSucursal(idDesuc);
            if(pos!=1)
            {
                printf("No Existe la sucursal\n");
            }
            else
            {
                stock=cargarStockYmodificarlos(ARCHIVO_DEPOSITO,buscadoDepos);
                if(modificarStockEnArchivoDepSuc(ARCHIVO_SUCUSALDep,idDeProdu,idDesuc,stock)==1)//separa la funcion verifiar si en el archivo existe y si exite modificar su atock
                {
                // modificarStockEnArchivoDepSuc(ARCHIVO_SUCUSALDep,idDeProdu,idDesuc,stock);
                }
                else
                {
                recorrerDeposito(ARCHIVO_DEPOSITO,ARCHIVO_SUCUSALDep,idDesuc,idDeProdu,stock);
                // muestraArchivoSucursal(ARCHIVO_SUCUSALDep);
                }
            }
        }
    }
    system("pause");
}

void mostrarDepositoSucursal(){
    provincia ar[30];
    int validosProv=0;
    validosProv=descargarArchivo(ar,validosProv,30);
    catalogoSuc arregloSucur[40];
    int validos = 0,pos=0;
    int idDesuc;
    mostrarTodo(ar ,validosProv);
    printf("\n\nCargue el id de la sucursal:  ");
    scanf("%d",&idDesuc);
    pos=VerificarSucursal(idDesuc);
    if(pos==1)
    {
        system("cls");
        printf("\n--MUESTRA DEPOSITO DEL LOCAL--\n\n");
        validos=pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep,arregloSucur,40,idDesuc);
        muestraDecatalogoSucursal(arregloSucur,validos);
    }
    else
    {
        printf("No Existe la sucursal.\n");
    }
    system("pause");
}

void menuDesactivarProductoSucursal(){
    provincia ar[30];
    int validosProv=0;
    validosProv=descargarArchivo(ar,validosProv,30);
    catalogoSuc arregloSucur[40];
    int validos = 0, buscar = 0, pos = 0;
    int idDeProdu=0;
    nodoproductosSucursal *buscado;
    int idDesuc;
    mostrarTodo(ar,validosProv);
    printf("\nIngrese el id de la sucursal:  ");
    scanf("%d",&idDesuc);
    pos=VerificarSucursal(idDesuc);
    if(pos!=1)
    {
        printf("No Existe la sucursal\n");
    }
    else
    {
        system("pause");
        system("cls");
        validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
        muestraDecatalogoSucursal(arregloSucur, validos);
        printf("\nIngrese el id del catalogo del producto a desactivar: ");
        scanf("%d", &buscar);

        pos = buscaEnCatalogoPorIdSUCURSAL(arregloSucur, validos, buscar);
        if (pos == -1){
            printf("\nEl catalogo con ID %d no existe.\n", buscar);
        }
        else{
            printf("\nIngrese el id del producto a desactivar: ");
            scanf("%d", &idDeProdu);
            buscado = buscaEnListaIdSucursal(arregloSucur, pos, idDeProdu);
            if (buscado == NULL){
                printf("\nEl producto con ID %d no existe en el catalogo %d.\n", idDeProdu, buscar);
            }
            else{
                if (pos !=-1 ){
                    desactivarProductoEnSucursal(ARCHIVO_SUCUSALDep,arregloSucur, pos, buscado,idDesuc);
                    validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
                    muestraDecatalogoSucursal(arregloSucur, validos);
                }
                else
                {
                    printf("\nNo se encontro catalogo.\n");
                }
            }
        }
    }
    system("pause");
}

void menuDesactivarCatalogoSucursal(){
    provincia ar[30];
    int validosProv=0;
    validosProv=descargarArchivo(ar,validosProv,30);
    catalogoSuc arregloSucur[40];
    int validos = 0, buscar = 0, pos = 0;
    int idDesuc;

    mostrarTodo(ar,validosProv);
    printf("\n\nIngrese el id de la sucursal:  ");
    scanf("%d",&idDesuc);
    pos=VerificarSucursal(idDesuc);
    if(pos!=1){
        printf("No Existe la sucursal\n");
    }
    else
    {
        system("pause");
        system("cls");
        validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
        muestraDecatalogoSucursal(arregloSucur, validos);
        printf("\nIngrese el id del catalogo a desactivar: \n");
        scanf("%d", &buscar);

        // Verificar si el catálogo existe en el arreglo
        pos = buscaEnCatalogoPorIdSUCURSAL(arregloSucur, validos, buscar);
        if (pos == -1){
            printf("\nEl catálogo con ID %d no existe.\n", buscar);
        }
        else{
            if (pos !=-1 ){
                desactivarCatalogoSucursal(ARCHIVO_SUCUSALDep,arregloSucur, buscar,pos,idDesuc);
                validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
                muestraDecatalogoSucursal(arregloSucur, validos);
            }
            else
            {
                printf("\nNo se encontro catalogo.\n");
            }
        }
    }

    system("pause");

}

void menuActivarCatalogoSucursal(){
    provincia ar[30];
    int validosProv=0;
    validosProv=descargarArchivo(ar,validosProv,30);
    catalogoSuc arregloSucur[40];
    int validos = 0, buscar = 0, pos = 0;
    int idDesuc;
    mostrarTodo(ar,validosProv);
    printf("\n\nIngrese el id de la sucursal:  ");
    scanf("%d",&idDesuc);
    pos=VerificarSucursal(idDesuc);
    if(pos!=1){
        printf("No Existe la sucursal.\n");
    }
    else
    {
        system("pause");
        system("cls");
        validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
        muestraDecatalogoSucursalTodos(arregloSucur, validos);
        printf("\nIngrese el id del catalogo del producto a activar: \n");
        scanf("%d", &buscar);


        pos = buscaEnCatalogoPorIdSUCURSAL(arregloSucur, validos, buscar);
        if (pos == -1)
        {
            printf("\nEl catalogo con ID %d no existe.\n", buscar);
        }
        else{
            activarCatalogoSucursal(ARCHIVO_SUCUSALDep,arregloSucur, buscar,pos,idDesuc);
            validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
            muestraDecatalogoSucursalTodos(arregloSucur, validos);
        }
        system("pause");
    }
}

void menuActivarProductoSucursal(){
    provincia ar[30];
    int validosProv=0;
    validosProv=descargarArchivo(ar,validosProv,30);
    catalogoSuc arregloSucur[40];
    int validos = 0, buscar = 0, pos = 0;
    int idDeProdu=0;
    nodoproductosSucursal *buscado;
    int idDesuc;
    mostrarTodo(ar,validosProv);
    printf("\n\nIngrese el id de la sucursal:  ");
    scanf("%d",&idDesuc);
    pos=VerificarSucursal(idDesuc);
    if(pos!=1)
    {
        printf("No Existe la sucursal\n");
    }
    else{
        system("pause");
        system("cls");

        validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
        muestraDecatalogoSucursalTodos(arregloSucur, validos);
        printf("\nIngrese el id del catalogo del producto a activar: \n");
        scanf("%d", &buscar);
        pos = buscaEnCatalogoPorIdSUCURSAL(arregloSucur, validos, buscar);
        if (pos == -1)
        {
            printf("\nEl catálogo con ID %d no existe.\n", buscar);

        }
        else{
            printf("\nIngrese el id del producto a activar: \n");
            scanf("%d", &idDeProdu);
            buscado = buscaEnListaIdSucursal(arregloSucur, pos, idDeProdu);
            if (buscado == NULL){
                printf("\nEl producto con ID %d no existe en el catálogo %d.\n", idDeProdu, buscar);
            }
            else{
                activarProductoEnSucursal(ARCHIVO_SUCUSALDep,arregloSucur, pos, buscado,idDesuc);
                validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40,idDesuc);
                muestraDecatalogoSucursalTodos(arregloSucur, validos);
            }

            }
        }

    system("pause");
}
int menuDepositoSucursalesAdmin()
{

    int input;
    system("cls");
    printf("\n\n\n");
    printf("\t\t _____________________________________________________________________________________________________________________________________________________________________________\n");
    printf("\t\t|                                                                                                                                                                             |\n");
    printf("\t\t|                                                                                                                                                                             |\n");
    printf("\t\t|   ###                                         ##       ##                                                                                       ###                         |\n");
    printf("\t\t|    ##                                                  ##                                                                                        ##                         |\n");
    printf("\t\t|    ##    ####     ######   ####     #####    ###      #####    ####              #####   ##  ##    ####    ##  ##   ######    #####    ####      ##      ####     #####     |\n");
    printf("\t\t| #####   ##  ##    ##  ##  ##  ##   ##         ##       ##     ##  ##            ##       ##  ##   ##  ##   ##  ##    ##  ##  ##           ##     ##     ##  ##   ##         |\n");
    printf("\t\t| ##  ##  ######    ##  ##  ##  ##    #####     ##       ##     ##  ##             #####   ##  ##   ##       ##  ##    ##       #####    #####     ##     ######    #####     |\n");
    printf("\t\t| ##  ##  ##        #####   ##  ##        ##    ##       ## ##  ##  ##                 ##  ##  ##   ##  ##   ##  ##    ##           ##  ##  ##     ##     ##            ##    |\n");
    printf("\t\t| ######  #####     ##       ####    ######    ####       ###    ####             ######    ######   ####     ######  ####     ######    #####    ####     #####   ######     |\n");
    printf("\t\t|                  ####                                                                                                                                                       |\n");
    printf("\t\t|                                                                                                                                                                             |\n");
    printf("\t\t|                                            1. CARGAR STOCK DE SUCURSAL                                                                                                      |\n");
    printf("\t\t|                                            2. VER CATALOGO DE SUCURSAL                                                                                                      |\n");
    printf("\t\t|                                            3. DESACTIVAR PRODUCTO                                                                                                           |\n");
    printf("\t\t|                                            4. DESACTIVAR CATALOGO                                                                                                           |\n");
    printf("\t\t|                                            5. ACTIVAR CATALOGO                                                                                                              |\n");
    printf("\t\t|                                            6. ACTIVAR PRODUCTO                                                                                                              |\n");
    printf("\t\t|                                            0. SALIR                                                                                                                         |\n");
    printf("\t\t|_____________________________________________________________________________________________________________________________________________________________________________|\n");

    input=getch()- '0';
    system("cls");
    return input;
}


int menuOpcionVentasAdmin()
{
    int selected;
    do
    {
        selected = menuVentasAdmin();

        switch (selected)
        {
        case 1:
            cargarArchivoVentasMenu();
            break;

        case 2:
            muestraArchivoVentas(ARCHIVO_VENTAS);
            system("pause");
            break;
        case 3:
            menuGanancias();
            break;


        }
    }
    while (selected != 0);

    printf("\n");
    return 0;
}


void cargarArchivoVentasMenu()
{


    provincia ar[30];
    int validosProv=0;
    validosProv=descargarArchivo(ar,validosProv,30);
    int pos=0;
    catalogoSuc arregloSucur[40];
    int idDeSuc,  validos;
    char fechaVenta[11];


    mostrarTodo(ar,validosProv);
    printf("\n\ncargue el id de la sucursal:  ");// esta la voy a pedir del menu de sucursales
    scanf("%d",&idDeSuc);
    pos=VerificarSucursal(idDeSuc);
    if(pos==1)
    {

        printf("\nIngrese la fecha de la venta(DIA/MES/ANIO): ");
        fflush(stdin);
        gets(fechaVenta);
        int seEncuentraFechaGanancias=buscaEnArchivoGanancias(nombreArchivoGanancias, fechaVenta);
        if(seEncuentraFechaGanancias==0 || seEncuentraFechaGanancias==-1){
            validos = pasardeArchivoAArregloSucursal(ARCHIVO_SUCUSALDep, arregloSucur, 40, idDeSuc);
            muestraDecatalogoSucursal(arregloSucur, validos);
            pasarDeArregloDeposAArchivoVenta(arregloSucur,validos,ARCHIVO_VENTAS,ARCHIVO_SUCUSALDep, idDeSuc,fechaVenta);
            crearArchivoGananciasConVentas();
            getchar();
        }
        else{
            printf("\nLa fecha ya ha sido cargada.\n");
        }
    }
    else
    {
        printf("No Existe la sucursal\n");
        system("pause");

    }
    system("pause");
    system("cls");


}


int menuVentasAdmin()
{

    int input;
    system("cls");
    printf("\n\n\n");
    printf("\t\t ______________________________________________________\n");
    printf("\t\t|                              ##                      |\n");
    printf("\t\t|                              ##                      |\n");
    printf("\t\t| ##  ##    ####    #####     #####    ####     #####  |\n");
    printf("\t\t| ##  ##   ##  ##   ##  ##     ##         ##   ##      |\n");
    printf("\t\t| ##  ##   ######   ##  ##     ##      #####    #####  |\n");
    printf("\t\t|  ####    ##       ##  ##     ## ##  ##  ##        ## |\n");
    printf("\t\t|   ##      #####   ##  ##      ###    #####   ######  |\n");
    printf("\t\t|                                                      |\n");
    printf("\t\t|                                                      |\n");
    printf("\t\t|                 1. CARGA DE ARCHIVO VENTAS           |\n");
    printf("\t\t|                 2. MUESTRA DE ARCHIVO VENTAS         |\n");
    printf("\t\t|                 3. MENU GANANCIAS                    |\n");
    printf("\t\t|                 0. VOLVER                            |\n");
    printf("\t\t|______________________________________________________|\n");

    input=getch()-'0';
    system("cls");
    return input;
}



//MENU PROVEDORES


int menuOpcionProveedoresAdmin()
{
    catalogo arregloDepos[40];
    int validos, selected;
    fila prov;
    inicFila(&prov);

    do
    {
        selected = menuProveedoresAdmin();

        switch (selected)
        {
        case 1://carga la mercaderia en depos general
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arregloDepos, 40);
            pasarDeDepositoAAFilas(arregloDepos, validos, &prov, ARCHIVO_DEPOSITO);
            mostrarFila(prov);
            system("pause");
            break;

        case 0:
            printf("\n\nTERMINATE THE PROGRAM\n");
            break;
        }

    }
    while (selected != 0);

    printf("\n");
    return 0;
}

int menuProveedoresAdmin()
{
    int input;
    system("cls");
    printf("\n\n\n");
    printf("\t\t __________________________________________________________________________________________\n");
    printf("\t\t|                                                 ###                                      |\n");
    printf("\t\t|                                                  ##                                      |\n");
    printf("\t\t| ######   ######    ####    ##  ##    ####        ##    ####    ######    ####     #####  |\n");
    printf("\t\t|  ##  ##   ##  ##  ##  ##   ##  ##   ##  ##    #####   ##  ##    ##  ##  ##  ##   ##      |\n");
    printf("\t\t|  ##  ##   ##      ##  ##   ##  ##   ######   ##  ##   ##  ##    ##      ######    #####  |\n");
    printf("\t\t|  #####    ##      ##  ##    ####    ##       ##  ##   ##  ##    ##      ##            ## |\n");
    printf("\t\t|  ##      ####      ####      ##      #####    ######   ####    ####      #####   ######  |\n");
    printf("\t\t| ####                                                                                     |\n");
    printf("\t\t|                                                                                          |\n");
    printf("\t\t|                                                                                          |\n");
    printf("\t\t|                               1. COMPRA DE STOCK                                         |\n");
    printf("\t\t|                               0. VOLVER                                                  |\n");
    printf("\t\t|__________________________________________________________________________________________|\n");



    scanf("%d", &input);
    system("cls");
    return input;
}


//MENUS USUARIO



int mainMenuUsuario ()
{



    int opcion=99;

    do
    {
        // Menú principal
        system("cls");
        printf("\n\n\n");
        printf("\t\t _______________________________________________________________________________________________\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|   ##   ##  ### ###  ### ##    ## ##     ##     ### ##   ### ###  ### ##     ####     ##       |\n");
        printf("\t\t|    ## ##    ##  ##   ##  ##  ##   ##     ##     ##  ##   ##  ##   ##  ##     ##       ##      |\n");
        printf("\t\t|   # ### #   ##       ##  ##  ##        ## ##    ##  ##   ##       ##  ##     ##     ## ##     |\n");
        printf("\t\t|   ## # ##   ## ##    ## ##   ##        ##  ##   ##  ##   ## ##    ## ##      ##     ##  ##    |\n");
        printf("\t\t|   ##   ##   ##       ## ##   ##        ## ###   ##  ##   ##       ## ##      ##     ## ###    |\n");
        printf("\t\t|   ##   ##   ##  ##   ##  ##  ##   ##   ##  ##   ##  ##   ##  ##   ##  ##     ##     ##  ##    |\n");
        printf("\t\t|   ##   ##  ### ###  #### ##   ## ##   ###  ##  ### ##   ### ###  #### ##    ####   ###  ##    |\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|                             1. DEPOSITO GENERAL                                               |\n");
        printf("\t\t|                             2. DEPOSITO POR SUCURSAL                                          |\n");
        printf("\t\t|                                                                                               |\n");
        printf("\t\t|_______________________________________________________________________________________________|\n");
        printf("\n");

        opcion=getch() - '0';
        system("cls");
        switch (opcion)
        {
        case 1:
            menuOpcionDepositoUusuario();
            break;
        case 2:
            menuOpcionDepositoSucursalUsuario();
         break;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");
        }

    }
    while (opcion != 0);

    return 0;
}




int menuOpcionDepositoUusuario()
{
    int selected;
    catalogo arreglo[40];
    int validos = 0;
    do{
        selected = menuDepositoUusario();
        switch (selected)
        {
        case 1:
            validos = pasardeArchivoAArreglo(ARCHIVO_DEPOSITO, arreglo, 40);
            muestraDeCatalogo(arreglo, validos);
            system("pause");
            break;


        }

    }
    while (selected != 0);

    //system("pause");
    // system("cls");
    return 0;
}

int menuDepositoUusario()
{

    int input;
    system("cls");


    printf("\n\n\n");
    printf("\t\t __________________________________________________________________________________________________________________________________________________\n");
    printf("\t\t|                                                                                                                                                  |\n");
    printf("\t\t|                                                                                                                                                  |\n");
    printf("\t\t|  #####    #######  ######    #####    #####    ####    ######    #####              ####   #######  ##   ##  #######  ######     ##     ####     |\n");
    printf("\t\t|  ## ##    ##   #   ##  ##  ##   ##  ##   ##    ##     # ## #   ##   ##            ##  ##   ##   #  ###  ##   ##   #   ##  ##   ####     ##       |\n");
    printf("\t\t|  ##  ##   ## #     ##  ##  ##   ##  #          ##       ##     ##   ##           ##        ## #    #### ##   ## #     ##  ##  ##  ##    ##       |\n");
    printf("\t\t|  ##  ##   ####     #####   ##   ##   #####     ##       ##     ##   ##           ##        ####    ## ####   ####     #####   ##  ##    ##       |\n");
    printf("\t\t|  ##  ##   ## #     ##      ##   ##       ##    ##       ##     ##   ##           ##  ###   ## #    ##  ###   ## #     ## ##   ######    ##   #   |\n");
    printf("\t\t|  ## ##    ##   #   ##      ##   ##  ##   ##    ##       ##     ##   ##            ##  ##   ##   #  ##   ##   ##   #   ##  ##  ##  ##    ##  ##   |\n");
    printf("\t\t| #####    #######  ####      #####    #####    ####     ####     #####              #####  #######  ##   ##  #######  #### ##  ##  ##   #######   |\n");
    printf("\t\t|                                                                                                                                                  |\n");
    printf("\t\t|                                                                                                                                                  |\n");
    printf("\t\t|                                                                  1. MUESTRA DEL DEPOSITO                                                         |\n");
    printf("\t\t|                                                                                                                                                  |\n");
    printf("\t\t|__________________________________________________________________________________________________________________________________________________|\n");

    input=getch()-'0';
    system("cls");
    return input;
}





int menuOpcionDepositoSucursalUsuario()
{
    int opcion;
    do{
        opcion = menuDepositoSucursalesUusario();
        switch (opcion)
        {

        case 1:
            mostrarDepositoSucursal();
            break;

        }

    }
    while (opcion != 0);

    return 0;
}



int menuDepositoSucursalesUusario()
{

    int input;
    system("cls");
    printf("\n\n\n");
    printf("\t\t _____________________________________________________________________________________________________________________________________________________________________________\n");
    printf("\t\t|                                                                                                                                                                             |\n");
    printf("\t\t|                                                                                                                                                                             |\n");
    printf("\t\t|   ###                                         ##       ##                                                                                       ###                         |\n");
    printf("\t\t|    ##                                                  ##                                                                                        ##                         |\n");
    printf("\t\t|    ##    ####     ######   ####     #####    ###      #####    ####              #####   ##  ##    ####    ##  ##   ######    #####    ####      ##      ####     #####     |\n");
    printf("\t\t| #####   ##  ##    ##  ##  ##  ##   ##         ##       ##     ##  ##            ##       ##  ##   ##  ##   ##  ##    ##  ##  ##           ##     ##     ##  ##   ##         |\n");
    printf("\t\t| ##  ##  ######    ##  ##  ##  ##    #####     ##       ##     ##  ##             #####   ##  ##   ##       ##  ##    ##       #####    #####     ##     ######    #####     |\n");
    printf("\t\t| ##  ##  ##        #####   ##  ##        ##    ##       ## ##  ##  ##                 ##  ##  ##   ##  ##   ##  ##    ##           ##  ##  ##     ##     ##            ##    |\n");
    printf("\t\t| ######  #####     ##       ####    ######    ####       ###    ####             ######    ######   ####     ######  ####     ######    #####    ####     #####   ######     |\n");
    printf("\t\t|                  ####                                                                                                                                                       |\n");
    printf("\t\t|                                                                                                                                                                             |\n");
    printf("\t\t|                                            1. MOSTRAR DEPOSITO SUCURSAL                                                                                                     |\n");
    printf("\t\t|                                            0. SALIR                                                                                                                         |\n");
    printf("\t\t|_____________________________________________________________________________________________________________________________________________________________________________|\n");

    input=getch()- '0';
    system("cls");
    return input;
}


